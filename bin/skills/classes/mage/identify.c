/** Identify; by Serepion  **/
#include <mudlib.h>
#include <spell.h>

/* updated feb. 94 */


status identify(string targ, mixed alt_type, string class) {
   int level, i;
   string file;

   if(!targ) {
     notify_fail("identify what?\n");
     return 0;
   }    
   if (!alt_type) alt_type = "divination";
  if(!class) class = "mage";
   level = (objectp(alt_type))
         ? (int)alt_type->query_cast_level()
         : (int)call_other(this_player(),"query_"+ alt_type);
   file = file_name(this_object());
   sscanf(file,"%s#%d",file,i);

   this_player()->load_spell(({
   "target",       targ,
   "name",         "Identify",
   "sphere",       alt_type,
   "cost",         5,
   "immune",       "divination",
   "damage",       level,
   "level",        5,
  "class", class,
   "cast time",    1,
   "spell object", file,
   "passive",
   }));
   return 1;
}

#define TARG_DEX (int)ob->query_dexterity()
#define CAST_COM (int)caster->query_combat()
#define CAST_INT (int)caster->query_intelligence()
#define PRONOUN  capitalize((string)ob->query_pronoun())

status cast_spell(object caster,object ob,object prev,int level) {
  int ac, wc, mon_level, p_level, level_dif;
  int accuracy, value;
  string *classes;

  accuracy = (random(50) > level + CAST_INT) /* level 25 always accurate */
           ? random(10) - 5
           : 0;

  ac = (int)ob->query_ac() + (accuracy/3);
  wc = (int)ob->query_wc() + accuracy;
  value = (int)ob->query_value();
  value = (accuracy < 0)
        ? value/(accuracy*(-2))
        : (accuracy > 0)
        ? value * accuracy * 2
        : value;

  if(ob->query_npc() || ob->id("PLAYER")) {
    if(ob != caster && (random(TARG_DEX) > random(CAST_COM))) {
      write("You attempt to place your hands on "+ ob->query_name()
           +", but "+ob->query_pronoun()+" dodges out of the way.\n");
      say(this_player()->query_name() +" fails to touch "+
          ob->query_name()+".\n");
    }
    else { 
      if(ob == caster) {
        write("You place your hands on yourself, and attempt to identify \n"+
		"your abilities.\n");
	say(caster->query_name()+" identifies "+caster->query_objective()+
		"self.\n");
      }
      else {
        write("You place your hands on "+ ob->query_name() 
           +" and attempt to identify "+ ob->query_objective() +".\n");
        say(this_player()->query_name() +" touches "+ ob->query_name()
         +" and seems enlightened.\n");
      }

      mon_level = (int)ob->query_level() + accuracy;
      p_level = (int)this_player()->query_level() + accuracy;
      level_dif = mon_level - p_level;
      if(ac > 20)
        write(capitalize((string)ob->query_pronoun()) +" is extremely well armoured.\n");
      else if(ac > 15)
        write(capitalize((string)ob->query_pronoun()) +" is rather well armourer.\n");
      else if(ac > 10)
        write(capitalize((string)ob->query_pronoun()) +" is well armoured.\n");
      else if(ac > 5)
        write(capitalize((string)ob->query_pronoun()) +" is somewhat armoured.\n");
      else
        write(capitalize((string)ob->query_pronoun()) +" is nearly naked.\n");
      if(wc > 25)
        write(PRONOUN +" can turn you into a bloody mess before you think.\n");
      else if(wc > 20)
        write(PRONOUN +" can massacre on a good day.\n");
      else if(wc > 15)
        write(PRONOUN +" can knock you unconcious without thinking.\n");
      else if(wc > 10)
        write(PRONOUN +" can rip out your heart for lunch.\n");
      else if(wc > 5)
        write(PRONOUN +" can knock you around a bit.\n");
      else
        write(PRONOUN +" might leave a scar or two.\n");
      if(level_dif > 20)
        write(PRONOUN +" towers over you like a tall building.\n");
      else if(level_dif > 10)
        write(PRONOUN +" is head and shoulders above you.\n");
      else if(level_dif > 0)
        write(PRONOUN +" is a little bigger than you.\n");
      else if(level_dif == 0)
        write(PRONOUN +" is just your size.\n");
      else if(level_dif >= -10)
        write(PRONOUN +" is a little smaller than you.\n");
      else if(level_dif >= -20)
        write("You stand head and shoulders above it.\n");
      else
        write("You tower over it like a tall building.\n");
      if((classes = (string *)ob->query_classes())) {
        write(PRONOUN +" looks skilled as a "+ implode(classes, ", ") +".\n");
      }
    }
  }
  else {
    if(ac > 0) {
      if(ac >= 5)
        write("It can take anything that is dished out to it.\n");
      else if(ac == 4)
        write("It can take a beating.\n");
      else if(ac == 3 || ac == 2)
        write("It can take a little pounding.\n");
      else
        write("It can't take much of a pounding.\n");
    }
    if(wc > 0) {
      if(wc > 25)
        write("It can turn anything into a bloody mess before your eyes.\n");
      else if(wc > 20)
        write("It can massacre on a good day.\n");
      else if(wc > 15)
        write("It can knock anything unconscious without effort.\n");
      else if(wc > 10)
        write("You can rip out someone's heart for lunch.\n");
      else if(wc > 5)
        write("You can knock someone around with it.\n");
      else
        write("You might leave a scar or two.\n");
    }
    if(value <= 0)
      write("It might be worth some old lead.\n");
    else if(value < 10)
      write("It might buy you a drink.\n");
    else if(value < 100)
      write("It is worth at least a hearty meal.\n");
    else if(value < 1000)
      write("It is very valuable.\n");
    else
      write("It isn't something to be displaying at a thief's guild.\n");
  }
  destruct(this_object());
  return 1;
}


