/* LONG SWORD +1 */
/* Author : DarkBringer  */
/* 04-26-97 */


inherit "inherit/weapon";

void reset(status arg) {
  if(arg) return;
  set_name("longsword");
  set_alias("sword");
  set_short("longsword");
  set_long("This is a finely crafted longsword.\n");
  set_value(3100);
  set_weight(4);
  set_wc(14);
  set_length(45);
  set_type("slash");
  set_info("A finely crafted sword, it'll make someone cry for their mama.\n");

}

