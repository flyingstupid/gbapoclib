inherit "inherit/weapon";

reset(arg) {
    if(arg) return;
    set_short("axe");
    set_long("A standard issue axe from any prenuke hardware store.\n");
    set_type("Cleave");
    set_length(48);
    set_name("ax");
    set_alias("axe");
    set_wc(12); /* axe from the hardware store damage! */
    set_weight(6); /* As heavy as it comes for hammers of WC12 */
    set_value(870); /* worth the average amount */
}