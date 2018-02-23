#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  object obj;

  ::reset(arg);
  if(!present("necklace")) {
    obj = clone_object(CLOTHING);
    obj -> set_name("necklace");
    obj -> set_short("A dirty necklace");
    obj -> set_plural("dirty necklaces");
    obj -> set_long("What was once a lovely gold necklace is now dirty and \n"+
		  "dusty. It looks badly treated and worth very little.  \n");
    obj -> set_value(200);
    obj -> set_weight(1);
    move_object(obj, this_object());
    init_command("wear necklace");
  }
  if(arg) return;
  set_name("greeli");
  set_race("human");
  set_alias("thief");
  add_class("thief");
  add_class("mage");
    load_spells(90, ({ "magic missile", "chill touch",
	"acid arrow", "charm person", "bbb", "cone of cold", }));
  add_class("fighter");
  set_gender(1);
  set_short("Greeli the thief");
  set_alignment(-100);
  set_long(
	"Greeli's scar pocked face peers out from his soiled ragged cloak, \n"+
	"his eyes weepy and tired with sickness. Although Greeli is but a  \n"+
	"beggar, he is a skilled thief as well.\n");
  set_level(8);
  set_steal_chance(80);
  load_chat(12, ({ "Greeli says: Hey, gimme some coppers.\n",
	"Greeli sneazes into his hands.\n",
	"Greeli picks his nose.\n",
	"Greeli asks: Eh, gimme one of those pal?\n",
  }));

  load_a_chat(15,({ "Greeli says: Gimme a break.\n",
	"Greeli exclaims: Bugger off!\n",
	"Greeli bursts out into tears!\n",
	"Greeli kicks you in the ribs.\n",
	"Greeli tries to hide in the shadows.\n",
  }));
  add_money(500);
  set_heart_ob(this_object());
}

void monster_heart_beat() {
  int i;
  object *inv;

  inv = all_inventory(this_object());
  for(i=0; i<sizeof(inv); i++) {
    if(inv[i]->query_value() > 200) 
    {
      call_out("tell_me", 1);
      destruct(inv[i]);
    }
  }
}

void tell_me() {
/* the message that he steals is given before players
 enterring messages is written. Looks odd */
  tell_room(environment(), "Greeli slips something into his pocket.\n");
}
