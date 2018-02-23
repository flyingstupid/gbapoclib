inherit "inherit/room2";

object stick, cloth, m1, m2;

reset (arg) {
  if(!stick) {
     stick = clone_object("/d/tempus/w/serepion/obj/stick.c");
     move_object(stick, this_object());
  }
  if(!cloth) {
     cloth = clone_object("/d/tempus/w/serepion/obj/cloth.c");
     move_object(cloth, this_object());
  }
  if(!m1) {
     m1 = clone_object("/d/tempus/w/serepion/obj/match.c");
     move_object(m1, this_object());
  }
  if(!m2) {
     m2 = clone_object("/d/tempus/w/serepion/obj/match.c");
     move_object(m2, this_object());
  }
  if(arg) return;
  set_short("Space under the floorboards");
  set_long("You stand in a crawlspace under the floorboards of the old\n"+
     "woman's house. The air is warm and damp, and light filters down\n"+
     "through a hole in the floorboards.\n");
  set_weather(2, 1, 0);
  set_exits(({"/d/tempus/w/serepion/floor2.c", "north",
     "/d/tempus/w/serepion/floor12.c", "west"}));
  set_listen("You can hear the woman through the hole in the boards.\n");
  set_items(({"hole", "It's the hole you fell through.\n"}));
}
