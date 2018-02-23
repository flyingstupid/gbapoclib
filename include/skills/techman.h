#ifndef TECHMAN_H
#define TECHMAN_H

/* Techman are our glass cannon / Mage types. They will be big time damage
dealers but will have crap for hit points. In general they will need help to
go out. They will devastate things lower level than them and help a great deal
with stuff equal and higher level than themselves.*/


#define HEAL_TECHMAN_PERIOD (20 - query_intelligence()/3)



int sensing;    //Detecting type stuffs 
int destroying; //Blasting type spells
int creating;   //Creating magic/tech works
int nanites;    //The amount of nanites the techie has
int maxnanites; //The Max amount of nanites a techie can have



//Finding skills
int query_sensing()    { return sensing;}
int query_destroying() { return destroying;}
int query_creating()   { return creating;}

//Nanite Stuff
int query_nanites() { return nanites; }

int query_maxnanites()
{
 int skilltotal;

 skilltotal = query_sensing() + query_destroying() + query_creating();

 return (skilltotal*10);


}


//Then setting those skills
int set_sensing(int i)    { return sensing = i;  }
int set_destroying(int i) { return destroying = i; }
int set_creating(int i)   { return creating = i; }

int set_nanites(int i) { return nanites = i; }


int adj_nanites_techman(int i)
{
    if(nanites < query_maxnanites())
    {
        nanites = nanites + i;
    }    
}



// Blowing out skills if you change classes
void clear_techman(){

sensing = 0; destroying = 0; creating = 0;

}

void query_techman_stats()
{
    string str;
    
    write("\n         -=[ Techman Skills ]=-\n\n");
    str  = " Sensing: "+sensing+"                               ";
    str  = extract(str,0,25);
    str += " Destroying: "+destroying+"                                 ";
    str  = extract(str,0,50);
    str += " Creating: "+ creating +"                         ";
    str  = extract(str,0,75);
    write(str);
}

void heal_techman(int arg) {
  if(random(HEAL_TECHMAN_PERIOD)) return;
  if(arg == 0) arg = 1;
  adj_nanites_techman(arg);
}

#endif