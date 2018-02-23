/* main_st5.c */

inherit "inherit/room2";

reset(arg) {

  if(arg) return;

set_short("Baker Street");
  set_long(
"\tBaker Street\n"+
"You stand on Baker Street which runs east and west .\n"+
"To the north lie palatial estates seperated from you by wrought iron\n"+
"fences.  To the south is the Museum of Ancient Art, part of\n"+
"the governmental annex.  To the east, there are several law \n"+
"offices.\n");
	
  set_night_desc(
"Flickering streetlights bathe the avenue in a warm glow.\n");

  set_day_desc(
"Street lights line the carefully tended sides of the avenue.\n");

  set_items(({
"fences#fences",
"The wrought iron fences keep the gawkers from trampling on the\n"+
"carefully tended lawns of the mansions lining the road.",



  }));

  set_smell("The fragrent smells of new flowers comes from the north.\n");


  set_day_items(({
"lamps", "They are wrought-iron street lamps",
     "torch#torches", "They are not lit, awaiting night fall"
  }));

  set_weather(2, 1, 0);
  set_exits(({
"players/mycroft/workroom.c","office",
"d/coronos/w/mycroft/baker2.c","east",
  }));
}

