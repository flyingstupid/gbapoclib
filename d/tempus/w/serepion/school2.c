inherit "inherit/room2";

reset (arg) {
  load_door(({"file", "/d/tempus/w/serepion/school7",
     "direction", "east door", 
     "long", "A very thick, oak door.\n",}));
  load_door(({"file", "/d/tempus/w/serepion/school3",
     "direction", "south door", 
     "long", "A large oak door engraved with ivy.\n",}));
  if(arg) return;
  set_short("secretary's office");
  set_long("This is probably the entrance to the principal's office. A\n"+
     "large cluttered desk sits next to the east door. Several chairs\n"+
     "line the west wall, and a large plant sits in the corner.\n");
  set_weather(2, 1, 0);
  set_listen("You can hear thumps and shouting elsewhere in the house.\n");
  set_items(({"desk", "It's the secretary's desk. It is cluttered with"+
     " various papers. On one corner\nis a nameplate.\n",
     "papers", "Papers filled with information for someone.\n",
     "nameplate", "The nameplate reads: Ms. Sorof\n",
     "plant", "You aren't sure what kind of plant this is. It looks dead.\n",}));
}
