/* Bank     */
/* Darkness */

#include <mudlib.h>
inherit BANK;
 
void reset(status arg) {
    set_owner("gnak");

  reset_doors(arg);
  load_door(({
    "destination",      "d/coronos/w/darkness/b/hall/hall6",
    "direction",        "north door",
    "long",             "The heavy door is made of sturdy oak.  Iron bracers also\n"+
                        "reinforce the door\n",
    "door id",          "north door",
  }));

    ::reset(arg);
    if(arg) return;
    set_short("the Ille Coronos city bank");
    set_long(
      "\t==Ille Coronos Bank==\n"+
      "The granite walls of the bank make certain that its valuable stores\n"+
      "are kept safe.  A red velvet rug matches the velvet curtains that\n"+
      "hang along the wood-framed windows.  A counter seperates the customer\n"+
      "area from the metal vault in the back of the room.\n");

    set_items(({
      "counter",
        "The counter has a wooden base and a marble counter top.\n",
      "customer area#area",
        "You're in the customer area.  Passage behind the counter is not allowed.\n",
      "vault",
        "The thick metal vault is very safe and secure.\n",
      "wall#walls"
        "The walls are made from think granite blocks.\n",
      "stores",
        "The money kept in the vault is not visible from here.\n",
      "rug",
        "The rug is thin but very soft.  It matches the curtains in the room.\n",
      "curtain#curtains",
        "The curtains are made of red velvet.  They match the rug in the room.\n",
      "window",
        "The medium sized windows are barred on the inside.\n",
      "frame#wood-frames#wood-frame",
        "The wood frame is simply made from sturdy oak.\n",
      "bar#bars",
        "The storing metal bars are there for protection.\n",
      }));
 
    set_weather(2, 1, 0);
    set_smell("The scent of coins lingers here.\n");
    set_listen("Footsteps can be heard in the hallway just outside the bank.\n");
}
 
int query_no_fight() { return 1; }
int query_prop(string str) {
    if(str == "Nulmagic") return 1;
    else return query_prop(str);
}
