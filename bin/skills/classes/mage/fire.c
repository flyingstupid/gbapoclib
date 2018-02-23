/** fire ball, fire shield **/
 
inherit "inherit/base/base_obj";
inherit "inherit/timer";
 
#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"
 
status fire(string spell_type, mixed alt_type, string class) {
  int dam;
  string targ;
  string file;
  int i;
 
  if(!spell_type) {
    notify_fail("fire ball, fire shield?\n");
    return 0;
  }
 
  sscanf(spell_type,"%s %s", spell_type, targ);
  spell_type = lower_case(spell_type);
 
  if(!class) class = "mage";

  switch(spell_type) {
    case "ball":
      if(!alt_type) alt_type = "evocation";
      dam = (objectp(alt_type))
          ? (int)alt_type->query_cast_level() 
          : (int)call_other(this_player(),"query_"+alt_type);
          dam *= (random(4) + 1);
    if(dam > 25) dam = 25;
 
      this_player()->load_spell(({
      "target",            targ,
      "name",              "Fire Ball",
      "sphere",            alt_type, 
      "cost",              10,
      "damage",            dam,
      "immune",            "fire",
      "level",             10,
      "cast time",         2,
      "class",             class,
      "area",
      "casting msg",       "A small red dot forms from your fingertip...\n",
      "casting msg room", "A small red dot forms at "+ NAME  
                            +"'s fingertip...\n",
      "msg target",        "A ball of hot flame sears you.\n",
      }));
    break;
 
    case "shield":
      if(!alt_type) alt_type = "evocation";
 
      file = file_name(this_object());
      sscanf(file,"%s#%d",file,i);
      if(!alt_type) alt_type = "evocation";
      dam = (objectp(alt_type))
          ? (int)alt_type->query_cast_level()
          : (int)call_other(this_player(),"query_"+alt_type);
          dam *= (random(4) + 1);
    if(dam > 25) dam = 25;
  
      this_player()->load_spell(({
      "target",            this_player(),
      "name",              "Fire Shield",
      "sphere",            alt_type, 
      "cost",              12,
      "level",             12,
      "cast time",         2,
      "class",             class,
      "spell object",      file,
      "passive",
	"damage",	   dam,
      "casting msg",       "You start to feel cold flames spring up around "+
                           "you.\n",
     "casting msg room",   "You start to see flames spring up about "+
                           NAME+".\n",
      }));
    break;
 
    default:
      notify_fail("fire ball, fire shield?\n");
      return 0;
    break;
  }
  return 1;
}
 
      
status cast_spell(object caster,object target,object prev,int dmg) {
  object shield;
 
  shield = present("fireshield 2",target);
  if(shield) {
    tell_object(caster,"You extend the time of your fireshield...\n");
    shield->adj_time(dmg *30);
    destruct(this_object());
    return 1;
  }
  write("A cold flame encirlces you.\n");
  say("A cold flame encircles "+(string)target->query_name()+".\n");
  set_name("fireshield");
  set_alt_name("spell");
  set_listen("You hear the crackling of flames.\n");
  set_smell("You smell the pungent odor of burning flesh.\n");
  set_alt_extra_long("A red fireshield crackles around you.\n");
  set_extra_long("A red fireshield crackles around "+
                  (string)target->query_name()+".\n");
  set_long("The red shield of fire harms all who touch it.\n");
  set_examine("Although surrounded by crackling red flame,\n"+
                 "you feel rather cool.\n"); 
  set_info("The fireshield makes the caster immune to fire.\n"+
           "This shield has only @@query_approx_time:"+
            file_name(this_object())+"@@ left before it expires.\n");
  target->add_spell_immunity("fire");
  set_heart_beat(1);
  adj_time(dmg *30);
  return 1;
}
 
void time_out() {
  object env;
 
  env = environment();
  env->remove_spell_immunity("fire");
  tell_object(env,"Your fire shield fades...\n");
  ::time_out();
}
 
void dispel_magic() {  time_out(); }
int oldhp;
 
void heart_beat() {
  object monster, env;
  int hp, dmg;
 
  env = environment();
  if(!(monster = (object)env->query_attack())) return;
  if(environment(monster) != environment(env)) return;
  if(monster->query_spell_immunity("fire")) return;
  if(random((int)monster->query_magic_resist()+1) > random(100)) return;
 
  hp = (int)env->query_hp();
  dmg = oldhp - hp;
  oldhp = hp;
 
  if(dmg > 0 && dmg <= (int)monster->query_right_wc() * 2) {
    tell_object(env,"Flames from your shield burn "+
      monster->query_name() +" as "+ monster->query_pronoun() +
      " attacks you!\n");
      say("Flames from "+ env -> query_name() +"'s fire shield "+
      " burn "+ monster -> query_name() +" as "+ monster -> query_pronoun() +
      " attacks "+ env -> query_objective() +"\n", env);
      if((int)monster->query_hp() > 2 * dmg) {
        dmg *= 2;
        monster->adj_hp(-dmg);
      }
  }
}
 
 
status drop(status quit) {
  if(quit) time_out();
  return 1;
}


status id(string str) {
  return ::id(str) ||
  str == "fireshield" ||
  str == "fire shield" ||
  str == "spell";
}

