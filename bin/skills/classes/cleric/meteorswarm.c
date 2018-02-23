/* meteor swarm */

status meteorswarm(string targ, mixed alt_type, string class) {
  if(!alt_type) alt_type = "combat_sphere";
  if(!class) class = "cleric";
  if(!targ)
    targ = "swarm";
  else
    targ = "swarm "+ targ;
  return (status)"/bin/skills/classes/mage/meteor"->meteor(targ, alt_type, class);
}

