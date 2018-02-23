int counter;
string race;
string *stat_name;
string *max_stats;

reset_counter() { return counter = 0; }

set_max_stats(string str) { 
  string tmp1, tmp2; 
  if(!str) return 0; 
  race = str; 
 
  if(race == "half elf")  
     max_stats = ({  20, 25, 22, 23, 26, 25, 24  }); 

  else
    if(race == "high elf" || race == "dark elf")
      max_stats = ({  20, 26, 20, 22, 26, 21, 26  });

  else
    if(race == "grey elf" || race == "gray elf")
      max_stats = ({  19, 27, 20, 21, 26, 22, 26  });

  else
    if(race == "wood elf" || race == "wild elf")
      max_stats = ({  20, 20, 26, 23, 26, 19, 26  });

  else 
    if (race == "hill dwarf" || race == "mountain dwarf")
     max_stats = ({ 27, 20, 26, 23, 23, 25, 19  }); 
 
  else  
    if(race == "orc")
     max_stats = ({  24, 20, 28, 24, 23, 25, 18  }); 

  else if(race == "minotaur")
     max_stats = ({ 26, 20, 28, 23, 22, 20, 18 });

  else  
    if(race == "half giant") 
      max_stats = ({  32, 15, 32, 23, 20, 20, 18 }); 
 
  else  
    if(race == "halfling" || race == "kender" || race == "brownie")
     max_stats = ({  18, 25, 20, 20, 26, 25, 22   }); 
 
  else  
    if(race == "gnome"  || race == "pixie"  || race == "nixie" ||
       race == "kobold" || race == "goblin" || race == "sprite" )
     max_stats = ({  20, 25, 20, 20, 26, 27, 23   }); 
 
  else /* default are human stats */
    max_stats = ({ 25, 25, 25, 25, 25, 25, 25 }); 

  stat_name = ({ 
   "strength", "intelligence", "constitution", 
   "combat",  "dexterity",    "wisdom", "charisma" 
  }); 
 
  call_other(this_player(), 
     "set_max_"+ stat_name[counter], max_stats[counter]); 
  if(counter < 6) {
    counter ++;
    set_max_stats(str);
    return 1;
  }
} 


