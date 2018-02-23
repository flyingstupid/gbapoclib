status locate(string str, mixed alt_type, string class) {
  if(!alt_type) alt_type = "divination";
  if(!class) class = "mage";

  return (status)"/bin/skills/classes/cleric/locate"->locate(str, alt_type, class);
}
