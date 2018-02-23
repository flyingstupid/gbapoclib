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
  set_short("Space under the floorboards");
  set_long("You are at a corner of the crawlspace. Above you is a large\n"+
     "trapdoor, made of wood and iron.\n");
  set_weather(0, 1, 0);
  set_exits(({"/d/tempus/w/serepion/floor10.c", "north",
     "/d/tempus/w/serepion/floor12.c", "east"}));
  set_listen("You hear the sounds of mice all around you.\n");
  set_items(({"trapdoor#door", "It looks like it's made of oak.\n"}));
}
