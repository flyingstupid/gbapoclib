// wiz/kate/open/medic/medkit.c

/*Medic's Field kit This is their 'guild' item and it autoloads.
It keeps track of all of their medicines for their guild powers.


 */

#include <mudlib.h>

#define PATH "/wiz/kate/open/medic/"

inherit "inherit/treasure";

//med kit components
int syringe = 0;        //general injections
int bandages = 0;       //general healing
int enzymes = 0;        //for serum customization
int serum = 0;          //for injecting
int antibiotics = 0;   //for curing/treating diesase
int levelMax = this_player()->query_level()*10;

/*int healingserum=0;  // For all instant healing powers
int strengthserum=0; // For extra carrying capacity
int combatserum=0;   // For over all bad assness
int antibotics=0;    // For remove disease
int epinephrine=0;   // For Rezz*/


// Still need something that heals blindness and deafness.

int query_syringe;
int query_bandages;       
int query_enzymes;        
int query_serum;          
int query_antibiotics;
string writelong();

// Setting absolute value
int set_syringe;
int set_bandages;
int set_enzymes;
int set_serum;
int set_antibiotics;

// Adding to the value!
int add_syringe(int i);
int add_bandage(int i);
int add_enzymes(int i);
int add_serum(int i);
int add_antibiotics(int i);


// Checks if the medkit is full or not
int check_full();

// Tells how much is currently IN the medkit
int check_filled();

// Alerts the Medic that someone is down.
int distress_call();

//create medkit items from medical components
int fill_kit(string item);

//Array of powers
mapping powers = ([
                   1    :   ({"medpatch.c"}),
                   2    :   ({"immuneboost.c"}),
                   3    :   ({"enhancefood.c"}),
                   4    :   ({"limber.c"}),
                   5    :   ({"tighten.c"}),
                   6    :   ({"suture.c"}),
                   7    :   ({"frenzy.c"}),
                   8    :   ({"demoralize.c"}),
                   9    :   ({"steroid.c"}),
                   10   :   ({"exsanguinate.c"}),
                   11   :   ({"brewserum.c"}),
                   12   :   ({"diagnose.c"}),
                   13   :   ({"treatdisease.c"}),
                   14   :   ({"engineerdisease.c"}),
                   15   :   ({"treatpoison.c"}),
                   16   :   ({"engineerpoison.c"}),
                   17   :   ({"curedisease.c"}),
                   18   :   ({"makecocktain.c"}),
                   19   :   ({"spurmules.c"}),
                   20   :   ({"chitin.c"}),
                   ]);



reset(arg)
{
    if (arg)
    {
        return (0);
    }
    set_name("medic_kit"); //This is so we can target it for guild skills!
    set_short("Field Medic's kit");
    set_alias("kit");
    set_long(writelong());
    set_weight(0);
    
}

void init(){
    
    ::init();
    
    int level = this_player()->query_level();
    for (int i = 1; i <= level; i++) {
        for (int j = 0; j<sizeof( powers[i] ); j++) {
            {environment(this_object())->add_path( PATH + powers[i][j] );
            }
        }
        
        
        
        add_action("fill_kit", "fillkit");
    }
}


// Checking the varible

int query_syringe()
{
    return syringe;
}

int query_bandages()
{
    return bandages;
}

int query_enzymes()
{
    return enzymes;
}

int query_serum()
{
    return serum;
}

int query_antibiotics()
{
    return antibiotics;
}

// Setting the varibles
int set_syringe(int i)
{
    if(check_full())
    {
        return syringe = i;
    }
    else
    {
        write("Your medkit is full!\n");  
        return 1;  
    }
}


int set_bandages(int i)
{
    if(check_full())
    {
        return bandages = i;
    }
    else
    {
        write("Your medkit is full!\n");
        return 1;          
    }
}

int set_enzymes(int i)
{
    if(check_full())
    {
        return enzymes = i;
    }
    else
    {
        write("Your medkit is full!\n");
        return 1;
    }
}

int set_serum(int i)
{
    if(check_full())
    {
        return serum = i;
    }
    else
    {
        write("Your medkit is full!\n");
        return 1;          
    }
}
int set_antibiotics(int i)
{
    if(check_full())
    {
        return antibiotics = i;
    }
    else
    {
        write("Your medkit is full!\n");
        return 1;
    }
}


int add_syringe(int i)
{
    if(check_filled() + i > levelMax)
    {
        write("Your medkit is now full!\n");
        syringe = syringe + levelMax - check_filled();
        return 1;
    }
    else
    {
        syringe = syringe + i;
        return 1;  
    }
}
int add_bandage(int i)
{
    if(check_filled() + i > levelMax)
    {
        write("Your medkit is now full!\n");
        bandages = bandages + levelMax - check_filled();
        return 1;
    }
    else
    {
        bandages = bandages + i;
        return 1;
    }
}

int add_enzymes(int i)
{
    if(check_filled() + i > levelMax)
    {
        write("Your medkit is now full!\n");
        enzymes = enzymes + levelMax - check_filled();
        return 1;
    }
    else
    {
        enzymes = enzymes + i;
        return 1;
    }
}

int add_serum(int i)
{
    if(check_filled() + i > levelMax)
    {
        write("Your medkit is now full!\n");
        enzymes = serum + levelMax - check_filled();
        return 1;
    }
    else
    {
        serum = serum + i;
        return 1;
    }
}

int add_antibiotics(int i)
{
    if(check_filled() + i > levelMax)
    {
        write("Your medkit is now full!\n");
        antibiotics = antibiotics + levelMax - check_filled();
        return 1;
    }
    else
    {
        antibiotics = antibiotics + i;
        return 1;
    }
}



status look_at()
{
    string str;
    object TP=this_player();
    
    
    str =  "==============Med Kit==============\n";
    str += "       Total Space:" + check_filled()  + "/" + (TP->query_level()*10) +"\n";
    str += "\n";
    str += "Syringes:       " +query_syringe()+"\n";
    str += "Bandages:       " +query_bandages()+"\n";
    str += "Enzymes:        " +query_enzymes()+"\n";
    str += "Serum base:     " +query_serum()+"\n";
    str += "Antibiotics:    " +query_antibiotics()+"\n";
  //  str += ""
  //  str += ""
    str += "===================================\n";

    tell_object( this_player(), str );

    return 1;
}
    
    
string writelong()
{
    string str;
    str =  "==============Med Kit==============\n";
    str += "Syringes:       " +query_syringe()+"\n";
    str += "Bandages:       " +query_bandages()+"\n";
    str += "Enzymes:        " +query_enzymes()+"\n";
    str += "Serum base:     " +query_serum()+"\n";
    str += "Antibiotics:    " +query_antibiotics()+"\n";
  //  str += ""
  //  str += ""
    str += "===================================\n";
}



/*
 int check_full()
{
    int total;
    int levelmax;
    
    levelmax=this_player()->query_level()*10;
    total=check_filled();
        
    if(levelmax>total) { return 1; }
    
}
 */

int check_filled()
{
    return query_syringe()+query_bandages()+query_enzymes()+query_serum()+query_antibiotics();
}   

int distress_call()
{
    //This will be called for folks who get distress calls from dead players
    return 1;
}

int fill_kit(string item){
    if (!item){
        tell_object(this_player(), "fillkit <item>");
    }

    object *inv = all_inventory( this_player() );
    object resource;
    for (int i = 0; i<sizeof(inv); i++) {
        if (is_a ("wiz/kate/open/medic/medresource.c", inv[i])){
            resource = inv[i];
        }
    }
    
    //tell_object(this_player(), "There are " + check_filled() + " items in your kit with a capacity of " + levelMax + "\n");
    if ( !resource ){
        tell_object(this_player(), "You do not have any resources to convert to medical supplies.\n");
        return 1;
    }
    
    if( check_filled() <= levelMax )
    {
        float number;
        switch (item) {
                case "syringe": case "syringes":
                number = (this_player()->query_level() * random(1)) + 1;
                tell_object(this_player(), "You create " + (int)number + " syringe");
                if ( (int)number > 1 ){
                    tell_object(this_player(), "s");
                }
                tell_object(this_player(), ".\n");
                add_syringe( (int)number );
                break;
                
            case "bandage": case "bandages":
                number = (this_player()->query_level() * random (2)) + 1;
                tell_object(this_player(), "You create " + (int)number + " bandage");
                if ( (int)number > 1 ){
                    tell_object(this_player(), "s");
                }
                tell_object(this_player(), ".\n");
                add_bandage( (int)number );
                break;
                
            case "enzyme": case "enzymes":
                number = (this_player()->query_level() * random (1)/2.0) + 1;
                tell_object(this_player(), "You create " + (int)number + " enzyme");
                if ( (int)number > 1 ){
                    tell_object(this_player(), "s");
                }
                tell_object(this_player(), ".\n");

                add_enzymes( (int)number );
                break;
                
            case "serum": case "serums":
                number = ((this_player()->query_level() * random (1))/2.0) + 1;
                tell_object(this_player(), "You create " + (int)number + " serum");
                if ( (int)number > 1 ){
                    tell_object(this_player(), "s");
                }
                tell_object(this_player(), ".\n");

                add_serum( (int)number );
                break;
                
            case "antibiotic": case "antibiotics":
                number = ((this_player()->query_level() * random (1))/2.0) + 1;
                tell_object(this_player(), "You create " + (int)number + " antibiotic");
                if ( (int)number > 1 ){
                    tell_object(this_player(), "s");
                }
                tell_object(this_player(), ".\n");

                add_antibiotics( (int)number );
                break;
        }
        destruct(resource);
        return 1;
    }
    else{
        tell_object(this_player(), "Your kit is full to capacity");
    }
    
}



status query_auto_load() { return 1; }
status drop(status wiz)  { return 1; }