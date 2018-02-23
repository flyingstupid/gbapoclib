# include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
      
  if(arg) return;
  set_name("fisher");
  set_alt_name("man");
  set_alt_name("fisherman");
  set_level(8);
  set_gender(1);
  set_short("An old fisherman");
  set_long(
    "The old fisherman has a wildely grown beard and a pipe in the \n"+
    "corner of his mouth. He is dressed in some old rags that smells \n"+
    "terribly of rotten fish. He doesn't seem to notice you at all.\n");
  set_alignment(50);
  add_money(random(150)+100);
  set_race("human");
  load_chat(5, ({
    "The old fisherman puffar on his pipe.\n",
    "The old man complains about the weather.\n",
    "The fisherman says: We are going to have bad weather tomorrorw,\n"+
    " I'll know it.\n",
    "The old fisherman sighs as he he gazes over the sea.\n",
}));
   load_a_chat(6, ({ "The old man exclaims: Please don't hurt me!\n",
             "The old fisherman cries for help.\n",
              "The fisher screams in agony.\n",
}));
}
