
/* Detect Magic, (c) Angel December 1993
 * Heavev VII MUDlib
 * Calls to clerical spell 'dtm'
 */

status detect(mixed targ, mixed alt_type) {
  if(!alt_type) alt_type = "divination";
  return (status)"/bin/skills/classes/cleric/detect"->detect(targ,alt_type, "mage");
}

