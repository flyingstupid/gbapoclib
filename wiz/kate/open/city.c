//
//  wiz/kate/open/city.c
//
// base file for city objects
//

#define TP(XXX, YYY) tell_object( XXX, YYY )
#define CITY_PATH ("/wiz/kate/open/")

#include <mudlib.h>

inherit ROOM;


//variables
string *leaders;
string *citizens;
string *buildings;
string cityName;
string cityPath;
int citySize;

//functions
void add_leader( string name );
void remove_leader( string name );
string is_leader( string name );
string query_leaders();

void add_citizen( string name );
void remove_citizen( string name );
string is_citizen(string name);
string query_citizens();

void add_building( string buildingName );
void remove_building( string buildingName );
string has_building (string buildingName );
string query_buildings();
void create_building(string buildingName);
int get_build_site();

void set_city_name (string cName);
string query_city_name();

void set_city_size(int size);
int query_city_size();




void reset(status arg)
{
    if(arg) return;
    set_city_name("Base City");
    set_weather(2, 1, 0);
   
}

void add_leader( string name ){
    leaders += ({name});
}

void remove_leader( string name ){
    leaders -= ({name});
}

int is_leader( string name ){

    if (member( leaders, name ) == -1){
        return 0;
    }
    else {
        return 1;
    }
    
}

string query_leaders(){
    string tempString;
    tempString =" -----Leaders of " + cityName + "------\n" +
    implode ( leaders, "\n") +
    "\n-------------------------------------\n";
    return tempString;
}




void add_citizen( string name ){
    citizens += ({name});
}

void remove_citizen( string name ){
    citizens -= ({name});
}

int is_citizen(string name){
    
    if (member( citizens, name ) == -1){
        return 0;
    }
    else {
        return 1;
    }
    
}

string query_citizens(){
    string tempString;
    tempString =" -----Citizens of " + cityName + "------\n" +
    implode ( citizens, "\n") +
    "\n-------------------------------------\n";
    return tempString;
}




void add_building( string buildingName ){
    buildings += ({buildingName});
    TP(this_player(), "buildign added\n");
    //create_building(buildingName);
}

/*void create_building( string buildingName ){
    int siteNumber = get_build_site();
    TP(this_player(), "Site number: " + siteNumber + "\n");
    object room;
    string exitRoom;
    string fileName;
    cityLayout[siteNumber,0] = buildingName;
    //create the file
    
    string lowerCityName = lower_case(cityName);
    
    fileName = "wiz/kate/open/" + lowerCityName + siteNumber + ".c";
    TP(this_player(), "the new file name is " + fileName + "\n");
    
    /*room = find_object(filename);
     if (cityLayout[sitenumber, 2]){
     exitRoom = "wiz/kate/open/" + cityName + cityLayout[sitenumber, 2] + ".c";
     room->set_exits(exitRoom, north}
     }
     
     
     exitRoom = "wiz/kate/open/" + cityName + cityLayout[sitenumber, 3] + ".c";
     room->set_exits(exitRoom, east}
     exitRoom = "wiz/kate/open/" + cityName + cityLayout[sitenumber, 4] + ".c";
     room->set_exits(exitRoom, south}
     exitRoom = "wiz/kate/open/" + cityName + cityLayout[sitenumber, 5] + ".c";
     room->set_exits(exitRoom, west}
    
}

int get_build_site(){
    int *emptySpots = ({});
    int buildSite;
    
    TP(this_player(), "determining build site\n");
    
    for (int i = 1; i <= maxSize; i++ ){
        //TP(this_player(), "room " + i +" has " + cityLayout[i, 0] + "in it.\n" );
        if (cityLayout[i, 0] == "field"){
            TP(this_player(), "room " + i +" is empty.\n" );
            emptySpots += ({i});
        }
    }
    
    
    int temp = random (sizeof( emptySpots ));
    buildSite = emptySpots[temp];
    return buildSite;
    
}
*/

void remove_building( string buildingName ){
    buildings -= ({buildingName});
    
}
int has_building (string buildingName ){
    if (member( buildings, buildingName ) == -1){
        return 0;
    }
    else {
        return 1;
    }
    
}

string query_buildings(){
    string tempString;
    tempString =" -----Buildings of " + cityName + "------\n" +
    implode ( buildings, "\n") +
    "\n-------------------------------------\n";
    return tempString;
}





void set_city_name (string cName){
    cityName = cName;
    cityPath = CITY_PATH + cName + "/" + cName;
    //TP(this_player(), "the city path is :  " + cityPath + "\n");
}
string query_city_name(){
    return cityName;
}


void set_city_size(int size){
    citySize = size;
}
int query_city_size(){
    return citySize;
}




