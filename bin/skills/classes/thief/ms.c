/* MOVE SILENTLY. Angel, August 1993.
 * This function simply toggles the players
 * stealth flag on and off.
 */

status ms() {
  if(this_player()->query_attack()) {
    notify_fail("You can't move silently whilst in combat!\n");
    return 0;
  }
  this_player() -> toggle_stealth();
  return 1;
}

