inherit "inherit/weapon";

reset(arg) {
    if(arg) return;

  set_name("dagger");
  set_short("A nice dagger");
  set_long(
	"A small bladed knife. Its hilt is made of simple wood.\n");
  set_length(5);
  set_type("slash");
  set_sell_destruct(1);
  set_value(800);
  set_wc(10);
  set_weight(3);
}
