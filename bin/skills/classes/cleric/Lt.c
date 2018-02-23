/* light */

status Lt(string targ, mixed alt_type, string class) {
  if(!alt_type) alt_type = "stellar_sphere";
  return (status)call_other("/bin/skills/classes/mage/lt", "lt", targ, alt_type, class);
}

