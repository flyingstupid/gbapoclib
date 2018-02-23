# include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(!present("amulet")) {
    move_object(clone_object("players/blake/amulet"),this_object());
    command("wear amulet");
    }
      
  if(arg) return;
  set_name("Apprentice");
  set_level(12);
  set_gender(random(2) + 1);
  set_short("An apprentice");
  set_long(
    "This is a young elfin apprentice that is trying to learn some magic. \n"+
    "The apprentice spends almost every moment of her awake time studying \n"+
    "old tomes trying to figure out some new complex formulas.\n");
  set_alignment(150);
  add_money(random(150)+300);
  add_class("mage");
  set_race("elf");
  set_wander(50,90);
  load_chat(5, ({
    "Apprentice says: Good day. \n",
    "Apprentice looks around for some spellcomponents. \n",
    "Apprentice ponders the situation. \n",
    "Apprentice asks: Can you help me with this formula? \n",
}));
   load_a_chat(6, ({ "Apprentice exclaims: Please don't hurt me! \n",
                     "Apprentice exclaims: Beware of my powers! \n",
                     "Apprentice exclaims: Leave me alone! \n",
                     "Apprentice sobs quietly. \n",
                      }));
   load_spells(50,({ "acid arrow", "bbb", "fire ball", "shield",
                     "coc", }));
   set_magic_resist(10);
}
