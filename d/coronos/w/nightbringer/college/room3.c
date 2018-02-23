#include <mudlib.h>
inherit STORE;

void reset(status arg) {
   ::reset(arg);

/*   add_inventory ("d/coronos/w/nightbringer/college/item/bag");
   add_sell_items ("bag"); */


   if(arg) return;
   set_short("Ma And Pa Kettle's General Store");
   set_long(
      "\t-=+ Ma And Pa Kettle's General Store +=-.\n"+
      "It is here that the students of Ille Coronos University do their\n"+
      "shopping. The inventory is pretty slim, as all it carries are basic\n"+
      "supplies for the pursuit of education. Shelves line the walls holding\n"+
      "various types and sizes of parchment, ink quills, and charcoal \n"+
      "pencils.  Hanging by two chains from the ceiling is an wooden sign.\n"
   );

   set_items(({

"shelves#shelf",
"Thin wooden shelves are attached firmly to the wall so as to not\n"+
"collapse under the weight of the items that sit upon them.\n",

"chains#chain",
"Two linked chains support the weight of the large wooden sign that\n"+
"bears instructions for the shop.\n",         

"inventory#supplies#basic supplies#supply#basic supply",
"Parchment, ink quills, and charcoal pencils are displayed on the shelves.\n",

"parchment#ink quill#ink quills#charcoal pencil#charcoal pencils",
"They are displayed on the shelves, awaiting purchase.\n",

   }));

   set_smell(
      "A most welcoming potpourri has been set out for your smelling pleasure.\n"
   );
   
   set_listen("You hear nothing unusaul.\n");

   set_weather(1,4,0);
   set_owner("Pa Kettle");

  set_exits(({
     "d/coronos/w/nightbringer/college/room1", "west",
  }));

} 

