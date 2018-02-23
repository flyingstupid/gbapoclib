
#include <mudlib.h>
inherit TREASURE;

reset (arg){
    if(arg) return;

    set_weight(1);
    set_value(10);
    set_name("Gem");
    set_alias("dragem");
    set_short("Dragon's Gem");
    set_singular( "Gem" );
    set_plural( "Gems" );
    set_long("It looks like a red stone set in a metal band.\n");
    set_extra_info("It doesn't look very valuable but it has a carving of\n"+
      "a red dragon on it."); 
}
