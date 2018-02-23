/* forest6.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

  if(!present("cow")) {
    int i;
    for(i=0; i<5; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/newbie/npc/cow"),this_object());
    }
  }

  if(arg) return;
 
  set_short("a field");
  set_long(
    "This is an extensive field blanketed with lush grass, dotted with\n"+
    "tall trees and pretty little wild flowers.  It lies in the beginnings\n"+
    "of a sinister forest which looms ominously a ways to the north.  \n"+
    "Shadows from the dark forest contrast sharply with the cheeriness\n"+
    "of the field.  A crystal clear pond sparkles to the east.  To the\n"+
    "south is another little field in front of a barn.");
  set_day_desc(
     "  The sun sheds bright\n"+
    "rays of warming light that bask the field in glow.  The cold\n"+
    "shadows of the forest remains dark and dismal.\n");
  set_night_desc(
    "  The moon casts a pale,\n"+
    "eerie glow that is enchanced by the chilling presence of the forest.\n"+
    "Stars twinkle from far up above in the night sky.\n");
  set_items(({
    "field#cow field",
      "This is a beautiful, green field filled with wild flowers.\n"+
      "It is perfect for grazing cattle and other animals.\n",
    "pond#east",
      "Over to the east you spy a medium sized pond.  Looks perfect\n"+
      "for a swim.\n",
    "grass",
      "The luscious, green grass grows tall, almost up to your knees.\n"+
      "In several places it has be cropped short by the grazing animals.\n",
    "wild flowers#flowers",
      "The splendor of the wilderness is brought out in the beauty of\n"+
      "these little wild flowers.  They enhance the field with their\n"+
      "array of colours.\n",
    "trees#tree",
      "Many different types of tall trees grow about the field, getting\n"+
      "denser to the norther end.  They look ancient, like they have\n"+
      "seen many seasons.  They are the beginnings of the dark forest.\n",
    "dark forest#forest",
      "At the north end of the field, stands a dark, almost gloomy forest.\n"+
      "It does not look too particularly inviting.  You wonder what could\n"+
      "live there in the darkness with who knows what.\n",
    "little field#south",
      "Another little field lies quietly to the south of this field.\n"+
      "A big barn can be seen off to one side.\n",
    "barn",
      "On the far end of the other field sit a large, old barn.  It is\n"+
      "probably still used to house a variety of farm animals.\n",
    "shadow#shadows",
       "Cold, dark shadows creep forth from the ominous forest.\n"+
       "They slice the warmth of the cheerful field like a knife,\n"+
       "challenging the brave the walk amoung them.\n",
    }));
  set_day_items(({
    "sun",
      "You are temporily blinded from looking into the bright sun.\n",
    "light",
       "Warming rays of light make the field seem to glow.\n",
    "rays",
       "The bright rays of sunlight stream down gently touching\n"+
       "the blades of luscious grass.\n",
    }));
  set_night_items(({
    "sky",
      "The black, velvet sky covers the earth like a blanket.  One silver\n"+
      "moon and thousands of sparkling stars hang within its darkness.\n"+
    "stars#star",
      "Tiny balls of twinkling light are nestled in the night sky.\n",
    "moon",
      "A large silvery moon glows in the darkened sky, casting an\n"+
      "pale and eerie light over the field.\n",
    "light",
      "A silvery light cast by the moon which illuminates this field.\n",
    }));
  set_smell(
    "The scent of the flowers mixes in with the fresh scent of the grass.\n"+
    "A lingering scent of prarie pies permiates underneath it all.\n");
  set_listen(
    "Nature life goes on as usual under the sun, with chirping birds,\n"+
    "buzzing insects and a breeze rustling the vegetation.  But amoung\n"+
    "the shadows, all is deathly still.\n");
  set_weather(2, 4, 0);  /*beginning newbie area. lit by moon at night.*/
  set_exits(({
      "/d/coronos/w/newstar/newbie/rooms/pond1", "east",
      "/d/coronos/w/newstar/newbie/rooms/field1",  "south",
      "/d/coronos/w/newstar/newbie/rooms/forest5", "north",
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
      "You pick a a pretty wild flower from the field.\n");
    say(this_player()->query_name()+
      " picks a pretty wild flower from the field.\n", this_player());
    move_object(clone_object(
      "d/coronos/w/newstar/newbie/items/flower"), this_player());
    return 1;
   }
   return 0;
}
