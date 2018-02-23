inherit "inherit/weapon";

reset (arg) {
  if (arg) return;
  set_name("dagger");
  set_type("thrust");
  set_short("A silver dagger");
  set_long("A very fine looking dagger, the blade is made of silver and the.\n"+
                   "hilt is made of ivory.\n");
  set_wc(9);
  set_length(18);
  set_weight(3);
  set_value(500);
}
