inherit "inherit/room2";

object woman;
int going;

reset (arg) {
  if(!woman) {
     woman = clone_object("/d/tempus/w/serepion/mon/woman.c");
     move_object(woman, this_object());
     going = 0;
   }
  if(arg) return;
  set_short("Old house");
  set_long("This is one of the older buildings of the city, belonging to a rather\n"+
     "old woman. The house looks clean, with plenty of furnishings, but there\n"+
     "are many mouse holes in the walls, and a few holes in the floorboards.\n");
  set_weather(2, 1, 0);
  set_no_fight(1);
  set_exits(({"/room/city/main_st2.c", "south"}));
}

init() {
  ::init();
  add_action("offerhelp", "offer");
}

offerhelp(str) {
  if(!woman) {
     write("Offer help to whom?\n");
     return 1;
  }
  if(going == 1) {
     write("The woman tells you that someone is already helping her.\n");
     return 1;
  }
  if(str == "help") {
     write("The woman seems very pleased by your offer.\n");
     write("She mutters some words, and you start to shrink!\n");
     write("You shrink very quickly, and fall through a hole in the floor.\n");
     say("The woman seems very happy. She mutters some words, and "+this_player()->query_name()+" starts to shrink.\n");
       this_player()->move_player("through a hole in the floor#/d/tempus/w/serepion/floor1.c");
     going = 1;
     return 1;
  }
}

done() {
  going = 0;
  if (woman) destruct(woman);
  return 1;
}
