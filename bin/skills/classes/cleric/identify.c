status identify(mixed targ, mixed alt_type, string class) {
  if(!alt_type) alt_type = "divination_sphere";
  if(!class) class = "cleric";
  return (status)"/bin/skills/classes/mage/identify"->identify(targ,alt_type, class);
}

