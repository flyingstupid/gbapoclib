#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gzabo");
  set_alias("hill giant");
  set_race("giant");
  set_gender(1);
  set_alignment(-50);
  set_short("Gzabo, the hill giant");
  set_long(
	"Gzabo is a simple, dull minded hill giant who lives in the \n"+
	"elf forest. He spends his days searching for food to fill  \n"+
	"and satisfy his huge appetite! Although he's not very smart\n"+
	"he is certainly very strong!\n");
  set_level(12);
  add_money(100 + random(50));
  load_chat(10,({ "Gzabo scratches his tummy.\n",
	"Gzabo ponders.\n",
	"Gzabo tries to think about something.\n",
	"Gzabo says: Hey, have you got my... oh...I forgot.\n",
	"Gzabo says: Where's my... ...oh... I forgot.\n",
	"Gzabo tries to remember something.\n",
  }));
  load_a_chat(10,({ "Gzabo exclaims: You baddie!\n",
	"Gzabo says: Go away.\n",
	"Gzabo exclaims: That hurts!\n",
  }));
}

