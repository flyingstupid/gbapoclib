#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define GNAME (string)caster->query_name()
#define TARG "@@query_name:$this_object()$@@"


status turn(string targ, mixed alt_type) {
  int dam, i;
  string file;

  if(!alt_type) alt_type = "combat_sphere";


  if(!this_player()->query_class("cleric")) {
    notify_fail("Only a priest may pray for spells.\n");
    return 0;
  }

  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()
      : (int)call_other(this_player(),"query_"+alt_type);

  dam *= (random(20) + 1);
  if(dam > 80) dam = 80;

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
	"target",            targ,
	"name",              "Turn Undead",
	"sphere",            alt_type,
	"cost",              10,
	"area",
	"passive",
	"damage",            dam,
	"immune",            "light",
	"level",             10,
	"cast time",         3,
	"area",
  "casting msg", ({
    "Devine retribution builds as the heavens overhead begin to roar...\n",
    "The ground beneath you begins to shake...\n",
    "You are filled with a holy power...!\n",
   }),

  "casting msg room",  ({
    "Devine retribution builds up in "+NAME+"...\n",
    "The ground beneath you begins to shake violently...\n",
    "The heavens overhead begin to roar...\n",
   }),

  "msg caster",         TARG +" is engulfed in holy light!\n",
  "spell object",      file,
  }));
  return 1;
}

status cast_spell(object caster,object target,object prev,int dmg) {
  if(caster == target) {
    destruct(this_object());
    return 1;
  }

  if(!target->id("undead")) {
    tell_object(caster, target->query_name() +" is uneffected.\n");
    destruct(this_object());
    return 1;
  }

  tell_object(caster, target->query_name()+" burns with holy light!\n");
  say(target->query_name()+" burns with holy light!\n", target);
  caster->attack_msg(dmg, "spell", target, 0);
  target->do_damage(dmg);
  destruct(this_object());
  return 0;
}


