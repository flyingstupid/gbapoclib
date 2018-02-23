#include <mudlib.h>
#define PATH "d/coronos/w/angel/city/gardens/"
#define MONST "d/coronos/w/angel/city/monst/"
inherit ROOM;

status enter();
void reset(status arg) {
    object obj;
    int i;
    if(!present("dingopup")){
	for(i=0; i<3; i++) {
	    move_object(clone_object(MONST+"dingopup"),this_object());
	}
    }
    if(arg)return;
    set_weather(1,3,0);
    set_short("the city garden");
    set_long(
      "The ground consists of sandy soil and is mostly hard \n"+
      "packed. In certain areas the ground is soft and full of \n"+
      "paw prints. A small mound rises up and looks very dark \n"+
      "within a small opening to what seems to be a den. Small \n"+
      "bones lay by the entrance, along with pieces of fur that \n"+
      "seemingly have been discarded.\n");
    set_items(({
	"den#dark den",
	"The den looks dark and it seems like there is something \n"+
	"moving within.",
	"movement#darkness#inside den#inside the den",
	"You might be able to see more if you actually entered the den",
	"mound#hill",
	"It seems to be a possible dingo den",
      }));
    set_exits(({
	PATH+"garden8","north",
	PATH+"garden9","northeast",
	PATH+"garden11","west",
      }));
}
void init() {
    ::init();
    add_action("enter","enter");
}
status enter() {
    write("You climb into the den after dropping to your "+
      "knees and watching your head.\n");
    this_player()->move_player("into the den#"+PATH+"den1");
    return 1;
}
