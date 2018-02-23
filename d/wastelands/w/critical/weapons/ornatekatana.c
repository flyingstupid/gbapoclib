inherit "inherit/weapon";

reset(arg) {
    if(arg) return;
    set_short("ornate katana");
    set_long("An ornate display katana that has been crudely sharpened.\n");
    set_type("Slash");
    set_length(35);
    set_name("kanata");
    set_alias("katana");
    set_wc(10); /* A very junky katana, this is a sharpened display peice */
    set_weight(5); /* Slightly heavy, because its junky heh */
    set_value(520); /* worth the average amount */
}