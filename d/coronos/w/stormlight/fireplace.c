#include <mudlib.h>
inherit ROOM;
status brick_pushed;

void reset(status arg) {
  brick_pushed = 0;
set_short("Inside the Fireplace");
set_long("The fireplace is alot bigger on the inside then one might think.\n"+
"Soot and grim coat the rocky walls and floor here. And you can \n"+
"see the chimney heading up into the sky. The rocks that form the \n"+
"walls are chared slightly, and one of them even looks out of place.\n");

set_weather(0,1,0);

set_exits(({"d/coronos/w/stormlight/house2", "out",
             }));
 

set_items(({"rock#brick", "The rocks are actually finely chiseled bricks, made to look \n"+
                    "like rough cut stone. One brick in particular looks to be sticking \n"+
                    "out farther then the others.\n",
            }));

set_day_items(({"chimney", "The chimney goes straight up from the fireplace. High above \n"+
                     "you can see the bright blue sky.\n",
            }));

set_night_items(({"chimney", "The chimeny goes straight up from the fireplace. High above \n"+
                    "you can see the dark night sky.\n",
            }));

}

void long(status wiz) {
  ::long(wiz);
  if(brick_pushed) {
    write("There is an open door that leads down.\n");
  }
}

void init() {
  ::init();
  add_action("down", "down");
  add_action("push", "push");
}

status down() {
  if(!brick_pushed) return 0;
  write("You go down through the door.\n");
this_player()->move_player("down#", "/d/coronos/w/stormlight/underground/under1");
  return 1;
}

status push(string str) {
  string tmp1, tmp2;
  if(!str) {
    notify_fail("Push what?\n");
    return 0;
  }
  if(sscanf(str, "%sbrick%s", tmp1, tmp2)) {
    if(brick_pushed) {
      notify_fail("The brick is already pushed into the wall.\n");
      return 0;
    }
    write("You push the brick into the wall.\n");
    say(this_player()->query_name()+" pushes a brick in the wall.\n",
	this_player());

    tell_room(this_object(), "A door opens in the floor...\n");
    brick_pushed = 1;
    return 1;
  }
  return 0;
}

