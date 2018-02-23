#pragma strict_types
#pragma save_types
#pragma combine_strings

#include <mudlib.h>
#include <linewrap.h>
inherit LIVING;
inherit ACTIONS;
inherit BINCMD;

#include <player.cfg>

inherit COLOR_OBJ;

#include <player.spc>
#include <levels.h>
#include <ansi.h>
#include <bad_file.h>

// MCCP support added by Arron Cusimano (mordain)  14aug04
#ifdef __MCCP__
#include <sys/telnet.h>
#endif

#define description    long_desc
#define invis_name     alt_name
#define plan           extra_info

#ifdef PARTY_DAEMON
string party;               /* the name of the party u are in */
#endif /* PARTY_DAEMON */

#ifdef PING_PONG
object pinger;
#endif

#ifdef PURGE
status purge;               /* for funny things to happen if we get open! */
#endif /* PURGE */

string lastname;             /* last name of the player's character */
string special_title;        /* special titles for Rp stuff          */
string birth_date;	      /* when the player was created!         */
string spouse;              /* person we are married to */
string realname;            /* persons real name */  
string email;               /* eMail address of player */  
int last_login_time;        /* int time */
string last_login;          /* ctime() */
string called_from_ip;      /* IP number was used last time */  
string enter_room;          /* optional room to log into - for guilds */  
#ifdef RPG
string ooc_enter_room;      /* room player was in before going -ooc */
#endif /* RPG */

int security_level;         /* access privileges */ 

static object i_initiated_attack;  /* who made an attack */

string pretitle;            /* our rank - lady, lord, king etc. */
string title;               /* Our official title. Wiz's can change it. */  
string al_title;            /* alignment title 'good','bad' etc. */
string password;            /* crypted password. */  

mapping player_info;         /* so we can store misc. info in the player */

int savings;                /* money in bank */
int total_exp;              /* All the exp a player has ever earned */ 

int enhanced;               /* 1 if the player is medic enhanced, 0 if not*/
int intoxicated;            /* How many ticks to stay intoxicated. */
int stuffed;                /* How many ticks to stay stuffed */  
int soaked;                 /* How many ticks to stay soaked */  
int scar;                   /* Number of scars */
int tot_value;              /* Saved values of this player. */  

string guild_string;        /* guild string */  
string *affiliations;       /* an array of RP things u belong to */

string *alias_commands;     /* list of alias commands a player can use */
mixed *autoload;            /* list of autoloaded abjects */

#ifdef SAVE_OBJECTS_ON_QUIT
mixed *saved_items;
#endif /* SAVE_OBJECTS_ON_QUIT */

status ansi_on;             /* 1 == don't filter ansi characters */
string URL;                /* Player's Homepage URL */


#ifdef QUEST_ROOM

int quest_points;           /* points achieved doing quests */
string *quests;             /* quests completed             */
string current_quest;       /* quest that must be completed before next */

#endif /* QUEST_ROOM */

/* logon stuff */

static int password_check;  /* Gives you 3 tried if you forget your password*/
static object other_copy;   /* other me when logging in */


/* describe & chfn & plan & suicide */

static string new_text;  
static int line;  

static string manual_dir;  /* just for the help|manual thing */

static int time_to_save;    /* Time to autosave. */  
static status do_cmd_on;    /* stops loops between aliases & 'do' cmds */

static int headache;        /* should work something better */  
static int max_headache;
static status entering; /* Tests whether move into room was an enter to mud */

string *channels; /* this no only includes standard mud chat lines, but
		     also can include intermud if/when it is installed */


/************************************************************************/
/* these should be put in /include/fn_specs/player_fn.spc */

status ansi_on();


/************************************************************************/
/* Normal commands for   players and wizards alike 8) */  

void add_standard_commands() {  

    add_action (  "Quit",                     "quit"    );  
    add_action (  "Quit",                     "Quit"    );
    add_action (  "communicate",              "say"     );  
    add_action (  "communicate",              "'", 1    );  
    add_action (  "change_language",          "speak"   );  

    /* Note that these are still used for putting/giving money */
    add_action (  "put",                      "put"     );  
    add_action (  "pick_up",                  "get"     );  
    add_action (  "pick_up",                  "take"    );  
    add_action (  "drop_thing",               "drop"    );  
    add_action (  "give_object",              "give"    );

    add_action (  "change_password",          "password");  
    add_action (  "do_cmd",                   "do"      );

    add_action (  "command_centre",           "",1);

    add_action (  "suicide",                  "suicide" );
    
#ifdef __MCCP__
    add_action("start_mccp", "mccp");
#endif
}  

/****************************************************************************/
/* reset */

void reset(status arg) {  
	string fname;
	string tmp;
	int i;
	::reset(arg);
	if(arg) return;


	if(name) return;
	level = -1;  
	affiliations = ({ });
	name = "logon";  
	channels = ({ "OOC", });
	lastname = "";
	special_title = "";
	title = "the Utter Newbie";  
	description = "";  
	plan = "";  
	guild_string = "No";  
	pretitle = "";  
        birth_date = (string)call_other("/obj/weather", "query_mud_date");
	email = "none";
	msgin = "arrives";
	msgout = "leaves";
	al_title = "(Wandering)";  
	right_wc = WEAPON_CLASS_OF_HANDS;
	alias_commands = ({});
	cmd_paths = ({ "/bin/player/", "/bin/std/", "/bin/skills/classes/fighter/", });
#ifdef QUEST_ROOM
	quests = ({});
#endif /* QUEST_ROOM */

	if(!sscanf(file_name(this_object()),"%s#%d", fname,i)) return;

	if(!(fname == PLAYER ||
	    fname == WIZARD ||
	    sscanf(fname, RACE_DIR+"%s", tmp))) {
	    illegal_patch("Inherited "+file_name(this_object()));  
	    destruct(this_object());
	    return;
	}
	if(previous_object()) {
	    if((previous_object() == this_player() || secure(SEC5))
	      && query_ip_number(this_player()) && query_ip_number(previous_object())){
		if((other_copy = (object)previous_object()->query_other_copy())) {
		    name = (string)previous_object()->query_name(1);
		    exec(this_object(),previous_object());
		    logon9_throw_out_other_copy("y");
		    return;
		}
	    }
	}
	if(creator(this_object())) {
	    illegal_patch("Cloned "+file_name(this_object()));  
	    destruct(this_object());  
	    return;
	}
    }  

    /*************************************************************************/
    /* IDENTIFY the player */

    status id(string str) { 
	if(str == "PLAYER") return 1;
	if(this_player() != this_object())
	    if(query_invis()) {
		if(this_player()) {
		    if((int)this_player()->query_security_level() < security_level) {
			return 0;
		    }
		    else if(!this_player()->query_security_level()
		      && random((int)this_player()->query_intelligence())
		      < random(query_invis()+1)){
			return 0;
		    }
		}
	    }
	return str == query_name(1)
	|| str == query_name()
	|| str == lower_case(query_name());
    }


    /**************************************************************************/
    /* short */

    string short(status wiz) { 
	string str; 

#ifdef RPG
#endif /* RPG */


	str = "";
	if(query_invis() && this_player() != this_object()) {
	    if((int)this_player()->query_security_level() < query_security_level()) {
		return 0;
	    }
	    else if(sizeof(compare("intelligence","invis",({ this_object(),})))) {
		return 0;
	    }
	    str += "#";
	}
	if(!query_disguise_on())
	    str += (pretitle != "") ? " "+pretitle+" " : "";

	str += query_name();
	if(query_disguise_on()
	  && !sizeof(compare("intelligence","disguise",({ this_object(),})))) {
	    str += "??";
	}
	if(!query_security_level() && !query_disguise_on()) {
	    str += " "+query_lastname()+" ";
	    if(strlen(special_title)) str += special_title;
	    else str += title;
	}

	else {
	    str += (this_object()->query_edit())
	    ? " "+ (string)this_object()->query_edtitle()
	    : " "+  (query_security_level() ? query_title()+" "+al_title :"");
	}

	if(!query_ip_number(this_object())) str = " A statue of "+ str; 
	return str;
    } 

    /*************************************************************************/
    /* sets */

mapping set_player_info(mapping map) {
  if(!map) player_info = ([ ]);
  if(!player_info) player_info = ([ ]);
  return (mappingp(map) ? player_info = map : 0);
}


    int i_light(int s) { return set_light(s); }

    string * set_alias_commands(string *s) { return alias_commands = s; }
    int set_ansi(int s) { return ansi_on = s ; }
    object set_pinger(object s) { return pinger = s ; }
    string set_ooc_enter_room(string n) { return ooc_enter_room = n; }
    string set_name(string n)  { return ""; /* disable */ }
    string set_id(string n)    { return ""; /* disable */ }
    string set_short(string n) { return ""; /* disable */ }
    string set_long(string n)  { return ""; /* disable */ }

    string set_title(string t)    { return title    = (t) ? t : ""; }
    string set_special_title(string t) { return special_title = (t) ? t : ""; }
    string set_pretitle(string t) { return pretitle = (t) ? t : ""; }
    string set_al_title(string t) { return al_title = (t) ? t : ""; } 
    string set_spouse(string t)   { return spouse = (t) ? t : 0;    }
    string set_lastname(string l) { return lastname = (l) ? l : ""; }

    string set_manual_dir(string s) { return manual_dir = (s) ? s : 0; }


#ifdef PARTY_DAEMON
    string set_party(string s)    { return party = (s) ? s : 0;     }
#endif /* PARTY_DAEMON */


    string set_enter_room(string str) {   
	return enter_room = (!str) ? "" : ((FILE_SIZE(str+".c") > 0) ? str : "");
    }  

    int set_intoxicated(int i)     { return intoxicated = i; } 
    int set_stuffed(int i)         { return stuffed = i;     }
    int set_enhanced(int i)        { return enhanced = i;    }
    int set_soaked(int i)          { return soaked = i;      }
    int set_headache(int i)        { return headache = i;    }
    int set_scar(int i)            { return scar = i;        }  


    string set_guild_string(string s) { return guild_string = (s) ? s : "No"; }
    string set_email(string s)        { return email = (s) ? s : "none";     }
    string set_description(string s)  { return description = (s) ? s : "";   }
    string set_plan(string s)         { return plan = (s) ? s : ""; }
    int set_time_to_save(int i)       { return time_to_save = i;    }


    status set_start() {
	if(set_enter_room(file_name(environment()))) {
	    write("You will now enter "+ MUD_NAME +" into this room.\n");
	}
	else {
	    write("Cannot set enter to this room.\n");
	}
	return 1;
    }
    string set_URL(string arg) { return URL = arg; }
    string set_realname(string s) { return realname = s; }

    /***************************************************************************/
    /* querys */

mapping query_player_info(string key) {
  if(!player_info) player_info = ([ ]);

  if(key) 
    return (member(player_info, key)) ? player_info[key,0] : 0; 
  else
    return player_info;
}

    string * query_alias_commands() { return alias_commands; }
    object query_pinger() { return pinger; }
    string query_ooc_enter_room() { return ooc_enter_room; }
    string query_plan()       { return plan; }
    string query_realname()   { return realname;  }  
    string query_lastname()    { return lastname;  }
    string query_last_login() { return ctime(last_login_time); }  
    string query_enter_room() { return enter_room; }  
#ifdef PARTY_DAEMON
    string query_party()      { return party;      }
#endif /* PARTY_DAEMON */

#ifdef NO_SHADOWS
    nomask status query_prevent_shadow() { return 1; }  
#endif

    string query_email()      { return email;  }  

    string query_al_title()   { return al_title;    }  
    string query_title()      { return title;       }  
    string query_special_title(){ return special_title;   }
    string query_desc()       { return description; }  
    string query_spouse()     { return spouse;      }

    string query_manual_dir() { return manual_dir;  }
    string query_birth_date(){ return birth_date; }


    int query_total_exp()    {  return total_exp;   } 
    int query_savings()      {  return savings;     }
    int query_intoxication() {  return intoxicated; }  
    int query_stuffed()      {  return stuffed;     }
    int query_enhanced()     {  return enhanced;    }
    int query_soaked()       {  return soaked;      }  

    string query_guild_string() { return guild_string; }  

    object query_other_copy()   { return other_copy; }
    string query_URL() { return URL; }

    object query_i_initiated_attack() { return i_initiated_attack; }
    object set_i_initiated_attack(object ob) { return i_initiated_attack = ob; }


    /*************************************************************************/
    /* heart beat */

    static void heart_beat() {   
	int i;

	age += 1;   
	if(ghost) return;   
	dead = ghost;   
	if(age > time_to_save) {   
	    if(!secure(SEC1)) {   
		if(!brief) write("Autosave.\n");   
		save_me(1);   
	    }   
	    time_to_save = age + SAVE_TIME;   
	}   
	if(!query_ip_number(this_object())) {   
	    say(query_name()+" gives a sudden cry as "+ query_pronoun() +
	      " turns to stone!\n");
	    set_heart_beat(0);   
	    call_out("Quit",3600,1);   
	    return;   
	}   
	if(!secure(SEC1)) {
	    if(query_idle(this_object())/60 >= 30) {   
		if(name == "monger") return;
		tell_object(this_object(),"You have been idle too long.\n"+   
		  "You have left the world.\n");   
		say(query_name()+ " is struck by a lightning bolt and vanishes!\n"); 

		Quit();   
		return;   
	    }   
	}
	if(intoxicated && !random(40)) {   
	    int n;

	    n = random(7);   
	    if(n == 0) {   
		say(query_name() + " hiccups.\n");   
		write("You hiccup.\n");   
	    }   
	    else if(n == 1) {   
		say(query_name() + " almost falls, but takes a step and recovers.\n"); 

		write("You stumble.\n");   
	    }   
	    else if(n == 3) {   
		write("You feel drunk.\n");   
		say(query_name() + " looks drunk.\n");   
	    }   
	    else if(n == 5) {   
		say(query_name() + " burps.\n");   
		write("You burp.\n");   
	    }   
	}   
	if(!random(HEAL_HP_PERIOD)) {   
	    if(hp < max_hp) {   
		hp += (1 + constitution/6);   
		if (intoxicated) hp += 2;
		if (soaked)      hp += 1;
		if (stuffed)     hp += 1;
		if(hp > max_hp) hp = max_hp;   
	    }
	    if(headache) {   
		headache -= 1;   
		if(!headache) 
		    tell_object(this_object(),"You no longer have a headache.\n");   
	    }   
	    if(intoxicated) {   
		intoxicated -= 1;   
		if(!intoxicated) {   
		    headache = max_headache;   
		    max_headache = 0;   
		    tell_object(this_object(),
		      "You suddenly without reason get a bad headache.\n");   
		    if((hp -= 3) < 0) hp = 0;   
		}   
	    }   
	    if(stuffed) {   
		stuffed -= 1;
		if(!stuffed) tell_object(this_object(),"You start to feel hungry.\n"); 

	    } 
	    if(soaked) {   
		soaked -= 1;   
		if(!soaked) tell_object(this_object(),"You begin to feel thirsty.\n"); 
	    }
	}
	for(i = sizeof(classes); i--; ) {
	    call_other(this_object(),"heal_"+ classes[i], 0);
	}
	if(!(dead || ghost)) attack();
	if(primary_attack && present(primary_attack,environment()) && hp < whimpy){
	    random_move();
	}
    }   

    /**************************************************************************/
    /* used by help function to validate access to help data */

#define NO_ACCESS ({\
	"efun", "efun32", "efun321",\
	"driverfn", "driver", "compatfn",\
	"creator",\
  })

    status valid_help(string *subtopics) {
	int i;

	if(security_level > SEC0) return 1;
	for(i = 0; i < sizeof(NO_ACCESS); i++) {
	    if(member_array(NO_ACCESS[i], subtopics) != -1) return 0;
	}
	return 1;
    }


    nomask varargs string valid_write(string path,string call_fun) { 
	object caller;

	if(path[0] != '/') {
	    path = (string)this_object()->make_path(path);
	}
	return (string)MASTER->valid_write(path,0,call_fun,caller);
    } 

    nomask varargs string valid_read(string path,string call_fun) { 
	object caller;

	if(path[0] != '/') {
	    path = (string)this_object()->make_path(path);
	}
	return (string)MASTER->valid_read(path,0,call_fun,caller);
    }

    /***************************************************************************/
    /*                   Player Actions                                        */
    /***************************************************************************/

#ifdef RPG
    status check_ooc() {
	if(this_player()->query_security_level() >= 20) return 0;
	if((status)environment(this_player())->query_ooc_room()) {
	    write("That action is not available while you are out of character.\n");
	    return 1;
	}
	return 0;
    }

#endif /* RPG */


    /***********************************************************************/
    /* ansi filters on communication stuff */

    status ansi_on() { return ansi_on; }


    /***************************************************************************/
    /* change password */

    static status change_password() {
	if(password) {
	    write("Old Password > ");
	    input_to("change_password1",1);
	    return 1;
	}
	change_password1("");
	return 1;
    }


    static void change_password1(string str) {
	if(password && password != crypt(str, password)) {  
	    write("\nWrong old password.\n");  
	    return;  
	}  
	password = 0;  
	input_to("change_password2", 1);  
	write("New password > ");  
	return;  
    }   

    static void change_password2(string str){  
	if(!str || str == "") {  
	    change_password1("");  
	    return;  
	}  
	if(!password) {  
	    password = str;  
	    input_to("change_password2", 1);  
	    write("Again > ");  
	    return;  
	}  
	if(password != str) {  
	    write("\nStart Again!!\n");
	    password = 0;
	    change_password1("");  
	    return;  
	}  
	password = crypt(password, 0); /* Generate new seed */  
	write("\nPassword change Successfull.\n");  
	save_me(0);  
    }  


    /***************************************************************************/
    /* suicide */

    static status suicide() {
	if(level < 2) return 0;
	tell_object(this_object(),
	  "The suicide command removes your character, and Banishes \n"+
	  "you name. No one, not even yourself, will be able to use \n"+
	  "that name again.\n");
	write("To continue enter password> ");
	input_to("pass1",1);
	return 1;
    }

    static void pass1(string str) {
	int old_sec_level;
	if(password != crypt(str, password)) {  
	    write("\nWrong password.\n");  
	    return;
	}
	line = 1;  
	new_text = "";  
	input_to ("suicide_note");  
	write ("\nEnter your Suicide Note.  End with '**', abort with '~q'.\n");  
	write ("1] ");  
	return;  
    }  

    static void suicide_note(string arg) {  
	if(arg == "~q") {  
	    write ("Suicide aborted.\n");  
	    return;  
	}  
	if(arg == "**") {  
	    write("Suicide Note:\n"+ new_text+"\n"); 
	    do_suicide(new_text);  
	    return;  
	}  
	new_text = new_text+arg+"\n";  
	write (++line+"] ");  
	input_to ("suicide_note");  
    }  

    static void do_suicide(string note) {
	string txt;
	int old_level;

	save_object("/"+ SAVE_BANISH + query_name(1));
	write("Suiciding......\n");
	set_heart_beat(0);
	rm(SAVE_PLAYER+query_name(1)+".o");
	rm(SAVE_WIZARD+query_name(1)+".o");
# ifdef LOG_SUICIDE
	log(LOG_SUICIDE,note,0);
# endif
	shout(query_cap_name()+" has just Suicided.\nMay "+
	  query_possessive()+" Rest in Peace.\n");
	write("You Die!\n");
	destruct(this_object());
    }   


    /*************************************************************************/
    /* change disguise */

    status change_disguise(string str) {
	string tmp;


#ifdef RPG
	if(check_ooc()) return 1;
#endif /* RPG */



	if(str) {
	    str = lower_case(str);
	    if(!bad_file(str, ({ "-", "_", ".", }))
	      && !(FILE_SIZE("/"+SAVE_FIRST+str+".o") > 0
		|| FILE_SIZE("/"+SAVE_PLAYER+str+".o") > 0
		|| FILE_SIZE("/"+SAVE_WIZARD+str+".o") > 0
		|| FILE_SIZE("/"+SAVE_NO_BANISH+str+".o") > 0
		|| FILE_SIZE("/"+ SAVE_BANISH + str +".o") > 0)) {
		if(primary_attack && present(primary_attack,environment())) {
		    write("You cannot disguise yourself when you are fighting.\n");
		    return 1;
		}
		write("You disguise yourself as "+capitalize(str)+".\n");
		set_alias_name(capitalize(str));
		disguise_on = 1;
	    }
	    else {
		write("You cannot disguise yourself as "+capitalize(str)+".\n");
	    }
	}
	else {
	    if(primary_attack && present(primary_attack,environment())) {
		write("You cannot disguise yourself while attacking.\n");
		disguise_on = 0;
	    }
	    else {
		toggle_disguise(0);
	    }
	}
	return 1;
    }

    /**************************************************************************/
    /* command centre */

    status command_centre(string str) {
	string channel, emote, mud;
	string verb, tmp1, tmp2;
	string prep;
	int i, num;
	mixed *items;
	object ob1, ob2;

	write(OFF); /* Clear out and ANSI from previous stuff */

	verb = query_verb();

	switch(verb) {
#ifdef RPG
	case "-ic": verb = "ic"; break;
	case "-ooc": verb = "oc"; break;
#endif /* RPG */
	case "?": verb = "score"; break;
	case "i": verb = "inventory"; break;
	case "l": verb = "look"; break;
	case "exa": verb = "examine"; break;
	case "man": verb = "manual"; break;
	case "unalias": verb = "alias"; break;
	}
	if(verb[0] == ":"[0]) verb = "emote";

	if(!bad_file(verb, ({ ".", "/", } ))) {
	if(FILE_SIZE("/bin/std/" + verb +".c") > 0) {
	    if(call_other("bin/std/" + verb, verb, str)) return 1;
	}
	if(FILE_SIZE("/bin/player_OOC/" + verb +".c") > 0) {
	    if(call_other("/bin/player_OOC/" + verb, verb, str)) return 1;
	}
    }

    if(sscanf(verb,"%s@%s", tmp1, tmp2) == 2) {
	if(!bad_file(tmp1,({ ".", "/", })) && !bad_file(tmp2, ({ ".", "/", }))) {
	    if(member_array(tmp1, classes) != -1) {
		if(FILE_SIZE("/bin/skills/classes/"+ tmp1 +"/"+ tmp2 +".c") > 0) {
#ifdef RPG
		    if(check_ooc()) return 1;
#endif /* RPG */
		    if(call_other("bin/skills/classes/"+ tmp1 +"/"+ tmp2, tmp2, str)) 
			return 1;
		}
	    }
	}
    }

    if(!bad_file(verb, ({ ".", "/", }))) {
	for(i = 0; i < sizeof(cmd_paths); i++) {
	    if(FILE_SIZE(cmd_paths[i] + verb +".c") > 0) {
#ifdef RPG
		if(check_ooc()) return 1;
#endif /* RPG */
		if(call_other(cmd_paths[i] + verb, verb, str)) return 1;
	    }
	}
    }



    if(query_channel(verb)) {
	if(!str || str == "" || str == 0) str = "mumbles";
	if(verb == "ooc") verb = "OOC";
	return chat_channel(verb, str);
    }


#ifdef INTERMUD
    /* intermud hook */

#if (INTERMUD)
    if(secure(SEC1)) {
#endif /* wizards only */

	if(!sscanf(verb, "%s:%s", channel, emote)) channel = verb;
	sscanf(channel, "%s@%s", channel, mud);
	if(channel == "intermud" || member_array(channel, channels) != -1) {
	    call_other(this_object(),
	      "intermud",
	      channel,
	      ((emote) ? "emote "+ emote +" "+ str : str),
	      mud);
	    return 1;
	}

#if (INTERMUD)
    }
#endif /* wizards only */

#endif /* INTERMUD */



    switch(verb) {
    case "typo": case "idea": case "soul": case "bug":
    case "comment":
	log_for_players(capitalize(verb),str);
	return 1;
	break;

    case "stealth":
	if(!query_stealth()) return 0;
	toggle_stealth(0);
	return 1;
	break;

    case "disguise":
	if(!query_disguise()) return 0;
	change_disguise(str);
	return 1;
	break;
    }
    if((i = get_alias_index(verb)) != -1) {
	if(!do_cmd_on && i < sizeof(alias_commands)) {
	    str = alias_commands[i]+((str) ? " "+ str : "");
	    if(!command(str, this_object())) write("Command: "+str+" failed.\n");
	}
	else
	    write("Error: Do command cannot call aliases.\n");  
	return 1;
    }


    if(SOUL_D->do_soul(verb, str)) return 1;

    return 0;
}


/*************************************************************************/
/* do cmd */


static void wait(int time, string cmd) {
    time += find_call_out("do_cmd");
    remove_call_out("do_cmd");
    call_out("do_cmd",time, cmd);
}



status do_cmd(string str) {
    string cmd, rest;
    int i, len, time;
    if(!str || str == "") {
	write("Usage: do command1, command2, etc, etc\n\n"+
	  "Notes: Do has a special wait status (0-30 seconds).\n"+
	  "       Eg. do north,east,wait 5,south\n");
	return 1;
    }
    if((time = find_call_out("do_cmd")) != -1) {
	write("Do command Wait status: "+ time +" seconds.\n");
	return 1;
    }
    if(do_cmd_on) {
	write("Do command cannot call 'do'.\n");
	return 1;
    }
    do_cmd_on = 1; /* flag on == alias cannot be called-stops possible loops */
    while(str != "") {
	if(sscanf(str,"%s,%s",cmd,rest)) {
	    str = rest;
	}
	else {
	    cmd = str;
	    str = "";
	}
	if(!(len = strlen(cmd))) continue;
	for(i = 0; i < len && cmd[i] == ' '; i++);
	if(i == len) continue;
	cmd = extract(cmd,i); 
	if(sscanf(cmd,"wait %d",time)) {
	    if(time < 30 && time > 0) {
		write("Wait "+time+" seconds to 'do "+ str +"'\n");
		do_cmd_on = 0;
		wait(time,str);
		return 1;
	    }
	}
	write(cmd +"\n");
	if(!command(cmd)) {
	    write("Do command \""+cmd+"\" Failed.\n");
	    do_cmd_on = 0;
	    return 1;
	}
    }
    write("Do command line Done.\n");
    do_cmd_on = 0;
    return 1;
}


/*************************************************************************/
/* alias commands */

int get_alias_index(string str) {
    int i;

    if((i = member_array(str, alias_commands)) != -1) {
	if(i%2) return -1;
	return i+1;
    }
    return -1;
}

/***************************************************************************/
/* player logs */

status log_for_players(string file, string str){  
    return (status)call_other("/bin/player/bug", "bug", str);
}  


#ifdef __MCCP__
status start_mccp() // This function toggles MCCP. 
{
    if (!query_mccp()) {
        write("Starting MCCP.\n");
        start_mccp_compress(TELOPT_COMPRESS2);
     		//binary_message(({ IAC, WILL, TELOPT_COMPRESS2 }), 1);
    } else {
        end_mccp_compress();
        write("Stopped MCCP.\n");
    }
    return 1;
}
#endif      // __MCCP__



/**************************************************************************/
/*                  Mud Logon - calls logon() first                       */
/**************************************************************************/

static void time_out() {  
    if(!this_object()) return;
    write("Time out\n");  
    destruct(this_object());  
}  

static status logon() 
{

#ifdef __MCCP__
	if (!query_mccp()) {
		binary_message(({ IAC, WILL, TELOPT_COMPRESS2 }), 1);
	}
#endif
    cat(WELCOME);  
    write("Using HEAVEN7 "+ MUD_VERSION +" Mudlib. ");
    write("Running on a "+ __VERSION__ +" Driver.\n");

    if((sizeof(users()) == 1))
	write("You are the first to logon!\n");
    else if(sizeof(users()) == 2) 
	write("There is 1 person currently connected.\n");
    else 
	write("There are "+(sizeof(users()) -1)+" people currently connected!\n");

    write("Valid commands are: [1] Create New Character         \n"+
      "                    [2] Logon as existing Character \n"+
      "                    > ");
    input_to("logon1");  
    call_out("time_out", 90);  
    return 1;  
}  

#ifdef LOCK_OUT
void destruct_lock_out() 
{
    destruct(this_object());
}
#endif /* LOCK_OUT */


static void logon1(string str)
{
    int i;

    if(!str) 
        str = "3";

    if(sscanf(str, "%d", i) == 1) 
    {
        if(i == 1) 
        {
            cat(INTRO);
            write("Enter a name for your new character > ");
            input_to("logon2");
            return;
        }

        if(i == 2) 
        {
            write("Enter your name > ");
            input_to("logon2");
            return;
        }

	    return;
    }


    write(  "Invalid Command.\n" );
    write(  "Commands are:  [1] Create new character.\n"+
            "               [2] Enter as existing character.\n"+
            "               > ");
    input_to("logon1");
    return;
}

static void logon2(string str) 
{ 
    string *tmp, s1, s2;
    int i, length; 

    /* please write your lock out-type names here */
    tmp = restore_value( read_file( BAD_WORDS, 1, 2 ) );

    if( !tmp ) tmp = ({});

    if(!str || str == "") 
    { 
	    write("Invalid new name. Please enter in your login preference again.\n");
        write(  "Commands are:  [1] Create new character.\n"+
                "               [2] Enter as existing character.\n"+
                "               > ");
    	input_to("logon1");
	    return;
    } 

    str = lower_case(str);
    
    for(i = 0; i < length; i++) 
    {  
	    if(str[i] < 'a' || str[i] > 'z') 
        {  
	        write("Invalid characters in name.\n");  
    	    remove_call_out("time_out"); 
	        logon1(0);
	        return;  
    	}  
    }  

    // Check the name for bad words 
    for(i=0; i<sizeof(tmp); i++) 
    {
	    if(sscanf(str, "%s"+tmp[i]+"%s", s1, s2)) 
        {
            write( "Get out of here!\n" );
	        remove_call_out("time_out");
    	    destruct(this_object());
    	    return;
	    }
    }



    if(str == "logon") 
    {  
	    write("Invalid name.\n");  
    	remove_call_out("time_out"); 
    	logon1(0);
	    return;  
    }  


    if((length = strlen(str)) > MAX_CHAR_NAME) 
    {  
	    write("Name is too long (max. "+MAX_CHAR_NAME+" characters).\n");  
    	remove_call_out("time_out"); 
    	logon1(0);
    	return;
    }  

    if(restore_object(SAVE_BANISH + str)
	&& !restore_object(SAVE_NO_BANISH+ str)) {
	  write("Sorry, but that name is banned from play.\n");  
	  remove_call_out("time_out"); 
	  logon1(0);
	  return;  
      }

      name = str;
      if(!restore_me() && name != "guest") { 
	  write("\nCreating new character...\n"+
	    "Welcome "+ capitalize(name) +" !!\n");
	  level = -1; /* so we know you've just logged in! */  
      } 
      if(sizeof(users()) >= 
	MAX_USERS+sizeof(filter(users(),"filter_wizards",this_object()))) {
	  if(!secure(SEC1)) {
	      write("Sorry, "+ MUD_NAME +" is currently full.\n"+
		"Perhaps someone might log out soon?\n");
	      remove_call_out("time_out"); 
	      destruct(this_object());
	      return;
	  }
	  else {
	      write(MUD_NAME +" is at Maximum Players.\nCreators accepted.\n");
	  }
      }

#ifdef LOCK_OUT
      if(security_level < LOCK_OUT && security_level < SEC9) {
	  write(
	    MUD_NAME +" is temporarily closed.\n"+
	    "We appologise for any inconvenience.\n\n");
	  remove_call_out("time_out"); 
	  call_out("destruct_lock_out",5);
	  return;
      }
      else {
	  write("We are in Player Lock Out. Creator name accepted.\n");
      } 
#endif /* LOCK_OUT */

      if(name == "guest") {
	  int guest_num;
	  for(i = 0; i < sizeof(users()); i++) {
	      if((string)users()[i]->query_name(1) == "guest") guest_num += 1;
	  }
	  if(guest_num > MAX_NUM_GUESTS) {
	      write("Sorry, there are too many Guests.\n");
	      remove_call_out("time_out");
	      destruct(this_object());
	      return;
	  }
	  dead = 0;
	  ghost = 0;
	  remove_call_out("time_out");
	  logon7();
	  return;
      }
      if(level != -1)
	  write("Please enter your password > ");
      else
	  write("Please enter a password for your character of at least 6 characters.\n"+
	    " > ");
      input_to("check_password", 1);  
      return;  
  } 

    static void check_password(string p) { 
	write("\n");
	if(++password_check > PASSWORD_CHECK) {
	    write("\nThat was your last try!\n");
	    remove_call_out("time_out"); 
	    destruct(this_object()); 
	    return;
	}

	if(!p || p == "") {
	    write("Please enter a unique password > ");
	    input_to("check_password",1);
	    return;
	}

	if(!password) {
	    new_password(p);
	    return;
	}
	if(crypt(p, password) != password) { 
	    write("\nWrong password!");
	    if(password_check >= PASSWORD_CHECK) {
		write("\n\nThat was your last try!\n");
		remove_call_out("time_out");
		destruct(this_object());
		return;
	    } else {
		write(" (You have "+(PASSWORD_CHECK-password_check)+" attempts left) > ");
		input_to("check_password",1);
	    }
	    return;
	}
	remove_call_out("time_out"); 
# ifdef LOG_ENTER
	log(LOG_ENTER, "Exit:"+ name +", Exp: "+ experience+
	  " Lvl: "+ level +  
	  " Gld: "+ money+" From: "+query_ip_number()+
	  "Time: "+ctime(time()),0);
# endif /* LOG_ENTER */
	logon3();
    } 

    static void new_password(string p){ 
	write("\n"); 
	if(!p || p == "") {
	    write("Please enter unique password > ");
	    input_to("check_password",1);
	    return;
	}
	if(strlen(p) < 6) { 
	    write("The password must have at least 6 characters.\n"); 
	    input_to("new_password", 1); 
	    write("Please enter password > "); 
	    return; 
	} 
	if(!password) { 
	    password = p; 
	    input_to("new_password", 1); 
	    write("Password (again to confirm) > ");
	    return; 
	} 
	remove_call_out("time_out"); 
	if(password != p) { 
	    write("You changed !\n");
	    destruct(this_object()); 
	    return; 
	} 
	password = crypt(password,0);    /* Generate new seed. */ 
	save_me(0);
	logon3(); 
    } 


    static void logon3() { 
	if(!email || email == "" || email == "none") {
	    write(
	      "You must enter a valid eMail address so that the administration \n"+
	      "can keep track of you. Place a '!' after it if you don't wish \n"+
	      "others to see you eMail. > ");
	    input_to("logon4"); 
	    return; 
	} 
	logon5(); 
    } 

    static void logon4(string maddr) { 
	string tmp1, tmp2;
	if(!maddr && maddr = "" && 
	  !sscanf(maddr, "%s@%s", tmp1, tmp2)) {
	    write("You must enter a valid email address!\n");
	    destruct(this_object());
	    return;
	}
	email = maddr; 
	save_me(0);
	logon5(); 
    } 


    static void logon5() { 
	if(!(gender == 1 || gender == 2)) { 
	    write("Is your character Male or Female? > "); 
	    input_to("logon6"); 
	    return; 
	} 
	logon7(); 
    } 


    static void logon6(string gender_str) { 
	gender_str = lower_case(gender_str); 
	if(gender_str[0] == 'm') { 
	    write("Welcome, Sir!\n"); 
	    gender = 1;
	} 
	else if (gender_str[0] == 'f') { 
	    write("Welcome, Madam!\n"); 
	    gender = 2;
	} 
	else { 
	    write("Sorry, but thats too weird for this place!\n"); 
	    write("Are you, Male or Female? (type m or f) > "); 
	    input_to("logon5"); 
	    return; 
	}   
	save_me(0);
	logon7(); 
    } 

    static void logon7(){ 
	if(name == "guest") {
	    gender = random(2) + 1; /* random male or female */
	    race = 0;
	}
	if(!race) {
	    write("What race do you wish to be? (Type '~h' for help) 		 \n"+
	      "Dwarf, Elf, Half Giant, Halfling, Human, Minotaur, Gnome, or Orc?\n"+
	      "> ");
	    input_to("logon8");
	    return;
	}
	logon8_describe_me();
    }

    static void logon8(string str) {
	if(str == "~h") {
	    cat(RACE_INFO);
	    logon7();
	    return;
	}
	if(lower_case(str) == "elf") {
	    write("There are several elvish races.\n"+
	      "High Elf, Grey Elf, Dark Elf, Wood Elf, Wild Elf, Half Elf > ");
	    input_to("logon8_validate_race");
	    return;
	}
	else if(lower_case(str) == "gnome") {
	    write("There are several gnomish races.\n"+
	      "Forest Gnome, Rock Gnome, Deep Gnome (also known as Svirfneblin) > ");
	    input_to("logon8_validate_race");
	    return;
	}
	else if(lower_case(str) == "dwarf") {
	    write("There are several dwarvish races.\n"+
	      "Mountain Dwarf, Hill Dwarf > ");
	    input_to("logon8_validate_race");
	    return;
	}
	else
	    logon8_validate_race(str);
    }


    static void logon8_validate_race(string str) {
	if(!str || str == "") {
	    logon7();
	    return;
	}
	str = lower_case(str);
	if(member_array(str,VALID_RACES) == -1) {
	    write("Sorry, that race is too wierd for this game.\n"); 
	    logon7(); 
	    return; 
	} 
	this_object()->set_race(str);
	save_me(0);
	logon8_describe_me(); 
    } 

    static void logon8_describe_me() {
	if(!strlen(description)) {
	    line = 1;  
	    new_text = "";  
	    input_to ("logon8_get_desc");
	    write ("Enter the description of you character.             \n"+
	      "When you are finished, type '**', or abort with '~q'.\n");  
	    write ("1] ");  
	    return;

	}  
	logon9_log_wizard();
	return;
    }  

    static void logon8_get_desc(string arg) {  
	if(arg == "~q") {  
	    write ("Description aborted.\n");  
	    logon9_log_wizard();
	    return;  
	}  
	if(arg == "**") {  
	    description = new_text;
	    write("New description:\n"+((description == "") ? "Cleared" : description)); 
	    save_me(0);
	    logon9_log_wizard();
	    return;
	}  
	new_text = new_text+arg+"\n";  
	write (++line+"] ");  
	input_to ("logon8_get_desc");  
    }  

    static void logon9_log_wizard() {
	other_copy = this_object();
	if(secure(SEC1)) {
	    clone_object(WIZARD);
	    return;
	}
	else {
	    if(FILE_SIZE("/"+RACE_DIR +"/"+ query_race(1) +".c") > 0) {
		clone_object(RACE_DIR +"/"+ query_race(1));
	    }
	    else
		clone_object(RACE_DIR +"/default");
	    return;
	}
	logon9(0);
    }



    status query_entering() { return entering; }

    static void move_enter(object where) { 
	int in_prison;

	entering = 1;
	if(objectp(where)) {
	    tell_room(where,"The statue of "+ query_name() +" starts to move!\n");
	    move_object(this_object(),where);
	    entering = 0;
	    call_other("/bin/std/look", "look", 0, 0);
	    return;
	}


	if(enter_room) {  
	    move_player("X#"+enter_room);  
	    if(!secure(SEC1)) enter_room = 0; /* reset enter room */
	}
	else if (!secure(SEC1))  
#ifdef RPG
	    move_player("X#"+OOC_ENTER);
#else
	move_player("X#"+DEFAULT_ENTER);  
#endif /* RPG */
	else  
	    move_player("X#"+DEFAULT_WIZ_ENTER);
	entering = 0;
    }


    /* It is CRITICAL that nothing fails in logon9?() functions, and if
     * they do they still allow loading of the wizard object!!
     * So CATCH() any clones, moves, and call_others.
     *
     *             Zilanthius.
     */

    static void logon9(object where) { 
	object ob; 
	string tmp_name; 
	status new_mail_flag;
	int k;

	tmp_name = name;  
	name = 0;  
	other_copy = find_player(tmp_name);  
	name = tmp_name;  

	if(other_copy && name != "guest") {  
	    write("Your character seems to already be in the game !\n");  
	    write("Do you still wish to log back in ? (y/n) > ");  
	    input_to("logon9_throw_out_other_copy");
	    return;  
	}
	enable_commands();  
	set_living_name(lower_case(name));
	time_to_save = age + SAVE_TIME;  /* set time before starting heart */
	set_heart_beat(1);  
	if(!alias_name) alias_name = capitalize(name);  
	add_standard_commands();  
/* ..this never works properly!
	if(tot_value && !where) {  
	    write("You find " + tot_value + " coins of your lost money!\n");  
	    money += tot_value;  
	    tot_value = 0;  
	}  
*/
	if(lower_case(name) != "tester")  
	    if(!where) { /* We don't want to see it if we */
		cat(NEWS);
		if(secure(SEC1)) cat(WIZNEWS);

	    }                       
	if(catch(move_enter(where))) {
	    write("Entry Room Failure!\n");
	    move_object(this_object(),"room/void");
	}
	entering = 0; /* failsafe */

	if(!where) load_auto_obj();  
	if(is_invis && !secure(SEC2)) is_invis = 0;  
	if(!is_invis) {
	    if(!where) check_shout(capitalize(name)+" enters the world.\n");  
	}  
	else  { 
	    write("\nYOU ARE INVISIBLE !\n\n");  
	}
	if(query_ip_number() != called_from_ip && called_from_ip)  
	    write("Your last login was from " + called_from_ip + "\n");  
	if(last_login_time && !where) {
	    last_login = ctime(time());
	    write("Your last login was on "+ ctime(last_login_time) +".\n");  
	}
	last_login_time = time();
	called_from_ip = query_ip_number();  
	if(level == -1) { /* new player */
	    level = 1;
	    money = 750;
	    heal_self(200);
#ifdef PURGE
	    purge = 1;
#endif /* PURGE */ 
	} 
	recalc_carry();
	recalc_ac();
	recalc_wc();

#ifdef MAILER
	    if(catch((new_mail_flag = (status)call_other(MAILER,"new_mail",name)))) {
		write("Error in querying Mail.\n");
	    }
	    if(new_mail_flag > 0) {
		write("You have New mail.\n");
	    }
#ifdef MAIL_FIELD_LOADER /* for default mailing fields, admin, arch etc */
	    catch(call_other(MAIL_FIELD_LOADER,"add_to_mail_field",name,security_level));
#endif /* MAIL_FIELD_LOADER */
#endif /* MAILER */

#ifdef PURGE
	    if(!purge) {
		weapon_prof = ({});
		if(level > 3) {
		    if(catch(call_other(PURGE, "purge"))) {
			write("Error in purging character.\n");
		    }
		    heal_self(200);
		    savings = 0;
		}
	    }
	    purge = 1;
#endif  /* PURGE */


	    if(secure(SEC1)) {
		if(file_size("/log/reports/"+ name +".rep") > 0) {
		    write("You have a bug report for your areas. Please check '"+
		      "/log/reports/"+ name +".rep \n");
		}
	    }

#ifdef PARTY_DAEMON
	    if(party) {
		if(catch(call_other(PARTY_DAEMON, "???"))) {
		    write("Error in party object.\n");
		    party = 0;
		}
		else if(!call_other(PARTY_DAEMON, "query_party", party)) {
		    write("The '"+party+"' party has been disbanded!\n");
		    party = 0;
		}
		else if(!call_other(PARTY_DAEMON, "get_party_object", party)) {
		    write("You are no longer a member of the '"+party+"' party!\n");
		    party = 0;
		}
	    }
#endif /* PARTY_DAEMON */

#ifdef SAVE_OBJECTS_ON_QUIT
            write("Loading equipment");
	    if(!saved_items || !sizeof(saved_items)) {
                write("\nWarning: Could not find any equipment to load.\n");
	    }
	    else {
		for(k=0; k<sizeof(saved_items); k++) {
                    write(".");
		    ob = clone_object(saved_items[k][0]);
		    move_object(ob, this_object());
		    ob -> set_all_info(saved_items[k][1]);
		    ob -> init();
		}
	    }
            write("\nLoading complete\n");
	    saved_items = ({ });
#endif /* SAVE_OBJECTS_ON_QUIT */
	    save_me(1);
	}  

	/* used by monster.c */

	static void logon9_throw_out_other_copy(string str) {  
	    string fname1, fname2;
	    object *inv, where;  
	    int i, j;

	    if(str == "" || (str[0] != 'y' && str[0] != 'Y')) {  
		write("Welcome another time then !!\n"); 
		destruct(this_object());  
		return;  
	    }  
	    if(other_copy) {
              where = environment(other_copy);
		enable_commands();
		sscanf(file_name(this_object()),"%s#%d",fname1,i);
		sscanf(file_name(other_copy),"%s#%d",fname2,i);

		inv = all_inventory(other_copy);  
		if((j=sizeof(inv)) > 30)
		    write("Warning: Only transferring first thirty items from other copy\n");

		for(i = j; i--;) { /* so same order as old copy */
		    int wt;

		    inv[i]->drop();
		    if(!inv[i]) continue;
		    if(inv[i]->id("soul")) continue;
		    wt = (int)inv[i]->query_weight();

		    if(add_weight(wt)) {  
			if(inv[i]) move_object(inv[i], this_object());  
		    }  
                    else {
                      if(where) {
                        move_object(inv[i], where);
                      }
                    }

		}  


		if(fname1 == fname2) {
		    other_copy->save_me(1);
		}
		destruct(other_copy); /* force the issue */  
	    }
	    if(restore_me() && fname1 == fname2) {
		write("Attempting to restore points from other copy...\n");
	    }
	    else {
		if(security_level) {
		    write("Granting Creator Powers.\n");
		}
	    }
	    logon9(where);  
	}  



	/***************************************************************************/
	/*           Fn's called by various actions                                */ 
	/***************************************************************************/
	/* save_me() - all players saves are thru' this fn */

	void save_me(status value_items) {  
	    if(value_items) {
		if(!query_security_level()) {
		    if(money > level * MONEY_PER_LEVEL) {
			tell_object(this_object(),
			  "You feel you have a hole in your money pouch...\n");
			money = level * MONEY_PER_LEVEL;
		    }
		    tot_value = compute_values(this_object());
		}
	    }
	    else {
		tot_value = 0;
	    }
	    if(value_items)
		compute_auto_str();  
	    if((int)MASTER->master_file_size(SAVE_NO_BANISH+ query_name(1) +".o") > 0) {
		save_object(SAVE_NO_BANISH+ query_name(1));
	    }
	    else if(security_level) {
		save_object(SAVE_WIZARD+lower_case(name));
/*
		if(SAVE_WIZARD != SAVE_FIRST) {

if((int)MASTER->master_file_size(SAVE_FIRST+query_name(1)+".o") > 0) {
			rm(SAVE_FIRST+query_name(1)+".o");
		    }
		}
		if(SAVE_WIZARD != SAVE_PLAYER) {
if((int)MASTER->master_file_size(SAVE_FIRST+query_name(1)+".o") > 0)
		    rm(SAVE_PLAYER+query_name(1)+".o");
		}
*/
	    }
	    else if(level < 2) {
		save_object(SAVE_FIRST+lower_case(name));
/*
		if(SAVE_FIRST != SAVE_PLAYER) {
if((int)MASTER->master_file_size(SAVE_FIRST+query_name(1)+".o") > 0)
		    rm(SAVE_PLAYER+query_name(1)+".o");
		}
*/
	    }
	    else {
		save_object(SAVE_PLAYER+lower_case(name));
/*
if((int)MASTER->master_file_size(SAVE_FIRST+query_name(1)+".o") > 0)
		if(SAVE_PLAYER != SAVE_FIRST) {
		    rm(SAVE_FIRST+query_name(1)+".o");
		}
*/
	    }  
	    /*  saved_items = ({ });*/
	}  


	/*************************************************************************/
	/* restore_me() - all player restores are thru' this fn */

	status restore_me() {
	    if(restore_object(SAVE_NO_BANISH + lower_case(name))) return 1;
	    if(restore_object(SAVE_WIZARD+lower_case(name))) return 1;
	    if(restore_object(SAVE_PLAYER+lower_case(name))) return 1;
	    if(restore_object(SAVE_FIRST+lower_case(name))) return 1;
	    if(restore_object("usr/"+lower_case(name))) return 1;
	    return 0; /* New player */
	}



	/****************************************************************************/
	/* The reverse of loggin on  */

	status quit(mixed arg) {
	    if(stringp(arg)) arg = 0;
	    remove_call_out("quit");
	    if(name == "guest") {
		check_shout(query_name() +" left the world.\n");
		destruct(this_object());
		return 1;
	    }
	    set_heart_beat(0);  /* kill heart beat */ 

#ifdef LOG_SNOOPERS
	    if(query_snoop(this_object())) log(LOG_SNOOPERS,"Quit broke snoop",0);
#endif /* LOG_SNOOPERS */

#ifdef LOG_QUITS
	    if(previous_object()) log(LOG_QUITS,"Quit called externally",0);
#endif /* LOG_QUITS */

#ifdef LOG_ENTER
	    log(LOG_ENTER, "Exit:- Exp: "+ experience+
	      " Lvl: "+ level +  
	      " Gld: "+ money,0);
#endif /* LOG_ENTER */

	    if(!secure(SEC1)) is_invis = 0;
	    if(!is_invis) { 
		say(query_name() +" vanishes from the virtual world...\n");
		if(interactive(this_object())) {
		    if(this_object()->query_msgquit())
			check_shout((string)this_object()->query_msgquit());
		    else
			check_shout(query_name() +" left the world.\n");
		}
	    }
	    write("Saving....\n");
#ifdef DESTRUCT_INV_ON_QUIT
	    save_me(1);
	    destruct_all_inventory(this_object());
#else
	    save_me(1);
	    if(secure(SEC1)) {
		destruct_all_inventory(this_object());
		write("Destructing excess equipment on quit for creator...\n");
	    }
	    move_or_destruct_inventory(this_object());
#endif
	    rm(PASTE);
	    destruct(this_object()); 
	    return 1; 
	} 

	status Quit() {
	    int i;

	    saved_items = ({ }); /* initialise the array */
	    if(environment()) {
		string file, temp;

		file = query_current_room();
		if(sscanf(file, "%s#%d", temp, i) == 2 || 
		  (sscanf(file, "players/workroom", temp) == 1 && query_name() != temp)) {
		    write("A magical instability prevents you from returning to here!\n");
		}
		else {
		    write("You will return to this location.\n");
		    enter_room = file;
		}
	    }
	    quit(0);
	    return 1;
	}


	/**************************************************************************/
	/* compute monetry value of inventory */

	int compute_values(object ob) {  
	    int total_value;  
	    object *inv;
	    int i;

	    if(!ob) ob = this_object();
	    inv = all_inventory(ob);
	    for(i =0; i < sizeof(inv); i++) {
		if(inv[i]) {
		    total_value += compute_values(inv[i]);
		    total_value += (int)inv[i]->query_value()/2;
		}
	    }
	    return total_value;
	}  


	/***************************************************************************/
	/* move or destruct inventory to environment */

	static void move_or_destruct_inventory(object ob) {
	    int i, wt;
	    object *inv, env;

	    if(!(env = environment(ob))) {
		destruct_all_inventory(ob);
		return;
	    }
	    inv = all_inventory(ob);
	    for(i = sizeof(inv); i--; ) {
		if(inv[i]) {
		    if(inv[i]->drop(1)) {
			if(inv[i]) destruct(inv[i]);
		    }
		    else {
			if(inv[i]) {
			    wt = (int)inv[i]->query_weight();
			    ob->add_weight(wt*(-1));
			    move_object(inv[i], env);
			    env->add_weight(wt);
			}
		    }
		}
	    }
	}


	/***************************************************************************/
	/* destruct inventory */

	static void destruct_all_inventory(object ob) {
	    int i, size;
	    object *inv;

	    inv = all_inventory(ob);
	    for(i = 0, size = sizeof(inv); i < size; i++) {
		if(inv[i]) destruct_all_inventory(inv[i]);
		if(inv[i]) destruct(inv[i]);
	    }
	}


	/****************************************************************************/
	/* renews player object */
	void get_new_player_object() {  
	    int i;
	    string fname;

	    save_me(1);  
	    sscanf(file_name(this_object()),"%s#%d",fname,i);   
	    if(!(fname == WIZARD || fname == PLAYER)) return;
	    other_copy = this_object();
#ifdef LOG_RENEWALS
	    log(LOG_RENEWALS, fname, ((security_level) ? WIZARD : PLAYER));
#endif /* LOG_RENEWALS */
	    if(security_level)
		clone_object(WIZARD);
	    else
		clone_object(PLAYER);  
	}  


	/**********************************************************************/
	/* make_path - for players */

	string make_path(string file) {
	    string tmp1, tmp2;
	    string *path_split;
	    int i;

	    if(sscanf(file,"%s..%s", tmp1, tmp2)) {
		path_split = explode(file,"/");
		while((i = member_array("..",path_split)) != -1) {
		    path_split = path_split[0..i-2]+path_split[i+1..sizeof(path_split)-1];
		}
		file = "/" +implode(path_split,"/");
		while(sscanf(file, "%s//%s", tmp1, tmp2)) file = tmp1 + "/" + tmp2;
	    }
	    return file;
	}



	/*****************************************************************************/
	/* A NO valid_read() restricted file_size */

	static int FILE_SIZE(string file) {
	    return (int)MASTER->master_file_size(file); 
	}



	/**************************************************************************/
	/* shout_tell - called from check_shout() */

	varargs void shout_tell(string str, string lang) {
	    if(!environment()) return;
	    if(this_object()->query_edit() 
	      && security_level >= (int)this_player()->query_security_level()) {
		return;
	    }
	    if(!ansi_on) 
		str = filter_ansi(str);
	    else
		str += OFF; /* turn ansi off */
	    if(!lang || query_language(lang)) tell_object(this_object(),str);
	}



	/***************************************************************************/
	/* illegal patch */

	void illegal_patch(string what) {  
	    write("You are struck by a mental bolt from the interior of the world.\n"); 
	    log(LOG_ILLEGAL,"Illegal: "+what,0);
	}  



	/**************************************************************************/
	/* filter_users - removes invis, and players logging in */


	status filter_users(object ob) {
	    int sec, lvl;

	    if(!environment(ob)) return 0;
	    sec = (int)ob->query_security_level();
	    lvl = (int)ob->query_level();
	    if(sec) {
		if((ob->query_invis() && sec <= security_level) || !ob->query_invis()) {
		    return 1;
		}
	    }
	    else {
		if((ob->query_invis() && (lvl <= level || security_level)) 
		  || !ob->query_invis()) {
		    return 1;
		}
	    }
	    return 0;
	}

	status filter_wizards(object ob) {
	    return (ob->query_security_level()) ? 1 : 0;
	}


	/***************************************************************************/
	/* sort by security level */

	status by_sec_level(object a, object b) {
	    if((int)a->query_security_level() == (int)b->query_security_level()
	      && (int)a->query_level() < (int)b->query_level()) return 1;
	    return
	    ((int)a->query_security_level() < (int)b->query_security_level()) ? 1 : 0;
	}



	/****************************************************************************/
	/* autoload */

	void load_auto_obj() {  
	    object ob;  
	    mixed *load;
	    int i;

	    load = autoload;

	    if(!load) return;
	    for(i = 0; i < sizeof(load); i++) {
		if(catch((ob = clone_object(load[i][0])))) {
		    write("Error: Cannot load file.\n");
		    continue;
		}
		ob->init_arg(load[i][1]);
		move_object(ob, this_object());
		/*
#ifdef LOG_PLAYER_AUTO
	      if(!secure(SEC1)) log(LOG_PLAYER_AUTO,"Autoloaded: "+autoload[i][0],0);
#endif
		*/
	    }  
	}  

	void compute_auto_str() {  
	    object *ob, *inv;
	    int i, j, k, iarg;
	    mixed auto_load_arg, arg;
	    string fname, file;

	    if(name == "guest") return; /* no autoload stuff for guests */
	    ob = all_inventory();  
	    autoload = ({});
	    for(i = 0; i < sizeof(ob); i++) {
		if((auto_load_arg = (mixed)ob[i]->query_auto_load())) {
		    if(intp(auto_load_arg)) { /* simple: return 1; */
			sscanf(file_name(ob[i]),"%s#%d", fname, iarg);
			arg = 0;
		    }
		    else if(stringp(auto_load_arg)) {  /* old way */
			if(sscanf(auto_load_arg,"%s:%s",fname,arg) != 2) {
			    tell_object(this_object(),
			      "Invalid auto load string! Object "+ file_name(ob[i]) +"\n" +
			      "Please report this!\n");
			}
			else {
			    sscanf(fname,"/%s",fname);
			    sscanf(fname,"%s.c",fname);
			}
		    }
		    else if(pointerp(auto_load_arg)) { /* new way */
			if(sizeof(auto_load_arg) == 2) {
			    fname = auto_load_arg[0];
			    arg = auto_load_arg[1];
			}
		    }
		    autoload += ({ ({ fname, arg, }), });
		}
	    }
	    saved_items = ({ });
#ifdef SAVE_OBJECTS_ON_QUIT
	    inv = all_inventory(this_object());
	    for(i=0; i<sizeof(inv); i++) {
		if(!inv[i]->short()) continue;
		if(inv[i]->id("spell")) continue;
		if(inv[i]->query_auto_load()) continue;
		if((string)inv[i]->query_object_type() == "Party") continue;
		if((string)inv[i]->id("mailer")) continue;
		if(inv[i]->id("soul")) continue;
		sscanf(file_name(inv[i]), "%s#%d", file, k);
		if((string)inv[i]->query_object_type() == "Container")
		    inv += all_inventory(inv[i]);
		saved_items += ({
		  ({ file, (mapping)inv[i]->query_all_info(), }),
		});
	    }
	    if(!sizeof(saved_items))
		saved_items = ({ });
#endif /* SAVE_OBJECTS_ON_SAVE */

	}


	/**************************************************************************/
	/* more */

	status more(string file) {
	    object ob, ob2;

	    ob = clone_object(MORE_OB);
	    move_object(ob, this_object());
	    ob->more(file);
	    return 1;
	}


	/************************************************************************/
	/* cat */

	status cat_file(string path){  
	    if(!path) return 0;  
	    path = make_path(path);
	    if(!cat(path)) return 0;
	    return 1;  
	}  


	/**************************************************************************/
	/* invis */

	status toggle_invis(){  
	    if(is_invis = !is_invis) {  
		is_invis = level;  
		say(query_name() +" "+ query_mmsgout() +".\n", this_object());  
		tell_object(this_object(), "You are now invisible.\n");  
	    }
	    else {
		tell_object(this_object(), "You are now visible.\n");  
		say(query_name() +" "+ query_mmsgin() +".\n", this_object());  
	    }  
	    return 1;  
	}  

	/****************************************************************************/
	/* no wimpy */

	status toggle_no_wimpy() {  
	    return no_wimpy = !no_wimpy;
	}


	/**************************************************************************/
	/*  ghost */

	status toggle_ghost() {  
	    if(!ghost) {
		msgin = "drifts around";
		msgout = "drifts";
		ghost = 1;
	    }
	    else {
		tell_object(this_object(),  
		  "You feel a very strong force pulling your body back to reality...\n"+ 
		  "Your body solidifies in a more solid form!\n");  
		say(query_name() + "'s body begins to solidify...\n"+  
		  query_name()+" appears whole once more!\n");  
		ghost = 0;  
		dead  = 0;  
		msgin = "arrives";  
		msgout = "leaves";
	    }  
	    save_me(1);  
	    return 1;  
	}  


	/****************************************************************************/
	/* security level routines */

	nomask status security(int sec_level){ 
	    if(!query_ip_number(this_player())) return 0;
	    return ((int)this_player()->query_security() >= sec_level
	      || this_player() == this_object()) ? 1 : 0;
	} 


	nomask status secure(int sec_level) {
	    object user;

	    if(!(user = (this_interactive()) ? this_interactive() : this_player())) {
		return 0;
	    }
	    if(!query_ip_number(user)) return 0;
	    return ((int)user->query_security() >= sec_level) ? 1 : 0;
	}

	nomask int query_security() { 
	    return security_level; 
	} 

	nomask int query_security_level() {
	    return security_level;
	} 

	nomask int set_security_level(int new_level) {
	    string str;
	    int old_level;
	    object wiz_creator;

	    old_level = security_level;

	    if(!this_player() || !interactive(this_player())
	      || previous_object() != this_player()) {
		write("Use the 'promote' command.\n");
		return 0;
	    }
	    if(secure(SEC9)) {
		if(security_level < SEC9 || new_level > security_level) {
		    security_level = new_level;            
		} /* demotion of admin is done by hand */
	    }
	    else if((secure(SEC8) && new_level < SEC8)    /* arches make lords */
	      || (secure(SEC7) && new_level < SEC6)    /* lords make elders  */
	      || (secure(SEC5) && new_level < SEC4)) { /* elders make creators */
		security_level = new_level;
	    }
	    if(old_level == security_level) {
		write("It is not possible for you to promote "+ query_cap_name()
		  +" to a higher security level.\n");
		return security_level;
	    }
	    str  = (security_level >= SEC9)
	    ? "an Administator"
	    : (security_level >= SEC8)
	    ? "an Arch"
	    : (security_level >= SEC7)
	    ? "an QC"
	    : (security_level >= SEC6) 
	    ? "a Lord"
	    : (security_level >= SEC5)
	    ? "a Elder"
	    : (security_level >= SEC4)
	    ? "a Senior"
	    : (security_level >= SEC3) 
	    ? "a Creator"
	    : (security_level >= SEC2)
	    ? "an Apprentice Creator"
	    : "an Aspirant Creator";

	    tell_object(this_object(),"You have become "+str+".\n"); 
#ifdef WIZ_SCROLL
	    if(old_level < SEC1) {
		object scroll;

		scroll = clone_object(WIZ_SCROLL);  
		move_object(scroll, this_object());  
		tell_object(this_object(),
		  "You have been given a scroll containing valuable information.\n"+  
		  "Read it, and the docs that it outlines, now!\n\n"+  
		  "Don't seek an Elder for further advancement UNTIL you have read it\n");
	    }
#endif

	    /* Note: master.c has been changed for create_wizard() */

	    create_wizard(query_name(1)); 
	    save_me(1);
	    write("You have promoted "+ query_name(1) +" to "+ str +".\n"); 
	    write("Security Level: "+ security_level +"\n"); 

#ifdef LOG_SPONSER
	    log(LOG_SPONSER,"Lvl: "+ level +", Sec Lvl: "+ old_level,
	      "Sec Level: "+ security_level);
#endif   

	    if(old_level < SEC3) {
		tell_object(this_object(),"Adding Wizard Commands....\n");
                this_object()->add_path("/bin/creator/");
		get_new_player_object(); 
	    }
	    return security_level; 
	} 


	/**********************************************************************/
	/* adds */

mapping add_player_info(string key, mixed value) {
  if(!player_info) player_info = ([]);
  if(member(player_info, key))
      player_info -= ([ key ]);
  return player_info += ([ key: value ]);
}

mapping remove_player_info(string key) {
  if(!player_info) player_info = ([ ]);
  if(member(player_info, key)) 
    player_info -= ([ key ]);
  return player_info;
}



	void set_savings(int s) { savings = s; }

	int add_savings(int s) {
	    return savings += s;
	}

	int add_exp(int e) {
	    if(e > level*MAX_XP_PER_LVL)  e = level*MAX_XP_PER_LVL;
	    e = (e * (max_hp - whimpy))/max_hp; /* wimpy reduces exp */
	    if(e > 0) total_exp += e; 
	    return ::add_exp(e);
	} 

	int add_intoxication(int i) { 
	    return intoxicated = (intoxicated + i < 0) ? intoxicated + i : 0; 
	}

	int add_stuffed(int i) {
	    return stuffed = (stuffed + i < 0) ? stuffed + i : 0;
	}

	int add_soaked(int i) {
	    return soaked = (soaked + i < 0) ? soaked + i : 0;
	}

	void add_alignment(int a) {  /* This happens when you kill something! */
	    if(secure(SEC1)) return;
	    if(!intp(a)) return;
	    if(!intp(alignment)) alignment = 0;
	    alignment = a + (alignment * 9)/10;
	    al_title = (alignment > NEUTRAL_AL * 100)
	    ? "(Lawful Good)"
	    : (alignment > NEUTRAL_AL * 20)
	    ? "(Lawful Neutral)"
	    : (alignment > NEUTRAL_AL * 4)
	    ? "(Neutral Good)"
	    : (alignment > - NEUTRAL_AL * 4)
	    ? "(True Neutral)"
	    : (alignment > - NEUTRAL_AL * 20)
	    ? "(Chaotic Neutral)"
	    : (alignment > - NEUTRAL_AL * 100)
	    ? "(Neutral Evil)"
	    : "(Chaotic Evil)"; 
	} 


	/************************************************************************/
	/* scars */

	static void make_scar() { 
	    if (level < 10) return; 
	    scar |= 1 << random(MAX_SCAR); 
	} 


	void remove_scar() { 
	    scar = 0; 
	} 

	void show_scar() { 
	    int i, j, first, old_value; 
	    string *scar_desc; 

	    scar_desc = ({ 
	      "left leg", "right leg", "nose", "left arm", "right arm", 
	      "left hand", "right hand", "forhead", "left cheek", 
	      "right cheek",
	    }); 
	    old_value = scar; 
	    for(j = 1,first = 1; i < MAX_SCAR;j *= 2,i++) { 
		if(scar & j) { 
		    old_value &= ~j; 
		    if(first) { 
			write(query_name() +" has a scar on "+ query_possessive() + 
			  " " + scar_desc[i]); 
			first = 0; 
		    }
		    else if(old_value) { 
			write(", " + query_possessive() + " " + scar_desc[i]); 
		    }
		    else { 
			write(" and " + query_possessive() + " " + scar_desc[i]); 
		    } 
		} 
	    } 
	    if(!first) write(".\n"); 
	} 




	/**************************************************************************/
	/* second_life */

	status second_life() {  
	    object death_mark;  
	    int i;

	    if(security_level) {
		tell_object(this_object(),"   YOU DIE....luckily\n");
		tell_object(this_object(),"Your arcane powers protect you from death.\n");
		dead = 0;
		return 1;
	    }
	    if(secure(SEC1)) {
		illegal_patch("second_life");  
	    }
	    make_scar();  
	    toggle_ghost();
	    if(this_player()->query_npc()) { 
		level        -= (level < 2) ? 0 : 1;
		strength     -= (strength < 2) ? 0 : 1;
		constitution -= (constitution < 2) ? 0 : 1;
		dexterity    -= (dexterity < 2) ? 0 : 1;
		intelligence -= (intelligence < 2) ? 0 : 1;
		wisdom       -= (wisdom < 2) ? 0 : 1;
		combat       -= (combat < 2) ? 0 : 1;
		charisma     -= (charisma <  2) ? 0 : 1;
		adj_constitution(0);
		for(i = sizeof(classes); i--; ) {
		    call_other(this_object(),"second_life_"+ classes[i]);
		}
	    }
	    msgin  = "drifts around";  
	    msgout = "drifts";  
	    headache    = 0;  
	    intoxicated = 0;  
	    stuffed     = 0;  
	    soaked      = 0;  
	    log_file("KILLS", name+"("+level+")"+", exp "+experience+
	      ", killed by "+(string)this_player()->query_name(1)+
	      ", Prev. Ob: "+ file_name(previous_object()) +
	      ", creator: "+creator(this_player()) + "\n");  
	    primary_attack = 0;
	    secondary_attacks = ({});
	    tell_object(this_object(),
	      "\n You slump to the ground in agony!      \n"+
	      "\n            YOU DIE...                  \n"+  
	      "  Your soul begins to leave your body...  \n"+  
	      "You have a strange feeling as you look on \n"+  
	      "     your own dead form from above.       \n\n");  

#ifdef DEATH_MARK
	    death_mark = clone_object(DEATH_MARK);  
	    move_object(death_mark, this_object());  
#endif /* DEATH_MARK */
	    save_me(1);
	    return 1;  
	}  


	/******************************************************************************/
	/* drink alco */

	int drink_alcohol(int drink_strength) {  
	    string tmp1, tmp2;
	    int drink_bonus;

	    if(sscanf(race, "%sdwarf", tmp1)) drink_bonus = 2*(1+(constitution/5));  
	    if(intoxicated + drink_strength - drink_bonus > constitution * 3) {  
		tell_object(this_object(),"You fail to reach the drink with your mouth.\n");
		return 0;  
	    }  
	    intoxicated += drink_strength/2;  
	    if(intoxicated < 0) intoxicated = 0;  
	    if(!intoxicated && previous_object()
	      && (string)previous_object()->query_object_type() != "Potion") {
		tell_object(this_object(),"You are completely sober.\n");
	    }  
	    else if(headache) {  
		headache = 0;  
		tell_object(this_object(), "Your headache disappears.\n");  
	    }  
	    if(intoxicated > max_headache) max_headache = intoxicated;  
	    if (max_headache > 8) max_headache = 8;  
	    return 1;  
	}  


	/**************************************************************************/
	/* drink soft */

	status drink_soft(int drink_strength) {  
	    if(soaked + drink_strength > constitution * 8) {  
		tell_object(this_object(),
		  "You can't possibly drink that much right now!\n" +   
		  "You feel crosslegged enough as it is.\n");  
		return 0;  
	    }  
	    soaked += drink_strength * 2;  
	    if(soaked < 0) soaked = 0;  
	    if(!soaked && previous_object()
	      && (string)previous_object()->query_object_type() != "Potion") {
		tell_object(this_object(),"You feel a bit thirsty.\n");
	    }
	    return 1;  
	}  



	/**************************************************************************/
	/* eat food */

	status eat_food(int food_strength) {  
	    if(stuffed + food_strength > constitution * 8) {  
		tell_object(this_object(),
		  "This is much too rich for you right now! Perhaps something lighter?\n"); 
		return 0;  
	    }  
	    stuffed += food_strength * 2;  
	    if(stuffed < 0) stuffed = 0;  
	    if(!stuffed)  
		tell_object(this_object(),"Your stomach makes a rumbling sound.\n");  
	    return 1;  
	}  





	/***********************************************************************/
	/* Channel stuff. Not to be confused with intermud */

	string *query_channels() {  return channels; }

	status query_channel(string channel) {
	    if(channel == "ooc") channel = "OOC";
	    if(channel == party) return 1;
	    if(channel == speak_language) return 1;
	    return (member_array(channel, channels) != -1) ? 1 : 0;
	}

	string *query_affiliations() { return affiliations; }
	status query_affiliation(string str) {
	    return (member_array(str, affiliations) != -1) ? 1 : 0;
	}

status chat_channel(string sChannel, string sMessage){
  string sSoul;
  string sParams;
  string *spSoulStrings;

  sMessage = filter_ansi(sMessage);

 switch(sMessage[0])
  {
    case ':':
      sMessage = query_name() +" "+ sMessage[1..];
      break;

    case ';':
      sSoul = sMessage[1..];
      sParams = "";

      sscanf(sSoul, "%s %s", sSoul, sParams);

      spSoulStrings = (mixed)SOUL_D -> do_soul(sSoul, sParams, 1);

      if(sizeof(spSoulStrings) == 3 && spSoulStrings[2] != "")
        sMessage = spSoulStrings[2];
      else
        return 0;

      break;


    default:
      sMessage = query_name() +": "+ sMessage;
  }
  if(sMessage == 0) sMessage = "Mumbles";
  return (status)CHANNEL_D -> chat_channel(sChannel, sMessage);
}

	void add_channel(string channel) {
	    int s;
	    object ob;
	    ob = previous_object();
	    if(ob) {
		if(ob != this_object() && (s=(int)ob->query_security_level())) {
		    if(s < SEC9)
			notify_fail("Illegal patch: Too low security access.\n");
		    illegal_patch("Add channel: "+ob->query_name(1)+"\n");
		    return 0;
		}
	    }
	    if(channel == "ooc") channel = "OOC";
	    if(!query_channel(channel) && channel) channels += ({ channel, });
	}

	void add_affiliation(string str) {
	    if(!query_affiliation(str) && str) affiliations += ({ str, });
	    this_object()->add_path("/bin/skills/affils/"+ str +"/");
	}


	void remove_channel(string channel) {
	    int i;

	    if((i = member_array(channel,channels)) != -1) {
		channels = channels[0..i-1]+channels[i+1..sizeof(channels)-1];
	    }
	}

	void remove_affiliation(string str) {
	    int i;
	    if((i=member_array(str, affiliations)) != -1) {
		affiliations = affiliations[0..i-1]+affiliations[i+1..sizeof(affiliations)-1];
	    }
	    this_object()->remove_path("/skills/affils/"+ str +"/");
	}


	status valid_channel(string str) {
	    return (status)CHANNEL_D->valid_channel(str);
	}



#ifdef INTERMUD
	status intermud(string send_channel, string str, string mud) {
	    int i;
	    string verb, msg;
	    string cmd;


#if (INTERMUD)
	    if(!secure(SEC1)) return 0;
#endif /* WIZ_ONLY */
	    if(!str) {
		write("   <channel> emote <msg>      - do an emote on <channel>\n"+
		  "   <channel> list             - get list of channel users\n"+
		  "   <channel> <msg>            - send msg on <channel>\n"+
		  "   intermud channel <channel> - toggle <channel> on|off\n"+
		  "   intermud off               - stop listening all channels\n"+
		  "   <channel@mud>              - send channel to only mudname\n\n");
		write(pad_str("Currently Known Channels: ",
		    (string)call_other(UDP_CMD_DIR+"channel","known_channels") +".",75));
		if(!(i = sizeof(channels))) {
		    write("No channels are currently open.\n");
		}
		else {
		    write(pad_str("You have "+i+" channel"+((i == 1) ? "" : "s")+" open: ",
			implode(channels, ", ") +".", 75));
		}
		return 1;
	    }
	    if(str == "off") {
		write("You stop listening to all channels.\n");
		channels = ({});
		return 1;
	    }
	    if(str == "list") cmd = "list";
	    if(sscanf(str,"emote %s",str) || sscanf(str,":%s",str)) cmd = "emote";
	    if(str == "channel") str += " "+ send_channel;
	    if(sscanf(str,"channel %s",str)) {
		if(query_channel(str)) {
		    write("You stop listening to channel "+str+".\n");
		    remove_channel(str);
		}
		else {
		    write("You start listening to channel "+str+".\n");
		    add_channel(str);
		}
		return 1;
	    }
	    if(!sizeof(channels)) channels = ({ "intermud", });
	    call_other(UDP_CMD_DIR+"channel","channel", send_channel, str, cmd, mud);
	    return 1;
	}

#endif /* INTERMUD */


	/********************************************************************/
	/* time for various time zones */


	status show_time(string arg) {
	    int n;

	    n = time();
	    switch(arg) {
	    case "uk":
		n = n-36000;
		break;

	    case "usa":
		n = n -54000;
		break;

	    default:
		arg = "aust";
		break;
	    }
	    write("Time/date @" + arg + " is " + ctime(n) + ".\n");
	    return 1;
	}


	varargs
	status move_player(string dir_dest,mixed optional_dest_ob,status safe) {
	    set_this_player();
	    return ::move_player(dir_dest,optional_dest_ob,safe);
	}


	/************************************************************************/
	/* racial bargaining bonus */

	int bargain_bonus() {
	    string tmp1, tmp2;
	    int bonus;

	    if(race) {
		if(sscanf(race,"%self%s", tmp1, tmp2))
		    bonus -= 2;
		else if(sscanf(race,"%sdwarf%s", tmp1, tmp2))
		    bonus -= 1;
		else if(sscanf(race,"%sminotaur%s", tmp1, tmp2))
		    bonus -= 2;
		else if(sscanf(race,"%sorc%s", tmp1, tmp2))
		    bonus -= 2;
		else if(sscanf(race,"%sgiant%s", tmp1, tmp2))
		    bonus += 2;
		else if(sscanf(race,"%shalfling%s", tmp1, tmp2))
		    bonus += 3;
		else if(sscanf(race,"%skender%s", tmp1, tmp2))
		    bonus += 1;
		else if(sscanf(race,"%spixie%s", tmp1, tmp2))
		    bonus += 2;
		else if(sscanf(race,"%snixie%s", tmp1, tmp2))
		    bonus += 1;
		else if(sscanf(race,"%skobold%s", tmp1, tmp2))
		    bonus -= 1;
		else if(sscanf(race,"%sgoblin%s", tmp1, tmp2))
		    bonus -= 1;
		else if(sscanf(race,"%ssprite%s", tmp1, tmp2))
		    bonus += 1;
	    }
	    return bonus + random((int)this_object()->query_appraisal());
	}


#ifdef QUEST_ROOM

	/* Player's Quest Stuff. v1.01 Ramses, November 1993
	 * v1.02 revised by Angel, March 1994.
	 */


	status query_quests(string what) {
	    if(!quests || !pointerp(quests)) quests = ({});
	    return (member_array(what, quests) == -1) ? 0 : 1;
	}

	string *query_done_quests() {
	    if(!quests) quests = ({});
	    return quests;
	}

	string assign_quest(string quest_id) {
	    string temp;

	    if(!quest_id) {
		if(temp = (string)QUEST_ROOM->get_new_quest(this_object())) {
		    if(query_quests(temp)) return 0;
		    log_file("QUEST.INFO", name+": current quest "+temp+", assigned "+
		      ctime(time())+"\n");
		    current_quest = temp;
		}
	    }
	    else if(interactive(this_player())      &&
	      (this_player()->query_security_level() > SEC6)) {
		temp = quest_id;
		current_quest = temp;
		log_file("QUEST.INFO", name+": current quest "+temp+", set at "+
		  ctime(time())+", by "+(string)this_player()->query_name(1)+"\n"); 
	    }
	    return temp;
	}


	status finish_quest(string quest_id) {
	    object called_by;
	    int qp;

	    if(quest_id == current_quest) {
		called_by = previous_object();
		if(qp = (int)QUEST_ROOM->finish_quest(quest_id, called_by, this_object())){
		    quests += ({ quest_id, });
		    quest_points += qp;
		    log_file("QUEST.DONE", name+": finished quest "+current_quest+" at "+
		      ctime(time())+"\n");   
		    current_quest = 0;
		    return 1;  /* success! quest is now finished! */
		}
	    }
	    return 0;      /* failure to finish quest */
	}

	void quest_hint() {
	    string hint;

	    hint = (string)QUEST_ROOM->get_quest_hint(current_quest);
	    if(hint) 
                write(hint +"\n");
	    else
		write("You do not currently have a quest.\n");
	}

	int query_quest_points()     {  return quest_points;      }
	int add_quest_points(int i)  {  return quest_points += i; }
	int add_qpoints(int i)       {  return quest_points += i; }
	string *query_all_quests()   {  return quests;            }
	string query_current_quest() {  return current_quest;     }
	string query_curr_quest()    {  return current_quest;     }

#endif /* QUEST_ROOM */


#ifdef PING_PONG

	status catch_ping() {
	    string who;
	    int i;

	    if(this_object()->query_edit()
	      && (int)this_player()->query_security_level() 
	      < (int)this_object()->query_security_level()) {
		return 0;
	    }
	    pinger = this_player();
	    who = (string)pinger->query_name(1);
	    if (!who) return pinger = 0;
	    tell_object(this_object(), capitalize(who) +" pings you.\n");
	    for(i = 3; i--;) {
		tell_object(this_object(), sprintf("%c",7));
	    }
	    return 1;
	}

#endif /* PING_PONG */
