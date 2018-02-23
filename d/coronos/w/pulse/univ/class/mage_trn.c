#include <mudlib.h>
inherit GUILD;
 
void reset(status arg) {
  if (arg) {
    return;
  } 
 
  set_exp(({
      0,       1014,    1522,    2283,    3425,    5138,
      7707,    11561,   17341,   26012,   39018,   58527,
      87791,   131687,  197530,  296296,  444444,  666666,
      1000000, 1500000, 2000000, 2500000, 3000000, 3500000,
      4000000, 4500000, 5000000, 5500000, 6000000, 6500000,
  }));
 
  set_skill_exp(({
      30,      50,     75,      100,     175,     250,
      400,     600,    900,     1200,    2000,    3000,
      4500,    6500,   10000,   15000,   20000,   30000,
      50000,   75000,  100000,  125000,  150000,  175000,
      200000,  225000, 250000,  275000,  300000,  325000,
  }));
 
  set_titles(({ 
      ({}), /* no neuter characters now but possible */
 
 
      /* male titles */ 
      ({
        "the Utter Newbie",
        "the Apprentice",
        "the Initiate",
        "the Student of Magic",
        "the Apprentice of Magic",
        "the Apprentice Magician",
        "the Magician",
        "the Apprentice Sorcerer",
        "the Sorcerer",
        "the Wizard",
        "the Wizard of the 1st Circle",
        "the Wizard of the 2nd Circle",          
        "the Wizard of the 3rd Circle",          
        "the Wizard of the 4th Circle",          
        "the Wizard of the 5th Circle",          
        "the Wizard of the 6th Circle",          
        "the Wizard of the 7th Circle",         
        "the Wizard of the 8th Circle",     
        "the Wizard of the 9th Circle",      
        "the Mage",
        "the High Mage",
        "the High Mage of the 1st Circle",
        "the High Mage of the 2nd Circle",    
        "the High Mage of the 3rd Circle",    
        "the High Mage of the 4th Circle",  
        "the High Mage of the 5th Circle",
        "the High Mage of the 6th Circle",  
        "the High Mage of the 7th Circle",   
        "the High Mage of the 8th Circle",  
        "the High Mage of the 9th Circle",   
      }),
 
      /* female titles */
      ({
        "the Utter Newbie",
        "the Apprentice",
        "the Initiate",
        "the Student of Magic",
        "the Apprentice of Magic",
        "the Apprentice Magician",
        "the Magician",
        "the Apprentice Sorcerer",
        "the Sorcerer",
        "the Wizard",
        "the Wizard of the 1st Circle",
        "the Wizard of the 2nd Circle",          
        "the Wizard of the 3rd Circle",          
        "the Wizard of the 4th Circle",          
        "the Wizard of the 5th Circle",          
        "the Wizard of the 6th Circle",          
        "the Wizard of the 7th Circle",         
        "the Wizard of the 8th Circle",     
        "the Wizard of the 9th Circle",      
        "the Mage",
        "the High Mage",
        "the High Mage of the 1st Circle",
        "the High Mage of the 2nd Circle",    
        "the High Mage of the 3rd Circle",    
        "the High Mage of the 4th Circle",  
        "the High Mage of the 5th Circle",
        "the High Mage of the 6th Circle",  
        "the High Mage of the 7th Circle",   
        "the High Mage of the 8th Circle",  
        "the High Mage of the 9th Circle",   
      }),
  }));
  /*** get a new pretitle one in four levels after 30 ***/
  set_pretitles(({
      ({}), /* no neuter pretitles */
 
      /* male pretitles */
      ({
        "Magus",
        "Magus",
        "Magus",
        "High Magus",
        "High Magus",
        "High Magus",
        "Archmage",
        "Archmage",
        "Archmage",
      }), 
 
      /* female pretitles */
      ({
        "Magus",
        "Magus",
        "Magus",
        "High Magus",
        "High Magus",
        "High Magus",
        "Archmage",
        "Archmage",
        "Archmage",
      }),
  })) ;
 
  set_guild_name("No");
 
  ::reset();
}
