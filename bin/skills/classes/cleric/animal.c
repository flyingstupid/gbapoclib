/* animal friendship */

#define  NAME       "@@query_name:$this_player()$@@"
#define  SPELLNAME  (string)caster->query_spell_name()
#define  SPELLDMG   (int)caster->query_spell_dmg()
#define  TARGET_WIS (int)target->query_wisdom()
#define  CASTER_CHR (int)caster->query_charisma()

status animal(string targ, mixed alt_type, string class) {
  string file;
  int i;
  int level;

  if(!targ || !(targ == "friendship" || sscanf(targ,"friendship %s",targ))) {
    notify_fail("animal friendship?\n");
    return 0;
  }
  if(targ == "friendship") targ = 0;
  if(!alt_type) alt_type = "nature_sphere";
  if(!class)    class = "cleric";

  file = file_name(this_object());
  sscanf(file,"%s#%d", file, i);

  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level() 
        : (int)call_other(this_player(),"query_"+alt_type);

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Animal Friendship",
  "sphere",            alt_type, 
  "cost",              3,
  "damage",            level,
  "immune",            "charm",
  "level",             3,
  "class",             class,
  "cast time",         2,
  "casting msg",       "The powers of nature come to your aid...\n",
  "casting msg room",  NAME +" starts to croon softly.\n",
  "spell object",      file,
  "passive"
  }));

  return 1;
}


  
/* call when this object is cloned to target */

status cast_spell(object caster, object target, object previous, int level) {
  object charm;

#ifndef PLAYER_KILL
  if(!(caster->query_npc() || target->query_npc())) {
    write(target->query_name() +" gets upset with you!!\n");
    tell_object(target,caster->query_name() +" tried to charm you.\n");
    destruct(this_object()); /* get rid of cloned object */
    return 1; 
  }
#endif

  if((int)target->query_level() < 3 && SPELLNAME == "Animal Friendship") {
    if(!target->query_made_my_save()) {
      if((charm = present("charm", caster))) {
        write("You lose a friend.\n");
        destruct(charm);
      }
      target->set_aggressive(0);
      target->stop_fight(caster);
      caster->stop_fight(target);
      charm = clone_object("obj/skills/charm_ob");
      charm->set_charmed(target);
      move_object(charm, caster);
      write("A trust forms between you and "+ target->query_name() +".\n");
      tell_object(target,"You find "+ caster->query_name() 
                        +" very trusting.\n");
      if(!present("soul", target)) {
        move_object(clone_object("obj/soul"),target);
      }
      destruct(this_object());
      return 1;
    }
  }
  if(random(TARGET_WIS) < random(CASTER_CHR)) {
    write(target->query_name() +" does not take any notice of you.\n");
  }
  else {
    write(target->query_name() +" gets upset with you!!\n");
    target->add_secondary_attacker(caster);
  }
  destruct(this_object()); /* get rid of cloned object */
  return 1; /* do damage */
}

status id(string str) { return (str == "spell"); }

