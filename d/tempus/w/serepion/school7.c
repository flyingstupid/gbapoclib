inherit "inherit/room2";

reset (arg) {
  load_door(({"file", "/d/tempus/w/serepion/school2",
     "direction", "west door", 
     "long", "A very thick, oak door.\n",}));
  if(arg) return;
  set_short("principal's office");
  set_long("You are standing in the office of the principal of the school\n"+
     "of hard knocks. The office is well decorated, consisting of a nice\n"+
     "solid desk, soft comfy chair, a few plants, and nice curtains on\n"+
     "the windows. In front of the desk is a hard chair.\n");
  set_weather(2, 1, 0);
  set_listen("You can hear thumps and shouting elsewhere in the house.\n");
  set_items(({"desk", "This is a very large, oak desk. It is completely"+
     "clean on top.\n",
     "comfy chair", "A large, padded chair used by the principal.\n",
     "plants", "Various plants, still alive.\n",
     "curtains", "Heavy curtains, used to reduce the amount of light.\n",
     "windows", "Heavy paned windows, draped with heavy curtains.\n"}));
}
