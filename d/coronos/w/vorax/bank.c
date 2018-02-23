#include <mudlib.h>
inherit BANK;

void reset(status arg) {
  owner = "gnak";
  if(!present("gnak")) {
  move_object(clone_object("/d/coronos/w/vorax/mon/gnak.c"),this_object());
  }
  ::reset(arg);
  if(arg) return;
  set_short("the Ille Coronos Vault");
  set_long(
  "\tThe Ille Coronos Vault.\n"+
  "A large desk sits in the middle of the room, and the shine of\n"+
  "polished wood gleams.  There are several lanterns hanging from\n"+
  "the polished white ceiling.  There is a large iron gate across\n"+
  "the room that leads to the vault.\n"
  );

  set_items(({
    "large desk#desk",
    "This is an oak desk, in which the bank keeper normally sits.",
    "lanterns",
    "These lanterns illuminate the entire room.",
    "white ceiling#ceiling",
    "The ceiling is shiny, and reflects the light.",
    "iron gate#gate",
    "This iron gate protects your money.",
    "vault",
    "The vault is where the money is kept.",
  }));
  
  set_weather(2, 0, 0);

  load_door(({
    "destination", "d/coronos/w/darkness/b/hall/hall6.c",
    "direction", "north door",
    "long",
    "A large heavy oak door.\n",
  }));

  set_smell("The smell of old currency is in the air.\n");
  set_listen("You can hear coins clanging against each other.\n");
  }
  int query_no_fight() { return 1; }
  int query_prop(string str) {
  if(str == "Nulmagic") return 1;
  else return query_prop(str);
  }
