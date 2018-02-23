/* Giant Spider */
/* Author:DarkBringer */
/* 04-26-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Giant Spider");
  set_name("giant spider");
  set_alias("spider");
  set_race("spider");
  set_long(
"It is a viscious, black, hunting spider. It has eight long, hairy\n"+
"legs attached to a slender abdomen. Its head is small, with eight\n"+
"glassy eyes and sharp fangs.\n");


  set_gender(1);
  set_level(3);
  set_ac(4);
  set_wc(7);
  set_aggressive(1);

  add_class("fighter");


  load_a_chat(5,({"Spider hisses\n",
    }));

  set_attack_msg(({
  "brushes softly",       "with its leg",
  "barely touches",       "with its leg",
  "touches lightly",      "with its leg",
  "slaps meanly",         "with its leg",
  "bites softly",         "with its teeth",
  "bites lightly",        "with its teeth",
  "bites meanly",         "with its teeth",
  "bites severly",        "with its teeth",
               }));

  }
