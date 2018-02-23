//
//  obj/crafting/pickaxe_head.c
//
// object file for shaft part
//

inherit "obj/craft_tool.c";
void reset(status arg)
{
    if(arg) return;
    set_components("iron ingot,iron ingot");
    set_difficulty(7);
    set_quality(100);
    set_name("pickaxe head");
    set_alias("pickaxe head");
    set_short("pickaxe head");
    set_long("A metal shovel head.\n");
    set_extra_info("This is a iron pickaxe head, it can be used to make a pickaxe.\n"
                   "A shovel head and a wooden shaft are required to construct this tool.\n"
                   );
}

status get()
{
    return 1;
}