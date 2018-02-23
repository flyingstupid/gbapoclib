#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
if(!present("aaron")) {
move_object(clone_object("/d/coronos/w/vorax/mon/aaron.c"),this_object());
}
  if(arg) return;
  set_weather(2, 0, 0);
  set_short("The Ille Coronos Post Office");
  set_long("\tThe Ille Coronos Post Office\n"+
    "A long counter sits against one of the four walls.  Against\n"+
    "one of the other walls, there are many pigeon holes filled\n"+
    "with mail.  Ever now and then a man will come in and fill\n"+
    "another one of the pigeon holes with mail.\n"+
    "A small plaque of gold hangs over the edge of the counter.\n");

  set_items(({
    "counter",
    "This is a long, polished, wood counter.",
    "pigeon holes#holes",
    "These pigeon holes are filled with mail.",
    "plaque#sign",
              "Post Office Commands: \n"+
              "read  Read your mail from your pigeon hole\n"+
              "mail  <name>Mail to another player\n"+
              "from  List  all the mail you have stored away\n"
  }));
  set_no_fight(1);
  set_no_summon(1);
  load_door(({
    "destination", "d/coronos/w/darkness/b/hall/hall6.c",
    "direction", "south door",
    "long",
    "A large, oak door.\n",
  }));

}


  void init() {
    ::init();
    if(this_player() && !present("mailer", this_player())) {
	move_object(clone_object(MAILER), this_player());
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

  status query_no_teleport() { return 1; }
