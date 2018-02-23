inherit "inherit/room2";

reset (arg) {
  if(arg) return;
  set_short("dining hall");
  set_long("This is the center of the entire dining hall. A large walkway\n"+
     "runs between the tables from the hallway to the kitchen on the\n"+
     "east side of the dining hall. The tables are cleared, and chairs\n"+
     "set for meal time. Large banners hang from the walls.\n");
  set_weather(2, 1, 0);
  set_listen("You can hear thumps and shouting elsewhere in the house.\n");
  set_items(({"tables", "Large, well worn tables used by the students.\n",
     "chairs", "The chairs are packed around the tables.\n",
     "banners", "Banners won by the school in various sporting events.\n"}));
  set_exits(({"/d/tempus/w/serepion/school8.c", "north",
     "/d/tempus/w/serepion/school12.c", "east",
     "/d/tempus/w/serepion/school10.c", "south",
     "/d/tempus/w/serepion/school4.c", "west"}));
}
