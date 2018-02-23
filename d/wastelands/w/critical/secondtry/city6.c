#include <mudlib.h>
inherit ROOM;
 
 
 int is_workshop();
 
void reset(status arg) {
    
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("Second Chance's Workshops");
    set_long(
      "Second Chance's Workshops\n"+
      "Being the only concrete building around, the workshops are the highest degree\n"+
      "of craftmenship the city has ever been able to complete. Half bomb shelter and\n"+
      "half handy man's wet dream, this building has it all. Electric lights, \n"+
      "electric plugins for power tools and even a fully assembled forge for working\n"+
      "metals into tools. Each citizen pays a small amount of credits to work in the\n"+
      "workshop in order to keep it maintained but otherwise its always open to whoever\n"+
      "needs it. Posted on one wall are instructions for basic uses\n"
      );   
    set_exits(({
    "d/wastelands/w/critical/secondtry/city4","west",
    }));
    set_items(({
    "instructions#sign#posting",
    "======================Instructions====================\n"+
    "CRAFT - This allows you to make items on the workbench\n"+
    "=======================================================\n"
    }));
}

int is_workshop() { return 1;}