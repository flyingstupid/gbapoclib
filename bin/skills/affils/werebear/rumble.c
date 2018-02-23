#define NAME		(string)this_player()->query_name()
#define POSSESSIVE	(string)this_player()->query_possessive()

status rumble() {
  write("You rumble softly with contentement.\n");
  say(NAME +" rumbles softly with contentement.\n");
  return 1;
}
