//
//  obj/crafting/shovel.c
//
// object file for a shovel
//

inherit "obj/craft_tool.c";

void reset(status arg)
{
    if(arg) return;
    
    set_components("shaft,shovel head");
    set_difficulty(12);
    set_name("shovel");
    set_alias("shovel");
    set_short("shovel");
    set_long("A metal shovel.\n");
    set_extra_info("This is a simple iron shovel, it can be used for digging.  A wooden \n"
                   "shaft and a shovel head are required to construct this tool.\n"
                   );
    
    
}

status get()
{
    return 1;
}

