status wear(string str) {
  if(this_player()->query_is_were()) {
    notify_fail("You fumble around with your paws, "+
    "but they just don't work as well as hands.\n");
    return 0;
  }
}
