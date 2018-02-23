/* General Skills ***
 * New General skills Healing, Riding Land/Riding Airborne added Oct 98. Angel.
 */

#ifndef GENERAL_H
#define GENERAL_H

/*** general ***/

//Our skills for the game!
int mining;









int climb;            /* climb walls */
int swim;
int animal_handling;
int healing;
int riding_landbased;
int riding_airborne;


/*** general ***/

//Our skills
int set_mining(int i)          { return mining = i;           }


int set_climb(int i)           { return climb = i;            }
int set_swim(int i)            { return swim = i;             }
int set_animal_handling(int i) { return animal_handling = i;  }
int set_healing(int i)         { return healing = i;          }
int set_riding_landbased(int i){ return riding_landbased = i; }
int set_riding_airborne(int i) { return riding_airborne = i;  }

//Our skills
int query_mining()                { return mining; }


int query_climb()              { return climb;            }
int query_swim()               { return swim;             }
int query_animal_handling()    { return animal_handling;  }
int query_healing()            { return healing;          }
int query_riding_landbased()   { return riding_landbased; }
int query_riding_airborne()    { return riding_airborne;  }


void query_general_stats() {
  string str;

  write("\n              -=[ General Skills ]=-\n\n");
  str  = " Climb: "+climb+"                               ";
  str  = extract(str,0,25);
  str += " Swim: "+swim+"                                 ";
  str  = extract(str,0,50);
  str += " Healing: "+ healing +"                         ";
  str  = extract(str,0,75);
  write(str +"\n");

  str  = " Animal Handling: "+animal_handling+"            ";
  str  = extract(str,0,25);
  str += " Riding Landbased: "+ riding_landbased +"        ";
  str  = extract(str,0,50);
  str += " Riding Airborne: "+ riding_airborne +"          ";
  str  = extract(str,0,75);
  write(str +"\n");

  str = " Mining: " + mining;
  write(str +"\n");
}


#endif /* GENERAL_H */ 

