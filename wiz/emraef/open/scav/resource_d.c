#include <mudlib.h>
#include "/wiz/emraef/open/scav/scavpaths.h" 

// uncomment to enable saving
//#define ENABLE_SAVE

#ifdef ENABLE_SAVE

#define SAVEPATH "/wiz/emraef/open/scav/resource_d"
#define SAVE save_object(SAVEPATH)
#define LOAD restore_object(SAVEPATH);
#else

#define SAVE
#define LOAD

#endif // ENABLE_SAVE

// TYPE : ({ NAME, PLURAL, SHORT, WEIGHT, ALIAS, DEFAULT_VALUE, DEFAULT_COST })
nosave mapping resourceTypes = ([
        "wood"      :   ({ "wood", "wood", "some wood", 1, "wood", 1, 2 }),
        "mushrooms" :   ({ "mushrooms", "mushrooms", "some mushrooms", 1, "mushrooms", 2, 3 }),
        "ironore"   :   ({ "ironore", "ironore", "some ironore", 3, "ironore", 5, 7 }),
        "cotton"    :   ({ "cotton", "cotton", "some cotton", 1, "cotton", 3, 6 }),
        "coal"      :   ({ "coal", "coal", "some coal", 2, "coal", 2, 4 }),
        "stone"     :   ({ "stone", "stone", "some stone", 2, "stone", 1, 2 }),
        "quartz"    :   ({ "quartz", "quartz", "some quartz", 1, "quartz", 3, 10 }),
        ]);

// TYPE : ({ NAME, SHORT, LONG, ALIAS, RESOURCETYPE, MAXAMOUNT, DIFFICULTY, REQUIRED_ITEM })
nosave mapping sourceTypes = ([
        "wood"          : ({ "wood", "a source of wood", "A source of good quality wood.", "wood source", "wood", 7, 1, "" }),
        "mushrooms"     : ({ "mushrooms", "a cluster of mushrooms", "A large cluster of edible mushrooms.", "mushrooms source", "mushrooms", 4, 1, "" }),
        "ironvein"      : ({ "ironvein", "a vein of iron", "A small vein of iron ore.", "ironore source", "ironore", 3, 1, "pickaxe" }),
        "cotton"        : ({ "cotton", "a cluster of cotton plants", "a cluster of cotton plants.", "cotton source", "cotton", 4, 2, ""}),
        "burnttree"     : ({ "burnttree", "a charred tree.", "the charred remains of a tree.", "tree", "coal", 3, 1, "" }),
        "stonedeposit"  : ({ "stonedeposit", "a stone deposit.", "A deposit of good quality stone.", "stone", "stone", 5, 1, "pickaxe" }),
        "quartzdeposit" : ({ "quartzdeposit", "a quartz deposit.", "A deposit of good quality quartz.", "quartz", "quartz", 2, 1, "pickaxe" }),
        "coaldeposit"   : ({ "coaldeposit", "a coal deposit.", "A deposit of coal.", "coal", "coal", 3, 1, "pickaxe" }),

        ]);

// TYPE : ({ ({ TYPE, CHANCE })
nosave mapping roomTypes = ([
        "forest1": ({ 
            ({ "none", 10 }),
            ({ "wood", 5 }), 
            ({ "cotton", 5 })    
        }),
        "forest2": ({ 
            ({ "none", 10 }),
            ({ "wood", 20 }), 
        }),
        "forest3": ({ 
            ({ "none", 10 }),
            ({ "wood", 3 }), 
            ({ "mushrooms", 2 }),
        }),
        "forest4": ({ 
            ({ "none", 30 }),
            ({ "wood", 10 }), 
            ({ "mushrooms", 10 }),
            ({ "cotton", 10 })    
        }),
        "forest5": ({ 
            ({ "none", 20 }),
            ({ "wood", 10 }), 
        }),
        "forest6": ({ 
            ({ "none", 15 }),
            ({ "wood", 10 }), 
            ({ "mushrooms", 1 }),
            ({ "cotton", 1 })    
        }),
        "forest7": ({ 
            ({ "none", 10 }),
            ({ "wood", 10 }), 
            ({ "cotton", 4 })    
        }),
        "forest8": ({ 
            ({ "none", 20 }),
            ({ "wood", 20 }),
            ({ "ironvein", 1 }),
        }),
        "forest9": ({ 
            ({ "none", 20 }),
            ({ "wood", 20 }), 
            ({ "burnttree", 3 }),
        }),
        "forest10": ({ 
            ({ "none", 20 }),
            ({ "wood", 10 }), 
            ({ "cotton", 10 })    
        }),
        "cave1": ({ 
            ({ "none", 20 }),
            ({ "stonedeposit", 20 }),
            ({ "coaldeposit", 5 }),
            ({ "quartzdeposit", 1 }),
            ({ "ironvein", 1 }), 
        }),
        "cave2": ({ 
            ({ "none", 20 }),
            ({ "stonedeposit", 20 }),
            ({ "ironvein", 1 }), 
        }),
        "cave3": ({ 
            ({ "none", 20 }),
            ({ "stonedeposit", 20 }),
        }),
        "cave4": ({ 
            ({ "none", 20 }),
            ({ "stonedeposit", 20 }),
            ({ "coaldeposit", 3 }),
            ({ "ironvein", 2 }), 
        }),
        "cave5": ({ 
            ({ "none", 20 }),
            ({ "stonedeposit", 20 }),
            ({ "coaldeposit", 5 }),
            ({ "quartzdeposit", 1 }),
            ({ "ironvein", 1 }), 
        }),
        "cave6": ({ 
            ({ "none", 30 }),
            ({ "stonedeposit", 30 }),
            ({ "ironvein", 5 }), 
        }),
        "cave7": ({ 
            ({ "none", 20 }),
            ({ "stonedeposit", 10 }),
            ({ "quartzdeposit", 3 }),
        }),
        "cave8": ({ 
            ({ "none", 20 }),
            ({ "stonedeposit", 20 }),
            ({ "coaldeposit", 5 }),
            ({ "quartzdeposit", 1 }), 
        }),
        "cave9": ({ 
            ({ "none", 20 }),
            ({ "stonedeposit", 20 }),
        }),
        "cave10": ({ 
            ({ "none", 20 }),
            ({ "stonedeposit", 20 }),
            ({ "coaldeposit", 5 }), 
        }),

        "city": ({
            ({ "none", 100 }),
            ({ "mushrooms", 1 }), 
        }),

        "test": ({
            ({ "ironvein", 1 }),
        }),
        ]);

nosave mapping craft_items = ([]);

mapping rooms = ([ ]);

mapping get_rooms() { return rooms; }

object create_resource_by_type( string resourceType );
object create_source_given_list( object room_ob, mixed *roomArray );
object create_source_by_type( string sourceType, int skill );
object create_source_by_room_type( object room_ob, string roomType );
int calculate_gather_value( int skill, int max );


int query_resource_value( string type ) { return (resourceTypes[type] ? resourceTypes[type][R_DEFAULT_VALUE] : 0); }
status is_valid_resource_type( string type ) { return member( m_indices(resourceTypes), type ) != -1; }
string * query_resource_types() { return m_indices( resourceTypes ); }
string * query_craft_items() { return m_indices( craft_items ); }

mapping query_craft_item_cost( string item ) { return craft_items[item] ? craft_items[item]["cost"] : ([]); } 
string query_craft_item_file( string item ) { return craft_items[item] ? craft_items[item]["file"] : 0; } 
int query_resource_use_cost( string type ) { return (resourceTypes[type] ? resourceTypes[type][R_DEFAULT_COST] : 0); }

//------------------------------------------------------------------
void reset(status arg)
{
    if( arg )
        return;

    LOAD;

    string base_path = "/obj/crafting/base/"; 

    mixed * base_items = get_dir( base_path, 3 ); // 3 = Names and file sizes

    int i = 0;

    for( i = 0; i < sizeof( base_items ); i+=2 )
    {
        // not a file
        if( base_items[i+1] <=0 )
        {
            continue;
        }

        string file_path = base_path + base_items[i];

        object ob = load_object( file_path );

        // Error loading
        if( !ob )
        {
            continue;
        }

        string name = ob->query_name();
        mapping cost = ob->query_resource_cost();
        
        craft_items[name] = ([ "file":file_path, "cost":cost ]);
    }
}

//------------------------------------------------------------------
object create_resource_by_type( string type )
{
    mixed *resource_data = resourceTypes[type];

    if( !resource_data )
    {
        return 0;
    }

    object resource = clone_object( RESOURCE );
    resource->set_resource_type( type );
    resource->set_name( resource_data[R_NAME] );
    resource->set_plural( resource_data[R_PLURAL] );
    resource->set_short( resource_data[R_SHORT] );
    resource->set_weight( resource_data[R_WEIGHT] );
    resource->set_alias( resource_data[R_ALIAS] );
    
    
    resource->set_long( "This is a unit of gathered " + resource_data[R_NAME] + ".\n" );

    return resource;
}

//------------------------------------------------------------------
object create_source_by_type( string sourceType, int skill )
{
    mixed *source_data = sourceTypes[sourceType];

    if( !source_data )
    {
        LOG( "source data not found for: " + sourceType );
        return 0;
    }

    object source = clone_object( GATHER_SOURCE );

    if( !source )
    {
        LOG( "ERROR: INVALID ROOM TYPE PASSED TO RESOURCE_D\n" );
        return 0;
    }

    source->set_source_type( sourceType );
    source->set_name( source_data[S_NAME] );
    source->set_short( source_data[S_SHORT] );
    source->set_long( source_data[S_LONG] + "\nPerhaps you should <gather> it.\n" );
    source->set_alias( source_data[S_ALIAS] );
    source->set_gather_object( source_data[S_RESOURCETYPE] );
    source->set_num_gathers( calculate_gather_value( skill, source_data[S_MAXAMOUNT] ) );
    source->set_required_item( source_data[S_REQUIRED_ITEM] );

    return source;
}

//------------------------------------------------------------------
object create_source_by_room_type( object room_ob, string roomType )
{
    mixed *roomArray;

    if( roomType == "custom" )
    {
        roomArray = room_ob->query_custom_source_list();
        if( !roomArray )
        {
            return 0;
        }
    }
    else
    {
        roomArray = roomTypes[ roomType ];
    }

    return create_source_given_list( room_ob, roomArray );
}

//------------------------------------------------------------------
object create_source_given_list( object room_ob, mixed *roomArray )
{
    int i;
    int totalWeight = 0;

    mapping room = rooms[file_name(room_ob)];

    if( !room )
    {
        rooms[file_name(room_ob)] = ([]);

        room = rooms[file_name(room_ob)];
    }

    string sourceType = "none";

    // INVALID TYPE
    if( !roomArray )
    {
        LOG( "ERROR: INVALID ROOM TYPE PASSED TO RESOURCE_D\n" );
        return 0;
    }

    // total the weights
    for( i = 0; i < sizeof( roomArray ); i++ )
    {
        int roomAdjust = (room ? room[roomArray[i][0]] : 0);
        int typeWeight = roomArray[i][1] - roomAdjust;

        totalWeight += max( 0, roomArray[i][1] - roomAdjust );
    }

    int roll = random( totalWeight );
    //LOG( "source roll: " + roll + " of " + totalWeight );

    for( i = 0; i < sizeof( roomArray ); i++ )
    {
        int roomAdjust = (room ? room[roomArray[i][0]] : 0);
        int typeWeight = roomArray[i][1] - roomAdjust;

        if( roll < typeWeight ) 
        {
            sourceType = roomArray[i][0];
            break;
        }

        roll -= typeWeight;
    }

    // Didn't find anything.
    if( sourceType == "none" )
    {
        return 0;
    }

    room[sourceType] = room[sourceType] + 1;

    SAVE;

    return create_source_by_type( sourceType, 0 );
}


//------------------------------------------------------------------
int calculate_gather_value( int skill, int max )
{
    int value = 1;

    // we always give one so only roll on max - 1.
    max--;

    for( int i = 0; i < max; i++ )
    {
        if( ( random(100) - skill ) < 30 )
        {
            value++;
        }
    }

    return value;
}


