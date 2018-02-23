#include <mudlib.h>
inherit ROOM;

void reset (status arg){
  object ob;

  if(!present("citizen")) {
    ob = clone_object("d/coronos/w/angel/city/monst/citizen");
    move_object(ob, this_object());
  }

    if (arg) return;

    set_short("Main Street");
    set_long(
      "This is the corner of Main Street and East Road.  A fountain and\n"+
      "sitting area is to the northwest.  To the east is the commercial\n"+
      "sector of the city.  A signpost stands at the corner of the road.\n"+
      "Next to the sign post is an old iron lamp post."); 
    set_day_desc(
      "  The streets are\n"+
      "busy with people walking about.\n");   
    set_night_desc(
      "  The lit oil lamp\n"+
      "burns brightly, illuminating the quiet street.\n");
    set_items(({
	"corner",
	"This is where four roads meet.\n",
	"lamp post",
	"This is a simple lamp post.  The oil lamp hangs from the post by a chain.\n",
	"cobblestones#cobblestone",
	"These grey cobblestones have been smoothed and worn over time.\n",
	"road#streets#street",
	"The road is paved with grey cobblestone.\n",           
	"signpost",
	"This is a wodden signpost stuck into the ground.  A few\n"+
	"signs have been nailed into the top of the signpost.\n",
	"post",
	"There are two posts here.\n",
	"fountain#water#sitting area",
	"The fountain is to the northwest.\n",
	"commercial sector#sector",
	"The commercial sector is to the east.\n",
      }));
    set_day_items(({
	"lamp#oil lamp",
	"This is a simple oil lamp that hangs from a post.  It is has a metal\n"+
	"frame and glass panels.  The lamp is unlit right now.\n",
	"people",
	"Many different people go about their way this fine day.\n",
      }));
    set_night_items(({
	"lamp#oil lamp",
	"This is a simple oil lamp that hangs from a post.  It has a metal\n"+
	"frame and glass panels.  The lamp shines brightly, illuminating the\n"+
	"area.\n",
      }));
    set_sign_message(
      "West: Main Street \n"+
      "North: East Street \n"+
      "Northeast: Western Commerce \n"+
      "Southeast: D'Tagma Way \n");
    set_smell(
      "You smell nothing but fresh air.\n");
    set_listen(
      "You faintly hear the trickling of water from the fountain\n"+
      "to the northwest.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/darkness/mainst4", "west",
	"/d/coronos/w/darkness/eastrd5", "north",
	"/d/coronos/w/darkness/fountn", "northwest",
"/d/coronos/w/alena/ille/c_4","northeast",
"/d/coronos/w/alena/ille/c_5","southeast",
      }));
}
