inherit "inherit/weapon";

reset(arg) {
    if(arg) return;
    set_short("sledge hammer");
    set_long("A standard issue sledge hammer from any prenuke hardware store.\n");
    set_type("Crush");
    set_length(35);
    set_name("sledge");
    set_alias("hammer");
    set_wc(12); /* sledge hammer from the hardware store damage! */
    set_weight(6); /* As heavy as it comes for hammers of WC12 */
    set_value(870); /* worth the average amount */
}