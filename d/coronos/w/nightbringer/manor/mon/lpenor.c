/*LORD PENOR.C */
/* Author:DarkBringer */
/* 04-24-97 */


#include <mudlib.h>
inherit MONSTER;

reset(status arg){

  ::reset(arg);
  if(arg) return;

  if(!present("sword")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/weapon/thsword.c"),this_object());
    init_command("wield sword");
    }



  set_short("Lord Penor");
  set_name("lord penor");
  set_alias("penor");
  set_race("human");
  set_long(
" Lord Penor is a middle aged human of about 45 years of age. Though\n"+
" he's starting to get old, he is still quite powerful. Muscles ripple\n"+
" all over his body. He stands six feet tall, and is considered very\n"+
" handsome by the ladies in town, most notably, Lady Penor. He wears \n"+
" a suit of specially crafted chainmail armour, made for him in a joint\n"+
" effort by the Mountain Dwarves and the High Elves. At his side he wears\n"+
" an enourmous two-handed sword that most men would find impossible to wield.\n");


  set_gender(1);
  set_level(45);
  set_ac(20);
  set_wc(32);

  add_money(3000 + random(2000));
  add_class("fighter");
  add_class("mage");

  load_spells(40,({ "burning hands", "magic missile", "chill touch" }));

  load_chat(5, ({"Lord Penor exclaims: I am not getting senile!\n",
      "Lord Penor yells: I tell you, there's something beneath the cellar!\n",
    }));

  load_a_chat(5,({"Lord Penor says: The town council will not stand for this!\n",
    "Lord Penor asks: Are you as stupid as you are ugly?\n",
    }));


  }
