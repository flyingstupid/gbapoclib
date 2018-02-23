/* main_st5.c */

inherit "inherit/room2";

reset(arg) {

  if(arg) return;

set_short("The 500 Block of Baker Street");
  set_long(
"\tBaker Street\n"+
"You stand in the middle of the 500 Block of Baker Street. \n"+
"is very clean and tidy in keeping with the professional look of\n"+
"the area.  This particular block seems devoted to the \n"+
"administrative offices of the Church of the All-God.  To the north\n"+
"lies a strange hybrid of church and office building that is the\n"+
"Church's International Headquarters.  To the south is the \n"+
"gargantuan Governmental Annex.  To the east lies the 600 Block oof\n"+   
"of Baker Street.\n");
	





set_smell("The smell of copier toner and stamp glue fills the air.\n");



set_weather(2,1,0);
  set_exits(({
"//d/coronos/w/mycroft/baker4.c","west",
"//d/coronos/w/mycroft/baker6.c","east",
"//d/coronos/w/mycroft/bakerchurch1.c","north"
}));
}

