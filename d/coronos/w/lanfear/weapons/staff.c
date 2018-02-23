inherit "inherit/weapon";

reset(arg) 
{
  if(arg) return;

  set_name("staff");
  set_short("A long staff");
  set_long("The staff is made of ebony and it's covered \n"+
	   "with complicated inlays of cedar. \n");
  set_length(80);
  set_type("crush");
  set_sell_destruct(1);
  set_value(1100);
  set_wc(12);
  set_weight(5);
  set_smell("It hardly smells anything.\n");
}

