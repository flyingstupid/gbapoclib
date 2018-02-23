//
//  obj/crafting/dress.c
//


inherit "obj/craft_clothing.c";

void reset(status arg)
{
    if(arg) return;
    
    set_components("cloth,cloth,cloth");
    set_difficulty(15);
    set_quality(100);
    set_name("dress");
    set_alias("dress");
    set_short("dress");
    set_long("This is a pretty dress.\n");
    set_extra_info("This is a dress, it can be worn as clothing.\n"
                   "3 cloths are required to construct this clothing.\n"
                   );
}

status get()
{
    return 1;
}