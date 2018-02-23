#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
    reset_doors(arg);
 
    load_door(({
    "file", "d/coronos/w/silvara/woodshop",
    "direction", "west door",
    "long",
      "A large, heavy-set wooden, door.\n",
    }));
 
  ::reset(arg);
  if(arg)return;
        set_short("the commercial sector of Ille Coronos");
        set_long(
          "Gshone Street forms an elbow here in the road, continuing both to the \n"+
          "north as well as to the west. A large wood carpenter's shop stands \n"+
          "to the east and a huge tall oak tree stands to the south. Smooth grey \n"+
          "stones line the road and have been worn down by many pairs of boots \n"+
          "over the past years.");
        set_day_desc(
          " The lamp stands unlit.\n");
        set_night_desc(
          " The oil lamp is lit and its glow illuminates the \n"+
          "street below.\n");
        set_items(({
            "road#stone#stones#walk#walkway#street",
            "Grey stones pave the road, consisting of many holes and chips \n"+
            "obtained over the many years of use.\n",
            "grass",
            "Pushing its way up through the stones the blades seemingly \n"+
            "reach for the sky.\n",
            "oak tree#tree#oak",
            "Standing many feet tall the huge tree is made up of many branches \n"+
            "reaching out and its trunk is strong and sturdy.\n",
          }));
        set_day_items(({
            "lamp#light#oil lamp post#lamp",
            "The oil lamp stands about seven feet tall and the wick is \n"+
            "encased by glass and steel, unlit for now.\n",
          }));
        set_night_items(({
            "lamp#light#oil lamp post#lamp",
            "The oil lamp stands about seven feet tall and the wick is \n"+
            "lit, illuminating the street below. It has been encased by \n"+
            "glass and steel, protecting the flame from wind and rain.\n",
          }));
        set_smell(
          "A salty smell on the air brushes your nose from the southeast.\n");
        set_listen(
          "Boots upon stone, voices, and other bustling sounds fill the air \n"+
          "about you. Chattering can be heard from the tall oak.\n");
        set_sign_message(
          "     Carpenter of Ille Coronos   \n");
        set_weather(2, 4, 0);
        set_exits(({
            "/d/coronos/w/alena/ille/g_4","north",
          }));
    }
