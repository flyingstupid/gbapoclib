#include <mudlib.h>
inherit STORE;
 
void reset(status arg) {
  owner = "Gitane";
  if(!present("Gitane")) {
         move_object(clone_object(
         "d/coronos/w/darkness/npc/gitane"),this_object());
  }

  reset_doors(arg);
  load_door(({
     "file", "d/coronos/w/alena/ille/c_6",
     "direction", "east door",
     "long",
        "The slender door is made of pine.  Many intricate designs are carved\n"+
        "into the door as well as the frame.  An oval window of glass, decorates\n"+
        "the center of the door.\n",
    }));

  ::reset(arg);
  if(arg) return;

  set_short("The Dancing Flame");
  set_long(
    "\t~The Dancing Flame~\n"+
    "This small shop has a warm and yet eerie feel to it.  Many different \n"+
    "candles of all shapes and sizes, light the room from various shelves,\n"+ 
    "tables and stands.  Shadows dance all about the shop, and aromas from\n"+ 
    "scented candles permeate through the air.  The half oval desk, in the\n"+
    "corner, is made of pinewood just like most of the furniture.  Even the\n"+
    "wood floor looks to be pine.  A rectangular window overlooks the street,\n"+
    "outside the shop, and a smaller window decorates the front door.\n");
 
  set_items(({    
    "dragon candle#a dragon candle",
      "This is a candle carved into the shape a a great dragon.\n",
    "door#front door#east door",
      "The slender door is made of pine.  Many intricate designs are carved\n"+
      "into the door as well as the frame.  An oval window of glass, decorates\n"+
      "the center of the door.\n",
    "outside#street",
      "The glare from the candles makes it a bit hard to see outside, through\n"+
      "the window.\n",
    "floor#wood floor",
      "The wood floor seems to be made of pine.  It is somewhat scratched\n"+
      "up and scuffed from many years of use.\n",
    "furniture",
      "Many differnt kinds of stands, tables and shelves are used in the\n"+
      "shop to display the many types of candles that the shop has to \n"+
      "offer.\n",
    "corner",
      "A half oval desk stands in the corner of the shop.\n",
    "desk",
      "This beautiful desk looks to be very old.  It has a deep rosewood\n"+
      "color that is enhanced with black stain.  It is marked and scuffed\n"+
      "from many years of use.  It seperates the main room of the shop from\n"+
      "the back door.  There is a sign on the desk that shows a 'list' of \n"+
      "what you may purchase at this time.\n",
    "shadow#shadows",
      "The shadows are created by the many dancing flames from the lit\n"+
      "candles.  They seem as if they are alive and all around you, \n"+
      "watching you from every corner of the room.\n",
    "stands#stand",
      "Thin, pillar-like, stands are positioned in various areas on the shop's\n"+
      "floor to display all types of candles.\n",
    "tables#table",
      "Wooden tables of all shapes and sizes stand in variuos spots on shop's\n"+
      "floor.  They are stacked and lined with all types of candles.\n",
    "shelves#shelf",
      "Wooden shelves line all four of the shop's walls.  The shelves are\n"+
      "full of many different kinds of candles.\n",
    "candles#candle",
      "The candles fill every corner of the shop.  Many of them are alit to\n"+
      "light the room and fill it with many different aromas.\n",
    "shop#room#store",
      "This shop is called the 'Dancing Flame'.  It is a quaint shop full\n"+
      "candles of all shapes and sizes.\n",
    "designs#design",
      "The designs are intricately carved into the wood and\n"+
      "highlighted with a deep wood stain.\n",
    "window",
      "The rectangular window is made up of six panes of glass.\n"+
      "The candle light shimers on the shiny glass.\n",     
    }));
  set_smell(
    "Many different aromas fill your lungs.  All types of scents from candles\n"+
    "mingle together and permeate through the room.  The smell of burnt wick\n"+
    "and smoke also can be noticed here.\n");
  set_listen(
    "The shop is rather peacefull and silent.  The random crackle and pop of\n"+
    "candle flame breaks the silence often. \n"); 
  set_weather(2,0,0);
  add_sell_items("candles");
 
  add_inventory("d/coronos/w/darkness/items/candle1.c");
  add_inventory("d/coronos/w/darkness/items/candle2.c");
  add_inventory("d/coronos/w/darkness/items/candle3.c");
  add_inventory("d/coronos/w/darkness/items/candle4.c");
  add_inventory("d/coronos/w/darkness/items/candle5.c");

}
