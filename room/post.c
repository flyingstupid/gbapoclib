/* updated jan. 94 */

inherit "inherit/room2";

void reset(status arg) {
  if(arg) return;
  set_weather(4, 1, 0);
  set_short("The post office");
  set_long("\tTempus Post Office \n"+
      "A long counter stands against the far wall, behind it   \n"+
      "are several small pigeon holes where mail is kept for   \n"+
      "those who live within the city. Perhaps some mail has   \n"+
      "been left here for you? A small plaque of gold hangs    \n"+
      "over the edge of the counter.\n");

  set_exits(({
   "room/city/town_hall3", "west",
  }));

  set_items(({
   "counter", "On the counter are pens, stamps, and writing paper,\n"+
              "all for writing letter to the people of the city",

    "pens",   "Writing quills of long purple feathers",
    "stamps", "The stamps have the picture of the city hall "+
              "upon them",
    "writing paper#paper#papers",
              "Pure white parchment. It looks very expensive",
    "plaque#sign",
              "Post Office Commands: \n"+
              "read  Read your mail from your pigeon hole\n"+
              "mail  <name>Mail to another player\n"+
              "from  List all the mail you have stored away\n"
  }));
  set_no_fight(1);
  set_no_summon(1);
}


void init() {
  ::init();
  if(this_player() && !present("mailer", this_player())) {
    move_object(clone_object("obj/mail_reader"), this_player());
  }
  add_action("say", "say");
  add_action("say", "'", 1);
}


status ready_to_move(string str) {
  if(present("mailer", this_player())) {
    destruct(present("mailer", this_player()));
  }
  return ::ready_to_move(str);
}

status door_to_move(string str) {
  if(present("mailer", this_player())) {
    destruct(present("mailer", this_player()));
  }
  return ::door_to_move(str);
}

status say(string arg) {
  write("Post master says: Shhh! People are trying to mail here.\n");
  return 1;
}

status query_no_teleport() {  return 1; }
