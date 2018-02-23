inherit "inherit/room2";

object kmouse;

reset (arg) {
  if(!kmouse) {
     kmouse = clone_object("/d/tempus/w/serepion/mon/kmouse.c");
     move_object(kmouse, this_object());
  }
  if(arg) return;
  set_short("In the wall");
  set_long("You are standing in a large space behind the wall. You can\n"+
     "see the east end of the wall, and a mouse hole in the south\n"+
     "side of the space. Debris litters the area.\n");
  set_weather(0, 1, 0);
  set_exits(({"/d/tempus/w/serepion/wall6.c", "west"}));
  set_items(({"hole", "Looking the hole, you can see inside the house.\n",
     "debris", "Random bits of wood, cloth, and other assorted items.\n"}));
}
