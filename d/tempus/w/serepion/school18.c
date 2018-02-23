inherit "inherit/room2";

reset (arg) {
  if(arg) return;
  set_short("entry way");
  set_long("You are standing in the entry hall of the school of hard knocks.\n"+
     "Pictures of all the presidents line the walls, many of them have\n"+
     "interesting oddities. A large black carpet seems to invite you into\n"+
     "the rest of the school.\n");
  set_weather(2, 1, 0);
  set_listen("You can hear thumps and shouting elsewhere in the house.\n");
  set_items(({"carpet", "A large, black carpet almost as wide as the hall,"+
     " extending into the school.\n",
     "pictures", "All of the pictures are well taken care of, but many of"+
     " the presidents weren't.\n Some are missing parts of ears, have"+
     " scars, or are wearing eyepatches.\n"}));
  set_exits(({"/d/tempus/w/serepion/school4.c", "east",
     "/room/city/market2.c", "west"}));
}
