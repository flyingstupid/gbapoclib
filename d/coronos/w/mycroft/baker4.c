/* main_st5.c */

inherit "inherit/room2";

reset(arg) {

  if(arg) return;

set_short("The 400 Block of Baker Street");
  set_long(
"\tBaker Street\n"+
"This part of Baker Street is home to several fine inns and\n"+
"restaurants to serve those working and staying nearby.  To the\n"+
"west is the 300 Block of Baker Street.  To the \n"+
"north is Yvegni's Speakeasy.  To the south lies the\n"+
"Rosewater Inn.  To the east lies the 500 Block of Baker Street\n");
	
  set_night_desc(
"Twinkling street lamps light the way home for those heading home\n"+
"at this hour of the evening.\n");


  set_items(({



  }));

set_smell("The smell of fine food wafts down the street from the\n"+
"nearby restaurant.\n");



  set_weather(2, 1, 0);
  set_exits(({
"d/coronos/w/mycroft/baker3.c","west",
"d/coronos/w/mycroft/baker5.c","east",
"d/coronos/w/mycroft/bakerinn1.c","south",
"d/coronos/w/mycroft/bakerpub.c","north"
  }));
}

