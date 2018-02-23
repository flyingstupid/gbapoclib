/** detect illusion, detect magic **/

#define NAME "@@query_name:$this_player()$@@"

status detect(string spell_type, mixed alt_type, string class) {
   int level, i;
   string file, objective, tmp1;
   string targ;
   object obj;

   if(!spell_type) {
     tmp1 = "detect magic, detect illusion, detect secret doors?\n"
          + "detect evil, "+
           "detect immunities, detect magic resistance?\n";
     if(this_player()->query_traps()) tmp1 += "detect trap on what?\n";
     notify_fail(tmp1);
     return 0;
   }
   if (!alt_type) alt_type = "divination_sphere";
  if(!class) class = "cleric";
   level = (objectp(alt_type))
         ? (int)alt_type->query_cast_level()
         : (int)call_other(this_player(),"query_"+ alt_type);
   file = file_name(this_object());
   sscanf(file,"%s#%d",file,i);

   sscanf(spell_type,"%s %s",spell_type,targ);
   switch(spell_type) {
    case "illusion":
      if(!targ) targ = "room";

      this_player()->load_spell(({
      "target",       targ,
      "name",         "Detect Illusion",
      "sphere",       alt_type,
      "cost",         1,
      "immune",       "divination",
      "damage",       level,
      "level",        1,
	"class",	class,
      "cast time",    1,
      "spell object", file,
      "passive",
      }));
    break;
  
    case "magic":
      if(!targ) {
        write("detect magic target\n"+
              "detect magic resistance target?\n");
        if(this_player()->query_traps()) {
          write("detect traps on what?\n");
        }
        return 1;
      }
      if(sscanf(targ,"resistance %s",targ)) {
        this_player()->load_spell(({
        "target",       targ,
        "name",         "Detect Magic Resistance",
        "sphere",       alt_type,
        "cost",         4,
        "immune",       "divination",
        "damage",       level,
        "class",        class,
        "level",        4,
        "cast time",    1,
        "spell object", file,
        "passive",
        }));
      }
      else {
        if(!(obj = present(targ, environment(this_player())))) {
          if(!(obj = present(targ, this_player()))) {
            notify_fail("There is no "+ targ +" here.\n");
             return 0;
          }
        }
        if(!(objective = (string)obj->query_objective())) objective = "it";

        this_player()->load_spell(({
        "target",            targ,
        "name",              "Detect Magic",
        "sphere",            alt_type, 
        "cost",              3,
        "level",             3,
        "class",             class,
        "passive",
        "cast time",         3,
        "spell object",      file,
        "casting msg", 
         ({
          "You look at "+ obj->query_name() +" carefully, concentrating "+
          "upon "+ objective +".\n",
          "You begin to see the magical aura surrounding "+ objective +".\n"
         }),

        "casting msg room",  
         ({ 
          NAME +" looks at "+ obj->query_name() +", concentrating upon "+
          objective +".\n",
          NAME +" suddenly looks enlightened!\n" 
         }),
        }));
      }
    break;
 
    case "secret":
      if(targ != "doors") {
        notify_fail("detect secret doors?\n");
        return 0;
      }
      this_player()->load_spell(({
      "target",       environment(this_player()),
      "name",         "Detect Secret Doors",
      "sphere",       alt_type,
      "cost",         2,
      "immune",       "divination",
      "damage",       level,
      "level",        2,
      "cast time",    1,
      "spell object", file,
      "passive",
      "class", class,
      }));

    break;

    case "evil":
      this_player()->load_spell(({
      "target",      targ,
      "name",        "Detect Evil",
      "sphere",      alt_type,
      "cost",        1,
      "immune",      "divination",
      "damage",      level,
      "class",       class,
      "level",       1,
      "casting time", 1,
      "spell object", file,
      "passive",
      }));
    break;

    case "immunities": case "immunity":
      this_player()->load_spell(({
      "target",       targ,
      "name",         "Detect Immunity",
      "sphere",       alt_type,
      "cost",         4,
      "immune",       "divination",
      "damage",       level,
      "level",        4,
      "cast time",    1,
      "class",        class,
      "spell object", file,
      "passive",
      }));
    break;

    default:
      tmp1 = "detect magic, detect illusion, detect secret doors?\n"
           + "detect evil, "+
            "detect immunities, detect magic resistance?\n";
      if(this_player()->query_traps()) tmp1 += "detect trap on what?\n";
      notify_fail(tmp1);
      return 0;
    break;
  }
  return 1;
}









/* Modifications to Detect Magic spell by Angel July 1998 */
#define DEBUG	      ((string)this_player()->query_name() == "Angel")
#define ALL_REALNAME  capitalize((string)all[i]->query_name(1))
#define TARG_REALNAME capitalize((string)target->query_name(1))
#define DIFFICULTY    15


static int mod;

void evil       (object caster, object target, int level, string spell);
void doors      (object caster, object target, int level, string spell);
void illusion   (object caster, object target, int level, string spell);
void immunity   (object caster, object target, int level, string spell);
void resistance (object caster, object target, int level, string spell);
void magic      (object caster, object target, int level, string spell);

status cast_spell(object caster,object target,object prev,int level, string spell){
  int me, you;


  me  = random(level) + 1;
  you = random(DIFFICULTY) + 1;

  if(you > me) mod = you - me; /* amount we missed out by */
  
  if(DEBUG) write("test1\n");
  if(!spell) spell = (string)caster->query_spell_name();
  if(!spell) spell = "Detect Magic";

  switch(spell) {
    case "Detect Illusion" :
      illusion(caster, target, level, spell);
      break;

    case "Detect Secret Doors" :
      doors(caster, target, level, spell);
      break;

    case "Detect Evil" :
      evil(caster, target, level, spell);
      break;

    case "Detect Immunity" :
      immunity(caster, target, level, spell);
      break;

    case "Detect Magic Resistance" :
      resistance(caster, target, level, spell);
      break;
 
    default : /* Detect Magic */
      if(DEBUG) write("test2\n");
      magic(caster, target, level, spell);
      if(DEBUG) write("test3\n");
      break;
  }

  destruct(this_object());
  return 1;
}

void illusion(object caster, object target, int level, string spell) {
  status flg;
  int i;
  object *all, *who, ob;

  if(target->query_disguise_on()) {
    if(!mod) /* we made our check */
      write(TARG_REALNAME +" is disguised as "+ target->query_name() +".\n");
    else {   /* didn't make our check :(  */
      who = users();
      ob = who[random(sizeof(who))];
      write((string)ob->query_name() + 
      " is disguised as "+ target->query_name() +".\n");
    }
    flg = 1;
  }

  if(target->query_invis()) {
    write(TARG_REALNAME +" is invisible.\n");
    flg = 1;
  }

  if(target->query_illusion_object()) {
    write("There is an "+ target->short(0,1) +".\n");
    flg = 1;
  }

  all = all_inventory(target);
  for(i = 0; i < sizeof(all); i++) {
    if(all[i]->query_disguise_on()) {
      if(!mod) /* we made our check */
        write(ALL_REALNAME +" is disguised as "+ target->query_name() +".\n");
      else {
        who = users();
        ob = who[random(sizeof(who))];
        write((string)ob->query_name() +
        " is disguised as "+ target->query_name() +".\n");
      }
      write(ALL_REALNAME +" is disguised as "+ all[i]->query_name() +".\n");
      flg = 1;
    }
    if(all[i]->query_invis()) {
      write(ALL_REALNAME +" is invisible.\n");
      flg = 1;
    }
      if(all[i]->query_illusion_object()) {
        write("There is an "+ all[i]->short(0,1) +".\n");
        flg = 1;
      }
    }      
    if(!flg) {
     if(target == environment(caster)) {
        write("There are no obvious illusions in the area.\n");
      }
      else {
        write("There are no illusions on "+ TARG_REALNAME +".\n");
      }
    }

}


void magic(object caster, object target, int level, string spell) {
  string *colours;
  mixed  *items;
  int non_magical_value, magic_intensity;
  int tmpInt;

  
  colours = ({
      "black", "normal", "red", "orange", "yellow", "green", "blue", "purple",
      "violet", "brass", "copper", "silver", "gold", "platinum",
  });

  items = ({
        /* weapons */      /* non magical wc value */
          "sickle",            9,
          "dagger",            8,
          "dirk",              8,
          "knife",             6,
          "scimitar",         10,
          "broadsword",       12,
          "falchion",         12,
          "khopesh",          11,
          "longsword",        13,
          "mace",             12,
          "shortsword",       10,
          "rapier",           12,
          "sabre",            10,
          "cutlass",          11,
          "cutlas",           11,
          "halberd",          13,
          "lance",            10,
          "ranseur",          11,
          "spear",            10,
          "trident",          10,
          "club",              9,
          "flail",            10,
          "hammer",           11,
          "war hammer",       11,
          "staff",            12,
          "rod",              12,
          "mace",             12,
          "battleaxe",        12,
          "battle axe",       12,
          "handaxe",           8,
          "hand axe",          8,
          "axe",              10,
          "twohandedsword",   14,
          "bastardsword",     13,
          "morningstar",       9,
          "claymore",         14,
      
       /* armour */     /* non magical value */
          "bracers",     0,
          "leather",     1,
          "chainmail",   3,
          "platemail",   4,
          "cloak",       0,
          "furs",        1,
          "fur",         1,
          "skins",       1,
          "ring",        0,
          "robes",       0,
          "amulet",      0,
          "robe",        0,
          "shield",      1,
          "boots",       1,
          "gloves",      0,
          "helm",        1,
          "helmet",      0
  });

  if(!target->query_name(1))
    tmpInt = -1;
  else
    tmpInt = (int)member_array((string)target->query_name(1), items);

  non_magical_value = (tmpInt != -1)
                       ? items[tmpInt+1]
                       : ((int)target->query_wc())
                       ? 10
                       : ((int)target->query_ac()) 
                       ? 1
                       : 0;

  target->init();

  /* some magical items need persuasion in order to set their
     values upon initialisation */

  
  if(target->query_wc())
    magic_intensity = (int)target->query_wc() - non_magical_value + 1;
  else
    magic_intensity = (int)target->query_ac() - non_magical_value + 1;

  if(mod) {
    if(random(2)) 
      magic_intensity += mod/3; /* accuracy modifier */
    else
      magic_intensity -= mod/3;
  }

  if(magic_intensity < 0)
    magic_intensity = 0;

  if(magic_intensity >= sizeof(colours))
    magic_intensity = sizeof(colours)-1;

  tell_object(caster, "A "+ colours[magic_intensity] 
         +" magical aura surrounds the "+
         target->query_name() +".\n");

  if(target->info()) write(target->info()+"\n");

  /* use accuracy modifier */
  if(target->query_classes_string())
    write(target->query_classes_string());

  if(target->query_charges_string()) {
    write("The "+target->short()+" has ");
    if(target->query_object_type() == "Scroll" ||
       target->query_object_type() == "Potion")
      write("but one use.\n");
    else
      write(target->query_charges() + (mod*2) +" charges\n");
  }

  if(target->query_level_string())
    write("The "+target->short()+" casts spells at a skill level of "+
    (target->query_cast_level() + random(mod)) +".\n");

  if(target->query_spell_triggers())
    write(target->query_spell_triggers());
}


void evil(object caster, object target, int level, string spell) {
  say(caster->query_name()+" concentrates upon "+target->query_name()+"\n");
  write("Concentrating upon "+target->query_name()+" you sense");

  if(target->query_gender() == 1)
    write(" he ");
  else if(target->query_gender() == 2)
    write(" she ");
  else
    write(" it ");
  if(target->query_alignment() < -25)
    write("is evil.\n");
  else if(target->query_alignment() > 25)
    write("is good.\n");
  else
    write("is somewhat neutral.\n");
}


void doors(object caster, object target, int level, string spell) {
  int i;
  string real_name;
  string *secret_door_exits, *door_finders;

  real_name = (string)caster->query_name(1);

  say(caster->query_name() +" peers around the room.\n");
  secret_door_exits = (string *)target->query_door_exits(3);

  if(!secret_door_exits || !sizeof(secret_door_exits)) {
    write("There are no secret doors.\n");
  }

  else {
    for(i = 1; i < sizeof(secret_door_exits); i += 2) {
      write("You find a secret door, "+
             capitalize(secret_door_exits[i]) +"!\n");
      door_finders =
          (string *)target->query_door_attribute(secret_door_exits[i],
                                                 "secret door finders");
      if(member_array(real_name,door_finders) == -1) {
        door_finders += ({ real_name, });
      }
      target->set_door_attribute(secret_door_exits[i],
                                 "secret door finders",
                                         door_finders);
    }
  }
}



void immunity(object caster, object target, int level, string spell) {
  string *immunities;
  immunities = (string *)target->query_all_spell_immune();
  if(!immunities || !sizeof(immunities)) {
    write(target->query_name() +" has no innate immunities.\n");
  }
  else {
    write(target->query_name() +" has the following innate immunities: ");
    write(implode(immunities,", ") +".\n");
  }
  say(caster->query_name() +" peers at "+ target->query_name() +".\n");
}


void resistance(object caster, object target, int level, string spell) {  
  int resist;
  resist = (int)target->query_magic_resist();
  write(target->query_name() +" ");

  if(resist >= 100)
    write("is resistant to all magic.\n");
  else if(resist > 75)
    write("is very magic resistant.\n");
  else if(resist > 50)
    write("has high magic resistance.\n");
  else if(resist > 25)
    write("has some resistance to magic.\n");
  else if(resist > 10)
    write("has low magic resistance.\n");
  else if(resist > 0)
    write("has very low magic resistance.\n");
  else
    write("has a normal resistance to magic.\n");
  say(caster->query_name() +" peers at "+ target->query_name() +".\n");
}



