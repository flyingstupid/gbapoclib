#include <mudlib.h>
inherit MONSTER;

reset (arg) {
  ::reset(arg);
  if(arg) return;
  set_level(5);
  set_race("human");
  set_name("woman");
  set_short("Old woman");
  set_long("This woman is rather old, and appears frail. Her clothes\n"+
     "hang loosely about her skeleton-like body. Her long white hair\n"+
     "is well combed, and braided down to the mibble of her back. She\n"+
     "seems to be upset about something. Maybe you can offer her some\n"+
     "help to solve her problems.\n");
  set_hp(80);
//init_command("wield staff");
  set_wc(9);
  set_ac(5);
  set_al(100);
  load_chat(10,({"The woman asks: Oh! What will I do?\n",
     "The woman asks: How will I get rid of them?\n",
     "The woman begs: Will you help me?\n",
     "The woman screams: They're everywhere!\n",
     "The woman swings her broom at a mouse.\n",
     "The woman bursts into tears.\n"}));
  add_spell_immune("fear");
}
