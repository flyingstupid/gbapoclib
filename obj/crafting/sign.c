//
//  obj/crafting/sign.c
//
// object file for shaft part
//

inherit "obj/craft/tool.c";

void reset(status arg)
{
    if(arg) return;
    
    set_difficulty(0);
    set_quality(100);
    set_name("sign");
    set_alias("sign");
    set_short("traffic sign");
    set_long("A metal traffic sign.\n");
    set_extra_info("This is a traffic sign.\n"
                   "This item is only obtained from the scavenging.\n"
                   );
}

status get()
{
    return 1;
}
