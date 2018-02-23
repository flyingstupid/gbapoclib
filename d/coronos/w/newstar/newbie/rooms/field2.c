/* field2.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

 if(!present("cow")) {
    int i;
    for(i=0; i<4; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/newbie/npc/cow"),this_object());
    } 
  }

  if(arg) return;
 
  set_short("a cow field");
  set_long(
    "This is a large cow field filled with luscious, green grass that\n"+
    "is perfect for grazing animals.  Many different types of little\n"+
    "wild flowers add pleasing splashes of colours and small clusters of\n"+
    "bushes are scattered throughout.  Off to the north lies a big pond,\n"+
    "beyond looms a dark forest.  A farmhouse can be seen in the distant\n"+
    "south and to the west is another field.");
  set_day_desc(
    "  The sun shines pleasently,\n"+
    "warming the earth from an open blue sky.  Butterflies float\n"+
    "peacefully amoung the flowers.\n");
  set_night_desc(
    "  The field is illuminated\n"+
    "by silvery light cast from a glowing moon.  Thousands of twinkling\n"+
    "stars sparkle in the night sky.  \n");
  set_items(({
    "field#cow field",
      "This is a beautiful, green field filled with wild flowers.\n"+
      "It is perfect for grazing cattle and other animals.\n",
    "farmhouse#farm",
      "The cheery looking farmhouse is far to the south.\n",
    "pond#north",
      "Off to the north is a medium sized pond.\n",
    "grass",
      "The luscious, green grass grows tall, almost up to your knees.\n"+
      "In several places it has be cropped short by the grazing animals.\n",
    "wild flowers#flowers",
      "The splendor of the wilderness is brought out in the beauty of\n"+
      "these little wild flowers.  They enhance the field with their\n"+
      "array of colours.\n",
    "cluster#clusters",
      "Small clusters of bushes dot the field, providing meager shade and\n"+
      "shelter.  They also provide a variety in the cattle's diet.\n",
    "bushes#bush",
      "Small clusters of bushes seems to be strewn about the vast field.\n"+
      "They provide a little shade, shelter and variety.\n",
    "dark forest#forest",
      "Far off in the hazy distance, stands a dark, almost gloomy forest.\n"+
      "It does not look too particularly inviting.  You wonder what could\n"+
      "live there, in the darkness with who knows what.\n",
    "another field#west",
      "Another field lies ajacent to the cow field off the the west.\n"+
      "A barn can be seen off to the far end.\n",
    "barn",
      "On the far end of the other field sit a large, old barn.  It is\n"+
      "probably still used to house a variety of farm animals.\n",
    }));
  set_day_items(({
    "sky",
      "The sky is a marvelous blue, vast and open and dotted with\n"+
      "fluffy white clouds.\n",
    "sun",
      "You shield your eyes from the bright rays of sunlight.\n",
    "clouds",
      "The fluffy white clouds float happily through the sun warmed sky.\n",
    "earth",
      "Rich, dark brown earth just right for growing healthy grass.\n",
    "butterfly#butterflies",
      "Beautiful butterflies of various sizes and colours are attrached\n"+
      "to this cow field because of its gorgeous wild flowers.  They\n"+
      "flit and float peacefully from flower to flower.\n",
    }));
  set_night_items(({
    "sky",
      "The black, velvet sky covers the earth like a blanket.  One silver\n"+
      "moon and thousands of sparkling stars hang within its darkness.\n"+
      "Thin clouds pass silently along, glowing by the light of the moon.\n",
    "stars#star",
      "The stars sparkle like little diamonds in the sky.\n",
    "moon",
      "A large silvery moon glows in the darkened sky, casting an\n"+
      "soft light over the field.\n",
    "light",
      "A silvery light cast by the moon which illuminates this field.\n",
    "clouds#cloud",
      "Thin streaks of clouds pass silently along in the dark sky,\n"+
      "glowing slightly by the silvery light shed from the moon.\n",
 
    }));
  set_smell(
    "The scent of the flowers mixes in with the fresh scent of the grass.\n"+
    "A lingering scent of meadow muffins permiates underneath it all.\n");
  set_listen(
    "You hear some birds chirp cheerfully from the bushes and the wind\n"+
    "rustles throught the leaves and the grass.\n");
  set_weather(2, 4, 0);  /*beginning newbie area. lit by moon at night.*/
  set_exits(({
      "/d/coronos/w/newstar/newbie/rooms/pond1", "north",
      "/d/coronos/w/newstar/newbie/rooms/field1",  "west",
      }));
}


 
void init() {
  add_action("pick1", "pick");
  ::init();
}



status pick1(string str) {
  string tmp1, tmp2;
 
  if(!str) {
    write("What are you trying to pick?\n");
    return 1;
    }
 
  else if(sscanf(str, "%sflower%s", tmp1, tmp2)) {
    write(
      "You pick a a pretty flower from the field.\n");
    say(this_player()->query_name()+
      " picks a pretty flower from the field.\n", this_player());
    move_object(clone_object(
      "d/coronos/w/newstar/newbie/items/flower"), this_player());
    return 1;
    }
   return 0;
}
