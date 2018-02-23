//
//  obj/crafting/cloth.c
//
// object file for shaft part
//

inherit "obj/craft_base.c";

void reset(status arg)
{
    if(arg) return;
    
    set_difficulty(0);
    set_quality(100);
    set_name("cloth");
    set_alias("cloth");
    set_short("cotton cloth");
    set_long("A bolt of cotton cloth.\n");
    set_extra_info("This is a bolt of cloth it is refined from cotton.\n"
                   "This item is only obtained from the storeroom\n"
                   );
}

status get()
{
    return 1;
}

mapping query_resource_cost()
{
    return ([ "cotton":3 ]);
}
