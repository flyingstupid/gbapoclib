#include <mudlib.h>
inherit PUB;
 
void reset(status arg) {
 
    reset_doors(arg);
   load_door(({
      "destination",    "d/coronos/w/alena/ille/c_8",
      "direction",      "east door",
   "description",
     "The heavy, old door of the pub is made out of solid oak,\n"+
     "smooth and shiny from wear.  The thick hinges, long bindings\n"+
     "and curved handle are of intricately molded cast iron.  In\n"+
     "the top half of the door is a little stain glass window\n"+
     "depicting a wyvern at sunset.\n",
 
    }));
  if(arg) return;
 
   set_short("Seline's Song");
   set_long(
"     ||_-*`SELINE'S SONG`*-_||                                    \n"+
"The famed fable of Seline and the Wyvern is where this pub takes  \n"+
"its name. Clean and tidy, it is a wonderful place to come and take\n"+
"a load off.  The cheery atmosphere contrasts with the impedending \n"+
"doom of the wyvern theme that lurks in every corner of the pub.   \n"+
"Thick tables and chairs fashion neat rows running up and down the \n"+
"room, with fresh rushes strewn about the hardwood floor. A long   \n"+
"counter stands ready to serve on the left, a large fireplace   \n"+
"takes up the right side and stairs run up against the back wall.\n"+
"A menu and a plaque are hanging upon the wall above the counter.  \n");
 
  set_owner("Orson");
  set_weather(2,2,0);
  add_sdrink("juice", "A cup of red currant juice", "Sweet!", 5);
  add_sdrink("milk", "A small glass of goat's milk", "Different and"+
             "robust..but very good.", 9);
  add_drink("mead","A mug of honey mead", "That hits the spot.", 18);
  add_drink("whiskey", "A shot of dark whiskey", "Burns a little "+
            "as it goes down.", 29);
  add_drink("wine", "A glass of bubbling wyvern's wine",
            "You think your throat has been seared off.", 45);
 
  add_food("buns", "Soft golden-brown buns", "Still warm from the"+
          "oven!", 6);
  add_food("potato", "A whole boiled potato", "Bland but very"+
          "filling.", 14);
  add_food("stew", "A bowl of thick beef stew",  "Tastes just like"+
          "homemade.", 30);
  add_food("chicken", "Half a roast chicken", "Juicy!", 46);
 
  set_items(({
    "tables#table",
      "Many different sized, round tables with intricately painted\n"+
      "tops portraying scences of the myth.  The thick tables are\n"+
      "made of maple with a single base supporting them.\n",
    "chairs#chair",
      "Large, comfortable looking chairs that sit around the various\n"+
      "sized tables in an orderly fashion.  A rearing wyvern is carved\n"+
      "into the wooden back of each chair.\n",
 
    "rushes",
      "Reedy vegetation gathered from a nearby field that helps\n"+
      "keep the place looking and smelling clean.\n",
    "counter",
      "A long wooden counter running along the left wall of the pub.\n"+
      "It is here that one gets served.\n",
    "fireplace",
      "A large stone fireplace, providing both warmth and light.\n"+
      "It takes up most of the right wall of the pub.\n",
    "walls#wall",
      "White washed walls that help with the cheery atmosphere.\n",
    "plaque",
      "A golden plaque upon the wall.  Perhaps you should read it?\n",
    "stairs",
      "At the back of the pub, wide wooden stairs, with a sturdy\n"+
      "banister run upwards along the wall.\n",
    "corner#corners",
      "The corners of the pub are a little dark and spooky, with\n"+
      "large wooden wyvern head masks looming out of the shadows.\n",
    "mask#masks",
      "The masks are snarling and roaring wyvern heads intricately\n"+
      "carved out of dark wood.  The detail of the features is\n"+
      "incredible.  They alsmot seem to come alive right before\n"+
      "your eyes.\n",
    }));
  set_listen(
    "The pub is fairly quiet except for the crackling of the fire\n"+
    "and the sounds of cooking from the kitchen in the back.\n");
  set_smell(
    "The armoa of good food wafts through the air, making your\n"+
    "stomach growl.\n");
}
 
 
 
void init() {
  ::init();
  add_action("read1", "read");
  add_action("list1", "list");
  add_action("exa1", "examine");
  add_action("exa1", "exa");
}
 
 
status read1(string str) {
  string tmp1, tmp2;
  int pmon;
 if(!str) {
    write("Trying to read the thin air?\n");
    return 1;
  }
 
  if(sscanf(str, "%smenu%s", tmp1, tmp2)) {
      write(
        "_______________________________________________________________\n"+
        "               ~*~ Welcome to SELINE's SONG ~*~                \n"+
        "                                                               \n"+
        " -Drinks-:                                                     \n"+
        "     Red Currant 'Juice',.,.,.,.,.,.,.,.,.,.,. 22 copper coins \n"+
        "     Goat's 'Milk',.,.,.,.,.,.,.,.,.,.,.,.,.,. 44 copper coins \n"+
        "     Honey 'Mead'.,.,.,.,.,.,.,.,.,.,.,.,.,.,. 1 silver coins  \n"+
        "     Dark 'Whiskey'.,.,.,.,.,.,.,.,.,.,.,.,.,. 2 silver coins  \n"+
        "     Wyvern's 'Wine',.,.,.,.,.,.,.,.,.,.,.,.,. 3 silver coins  \n"+
        "                                                               \n"+
        " -Foods-:                                                      \n"+
        "     Soft 'Buns',.,.,.,.,.,.,.,.,.,.,.,.,.,.,. 27 copper coins \n"+
        "     Boiled 'Potato',.,.,.,.,.,.,.,.,.,.,.,.,. 75 copper coins \n"+
        "     Beef 'Stew',.,.,.,.,.,.,.,.,.,.,.,.,.,.,. 2 silver coins  \n"+
        "     Half a Roast 'Chicken'.,.,.,.,.,.,.,.,.,. 3 silver coins  \n"+
        "                                                               \n"+
        "               *~ Eat, Drink, and Be Merry! ~*                 \n"+
        "_______________________________________________________________\n");
 
      say(this_player()->query_name()+
        " hmms and carefully reads the menu.\n", this_player());
      return 1;
  }
 
 
  if(sscanf(str, "%splaque%s", tmp1, tmp2)) {
      write(
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n"+
        "|                 ~{Seline and the Wyvern}~                 |\n"+
        "|                                                           |\n"+
        "|    The tale of Seline and the Wyvern is one well known in |\n"+
        "| these parts.  An old tale of bravery and sacrifice that   |\n"+
        "| can touch anyone's heart.                                 |\n"+
        "|    A black wyvern awoke from its ancient deep sleep in    |\n"+
        "| the nearby mountains.  It ravaged the countryside leaving |\n"+
        "| nothing unharmed.  Many brave attempts were made to kill  |\n"+
        "| the vicious beast only to find out it could not be killed |\n"+
        "| but had to be charmed back into sleep with song.          |\n"+
        "|    The young girl, Seline, heedless of her own safety     |\n"+
        "| accomplished this deed with the power of her heart and    |\n"+
        "| musical talent.  In the end of the tale, young Seline     |\n"+
        "| saved her town but lost her voice forever.                |\n"+
        "|                          ~{*}~                            |\n"+
        "+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
 
      say(this_player()->query_name()+
        " studies the golden plaque.\n", this_player());
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
  else { return 0;
  }
 }
 
status list1(string str) {
    string tmp1, tmp2;
 
write("Orson says: How 'bout readin' the menu, Neighbour?\n");
    return 1;
  }
 
status exa1(string str) {
  string tmp1, tmp2;
  if(!str) {
    write("What are you trying to examine?  Pick something already..\n");
    return 1;
  }
 
  if(sscanf(str, "%smenu%s", tmp1, tmp2)) {
    write(
      "Orson says: How 'bout readin' the menu, Neighbour?\n");
    return 1;
  }
 
  else { return 0;
  }
}
 
