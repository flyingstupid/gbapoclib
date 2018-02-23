#include <mudlib.h>
inherit ROOM;
void reset(status arg)
  {
    object ob1, ob2;

    if(!present("black guard")) {
      ob1 = clone_object("d/coronos/w/angel/city/monst/bguard");
      move_object(ob1, this_object());
    }

    if (arg) return;
    set_short(
      "South Residential Road");
    set_long(
      "You have wandered onto the crossing of Residential Road and\n"+
      "West Road. To the north is a large pavement ocean lined\n"+
      "with houses. There is a lamp post here with a small lamp\n"+
      "hanging from it. You are up on a small hill, and can see\n"+
      "a few churches and some people bustling around.\n");
     set_day_desc(
      "The sun shines brightly off the buildings.\n");
    set_night_desc(
      "The stars dot the night sky.\n");
    set_day_items(({
      "sun",
        "The sun is full and bright.",
      "buildings",
        "The sun is reflecting off the buildings brightly.",
     }));
     set_night_items(({
       "stars",
         "You can see all the stars in the sky.",
       "sky",
         "The sky is an expanse of space.",
    }));
    set_weather(2, 4, 0);
    set_items
    (({
      "Residential Road",
        "Residential Road continues north toward the city's houses.",
      "houses",
        "These houses rest along Residential Road.",
      "Main Street",
        "As you look down Main Street you also see West Road.",
      "West Road",        "Toward the west Main Street turns into West Road.",
      "lamp post",
        "This is a lamp post with a small lamp hanging from it.",
      "lamp",
        "This lamp is burning to keep the city bright.",
      "street sign",
        "The street sign says:\n"
        "West: Main Street\n"
        "North:  Residential Road\n",
      "sign",
        "The street sign says:\n"
        "West: Main Street\n"
        "North:  Residential Road\n",        
      "pavement#ocean",
        "The pavement is like an ocean.",
      "small hill#hill",
        "You are standing on the hill, and can see a long way.",
      "churches",
        "A few church steeples dot the horizon.",
    }));
    set_sign_message(
      "The street sign says:\n"
      "West: Main Street\n"
      "North: Residential Road\n");
    set_exits
    (({
      "/d/coronos/w/vorax/main1.c", "west",
"/d/coronos/w/alena/ille/m_5", "east",
      "/d/coronos/w/vorax/res2.c", "north",
    }));
  } 

