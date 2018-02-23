/** Charm Animal, person, monster **/

#include <humanoid.h>

#define  NAME       "@@query_name:$this_player()$@@"
#define  SPELLNAME  (string)caster->query_spell_name()
#define  SPELLDMG   (int)caster->query_spell_dmg()
#define  TARGET_WIS (int)target->query_wisdom()
#define  CASTER_CHR (int)caster->query_charisma()

status charm(string spell_type, mixed alt_type, string class) {
  int level, i;
  string file;
  string targ, spell_name;
  int spell_level;

  if(!spell_type) {
    notify_fail("Charm animal, charm person, charm monster?\n");
    return 0;
  }
    
  if(!alt_type) alt_type = "charm";
  if(!class) class = "mage";
  level = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  sscanf(spell_type, "%s %s", spell_type, targ);
  spell_type = lower_case(spell_type);
  switch(spell_type) {
    case "animal":
      spell_name  = "Charm Animal";
      spell_level = 2;
    break;

    case "person":
      spell_name  = "Charm Person";
      spell_level = 12;
    break;

    case "monster":
      spell_name  = "Charm Monster";
      spell_level = 18;
    break;

    default:
      notify_fail("Charm animal, charm person, charm monster?\n");
      return 0;
    break;
  }

   
  this_player()->load_spell(({
  "target",            targ,
  "name",              spell_name,
  "sphere",            alt_type,
  "cost",              spell_level,
  "damage",            level,
  "immune",            "charm",
  "level",             spell_level,
  "cast time",         2,
  "spell object",      file,
  "class",             class,
  "casting msg",      "You start to feel empathic...\n",
  "casting msg room", NAME +" starts to look very trusting.\n",
  "passive",

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

  if(((int)target->query_level() < 3 && SPELLNAME == "Charm Animal")
  || (humanoid(target) && SPELLNAME == "Charm Person")
  || (SPELLNAME == "Charm Monster")) {
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

