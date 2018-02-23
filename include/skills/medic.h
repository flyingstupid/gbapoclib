#ifndef MEDIC_H
#define MEDIC_H

/* Medics are our verisons of clerics. They won't have many skills, but they will get tons of powers
   within these three powers. Thinking we can easily add some other stuff too. */

int mhealing; //Medic Healing Tree
int enhancing; //Enhancing tree buffs
int preventing; //Helps for going into some areas and other junk


int query_mhealing()     { return mhealing; }
int query_enhancing()   { return enhancing; }
int query_preventing()  { return preventing; }

int set_mhealing(int i)    { return mhealing = i; }
int set_enhancing(int i)  { return enhancing = i;}
int set_preventing(int i) { return preventing = i;}

void clear_medic(){

    mhealing = 0; enhancing = 0; preventing = 0;

}

void query_medic_stats()
{
    string str;

    write("\n         -=[ Medic Skills ]=-\n\n");
    str  = " Mhealing: "+mhealing+"                               ";
    str  = extract(str,0,25);
    str += " Enhancing: "+enhancing+"                                 ";
    str  = extract(str,0,50);
    str += " Preventing: "+ preventing +"                         ";
    str  = extract(str,0,75);
    write(str);
}

#endif
