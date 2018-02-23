status craft(string str, mixed alt_type) {
  if(!alt_type) alt_type = "bowyer";
  return (status)"/bin/skills/classes/fighter/forge"->forge(str, alt_type);
}
