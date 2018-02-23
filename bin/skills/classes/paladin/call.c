#define MIN_LEVEL_TO_CALL	16

status call(string str, mixed alt_type) {
  if(this_player()->query_level() < MIN_LEVEL_TO_CALL) {
    notify_fail("You have not yet proven yourself worthy.\n");
    return 0;
  }

  if(!str) {
    notify_fail("Call what?\n");
    return 0;
  }
  if(this_player()->query_horse_object()) {
    notify_fail("You're already mounted. You're sitting on your steed!\n");
    return 0;
  }
  if(environment(this_player())->query_inside()) {
    notify_fail("You can't call your steed here.\n");
    return 0;
  }
  if(str == "horse" || str == "warhorse" || str == "steed") {
    return call_other(
		"/bin/skills/classes/paladin/whistle",
		"whistle", str, alt_type);
  }
  return 0;
}
