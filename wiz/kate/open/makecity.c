//
//  wiz/kate/open/makecity.c
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
string newCityFile;
object currentLocation;




status makecity(string arg){
   
        //------ERROR CHECKING--------
    if (!arg){
        TP(this_player(), "createcity <city name >\n");
        return 1;
    }
    
    //check to see if there is a city nearby
    currentLocation = environment(this_player());
    
    if (is_city_near()){
        TP(this_player(), "There is already a city established nearby.\n");
        return 1;
    }
    
    //check to see that there is a generator in the room
    if (!present ("generator", environment(this_player()))) {
        TP(this_player(), "You have no way to illuminate your city.  As a result Beasts from the forest destroy any improvements you make and kill your citizens.  You are forced to abandon the ill fated project.\n");
        TR(this_player(), "You have no way to illuminate your city.  As a result Beasts from the forest destroy any improvements you make and kill your citizens.  You are forced to abandon the ill fated project.\n");
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
    
    cityName = remove_char_from_string( arg, ({"\'", "\"", " "}));
    cityName = lower_case(cityName);

    //The following lines were temp removed for programer sanity
    //call_out("build1", 5);
    //call_out("build2", 10);
    //call_out("build3", 15);
    //call_out("do_build", 17);
    
    
    call_out("do_build", 3);
    
    
    
    
    
    return 1;
    
}

int is_city_near(){
    string *tier1 = ({});
    string *tier2 = ({});
    string *tier3 = ({});
    int distance = 0;
    
    
    TP(this_player(), "Determining if there is already a city nearby\n\n");
    tier1 = currentLocation->query_all_exits();
    for (int i=0; i< sizeof(tier1); i += 2) {
        tier2 += tier1[i]->query_all_exits();
        if (tier1[i]->query_room_type() == "city"){
            distance = 1;
        }
    }
    
    for (int j=0; j < sizeof(tier2); j += 2) {
        tier3 += tier2[j]->query_all_exits();
        if (tier2[j]->query_room_type() == "city"){
            distance = 2;
        }
    }
    
    for (int k=0; k < sizeof(tier3); k += 2) {
        if (tier3[k]->query_room_type() == "city"){
            distance = 3;
        }
    }
    return distance;
    
}

void build1(){
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
}

void do_build(){
    
    copy_city_files();
    build_city();
    change_exits();
    destruct (present ("generator", environment(this_player())));
    //---needs to be updated to move ALL players to the town center---
    object *inv = all_inventory( environment( this_player() ));
    for(int i = 0; i<sizeof(inv); i++) {
        if (living (inv[i])){
            move_object(inv[i], CITY_PATH + cityName + "/" + cityName + "_0/blankcity_4.c");
        }
    }

    int citySize = newCityFile->query_city_size();
    return;
    
}


void copy_city_files(){
    mkdir(CITY_PATH + cityName);
    newCityFile = CITY_PATH + cityName + "/" + cityName + ".c";
    copy_file( "wiz/kate/open/base_city/base_city.c", newCityFile );
    newCityFile->set_city_name(cityName);
    TP(this_player(), "Preparing to build " + newCityFile->query_city_name() + "\n\n");
    
    mkdir(CITY_PATH + cityName + "/" + cityName + "_0");
    copy_file( "/wiz/kate/open/blankcity/autogenroom.h", CITY_PATH + cityName + "/" + cityName + "_0/autogenroom.h" );
	write_file( CITY_PATH + cityName + "/" + cityName + "_0/autogenroom.h", "\n\n#define CITY_FILE (\"" + newCityFile + "\")" );
    for (int i = 0; i< 9; i++){
        string roomFile = CITY_PATH + cityName + "/" + cityName + "_0/blankcity_" + i + ".c";
        copy_file( "/wiz/kate/open/blankcity/blankcity_" + i + ".c", CITY_PATH + cityName + "/" + cityName + "_0/blankcity_" + i + ".c" );
        roomFile->set_city_name(cityName);
    }
    
}

void build_city(){
    // rooms 1, 3, 4, 5, and 7, will designated as roads.
    int *roads  = ({1, 3, 4, 5, 7});
    for (int i = 0; i < sizeof(roads); i++){
        string roomFile =  CITY_PATH + cityName + "/" + cityName + "_0/blankcity_" + roads[i] + ".c";
        roomFile -> set_short( "cobblestone road");
        roomFile -> set_long( "A simple cobblestone road\n");
    }
    //rooms 0, 2, 6 and 8 will be populated with buildings at random.
    int *build = ({0, 2, 6, 8});
    
    //first the city_hall will be added
    int location = random (sizeof(build));
    string roomFile =  CITY_PATH + cityName + "/" + cityName + "_0/blankcity_" + build[location] + ".c";
    //roomexits contains exits in the following format ...file, exit...
    string *roomExits = roomFile->query_all_exits();
    string cityHallPath = CITY_PATH + cityName + "/" + cityName + "_0/city_hall.c";
    copy_file("wiz/kate/open/kate_hall.c",  cityHallPath);
    
    for (int i=0; i< sizeof(roomExits); i += 2) {
        if (roomExits[i]->query_short() == "cobblestone road") {
            cityHallPath -> add_exit(roomExits[i], roomExits[i+1]);
            string oppExit = query_opposite_exit(roomExits[i+1]);
            roomExits[i]->remove_exit(oppExit);
            roomExits[i]->add_exit(cityHallPath, oppExit);
        }
        build -= ({location});
    }
    
    //storage facility next
    int location2 = random (sizeof(build));
    roomFile =  CITY_PATH + cityName + "/" + cityName + "_0/blankcity_" + build[location2] + ".c";
    //roomexits contains exits in the following format ...file, exit...
    roomExits = roomFile->query_all_exits();
    string storeRoomPath = CITY_PATH + cityName + "/" + cityName + "_0/store_room.c";
    copy_file("wiz/kate/open/store_room.c",  storeRoomPath);
    
    for (int i=0; i< sizeof(roomExits); i += 2) {
        if (roomExits[i]->query_short() == "cobblestone road") {
            storeRoomPath -> add_exit(roomExits[i], roomExits[i+1]);
            string oppExit = query_opposite_exit(roomExits[i+1]);
            roomExits[i]->remove_exit(oppExit);
            roomExits[i]->add_exit(storeRoomPath, oppExit);
        }
        build -= ({location});
    }
    
    //finally workroom
}

void change_exits(){
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
}


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
