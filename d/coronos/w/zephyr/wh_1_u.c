/*wh_1_u.c ~zephyr
  An Upper Room of a Large Warehouse*/

#include <mudlib.h>
inherit ROOM;

void reset(status arg){
	if (arg) return;

	set_short("An Upper Room of a Large Warehouse");

	set_long("The upper level holds more crates and sacks stakced up\n"+
		"against the walls.  There is a space to walk around\n"+
		"between the crates and the balcony's railing.\n");

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
		"ladder","A sturdy wooden ladder leading down to the\n"+
			"lower level.",
		"window#windows","Regularly paned windows with a fine\n"+
			"layer of dust collecting on them."
	}));

   	set_smell("A mixture of smells rise from the assorted goods\n");

	set_weather(1, 2, 0);

	set_exits(({
		"/d/coronos/w/zephyr/wh_1","down"
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
		move_object(target,"wh_1.c");
	}
	else{
		write("climb <what>?");
	}
return 1;
}



			

