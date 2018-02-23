//
//  wiz/kate/open/kate_hall.c
//



#define TP(XXX, YYY) tell_object( XXX, YYY )
#define TR(YYY,XXX) tell_room( environment(YYY), XXX )
#define CITY_PATH ("/wiz/kate/open/")

#include <levels.h>
#include <mudlib.h>

inherit "wiz/kate/open/city.c";


//variables

//function prototypes
int add_lead (string name);
int add_cit (string name);
int citizen_list();
int leader_list();
int cast_out();
string query_citizens();
int add_build(string buildingName);
int building_list();


void reset(status arg) {
    
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("City Hall");
    set_long(" This is a City Hall \n");
    
    set_exits(({}));
    set_items(({
        "pews",
        "Hand crafted and beautifully done, it shows what folks can really\n"+
        "do when they put their minds to it.\n",
        "instructions#sign#posting",
        "=========================Instructions=======================\n"+
        "addleader < name > - This allowes admins to add a city leader\n"+
        "addcitizen < name > - This allowes admins to add a citizen\n"+
        "leaderlist - lists all the leaders of a city\n"+
        "addbuilding < building name > - initates construction of a building\n"+
        "citizenlist - lists all the citizens of a city\n"+
        "buildinglist - lists all the citizens of a city\n"+
        "castout < name >- removes a person as a citizen\n"+
        " More to come ....                                 \n"+
        "=============================================================\n"
        
    }));
    
    set_room_type("building");
}


void init()
{
    // you MUST call the parent's init
    ::init();
    
    if (this_player()->secure(SEC1)){
        add_action( "add_lead", "addleader" );
        add_action( "add_cit", "addcitizen" );
    }
    
    add_action( "citizen_list", "citizenlist");
    add_action( "build_list", "buildinglist");
    add_action( "leader_list", "leaderlist");
    add_action( "cast_out", "castout");
    add_action( "add_build", "addbuilding");
}


int add_lead(string name){
    if (!cityPath->is_citizen(name)){
        TP(this_player(), name + " is not a citizen of this city.\n");
        return 1;
    }
    if (!find_player(name)){
        TP(this_player(), name + " is not a living being in this realm.\n");
        return 1;
    }
    
    TP(this_player(), "You are about to name " + name + " as leader of " + query_city_name() + ".\n"  );
    TR(this_player(), name + " has been named as a leader of " + query_city_name() + ".\n");
    cityPath -> add_leader(name);
    return 1;
}

int add_cit(string name){
    
    //still need to ensure that the player is not a member of another city.
    if (cityPath->is_citizen(name)){
        TP(this_player(), name + " is already a citizen of this city.\n");
        return 1;
    }
    if (!find_player(name)){
        TP(this_player(), name + " is not a living being in this realm.\n");
        return 1;
    }
    TP(this_player(), "You are about to name " + name + " as citiaen of " + query_city_name() + ".\n"  );
    TR(this_player(), name + " has been named as a citizen of " + query_city_name() + ".\n");
    cityPath-> add_citizen(name);
    return 1;
}

int citizen_list(){
    TP(this_player(), cityPath -> query_citizens()  );
    return 1;
    
}

int leader_list(){
    TP(this_player(), cityPath -> query_leaders()  );
    return 1;
    
}

int cast_out (string name){
    
    TP(this_player(), "You are about to REMOVE " + name + " as citiaen of " + query_city_name() + ".\n"  );
    TR(this_player(), name + " has been REMOVED as a citizen of " + query_city_name() + ".\n");
    cityPath->remove_citizen( name );
    return 1;
}


int add_build (string buildingName){
    
    TP(this_player(), "You are about to build " + buildingName + " in " + query_city_name() + ".\n"  );
    cityPath->add_building(buildingName);
    return 1;
}

int build_list(){
    TP(this_player(), cityPath -> query_buildings()  );
    return 1;
    
}
