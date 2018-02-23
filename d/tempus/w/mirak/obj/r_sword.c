inherit "inherit/weapon";

reset(arg) {
    if(arg) return;
    set_short("A rusty shortsword");
    set_long("This is just a old rusty shortsword\n");
    set_type("Slash");
    set_length(24);
    set_name("shortsword");
    set_alias("sword");
    set_wc(8); /* it is rusty */
    set_weight(2); /* its rusty ie wieght is less cuz of oxidation */
    set_value(0); /* its a worthless piece of rust */
}
