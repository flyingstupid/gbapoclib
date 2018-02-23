

status detect(mixed targ, mixed alt_type) {
  string tmp;
  object guild_object;

  if(!alt_type) alt_type = "divination_sphere";
  /* Paladin can detect evil any time...but ONLY detect evil */
  if(!targ) {
    notify_fail("Detect evil who?\n");
    return 0;
  }

  if(!sscanf(targ, "evil %s", tmp)) {
    notify_fail("Detect evil on who?\n");
    return 0;
  }


  guild_object = present("guild_object", this_player());

  if(guild_object && guild_object->check_alignment()) {
    this_player()->set_divination_sphere(1);
    this_player()->adj_divination_sphere_points(1);
    return (status)"/bin/skills/classes/cleric/detect" -> detect (targ, alt_type);
  }
  else {
    notify_fail("You are too evil to use your holy powers!\n");
    return 0;
  }   
}

