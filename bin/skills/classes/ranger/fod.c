status fod(string str, mixed alt_type) {
  object guild_object;

  if(guild_object = present("guild_object", this_player())) {
    if(guild_object->check_alignment()) {
      notify_fail("You are too evil to use your God given powers.\n");
      return 0;
    }
  }

  return (status)"/bin/skills/classes/mage/fod"->fod(str, alt_type, "cleric");
}
