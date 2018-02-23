#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
set_weather(2,1,1);
set_short("Annex Lobby");
  set_long(
"\tLobby of the Governmental Annex\n"+
"You stand in the middle of a large room with a high vaulted\n"+
"ceiling.  On the walls are murals of famous scenes in the history\n"+
"of Ille Coronos, including one depicting its founding.  There a\n"+
"several leather chairs for those who are waiting to meet with\n"+
"important officials.  To the south are the offices of the Ministry\n"+
"of Justice, the enforcers of order in the realm.  To the west is the\n"+
"public entrance to the Museum of Ancient Art, depository of\n"+
"Ille Coronos' cultural heritage.  To the east lies the newly\n"+
"refurbished post office, a modern wonder of efficiency and \n"+
"convienience!\n");

  set_night_desc(
"Oil lamps hang from the ceiling, lighting the interior of the Lobby\n"+
"with a bright, cheerful glow.  The occasional office window is lit \n"+
"from within by the desk lamp of a clerk trying to catch up on his\n"+
"tasks.\n");

  set_night_items(({
"lamps",   "Large oil lamps hanging by chains from the ceilings",
  }));


  set_exits(({
"d/coronos/w/mycroft/bakerpost.c","east",
"d/coronos/w/mycroft/bakermus1.c","west",
"d/coronos/w/mycroft/bakerpol.c","south",
"d/coronos/w/mycroft/baker3.c","north",
  }));
}
