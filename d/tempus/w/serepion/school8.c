inherit "inherit/room2";

reset (arg) {
  if(arg) return;
  set_short("dining hall");
  set_long("This is the northern end of the dining hall, filled with\n"+
     "tables and chairs for the students to eat at. A large fireplace\n"+
     "is in the northern wall, and is not lit. Banners proclaiming the\n"+
     "school's greatness hang from the walls.\n");
  set_weather(2, 1, 0);
  set_listen("You can hear thumps and shouting elsewhere in the house.\n");
  set_items(({"tables", "Empty tables where the students eat.\n",
     "chairs", "Chairs are set around each table for the students.\n",
     "fireplace", "The fireplace looks more like a decorative piece.\n",
     "banners", "Many banners won in various sports of excitement.\n"}));
  set_exits(({"/d/tempus/w/serepion/school9.c", "south"}));
}
