inherit "inherit/weapon";

reset(arg) {
    if(arg) return;

  set_name("rapier");
  set_short("A rapier");
  set_long("The rapier is made of iron but the hilt and guard is made of \n"+
           "pure silver. It's a very old rapier and the former owner must \n"+
           "have used it quite frequently. \n");
  set_length(48);
  set_type("slash");
  set_sell_destruct(1);
  set_value(1800);
  set_wc(12);
  set_weight(5);
}
