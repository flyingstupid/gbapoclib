/* MACE +2 */
/* Author : DarkBringer  */
/* 03-26-97 */
inherit "inherit/weapon";

void reset(status arg) {
  if(arg) return;
  set_name("mace");
  set_short("a mace");
  set_long(
"This mace is finely crafted. It is made of black steel.\n");
  set_value(3100);
  set_weight(4);
  set_wc(14);
  set_length(35);
  set_type("crush");
}

