#include <mudlib.h>
inherit MONSTER;

object robe, symb;
void reset(status arg) {
    ::reset(arg);

    if(arg) return;

    set_name("elf");
    set_short("Wood Elf");
    set_long("This is a Wood Elf who cares for the forest.\n");
    set_gender(random(2) + 1);
    set_level(random(2)+5);
    set_wc(9);
    set_ac(5);
    set_hp(100);
    set_al(30 + random(200));
    load_chat(9, ({ "Wood Elf asks: Do you know the secret ways?\n",
	"Wood Elf says:  The Undercliff has many secrets.\n",
	"Wood Elf looks at the sky.\n",
	"Wood Elf prays a silent prayer.\n",
	"Wood Elf says:  There are dragon lairs within these hills.\n"
      }));
    load_a_chat(10, ({ "Elf exclaims: You are evil!\n",
	"Wood Elf winces in pain.\n",
	"Elf prays a silent prayer.\n",
	"Wood Elf cries out in pain.\n",
	"Elf calls for divine aid.\n",
      }));

    load_spells(2, ({ "clw"}));
    set_race("human");

    robe = clone_object(CLOTHING);
    robe -> set_name("robe");
    robe -> set_alias("robes");
    robe -> set_short("Green Robes");
    robe -> set_long("The robes are green and lightweight.\n");
    robe -> set_value(50);
    robe -> set_sell_destruct(1);
    robe -> set_weight(1);
    move_object(robe, this_object());
    init_command("wear robe");

    symb = clone_object(CLOTHING);
    symb -> set_name("holy symbol");
    symb -> set_alias("symbol");
    symb -> set_short("A wooden holy symbol");
    symb -> set_weight(1);
    symb -> set_sell_destruct(1);
    symb -> set_value(20 + random(10));
    symb -> set_long(
      "The wooden symbol bears the image of a cluster of four leaves held\n"+
      "at the top by a ivy garland.\n");
    move_object(symb, this_object());
    init_command("wear symbol");
}

