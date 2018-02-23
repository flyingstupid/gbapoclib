/* LONG SWORD */
/* Author : DarkBringer  */
/* 04-24-97 */


inherit "inherit/weapon";

void reset(status arg) {
  if(arg) return;
  set_name("longsword");  /* weapon type as set_name() see guidelines */
  set_alias("sword");
  set_short("longsword");
  set_long("This is a finely crafted longsword.\n");
  set_value(2300);         /* see guidelines for valid weight, value, wc */
  set_weight(4);
  set_wc(13);
  set_length(45);        /* length in inches, for two weapon use */
  set_type("slash");     /* set default weapon attack messages   */
  set_info("A finely crafted sword, it'll put a serious hurt on someone.\n");

}

