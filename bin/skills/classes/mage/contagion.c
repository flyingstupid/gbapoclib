/* Contagion 
 * H7 Mudlib, '96
 */

status contagion(mixed targ, mixed alt_type, string class) {
  if(!alt_type) alt_type = "necromancy";
  if(!class) class = "mage";
  return (status)"/bin/skills/classes/cleric/cause"->cause("disease "+targ,
		alt_type, class);
}

