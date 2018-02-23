status scribe(string str, mixed alt_type, string class) {
  if(!class) class = "mage";
  return (status)"/bin/skills/classes/cleric/scribe"->scribe(str, alt_type, class);
}
