#include <mudlib.h>
#include <ansi.h>

inherit PUB;

void reset(status arg) {
    
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("Second Chance's Inn");
    set_long(
      "Second Chance's Inn\n"+
      "Within this all wood created inn are 10 very large wooden pinic tables.\n"+
      "Some are from before the fall out and others are freshly made by the skilled\n"+
      "craftsmen of the town. A large wooden bar fills the entirity of one side of the\n"+
      "building and has rows of old and repurposed bottles. There's a soft hum of electric\n"+
      "lights within the area and coming from the back where an electric cooler is.\n"+
      "Posted above the bar is a menu for citizens to cash their credits in for food.\n"
      );
  set_owner("Micky");

  add_sdrink("water", "bottle of filtered water", "That was crips and clean", 10);
  add_sdrink("cola", "can of cola", "Flat and sugary, but man it hits the spot", 20);
  add_sdrink("juice", "can of juice", "Vitamins, how your body longed for that", 50);
  add_drink("moonshine",  "bottle of moonshine",  "That was brutal, but it ", 30);
  add_food("soup", "bowl of mushroom soup", "It is a little watery", 10);
  add_food("chicken", "leg of roasted chicken", "Not bad, you'll have to thank Mikey next time", 20);
  add_food("steak", "flank steak", "A little dry, but it is actual MEAT!", 50);

    
    set_exits(({
    "d/wastelands/w/critical/secondtry/city4","out",
    }));
    set_items(({
    "menu", "====================Menu=================\n"+
            "Food                                     \n"+
            "Mushroom soup                  10 credits\n"+
            "Roasted chicken                20 credits\n"+ 
            "Flank steak                    50 credits\n"+
            "=========================================\n"+
            "Drinks                                   \n"+
            "Filtered Water                 10 credits\n"+
            "Cola                           20 credits\n"+
            "Moon shine                     30 credits\n"+
            "Juice                          50 credits\n"+
            "=========================================\n"
    }));
}
