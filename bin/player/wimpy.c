#include <mudlib.h>

#define TP this_player()

status wimpy(string str) {   
  int i, whimpy, max_hp, wisdom;
  string tmp;

  if(TP->query_no_wimpy()) {  
    write("You cannot use wimpy mode.\n");  
    return 1;  
  }  
  if(!str || str == "0") {  
    write("You begin to feel a little more brave.\n");  
    TP->set_wimpy(0);  
    return 1;  
  }
  if(str == "direction") {
    write("You decide to flee in any direction when running from battle.\n");
    TP->set_custom(0);
    return 1;
  }  
  if(!sscanf(str,"%d",i)) {
    if(sscanf(str,"direction %s",tmp)) {
      write("You will try to run "+tmp+" when fleeing from battle.\n");
      TP->set_custom(tmp);
      return 1;
    }
    write("Usage: wimpy <hit points>\n"+
          "       wimpy direction <direction>\n");
   return 1;
 }
 if (i < 0) {  
   write("Now don't be silly.\n");  
   return 1;  
 }  
 max_hp = TP->query_max_hp();
 whimpy = i;
  if(TP->query_level() < 6) {  
    if(whimpy > max_hp/2) whimpy = max_hp/2;  
  }  
  else {
   wisdom = TP->query_wisdom();
   if(whimpy > wisdom * 5) whimpy = wisdom * 5;
  }  
  tell_object(this_player(),"Whimpy is set to "+whimpy+" hit points.\n");
  TP->set_wimpy(whimpy);
  return 1;
}
