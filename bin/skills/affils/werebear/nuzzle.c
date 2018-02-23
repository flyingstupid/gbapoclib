#define NAME		(string)this_player()->query_name()
#define POSSESSIVE	(string)this_player()->query_possessive()
#define OBJECTIVE	(string)this_player()->query_objective()
#define PRONOUN		(string)this_player()->query_pronoun()
#define TP		this_player()

status nuzzle(string str) {
  object ob;
  if(!str) {
    write("You nuzzle yourself affectionately.\n");
    say(NAME +" nuzzles "+PRONOUN+"self affectionately.\n");
    return 1;
  }

  str = lower_case(str);
  if(!(ob = present(str, environment(TP)))) {
    notify_fail("There is no "+str+" here to nuzzle.\n");
    return 0;
  }

  write("You nuzzle "+capitalize(str)+" affectionately.\n");
  say(NAME +" nuzzles "+capitalize(str)+" affectiinately.\n", ob);
  tell_object(ob, NAME +" nuzzles you affectionately.\n");
  return 1;
}
