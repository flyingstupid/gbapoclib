#include <mudlib.h>
#define NAME (string)this_player()->query_name()

inherit ROOM;
void light(string str);
void douse(string str);
static status fire_on;

void reset(status arg) {
  reset_doors(arg);
  load_door(({
     "file", "room/city/mage/tower2", 
     "direction", "west door",
     "long",
          "A dark door or deep red wood.\n"+
     "key id", "silver key",
     "lock id", "silver lock",
     "lock description", "A shiny silver lock that glows softly\n",
     "closed", "locked",
     "trap on",
     "trap description", 
          "The trap appears to be some kind of fire trap spell.\n",
     "trap damage", (20 + random(50)),
     "trap message", "Fire Trap spell engulfs you from the door!\n",
     "trap message room", "@@query_name:$this_player()$@@ is engulfed "+
          "by a Fire Trap on the door.\n",
  }));

  if(!present("mordenkainen")) {
    move_object(clone_object("room/city/monst/mordkn"),this_object());
  }

  if(arg) return;
  fire_on = 1;
  set_short("Mordenkainen's personal study");
  set_long(
     "A wide desk of red wood stands in the centre of the room beside   \n"+
     "a large, candle stand and a small shelf of the same wood, in an   \n"+
     "elvish leaf design. It is here, in this comfortable study, that   \n"+
     "the great archmage Mordenkainen spends his time in contemplation. \n"+
     "The only window in the room looks over the city of Tempus.        \n");

  set_weather(2,1,0);

  set_items(({
     "window",
          "The view from the window is spectacular. From here you can    \n"+
          "easily see the entire city below, especially a beautiful view \n"+
          "of the gardens. The window is sealed shut, and cannot be openned",
     "fire#fire place",
          "A roaring fire place, keeping the inside of the study warm",
     "rug",
          "A plush, deep red rug, hand woven from the mane of a pegasus",
     "desk",
          "A wide desk of a deep red wood",
     "candle stand#stand",
          "A gold stand bearing 5 candles",
     "candle#candles",
          "The candles are white, and not lit",
     "shelf#small shelf",
          "A shelf of Mordenkainen's personal reading materials",
     "design#leaf design#leaf",
          "An intricate design, obviously elvish, and priceless",
  }));
  enable_commands();
}

void heart_beat() {
  string *messages;
  messages = ({
     "The fire crackles.\n",
     "The fire spits.\n",
     "The fire warms your bones.\n",
     "The fire light casts shadows that dance off the walls.\n",
     "The fire light bathes the room in a warm yellow glow.\n",
     "The fire flames dance.\n",
     "The fire light warms your spirits.\n",
  });
  if(!random(10) && fire_on)
    tell_room(this_object(), messages[random(sizeof(messages))]);
}

void long(status wiz) {
  ::long(wiz);
  if(fire_on)
    write(
       "Reems of heat roll across the deep, plush hand woven rug from \n"+
       "the fire place over the opposite side of the room.\n");
  else
    write(
       "The room is still stuffy from the heat from the fireplace which\n"+
       "has now been extinguished.\n");
}

void init() {
  ::init();
  add_action("light", "light");
  add_action("douse", "extinguish");
  add_action("douse", "douse");
}

status light(string str) {
  string tmp1, tmp2;

  if(sscanf(str, "%scandle%s", tmp1, tmp2)) {
    notify_fail("The candles on the stand will not light.\n");
    return 0;
  }
  if(!sscanf(str, "%sfire%s", tmp1, tmp2)) {
    notify_fail("Light the fire place?\n");
    return 0;
  }
  if(fire_on) {
    notify_fail("The fire place is already lit!\n");
    return 0;
  }
  tell_object(this_player(), "You light the fireplace.\n");
  say(NAME+" lights the fireplace.\n",this_player());
  this_object() -> remove_item("fire#fire place");
  this_object()->add_item("fire#fire place",
          "A roaring fire place, keeping the inside of the study warm");
  fire_on = 1;
  return 1;
}

status douse(string str) {
  string tmp1, tmp2;
  
  if(!sscanf(str, "%sfire%s", tmp1, tmp2)) {
    notify_fail("Extinguish the fireplace?\n");
    return 0;
  }
  if(!fire_on) {
    notify_fail("But the fireplace is not lit!\n");
    return 0;
  }
  tell_object(this_player(), "You extinguish the fireplace.\n");
  say(NAME+" extinguishes the fire in the hearth.\n");
  this_object()->remove_item("fire#fire place");
  this_object()->add_item("fire#fire place",
          "The fireplace has long since been extinguished. All that \n"+
          "is left are ashes and some wood still ready to burn");
  fire_on = 0;
  return 1;
}
