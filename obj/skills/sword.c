/* sword for companion spell (mks) */
#include <mudlib.h>
inherit BASE;



object owner;
int wc;

void reset(status arg) {
  if(arg) return;
  set_enchanted(1);
  set_name("sword");
  set_smell("You smell the odour of ozone as it crackles off the blades.\n");
  set_listen("You hear it hum softly.\n");
  set_short("A shimmering sword");
  set_long("The blade shimmers and seems almost liquid\n");        
  set_extra_info("This sword has a life of its own. It won't let you\n"+
                 "touch it.\n");
}

void heart_beat() {
  object attack_ob;
  int dmg;

  if(!owner) { /* logged out */
     destruct(this_object());
     return;
  }
  if(!present(owner, environment(this_object()))) {
    say("The sword follows its owner.\n");
    move_object(this_object(), environment(owner));
    tell_room(environment(owner), "The sword floats into the room.\n");
  }
  attack_ob = (object)owner->query_attack();  
  if(attack_ob) {
    string nam;

    if(present(attack_ob, environment(owner))) {
      dmg = random(wc+1) - random((int)attack_ob->query_ac()+1);
      if(dmg < 1) dmg = 1;
      if(dmg < (int)attack_ob->query_hp()) {
        attack_ob->adj_hp(-dmg); /* no fight ensues */
      }
      dmg /= 3;
      nam = (string)attack_ob->query_name();
      tell_room(environment(),"The sword "+
      ((dmg > 21)
      ? "gashed "+nam+" spilling blood everywhere"
      : (dmg > 18)
      ? "sliced "+nam+" across the throat"
      : (dmg > 15)
      ? "pierced "+nam+" in the abdomen"
      : (dmg > 12)
      ? "cut "+nam+" on the arm"
      : (dmg > 9)
      ? "chopped "+nam+" on the leg"
      : (dmg > 6)
      ? "grazed "+nam+" on the foot"
      : (dmg > 3)
      ? "brushed "+nam+" on the arm"
      : (dmg > 0)
      ? "hurt "+nam+" on the hand"
      : "missed "+nam)+".\n");
    }
  }
}


void set_owner(object ob) { 
  owner = ob;
  if(ob) {
    set_heart_beat(1);
    set_info("The sword was created by "+(string)ob->query_name()+".\n"+
             "It will expire in about @@query_approx_time:"+
              file_name(previous_object())+"@@.\n");
    wc = (int)ob->query_level()/2;
  }
}


object query_owner() { return owner; }


void dispel_magic() {
  object ob;

  if(owner) {
    ob = present("spellsword",owner);
    if(ob) {
      ob->dispel_magic(); /* destructs this */
      return;
    }
  }    
  destruct(this_object());
}

