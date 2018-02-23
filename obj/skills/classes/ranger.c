/***************************************************************************/
/* Ranger's Guild Object. v1.01 
 * Angel, August 1996 for Heaven7 development
 */


/***************************************************************************/
/* defines */

#define TRACK_MOD	4  /* adding onto searching in rooms */

#include <tell.h>

#define GOD                   "Antaaries"   /* goddess of the forest       */
#define RANGER_ALIGNMENT      10            /* min alignment for powers    */

#define R_WC_BONUS		  2           /* standard wc bonuses if good */
#define L_WC_BONUS		  2
#define TWO_WEAPON_LENGTH_BONUS 5           /* bonus for w lengths         */



static status flag;
#define WC		     (int)environment()->query_wc()
#define ALIGNMENT          (int)environment()->query_alignment()
#define THIS_PLAYER_WIZ    ((this_player()->query_security_level()) ? 1 : 0)


/***************************************************************************/
/* fn configs */
int calc_racial_hatred_bonus(); 
void kill_ranger();

/*********************************************************************/
/* queries */
string query_name()        { return "ranger_guild_object"; }
string query_object_type() { return "guild_object";         }

status query_auto_load()   { return 1;                     }

int query_search_bonus() {
  return ((int)environment()->query_tracking()/TRACK_MOD);
}

int right_weapon_class_bonus() {
  object weapon;
  weapon = (object)environment()->query_right_weapon();
  if(!weapon) return 0;
  return (weapon && (ALIGNMENT > RANGER_ALIGNMENT)) ? 
         (calc_racial_hatred_bonus() + R_WC_BONUS) : 0;
}

int left_weapon_class_bonus() {
  object weapon;
  weapon = (object)environment()->query_left_weapon();
  return (weapon && (ALIGNMENT > RANGER_ALIGNMENT)) ? L_WC_BONUS : 0;
}

int two_weapon_bonus() {
  return TWO_WEAPON_LENGTH_BONUS;
}


int calc_racial_hatred_bonus() {
  string *hated_races;
  string tmp1, tmp2, race;
  object attacker;

  hated_races = ({
	"bugbear", "cyclops", "dune stalker", "ettin", "flind",
	"giant", "gibberling", "gnoll", "goblin", "grimlock",
	"hobgoblin", "kobold", "meazel", "norker", "ogre",
	"ogre mage", "orgrillon", "orc", "quaggoth", "tasloi",
	"troll", "xvart",
  });
  
  attacker = (object)environment()->query_attacker();
  if(!attacker) return 0;
  race = (string)attacker->query_race();
  if(!race) return 0;

  if(sscanf(race, "%s %s", tmp1, tmp2)) {
    if(tmp2) race = tmp2;
  }


  return (member_array(race, hated_races) == -1) ? 0 : (WC*2);
}

/****************************************************************************
 * A paladin can wield any type of weapon, but certain types gain them 
 * WC bonuses.
 */

status check_alignment() {
  if(ALIGNMENT < RANGER_ALIGNMENT) return 1;
  return 0;
}

void process_alignment(int amount) {
  if(!flag) {
    flag = 1;
    call_out("process_alignment_fun", 1, amount);
  }
}

/* Call out for the effect only */
void process_alignment_fun(int amount) {
  string *message, msg;

  message = ({
     "You donot feel that was a good and wise thing to do.\n",
     "You feel that was not a noble act.\n",
     "You have displeased "+GOD+" with that action.\n",
      GOD+" regards your act with distain.\n",
     "You have discraced the name of "+GOD+" with that action.\n",
     "You feel the wrath of "+GOD+" upon you!\n",
  });

  if(check_alignment()) return;
  if((ALIGNMENT - amount) > 50)
    msg = message[0];
  else if((ALIGNMENT - amount) > 0)
    msg = message[1];
  else if((ALIGNMENT - amount) > -50)
    msg = message[2];
  else if((ALIGNMENT - amount) > -100)
    msg = message[3];
  else if((ALIGNMENT - amount) > -150)
    msg = message[4];
  else
    msg = message[sizeof(message)-1];

  tell_object(environment(), msg);
  if(msg == message[sizeof(message)-1]) {
    say(environment()->query_name()+" is struck with a bolt of lightning "+
     "from the heavens!\n",environment());
    kill_ranger();
  }
}

/**********************************************************************
 * A Ranger must always be pure of heart and noble of stature
 * hence, his alignment must never be 'evil'. If he becomes
 * evil, then the wrath of his God falls upon him, and he is stuffed.
 * Basically he turns into a standard fighter..and gets some damage
 */
void kill_ranger() {
  if(!environment()) return;
  environment()->set_alignment(RANGER_ALIGNMENT);
  environment()->set_guild_string(0);
  environment()->remove_class("ranger");
  environment()->add_class("fighter");
  environment()->clear_cleric();
  environment()->clear_mage();

  write(GOD+" transforms you, and removes your special powers.\n");

  environment()->hit_player(20); /* only a little zap */

  say(GOD+"'s wrath has been appeased.\n",environment());
  flag = 0;
}


string extra_look(status wiz) {
  if(this_player() != environment())
    return (string)environment()->query_name()+" is a Ranger who follows "+GOD;
  else
    return "You are a Ranger who follows the ways of "+GOD;
}

void init_arg() {
  call_out("ranger_bonuses", 2);
}

void ranger_bonuses() {
  if(environment()) {
    clone_object("obj/shadows/ranger")->ranger_aura(environment());
    environment()->add_spell_immunity("cold");
  }
}

void guild_death() {
  string *skills;
  int i;

   skills = ({
	"tracking",
	"two_weapon", "multi_opponent", "multi_attack",
	"charm", "conjuration", "nature_sphere",
  });

  for(i=0; i<sizeof(skills); i++) {
    call_other(environment(), "set_"+skills[i], 
      call_other(environment(),"query_"+skills[i]-1));
  }
}

status id(string str) {
  return str == "ranger"      ||
         str == "guild_object";
}

status drop(string quit) { return 1; }
status get(string quit)  { return 1; }

void init() {
  if(present("guild_object 2", environment()))
    destruct(this_object());
}
