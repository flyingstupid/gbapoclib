status heal(string targ, mixed alt_type) {
  object guild_object;

  guild_object = present("guild_object", this_player());
  if(guild_object && guild_object->check_alignment())
    return (status)"/bin/skills/classes/cleric/heal"->heal(targ, alt_type);
  else {
    notify_fail("You are too evil to use your holy powers!\n");
    return 0;
  }   
}
