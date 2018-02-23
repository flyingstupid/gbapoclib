#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  
  if(arg) return;

  set_alias("guard");
  set_name("ebony guard");
  set_gender(1);
  set_level(10);
  set_money(700);
  set_wc(14);
  set_ac(8);
  set_race("human");
  set_short("Ebony Guard");
  set_long(
"Proud, aware and confident, that is the best way to describe him.  He seems\n"+
"to be aware of everything that is happening around him.  In addition to this\n"+
"astute awareness, there also seems to be an eagerness for conflict in his\n"+
"posture.  The Ebony Guard have always been know for their swiftness in the\n"+
"application of deadly force whenever their authority comes into question.\n"
"This goes back to the days when Baron Sardin ruled with an iron fist and an\n"+
"indifferent attitude towards his people's health and well being.  It would not\n"+
"be a good idea to cross this guard any time in the near future.\n");
  load_spells(30, ({"cmw", "bls", "crs", "hwd"}));
  load_chat(8, ({"Guard stares at you suspiciously.\n",
                 "Guard says:  Keep you nose clean in my city.\n",
                 "Guard says:  Please, give me a reason to smash you.\n",
                 "Guard glares at you.\n",
                 "Guard says:  Move along, no loitering.\n",
            }));
  load_a_chat(12, ({"Guard sreams a war cry as he attacks.\n",
                    "Guard says:  You will mourn the day you became so foolish\n"+
                    "Guard calls for reinforcements.\n",
                    "Guard assumes an offensive position\n",
                    "Guard grins and says:  You're gonna die today.\n"
              }));
}
