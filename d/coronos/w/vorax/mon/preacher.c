#include <mudlib.h>
inherit MONSTER;
void reset(status arg)
  {
    ::reset(arg);
    if (arg) return;
    set_name("preacher");
    set_race("human");
    set_gender(1);
    set_short("The Preacher");
    set_long(
      "This is the preacher.  He is a fairly short man.\n"+
      "He wears all black, and always has a bible near\n"+
      "his hand at all times.  Right now he is sitting down\n"+
      "in his desk writing something.  You think it could\n"+
      "be his sermon for today or tonight's services.\n");
  set_plural("preachers");
    set_level(10);
    set_al(100);
    set_wc(14);
    set_ac(8);
    set_hp(175);
    set_money(700);
    set_max_hp(175);
    load_chat(8, ({
      "The preacher asks:  What can I do for you my son?\n",
      "The preacher says:  Please leave me to my thoughts.\n",
    }));
    load_a_chat(8, ({
      "The preacher says:  You dare attack me?\n",
      "The preacher says:  I'm a holy man!\n",
    }));
  }
