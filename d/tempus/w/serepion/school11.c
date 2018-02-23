inherit "inherit/room2";

reset (arg) {
  if(arg) return;
  set_short("study");
  set_long("This would be a great place to study, if there wasn't so much\n"+
     "dust, noise, and spiders. There are still a few tables left here,\n"+
     "but there are no chairs. All the windows are covered up.\n");
  set_weather(2, 1, 0);
  set_listen("You can hear thumps and shouting elsewhere in the house.\n");
  set_items(({"tables", "The tables are without chairs, and covered with dust.\n",
     "windows", "The windows have been boarded over.\n",
     "spiders", "Several harmless spiders inhabit this area.\n"}));
  set_exits(({"/d/tempus/w/serepion/school6.c", "west"}));
}
