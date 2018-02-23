inherit "inherit/weapon";

reset(arg) {
    if(arg) return;
    set_short("baseball bat");
    set_long("An alumnium baseball bat.\n");
    set_type("Crush");
    set_length(36);
    set_name("baseball");
    set_alias("bat");
    set_wc(9); /* Baseball bat from the store damage! */
    set_weight(4); /* As heavy as it comes for weapons of WC12 */
    set_value(400); /* worth the average amount */
}