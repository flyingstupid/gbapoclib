#define NAME	(string)this_player()->query_name()

status equip() {
  int i;
  object *invent;

  invent = all_inventory(this_player());
  write("You expertly equip yourself for battle . . . \n");
  say(NAME+" expertly equips "+this_player()->query_objective()+"self "+
	"for battle.\n", this_player());

  for(i=0; i<sizeof(invent); i++) {
    if(invent[i]->query_wc()) 
      command("wield "+(string)invent[i]->query_name(), this_player());
    else if(invent[i]->query_ac())
      command("wear "+(string)invent[i]->query_name(), this_player());
  }
  write("You finish your dressing maneouver.\n");
  return 1;
}


