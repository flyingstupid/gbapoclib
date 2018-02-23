/* Cure spell for Paladin */

status cure(mixed targ, mixed alt_type) {
  string tmp;
  object guild_object;

  if(!targ) {
    notify_fail("Cure disease on who?\n");
    return 0;
  }
  guild_object = present("guild_object", this_player());
  if(guild_object && !guild_object->check_alignment()) {
    notify_fail("You are too evil to use your holy powers!\n");
    return 0;
  }

  if(sscanf(targ, "disease %s", tmp)) {
 
      /* A paladin can cure diseases a few times per session */
      /* so check THIS ability first before deciding he's    */
      /* casting the actual spell instead of the ability     */

    if(guild_object && guild_object->can_cure_disease()) {
        alt_type = "divination_sphere";
        this_player()->set_divination_sphere(7);
        this_player()->adj_divination_sphere_points(7);
    }
  }


  if(!alt_type) alt_type = "healing_sphere";
  return (status)"/bin/skills/classes/cleric/cure"->cure(targ,alt_type);
}

