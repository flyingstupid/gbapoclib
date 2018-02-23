/* main_st5.c */

inherit "inherit/room2";

reset(arg) {

  if(arg) return;

set_short("300 Block of Baker Street");
  set_long(
"\tBaker Street\n"+
"You are standing on the 300 Block of Baker Street. To theeast lies\n"+
"the central gate, leading away from the bureaucratic district\n"+
"and out into the rest of the city.\n"+
"To the west lies the 200 Block of Baker Street.\n"+
"To the south is the entrance to the mammoth Governmental Annex,\n"+
"home of the Post Office, Police Barracks, Bank and Museum.\n");
	




  set_smell("The fragrent smells of new flowers comes from the north.\n");



  set_weather(2, 1, 0);
  set_exits(({
"d/coronos/w/mycroft/bakerd1.c","east",
"d/coronos/w/mycroft/baker2.c","west",
"d/coronos/w/mycroft/annex1.c","south",
  }));
}

