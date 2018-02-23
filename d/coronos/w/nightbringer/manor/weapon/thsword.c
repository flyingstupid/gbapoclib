/* twohandedSword */
/* Author : DarkBringer  */
/* 03-10-97 */
inherit "inherit/weapon";

void reset(status arg) {
  if(arg) return;
  set_name("twohandsword");  /* weapon type as set_name() see guidelines */
  set_alias("sword");
  set_short("twohandedsword");
set_long("This Sword was made by both the High Elves and the Mountain Dwarves\n"+        "in tribute to Lord Penor.\n");
  set_value(2000);          /* see guidelines for valid weight, value, wc */
  set_weight(6);
  set_wc(14);
  set_length(72);         /* length in inches, for two weapon use */
  set_type("cleave");     /* set default weapon attack messages   */
}

