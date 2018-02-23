#define ID	"/bin/skills/classes/mage/identify"

status appraise(string str, mixed alt_type) {
  object ob;

  if(!str) {
    notify_fail("Appraise what?\n");
    return 0;
  }
  if(!ob = present(str, this_player())) {
    notify_fail("You don't have a "+capitalize(str)+" to appraise.\n");
    return 0;
  }
  if(living(ob)) {
    notify_fail("You don't think "+ob->short()+" would go for much on "+
    "the slave market.\n");
    return 0;
  }
  return (status)call_other(ID, "cast_spell",
		this_player(),
		ob,
		0,
		(int)this_player()->query_appraisal()
          );

}
