#include <mudlib.h>

#define TP this_player()

status kill(string str) { 
  object ob, hiding, primary_attack;


  if(TP->query_ghost()) return 0; 
  if(!str) { 
    write("Kill what ?\n"); 
    return 1; 
  } 
  if(!(ob = present(lower_case(str), environment(TP)))) {
    write("No " + str + " here !\n"); 
    return 1; 
  } 
  if(!living(ob)) { 
    write(ob->short() + " is not a living thing !\n"); 
    say(TP->query_name() + " tries foolishly to attack " + str + ".\n"); 
    return 1; 
  }
  if(ob == TP) { 
    write("What ? Attack yourself ?\n"); 
    return 1; 
  } 
  if(environment(TP)->query_no_fight()) {
    write("Fighting is not allowed here.\n");
    return 1;
  }
  if((int)TP->query_level() < 2 && !TP->query_right_weapon()) {
    write("I wouldn't do that if I were you just yet.\n"+
          "Try and find a weapon first, and remember to use your wimpy.\n"+
          "Type 'help wimpy to find out more.\n");
    return 1;
  }

  if(!TP->query_wimpy() && (int)TP->query_level() < 2) {
    write("You should set your wimpy first. It allows you to run away from \n"+
          "battle. Type 'help wimpy' to find out more.\n");
    return 1;
  }



  if(primary_attack == ob) { 
    write("Yes, yes !!\n"); 
    return 1; 
  } 
  if(!TP->add_secondary_attacker(ob)) {
    write("The law prevents you from attacking "+ ob->query_name()  + ".\n");
    say(TP->query_name() +" attempts to kill "+ ob->query_name() +"!\n", ob);
    tell_object(ob,TP->query_name() +" tries to kill you!\n");
    return 1;
  }
  if(primary_attack && present(primary_attack, environment(TP))) {
    write("You turn to attack "+(string)ob->query_name()+".\n");
  }
  TP->set_primary_attack(ob);
  ob->set_primary_attack(TP);
  if(TP->query_disguise_on()) {
    write(ob->query_name() +" will remember that face next time . . . \n");
    TP -> toggle_disguise();
  }
  return 1; 
} 
