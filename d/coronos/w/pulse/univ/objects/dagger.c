/******************************************************************************
 * dagger.c
 * Generic dagger
 * 
 * Pulse
 * October, 1996
 */

#include <mudlib.h>
inherit WEAPON;

void reset(status arg) {
    if (arg) {
	return;
    }

    ::reset();
    set_name("dagger");
    set_type("slash");

    set_short("A sharp dagger");
    set_long(
      "A sharp dagger that any respectable mage would carry.\n"
"This dagger is made out of steel and sharpened by the dwarves of \n"
"the island.  It shows the pride they take in the making of weapons.\n"
    );

    set_wc(8);
    set_length(15);
    set_weight(2);
    set_value(350);
}


