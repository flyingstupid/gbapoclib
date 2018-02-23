status scry(string str, mixed alt_type, string class) {
  if(!alt_type) alt_type = "divination_sphere";
  if(!class) class = "cleric";
  return (status)"/bin/skills/classes/mage/scry"->scry(str,alt_type,class);
}

