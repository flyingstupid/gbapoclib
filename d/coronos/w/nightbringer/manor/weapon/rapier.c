/* RAPIER */
/* Author : DarkBringer  */
/* 04-24-97 */


inherit "inherit/weapon";

void reset(status arg) {
  if(arg) return;
  set_name("rapier");  /* weapon type as set_name() see guidelines */
  set_alias("sword");
  set_short("rapier");
  set_long("It has a long, slender blade .\n");
  set_value(1700);         /* see guidelines for valid weight, value, wc */
  set_weight(3);
  set_wc(12);
  set_length(48);        /* length in inches, for two weapon use */
  set_type("slash");     /* set default weapon attack messages   */
  set_info("A finely crafted sword, it can do some damage.\n");

}

