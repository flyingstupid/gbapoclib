status wish(mixed targ, mixed alt_type) {
  object guild_object;
  if(guild_object = present("guild_object", this_player())) {
    if(guild_object->check_alignment()) {
      notify_fail("You are too evil to use your God given powers.\n");
      return 0;
    }
  }
  if(!alt_type) alt_type = "conjuration";
  return (status)"/bin/skills/classes/mage/wish"->wish(targ, alt_type);
}

