status gate(string str, mixed alt_type) {
  if(!alt_type) alt_type = "conjuration";
  return (status)"/bin/skills/classes/mage/gate"->gate(str, alt_type);
}
