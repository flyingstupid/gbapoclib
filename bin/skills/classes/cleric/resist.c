/* Resist */

inherit "inherit/base/base_obj";
inherit "inherit/timer";

string type;  /* type of resistance */

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */

status resist(string spell_type, mixed alt_type, string class) {
  int time, i;
  string file, targ;
  string *casting, *casting_rm;

  if(!spell_type) {
    notify_fail("resist cold, fire, light, death, draining,\n"+
                "       earth, air, water, acid, disease,\n"+
                "       fear, charm, darkness?\n");
    return 0;
  }
  sscanf(spell_type,"%s %s",spell_type, targ);
  if(!targ) targ = (string)this_player()->query_name(1);
  switch(spell_type) {
    case "cold": 
      casting =  ({
        "You draw all the warmth from your surroundings.\n", 
        "You direct the warmth from around you to protect "+
        capitalize(targ)+".\n",
      }),
 
      casting_rm = ({ 
        "You feel the air around you become colder...\n",
        "You feel cold is being drawn toward "+ capitalize(targ)
        +" by "+ NAME +".\n",
      });
    break;

    case "fire":
      casting = ({
        "You draw all the cold from your surroundings.\n", 
        "You direct the cold air from around you to protect "+
        capitalize(targ) +".\n",
      });
     
      casting_rm = ({
        "You feel the air around you become warmer...\n",
        NAME +" draws the cold air away to protect "+
        capitalize(targ)+" from fire.\n",
      });
    break;

    case "poison":  case "light": case "death": case "draining":
    case "earth":   case "air":   case "water": case "acid":
    case "disease": case "fear":  case "charm": case "darkness":
    case "lightning":
      casting = ({
       "You chant slowly.\n",
       "You call on your god to protect "+ capitalize(targ) +" from "+
        spell_type +".\n",
      });
      casting_rm = ({
        NAME +" chants slowly.\n",
        "@@query_pronoun:$this_player()$@@ calls to @@query_possessive:"+
        "$this_player()$@@ god to protect "+ capitalize(targ) 
       +" from "+ spell_type +".\n",
      });
    break;
   
    default:
      notify_fail("resist cold, fire, light, death, draining,\n"+
                  "       earth, air, water, acid, disease,\n"+
                  "       fear, charm, darkness?\n");
      return 0;
    break;
  }
  if(!alt_type) alt_type = "protection_sphere";
  if(!class) class = "cleric";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level() /* wands */
       : (int)call_other(this_player(),"query_"+alt_type);

   file = file_name(this_object());
   sscanf(file,"%s#%d",file,i);

   this_player()->load_spell(({
   "target",            targ,
   "name",              "Resist "+ capitalize(spell_type),
   "sphere",            alt_type, 
   "damage",            time,
   "cost",              9,
   "level",             9,
   "spell object",      file,
   "cast time",         3,
   "casting msg",       casting,

   "casting msg room",  casting_rm,
/*
   "component",          "shield",
*/
   "class",             class,
   "passive",
  }));
  return 1;
}

/***********************************************************************/
/* when cloned */

void time_out() {
  tell_object(environment(),"You feel the Resist "+ type 
                           +" spell wear away...\n");
  environment()->remove_spell_immunity(type);
  ::time_out();
}

void dispel_magic() { time_out(); }
 
status drop(status quit) {
  if(quit) time_out();
  return 1;
}


status cast_spell(object caster,object target,object prev,int time) {
  object cold;
  string Type;

  Type = (string)caster->query_spell_name();
  sscanf(Type,"Resist %s",Type);
  type = lower_case(Type);
 
  cold = present("resist "+ type, target);
  if(cold) {
    if(caster != target) {
      write("You extend the time of the Resist "+ Type +" spell on "+
            (string)target->query_name()+".\n");
    }
    else {
      write("You extend the time of your Resist "+ Type +" spell.\n");
    }
    cold->adj_time(time * 30);
    destruct(this_object());
    return 1;
  }
  if(caster != target) {
    write("You protect "+ target->query_name() +" from "+ Type +".\n");
  }
  tell_object(target, "You feel protected from "+ Type +".\n");
  target->add_spell_immunity(type);
  set_name("resist "+ type);
  set_alt_name("spell");
  set_alias_name("resist");
  set_alt_extra_long("You are protected from "+ Type +" spells.\n");
  set_extra_long("@@query_name:$environment()$@@ is protected from "+ Type 
               +".\n");
  adj_time(time * 30);
  return 1;
}

