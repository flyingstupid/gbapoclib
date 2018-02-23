#define STEED	   "obj/skills/classes/p_steed" /* file for paladin's steed */
#define NAME       "Warhorse"
#define SHORT_DESC "A warhorse"
#define LONG_DESC  "A fine heavy warhorse of excelent quallity and breeding.\n"

status whistle(string str, mixed alt_type) {
  object obj, horse, follow;
  string *temp;

  if(environment(this_player())->query_inside()) {
    write("Your steed can't find you where you are.\n");
    return 1;
  }

  if(horse = present("warhorse", environment(this_player()))) {
    write(horse->query_name()+" turns her head towards you.\n");
    destruct(horse);
  }

  if(!present("paladin", this_player())) {
    write("You seem to have lost your paladinhood.\n"+
          "Seek the area where paladin train to regain your powers.\n");
    return 1;
  }

  if(horse = (object)(present("paladin", this_player()))->query_horse()) {
    tell_room(environment(this_player()),
	(string)horse->query_name()+" "+horse->query_msgin()+".\n");
    move_object(horse, environment(this_player()));
    return 1;
  }


  horse = clone_object(STEED);
  horse -> set_owner((string)this_player()->query_name());

  temp = (mixed *)this_player()->query_horse_info();
  if(sizeof(temp)) {
    horse -> set_long(LONG_DESC + temp[1]);
    horse -> set_name(lower_case(temp[0]));
    horse -> set_alt_name(lower_case(NAME));
    horse -> set_short(SHORT_DESC +" named "+ temp[0]);
    horse -> load_chat(5,({ temp[0]+" neighs.\n", }));
    horse -> load_a_chat(5,({ temp[0]+" kicks.\n", temp[0]+" bites.\n", }));
  }
  else {
    horse -> set_long(LONG_DESC);
    horse -> set_name(lower_case(NAME));
    horse -> set_short(SHORT_DESC);
    horse -> load_chat(5,({ NAME+" neighs.\n", }));
    horse -> load_a_chat(5,({ NAME+" kicks.\n", NAME+" bites.\n", }));
  }

  if(!alt_type) {
    say(this_player()->query_name()+" gives a loud"+
                    " whistle.\n",this_player());
    say(horse->query_name()+" gallops in.\n");
    if(sizeof(temp))
      write("You whistle for your steed, "+temp[0]+".\n");
    else
      write("You whistle for your "+NAME+".\n");
  }

  move_object(horse, environment(this_player()));
  return 1;
}

