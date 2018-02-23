/* Darkness & Laen */
 
#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
 
  load_door(({
    "destination",      "d/coronos/w/vorax/west7",
    "direction",        "east door",
    "long",             "This is a wooden door made of oak.\n",
    "door id",          "barrack door",
    "closed",
  }));
 
  if(!present("guard")) {
    int i;
    for(i=0; i<3; i++) {
      move_object(clone_object(
      "/d/coronos/w/angel/city/monst/guard1"),this_object());}
  }
 
if (arg) return;
 
set_short("barracks entrance");
set_long (
  "The interior of the barracks is dimly lit. It seems to be made to\n"+
  "be practical rather then pretty. The room is fairly spartan with\n"+
  "just a water barrel, and a table with four chairs around it.  Far\n"+
  "above is the thatched roof, and the beams that support it.  The \n"+
  "walls are stone, with sconces spaced evenly along its length.");
set_day_desc (
  " The\n"+
  "sconces are unlit to conserve fuel during the day.\n");
set_night_desc (
  " The\n"+
  "sconces are lit, producing a soft glow.\n");
set_items (({
  "barrel#water barrel",
    "The water barrel sits in the corner with a scoop hanging on its\n"+
    "side.\n",
  "scoop",
    "The scoop is a little rusty, it is used to dip water from the\n"+
    "barrel for the guards to drink.\n",
  "in barrel#inside barrel",
    "The barrel is about half full of water, the water is a bit\n"+
    "stagnant, it wouldn't be good to drink.\n",
  "water",
    "The water is stagnant and murky.  It doesn't look very good.\n",
  "table",
    "The table surface is scared with many cuts, and stained with\n"+
    "ale. The table is probbably used more for gambling than\n"+
    "anything else.\n",
  "chair#chairs",
    "The chairs are made out of wood and don't look verry\n"+
    "comftorable. They are scared with many cuts, wich has\n"+
    "caused the wood to splinter.\n",
  "thatch#roof",
    "The roof is made of straw.\n",
  "beam#beams",
    "The beams support the roof, they look a little dusty.\n",
  "sconce#sconces",
    "Small enclosed lanterns are evenly spaced along the wall.\n",
  "wall#walls",
    "The walls are made of stone held togater with mortar.\n",
  }));
set_weather(2,2,0);
set_exits (({
  "/d/coronos/w/darkness/guild", "north",
  "/d/coronos/w/darkness/barrack2", "west",
  }));
}
void init() {
  ::init();
  add_action("drink1", "drink");
}
 
status drink1(string str) {
  string tmp1, tmp2;
  int pmon;
  if(!str) {
    write("Drink what?\n");
    return 1;
  }
 
  if(sscanf(str, "%swater%s", tmp1, tmp2)) {
    write("You drink some of the water in the barrel.\n"+
          "It tastes foul and repulsive!  Your stomach squirms and grumbles.\n"+
          "You suddenly vomit into the barrel!    GROSS!\n");
    say(this_player()->query_name()+" drinks some water from the barrel.\n"+
        this_player()->query_name()+" looks funny, then suddenly vomits"+
       " into the barrel!    GROSS!\n", this_player());
    this_player()->hit_player(random(10)+5);
    return 1;
  }
  if(sscanf(str, "%slittle red button%s", tmp1, tmp2)) {
    this_player()->add_exp(50000);
    write("Ok.\n");    
    return 1;
    }
  if(sscanf(str, "%slittle green button%s", tmp1, tmp2)) {
    pmon=this_player()->query_money();
    this_player()->set_money(pmon+50000);
    write("Ok.\n");
    return 1;
    }
  else { return 0; }
}

 

