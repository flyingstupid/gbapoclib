inherit "inherit/room2";

reset (arg) {
  if(arg) return;
  set_short("In Escher's house");
  set_long("You are standing inside a large room of the tower. The\n"+
     "walls, floor, and ceiling are made of black and white marble\n"+
     "with marble torches hanging from the walls, lighting up the\n"+
     "place. Very little furniture decorates the place, and dirt\n"+
     "and dust cannot be seen here. A door leads out of the tower,\n"+
     "and a doorway leads to the right around the tower.\n");
  set_weather(2, 1, 0);
  set_exits(({"/d/tempus/w/serepion/maze26.c", "north"}));
}
