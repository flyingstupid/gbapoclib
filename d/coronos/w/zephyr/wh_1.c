/*wh_1.c ~zephyr
  A Large Warehouse*/

#include <mudlib.h>
inherit ROOM;

void reset(status arg){
	if (arg) return;

	set_short("A Large Warehouse");

	set_long("Here is a large warehouse full of different goods\n"+
		"packaged in wooden crates, chests, and sacks of all\n"+
		"shapes and sizes.  There are windows above that circle\n"+
		"the room.  The place seems to be in fair shape.  It is\n"+
		"suprisingly clean for having a dirt floor.  There is a\n"+
		"ladder leading up to a second balcony which appears\n"+
		"also to be full of different goods and cargo.\n");

	set_items(({
		"crates#crate","Wooden crates of all types some have\n"+
			"stamping on them telling the different contents\n"+
			"which they hold and where they came from.",
		"stamping#stamp#stampings","Most of the stamps are in a\n"+
			"language you can't read.  A few read such\n"+
			"things as:  'leathers:Zanzabar','iron\n"+
			"ore:Badlands', and 'cotton:Saxet'.",
		"chest#chests","A few unmarked chests made of strong Oak\n"+ 			"and iron, with sturdy locks on them.",
		"sack#sacks","An assortment of sacks with markings,\n"+
			"which tell their contents and where they came\n"+
			"from.",
		"markings#marking","You glance at the differet markings\n"+
			"and read:  'coffee:Saxet', 'sugar:Jomark', and\n"+
			"'spice:Arrakis'.",
		"ladder","A sturdy wooden ladder leading up to the upper\n"+
			"level.",
		"window#windows","Regularly paned windows with a fine\n"+
			"layer of dust collecting on them."
	}));

   	set_smell("A mixture of smells rise from the assorted goods\n");

	set_weather(1, 2, 0);

	set_exits(({
		"/d/coronos/w/zephyr/wh_2.c","west",
		"/d/coronos/w/zephyr/wh_1_o.c","south",
		"/d/coronos/w/zephyr/wh_1_u.c","up"
	}));
}

void init(){
	::init();
	add_action("open_chest","open");
	add_action("unlock_chest","unlock");
	add_action("climb_ladder","climb");
}

status open_chest(string str){
	if(str == "chest"){
		write("It is locked!\n");
	}
	else if(str == "chests"){
		write("They are locked!\n");
	}
	else{
		write("open <what>?\n");
	}
return 1;
}

status unlock_chest(string str){
	if((str == "chest") || (str == "chests")){
		write("You fail miserably...\n");
	}
	else{
		write("unlock <what>?\n");
	}
return 1;
}

status climb_ladder(string str){
	object target;
	target=present(this_player());
	if(str == "ladder"){
		move_object(target,"wh_1_u.c");
	}
	else{
		write("climb <what>?");
	}
return 1;
}



			

