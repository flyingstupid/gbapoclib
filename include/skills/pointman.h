#ifndef POINTMAN_H
#define POINTMAN_H

/* Pointmen are our verison of fighters. They have a lot of the same abilities as fighters
with the three different power group skills to show how they get class 'powers' which on
this lib will be defined as 'spells'. Anything that isn't instant, is considered a spell
in this lib! So realise they will always be calling the load spell dealy.*/

int fighting;         /* First Power Group */
int protecting;       /* Second Power Group */
int preparing;        /* Third Power Group*/


/******************************************************************/
/* sets */

int set_fighting(int i)       { return fighting = i ;}
int set_protecting(int i)     { return protecting = i; }
int set_preparing(int i)      { return preparing = i;}

/******************************************************************/
/* query */
 
int query_fighting()       { return fighting;   }
int query_protecting()      { return protecting;    }
int query_preparing()       { return preparing; }


void clear_pointman() {
  fighting = 0; protecting = 0; preparing = 0;
  this_object()->clear_fighter();
} 

void query_pointman_stats() {
  string str;

  write("\n         -=[ Pointman Skills ]=-\n\n");
  str = " Unarmed: "+query_unarmed()+"                 ";
  str = extract(str,0,12);
  str += " Two Weapon: "+query_two_weapon()+"          ";
  str = extract(str,0,29);
  str += " Multi Attack: "+query_multi_attack()+"         ";
  str = extract(str, 0, 50);
  str += " Multi Opponent: "+query_multi_opponent()+"             ";
  str = extract(str, 0, 79);
  write(str +"\n");
  str  = " Fighting: "+fighting+"                               ";
  str  = extract(str,0,25);
  str += " Protecting: "+protecting+"                                 ";
  str  = extract(str,0,50);
  str += " Preparing: "+ preparing +"                         ";
  str  = extract(str,0,75);

  write(str +"\n");

}

#endif /* POINTMAN_H */
