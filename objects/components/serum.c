 
inherit "inherit/treasure";
 
reset (arg){
    if(arg) return;
 
    set_weight(4);
    set_value(500);
    set_name("serum");
    set_short("vial of healing serum");
    set_long("A little glass vial of healing serum.\n");
   // set_extra_info("It doesn't look very valuable.");
}
