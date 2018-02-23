/* MOVE SILENTLY. Angel, August 1993.
 * This function simply toggles the players
 * stealth flag on and off.
 */

move(string arg) {
  if(arg != "silently") {
    notify_fail("move silently?\n");
    return 0;
  }
  return (status)"/bin/skills/classes/thief/ms" -> ms();
}

