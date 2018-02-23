inherit "inherit/treasure";

reset (arg) {
   if(arg) return;
   set_name("hand");
   set_alias("hedge");
   set_short("Hedge hand");
   set_long("This is a rather large hedge which has been trimmed in the"+
     " shape of a\nhand holding a large orb.\n");
   set_weight(100000);
   set_value(0);
}
