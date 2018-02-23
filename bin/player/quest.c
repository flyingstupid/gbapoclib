status quest(string player) {
  object ob;

  if(!player) player = (string)this_player()->query_name(1);

  if((int)this_player()->query_security_level())
    ob = find_player(player);
  else
    ob = this_player();

  ob->quest_hint();
  return 1;
}
