#include <mudlib.h>
inherit ROOM;

void reset(status arg){
    if(!present("blah")){
	int i;
	for(i=0;i<4; i++){
	    move_object(clone_object("/players/alena/temp/monst"),this_object());
	}
    }

    load_door(({
	"destination","blah/blah/blah2",
	"direction","north door",
	"key id","blah key",
	"closed", 1,
	"lock description", "A blah blah lock"+BS(n),
	"lock id", "lock",
	"door id", "blah door",
	"long","A blah door made of blah blah."+BS(n),
      }));

    if(arg) return;

    set_long(
      "Blah blah blippity blah blah blah."+BS(n));

    set_short("the blah room");
    set_weather(1,1,1);

/* int light, int weather, int climate */
/* light: Magical light is 3-5, magical darkness is -1 to -3 and
    normal darkness is 0 */
/* weather: 0 default; 1 none; 2 inside; 3 shelter; 4 full weather */
/*climate: 0 normal; 1 bad weather; 2 tropical; 3 jungle;
    4 desert; 5 artic; 6 sea */
    set_night_desc("Blah blah blah at night blah."+BS(n));
    set_items(({
	"blah#blahs",
	"Blah blah blah blippity blah blah",
      }));

    set_exits(({
	"/players/alena/blah/blippity","north",
      }));

    set_smell("Blah smells like blah blah."+BS(n));
    set_listen("You hear blah blah blippity blah."+BS(n));
}

void init() {
  ::init();
  add_action("echo_message", "echo");
}

status echo_message(string str) {
  if(!str) {
    notify_fail("Echo <what>?\n");
    return 0;
  }
  write("You echo: "+str+"\n");
  say("::"+str+"\n", this_player());
  return 1;
}
