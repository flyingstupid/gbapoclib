#include <mudlib.h>
inherit MONSTER;

void make_items();
void reset(status arg){
    object item;
    object item2;
    ::reset(arg);
    if(arg) make_items();
    set_id("red dragon");
    set_short("Red Dragon");
    set_long(
      "A huge winged reptile with fiery eyes, a crested head, and enormous claws.\n"+
      "This one has scaled, red skin and smoke coming from its nostrils.  It \n"+
      "appears to be sleeping.\n");
    set_alias("dragon");
    set_plural("Red Dragons");
    set_level(38);
    set_max_hp(1700);
    set_hp(1700);
    set_ac(16);
    set_wc(25);
    set_name("red dragon");
    set_race("Red Dragon");
    add_class("fighter");
    add_class("mage");
    set_gender(1);
    load_a_chat(10,({"Dragon breathes deadly flames at you.\n",
	"Dragon bellows in rage.\n"}));
    load_chat(5,({"Dragon snores heavily.\n"}));
    set_money(5000);
    add_spell_immune("fire");
    add_spell_immune("charm");
    set_alignment(-10000);
    load_spells(10,({"fire ball","magic missile","shield",}));


    set_heart_ob(this_object());
}
