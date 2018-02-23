//
//  bin/player/craft.c
//
// Base file for the crafting of tools
//

#define TP(XXX, YYY) tell_object( XXX, YYY )
#define CAP_NAME(XXX) (capitalize(XXX->query_name()))
#define TR(YYY,XXX) tell_room( environment(YYY), XXX,({YYY}) )

////////////////////////
//craft_tool functions//
////////////////////////

//returns the average quailty of the components or 0
int has_components(object arg);
string get_file(string name);
void make_item(object thing);
void make_item_2();
void customize_clothing();



// variables

string type;
string item;
object thing;
int quality;
object *tempComponents = ({});
mapping refMap = (["tool": "/obj/craft_tool.c",
                   "armour": "/obj/craft_armour.c",
                   "weapon": "/obj/craft_weapons.c",
                   "clothing": "/obj/craft_clothing.c",
                   "info": "no skill needed"
                   ]);
//mapping skillMap = (["tool": "this_player()->query_tools()" ]);
object ob;
int pass;  //value by which a test it passed


status craft(string arg)
{
    //check to make sure that they are in a workroom
    if (!environment(this_player())->is_workshop())
    {
        TP(this_player(), "You must be in a workroom to craft this item\n");
        return 1;
    }
    
    if (!arg)
    {
        TP(this_player(), "craft <skill> <item>.\n"
           "for more info type craft info <item>.\n"
           );
        return 1;
    }
    
    sscanf(arg, "%s %s", type, item);
    
    if ((!type) || (!item))
    {
        TP(this_player(), "craft <skill> <item>.\n"
           "for more info type craft info <item>.\n"
           );
        return 1;
    }
    
    if (!refMap[type])
    {
        TP(this_player(), type + " is not a valid crafting type.\n");
        TP(this_player(), "valid types are: " + implode( m_indices( refMap ), ", " ) + "\n");
        return 1;
    }
    
    string fileName = get_file(item);
    
    if (!fileName)
    {
        TP(this_player(), item + " is not a type of " + type + ".\n");
        return 1;
    }
    
    load_object(fileName);
    thing = find_object(fileName);    
    
    if (type == "info")
    {
        TP(this_player(), thing->query_extra_info());
        return 1;
    }
    
    //TP(this_player(), "Constructing a thing of type " + type + "\n");
    
    type = lower_case (type);
    

    
   // TP(this_player(), "Starting crafting.\n");
    
    
    if (!is_a (refMap[type], thing)){
        TP(this_player(), item + " is not a type of 2 "+ type + ".\n");
        return 1;
    }
    
    //TP(this_player(), "you are attempting to craft a " + thing->query_short() + ".\n");
    
    quality  = has_components(thing);
    if (quality) {
        //TP(this_player(), "you have the correct components.\n");
        make_item(thing);
        //destruct (tool->get_components());
    }
    return 1;
}

int has_components(object thing)
{
    string *components = explode(thing->get_components(), ",");
    object *inv = all_inventory( this_player() );
    int baseDamage;
    
    
    for(int j = 0; j < sizeof(components); j++)
    {
        //TP( this_player(), "/nlooking for a " + components[j] + ".\n");
        for(int i = 0; i <= sizeof(inv); i++)
        {
            if (i == sizeof(inv))
            {
                TP( this_player(), "You do not have the componenets necessary to craft that item.\n");
                return 0;
            }
            
            //TP( this_player(), "inv number " + i + " of " + sizeof(inv) + " " + inv[i]->query_alias() + "\n");
            
            if ((components[j] == inv[i]->query_alias()) && (member( tempComponents, inv[i] ) == -1)){
                baseDamage += inv[i]->get_quality();
                tempComponents += ({inv[i]});
                break;
            }
            
        }
        
    }

    quality = (baseDamage/sizeof(components));
    //TP( this_player(), "You have the componenets necessary to craft that item.\n");
    return quality;
    
}

void make_item (object thing)
{
    int roll = random(100);
    int pskill;
    if (type == "tool")
    {
        pskill = this_player()->query_tools();
    }
    
    if (type == "clothing")
    {
        pskill = this_player()->query_clothing();
    }
    
    if (type == "armour")
    {
        pskill = this_player()->query_armours();
    }
    
    if (type == "weapon")
    {
        pskill = this_player()->query_weapons();
    }
    /*
    TP( this_player(), "You have rolled a " + roll + ".\n");
    TP( this_player(), "difficulty :" + thing->get_difficulty() + " \n");
    TP( this_player(), "your skill :" + this_player()->query_tools() + " \n");
    TP( this_player(), "your skill :" + pskill + " \n");
    */
    
    pass = roll - (thing->get_difficulty() - this_player()->query_tools());
    TP( this_player(), "You have a pass number of " + pass + ".\n");
    if (pass > 0)
    {
        TP(this_player(), "You begin making a " + thing->query_short() + " with a difficulty of " + thing->get_difficulty() + ".\n");
        TR(this_player(), CAP_NAME(this_player()) + " begins crafting.\n");
    }
    if ((pass <= 0) && (pass > -10))
    {
        TP(this_player(), "You fail in your attempt to produce a " + thing->query_short() + ".\n");
        TR(this_player(), CAP_NAME(this_player()) + " fails in their crafting attempt.\n");
        return;
    }
    if (pass <= -10)
    {
        TP(this_player(), "You fail so miserably in your attempt to produce a " + thing->query_short() + " that all of the components are destroyed.\n");
        TR(this_player(), CAP_NAME(this_player()) + " fails miserably in their crafting attempt.\n");
        for(int j = 0; j < sizeof(tempComponents); j++)
        {
            destruct(tempComponents[j]);
        }
        return;
    }
    ob = clone_object (thing);
    
    if (type == "clothing")
    {
        call_out("customize_clothing", 2);
    }
    
    else
    {
        call_out ("make_item_2", 5);
    }
}


void make_item_2 ()
{
    
    int obQuality;
    
    
    if (pass >= (2*ob->get_difficulty()))
    {
        obQuality = quality;
    }
    else
    {
        obQuality = (quality - (2* ob->get_difficulty() - pass));
    }
    
    if (type == "weapon")
    {
        ob->set_weapon_strength (obQuality);
    }
    
    ob->set_max_damage(obQuality);
    move_object( ob, this_player() );
    
    for(int j = 0; j < sizeof(tempComponents); j++)
    {
        destruct(tempComponents[j]);
    }
    
    
    TP( this_player(), "You have a pass number of " + pass + ".\n");
    TP(this_player(), "You have made a " + ob->query_short() + " of quality " + obQuality + ".\n");
    TR(this_player(), CAP_NAME(this_player()) + " has successfully crafted a " + ob->query_short() + ".\n");
    
}


void customize_clothing ()
{
    write("item name?\n");
    input_to ("set_short");
}

void set_short (string name)
{
    TP(this_player(), "setting short name of " + ob->query_alias() + "to " + name + "\n");
    ob->set_short(name);
    write("item description?\n");
    input_to ("set_long");
}

void set_long (string desc)
{
    TP(this_player(), "setting description of " + ob->query_alias() + "to " + desc + "\n");
    ob->set_long(desc + "\n");
    
    call_out ("make_item_2", 5);
}

string get_file(string name)
{
    mapping objMap;
    
    objMap = (["shovel":"/obj/crafting/shovel.c",
               "shaft": "/obj/crafting/shaft.c",
               "shovel head": "/obj/crafting/shovel_head.c",
               "dress": "/obj/crafting/dress.c",
               "sign axe": "/obj/crafting/sign_axe.c",
               "pickaxe": "/obj/crafting/pickaxe.c"
               ]);
    
    return objMap[name];
}
