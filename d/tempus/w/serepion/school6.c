inherit "inherit/room2";

reset (arg) {
  reset_doors(0);
  if(arg) return;
  set_short("library");
  set_long("This is the school's library. It is filled with shelves, which\n"+
     "are only about half full of books. A small desk sits near the door,\n"+
     "and a study area is to the east. Odd how noone is here.\n");
  set_weather(2, 1, 0);
  set_listen("You can hear thumps and shouting elsewhere in the house.\n");
  set_items(({"shelves", "Half filled shelves, covered with dust.\n",
     "books", "The books are almost made of dust!\n",
     "desk", "The desk looks like it hasn't been disturbed in ages.\n"}));
  set_exits(({"/d/tempus/w/serepion/school11.c", "east"}));
  load_door(({"file", "/d/tempus/w/serepion/school5",
     "direction", "north door", "closed",
     "long", "A small, wooden door that is seldom used.\n",}));
}
