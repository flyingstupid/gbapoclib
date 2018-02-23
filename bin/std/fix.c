#include <mudlib.h>

#define TP this_player()

status fix(string str) {
    string reason;

    if(!str || !sscanf(str,"%s %s",str,reason)) {
     write("Usage: fix <skills|carry|armour|weapon|heart> <reason>\n\n"+
       "       Give reason so bugs can be traced.\n");
     return 1;
    }  
    if(str=="carry" || str=="weight") {  
     write("Fixing your carry problems.....\n");  
     TP->recalc_carry();  
     write("Your carry has been fixed.....\n");  
#ifdef LOG_FIX
     log(LOG_FIX,"Carry: "+reason,0);
#endif /* LOG_FIX */
    }  
    else if(str=="armor" || str=="armour" || str=="ac") {  
     write("Fixing your armor class........\n");  
     TP->recalc_ac();  
     write("Your armor class has been fixed.....\n");  
#ifdef LOG_FIX
     log(LOG_FIX,"Armour: "+reason,0);
#endif /* LOG_FIX */
    }  
    else if(str == "skills" || str == "sk") {
      write("Fixing your skills paths.........\n");
      TP->recalc_sk(); /* found in bincmd.c */
#ifdef LOG_SK
      log(LOG_FIX, "Skills: "+reason,0);
#endif /* LOG_SK */
    }
    else if(str=="wc" || str=="weapon") {  
     write("Fixing your weapon class.....\n");  
     TP->recalc_wc();  
     write("Your weapon class has been fixed.....\n");  
#ifdef LOG_FIX
     log(LOG_FIX,"Weapon: "+reason,0);
#endif /* LOG_FIX */
    }  
    else if(str=="h" || str=="heart" || str=="heartbeat") {  
     TP->cpr();
#ifdef LOG_FIX
     log(LOG_FIX,"Heartbeat: "+reason,0);
#endif /* LOG_FIX */
    }  
    else {
     write("This is your character fixing function.\n");  
     write("You may fix the following:\n");  
     write("Armour, Weapon, Skills, Carry, Heart.\n");  
     write("\nIf you are having other problems contact a creator.\n");  
    }
    return 1;  
}  
