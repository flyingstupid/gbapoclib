status pick(string str, mixed alt_type) {
  string tmp1, tmp2;
  if(!str) {
    notify_fail("Pick pockets?\n");
    return 0;
  }

  if(!sscanf(str, "pockets %s from %s", tmp1, tmp2)==2) {
    notify_fail("Pick pockets <what> from <who>?\n");
    return 0;
  }

  return (status)"/bin/skills/classes/thief/steal"->steal(
	tmp1 +" from "+ tmp2,
	(int)this_player()->query_dexterity() / 10 + random(20));
}

