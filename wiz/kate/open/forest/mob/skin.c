//
//  wiz/kate/open/forest/mob/skin.c
//  Second Chance
//
#include <mudlib.h>
#include "/wiz/emraef/open/scav/scavpaths.h"
inherit RESOURCE;

void reset(status arg)
{
    if(arg) return;
    set_name("skin");
    set_plural( "skin" );
    set_short("an animal skin");
    
    set_long(
             "This is a unit of animal skin. It can be used to \n"+
             "make things in the town.\n");
    
    set_weight(1);
    set_value(0);
    set_alias("skin");
    
    set_resource_type( "skin" );
}
