/* Shop v3.0
 *
 * v1 by Zilanthius, Jan 1994. updates by Kingbilly
 * v2 by Xanax of Malevolence (www.malevolence.com), Dec 1995
 * 
 * New economy for gold, silver, platinum, etc, by Angel
 *
 * v3 by Angel 1997
 *
 */


#include <mudlib.h>
#include <linewrap.h>

inherit ROOM; 


/*****************************************************************************/
/* Shop Configuration */

#define MAX_VALUE        4000     /* max. money when selling + charisma      */ 
#define BUY_MOD          2        /* divide price by this amount when selling */

#define S_STORE_ROOM     "/objects/store_room"
#define NAME             (string)this_player()->query_name() 

#define MAX_LIST_LENGTH  50

#define MAX_STOCK        10      /* maximum stock of each specific item      */
#define TOTAL_STOCK      60      /* total number of armour, weapon, treasure */


#define OWNER_STAT       25 

#define BARGAIN             (int)this_player()->query_charisma() +\
    (int)this_player()->bargain_bonus()

#define APPRAISAL       (int)this_player()->query_intelligence()/5 +\
    (int)this_player()->query_appraisal()

object STORE_ARMOUR; 
object STORE_WEAPON; 
object STORE_TREASURE; 


string owner; 
mixed *files;

string *sell_items;
mapping global_economy;
mapping store_list;




/*****************************************************************************/
/* Function Prototypes */

status  query_sell_items(string str);
void    set_owner(string arg);
varargs void inventory(object arg, string fn);
mixed   calc_value(int i);

varargs query_global_economy(object ob);
mapping add_global_economy(object ob);
mapping remove_global_economy(object ob);




void reset(status arg) { 
    if(!global_economy) global_economy = ([ ]);
    if(owner && !present(lower_case(owner))) set_owner(owner); 

    if(arg) return;
    set_weather(2, 1, 1);
} 



void init() {
    ::init(); 

    /* if you do forget to set_name() - defaults to "Farin" */


    if(!owner) set_owner(0); 
    if(!global_economy || !sizeof(global_economy)) global_economy = ([ ]);

    if(!sizeof(files)) files = ({ });


    /* This is so you don't get a new holder everytime you update the shop */ 

    if(!STORE_ARMOUR || !STORE_WEAPON || !STORE_TREASURE) { 
        int i; 
        string filename; 
        object *inv; 

        call_other(S_STORE_ROOM,"???"); /* load the storeroom */ 
        inv = all_inventory(find_object(S_STORE_ROOM));
        for(i = 0; i < sizeof(inv); i++) { 
            if(inv[i]->id(file_name(this_object()))){ 
                if(inv[i]->id("armour"))   STORE_ARMOUR = inv[i]; 
                if(inv[i]->id("weapon"))   STORE_WEAPON = inv[i]; 
                if(inv[i]->id("treasure")) STORE_TREASURE = inv[i]; 
            } 
        } 
    } 

    /*** Make the storage containers ***/ 

    if(!STORE_ARMOUR){ 
        STORE_ARMOUR = clone_object(CONTAINER);
        STORE_ARMOUR -> set_name("armour"); 
        STORE_ARMOUR -> set_alt_name(file_name(this_object())); 
        STORE_ARMOUR -> set_short("Armour: "+file_name(this_object())); 
        STORE_ARMOUR -> set_weight(10000); 
        STORE_ARMOUR -> set_max_weight(100000); 
        move_object(STORE_ARMOUR, S_STORE_ROOM); 
    } 
    if(!STORE_WEAPON) {
        STORE_WEAPON = clone_object(CONTAINER);
        STORE_WEAPON -> set_name("weapon"); 
        STORE_WEAPON -> set_alt_name(file_name(this_object())); 
        STORE_WEAPON -> set_short("Weapon: "+file_name(this_object())); 
        STORE_WEAPON -> set_weight(10000); 
        STORE_WEAPON -> set_max_weight(100000); 
        move_object(STORE_WEAPON, S_STORE_ROOM); 
    } 
    if(!STORE_TREASURE){ 
        STORE_TREASURE = clone_object(CONTAINER); 
        STORE_TREASURE -> set_name("treasure"); 
        STORE_TREASURE -> set_alt_name(file_name(this_object())); 
        STORE_TREASURE -> set_short("Treasure: "+file_name(this_object())); 
        STORE_TREASURE -> set_weight(10000); 
        STORE_TREASURE -> set_max_weight(100000); 
        STORE_TREASURE->move(S_STORE_ROOM);
        move_object(STORE_TREASURE, S_STORE_ROOM); 
    } 



    /*** Shop actions ***/ 

    add_action("sell","sell"); 
    add_action("list","list"); 
    add_action("buy","buy"); 
    add_action("buy","browse"); /* same find ob routine */ 
    add_action("value","value"); 
    add_action("look_at", "read"); 
    add_action("storeroom","storeroom"); 
} 


status storeroom(){ 
    if(this_player()->query_security_level()){ 
        this_player()->move_player("storeroom#"+S_STORE_ROOM); 
        return 1; 
    } 
} 


void long(status wiz) {
    ::long(wiz);
    if(this_player()->query_security_level()){ 
        write("You also notice the store room exit: <storeroom>\n"); 
    } 
}


status look_at(string str) {

    if(str == "list" || str == "sign"){ 
        write("\t-=[ "+ query_short() +" ]=-\n\n"+

                "   Buy: buy <item>, buy <number> armour (or a),\n"+ 
                "        buy <number> weapon (or w), buy <number> treasure (or t).\n"+ 
                "  Sell: sell <all>, sell <item>.\n"+ 
                " Value: value <item>.\n"+ 
                "  List: list, list <armour> (or a), list <weapon> (or a),\n"+ 
                "        list <treasure> (or t).\n"+
                "Browse: browse <item>, browse <number>a, browse <number>w, "+
                "browse <number>t.\n\n");

        write("Conversion rate: 1 gold = 10 silver, 1 silver = 100 copper\n"+
                "For help on bargaining, see type 'man stats'\n");
        return 1; 
    } 
    return ::look_at(str); 
} 




status sell(string str){ 
    int i, value, number; 
    object *ob; 
    status flag;

    if(!present(lower_case(owner), this_object())){ 
        write(owner+" is not here right now, so you cannot sell anything.\n"); 
        return 1; 
    } 
    if(!str){ 
        write("Sell what?\n"); 
        return 1; 
    } 
    if(str == "all"){ 
        ob = all_inventory(this_player()); 
    }
    else if(present(str, this_player())) {
        ob = ({ present(str, this_player()), });
    }
    else {
        write(owner+" says: I'm not interested in a "+str+".\n"); 
        return 1; 
    } 
    for(i = 0; i < sizeof(ob); i++) { 
        if(ob[i]->short() && ob[i]->query_value() && !ob[i]->drop()) {
            if(!ob[i]) continue; 
            if(!query_sell_items(ob[i]->query_object_type()) &&
                    !query_sell_items(ob[i]->query_alias()) &&
                    !query_sell_items(ob[i]->query_name())) {
                write(owner+" says: I'm not interested in "+ob[i]->short()+"\n"+
                        "\tGo and see someone who buys "+
                        (string)ob[i]->query_object_type()+".\n");
                continue;
            }

            value = (int)ob[i]->query_value(); 
            number = (int)query_global_economy(ob[i]);

            /* the more he has, the less he wants !! */
            if(number > (MAX_STOCK-1)) {
                writelw(owner +" says: I'm not interested today. I've got too many "+
                        "as it is!\n");
                value /= number;
                return 1;
            }

            else if(number > 6) {
                writelw(owner +" says: These are pretty easy to come by now days. That'll "+
                        "bring the sale price down somewhat.\n");
                value /= number;
            }
            else if(number > 3) {
                writelw(owner +" says: These are pretty common. Not sure if I need one.\n");
                value /= number;
            }
            else {
                writelw(owner +" says: I have just a few in stock. I think I "+
                        "could do with one\n");
                value += random(value/2);
            }



            if(value > MAX_VALUE) value = MAX_VALUE;


            /* Bargaining skill */

            if(random(OWNER_STAT) > random(BARGAIN)) 
                value -= random(value/3); 
            else 
                value += random(value/4); 

            write(owner +" haggles with you over the price of "+
                    (string)ob[i]->short() +".\n"); 
            write(owner +" gives you "+calc_value(value)+" coins for "+
                    (string)ob[i]->short()+".\n"); 

            this_player()->add_money(value);
            this_player()->add_weight((int)ob[i]->query_weight() * (-1));

            if(ob[i]->armour_class()) {
                if(sizeof(all_inventory(STORE_ARMOUR)) > TOTAL_STOCK) {
                    ob[i]->set_sell_destruct(1);
                }
            }

            else if(ob[i]->weapon_class()) {
                if(sizeof(all_inventory(STORE_WEAPON)) > TOTAL_STOCK) {
                    ob[i]->set_sell_destruct(1);
                }
            }
            else {
                if(sizeof(all_inventory(STORE_TREASURE)) > TOTAL_STOCK) {
                    ob[i]->set_sell_destruct(1);
                }
            }
            if(ob[i]->query_sell_destruct()) { 
                write(owner + " hides the valuable item away...\n"); 
                destruct(ob[i]); 
            } 
            else { 
                if(ob[i]->armour_class())
                    move_object(ob[i],STORE_ARMOUR); 
                else if(ob[i]->weapon_class()) 
                    move_object(ob[i],STORE_WEAPON); 
                else 
                    move_object(ob[i],STORE_TREASURE); 
                add_global_economy(ob[i]);
            }
            flag = 1; 
        } 
    }
    if(!flag) write(owner +" isn't interested.\n");
    return 1;
}


status list(string str) {
    status flag;
    string tmp;

    if(!str || str == "all") {
        list("t"); list("a"); list("w");
        return 1;
    }

    else {
        if((str == "armour" || str == "armours" || str == "a") &&
                query_sell_items("Armour")) {
            inventory(STORE_ARMOUR);
            flag = 1;
        }
        else if((str == "weapon" || str == "weapons" || str == "w") &&
                query_sell_items("Weapon")) {
            inventory(STORE_WEAPON);
            flag = 1;
        }
        else if((str == "treasure" || str == "treasures" || str == "t") &&
                query_sell_items("Treasure")) {
            inventory(STORE_TREASURE);
            flag = 1;
        }
        else {
            inventory(STORE_TREASURE);
            flag = 1;
        }
    }

    if(!flag) {
        tmp = implode(sell_items, ", ");
        writelw(owner+" exclaims: Sorry, I've run out of "+tmp+"!\n");
    }
    return 1;
}


status buy(string str){ 
    object ob, *inv; 
    int value, number, i, j, abort;
    string type, *item_check; 
    string verb;

    verb = query_verb();
    if(!present(lower_case(owner))){ 
        write(owner +" is not here right now, so you cannot "+verb
                +" anything.\n"); 
        return 1; 
    } 
    if(!str){ 
        write(capitalize(verb) +" what?\n"); 
        return 1; 
    } 
    ob = present(str,STORE_ARMOUR); 
    if(!ob) ob = present(str,STORE_WEAPON); 
    if(!ob) ob = present(str,STORE_TREASURE); 

    if(!ob) { 
        if(sscanf(str,"%d%s",number,type) || sscanf(str,"%d %s",number,type)) { 
            if(type == "armour" || type == " a" || type == "arm" || type == " armor" 
                    || type == " armour" || type == "a" || type == " arm" || type == "armor") 
                ob = STORE_ARMOUR; 

            else if(type == "weapon" || type == " w" || type == "weap" 
                    || type == " weapon" || type == "w" || type == " weap") 
                ob = STORE_WEAPON; 

            else if(type == "treasure" || type == " t" || type == "treas" 
                    || type == " treasure" || type == "t" || type == " treas") 
                ob = STORE_TREASURE; 

            else{ 
                write(owner+" says: But I don't have that in stock!\n"+
                        "             Perhaps you should try ["+verb+" <number>(a|w|t)]\n"); 
                return 1; 
            } 

            inv = all_inventory(ob);
            item_check = ({});
            ob = 0;

            for(i = 0; i < sizeof(inv); i++) { 
                string tmp;
                int val;

                val = (int)inv[i]->query_max_value(); /* armour value changes */
                if(!val) val = (int)inv[i]->query_value();
                tmp = (string)inv[i]->short() +"#"+ val;
                if(member_array(tmp, item_check) != -1) continue;
                if(++j == number) { 
                    ob = inv[i];
                    break;  
                }
                item_check  += ({ tmp, });

                if(++abort > MAX_LIST_LENGTH) break;
            }
            if(!ob) {
                write(owner+" says: But I don't have that in stock!\n"+ 
                        "             Perhaps you should try ["+ verb +" <number>(a|w|t)]\n"); 
                return 1; 
            }
        }
        else{ 
            write(owner+" says: But I don't have a "+ str +" in stock!\n"); 
            return 1; 
        } 
    } 
    if(!query_sell_items("Armour") && ob->armour_class()) {
        write(owner+" says: Hey, I'm not an armourer. Go there instead.\n");
        return 1;
    }

    if(!query_sell_items("Weapon") && ob->weapon_class()) {
        write(owner+" says: I'm not a weaponsmith. Go there instead!\n");
        return 1;
    }

    if(verb == "browse") {
        write(owner +" shows you the "+ (string)ob->short() +"...\n\n");
        ob->long();
        return 1;
    }

    number = (int)query_global_economy(ob);

    if(number > (MAX_STOCK-1)) {
        writelw(owner +" says: I've got so many of these. Perhaps I'll nock a bit off "+
                "the price for you.\n");
        value -= (value/number);
    }
    else if(number > 6) {
        writelw(owner +" says: There's quite a few of these. You can have it "+
                "for a bit less.\n");
        value -= (value/number);
    }

    else if(number < 4) {
        writelw(owner +" says: Hold on a moment, I think I need a few of those "+
                "so it'll cost you extra today.\n");
        value *= number;
    }


    value = (int)ob->query_value();

    if(random(OWNER_STAT) > random(BARGAIN)) 
        value += random(value/3); 
    else 
        value -= random(value/4); 

    write(owner+" haggles with you over the price of "+ob->short()+".\n"); 


    if((int)this_player()->query_money() < value) { 
        write(owner+" says: You seem to have a cash flow problem!\n"); 
        return 1; 
    } 

    if(!call_other(this_player(),"add_weight",(int)ob->query_weight())){ 
        write(owner+" says: You should gain a bit more muscle before you\n"+ 
                "            buy "+(string)ob->short()+".\n");
        return 1; 
    }  

    say(NAME+" bought a "+ (string)ob->short() +".\n"); 
    write(owner +" takes "+ calc_value(value) +" coins for "+
            (string)ob->short() +"\n");
    move_object(ob,this_player()); 
    this_player()->add_money(-value);     
    remove_global_economy(ob);
    return 1; 
}  


status value(string str){ 
    object ob; 
    int value, difference;

    if(!present(lower_case(owner))){ 
        write(owner +" is not here right now, "+
                "so how can you get him to value anything.\n"); 
        return 1; 
    } 
    if(!str){ 
        write(owner +" asks: Value what?\n"); 
        return 1; 
    } 
    ob = present(str,this_player()); 
    if(!ob){ 
        write(owner+" says: You don't have a "+ str +" to value.\n"); 
        return 1; 
    } 

    value = (int)ob->query_value(); 

    if(!value) { 
        write(owner+" looks at the "+ str +" carefully...\n"+ 
                owner+" says: I'd wouldn't know what to give you for the "+str+"!\n"); 
        return 1;
    } 

    if(random(APPRAISAL) < random(OWNER_STAT))
        value -= random(value/3);

    write(owner +" says: I think that "+calc_value(value)+
            " coins might be a fair price, don't you?\n"); 
    return 1; 
} 



varargs void inventory(object obj, string pager_exit) { 
    object ob, *inv; 
    int i, val, abort;
    string str; 
    string list;
    int cost;
    string *item_list, *item_check;
    int *item_number;
    string sh;
    string tmp, tmp_val, tmp2;

    /*** Lets make sure the shop has at least one object ***/ 

    /* Standard Treasure Items */
    if(query_sell_items("Treasure")) {
        if(!present("torch", STORE_TREASURE)){ 
            move_object(clone_object("objects/torch"),STORE_TREASURE);
        }
        
        /*    
        if(!present("list", STORE_TREASURE)) {
            move_object(clone_object("objects/party_list"),STORE_TREASURE);
        }
        
        if(!present("parchment", STORE_TREASURE)){
            ob = clone_object(TREASURE);
            ob -> set_name("parchment");
            ob -> set_short("A sheet of parchment");
            ob -> set_long(
                    "A fine sheet of parchment. Perhaps it could be used to scribe "+
                    "spells with?\n");
            ob -> set_value(500);
            ob -> set_weight(1);
            move_object(ob, STORE_TREASURE);
            add_global_economy(ob);
        }
        
        if(!present("ore", STORE_TREASURE)) {
            ob = clone_object(TREASURE);
            ob -> set_name("ore");
            ob -> set_short("A hunk of ore");
            ob -> set_long(
                    "It seems to be a fine ore of metal, capable of being refined \n"+
                    "into a fine piece of armour, or perhaps a weapon of some sort.\n");
            ob -> set_value(random(500) + 250);
            ob -> set_weight(2);
            move_object(ob, STORE_TREASURE);
            add_global_economy(ob);
        }

        if(!present("bag", STORE_TREASURE)){ 
            move_object(clone_object("/objects/bag"),STORE_TREASURE); 
        } 
        */
    }


    /* Standard Armour Items */
    if(query_sell_items("Armour")) {
        if(!present("shield", STORE_ARMOUR)){ 
            ob = clone_object(ARMOUR); 
            ob -> set_name("shield"); 
            ob -> set_short("Shield"); 
            ob -> set_long("A wooden shield.\n"); 
            ob -> set_weight(3); 
            ob -> set_value(150); 
            ob -> set_ac(1); 
            ob -> set_type("shield"); 
            move_object(ob, STORE_ARMOUR); 
            add_global_economy(ob);
        }   
    }

        if(query_sell_items("Armour")) {
        if(!present("leather", STORE_ARMOUR)){ 
            ob = clone_object(ARMOUR); 
            ob -> set_name("leather"); 
            ob -> set_short("some patch work leather armour"); 
            ob -> set_long("A set of patch work leathers.\n"); 
            ob -> set_weight(5); 
            ob -> set_value(150);
            ob -> set_armour_material("leather");        
            ob -> set_ac(1); 
            ob -> set_type("armour"); 
            move_object(ob, STORE_ARMOUR); 
            add_global_economy(ob);
        }   
    }
    
    
    /* Standard Weapon Items */
    if(query_sell_items("Weapon")) {
        if(!present("machete", STORE_WEAPON)){ 
            ob = clone_object(WEAPON); 
            ob -> set_name("machete"); 
            ob -> set_alias("machete");
            ob -> set_short("A machete"); 
            ob -> set_long("A poorly crafted machete.\n"); 
            ob -> set_weight(4); 
            ob -> set_wc(10); 
            ob -> set_value(1300); 
            ob -> set_type("slash"); 
            ob -> set_length(24); 
            move_object(ob, STORE_WEAPON); 
            add_global_economy(ob);
        }   

        if(!present("knife", STORE_WEAPON)){ 
            ob = clone_object(WEAPON); 
            ob -> set_name("knife"); 
            ob -> set_short("A pocket Knife"); 
            ob -> set_long("A small pocket knife.\n"); 
            ob -> set_weight(3); 
            ob -> set_class(6); 
            ob -> set_value(110); 
            ob -> set_type("thrust"); 
            ob -> set_length(12); 
            move_object(ob, STORE_WEAPON); 
            add_global_economy(ob);
        }   
    }


    /* here is where files added by the creator, and re-added every time
       someone buys something, lists something again!
     */
    if(sizeof(files)) {
        for(i=0; i<sizeof(files); i++) {
            ob = clone_object(files[i][0]);
            if((string)ob->query_object_type() == "Armour") {
                if(!present(files[i][1], STORE_ARMOUR))
                    move_object(ob, STORE_ARMOUR);
                else
                    destruct(ob);
            }
            if((string)ob->query_object_type() == "Weapon") {
                if(!present(files[i][1], STORE_WEAPON))
                    move_object(ob, STORE_WEAPON);
                else
                    destruct(ob);
            }
            else {
                if(!present(files[i][1], STORE_TREASURE))
                    move_object(ob, STORE_TREASURE);
                else
                    destruct(ob);
            }
        }
        add_global_economy(ob);
    }

    if(!obj) 
        return 0; 
    inv = all_inventory(obj); 

    if(!sizeof(inv)) 
    { 
        string obj_name;
        if(obj->id("treasure")) obj_name = "treasure"; 
        if(obj->id("armour"))   obj_name = "armour"; 
        if(obj->id("weapon"))   obj_name = "weapons"; 
        if(obj_name)
            write(owner+" says: I don't have any "+obj_name+" at the moment.\n"); 
        else
            write(owner+" says: I don't have anything in stock at the moment.\n"); 
    } 
    else
    { 
        list = "";
        if(obj->id("armour")) 
            list = "\n\n              -=[ Armour ]=-\n\n"; 
        if(obj->id("weapon")) 
            list = "\n\n              -=[ Weapon ]=-\n\n"; 
        if(obj->id("treasure")) 
            list = "\n\n              -=[ Treasure ]=-\n\n"; 

        list += "--=[ Item ]=-----------------=[ R.R.P.]=-----=[ Stock ]=---\n"; 
        item_list = ({});
        item_check = ({});
        item_number = ({});

        for(i = 0; i < sizeof(inv); i++) 
        { 
            int j;

            sh = (string)inv[i]->short();
            val = (int)inv[i]->query_max_value(); /* armour value changes */
            if(!val) 
                val = (int)inv[i]->query_value();

            tmp = sh +"#"+ val;

            if((j = member_array(tmp, item_check)) != -1) 
            {
                if(item_number[j] == MAX_STOCK)
                    destruct(inv[i]);
                else
                    item_number[j] += 1;
                continue;
            }

            str = (sizeof(item_list) < 9) ? " " : "";
            str += " "+(sizeof(item_list)+1)+". "+ sh +"                         ";
            str = extract(str,0,30); 
            cost = (int)inv[i]->query_value();
            tmp_val = calc_value(cost);
            sscanf(tmp_val,"%d %s %s",cost, tmp_val, tmp2);

            if(cost < 10)
                str += " ";

            if(cost < 100)
                str += " ";

            str += " "+ cost +" "+ tmp_val +"                                    ";
            str = extract(str,0,49);

            item_check  += ({ tmp, });
            item_list   += ({ str, });        
            item_number += ({ 1, });

            if(++abort > MAX_LIST_LENGTH)
                break;

            for(j = 0; j < sizeof(item_list); j++) 
                list += item_list[j] + item_number[j] +"\n";
        }


        if(i != sizeof(inv)) 
            list += "     **** Truncated ***\n";     

    }  

    ob = clone_object(PAGER);
    ob->page(list,pager_exit);
    return; 
} 


/* If 'list all' is used, page next storage container */

void pager_quit(string fn) {
    switch(fn) {
        case "weapon":
            if(query_sell_items("Weapon")){
                write("list weapon\n");
                inventory(STORE_WEAPON,"weapon");
                break;
            }

        case "treasure":
            if(query_sell_items("Treasure")) {
                write("list treasure\n");
                inventory(STORE_TREASURE);
                break;
            }
    }
}



void set_owner(string owner_name){ 
    object owner_ob;

    if(!stringp(owner_name)) owner_name = "farin";
    if(!owner) owner = capitalize(owner_name); 
    owner_ob = clone_object(MONSTER);
    owner_ob -> set_name(lower_case(owner)); 
    owner_ob -> set_magic_resist(100);
    owner_ob -> set_no_kill_flag(1);
    owner_ob -> set_race("human"); 
    owner_ob -> set_short(owner+", the shopkeeper"); 
    owner_ob -> set_alias("shopkeeper");
    owner_ob -> set_long(owner +" has always run this shop.\n"); 
    owner_ob -> set_al(30); 
    owner_ob -> set_gender(1); 
    owner_ob -> set_level(15); 

    owner_ob -> set_wc(20); 
    owner_ob -> set_ac(18); 
    owner_ob -> set_hp(7050); 
    owner_ob -> load_chat(5,({ 
                owner+" gives you a polite nod.\n", 
                owner+" says: Would you like to buy something?\n", })); 
    owner_ob -> load_a_chat(25,({ 
                owner+" says: You'll never steal my goods!\n", 
                owner+" gives you a wack over the head with his money bag.\n", })); 
    owner_ob -> add_money(1200 + random(800)); 
    move_object(owner_ob, this_object()); 

/*
    if(!present("gully dwarf")) {
        move_object(clone_object("inherit/dwarf"),this_object());
    }
 */
} 


    void add_sell_items(string str) {
        if(!sell_items || !sizeof(sell_items))
            sell_items = ({ });
        sell_items += ({ str, });
    }

status query_sell_items(string str) {
    if(!str) return 0;
    if(!sell_items || !sizeof(sell_items)) sell_items = ({ });
    if(member_array(str, sell_items) != -1) return 1;
    return 0;
}

string *query_all_sell_items() { return sell_items; }


void set_sell_armour()  { return add_sell_items("Armour");   } 
void set_sell_weapon()  { return add_sell_items("Weapon");   }
void set_sell_treasure(){ return add_sell_items("Treasure"); }

string calc_value(int i) {
    int amount;
    string tmp;

    amount = i;
    tmp = "";

    return tmp = (string)MONEY->convert_money(amount);
}

void add_inventory(string file) {
    object ob;
    if(catch(ob = clone_object(file))) {
        write("Error in loading: "+file+"\n");
        return;
    }
    if(!sizeof(files)) files = ({ });
    files += ({ ({ file, (string)ob->query_name(), }), });
    if((string)ob->query_object_type() == "Weapon") {
        move_object(ob, STORE_WEAPON);
    }
    else if((string)ob->query_object_type() == "Armour") {
        move_object(ob, STORE_ARMOUR);
    }
    else {
        move_object(ob, STORE_TREASURE);
    }
    add_global_economy(ob);
}

void set_store_items(int num, string file) {
    int j;
    for(j=0; j<num; j++) 
        add_inventory(file);
}


varargs query_global_economy(object ob) {
    string obType, obName;
    mapping tmpMap;
    int number;

    if(!ob) return global_economy;

    obType = (string)ob->query_object_type();
    if(!obType) obType = "Treasure";

    tmpMap = global_economy[obType];
    if(!tmpMap) return 1;
    obName = ob->query_name();

    number = tmpMap[obName];
    return number;
}




mapping add_global_economy(object ob) {
    string obType, obName;
    mapping tmpMap;
    int number;

    if(!sizeof(global_economy)) global_economy = ([ ]);

    if(!ob) return 0;

    obType = (string)ob -> query_object_type();
    if(!(obName = (string)ob->query_name())) return 0;

    if(!obType) obType = "Treasure";

    if(!global_economy[obType]) global_economy += ([ obType : ([ ]), ]);

    tmpMap = global_economy[obType];
    number = tmpMap[obName];
    number ++;
    tmpMap[obName] = number;
    global_economy[obType] = tmpMap;

    return global_economy;
}


mapping remove_global_economy(object ob) {
    string obType, obName;
    mapping tmpMap;
    int number;

    if(!sizeof(global_economy)) return 0;
    if(!ob) return 0;

    obType = (string)ob -> query_object_type();
    if(!(obName = (string)ob -> query_name())) return 0;

    if(!obType) obType = "Treasure";

    if(!global_economy[obType]) return 0;

    tmpMap = global_economy[obType];
    number = tmpMap[obName];

    if((number--) < 0) number = 0;
    tmpMap[obName] = number;
    global_economy[obType] = tmpMap;

    return global_economy;
}


mapping add_store(string name) {
    if(!store_list || !sizeof(store_list)) store_list = ([ ]);
}

int query_no_fight() { return 1; }
