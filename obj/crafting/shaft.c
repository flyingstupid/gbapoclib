//
//  obj/crafting/shaft.c
//
// object file for shaft part
//

inherit "obj/craft_tool.c";

void reset(status arg)
{
    if(arg) return;
    
    set_components("plank,plank,plank");
    set_difficulty(2);
    set_quality(100);
    set_name("shaft");
    set_alias("shaft");
    set_short("wooden shaft");
    set_long("A long wooden shaft that can be attached to a tool head.\n");
    set_extra_info("This is a wooden Shaft, it can be used for a number of tools.\n"
                   "3 wooden planks are required to construct this tool.\n"
                   );
}

status get()
{
    return 1;
}