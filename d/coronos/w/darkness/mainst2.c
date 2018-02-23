#include <mudlib.h>
#define ROPE "objects/rope"

inherit ROOM;

status rope_tied;

void reset (status arg){
    rope_tied = 0;
    if (arg) return;

    set_short("Main Street");
    set_long(
      "Main Street runs west and east from here and East Temple branches \n"+
      "off to the south. A tall steeple like form rises high above the trees \n"+
      "to the southwest. A large group of bushes take root to the north. \n"+
      "In the middle of the street is a well.\n");

    set_day_desc(
      "Standing amoung the bushes is a lamp post with an oil lamp.\n");

    set_night_desc(
      "Standing amoung the bushes is a lit oil lamp that lights up the road.\n");

    set_items(({
        "symbol", "It is a wave of water with the torso of a young naked woman.\n",
        "woman",  "She is carrying a three pronged trident",
        "trident", "It looks very sharp",

        "torso", "That's rather rude to stare",
        
        "roof#small roof",
        "The roof over the well is made from shingles of wood",
        "shingles", "They are small pieces of wood, carved by human hands",

        "beam#wooden beam",
        "Stretching across the well's top is a strong piece of wood.\n"+
        "It looks as though something has been tied to it in the past\n"+
        "from the wear marks in its centre.\n",

        "water", "It's dark down in the well. You can't see the water from here.\n",
        "lamp post#post",
        "This is a simple lamp post.  The oil lamp hangs from the post by a chain.\n",
        "cobblestones#cobblestone",
        "These grey cobblestones have been smoothed and worn over time.\n",
        "road",
        "The road is made of grey cobblestones.\n",      
        "bush#bushes#patch",
        "These are short bushes that have pointy leaves.  They grow in a\n"+
        "group, around the lamp post.\n",
        "The church is off to the south.\n",
        "leaves",
        "The leaves are green and pointy.\n",
        "church",
        "The large church is off to the southwest, hidden behind some trees.\n",
        "trees#tree#tall trees",
        "They hide the huge temple behind their many branches.\n",
        ",.\n",
      }));

    set_day_items(({
        "lamp#oil lamp",
        "This is a simple oil lamp that hangs from a post.  It is has a metal\n"+
        "frame and glass panels.  The lamp is unlit right now.\n",
      }));

    set_night_items(({
        "lamp#oil lamp",
        "This is a simple oil lamp that hangs from a post.  It has a metal\n"+
        "frame and glass panels.  The lamp shines brightly, illuminating the\n"+
        "area.\n",
      }));

    set_smell("You smell nothing but fresh air.\n");

    set_listen(
      "You hear the rustling of the bushes' leaves, and the dripping \n"+
      "of water from deep within the well.\n");

    set_weather(2, 4, 0);

    set_exits(({
        "d/coronos/w/darkness/mainst3", "east",
        "d/coronos/w/darkness/mainst1", "west",
        "d/coronos/w/alena/ille/t_9",   "south",
      }));
}

void init() {
  ::init();
  add_action("look_at", "look");
  add_action("look_at", "exa");
  add_action("look_at", "examine");

  add_action("getIt",   "get");
  add_action("getIt",   "take");
  add_action("getIt",   "untie");

  add_action("tie",     "tie");
  add_action("tie",     "bind");
  add_action("tie",     "knot");

  add_action("well", "enter");
  add_action("well", "climb");
  add_action("well", "down");
  add_action("well", "d");
}


status look_at(string str) {
  string tmp1, tmp2;

  if(!str) return 0;

  if(sscanf(str, "%swell%s", tmp1, tmp2)) {
    write(
	"The well is made from a light grey stone and bears the symbol of \n"+
	"the goddess of Water. Above it stands a small roof to keep the   \n"+
	"elements out of the pure waters below. While there is no bucket  \n"+
	"to send into the water a wooden beam sits firmly in the rock     \n");

    if(rope_tied) {
      write(
	"with a length of rope attached to it. It looks sturdy enough to \n"+
	"climb down!\n");
      return 1;
    }
    else {
      write(
	"as if inviting you to tie something to it.\n");
      return 1;
    }
  }
  return 0;
}


status getIt(string str) {
  string tmp1, tmp2;

  if(!rope_tied) return 0;
  if(sscanf(str, "%srope%s", tmp1, tmp2)) {
    write("You untie the rope from the well and stow it away.\n");
    say(this_player()->query_name() +" unties the rope from the well "+
    "and stows it away.\n");
    rope_tied = 0;
    move_object(clone_object(ROPE), this_player());
    this_player()->recalc_carry();
    return 1;
  }
}


status well(string str) {
  string verb;
  string tmp1, tmp2;

  verb = capitalize(query_verb());
  if(!str) str = "the well";

  if(sscanf(str, "%swell%s", tmp1, tmp2)) {

    if(!rope_tied) {
      if(!present("rope", this_player())) {
        write("Without a rope, how do you expected to get down?\n");
        return 1;
      }
      write("You'd have to tie the rope to something before you could \n"+
            "make the descent.\n");
      return 1;
    }
    
    if((int)this_player()->query_climb() < 5) {
      write("Even while you have a rope to assist you, the climb down still \n"+
            "appears a little dangerous for you. Perhaps you should seek    \n"+
            "training in climbing before your next descent?\n");
      return 1;
    }

    if(random(5) > ((int)this_player()->query_climb())) {
      write("You fall into the well . . . \n\nTHUD!!\n\n");
      this_player()->adj_hp(random(5) + 1);
    }
    else {
      write("You climb down the well.\n");
    }
    this_player()->move_player("into the well#d/coronos/rooms/maze/well");
    return 1;
  }
}


status tie(string str) {
  object ob;
  string tmp1, tmp2;

  if(!str) {
    notify_fail("Tie what?\n");
    return 0;
  }

  if(!sscanf(str, "%s to %s", tmp1, tmp2)) {
    notify_fail("Tie what to where?\n");
    return 0;
  }

  ob = present("rope", this_player());
 
  if(!ob) {
    write("You have no rope to tie to the well.\n");
    return 1;
  }
 
  if(rope_tied) {
    write("There is already a rope tied to the well.\n");
    return 1;
  }

  write("You tie the "+ob->query_name()+" to the well.\n");
  destruct(ob);
  this_player()->recalc_carry(); /* fixes his carry */
  say(this_player()->query_name() +" ties a rope to the well.\n");
  rope_tied = 1;
  return 1;
}

