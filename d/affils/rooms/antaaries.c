/* The Clerics of the All-God */
/* This is an affiliation which grants such priests a little different
 * things in the way of their prayers
 */

#include <mudlib.h>
#define PATH	"d/coronos/w/angel/city/temple"
#define MONST	"d/coronos/w/angel/city/monst"


inherit AFFILIATION;
inherit GUILD;

void reset(status arg) {
  guild::reset(arg);
  affils::reset(arg);

  if(!guild_master) {
    guild_master = clone_object(MONST+"/stella");
    move_object(guild_master,this_object());
  }


  if(arg) return;
  set_short("a forest clearing");
  set_long(
	"The forest parts slightly, the trees almost swaying left and \n"+
	"right to make way for your comming. In the midst of the circle\n"+
	"of grand ancient oaks is a small lake of crystal clear water, \n"+
	"fed from a river flowing from the west. Before the lake is a  \n"+
	"few stones placed at the shore line; a small altar of some    \n"+
	"description. All is peaceful and quite here.\n");


  set_items(({
	"tree#trees#oak#oaks",
	"They tower nearly 80 feet above you, stretching toward the sky",
	"water#lake",
	"The water of the lake reflects the tall trees of the grove \n"+
	"upon it's surface, giving it the impression they are bowing\n"+
	"before the small alter at it's side",

	"river", "A small river of fresh water. It's not flowing very quickly",
	"stones#altar",
	"The alter has some berries and fruits upon it. Into the stone \n"+
	"is carved four leaves pointing downward, held at the tip by a \n"+
	"garland of ivy. It is the holy symbol of the goddess of nature",

	"shore", "There is an altar there",
  }));

  set_weather(2, 0, 0);
  set_affiliation_name("follower of Antaaries");
  set_affiliation_file("antaaries");
  set_affiliation_sponsor("Antaaries");
  set_skills_file("/obj/skills/affils/antaaries");

  set_no_fight(1);
  set_exits(({
	"d/coronos/w/angel/farms/plains/ranger", "south",
  }));
  set_guild_name("No"); /* normal guild */
  set_classes(({
/*
   "general",        ({
                       "climb", "swim",
                     }),
*/

   "primary",        ({
                       "intelligence", "wisdom",
/* can't raise these here....
                       "dexterity", "strength", 
                       "combat",   "constitution", "charisma",
 */
                     }),

   "cleric",         ({
                       "healing sphere", "necromancy sphere", "combat sphere",
                       "stellar sphere", "protection sphere", "nature sphere",
                       "divination sphere",
                     }),

/* these are alternatives....
   "fighter",        ({
                       "multi attack", "multi opponent", "two weapon",
                       "unarmed",     "armouring",      "weapon smith",
                     }),

   "thief",          ({
                       "stealth", "locks", "steal", "backstab",
                        "appraisal", "traps",
                     }),


   "mage",           ({
                       "illusion", "charm", "conjuration", "abjuration",
                       "necromancy", "evocation", "divination", "alteration",
                     }),
 */
  }));
  set_exp(({
                  0,    1014,    1522,    2283,    3425,    5138,
               7707,   11561,   17341,   26012,   39018,   58527,
              87791,  131687,  197530,  296296,  444444,  666666,
            1000000, 1500000, 2000000, 2500000, 3000000, 3500000,
            4000000, 4500000, 5000000, 5500000, 6000000, 6500000,
  }));
  set_skill_exp(({
                 30,      50,      75,     100,     175,     250,
                400,     600,     900,    1200,    2000,    3000,
               4500,    6500,   10000,   15000,   20000,   30000,
              50000,   75000,  100000,  125000,  150000,  175000,
             200000,  225000,  250000,  275000,  300000,  325000,
  }));
  set_titles(({ 
                /* neuter titles */
            ({ }),


         /* male titles */ 
           ({
         "the Utter Newbie",                             
         "the Humble Acolyte",                        
         "the Devout Acolyte",                        
         "the Humble Decon",                          
         "the Devout Decon",                          
         "the Humble Servant",                        
         "the Devout Servant",                        
         "the Humble Disciple",                       
         "the Devout Disciple",                       
        "the Humble Adept",                          
        "the Devout Adept",                          
        "the Humble Curate",                         
        "the Devout Curate",                         
        "the Humble Canon",                         
        "the Devout Canon",                         
        "the Humble Preceptor",                     
        "the Devout Preceptor",                     
        "the Humble Priest",                   
        "the Devout Priest",                  
        "the Humble Patriarch",                    
        "the Devout Patriarch",                    
        "the Humble Clerist",                      
        "the Devout Clerist",                      
        "the Humble High Clerist",                 
        "the Devout High Clerist",               
        "the Humble High Priest",                  
        "the Devout High Priest",                  
        "the Humble Prophet",                      
        "the Devout Prophet",                      
     
           }),

          /* female titles */
           ({
         "the Utter Newbie",
         "the Humble Acolyte",
         "the Devout Acolyte",
         "the Humble Decon",
         "the Devout Decon",
         "the Humble Servant",
         "the Devout Servant",
         "the Humble Disciple",
         "the Humble Disciple",
         "the Devout Disciple",
        "the Humble Adept",
        "the Devout Adept",
        "the Humble Curate",
        "the Devout Curate",
        "the Humble Canon",
        "the Devout Canon",
        "the Humble Preceptor",
        "the Devout Preceptor",
        "the Humble Priest",
        "the Devout Priest",
        "the Humble Patriarch",
        "the Devout Patriarch",
        "the Humble Clerist",
        "the Devout Clerist",
        "the Humble High Clerist",
        "the Devout High Clerist",
        "the Humble High Priest",
        "the Devout High Priest",
        "the Humble Prophet",
        "the Devout Prophet",
           }),
  }));

  /*** get a new pretitle one in four levels after 30 ***/
  set_pretitles(({
                  ({}), /* no neuter pretitles */

                   /* male pretitles */
                  ({
                        "Captain",
                          "Major",
                        "Colonel",
                        "General",
                       "Marshall",
                "Knight Marshall",
                            "Sir",
                           "Lord",
                        "Baronet",
                          "Baron",
                       "Viscount",
                          "Count",
                        "Marquis",   
                           "Duke",
                     "Grand Duke",
                       "Archduke",
                         "Prince",
                   "Crown Prince",
                           "King",
                        "Emperor",
                       "Overlord",
             }),

                 /* female pretitles */
             ({
                        "Captain",
                          "Major",
                        "Colonel",
                        "General",
                       "Marshall",
                "Knight Marshall",
                         "Madame",
                           "Lady",
                        "Baronet",
                       "Baroness",
                    "Viscountess",
                       "Countess",
                       "Marquise",   
                        "Duchess",
                  "Grand Duchess",
                    "Archduchess",
                       "Princess",
                 "Crown Princess",
                          "Queen",
                        "Empress",
                       "Overlady",
            }),
  }));
}

void init() {
  affils::init();
  guild::init();


/*
  add_action("pray",   "pray");
  if(guild_master) {
    object attacker;

    if((attacker = (object)guild_master->query_primary_attack())) {
      if(present(attacker, this_object())) {
        call_out("no_guild_mess",1,this_player());
        return;
      }
    }
  }
*/
}

void no_guild_mess(object ob) {
  if(!ob) return;
  tell_object(ob, guild_master->query_name() +" is busy defending "+
                  guild_master->query_possessive() +"self.\n");
  tell_object(ob,capitalize((string)guild_master->query_possessive()) +
                 " is too busy to train anybody.\n");
}


status pray() {
  this_player()->toggle_ghost();
  return 1;
}

int query_no_fight() { return 1; }

void admit_fn(object ob) {
}
