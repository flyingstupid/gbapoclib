#include <mudlib.h>
inherit MONSTER;
void reset(status arg)
  {
    ::reset(arg);
    if (arg) return;
    set_name("girl");
    set_race("human");
    set_gender(2);
    set_short("A little girl");
    set_long(
      "This is a very small little girl.  She couldn't be over\n"+
      "six years old, if that.  She has brown hair tied back\n"+
      "with a small ribbon.  She looks as if she is enjoying\n"+
      "game that she is playing, while waiting for her daddy, \n"+
      "Galdron, to come home.\n");
  set_plural("little girls");
    set_level(5);
    set_al(0);
    set_wc(9);
    set_ac(5);
    set_hp(80);
    set_money(200);
    set_max_hp(80);
    load_chat(8, ({
      "The little girl asks:  Would you like to play?\n",     
      "The girl asks: Have you seen my daddy?\n",
      "The girl wonders when her daddy will return from work.\n",
    }));
    load_a_chat(8, ({
      "The little girl yells:  Mommy help me!\n",
    }));
  }
  
