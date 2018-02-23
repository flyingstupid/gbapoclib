//
//  wiz/kate/open/expandcity.c
//
// base file for city objects
//

#define TP(XXX, YYY) tell_object( XXX, YYY )
#define CAP_NAME(XXX) (capitalize(XXX->query_name()))
#define TR(YYY,XXX) tell_room( environment(YYY), XXX,({YYY}) )
#define CITY_PATH "/wiz/kate/open/"

#include <mudlib.h>

//function prototypes
int is_city_near(); //returns distance to nearest city.  If distance is greater than 3 returns 0
void change_exits();
void copy_city_files();
void build_city();
void build1();
void build2();
void build3();
void do_build();
string query_opposite_exit(string exit);



//variables
string cityName;
object currentLocation;
string cityFile;
string citySide; // on which side of the current location the original city is located
string newDir;
int cityDistance;
int citySize;




status expandcity(){
    
    //------ERROR CHECKING--------
    
    
    //check to see if there is a city nearby
    currentLocation = environment(this_player());
    
    cityDistance = is_city_near();
    
    if (cityDistance >=  2){
        TP(this_player(), "This extension will cause your city walls to be too cloas to another city's borders.\n");
        return 1;
    }
    if (cityDistance == 0 ){
        TP(this_player(), "There is no city near enough to extend.\n");
        return 1;
    }
    
    //check to see that there is a generator in the room
    if (!present ("generator", environment(this_player()))) {
        TP(this_player(), "You have no way to illuminate more of your city.  Beasts will inhabit the streets and destroy your improvements.\n");
        TR(this_player(), "You have no way to illuminate more of your city.  Beasts will inhabit the streets and destroy your improvements.\n");
        return 1;
    }
    
    //Make sure that the player has petrol
    if (!present ("petrol", this_player())) {
        TP(this_player(), "You have no fuel for the generator.\n");
        TR(this_player(), "You have no fuel for the generator.\n");
        return 1;
    }
    
    //make sure that they are building in a forest
    
    if (currentLocation->query_room_type() != "forest"){
        TP(this_player(), "This location does not appear suitable for development.\n");
        TR(this_player(), "This location does not appear suitable for development.\n");
        return 1;
    }
    
    //TP(this_player(), "CITY EXPANSION FUNTCION COMING SOON.\n");
    //TR(this_player(), "CITY EXPANSION FUNTCION COMING SOON.\n");
    
    
    do_build();
    
    
    return 1;
    
}

int is_city_near(){
    string *tier1 = ({});
    string *tier2 = ({});
    string *tier3 = ({});
    int distance = 0;
    string *temp;
    string *temp2;
    string *temp3;
    string tempCityName;
    string debugstring;
    string debugstring1;
    
    
    TP(this_player(), "Determining if there is already a city nearby\n\n");
    tier1 = currentLocation->query_all_exits();
    
    for (int i=0; i< sizeof(tier1); i += 2) {
        tier2 += tier1[i]->query_all_exits();
        if (tier1[i]->query_room_type() == "city"){
            distance = 1;
            cityName = tier1[i] -> query_city_name();
            citySide = tier1[i+1];
            //cityFile = CITY_PATH + cityName + "/" + cityName + ".c";
            citySize = tier1[i]->query_city_size();
            TP(this_player(), "Found city file : " + tier1[i]->query_city_name() + " size " + citySize + " to the " + citySide +".\n\n");
        }
    }
    
    for (int j=0; j < sizeof(tier2); j += 2) {
        tier3 += tier2[j]->query_all_exits();
        if (tier2[j]->query_room_type() == "city"){
            if (distance == 1){
                tempCityName = tier2[j] -> query_city_name();
                if (tempCityName != cityName){
                    TP(this_player(), "city file " + tempCityName + " is 2 blocks away.\n");
                    distance = 2;
                }
            }
        }
    }
    
    for (int k=0; k < sizeof(tier3); k += 2) {
        if (tier3[k]->query_room_type() == "city"){
            if (distance == 1){
                tempCityName = tier3[k] -> query_city_name();
                if (tempCityName != cityName){
                    TP(this_player(), "city file " + tempCityName + " is 3 blocks away.\n");
                    distance = 3;                }
            }
        }
    }
    TP(this_player(), "the distance to the next city is " + distance + ".\n");
    return distance;
    
}

/*void build1(){
 TP(this_player(), "You carefully pour petrol into the generator, careful not to spill any into the dirt\n\n");
 TR(this_player(), CAP_NAME(this_player()) + " carefully pours petrol into the generator, careful not to spill any into the dirt\n\n");
 return;
 }
 
 void build2(){
 TP(this_player(), "You look at your companions and, with crossed fingers, switch the generator to the on position.\n\n");
 TR(this_player(), CAP_NAME(this_player()) + " looks at all of you and crosses their fingers before turning the generator to the on position.\n\n");
 return;
 }
 
 void build3(){
 TP(this_player(), "After a moment or two the lights flicker to life illuminating a small patch of land.  You realize that this, at one time must have been a primitive town. There are a few crumbling roads and three buildings that look safe enough to be used for a simple town hall, a workshop and a small storage facility");
 TR(this_player(), "After a moment or two the lights flicker to life illuminating a small patch of land.  You realize that this, at one time must have been a primitive town. There are a few crumbling roads and three buildings that look safe enough to be used for a simple town hall, a workshop and a small storage facility");
 return;
 }*/

void do_build(){
    
    copy_city_files();
    change_exits();
    
    
    /*object *inv = all_inventory( environment( this_player() ));
     for(int i = 0; i<sizeof(inv); i++) {
     if (living (inv[i])){
     move_object(inv[i], CITY_PATH + cityName + "/" + cityName + "_0/blankcity_4.c");
     }
     }
     
     
     move_object(this_player(), CITY_PATH + cityName + "/" + cityName + "_0/blankcity_4.c");*/
    
    
    return;
    
}


void copy_city_files(){
    newDir = CITY_PATH + cityName + "/" + cityName + "_" + (citySize + 1);
    mkdir(newDir);
    TP(this_player(), "Making new directory called " + newDir + ".\n\n");
    copy_file( "/wiz/kate/open/blankcity/autogenroom.h",newDir + "/autogenroom.h" );
    for (int i = 0; i < 9; i++){
        copy_file( "/wiz/kate/open/blankcity/blankcity_" + i + ".c", newDir + "/blankcity_" + i + ".c" );
    }
    
}


void change_exits(){
    //Mapping -----Exits({from, to, direction})
    string originalPath = CITY_PATH + cityName + "/" + cityName + "_" + citySize + "/";
    string expandPath = CITY_PATH + cityName + "/" + cityName + "_" + (citySize + 1) + "/";
    string entry = environment (this_player() )->query_exit_filename(citySide);
    string *northSide = ({ expandPath + "blankcity_0.c", expandPath + "blankcity_1.c", expandPath + "blankcity_2.c"});
    string *eastSide = ({ expandPath + "blankcity_2.c", expandPath + "blankcity_5.c", expandPath + "blankcity_8.c"});
    string *southSide = ({ expandPath + "blankcity_6.c", expandPath + "blankcity_7.c", expandPath + "blankcity_8.c"});
    string *westSide = ({ expandPath + "blankcity_0.c", expandPath + "blankcity_3.c", expandPath + "blankcity_6.c"});
    string *originalRooms = ({entry});
    mapping perpExits = ([
                          "north"   :   ({"east", "west",}),
                          "east"    :   ({"north", "south"}),
                          "south"   :   ({"east", "west"}),
                          "west"    :   ({"north", "south"}),
                          ]);
    
    
    if ((entry->query_exit_filename(perpExits[citySide][0]))->query_room_type() == "city"){
        originalRooms += entry->query_exit_filename(perpExits[citySide][0]);
    }
    if ((entry->query_exit_filename(perpExits[citySide][1]))->query_room_type() == "city"){
        originalRooms += ({entry->query_exit_filename(perpExits[citySide][1])});
    }
    
    TP(this_player(), "original rooms are: " + (implode( originalRooms , ", " ) + "\n"));
       
       /*
        
        string oldExit;
        string newExit;
        
        
        
        if (citySide == "south"){
        TP(this_player(), "CHANGING CITY EXITS. " + originalPath + "blankcity_1.c\n");
        oldExit = originalPath + "blankcity_1.c";
        oldExit->remove_exit("north");
        for (int i = 0; i<7; i++){
        
        southExits[i][0]->add_exit(southExits[i][1], southExits[i][2]);
        southExits[i][1]->add_exit(southExits[i][0], query_opposite_exit(southExits[i][2]));
        
        }
        
        oldExit = currentLocation->query_exit_filename("east");
        if (oldExit){
        oldExit -> remove_exit("west");
        }
        
        
        oldExit = currentLocation->query_exit_filename("west");
        if (oldExit){
        oldExit -> remove_exit("east");
        }
        
        
        oldExit = currentLocation->query_exit_filename("north");
        if (oldExit){
        oldExit -> remove_exit("south");
        
        }
        
        }*/

}


/*
 
 
 
 string oldExit;
 string newExit;
 
 oldExit = currentLocation->query_exit_filename("east");
 oldExit -> remove_exit("west");
 newExit = CITY_PATH + cityName + "/" + cityName + "_0/blankcity_5.c";
 oldExit->add_exit(newExit, "west");
 newExit->remove_exit("east");
 newExit->add_exit(oldExit, "east");
 
 oldExit = currentLocation->query_exit_filename("west");
 oldExit -> remove_exit("east");
 newExit = CITY_PATH + cityName + "/" + cityName + "_0/blankcity_3.c";
 oldExit->add_exit(newExit, "east");
 newExit->remove_exit("west");
 newExit->add_exit(oldExit, "west");
 
 oldExit = currentLocation->query_exit_filename("south");
 oldExit -> remove_exit("north");
 newExit = CITY_PATH + cityName + "/" + cityName + "_0/blankcity_7.c";
 oldExit->add_exit(newExit, "north");
 newExit->remove_exit("south");
 newExit->add_exit(oldExit, "south");
 
 oldExit = currentLocation->query_exit_filename("north");
 oldExit -> remove_exit("south");
 newExit = CITY_PATH + cityName + "/" + cityName + "_0/blankcity_1.c";
 oldExit->add_exit(newExit, "south");
 newExit->remove_exit("north");
 newExit->add_exit(oldExit, "north");
 return;
 }*/


string query_opposite_exit(string exit){
    mapping oppExits=([
                       "north" : "south",
                       "northeast" : "southwest",
                       "east" : "west",
                       "southeast" : "northwest",
                       "south" : "north",
                       "southwest" : "northeast",
                       "west" : "east",
                       "northwest" : "southeast"
                       ]);
    return oppExits[exit];
}
