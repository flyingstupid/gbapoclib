status barkskin(mixed targ, mixed alt_type) {
  object guild_object;
  if(guild_object = present("guild_object", this_player())) {
    if(guild_object->check_alignment()) {
      notify_fail("You are too evil to use your God given powers.\n");
      return 0;
    }
  }
  if(!alt_type) alt_type = "nature_sphere";
 return (status)"/bin/skills/classes/cleric/barkskin"->barkskin(targ,alt_type);
}

