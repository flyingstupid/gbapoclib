status dismount(string str) {
  object horse, follow;

  if(!(horse = this_player()->query_horse_object())) {
    notify_fail("You're not mounted on your steed!\n");
    return 0;
  }
  destruct(horse);
  write("You dismount from your steed.\n");
  say(this_player()->query_name()+" dismounts from "+
    this_player()->query_possessive()+" steed.\n");

  "/bin/skills/classes/paladin/call" -> call("horse", 1);
  return 1;
}

