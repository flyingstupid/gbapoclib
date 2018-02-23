#include <mudlib.h>
#define OBJ	"room/city/mage/dungeon/obj/"
inherit MONSTER;

void make_items();
void reset(status arg) {
    ::reset(arg);
    if(arg) {
	make_items();
	return;
    }
    set_name("jallon");
    set_short("Jallon, the wizard master");
    set_alias("journeyman");
    set_long(
      "The man before you appears to be in his mid 30's."+
      " His robes mark him \n"+"as a wizard master "+
      "close to becoming a master. He is on duty here \n"+
	"making sure all the wards are in place.\n"+
	"Jallon is a White Robe Mage.\n");

    set_al(100); 
    set_race("human");
    add_spell_immune("charm");
    set_gender(1);
    load_chat(5, ({
	"Jallon exclaims: Please! I have work to do.\n",
	"Jallon preforms a ritual.\n",
	"Jallon says : The wards here are in a delicate balance.\n",
	"Jallon scratches his head.\n",

      }));
    load_a_chat(8,({
	"Jallon shouts: Stop, you must not break the seals!\n",
	"Jallon prepairs a spell.\n",
      }));
    add_class("mage");
    load_spells(20,({ 
	"fire shield", "burning hands", "comet", "chill touch", 
	"ice storm", "stoneskin", "chain lightning", "death spell",
      }));
    set_level(15);
    set_max_hp(1500);
    set_hp(1500);
    add_money(100 + random(500));
    set_magic_resist(45 + random(50));
    make_items();
    set_heart_ob(this_object());
}




void make_items() {
    object obj;

    if(!present("dagger"))
	move_object(clone_object("room/city/obj/dagger"),this_object());
    if(!present("robe"))
	move_object(clone_object(OBJ+"jmanrobe"),this_object());
    command("wear robe",this_object());
    command("wield dagger",this_object());
    set_wc(20); set_ac(12);

}
