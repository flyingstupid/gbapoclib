#include <mudlib.h>
inherit MONSTER;

void make_items();
static object robe;
void reset(status arg) {
  ::reset(arg);
  if(arg && !present("robe")) {
    make_items();
  }
  else {
    set_name("julie");
    set_alias("clerk");
    set_short("Julie the city clerk");
    set_long(
       "Julie is the city clerk for Ille Coronos; a hard and dilligent worker. \n"+
       "Long ago she used to be a studious mage, adventuring in the wild \n"+
       "lands beyond the city. But they were many years ago, and now she \n"+
       "works sorting through papers and council documents, and helping  \n"+
       "other adventurers when she can.                                  \n");
    set_gender(2);
    set_race("half elf");
    set_level(6);
    set_hp(100000000000);  /* we don't want her killed now do we 8) */
    set_ac(6);
    set_wc(10);
    add_money(50 + random(50));
    load_spells(20, ({ "miss", "acd" }));
    make_items();
  }  
}

void make_items() {
  robe = clone_object("inherit/clothing");
  robe -> set_name("robe");
  robe -> set_weight(1);
  robe -> set_short("A blue robe");
  robe -> set_long(
     "This blue robe bears the crest of the city of Ille Coronos, and is \n"+
     "adorned with many medals and symbols of distinction.\n");
  robe -> set_value(250);
  move_object(robe, this_object());
  init_command("wear robe");
}
