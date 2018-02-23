//
//  obj/crafting/plank.c
//
// object file for shaft part
//

inherit "obj/craft_base.c";

void reset(status arg)
{
    if(arg) return;
    
    set_difficulty(0);
    set_quality(100);
    set_name("plank");
    set_alias("plank");
    set_short("wooden plank");
    set_long("A long wooden plank that can be used for crafting.\n");
    set_extra_info("This is a wooden plank it is refined from wood.\n"
                   "This item is only obtained from the storeroom\n"
                   );
}

status get()
{
    return 1;
}

mapping query_resource_cost()
{
    return copy( ([ "wood":1 ]) );
}
