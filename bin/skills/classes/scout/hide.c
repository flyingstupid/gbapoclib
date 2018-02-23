/* updated jan 94 - uses shadow of short() & move_player() */
/* updated july 98 due to players STILL hiding in shadows, even while in combat! */

status hide(mixed arg, string alt_type) {
  object ob;
  string tmp1, tmp2;

  if(!arg) {
    notify_fail("Hide in shadows?\n");
    return 0;
  }
  if(!sscanf(arg, "%sshadows%s", tmp1, tmp2)) {
    notify_fail("Hide in shadows?\n");
    return 0;
  }

  if((ob = (object)this_player()->query_primary_attack())) {
    notify_fail("You can't expect to hide in shadows while you're still in combat.\n"+
                capitalize((string)ob->query_name()) +" is looking right at you!\n");
    return 0;
  }

  if((ob = (object)this_player()->query_hide_in_shadows_object())) {
    write("You move out of the shadows...\n");
    say(this_player()->query_name() +" suddenly appears.\n");
    destruct(ob);
    return 1;
  }
  write("You attempt to hide in the shadows...\n");
  clone_object("obj/shadows/hider")->shadow_short(alt_type);
  return 1;
}

