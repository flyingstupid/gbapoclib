inherit "inherit/weapon";

reset(arg) {
    if(arg) return;
    set_short("ka-bar");
    set_long("\n");
    set_type("Slash");
    set_length(24);
    set_name("kabar");
    set_alias("knife");
    set_wc(8); /* Long knife */
    set_weight(3); /* standard weight for a solid knife */
    set_value(280); /* worth the average amount */
}