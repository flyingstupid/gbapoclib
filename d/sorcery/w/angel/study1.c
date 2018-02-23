#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(!present("red chair")) {
    move_object(clone_object("d/ooc/w/alena/red_chair"), this_object());
  }

  if(arg) return;
  set_short("the tower of sorcery");
  set_long(
"This is a simple room designed for comfort of reading. The walls bear \n"+
"paintings of various professors who have studied here at the library, \n"+
"and who have helped to make it one of the best in all the realms of Magia. \n");

  set_items(({
"wall#walls",
"They have been painted a soft grey. On them hang a few paintings",
"frame#frames", "They are all identical, all worked in gold and steel",

"painting#paintings",
"One is of the Archmagus Llore, one of the former leaders of the White \n"+
"Robes. Another depicts a former head of the Grey Robes; Justice Stronghand.\n"+
"There is a frame who you would assume would support one of the paintings \n"+
"of a former Black Robe, but the picture is missing. There is a small plaque\n"+
"on the frame on the bottom with his name on it.\n",

"archmagus llore#llore",
"Ekimthanis Llore, by the picture, appears to be a grey elf of noble standing",
"justice#justice stronghand",
"A man of strong charisma, even through his portrait.",

"plaque",
"It reads: The One Whose Name is Spoken in Whispers", 
  }));

 set_weather(2, 1, 0);

  set_exits(({
	"d/sorcery/w/angel/lib", "north",
  }));
}

