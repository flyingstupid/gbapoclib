#define NAME		(string)this_player()->query_name()
#define POSSESSIVE	(string)this_player()->query_possessive()

status roar() {
  write("You stand up on your hind legs and let out a ferocious roar!\n");
  say(NAME+" stands up on "+POSSESSIVE+" hind legs and lets our a ferocious roar!\n");
  return 1;
}
