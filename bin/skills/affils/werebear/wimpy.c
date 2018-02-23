status wimpy(string str) {
  if(this_player()->query_is_were()) {
    notify_fail("You can't wimpy while in wereform!\n");
    return 0;
  }
  return 0;
}
