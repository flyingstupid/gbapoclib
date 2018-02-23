status vent(string str, mixed alt_type, string class) {
 if(!class) class = "mage";
  return (status)"/bin/skills/classes/mage/ventriloquism" ->
	ventriloquism(str, alt_type, class);
}
