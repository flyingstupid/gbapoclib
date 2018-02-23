/* DWARVEN BATTLE AXE */
/* Author : DarkBringer  */
/* 03-24-97 */
inherit "inherit/weapon";

void reset(status arg) {
  if(arg) return;
  set_name("battle axe");  /* weapon type as set_name() see guidelines */
  set_alias("axe");
  set_short("battle axe");
  set_long(
"This battle axe is finely crafted by the skilled Mountain Dwarf armoures.\n"+
  "It is the standard fare of the Derro's.\n");
  set_value(2500);         /* see guidelines for valid weight, value, wc */
  set_weight(5);
  set_wc(14);
  set_length(48);        /* length in inches, for two weapon use */
  set_type("cleave");     /* set default weapon attack messages   */
}

