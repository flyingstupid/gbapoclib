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
    guild_master = clone_object(MONST+"/evilknight");
    move_object(guild_master,this_object());
  }


  load_door(({
        "file", "d/affils/ships/island/cliff1",
	"long", "A door made from a single piece of steel.\n",
	"direction", "west door",
  }));

  if(arg) return;
  set_short("the temple of Tiamut");
  set_long(
"Before you looms the huge presence of Tiamut, the queen of darkness, \n"+
"in dark marble, before an altar of dark silver. Her six heads rear  \n"+
"up at you, snearing and hissing, defying the onlooker to step toward\n"+
"her image. Two rows of blue marble pillars stand each side of a deep\n"+
"red rug that leads to the altar. \n");


  set_items(({
	"tiamut#heads#head",
	"Tiamut has five heads; black, red, green, white and blue. Each\n"+
	"represent the colours of the chromatic dragons - the evil ones.\n"+
	"Tiamut is their queen, revered on MAGIA as the temptress.\n",
	"altar",
	"It is made from some dark silver metal. On its sides are symbols\n"+
	"of dragonkind, magic and of power. It would be foolish to defile\n"+
	"such a powerful thing",


	"symbol#symbols",
	"They are runes of power",

	"columns#column",
	"They lead the way to the altar, where the priests of Tiamut pray",

  }));


  set_weather(2, 0, 0);
  set_affiliation_name("follower of the Tiamut, Queen of Dragons");
  set_affiliation_file("tiamut");
  set_affiliation_sponsor("Tiamut");
  set_skills_file("/obj/skills/affils/tiamut");

  set_no_fight(1);
  set_exits(({
  }));
  set_guild_name("No"); /* normal guild */
  set_classes(({
   "general",        ({
                       "climb", "swim",
                     }),

   "primary",        ({
			"wisdom",
/* can't advance intelligence here "intelligence",
 */
                       "dexterity", "strength", 
                       "combat",   "constitution", 
/* can't advaNCE charisma here "charisma",
 */
                     }),

   "cleric",         ({
                       "healing sphere", "necromancy sphere", "combat sphere",
                       "stellar sphere", "protection sphere", "nature sphere",
                       "divination sphere",
                     }),

   "fighter",        ({
                       "multi attack", "multi opponent", "two weapon",
                       "unarmed",     "armouring",      "weapon smith",
                     }),

/***
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
  if(this_player()->query_ghost())
    this_player()->toggle_ghost();
  return 1;
}

int query_no_fight() { return 1; }

void admit_fn(object ob) {
  ob->set_max_combat((int)ob->query_max_combat() + 2);
  ob->save_me();
}
