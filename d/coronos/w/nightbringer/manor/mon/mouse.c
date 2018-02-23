#include <mudlib.h>
inherit MONSTER;

reset (arg) {
  ::reset(arg);
  if(arg) return;
  set_level(1);
  set_al(-10);
  set_plural("mice");
  set_name("mouse");
  set_short("A Mouse");
  set_long("This is just a normal brown mouse with large beady, black \n"+
     "eyes, pointed ears, pink nose and a long tail.\n");
  set_wc(5);
  set_ac(3);
  load_chat(({"A mouse squeaks noisily.\n",
     "A mouse looks around for more food.\n",
     "A mouse sniffs you for food.\n"}));
}
