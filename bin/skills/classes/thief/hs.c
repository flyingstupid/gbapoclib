status hs(mixed arg, string alt_type) {
  if(!arg) arg = "in shadows";
  return (status)"/bin/skills/classes/thief/hide" -> hide(arg, alt_type);
}
