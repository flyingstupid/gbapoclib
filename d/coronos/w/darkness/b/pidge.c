/* Pidge the Gnome */
/* Darkness */

#include <mudlib.h>
inherit MONSTER;
  int count; 

void reset(status arg) {
  object obj;

  ::reset(arg);
  if(arg) return;

  set_name("pidge");
  set_alias("gnome");
  set_short("Pidge");
  set_long(
    "Pidge is an average gnome standing a little over a meter tall.  His\n"+
    "curly black locks are tied in a short ponytail at the back of his\n"+
    "head.  His black beard is cut short.  As with all gnomes, his most\n"+
    "prominent feature is his large nose.  Simple leather clothes and a\n"+ 
    "few pieces of jewelry are Pidge's choice of dress.\n");

  load_chat(4, ({ 
    "Pidge: Hello to you.\n",
    "Pidge: It's nice to be visiting this fine city.\n",
  }));
 
  load_l_chat(4,"gnome",({
    "Hello.\n",
    "I like it here.\n",
    }));

  load_a_chat(10,({ 
    "Pidge: Help!\n",
    "Pidge: Guards!\n",
    "Pidge: What are you doing?!\n",
    "Pidge: I came here in peace!\n",
    "Pidge jumps back.\n",
    "Pidge is very nimble and agile.\n",
  }));

  set_race("gnome");
  set_gender(1);
  set_alignment(50);
  set_level(18);
  set_max_hp(800);
  set_hp(800);
  set_ac(27);  /* +1 to AC because he's a small gnome */
  set_wc(14);  /* -1 to WC because he's a small gnome */
  add_class("thief");
  add_class("fighter");
  set_dexterity(25);
  set_two_weapon(15);
  set_multi_attack(50);
  set_steal(50);
  set_steal_chance(20);
  add_money(2000+random(400));
  set_magic_resist(20);
  add_spell_immunity("charm");
  set_heart_ob(this_object());

  if(!present("knife")) {
    int i;
    for(i=0; i<2; i++) {
      move_object(clone_object(
      "/d/coronos/w/darkness/b/knife"),this_object());}
  }

}


void monster_heart_beat()  {
  if(this_object()->query_attack()) {
    if(count!=1) {
      command("wield knife");
      command("wield knife 2 in left hand");    
      tell_room(environment(),
        "Pidge readies himself for battle.\n");
      count = 1;
    }
  }
}
