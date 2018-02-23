
#define  NAME       "@@query_name:$this_player()$@@"
#define  SPELLNAME  (string)caster->query_spell_name()
#define  SPELLDMG   (int)caster->query_spell_dmg()
#define  TARGET_WIS (int)target->query_wisdom()
#define  CASTER_CHR (int)caster->query_charisma()

status reincarnate(string targ, mixed alt_type, string class) {
  object dead;
  int level, i;
  string file;
  string spell_name;
  int spell_level;

  if(!targ) {
    notify_fail("Reincarnate who?\n");
    return 0;
}

  if(!alt_type) alt_type = "necromancy";
  if(!class) class = "mage";
  level = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()
      : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());

  if((dead = find_player(targ))) {
    if(!dead->query_dead()) {
      write(capitalize(targ) +" is not dead!\n");
      return 1;
    }
  }
  else {
    write("The essence of "+ capitalize(targ) +" does not exist.\n");
    return 1;
  }

  this_player()->load_spell(({
  "argument",	       targ,
  "name",              spell_name,
  "sphere",            alt_type,
  "cost",              18,
  "damage",            level,
  "immune",            "necromancy",
  "level",             18,
  "class", class,
  "cast time",         3,
  "spell object",      file,
  "passive",

  "casting msg", ({
    "You call upon the gods to give life to "+ capitalize(targ) +".\n",
    "You feel the essence of "+ capitalize(targ) +" coalescing.\n",
  }),
  "casting room", ({
    NAME +" calls upon the gods to give life to "+ capitalize(targ) +".\n",
    "You feel the essence of "+ capitalize(targ) +" coalescing.\n",
  }),
  }));
  return 1;
}


status cast_spell(object caster,object target,object prev,int dmg) {
  string *stats;
  string *races;
  int i;


  races = ({
	"half elf", "high elf", "dark elf", "grey elf", "wood elf", "wild elf",
	"half giant", 
	"halfling", "kender",
	"deep gnome", "forest gnome", "rock gnome",
	"hill dwarf", "mountain dwarf",
	"centaur", "minotaur",
	"pixie", "nixie", "brownie",
	"goblin", "orc", "kobold",
  });
	
  target = find_player((string)caster->query_spell_argument());
  if(target) {
    if(!target->query_dead()) {
      write(target->query_name() +" is not dead!\n");
    }
    else {
      write("You reincarnate "+ target->query_name() +" from the dead.\n");
      tell_object(target, caster->query_name()+" tries to reincarnate you.\n");
      target->toggle_ghost();
      move_object(target, environment(caster));
      caster->add_exp((int)target->query_level() * 100);

      stats = ({
                 "constitution", "intelligence", "wisdom", "charisma",
                 "strength",     "dexterity",    "combat",
              });
      for(i = 0; i < 4; i++) {
        call_other(target,"adj_"+ stats[random(sizeof(stats))],1);
      }
      target->heal_self(1000);
    }
  }
  else {
    write("The essence of "+ (string)caster->query_spell_argument()+
      " has left the world.\n");
  }
  destruct(this_object());
  return 1;
}

status id(string str) {
  return str == "spell"
      || str == "raise";
}


