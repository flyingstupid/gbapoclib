/* rooster.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
#define PATH    "d/coronos/w/newstar/newbie/rooms/"
#define MESSAGE (string)"A rooster crows as dawn breaks upon the land.\n"
inherit MONSTER;
int NUM;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  NUM = 1;
  set_name("rooster");
  set_short("a rooster");
  set_long(
    "This is a proud rooster in the prime of his life.  He is a\n"+
    "deep, rust red with multi-coloured tail feathers.  He knows\n"+
    "he's king of the roost and plans to stay that way for a very\n"+
    "long time.\n");
  load_chat(5, ({
    "The rooster struts around proudly.\n",
    "The rooster flutters his wings.\n",
    "The rooster puffs out his chest and crows loudly.\n",
    "The rooster scratches at the ground with his foot.\n",
    "The rooster looks at you strangely, cocking his head from side to side.\n",
    "The rooster pecks at the ground.\n",
    }));
 
  load_a_chat(40, ({
    "The rooster flutters his wings furiously.\n",
    "Rooster feathers fly everywhere.\n",
    "The rooster strikes with vicious, kicking feet.\n",
    "The rooster puffs up and lets out a loud, challenging crow.\n",
    }));
  set_attack_msg(({
    "nudged", "softly with his wing",
    "bumped", "slightly with his beak",
    "slapped", "around the face with his wings",
    "scratched", "with his clawed foot",
    "pecked", "rapidly on the foot",
    "kicked", "hard with his feet.",
    "bit", "deep with his beak",
    }));
 
  set_al(0);
  set_level(1);
  set_gender(1);
  set_money(10 + random(10));
  set_race("bird");
  set_heart_ob(this_object()); 
}



void monster_heart_beat() {

  if(!"/obj/weather"->query_day()) {
    NUM = 0;
  }

  if("/obj/weather"->query_day() && NUM!=1) {
    NUM = 1;
    tell_room(PATH+"barn1",MESSAGE);
    tell_room(PATH+"barn2",MESSAGE);
    tell_room(PATH+"field1",MESSAGE);
    tell_room(PATH+"field2",MESSAGE);
    tell_room(PATH+"pond1",MESSAGE);
    tell_room(PATH+"pond2",MESSAGE);
    tell_room(PATH+"house1",MESSAGE);
    tell_room(PATH+"house2",MESSAGE);
    tell_room(PATH+"house3",MESSAGE);
    tell_room(PATH+"house4",MESSAGE);
    tell_room(PATH+"yard",MESSAGE);
    tell_room(PATH+"garden",MESSAGE);
    tell_room(PATH+"path1",MESSAGE);
    tell_room(PATH+"path2",MESSAGE);
    tell_room(PATH+"forest1",MESSAGE);
    tell_room(PATH+"forest2",MESSAGE);
    tell_room(PATH+"forest3",MESSAGE);
    tell_room(PATH+"forest4",MESSAGE);
    tell_room(PATH+"forest5",MESSAGE);
    tell_room(PATH+"forest6",MESSAGE);
    tell_room(PATH+"tree1",MESSAGE);
    tell_room(PATH+"tree2",MESSAGE);
    tell_room("players/darkness/workroom",MESSAGE);
    tell_room("players/newstar/workroom",MESSAGE);
  }
}
