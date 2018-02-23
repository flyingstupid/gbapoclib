/* animate skeleton, animate zombie */

status animate(string targ, mixed alt_type, string class) {
  if(!alt_type) alt_type = "necromancy_sphere";
 if(!class) class = "cleric";
  return (status)"/bin/skills/classes/mage/animate"->animate(targ, alt_type, class);
}

