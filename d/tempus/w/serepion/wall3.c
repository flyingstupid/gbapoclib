inherit "inherit/room2";

object m1,m2,m3;

reset (arg) {
  if(!m1) {
     m1 = clone_object("/d/tempus/w/serepion/mon/mouse.c");
     move_object(m1, this_object());
  }
  if(!m2) {
     m2 = clone_object("/d/tempus/w/serepion/mon/mouse.c");
     move_object(m2, this_object());
  }
  if(!m3) {
     m3 = clone_object("/d/tempus/w/serepion/mon/mouse.c");
     move_object(m3, this_object());
  }
  if(arg) return;
  set_short("In the wall");
  set_long("You are inside the wall of the house. Right below you is\n"+
     "a hole in the wood, allowing mice below the house.\n");
  set_listen("You hear the sounds of mice all around you.\n");
  set_weather(0, 1, 0);
  set_exits(({"/d/tempus/w/serepion/wall4.c", "east",
     "/d/tempus/w/serepion/wall2.c", "west",
     "/d/tempus/w/serepion/floor5.c", "down"}));
}
