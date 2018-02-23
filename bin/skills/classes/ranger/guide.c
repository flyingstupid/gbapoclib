#define REAL		(string)this_player()->query_name(1)
#define NAME		(string)this_player()->query_name()

static mixed *door_info, *secret_door_finders;

status guide(string str) {
  object ob, tp;
  string file;
  int i;
  object guild_object;
  if(guild_object = present("guild_object", this_player())) {
    if(guild_object->check_alignment()) {
      notify_fail("You are too evil to use your God given powers.\n");
      return 0;
    }
  }

  tp = this_player();
  door_info = (mixed *)environment(tp)->query_doors();

  for(i=0; i<sizeof(door_info); i++) {
    if(door_info[i][1] == "trail") {
      secret_door_finders = door_info[i][9];
      break;
    }
  }

  if(!sizeof(secret_door_finders)) {
    notify_fail("You haven't found any wilderness trails here.\n");
    return 0;
  }
  if(member_array(REAL, secret_door_finders) == -1) {
    notify_fail("You haven't found any wilderness trails here.\n");
    return 0;
  }
  if(!str) {
    notify_fail("Guide who?\n");
    return 0;
  }
  if(!ob = present(str, environment(tp))) {
    notify_fail("There is no such person here to guide.\n");
    return 0;
  }

  write("You guide "+ob->short()+" onto the trail...\n");
  tell_object(ob, "\n"+NAME+" guides you onto a wilderness trail...\n\n");

  file = door_info[i][0];
  if(!stringp(file)) {
    notify_fail("The trail seems to be blocked with debris.\n");
    return 0;
  }
  ob->move_player("onto the wilderness trail#"+file);
  command("trail", tp);
  return 1;
}

