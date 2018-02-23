#ifndef SCOUT_H
#define SCOUT_H

/* Scouts are our verison of thieves. They will sneak, pick locks, etc. In general they need to be able
to solo a lot of stuff through stealth, but not be able to get away with -everything- Most of this skills
will be directly stolen from the thieves of our lib. So lets see what happens ;) -Critical*/

// These are Scout's three skills to get 'powers' from
int exploring;
int surviving;
int evading;



/* Our Skills */
int query_exploring() { return exploring; }
int query_surviving() { return surviving; }
int query_evading()   { return evading; }


/*Their skills
int query_stealth()    { return stealth;    } 
int query_locks()      { return locks;      } 
int query_backstab()   { return backstab;   } 
int query_traps()      { return traps;      } 

int query_stealth_on() { return stealth_on; } 
*/



/* This sets the skill levels */
int set_exploring(int i) { return exploring = i;  }
int set_surviving(int i) { return surviving = i;  }
int set_evading( int i ) { return evading = i;    }

/*
int set_stealth(int i)    { return stealth = i;    } 
int set_locks(int i)      { return locks = i;      }
int set_backstab(int i)   { return backstab = i;   } 
int set_traps(int i)      { return traps = i;      } 

int set_stealth_on(int i) { return stealth_on = (i) ? 1 : 0; }

*/






void clear_scout(){

exploring = 0; surviving = 0; evading = 0;
this_object()->clear_thief();
}

void query_scout_stats()
{
string str;

write("\n         -=[ Scout Skills ]=-\n\n");
  str  = " Exploring: "+exploring+"                               ";
  str  = extract(str,0,25);
  str += " Surviving: "+surviving+"                                 ";
  str  = extract(str,0,50);
  str += " Evading: "+ evading +"                         ";
  str  = extract(str,0,75);
write(str);
  str  = " Stealth: "+query_stealth()+"                               ";
  str  = extract(str,0,25);
  str += " Locks: "+query_locks()+"                                 ";
  str  = extract(str,0,50);
  str += " Backstab: "+ query_backstab() +"                         ";
  str  = extract(str,0,75);
//Thief Skills for our Scouts
write(str);
str = " Traps:" +query_traps()+ "\n";
write(str); 

}


#endif /* End Scout */