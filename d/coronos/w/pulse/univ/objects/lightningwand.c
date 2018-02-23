/******************************************************************************
 * icewand.c
 * Standard Issue Ice Wand
 * 
 * Adrik
 * October, 1996
 */

/* The class defaults to ice, so no coding here =) */

inherit "/d/coronos/w/pulse/univ/class/wand";


string set_wand_type() {
    return "lightning";
}

void init_wand_features() {
    add_spell( "lightning bolt" );
    add_spell( "call lightning" );
}
