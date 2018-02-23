/* spider.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("spider");
  set_short("a huge spider");
  set_long(
    "This is huge, dark brown spider with lighter markings\n"+
    "adorning its back.  Its segemeted body is round and eight\n"+
    "very long and hairy legs stick out from around the head.\n"+
    "It watches you with multiple, emotionless eyes.\n");
 
  load_chat(5, ({
    "A spider crawls over your foot.\n",
    "A spider hangs down from a thread.\n",
    "A spider speeds across the ground.\n",
    "A spider stands still and watches you with multiple eyes.\n",
    "A spider works its jaws hungrily.\n",
    }));
 
  load_a_chat(40, ({
    "The spider tries to crawl away, but fails.\n",
    "The spider scurries about frantically.\n",
    "The spider tries to look threatening.\n",
    }));
  set_attack_msg(({
    "missed", "barely",
    "nudged", "softly with a leg",
    "bumped", "lightly with two legs",
    "smacked", "hard with its legs",
    "pinced", "on the hand",
    "bit", "deep on the ankle",
    "sunk its fangs into", "",
    }));
 
  set_al(-200);
  set_level(2);
  set_ac(3);
  set_wc(6);
  set_gender(0);
  set_money(39 + random(11));
  set_race("arachnid");
}
