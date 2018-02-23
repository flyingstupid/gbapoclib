inherit "inherit/weapon";

reset (arg) {
  if (arg) return;
  set_name("battleaxe");
  set_alias("axe");
  set_type("cleave");
  set_short("A giant battle axe");
  set_long("A very large battle axe, made of very fine quality.\n");
  set_wc(15);
  set_length(54);
  set_weight(5);
  set_value(3500);
  set_sell_destruct(1);
}
