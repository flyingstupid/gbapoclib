/*wh_1_o.c ~zephyr
  Outside of a Large Warehouse*/

#include <mudlib.h>
inherit ROOM;

void reset(status arg){
	if (arg) return;

	set_short("Outside of a Large Warehouse");

	set_long("There is a large warehouse here with large double\n"+
		"doors to the north.  The outside is covered in fine\n"+
		"wood paneling with windows around the outside on what\n"+
		"appears to be a second level.  The building seems to\n"+
		"extend to the west, but no entrances can be seen on\n"+
		"that side.\n");

	set_items(({
		"door#doors","Large wooden doors with sturdy hinges and\n"+
			"iron framework",
		"paneling","It is fine paneling...",
		"window#windows","Seem to be normal windows...",
	}));

	set_weather(1, 0, 0);

	set_exits(({
		"/d/coronos/w/zephyr/wh_1","north"
	}));
}




			

