inherit "inherit/room2";

reset (arg) {
  if(arg) return;
  set_short("kitchen");
  set_long("This is the school's kitchen. A large fireplace burns warmly\n"+
     "on the eastern wall. A large pot hangs above the fire, bubbling\n"+
     "away. Large quantities of food are being prepared on an old\n"+
     "table, and a stack of plates is nearby.\n");
  set_weather(2, 1, 0);
  set_listen("You can hear thumps and shouting elsewhere in the house.\n");
  set_items(({"fire", "A large fire used to cook meals.\n",
     "fireplace", "A very large stone fireplace.\n",
     "pot", "A large pot of soup, bubbling over the fire.\n",
     "food", "You are sure exactly what food this is.\n",
     "table", "An old, betten table use to prepare food.\n",
     "plates", "A tall stack of plates ready to serve the students.\n"}));
  set_exits(({"/d/tempus/w/serepion/school9.c", "west"}));
}
