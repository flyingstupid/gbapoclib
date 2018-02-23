#include <mudlib.h>
#include <ansi.h>
#include "/wiz/emraef/open/scav/scavpaths.h"

// uncomment to enable saving
#define ENABLE_SAVE

#ifdef ENABLE_SAVE
#define LOAD restore_object( "/" + file_name(this_object()) )
#define SAVE save_object( "/" + file_name(this_object()) )
#else
#define SAVE
#define LOAD
#endif //ENABLE_SAVE

inherit ROOM;

#define CAP_NAME(XXX) (capitalize(XXX->query_name()))
#define TR(XXX, YYY) tell_room( this_object(), XXX, ({YYY}) )
#define TP(XXX, YYY) tell_object( XXX, YYY )

// TODO: REPLACE WITH CITY ACCESS CHECKS
#define CHECK_ACCESS(XXX) (1)
#define CHECK_CITIZEN(XXX) (1)


mapping supplies;
mapping deposit_values;
mapping minimums;
mapping refine_costs;

mapping query_supplies() { return supplies; }

status do_set_value( string arg );
status do_set_min( string arg );
status do_set_cost( string arg );
status do_inventory( string arg );
status do_storage( string arg );
status do_list_deposit_values( string arg );
status do_list_min( string arg );
status do_list_refining( string arg );
status do_list_resouce_cost( string arg );
status do_buy_refined_item( string arg );

int calculate_value_by_type( string type );
object get_scavbag( object player );

//-----------------------------------------------------------------
void reset(status arg) {
    if (arg) return;

    LOAD;

    if( !supplies )
        supplies = ([]);

    if( !deposit_values )
        deposit_values = ([]);

    if( !minimums )
        minimums = ([]);

    if( !refine_costs )
        refine_costs = ([]);
}

//-----------------------------------------------------------------
void init()
{
    ::init();

    add_action( "do_storage", "deposit" );
    add_action( "do_list", "list" );
    add_action( "do_set", "set" );
    add_action( "do_buy_refined_item", "buy" );
}

//-----------------------------------------------------------------
status do_buy_refined_item( string arg )
{
    if( !CHECK_CITIZEN(this_player()) )
    {
        return 0;
    }

    string *keys;
    
    keys = RESOURCE_D->query_craft_items( arg );

    if( sizeof( keys ) == 0 )
        return 0;

    int count = 1;
    sscanf( arg, "%s %d", arg, count );

    if( member( keys, arg ) == -1 )
    {
        TP( this_player(), capitalize(arg) + " is not a valid refined item.\n" );
        return 1;
    }

    mapping cost = RESOURCE_D->query_craft_item_cost( arg );
    string *cost_keys = m_indices( cost );
    int total_cost = 0;
    string bill_of_sale = "";
    status has_storage = 1;

    bill_of_sale += sprintf( "| %-11.11s(%5.5s) x %3.3s | %9.9s |\n", "ITEM", "PRICE", "###", "SUBTOTALS" );
    bill_of_sale += "|--------------------------------------|\n";

    for( int i = 0; i < sizeof( cost_keys ); i++ )
    {
        string key = cost_keys[i];

        cost[key] *= count;

        int min = minimums[key];
        int stores = supplies[key];

        // check if we have enough of the resource
        if( stores < cost[key] || ( min > 0 && min > supplies - cost[key] ) )
        {
            TP( this_player(), "There is not enough "+ key + " in storage.\n" );
            has_storage = 0;
        }
        
        int value = refine_costs[key] * cost[key];
        int base_price = 0;

        if( value == 0 )
        {
            base_price = RESOURCE_D->query_resource_use_cost( key );
            value = base_price * cost[key];
        }

        bill_of_sale += sprintf( "| %-11.11s(¢%4.4d) x %3.3d | %9.9s |\n", key, base_price, cost[key], "¢" + value );

        total_cost += value;
    }

    // if there wasn't enough of something bail.  We have already informed the player.
    if( !has_storage )
    {
        return 1;
    }

    if( this_player()->query_money() < total_cost )
    {
        TP( this_player(), "You don't have the required credits.\n" );

        return 1;
    }

    string file_name = RESOURCE_D->query_craft_item_file( arg );

    for( int i = 0; i < count; i++ )
    {
        object ob = clone_object( file_name );
        if( this_player()->add_weight(ob->query_weight()) )
        {
            move_object( ob, this_player() );
        }
        else
        {
            TP( this_player(), "You are carring too much dropping item in the room.\n" );
            move_object( ob, environment( this_player() ) );
        }
    }

    //charge the player
    this_player()->adj_money( -total_cost );

    // remove the supplies
    for( int i = 0; i < sizeof( cost_keys ); i++ )
    {
        string key = cost_keys[i];
        supplies[key] -= cost[key];
    }

    bill_of_sale += "|                                      |\n";
    bill_of_sale += "|======================================|\n";
    bill_of_sale += sprintf( "| TOTAL: %29.29s |\n", "¢" + total_cost );
    bill_of_sale += "+--------------------------------------+\n";

    TP( this_player(), "+--------------------------------------+\n" ); 
    TP( this_player(), sprintf( "| %-36.36s |\n|   %-34.34s |\n%s", "BILL OF SALE", arg + " x " + count, bill_of_sale ) );

    return 1;
}

//-----------------------------------------------------------------
status do_set( string arg )
{
    if( !CHECK_CITIZEN(this_player()) )
        return 0;
    
    if( !CHECK_CITIZEN(this_player()) )
        return 0;

    string type;
    if( !arg || sscanf( arg, "%s %s", type, arg ) != 2 )
    {
        type = arg;
        arg = "";
    }

    switch( type )
    {
        case "value":
        case "values":
            return do_set_value( arg );
            break;
        case "min":
        case "mins":
        case "minimum":
        case "minimums":
            return do_set_min( arg );
            break;
        case "cost":
            return do_set_cost( arg );
            break;
        default:
            TP( this_player(), "Storeroom Options: value, min, cost\n" );
            break;
    }

    return 0;
}

//-----------------------------------------------------------------
status do_list( string arg )
{
    if( !CHECK_CITIZEN(this_player()) )
        return 0;

    string type;
    if( !arg || sscanf( arg, "%s %s", type, arg ) != 2 )
    {
        type = arg;
        arg = "";
    }

    switch( type )
    {
        case "value":
        case "values":
            return do_list_deposit_values( arg );
            break;
        case "min":
        case "mins":
        case "minimum":
        case "minimums":
            return do_list_min( arg );
            break;
        case "refine":
        case "refineing":
        case "items":
            return do_list_refining( arg );
            break;
        case "cost":
            return do_list_resouce_cost( arg );
            break;
        case "all":
            arg = "all";
        case "stored":
        case "stores":
        case "store":
            arg = "";
            return do_inventory( arg );
            break;
        default:
            TP( this_player(), "Storeroom Options: value, min, refine, all, stored\n" );
            break;
    }

    return 0;
}

//-----------------------------------------------------------------
status do_set_cost( string arg )
{
    string type;
    int cost;

    if( !arg || arg == "" || sscanf( arg, "%s %d", type, cost ) != 2 )
    {
        TP( this_player(), "USESAGE: set cost <type> <cost>\n" );
        return 1;
    }

    if( !RESOURCE_D->is_valid_resource_type( type ) )
    {
        TP( this_player(), "Type: " + type + " is not a valid resource type.\n" );
        return 1;
    }

    string status_str = "SUCCESS!";

    if( cost <= 0 )
    {
        status_str = "RESET!";
        cost = 0;
    }

    refine_costs[type] = cost;

    SAVE;

    TP( this_player(), "[" + HIW + type + OFF + "] = " + cost + HIG + "\n" + status_str + "\n" + OFF );

    return 1;
}

//-----------------------------------------------------------------
status do_set_min( string arg )
{
    string type;
    int minimum;

    if( !arg || arg == "" || sscanf( arg, "%s %d", type, minimum ) != 2 )
    {
        TP( this_player(), "USESAGE: set min <type> <minimum>\n" );
        return 1;
    }

    if( !RESOURCE_D->is_valid_resource_type( type ) )
    {
        TP( this_player(), "Type: " + type + " is not a valid resource type.\n" );
        return 1;
    }

    string status_str = "SUCCESS!";

    if( minimum <= 0 )
    {
        status_str = "RESET!";
        minimum = 0;
    }

    minimums[type] = minimum;

    SAVE;

    TP( this_player(), "[" + HIW + type + OFF + "] = " + minimum + HIG + "\n" + status_str + "\n" + OFF );

    return 1;
}

//-----------------------------------------------------------------
status do_set_value( string arg )
{
    string type;
    int value;

    if( !arg || arg == "" || sscanf( arg, "%s %d", type, value ) != 2 )
    {
        TP( this_player(), "USESAGE: set value <type> <value>\n" );
        return 1;
    }

    if( !RESOURCE_D->is_valid_resource_type( type ) )
    {
        TP( this_player(), "Type: " + type + " is not a valid resource type.\n" );
        return 1;
    }

    string status_str = "SUCCESS!";

    if( value <= 0 )
    {
        status_str = "RESET!";
        value = 0;
    }

    deposit_values[type] = value;

    SAVE;

    TP( this_player(), "[" + HIW + type + OFF + "] = " + value + HIG + "\n" + status_str + "\n" + OFF );

    return 1;
}

//-----------------------------------------------------------------
object get_scavbag( object player )
{
    if( !player )
    {
        return 0;
    }

    object *inv = all_inventory( player );

    for( int i = 0; i < sizeof( inv ); i++ )
    {
        if( is_a( SCAVBAG, inv[i] ) )
            return inv[i];
    }

    return 0;
}

//-----------------------------------------------------------------
int calculate_value_by_type( string type )
{
    int value = deposit_values[type];

    if( !value )
    {
        value = RESOURCE_D->query_resource_value( type );
    }

    return value;
}

//-----------------------------------------------------------------
status do_storage( string arg )
{
    if( !CHECK_CITIZEN(this_player()) )
        return 0;

    object bag = get_scavbag( this_player() );

    if( !bag )
    {
        TP( this_player(), "You have no resources to deposit.\n" ); 
    }

    object *inv = all_inventory( bag );

    if( sizeof( inv ) == 0 )
    {
        TP( this_player(), "You have no resources to deposit.\n" ); 
    }

    TP( this_player(), "Depositing...\n" );

    int totalValue = 0;
   
    for( int i = 0; i < sizeof( inv ); i++ )
    {
        object ob = inv[i];
        string type = ob->query_resource_type();

        supplies[type]++;

        int value = calculate_value_by_type(type);
        totalValue += value;

        TP( this_player(), ob->query_short() + " [" + value + "]\n" );

        destruct(ob);
    }

    TP( this_player(), "Compelte!\n" );
    TP( this_player(), "Total credit: " + totalValue );

    this_player()->add_money( totalValue );

    SAVE;

    return 1;
}

//-----------------------------------------------------------------
status do_inventory( string arg )
{
    string *keys;

    keys = m_indices( supplies );
    string header = "The storeroom contains:\n";

    if( arg == "all" )
    {
        header = "The storeroom contains [all]:\n";
        keys = RESOURCE_D->query_resource_types();
    }

    TP( this_player(), header );
    for( int i = 0; i < sizeof(keys); i++ )
    {
        string color = HIW;
        string key = keys[i];
        int supply = supplies[key];

        if( minimums[key] > 0 )
        {
            color = ( supply > minimums[key] ? HIG : ( supply == minimums[key] ? HIY : HIR ) );
        }

        TP( this_player(), sprintf( "  %s%12.12s : %d%s\n", color, key, supply, OFF ) );
    }
    
    return 1;
}


//-----------------------------------------------------------------
status do_list_deposit_values( string arg )
{
    string *keys;
    
    if( !CHECK_ACCESS(this_player()) )
    {
        arg = "all";
    }

    if( arg == "all" )
    {
        keys = RESOURCE_D->query_resource_types();
    }
    else
    {
        keys = m_indices( deposit_values );
    }

    TP( this_player(), "VALUES:\n" );

    for( int i = 0; i < sizeof(keys); i++ )
    {
        int value = deposit_values[keys[i]];
        string color = HIG;

        if( !value )
        {
            value = RESOURCE_D->query_resource_value( keys[i] );
            color = HIW;
        }

        TP( this_player(), sprintf( "  %s%12.12s : %d%s\n", color, keys[i], value, OFF ) );
    }

    return 1;
}

//-----------------------------------------------------------------
status do_list_min( string arg )
{
    string *keys;

    if( !CHECK_ACCESS(this_player()) )
    {
        arg = "all";
    }

    if( arg == "all" )
    {
        keys = RESOURCE_D->query_resource_types();
    }
    else
    {
        keys = m_indices( minimums );
    }

    TP( this_player(), "MINIMUMS:\n" );

    for( int i = 0; i < sizeof(keys); i++ )
    {
        int value = minimums[keys[i]];
        string color = HIG;

        if( !value )
        {
            color = HIW;
        }

        TP( this_player(), sprintf( "  %s%12.12s : %d%s\n", color, keys[i], value, OFF ) );
    }

    return 1;
}

//-----------------------------------------------------------------
status do_list_refining( string arg )
{
    string *keys;
    
    keys = RESOURCE_D->query_craft_items( arg );

    if( sizeof( keys ) == 0 )
        return 0;

    // list flags
    status list_by_resource = 0;
    status single_item_full_list = 0;
    status list_details = 0;

    string mod = "";
    if( sscanf( arg, "%s %s", arg, mod ) )
        mod = "";

    if( member( keys, arg ) != -1 )
    {
        list_details = 1;
        single_item_full_list = 1;
    }

    if( RESOURCE_D->is_valid_resource_type( arg ) )
    {
        list_by_resource = 1;
    }

    if( arg == "all" || arg == "full" ||
        mod == "all" || mod == "full" )
    {
        list_details = 1;
    }
        

    TP( this_player(), "REFINED ITEMS:\n" );

    for( int i = 0; i < sizeof(keys); i++ )
    {
        if( single_item_full_list && keys[i] != arg )
            continue;

        mapping cost = RESOURCE_D->query_craft_item_cost( keys[i] );
        
        string color = HIW;

        int total_cost = 0;


        string *cost_keys = m_indices( cost );

        string resource_list = "";

        if( list_by_resource && member( cost_keys, arg ) == -1 )
            continue;

        for( int j = 0; j < sizeof( cost_keys ); j++ )
        {
            color = HIW;
            string key = cost_keys[j];
            int value = refine_costs[key] * cost[key];

            if( value == 0 )
            {
                value = RESOURCE_D->query_resource_use_cost( key ) * cost[key];
            }

            int min = minimums[key];
            int stores = supplies[key];

            // check if we have enough of the resource
            if( stores < cost[key] || ( min && min > supplies - cost[key] ) )
            {
                color = HIR;
            }

            if( value == -1 ) 
            {
                // if the value is -1 then the resource is restriced
                color = HIR;
            }
            resource_list += sprintf( "+--- %s%s x %d (¢%d)%s\n", color, key, cost[key], value, OFF );
            total_cost += value;
        }

        if( !list_details )
            TP( this_player(), sprintf( "%s%5.5s | %s%s\n", color, "¢" + to_string(total_cost), upper_case( keys[i] ), OFF ) );
        else
            TP( this_player(), sprintf( "%s%s (¢%d)\n%s%s\n", color, upper_case( keys[i] ), total_cost, OFF, resource_list ) );

    }

    return 1;
}

//-----------------------------------------------------------------
status do_list_resouce_cost( string arg )
{
    if( !CHECK_ACCESS(this_player()) )
    {
        arg = "all";
    }

    string *keys;

    if( arg == "all" )
    {
        keys = RESOURCE_D->query_resource_types();
    }
    else
    {
        keys = m_indices( refine_costs );
    }

    TP( this_player(), "RESOUCE REFINE COSTS:\n" );

    for( int i = 0; i < sizeof(keys); i++ )
    {
        int value = refine_costs[keys[i]];
        string color = HIG;

        if( !value )
        {
            value = RESOURCE_D->query_resource_use_cost( keys[i] );
            color = HIW;
        }

        TP( this_player(), sprintf( "  %s%12.12s : %d%s\n", color, keys[i], value, OFF ) );
    }

    return 1;
}
