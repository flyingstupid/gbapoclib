status brew(string targ, mixed alt_type, string class) {
  if(!class) class = "cleric";
  return (status)"/bin/skills/classes/mage/brew"->brew(targ, alt_type, class);
}
