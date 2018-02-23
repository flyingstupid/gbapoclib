/** Chain Lightning **/

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"


status chain(mixed targ, mixed alt_type, string class) {
  int dam, i;
  string file;

  if(!targ || !(targ == "lightning" || sscanf(targ,"lightning %s", targ))) {
    notify_fail("chain lightning?\n");
    return 0;
  }

  if(!alt_type) alt_type = "evocation";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(6) + 1);
  if(dam > 55) dam = 55;  

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Chain Lightning",
  "sphere",            alt_type, 
  "cost",              15,
  "damage",            dam,
  "immune",            "lightning",
  "level",             15,
  "class", class,
  "cast time",         2,
  "area",
  "spell object",      file,
  "casting msg",      "You are blinded as lightning leaps from your "+
                      "hands...\n",
  "casting msg room", "You are blinded as lightning leaps from "+NAME+
                      "'s hands...\n",
/* other spell options... 
  "msg target",       0,
  "msg room",         0,
  "msg caster",       0,
  "passive",
  "component",        0,
 */
  }));
  return 1;
}


/* call when this object is cloned to target */

status cast_spell(object caster, object target, object previous, int dmg) {
  if(caster == target) {
    destruct(this_object());
    return 1;
  }
  if(previous) {
    tell_room(environment(target),
    "The lightning bolt bounces from "+(string)previous->query_name()+
    " to hit "+(string)target->query_name()+".\n");
  }
  destruct(this_object()); /* get rid of cloned object */
  return 0; /* do damage */
}

status id(string str) { return (str == "spell"); }

