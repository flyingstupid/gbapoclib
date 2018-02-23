#include <mudlib.h>
inherit FOOD;
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("turkey leg");
  set_short("a smoked turkey leg");
  set_alias("leg");
  set_long(
    "This is a smoked turkey leg cooked by Frank.  It looks so rich and\n"+
    "juicy that your mouth is already watering.  The large hunk of steaming\n"+ 
    "meat gives off an aroma so tantalizing that you almost don't want to\n"+
    "eat it, just to savor its scent a bit longer.\n");
  set_smell(
    "The rich smell of the leg fills your lungs and makes your taste buds\n"+
    "tingle.  Oils, Spices, and smoke from different types of wood mingle\n"+
    "together to create an exquisit aroma that only Frank has perfected.\n");
  set_value(0);                /*to not buy*/
  set_strength(30+random(12)); /*36Hp would cost 2Plat.  Half of the time*/  
                               /*you get more Hp than you payed for. Yumm*/
  set_weight(1);              
}
