//
//  obj/crafting/sign_axe.c
//
// object file for shaft part
//

inherit "obj/craft_weapons.c";

void reset(status arg)
{
    if(arg) return;

    set_difficulty(20);
    set_name("axe");
    set_alias("traffic");
    set_short("traffic sign axe");
    set_long("A hand crafted death machine, its one part traffic sign.\n"+
             "One part handle and one part put ingunity. Sure it may not be as good\n"+
             "as what you can actually find in the hardware stores, but man in a pinch"+
             "it kills stuff pretty damn well.  This weapon can be made with a shaft and"+
             " a sign.\n");
    
    set_type("Cleave");
    set_components("shaft,sign");
    set_length(48);
    set_wc(10); /* less damage than a store bought axe */
    set_weight(5); /* lighter than a normal axe */
    set_value(470); /* worth quite a bit for some signs hammered together */
}


