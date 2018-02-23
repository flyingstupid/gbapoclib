/******************************************************************************
 * longsword.c
 * Generic longsword
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
    set_name("longsword");
    set_type("slash");
    set_alias("sword");
    set_short("A steel longsword");
    set_long(
      "An unadorned steel longsword, the essential companion for any fighter.\n"
    );

    set_wc(13);
    set_length(42);
    set_weight(5);
    set_value(1800);
}


