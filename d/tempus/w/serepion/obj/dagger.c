inherit "inherit/weapon";

reset (arg) {
  if (arg) return;
  set_name("dagger");
  set_type("thrust");
  set_short("A fine dagger");
  set_long("A very fine looking dagger, with a beautifuly ivory hilt.\n");
  set_wc(9);
  set_length(18);
  set_weight(3);
  set_value(500);
}
