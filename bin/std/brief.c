#include <mudlib.h>

#define TP this_player()

status brief(status silently){  
  int brief;
  brief = TP->query_brief();
  if((brief = !brief)) {
    if(!silently)
      tell_object(TP,
        "Brief mode. BEWARNED that there are many features\n"+
        " and room warnings that you will miss in this mode.\n");
    }
    else {
      if(!silently) tell_object(TP,"Verbose mode.\n");  
    }
  TP->set_brief(brief);
  return 1;
}  
