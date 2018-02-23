/* DAGGER */
/* Author : DarkBringer  */
/* 03-26-97 */
inherit "inherit/weapon";

void reset(status arg) {
  if(arg) return;
  set_name("dagger");
  set_short("dagger");
  set_long(
"A nice steel dagger.\n");
  set_value(350);
  set_weight(2);
  set_wc(8);
  set_length(15);
  set_type("slash");
}

