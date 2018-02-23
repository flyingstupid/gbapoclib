inherit "inherit/room2";

reset (arg) {
  if(arg) return;
  set_short("west bunk room");
  set_long("The students' bunks surround you at the north end of the bunk\n"+
     "room. Windows line the north and west wall, lighting up the place.\n"+
     "Locked footlockers sit at the foot of each set of beds. Some of\n"+
     "beds are currently occupied by resting students.\n");
  set_weather(2, 1, 0);
  set_listen("You can hear thumps and shouting elsewhere in the house.\n");
  set_items(({"windows", "Windows without covers to let in as much light"+
     " as possible.\n",
     "footlockers#lockers", "These belong to the students.\n",
     "bunks#beds", "You'd better not disturb any of the sleeping students.\n",
     "students", "These boys look tough, and try to act the part.\n"}));
  set_exits(({"/d/tempus/w/serepion/school14.c", "south"}));
}
