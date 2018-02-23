#pragma strict_types
#pragma combine_strings

#include <mudlib.h>
inherit PLAYER;

#include <wizard.cfg>   /* configuration */
#include <wizard.spc>
#include <levels.h>     /* security levels */
#include <ansi.h>
#include <stat.h>


#define TMP_FILE    make_path("~") + "/_lpc_cmd"
#define invis_name  alt_name /* save some global space by using alt_name */

mixed *domain_level; 

string msgtrans;            /* wizard msg when transing   */
string msghome;             /* wizard msg when going home */
string msgquit;             /* wizard msg when quit game  */
string mclone;              /* wizard msg when cloning    */
string mdest;               /* wizard msg when desting    */

string edtitle;             /* Title while editing */

static status edit_on;      /* use edit title, and filter shouts */  
static object snooped;      /* remember who we are snooping */  

static string current_path; /* Current directory */  
static string last_file;    /* hack in case ed() by itself doesn't work */

static string *list;

/* used by copy, and some other misc. fn */

static string sformat;
static string sformat_out;
static string path_out;
static status over_write;
static status move_file;

void reset(status arg) {  
	::reset(arg);
	if(arg) return;  
	if(this_object() != this_player()) return;
	if(!edtitle)      edtitle = "is editing.";
	if(!current_path)  current_path = extract(WIZARD_DIR+query_name(1),1);
	if(!msgtrans)     msgtrans = "You are summoned!\n";
	if(!msghome)      msghome = "heads for home";
        if(!cmd_paths) cmd_paths = ({ "/bin/player/", "/bin/creator/" });
	list = ({});

	if(!security_level) return;   
	add_action (  "cd",                       "cd"      );  
// Changed the command from 'lpc' to 'eval'
// The LPC channel had priority over the command, so the change was needed
// Vaejor  01/16/2002
	add_action(   "lpc",                      "eval"     );
	add_action (  "set_start",                "start"   );  
	add_action (  "wiz",                      "wiz"     );  
	add_action (  "stat",                     "Stat"    );  
	add_action (  "sk_stat",                  "skstat"  ); 
	add_action (  "wizard_title",             "title"   );  
	add_action (  "wizard_msghome",           "mhome"   );  
	add_action (  "wizard_invis_name",        "minvis"  );  
	add_action (  "wizard_msgtrans",          "mtrans"  );
        add_action (  "wizard_msgquit",           "mquit"   );
	add_action (  "wizard_mclone",            "mclone"  );  
	add_action (  "wizard_mmsgin",            "mmin"    );  
	add_action (  "wizard_mmsgout",           "mmout"   );  
	add_action (  "wizard_msgin",             "min"     );  
	add_action (  "wizard_msgout",            "mout"    );  
	add_action (  "wizard_edtitle",           "edtitle" );
	add_action (  "wizard_review",            "review"  );
	add_action (  "toggle_invis",             "invis"   );  
	add_action (  "toggle_invis",             "vis"     );  
	add_action (  "wizard_pretitle",          "pretitle");  
	add_action (  "wizard_align",             "align"   );  
	add_action (  "wizard_trans",             "trans"   );
	add_action (  "pwd",                      "pwd"     );  
	add_action (  "more",                     "more"    );  
	add_action (  "cat_file",                 "cat"     );  
	add_action (  "dir",                      "ls"      );  
	add_action (  "tail_file",                "tail"    );
	add_action (  "post",                     "post"    );
	add_action (  "home",                     "home"    );
	add_action (  "guild",                    "guild"   );
	add_action (  "pub",                      "pub"     );
	add_action (  "inner",                    "inner"   );
	add_action (  "stat_info",                "stat"    );
	add_action (  "renew",                    "new"     );
	add_action (  "renew",                    "refresh" );

	if(security_level > SEC1) {
	    add_action ("Cat_file",           "Cat");
	    add_action ("Put",                "Put");
	    add_action ("bomb",               "bomb");
	    add_action ("move",               "Get");
	    add_action ("force_player",       "command");
	    add_action ("clean",              "clean");
	    add_action ("dest_ob",            "dest");
	    add_action ("goin",               "goin");
	    add_action ("patch",              "patch");
	    add_action ("reset_ob",           "reset");
	    add_action ("Reset_ob",           "Reset");
	    add_action ("check_book",         "pay");
	    add_action ("grab",               "grab");
	    add_action ("duplicate",          "duplicate");
	    add_action ("duplicate",          "dup");
	    add_action ("set_lighting",       "light");
	    add_action ("goto",               "goto");
	    add_action ("copy",                     "copy");
      add_action ("NewCopy", "newcopy");
	    add_action ("copy",                      "cp");
	    add_action ("copy_with_overwrite",      "Copy");
	    add_action ("move_file_with_overwrite", "Mv");
	    add_action ("move_file",                "mv");
	    add_action ("delete",             "rm");
	    add_action ("Delete",             "Rm");
	    add_action ("dir",                "ls");
	    add_action ("deltree",            "deltree");
	    add_action ("find_file",          "find");
	    add_action ("path_tree",          "tree");
	    add_action ("Path_tree",          "Tree");
	    add_action ("toggle_edit",        "edit");  
	    add_action ("echoto",             "echoto");  
	    add_action ("echo",               "echo");  
	    add_action ("echoall",            "echoall");  
	    add_action ("wizard_mdest",       "mdest");  
	    add_action ("home",               "home");  
	    add_action ("edit",               "ed");  
	    add_action ("clone",              "clone");  
	    add_action ("load",               "load");  
	    add_action ("zap",                "zap");  
	    add_action ("update",             "update");  
	    add_action ("Update",             "Update");  
	    add_action ("heal",               "heal");  
	    add_action ("makedir",            "mkdir");  
	    add_action ("removedir",          "rmdir");  
	    add_action ("promote",            "promote");
	    add_action ("domain",             "domain");
	    add_action ("snoop_on",           "snoop");  
	    add_action ("snoopers_who",       "snoopers");
	    add_action ("shut_down_game",     "shutdown");  
	    add_action ("show_log",           "log");  
	    add_action ("show_main_log",      "main");
	    add_action ("show_debug_log",     "debug");  
	    add_action ("rlog",               "rlog");
	    /* add_action ("banish",     "banish"); */
	}

#ifdef MAILER
	if(!present("mailer")) {
		if(catch(move_object(clone_object(MAILER),this_object()))) {
		    write("Error Cloning Mail Reader.\n");
		}
	    }
#endif /* MAILER */
	}  



	/**************************************************************************/
	/* sets */

	string set_edtitle(string s)  { return edtitle  = (s) ? s : "is editing"; }  
	status set_edit_on(status i)  { return edit_on  = (i) ? 1 : 0; }  


	/***************************************************************/
	/* new */

	static status renew(string who) {
	    object ob;

	    if(!who)
		ob = this_object();
	    else
		ob = find_player(who);

	    if(!ob) {
		write(capitalize(who)+" is not here.\n");
		return 1;
	    }
	    ob->get_new_player_object();
	    return 1;
	}


	/****************************************************************************/
	/* wizard message sets */

	status wizard_msghome(string str) {  
	    msghome = (str) ? str : "heads home";
	    tell_object(this_object(),
	      "Your Message Home is: "+query_name()+" "+msghome+"\n");  
	    return 1;
	}  

	status wizard_invis_name(string str) {  
	    invis_name = (str) ? str : "Someone";
	    tell_object(this_object(), "Your invisible name is: "+invis_name+"\n");  
	    return 1;  
	}  

	status wizard_msgtrans(string str) {
	    msgtrans = (str) ? str : "You are magically transferred somewhere.";   
	    tell_object(this_object(),"Your trans message is: "+msgtrans+"\n");
	    return 1;  
	}  

	status wizard_msgquit(string str) {
	    msgquit = (str) ? str : "A resounding boom travels across the heavens.\n";
            tell_object(this_object(), "You quit message is "+msgquit+"\n");
            return 1;
	}


	status wizard_mdest(string str) {
	    mdest = (str) ? str : "$name disintegrates $obj \n";
	    tell_object(this_object(), "Your dest message is: "+mdest+"\n");
	    return 1;
	}  

	status wizard_mclone(string str) {  
	    mclone = (str) ?  str : "$name creates $obj";
	    tell_object(this_object(),"Your clone message is: "+mclone+"\n");
	    return 1;  
	}  

	status wizard_msgout(string str) {  
	    msgout = (str) ?  str : "leaves";
	    tell_object(this_object(),
	      "Your message out of a room is: "+query_name()+" "+msgout+" 'direction'\n");
	    return 1;  
	}  

	status wizard_msgin(string str) {  
	    msgin = (str) ?  str : "arrives";
	    tell_object(this_object(),
	      "Your message into a room is: "+query_name()+" "+msgin+"\n");
	    return 1;  
	}  

	status wizard_mmsgout(string str) {  
	    mmsgout = (str) ?  str : "disappears in puff of smoke";
	    tell_object(this_object(),
	      "Your message leaving magically is: "+query_name()+" "+mmsgout+"\n");
	    return 1;  
	}  

	status wizard_mmsgin(string str) {  
	    mmsgin = (str) ?  str : "appears in a puff of smoke";
	    tell_object(this_object(),
	      "Your message entering magically is: "+query_name()+" "+mmsgin+"\n");
	    return 1;  
	}  

	status wizard_edtitle(string str) {  
	    edtitle = (str) ?  str : "is editting";
	    tell_object(this_object(),
	      "Your editing short() is: "+pretitle+" "+query_name()+" "+edtitle+"\n");
	    return 1;  
	}  

	status wizard_title(string str) {  
	    title = (str) ?  str : "is a Creator";
	    tell_object(this_object(),
	      "Your title message is: "+title+"\n"+
	      "Your short() message is: "+pretitle+
	      " "+query_name()+" "+title+" "+al_title+"\n");
	    return 1;  
	}  

	status wizard_align(string str) {  
	    al_title = (str) ?  str : "";
	    tell_object(this_object(),
	      "Your alignment message is: "+al_title+"\n"+
	      "Your short() message is: "+pretitle+
	      " "+query_name()+" "+title+" "+al_title+"\n");
	    return 1;  
	}  

	status wizard_pretitle(string str) {  
	    if(str == "\"\"") str = "";
	    pretitle = (str) ?  str : ((gender == 2) ? "Lady" : "Lord");
	    tell_object(this_object(),
	      "Your pretitle message is: "+pretitle+"\n"+
	      "Your short() message is: "+pretitle+
	      " "+query_name()+" "+title+" "+al_title+"\n");
	    return 1;  
	}  

	status wizard_review() {  
	    write(" ========== Review of Wizard Messages ============"+  
	      "\nshort...."     + short(0) +
	      "\nmout....."     + msgout +  
	      "\nmin......"     + msgin +  
	      "\nmmout...."     + mmsgout +  
	      "\nmmin....."     + mmsgin +  
	      "\nminvis..."     + invis_name +  
	      "\nmclone..."     + mclone +  
	      "\nmdest...."     + mdest +  
	      "\nmtrans..."     + msgtrans +  
	      "\nedtitle.."     + edtitle +  
	      "\npretitle."     + pretitle +
	      "\ntitle...."     + title +
	      "\nalign...."     + al_title +
              "\nmquit..."      + msgquit +
	      "\nmhome...."     + msghome + "\n"+  
	      "Note: $name <wizards name>, $obj <object name>\n"+  
	      " =========================================================\n");  
	    return 1;  
	}  


	/**************************************************************************/
	/* query */

	object query_snoopers()   { return snooped;   }

	status query_edit()       { return edit_on;   }  
	string query_path() {  return current_path; }  

	string query_msgtrans()   { return msgtrans;   }  
        string query_msgquit()    { return msgquit;    }
	string query_msghome()    { return msghome;    }  
	string query_mclone()     { return mclone;     }  
	string query_mdest()      { return mdest;      }  
	string query_edtitle()    { return edtitle;    }

	/************************************************************************/
	/* toggles */

	/* edit */

	status toggle_edit(status silently) { 
	    if((edit_on = !edit_on)) {
		if(!silently) write("Edit title On.\n");
	    }
	    else {
		if(!silently) write("Edit title Off.\n");
	    }
	    return 1;
	}

	/****************************************************************************/
	/*             Wizard Actions                                               */
	/****************************************************************************/


	/****************************************************************************/
	/* promote */

	status promote(string cmd) {
	    object ob;
	    int new_level;
	    string level_name, str;

	    if(this_object() != previous_object()){ return 0;} //ash 6.96
	    if(sscanf(cmd,"%s %d",str, new_level) != 2 &&
	       sscanf(cmd,"%s %s",str, level_name) != 2) 
		{

		write("Usage: promote <who> <level|level name>\n");
		write("Notes: promotes a player to security level, <level> or "+
		  "<level name>.\n"+
		  "       level names: asp, app, creator, sage, lord, sen, elder, "+
		  " arch, or admin.\n"+
		  "       see also 'domain' command.\n");
		return 1;
	    }
	    if(!(ob = present(str,environment()))) {
		write(capitalize(str)+" is not here.\n");
		return 1;
	    }
	    if(level_name) {
		switch(level_name) {
		case "admin": case "administration":
		    new_level = SEC9;
		    break;

		case "arch":
		    new_level = SEC8;
		    break;
		case "elder":
		    new_level = SEC7;
		    break;
		case "sen": case "senior":
		    new_level = SEC6;
		    break;
		case "lord":
		    new_level = SEC5;
		    break;
		case "sage":
		    new_level = SEC4;
		    break;
		case "creator":
		    new_level = SEC3;
		    break;
		case "apprentice": case "app":
		    new_level = SEC2;
		    break;
		case "asp": case "aspirant":
		    new_level = SEC1;
		    break;
		default:
		    promote(0);
		    return 1;
		    break;
		}
	    }
	    ob->set_security_level(new_level);
	    return 1;
	}


	status domain(string str) {
	    object ob;
	    string domain, who;
	    int new_level;

	    if(!str || sscanf(str,"%s %s %d", domain, who, new_level) != 3) {
		write("Usage: domain <domain_name> <who> <level>\n\n");
		write("Notes: adds a new directory "+ DOMAIN_DIR 
		  +"domain_name/w/who for wizard who\n"+
		  "       adds domain_name if it doesn't exist.\n");
		return 1;
	    }
	    if(!(ob = present(who,environment()))) {
		write(capitalize(who)+" is not here.\n");
		return 1;
	    }
	    ob->set_domain_level(domain,new_level);
	    return 1;
	}


	void set_domain_level(string domain_name,int new_level) {
	    int i;
	    if(secure(SEC8) 
	      || call_other(DOMAIN_DIR +"access","query_domain_lord",domain_name)) {
		if(!domain_level) domain_level = ({ ({}), ({}), });
		if((i = member_array(domain_name, domain_level[0])) == -1) {
		    domain_level[0] += ({ domain_name, });
		    domain_level[1] += ({ new_level, });
		}
		else {
		    domain_level[1][i] = new_level;
		}
		create_wizard(name, domain_name);
		write("You make "+ capitalize(name) +" a creator in your domain.\n");
	    }
	    else {
		write("You are not the Lord of "+ capitalize(domain_name) +".\n");
	    }
	    return;
	}



	int query_domain_level(string domain_name) {
	    int i;

	    if(!domain_level) domain_level = ({ ({}),({}), });
	    if((i = member_array(domain_name, domain_level[0])) == -1) return 0;
	    return domain_level[1][i];
	}


	/***************************************************************************/
	/* echoall */

	status echoall(string str) { 
	    if(!secure(SEC3)) return 0;
	    if(!str) { 
		write("Usage: echoall <string>\n"); 
		return 1; 
	    } 
	    write("You echo: "+ str +"\n");
	    check_shout(str +"\n"); 
# ifdef LOG_SHOUTS
	    log_file(LOG_SHOUTS, this_player()->query_name(1)+" echoall: "+str+"\n"); 
# endif /* LOG_SHOUTS */
	    return 1; 
	} 


	/***************************************************************************/
	/* echo */

	status echo(string str) { 
	    if(!str) { 
		write ("Usage: echo <string>\n"); 
		return 1; 
	    }
	    str = filter_ansi(str); /* always filtered */
	    say(str + "\n"); 
	    write ("You echo: " + str + "\n"); 
	    return 1; 
	} 

	/************************************************************************/
	/* echoto */ 

	status echoto(string str){ 
	    object ob; 
	    string who, msg; 

	    if(!secure(SEC3)) return 0;
	    if(!str || sscanf(str, "%s %s", who, msg) != 2) { 
		write("Usage: echoto <who> <string>\n"); 
		return 1; 
	    } 
	    if(!(ob = find_living(lower_case(who)))) {
		write("No player with that name.\n"); 
		return 1; 
	    } 
	    if((ob->query_edit() || ob->query_invis())
	      && (int)ob->query_security_level() > security_level) {
		write("No player with that name.\n"); 
		return 1; 
	    } 
	    if(!ob->ansi_on()) 
		msg = filter_ansi(msg);
	    else
		msg += OFF; /* turn ansi off */

	    tell_object(ob, msg + "\n"); 
	    write("You echoto "+(string)ob->query_name()+": " + msg + "\n"); 
	    return 1; 
	} 



	/*************************************************************************/
	/* wiz */

	static status wiz(string str) { 
	    return ::chat_channel("wiz", str);

	} 


	/***************************************************************************/
	/* home */

	static status home() {  
	    string old_msg;

	    old_msg = query_mmsgout();
	    mmsgout = msghome;
	    move_player("X#"+ extract(WIZARD_DIR +query_name(1)+"/workroom",1));
	    mmsgout = old_msg;
	    return 1;  
	}  


	/************************************************************************/
	/* list_peoples */

	static status list_peoples(string arg) { 
	    string temp, domain_str;
	    object *who;
	    string str;
	    int i;
	    int a; 
	    int idle_count;
	    string location;

	    if(!secure(SEC1)) return 1;
	    str =  "Name           WL Level Age   Idle IP Address      Location\n"; 
	    str += "-----------    -- ----- ----- ---- ---------------";
	    str += " -------------------------\n"; 

	    who = filter(users(),"filter_users",this_object());  

	    if(arg == "1")
		who = sort_array(who, "by_name", this_object());
	    else if(arg == "2")
		who = sort_array(who, "by_level", this_object());
	    else if(arg == "3")
		who = sort_array(who, "by_age", this_object());
	    else if(arg == "4")
		who = sort_array(who, "by_environment", this_object());
	    else if(arg == "5")
		who = sort_array(who, "by_ip_number", this_object());
	    else 
		who = sort_array(who, "by_sec_level", this_object());

	    write(str);
	    for(i = 0; i < sizeof(who); i++) {
		str = capitalize((string)who[i]->query_real_name());
		str += (who[i]->query_invis())
		? " I"
		: "";
		str += (who[i]->query_edit())
		? " E"
		: "";
		str += (who[i]->query_disguise_on())
		? " D"
		: "";
		str += "                                ";
		str = extract(str,0,13) + " ";
		str += (string)who[i]->query_security_level()+"         ";
		str = extract(str,0,18) + " ";
		str += (string)who[i]->query_level()+"        ";
		str = extract(str,0,23) + " ";
		a = (int)who[i]->query_age();
		if(a/302400) {
		    str += (a/302400) + " W                  ";
		}
		else if(a/43200) {  
		    str += (a/43200) +" D                    ";  
		}  
		else if(a/1800) {  
		    str += (a/1800) +" h                     ";  
		}  
		else if(a/30) {  
		    str += (a/30) +" m                       ";  
		}  
		else 
		    str += (a*2) + " s                        ";
		str = extract(str,0,28) + " ";
		str += (query_idle(who[i])/60)+"            ";
		str = extract(str,0,33) + " ";
		str += query_ip_number(who[i])+"            ";
		str = extract(str,0,49) + " ";

		location = file_name(environment(who[i]));  
		if(sscanf(location, extract(WIZARD_DIR +"%s",1), temp))
		    str += "~" + temp;  
		else if(sscanf(location, "room/%s", temp))  
		    str += "#" + temp;  
		else if(sscanf(location,extract(DOMAIN_DIR+"%s/w/%s",1),domain_str,temp))
		    str += domain_str +","+ temp;
		else
		    str += location;
		str = extract(str,0,78) + "\n";
		write(str);
		if(query_idle(who[i]) > 10) idle_count++;
	    }  
	    write("\nThere are now " + i + " players ("+(i-idle_count)+" active). ");  
	    write(query_load_average() + "\n\n");  
	    return 1;  
	} 


	/*****************************************************************************/ 
	/* change directory */

	static status cd(string str) {  
	    int len;

	    if(!str) str = "~"; /* change to player dir */
	    str = make_path(str);
	    if(bad_file(str)) {
		write("Illegal filename: "+ str +"\n");
		return 1;
	    }
	    if(FILE_SIZE(str) != -2) {
		write("Error: Directory not found.\n");
	    }
	    else {
		if(str != "/") {
		    if(str[(len = strlen(str)-1)] == '/') str = extract(str,0,len-1); 
		}
		sscanf(str,"/%s",current_path);
	    }
	    tell_object(this_object(),"Current Path: /"+current_path+"\n");
	    return 1;
	}


	/**************************************************************************/
	/* trans someone */

	static status wizard_trans(string str) {
	    object ob, *obj;
	    int i, j;
	    string file;

	    if(!str) return 0;
	    if(!sizeof((obj = PROCESS_ARG(str)))) return 1;
	    for(i = 0; i < sizeof(obj); i++) {
		if((int)obj[i]->query_security_level() >= query_security_level()) {
		    write("Error: Too low security level.\n");
		    continue;
		}
		ob = environment(obj[i]);
		if(!ob) {
		    file = file_name(obj[i]);
		    if(!sscanf(file,"%s#%d",file,j)) {
			write("File: "+ file +" is loaded, cloning....\n");
			obj[i] = clone_object(file);
		    }
		}
		move_object(obj[i], environment());
		tell_object(obj[i], process_msg(msgtrans+"\n"));
		say(query_name()+" summons "+obj[i]->query_name()+".\n", obj[i]);
		write("You summon "+obj[i]->query_name()+".\n");
		if(ob) tell_room(ob,"A space-time warp suddenly pulls "+
		      obj[i]->query_name() +" away.\n");
	    }
	    return 1;
	}

	/**************************************************************************/
	/* tail */

	status tail_file(string path){  
	    if(!path) return 0;
	    path = make_path(path);  
	    if(bad_file(path)) {
		write("Illegal filename: "+ path +"\n");
		return 1;
	    }
	    if(!tail(path)) return 0;  
	    return 1;  
	}  


	/*****************************************************************************/ 
	/* print working directory */

	status pwd() {  
	    tell_object(this_object(), "Current path: /" + current_path + "\n");  
	    return 1;  
	}  


	/***************************************************************************/  
	/* places to Go - these may have to be edited from mud to mud */

	status post() {
	    move_player("X#"+POST_OFFICE);
	    return 1;
	}

	status guild() {
	    move_player("X#"+ GUILD);
	    return 1;
	}

	status pub() {
	    move_player("X#"+ PUB);
	    return 1;
	}

	status inner() {
	    move_player("X#"+ INNER);
	    return 1;
	}


	status banish(string str) {
	    if(!str) {
		notify_fail("Usage: banish <name>\n");
		return 0;
	    }
	    if(FILE_SIZE("/"+ SAVE_NO_BANISH + str +".o") > 0 ||
	      FILE_SIZE("/"+ SAVE_WIZARD + str +".o") > 0    ||
	      FILE_SIZE("/"+ SAVE_FIRST  + str +".o") > 0    ||
	      FILE_SIZE("/"+ SAVE_PLAYER + str +".o") > 0) {
		notify_fail("Error: "+str+" is already being used by a character.\n");
		return 0;
	    }

	    save_object("/"+ SAVE_BANISH + query_name(1));
	    write("Saving: "+str+" into banish directory.\n");
	    return 1;
	}

	/***************************************************************************/
	/* edit */

	void rm_ed_tbl() {
	    string file, *table;
	    int i;


	    table = (string *)SECURITY_FILE->query_current_edit();
	    if(!table) table = ({});
	    if((i = member_array(capitalize(query_name(1)),table)) == -1) return;
	    file = table[i-1];
	    SECURITY_FILE->remove_current_edit(file);
	}


	status ed_tbl(string file) {
	    int i;
	    string *table;

	    table = (string *)SECURITY_FILE->query_current_edit();
	    if(!table) table = ({});
	    if((i = member_array(file,table)) == -1) return 0;
	    write("Sorry, "+file+" is being edited by "+table[i+1]+".\n");
	    return 1;
	}

	static status edit(string file){  
	    string tmp_file;  
	    string tmp1, tmp2;
	    /* has some trouble working MOST of the time */
#if 0
	    if(!file) {
		ed();    
		return 1;  
	    }  
#endif /* 0 */

#if 1
	    if(!file) {
		current_path = "/";
		file = last_file;
		if(!sscanf(file, "%s.c", tmp1)) file = file +".c";
		write("File: "+file+"\n");
	    }
#endif
	    if(!(file = valid_write(file))) {
		write("Error: Access denied.\n");  
		return 1;  
	    }  
	    if(bad_file(file)) {
		write("Illegal filename: "+ file +"\n");
		return 1;
	    }
	    if(ed_tbl("/"+ file)) return 1;
	    ed(file,"rm_ed_tbl");  
	    return 1;  
	}  


	/**************************************************************************/
	/* update - accepts wildcards */

	static status Update(string str) {
	    update(str,1);
	    return 1;
	}

	static status update(string str, status no_reload) {  
	    object ob;  
	    string rest, *files, file, format, path;
	    object env, *temp;
	    int i, k;
	    status flag;

	    if(!str) {  
		str = "/"+ file_name(environment());
		sscanf(str, "%s#%s", str, rest);
	    }  
	    sscanf(str, "%s.c", str);
	    str = make_path(str);
	    if(bad_file(str)) {
		write("Illegal filename: "+ str +"\n");
		return 1;
	    }
	    for(i = strlen(str)-1; i && str[i] != '/'; i--);
	    path = extract(str,0,i);
	    file = extract(str,i+1);
#ifdef NO_GET_DIR_WILDCARDS
	    format = wildcard_format(file+".c");
	    files = (format_number(format)) ? get_dir(path +".") : get_dir(str +".c");
#else
	    files = get_dir(str +".c");
#endif
	    sscanf(path,"/%s",path);
	    for(k = 0; k < sizeof(files); k++) {
#ifdef NO_GET_DIR_WILDCARDS
		if(!(file = match_format(files[k],format,format))) continue;
		file = path + file;
#else
		file = path + files[k];
#endif
		ob = find_object(file);  
		if(!ob) {
		    if(!no_reload) {
			flag = 1;
			if(catch(load("/"+ file))) {
			    tell_object(this_object(),"Failed to load "+ file +"\n");
			}
		    }
		    continue;  
		}
		temp = all_inventory(ob);
		for(i = 0; i < sizeof(temp); i++) { /* move 'domain safe' to void */

		    if(query_ip_number(temp[i])) move_object(temp[i],VOID);
		}
		tell_object(this_object(),"Updating the old copy of: '"+file+"'\n");
		destruct(ob);  
		for(i = 0; i < sizeof(temp); i++) { 
		    if(!i) { /* 1st iteration only needed */
			if(catch(call_other(file,"??"))) {
			    tell_room(VOID, "You are in the Void.\n");
			    break;
			}
		    }
		    if(temp[i]) move_object(temp[i], file);
		}
		flag = 1;
	    }
	    if(!flag) {
		tell_object(this_object(),"Error: No Loaded Files that match "+ str +"\n");
		return 1;
	    }
	    return 1;
	}

	/******************************************************************************/
	/* load - accepts wildcards */

	static status load(string str) {  
	    object ob;
	    string  *files, file, format, path;
	    int i, k;
	    status flag;

	    if(!str) {  
		tell_object(this_object(), "Usage: load <file>\n");  
		return 1;  
	    }  
	    sscanf(str, "%s.c", str);
	    str = make_path(str);
	    if(bad_file(str)) {
		write("Illegal filename: "+ str +"\n");
		return 1;
	    }
	    for(i = strlen(str)-1; i && str[i] != '/'; i--);
	    path = extract(str,0,i);
	    file = extract(str,i+1);
#ifdef NO_GET_DIR_WILDCARDS
	    format = wildcard_format(file+".c");
	    files = (format_number(format)) ? get_dir(path +".") : get_dir(str +".c");
#else
	    files = get_dir(str +".c");
#endif
	    sscanf(path,"/%s",path);
	    for(k = 0; k < sizeof(files); k++) {
#ifdef NO_GET_DIR_WILDCARDS
		if(!(file = match_format(files[k],format,format))) {
		    continue;
		}
		file = path + file;
#else
		file = path + files[k];
#endif
		ob = find_object(file);
		if(ob) {
		    tell_object(this_object(),"Unloading old copy "+ file +"\n");
		    destruct(ob);
		}
		last_file = file;    /* lets store it for later use */
		if(catch(call_other(file, "??"))) {
		    tell_object(this_object(), "Error in loading: "+ file +"\n");
		    return 1;
		}
		tell_object(this_object(), "Loaded: "+ file +"\n");  
		flag = 1;
	    }
	    if(!flag) {
		tell_object(this_object(),"Error: No match for "+str+".c\n");
		return 1;
	    }
	    return 1;
	}


	/**************************************************************************/
	/* clone */

	static status clone(string file) {
	    object ob;

	    if(!file) {
		write("Usage: clone <filename>\n");
		return 1;
	    }
	    file = make_path(file);
	    if(bad_file(file)) {
		write("Illegal filename: "+ file +"\n");
		return 1;
	    }
	    sscanf(file,"%s.c",file);
	    sscanf(file,"/%s",file);
	    if(FILE_SIZE("/"+file+".c") < 0 && FILE_SIZE("/"+file) < 0) {
		tell_object(this_object(),"File: "+file+".c does not exist.\n");
		return 1;
	    }
	    last_file = file;
	    if(catch(ob = clone_object(file))) {
		tell_object(this_object(), "Error: Can't clone "+file+"\n");
		return 1;
	    }
	    write("Cloning: "+file+"\n");
	    if(ob->get()) {
		if(!ob) {
		    write("Object destructed itself after call to get()!!\n");
		    return 1;
		}
		move_object(ob,this_object());
		if(!ob) {
		    write("Object destructed itself after it move_object()!!\n");
		    return 1;
		}
		add_weight((int)ob->query_weight());          
		write("Object moved to you.\n");
	    }
	    else {
		move_object(ob,environment());
		if(!ob) {
		    write("Object destructed itself after it move_object()!!\n");
		    return 1;
		}
		write("Object moved to Room.\n");
	    }
	    if(!mclone) mclone = "$name creates $obj";
	    say(parse_msg(mclone,ob)+"\n", this_object());  
	    return 1;
	}

	/***************************************************************************/
	/* remove log */

	static status rlog() {
	    if(rm("log/errors/"+ query_name(1) +".log"))
		write("Removed Error Log.\n");
	    else
		write("Failed to remove error log.\n");
	    return 1;
	}

	/***************************************************************************/
	/* log */

	static status show_log(string who) {
	    if(!who) who = query_name(1);
	    if(bad_file(who)) {
		write("Illegal filename: "+ who +".log\n");
		return 1;
	    }
	    tail("/log/errors/"+ who +".log");  /* easier for elder to look at log */
	    return 1;
	}


	/**************************************************************************/

	/* mainlog */

	static status show_main_log() {
	    tail("/log/lpmud.log");
	    return 1;
	}

	/**************************************************************************/
	/*  Wizard Check Book */

	status check_book(mixed str) {
	    string name;
	    int amount;
	    object ob;

	    if(!str) {
		write("Usage: pay <amount> to <who>\n");
		return 1;
	    }
	    if(sscanf(str, "%d to %s", amount, name) == 2) {
		if(!(ob = present(name, environment()))) {
		    tell_object(this_object(), name+" is not present.\n");
		    return 1;
		}
		if(amount < 1) {
		    tell_object(this_object(), amount+" coins is an invalid amount.\n");
		    return 1;
		}
		ob->add_money(amount);
		say(this_player()->query_name()+
		  " pulls out a check book and writes out a check to "+
		  capitalize(name)+".\n",ob);
		tell_object(ob, query_name()+
		  " pulls out a check book and writes you a check for "+ amount+
		  " coins.\n");
		write("You write out a check for "+amount+" coins and hand it to "+
		  capitalize(name)+".\n");
#ifdef LOG_MONEY
		log(LOG_MONEY,"Payed "+ amount +" coins", 0);
#endif
		return 1;
	    }
	    check_book(0);
	    return 1;
	}
	/**************************************************************************/


	/**************************************************************************/
	/* debug log */

	static status show_debug_log() {
	    tail(DEBUG_LOG);
	    return 1;
	}


	/*****************************************************************************/
	/* mkdir */

	static status makedir(string str) {  
	    str = make_path(str);
	    if(bad_file(str)) {
		write("Illegal filename: "+ str +"\n");
		return 1;
	    }
	    if(FILE_SIZE(str) == -2) {
		tell_object(this_object(),"Error: Directory already exists.\n");
	    }
	    else if(mkdir(str))  
		write("New dir: "+ str +".\n");  
	    else  
		write("Error: Cannot make dir "+ str +"\n");  
	    return 1;  
	}  

	/*****************************************************************************/
	/* rmdir */

	static status removedir(string str) {
	    str = make_path(str);
	    if(bad_file(str)) {
		write("Illegal filename: "+ str +"\n");
		return 1;
	    }
	    if(FILE_SIZE(str) != -2) {
		tell_object(this_object(),"Error: Directory does not exists.\n");
	    }
	    else if(rmdir(str))  
		write("Removed dir: "+ str +".\n");  
	    else if(sizeof(get_dir(str+"/.")))
		write("Error: Directory "+str+" still contains files.\n");
	    else  
		write("Error: Cannot remove dir "+ str +".\n");  
	    return 1;  
	}  


	/**************************************************************************/
	/* snoop */

	static status snoopers_who() {
	    int i;
	    object victim;
	    object *ob;

            if(!secure(SEC10) && !secure(SEC9)) {
		notify_fail("Error: No access to command.\n");
		return 0;
	    }
	    ob = users();
	    for(i=0; i<sizeof(ob); i++) {
		if((status)ob[i]->query_security_level()) {
		    if(victim = (object)ob[i]->query_snoopers()) {
			write(capitalize((string)ob[i]->query_name(1))+" -> "+
			  capitalize((string)victim->query_name(1))+"\n");
		    }
		}
	    }
	    return 1;
	}

	static status snoop_on(string str){  
	    object ob;  

	    if(!str) {  
		snoop(0);  
		if(snooped) {
		    if(!secure(SEC8)) {  

		    }
#     ifdef LOG_SNOOPERS  
		    log(LOG_SNOOPERS,"Stopped snooping "+snooped->query_name()+".\n");  
#     endif /* LOG_SNOOPERS */
		    snooped=0;  
		}  
		return 1;  
	    }  
	    if(!secure(SEC5)) return 0;  
	    if(!(ob = find_player(str))) {  
		write("Could not find "+capitalize(str)+".\n");  
		return 1;  
	    }  
	    if((int)ob -> query_security_level() > security_level ) { 
		write("Error: Higher security level needed\n"); 
		return 1; 
	    } 
	    if(snooped) snoop_on(0);
//          if(!secure(SEC8)) {
            if(security_level < 60 ) {
		tell_object(ob, query_name()+" is now watching your every move.\n");  
	    }
	    snoop(ob);  
	    snooped = ob;
# ifdef LOG_SNOOPERS  
	    log(LOG_SNOOPERS,"Started snooping "+snooped->query_name()+".\n");  
# endif /* LOG_SNOOPERS */
	    return 1;  
	}  


	/*************************************************************************/
	/* force */

	static status force_player(string str) {  
	    string who, what;  
	    object ob;  

	    if(!secure(SEC3)) return 0;
	    if(!str) {
		write("Usage: command <who> <cmd>\n");
		return 1;
	    }  
	    if(sscanf(str, "%s to %s", who, what) == 2 ||  
	      sscanf(str, "%s %s", who, what) == 2) {  
		if(!(ob = find_living(who))) {  
		    tell_object(this_object(), "No such player.\n");  
		    return 1;  
		}  
		if((int)ob->query_security_level() > security_level) {  
		    tell_object(this_object(), 
		      "You can't force a higher creator than you!\n");  
		    return 1;  
		}  
		tell_object(ob, query_name()+" forces you to: "+what+"\n");  
		command(what, ob);  
#   ifdef LOG_FORCE
		log(LOG_FORCE,"Forced: "+ob->query_name(1)+" "+what+"\n",0);
#   endif /* LOG_FORCE */  
		tell_object(this_object(), "You FORCE "+capitalize(who)+" to "+what+"\n"); 
		return 1;  
	    }  
	    return 0;  
	}  


	/***************************************************************************/
	/* zap */

	static status zap(string str){  
	    object ob;  

	    if(!str)  
		ob = primary_attack;  
	    else  
		ob = present(lower_case(str), environment());  
	    if(!ob || !living(ob)) {  
		tell_object(this_object(), "Zap whom?\n");  
		return 1;  
	    }  
	    tell_object(this_object(), "You summon a flash of lightning...\n");
	    say(query_name() +" summons lightning from the heavens...\n");
	    ob->hit_player(100000);
	    return 1;  
	}  


	/***************************************************************************/
	/* heal */

	static status heal(string str){  
	    object ob;  

	    if(!secure(SEC3)) return 0;
	    if(!str) {
		write("Usage: heal <who>\n");
		return 1;
	    }  
	    if(!(ob = find_living(lower_case(str)))) {
		write("No such person is playing now.\n");  
		return 1;  
	    }  
	    call_other(ob, "heal_self", 100000);  
	    tell_object(ob, "You are healed by " + query_name() + ".\n");  
	    write("You HEAL "+ capitalize(str) +". Function logged.\n");  
            log_file("HEALS", "Name: "+str+" was healed by "+
	      query_name(1)+", at time: "+
	      ctime(time()) +"\n"); 
	    return 1;  
	}  


	/**************************************************************************/
	/* show stats - isn't complete */

	static status stat(string str) {  
	    object ob;  

	    if(!str) {
		write("Usage: stat <who>\n");
		return 1;
	    }
	    ob = present(str, environment());
	    if(!ob || !living(ob)) 
		if(!(ob = find_living(lower_case(str)))) {
		    write("No such person is playing now.\n");  
		    return 1;  
		}  
	    if(ob->query_invis() && (int)ob->query_security_level() > security_level) { 
		write("No such person is playing now.\n");  
		return 1;  
	    }  
	    ob->show_stats();  
	    return 1;  
	}  

	/**************************************************************************/
	/* skstat */

	static status sk_stat(string str) { 
	    object ob;  
	    string skill;

	    if(!str) {
		write("Usage: skstat <who> <class>\n");
		return 1;
	    }
	    sscanf(str,"%s %s", str, skill);
	    ob = present(str, environment());
	    if(!ob || !living(ob)) 
		if(!(ob = find_living(lower_case(str)))) {
		    write("No such person is playing now.\n");  
		    return 1;  
		}  
	    if(ob->query_invis() && (int)ob->query_security_level() > security_level) { 
		write("No such person is playing now.\n");  
		return 1;  
	    }
	    if(skill && !ob->query_class(skill)) {
		write(capitalize(str) +" is not in the class "+ skill +".\n");
	    }
	    else if(skill) {
		write(capitalize(str) +" is has the following skills in the class "+
		  skill +",\n");
		call_other(ob,"query_"+ skill +"_stats");
	    }  
	    write(capitalize((string)ob->query_pronoun()) +" is in the "+
	      "following classes: "+ implode((string *)ob->query_classes(),", ")+
	      ".\n");
	    return 1;  
	}  

	/**************************************************************************/
	/* shutdown */

	static status shut_down_game(string str){  
	    if(!str) {  
		write("You must give a shutdown reason as argument.\n");  
		return 1;  
	    }  
	    shout("Game is shut down by " + capitalize(name) + ".\n");  
	    log_file("GAME_LOG", ctime(time())+" Game shutdown by "+name+"("+str+")\n"); 
	    if(secure(SEC7))
		shutdown();  
	    else
		call_other(SHUTD,"shut",5); /* 5 min. shutdown */
	    return 1;  
	}  


	/****************************************************************************/
	/* rm */

	static status Delete(string str) {
	    delete(str,1);
	    return 1;
	}

	status filter_ftime(string file, mixed *info) {
	    if(file == ".." || file == ".") return 0;
	    if(file_time(info[0] + file) < info[1]) return 1;
	    return 0;
	}



	varargs static status delete(string str, status prompt_off) {
	    int date, year, ftime;
	    string month;
	    int i;
	    string tmp1, tmp2;
	    string path, file;

	    if(!str) {
		write("Usage: rm <file> { options: <-a> }\n\n"+
		  "Notes: <-a> delete all files without prompting\n"+
		  "       -t<date>:<month>:<year> <file> deletes file before date\n"+
		  "       Rm == rm -a\n"+
		  "       wildcard \"*\" accepted\n");
		return 1;
	    }

	    /* scan for -t switch */

	    if(sscanf(str,"-t%d:%s:%d %s", date, month, year, str) == 4) {
		if((ftime = rtime("xxx "+month+" "+date+" 00:00:00 "+ year)) == -1) {
		    write("-t time format, date:month:year\n");
		    return 1;
		}
		write("Deleting Files before "+ date +" "+ month +" "+ year +"\n");
	    }

	    /* scan for -a switch */

	    if(sscanf(str,"%s-a%s", tmp1, tmp2)) {
		prompt_off = 1;
		str = tmp1;
		if(str != "") {
		    while(str[strlen(str)-1] == ' ') {
			str = extract(str,0,strlen(str)-2);
		    }
		}
	    }

	    /* has wizard|player got write access */

	    if(!(str = valid_write(str))) {
		write("Invalid delete access.\n");
		return 1;
	    }
	    str = "/" + str;
	    if(bad_file(str)) {
		write("Illegal filename: "+ str +"\n");
		return 1;
	    }

	    /* extract path and filename */

	    for(i = strlen(str) - 1; (str[i] != '/' && i >= 0); i--);
	    new_text = extract(str,0,i);
	    file = extract(str,i+1,strlen(str));

	    if(!file || file == "") {
		write("Invalid filename: "+str+"\n");
		new_text = 0;
		return 1;
	    }
	    if(file_size(extract(new_text,0,strlen(new_text)-2)) != -2) {
		write("Directory: "+new_text+" does not exist.\n");
		new_text = 0;
		return 1;
	    }
#ifdef NO_GET_DIR_WILDCARDS
	    sformat = wildcard_format(file);
	    list = (format_number(sformat)) ? get_dir(new_text +".") : get_dir(str);
#else
	    list = get_dir(new_text + file);
#endif

	    if(ftime) {
		list = filter(list,"filter_ftime",this_object(),({new_text,ftime}));
	    }

	    if(!sizeof(list)) {
		write("No match found for "+str+"\n");
		return 1;
	    }
	    line = 0;

	    while(1) {
		if(list[line] == "." || list[line] == ".." 
#ifdef NO_GET_DIR_WILDCARDS
		  || !match_format(list[line],sformat,sformat)
#endif
		  || file_size(new_text+list[line]) < 0) {
		    line++;
		    if(line == sizeof(list)) {
			write("No File matches found for "+str+"\n"+
			  "Use 'rmdir' to remove directories.\n");
			return 1;
		    }
		    continue;
		}
		break;
	    }

	    if(prompt_off) {
		delete_all_files("y");
	    }
	    else {
		write("Remove "+new_text+list[line]+" (y/n/q) [n]: ");
		input_to("delete_files_prompt");
	    }
	    return 1;
	}

	static void delete_files_prompt(string answer) {
	    if(answer == "q") {
		write("Ok.\n");
		return;
	    }
	    if(answer == "y") {
		if(line < sizeof(list)) {
		    if(!rm(new_text + list[line])) {
			write("Failed to delete: ");
		    }
		    else { 
                        log("security", this_player()->query_name()+" deleted "+
                          new_text+list[line],0);
			write("Deleted: ");
		    }
		    write(new_text+list[line]+"\n");
		}
	    }

	    /* skip over directories */

	    if(++line < sizeof(list)) {
		while(1) {
		    if(list[line] == "." || list[line] == ".." 
#ifdef NO_GET_DIR_WILDCARDS
		      || !match_format(list[line],sformat,sformat)
#endif
		      || file_size(new_text+list[line]) < 0) {
			line++;
			if(line == sizeof(list)) {
			    write("Ok.\n");
			    return;
			}
			continue;
		    }
		    break;
		}
	    }

	    if(line < sizeof(list)) {
		write("Remove "+new_text + list[line]+" (y/n/q) [n]: ");
		input_to("delete_files_prompt");
	    }
	    else {
		write("Ok.\n");
	    }
	}


	static void delete_all_files(string answer) {
	    int start, skips;

	    if(answer == "n") {
		write("Ok.\n");
		return;
	    }

	    for(start = line; line < sizeof(list); line++) {
		if(list[line] == "." || list[line] == ".." 
#ifdef NO_GET_DIR_WILDCARDS
		  || !match_format(list[line],sformat,sformat)
#endif
		  || file_size(new_text+list[line]) < 0) {
		    if(++skips > 30) break; /* mainly for NO_GET_DIR_WILDCARDS */
		    line++;
		    if(line == sizeof(list)) {
			write("Ok.\n");
			return;
		    }
		    continue;
		}
		if(!rm(new_text+list[line])) {
		    write("Failed to delete: ");
		}
		else { 
                    log("security", this_player()->query_name()+" deleted "+
                        new_text+list[line],0);
		    write("Deleted: ");
		}
		write(new_text+list[line]+"\n");
		skips = 0;
		if(line - start > 20) break;
	    }
	    if(line != sizeof(list)) {
		write("Continue Deleting (y/n) [y]: ");
		input_to("delete_all_files");
		line -= 1;
	    }
	    else {
		write("Ok.\n");
	    }
	}


	/****************************************************************************/
	/* ls */

	static status dir(string str) { 
	    int i, start; 
	    status verbose;
	    string tmp1, tmp2;
	    string path, file;  
	    int len;

	    if(!str) str = "";


	    /* scan for help */

	    if(sscanf(str, "%s-h%s", tmp1, tmp2)) {
		write("Usage: dir { options: <path><-#><-v><-h> }\n\n"+
		  "Notes: writes out list of files.\n"+ 
		  "       <path> directory path, or wildcard filename\n"+
		  "       <-#>   start file list after file number#\n"+
		  "       <-v>   list files in verbose mode\n"+
		  "       <-h>   this help file\n");
		write("       Example: dir / -3-v\n");
		return 1;
	    }


	    /* scan for verbose */

	    if(sscanf(str,"%s-v%s", tmp1, tmp2)) {
		str = tmp1;
		if(str != "") {
		    while(str[strlen(str)-1] == ' ') {
			str = extract(str,0,strlen(str)-2);
		    }
		}
		str += tmp2;
		verbose = 1;
	    }

	    /* scan for start number */

	    line = 0;
	    if(sscanf(str, "%s-%d", tmp1, line)) {
		if(tmp1 != "") {
		    while(tmp1[strlen(tmp1)-1] == ' ') {
			tmp1 = extract(tmp1,0,strlen(tmp1)-2);
		    }
		}
		str = tmp1;
	    }

	    /* a fix */

	    str = make_path(str);
	    if(bad_file(str)) {
		write("Illegal filename: "+ str +"\n");
		return 1;
	    }
	    if(str[(len = strlen(str)-1)] == '/') str = extract(str,0,len-1);
	    if(str == "" || FILE_SIZE(str) == -2) str += "/*";

	    /* has wizard|player got read access */


	    if(!(str = valid_read(str))) {
		write("No directory access.\n");
		return 1;
	    }
	    str = "/"+ str;

	    if(!sscanf(str,"%s*%s",tmp1, tmp2)) {
		if(file_size(str) == -2) {
		    str += "/";
		    if(!(str = valid_read(str))) {
			write("No directory access.\n");
			return 1;
		    }
		    str = "/"+ str;
		}
	    }

	    /* extract path and filename */

	    for(i = strlen(str) - 1; (str[i] != '/' && i >= 0); i--);
	    new_text = extract(str,0,i);
	    file = extract(str,i+1,strlen(str));

	    if(!file || file == "." || file == "") file = "*";

#ifdef NO_GET_DIR_WILDCARDS
	    sformat = wildcard_format(file);
	    list = (format_number(sformat)) ? get_dir(new_text +".") : get_dir(str);
#else
	    list = get_dir(str);
#endif
	    line = 0;
	    if(!sizeof(list)) {
		write("Empty Directory or No match for "+str+"\n");
		return 1;
	    }  
	    if(verbose)
		print_verbose("");
	    else
		print_files(""); 
	    return 1;  
	}  

	static void print_files(string answer) {
	    string name; 
	    int i, finish, columns;  
#ifdef DETAILED_SHORT
	    string prefix;
	    int f_size;
#endif
	    if(answer == "n" || answer == "q") {
		write("Ok.\n");
		return;
	    }
	    sscanf(answer,"%d",line); 
	    if(line >= sizeof(list)) line = sizeof(list) - 52; 
	    if(line < 0) line = 0;
	    finish = line + 52; 
	    if(finish > sizeof(list)) finish = sizeof(list); 

	    write("Current Path: /"+((current_path == "") ? "\n" : current_path+"/\n")); 
	    if(new_text != "/" + current_path + "/") {
		if(current_path != "" || (current_path == "" && new_text != "/")) {
		    write("     ls Path: "+ new_text +"\n");
		}
	    }
	    write("\n"); 
	    for(i = line; i < finish; i++) { 
		if(list[i] == "." || list[i] == ".."
#ifdef NO_GET_DIR_WILDCARDS
		  || !match_format(list[i],sformat,sformat)
#endif
		) {
		    finish++;
		    if(finish > sizeof(list)) finish = sizeof(list); 
		    continue;
		}
#if 0
		if(!valid_read(new_text + list[i])) { 
		    name = "?????                                            "; 
		} 
		else
#endif
		if(file_size(new_text + list[i]) == -2) {  
#if 0
		    if(!valid_read(new_text+list[i]+"/"))
			name = "?????/                                              ";
		    else
#endif
#ifdef DETAILED_SHORT
			name = "  - "+ list[i] + "/                                    ";
		}
		else {
		    (f_size = file_size(new_text+list[i]));
		    f_size /= 1024;
		    if (f_size > 999) {
			prefix = sprintf("%2dM ", (f_size / 1000));
		    } else {
			prefix = sprintf("%3d ", f_size);
		    }
		    if(!find_object(new_text+list[i]))
			name = prefix+list[i] + "                                ";
		    else
			name = prefix+"*"+list[i]+"                            ";
		}
#else
		name = list[i] + "/                                    ";  
	    }
	    else { 
		if(!find_object(new_text+list[i])) 
		    name = list[i] + "                                   ";  
		else 
		    name = "*"+list[i]+"                                    "; 
	    }
#endif /*DETAILED_SHORT*/ 

	    name = extract(name,0,16);
	    if(++columns > 4) {
		columns = 1;
		write("\n");  
	    }
	    write(name);
	}  
	if(finish != sizeof(list)) {
	    line = finish;
	    write("\n("+(line+1)+"-"+finish+")/"+sizeof(list)+" Files\n");
	    write("\nContinue (y/n/#num) [y]: ");
	    input_to("print_files");
	    return;
	} 
	write("\nOk.\n");  
    }  


    static void print_verbose(string answer) {
	string name, date; 
	int i, finish;  
	int f_size;

	if(answer == "n") {
	    write("Ok.\n");
	    return;
	}
	sscanf(answer,"%d",line); 

	if(line >= sizeof(list)) line = sizeof(list) - 16; 
	if(line < 0) line = 0;
	finish = line + 16; 
	if(finish > sizeof(list)) finish = sizeof(list); 

	write("Current Path: /"+((current_path == "") ? "\n" : current_path+"/\n")); 
	if(new_text != "/" + current_path + "/") {
	    if(current_path != "" || (current_path == "" && new_text != "/")) {
		write("     ls Path: "+ new_text +"\n");
	    }
	}
	write("\n"); 
	for(i = line; i < finish; i++) { 
	    if(list[i] == "." || list[i] == ".."
#ifdef NO_GET_DIR_WILDCARDS
	      || !match_format(list[i],sformat,sformat)
#endif
	    ) {
		finish++;
		if(finish > sizeof(list)) finish = sizeof(list); 
		continue;
	    }
	    if(!valid_read(new_text + list[i])) { 
		name = "?????                                              ";
		name = extract(name,0,20) + " Size: Unknown                       ";
		name = extract(name,0,40) + " Access: None\n";
	    } 
	    else if ((f_size = file_size(new_text + list[i])) == -2) {  
		if(!valid_read(new_text+list[i]+"/")) {
		    name = "?????/                                           ";
		    name = extract(name,0,20)+" Size: Unknown                       ";
		    name = extract(name,0,40)+" Access: None\n";
		}
		else {
		    string *tmp_dir;

		    name = list[i] + "/                                    ";  
		    name = extract(name,0,20) + " Size: ";
		    tmp_dir = get_dir(new_text+list[i]+"/.");
		    if(!tmp_dir) tmp_dir = ({});
		    name += sizeof(tmp_dir) + " Files\n";
		}
	    }
	    else { 
		if(!find_object(new_text+list[i])) 
		    name = list[i] + "                                   ";  
		else 
		    name = "*"+list[i]+"                                    "; 
		name = extract(name,0,20) + " Size: "+f_size+" bytes                  ";
		if(valid_write(new_text+list[i])) {
		    name = extract(name,0,40) + " Access: R/W";
		    name += "  Date: "+ DATE(file_time(new_text+list[i]))+"            ";
		}
		else {
		    name = extract(name,0,40) + " Access: Read";
		    name += " Date: "+ctime(file_time(new_text+list[i]))+"            ";
		}
		name = extract(name,0,78);
		name += "\n";
	    }
	    write(name);
	}  
	if(finish != sizeof(list)) {
	    line = finish;
	    write("\n("+(line+1)+"-"+finish+")/"+sizeof(list)+" Files\n");
	    write("Continue (y/n/#num) [y]: ");
	    input_to("print_verbose");
	    return;
	} 
	write("Ok.\n");  
    }


    /***************************************************************************/
    /* duplicate: copy another object, this will not set values in that object */

    static status duplicate(string str) {
	int i, j, clone_number;
	string what, where, file;
	object *ob, *dest;
	object cl;

	if(!str) {
	    write("Usage: Dup <object> {clone it to yourself}\n"+
	      "       Dup <object> to <object2>\n"+
	      "       Dup <object::object2>\n\n"+
	      "Notes: Dup <file.c>  can clone a file\n"+
	      "       Duplicate makes clones of existing objects, note that it\n"+
	      "       does not set values in an object.\n");
	    return 1;
	}
	if(!sscanf(str,"%s to %s", what, where)) { 
	    if(!sscanf(str,"%s::%s", what, where)) { 
		what = str;
		where = "me";
	    }
	}
	if(!sizeof((dest=PROCESS_ARG(where)))) return 1;
	if(!sizeof((ob=PROCESS_ARG(what)))) return 1;
	for(i = 0; i < sizeof(ob); i++) {
	    if(!sscanf(file_name(ob[i]),"%s#%d", file, clone_number)) 
		file = file_name(ob[i]); 
	    for(j = 0; j < sizeof(dest); j++) {
		if(catch(cl = clone_object(file))) {
		    write("Error in cloning: "+file+"\n");
		    continue;
		}
		move_object(cl, dest[j]);
		write("Duplicated: "+file+", moved to "+dest[i]->short()+"\n");
	    }
	}
	return 1;
    }


    /*****************************************************************************/
    /* clean: destruct all objects in an object, except those in the 'keep' list */
    /*        This will not destruct interactive players */

    static status clean(string str) {
	status kflag;
	object *ob, *inv;
	string name, filename;
	int i, j, k, l, count;

	if(!str) {
	    write("Usage: clean <object>\n\n"+
	      "Notes: Destructs inventory of <object> except for interactive\n"+
	      "       players, and objects with id \"guild_object\", \"soul\",\n"+
	      "       or "+query_name(1)+"\n");
	    return 1;
	}
	if(!sizeof((ob = PROCESS_ARG(str)))) return 1;

	/* hmm.....'clean users' ;) */

	for(l = 0; l < sizeof(ob); l++) {  
	    while(sizeof((inv = all_inventory(ob[l])))) {
		if((count++) > 4) break; /* object depth of destruction */
		for(i = 0; i < sizeof(inv); i++){
		    for(j = 0; j < sizeof(KEEP); j++) if(inv[i]->id(KEEP[j])) kflag = 1;
		    if(!kflag){
			if(living(inv[i]) && interactive(inv[i])) continue;
			name = (inv[i]->short()) ? (string)inv[i]->short()
			: "Invisible Object";
			filename = file_name(inv[i]);
			write("Destructing->"+filename+"<->"+name+".\n");
			destruct(inv[i]);
		    }
		    kflag = 0;
		}        
	    }
	    if(ob[l]->query_name())
		write((string)ob[l]->query_name()+" has been cleaned.\n");
	    else
		write((string)ob[l]->short()+" has been cleaned.\n");
	}
	return 1;
    }


    /***************************************************************************/
    /* bomb: get rid of all objects in a room except players */

    static status bomb(){
	clean("room");
	return 1;
    }


    /****************************************************************************/
    /* destruct: destructs object and object lists. This will destruct    */
    /*           individual players, but won't if they are part of a list */

    static status dest_ob(string arg) {
	int i;
	object *ob;
	string name, filename, what, who;

	if(!arg){
	    write("Usage: Dest <object>\n\n"+
	      "Notes: Will only dest specifically named interactive players.\n"+
	      "       For example: 'dest all in room' won't destruct players,\n"+
	      "                    but 'dest zilanthius' will dest the player\n");
	    return 1;
	}
	if(!sizeof((ob = PROCESS_ARG(arg)))) return 1;
	for(i = 0; i < sizeof(ob); i++){
	    /* "dest users" is invalidated :) */

	    if(living(ob[i]) && interactive(ob[i]) && sizeof(ob) > 1) continue;
	    if(living(ob[i]) && interactive(ob[i])
	      && arg != (string)ob[i]->query_real_name()) continue;
	    if(catch((name = (string)ob[i]->short()))) {
		write("Error in short.\n"); /* I have had this!! */
	    }
	    else {
		if(!secure(SEC5)) {
		    if(!present(arg) && !present(arg, environment())) {
			write("There is no "+arg+" here.\n");
			return 1;
		    }
		}
		if(!mdest) mdest = "$name destructs $obj";
		say(parse_msg(mdest+"\n", ob[i]));
	    }
	    if(!name) name = "Invisible Object";
	    filename = file_name(ob[i]);
	    write("Destructing->"+filename+"<->"+name+".\n");
	    destruct(ob[i]);
	}
	return 1;
    }


    /***************************************************************************/
    /* goin: go into an object */

    static status goin(string str) {
	object *ob;
	if(!str){
	    write("Usage: Goin <object>\n\n"+
	      "Notes: Go into an object, gets upset if object is inside you.\n"+
	      "       If it does try 'Put me::<object>'\n");
	    return 1;
	}
	if(!sizeof((ob = PROCESS_ARG(str)))) return 1;
	if(sizeof(ob) > 1) {
	    write("You cannot go into an object list, using first element.\n");
	}
	if(ob[0] != this_player()) {
	    if(environment(ob[0]) == this_player()) {
		write("You cannot go into an object in your inventory.\n");
		return 1;
	    }
	    move_object(this_player(),ob[0]);

	    command("look", this_player());
	}
	else {
	    write("You cannot go into yourself!\n");
	}
	return 1;
    }


    /***************************************************************************/
    /* goto: goto the room of a player, otherwise goin object */

    static status goto(string str){
	object *ob, env;
	string sh;
	string file;
	int clone_number;

	if(!str){
	    write("Usage: Goto <object>\n\n"+
	      "Notes: Goto the environment of the <object>, otherwise go into\n"+
	      "       the <object>. If you find yourself inside a monster,\n"+
	      "       then the monster is loaded, but not cloned ;).\n");
	    return 1;
	}
	if(!sizeof((ob = PROCESS_ARG(str)))) return 1;
	if(sizeof(ob) > 1) {
	    write("You cannot goto an object list, using first element.\n");
	}
	sscanf(file_name(ob[0]),"%s#%d",file, clone_number);
	sh = (ob[0]->short()) ? (string)ob[0]->short()
	: file_name(ob[0]);
	if(!file) {
	    write(sh+" is not cloned, Loaded file exists.\n"+
	      "Moving into "+sh+"\n");
	    move_object(this_player(), ob[0]);
	}
	else { 
	    env = environment(ob[0]);
	    if(!env){
		write("Could not find environment of "+sh+".\n"+
		  "Moving into "+sh+".\n");
		say(query_name() +" "+ mmsgout +".\n");
		move_object(this_player(), ob[0]);
		say(query_name() +" "+ mmsgin +".\n");
	    }
	    else {
		if(env == this_player()) {
		    write("You cannot goto "+sh+"\n"+
		      sh+" is in your inventory.\n");
		    return 1;
		}
		write("You goto "+sh+"\n");
		say(query_name() +" "+ mmsgout +".\n");
		move_object(this_player(),env);
		say(query_name() +" "+ mmsgin +".\n");
	    }
	}
	command("look",this_player());
    command("vmap",this_player());
	return 1;
    }


    /****************************************************************************/
    /* put: move objects about */

    static status Put(string str){
	int i;
	object *ob1, *ob2;
	string what, who, short_desc;

	if(!str){
	    write("Usage: put <object> in <where> (may cause ambiguitites)\n"+
	      "       put <object::where>\n\n"+
	      "Notes: Reposition objects. The first variation is for the sake\n"+
	      "       of compatability with the original 'put', but it can be\n"+
	      "       ambiguous. The second format eliminates that.\n");

	    return 1;
	}
	if(!sscanf(str,"%s::%s",what,who)) {
	    if(!sscanf(str,"%s in %s",what,who)){
		Put(0);
		return 1;
	    }
	}
	if(!sizeof((ob1 = PROCESS_ARG(what)))) return 1;
	if(!sizeof((ob2 = PROCESS_ARG(who)))) return 1;
	if(sizeof(ob2) > 1){
	    write("You cannot put into an object list, using first element.\n");
	}
	for(i = 0; i < sizeof(ob1); i++) {
	    if(environment(ob2[0]) == ob1[i]){
		if(environment(ob1[i])) {
		    move_object(ob2[0], environment(ob1[i]));
		}
		else{
		    write("You cannot move an object into itself!\n");
		    return 1;
		}
	    }  
	    if(ob1[i] != ob2[0]) {
		move_object(ob1[i],ob2[0]);
		if(!ob1[i]) { /* This has happen, how unusual */
		    write("Object has destructed itself, on moving.\n");
		    continue;
		}
		short_desc = (ob1[i]->short()) ? (string)ob1[i]->short()
		: file_name(ob1[i]);
		write(capitalize(short_desc)+" has been moved into "+
		  ob2[0]->short()+".\n");
	    }
	}
	return 1;
    }


    /***************************************************************************/
    /* get: move objects from anywhere into yourself */

    static status move(string str) {
	int i;
	object *ob;
	if(!str){
	    write("Usage: Get <object>\n\n"+
	      "Notes: Get any object, no get() or add_weight() checks.\n"+
	      "       An alternative to 'put <object>::me'\n"); 
	    return 1;
	}
	if(!sizeof((ob = PROCESS_ARG(str)))) return 1;
	for(i = 0; i < sizeof(ob); i++){
	    string short_desc;
	    move_object(ob[i],this_player());
	    short_desc = (ob[i]->short()) ? (string)ob[i]->short()
	    : file_name(ob[i]);     
	    write("Getting: "+short_desc+"\n");
	}
	write("Ok.\n");
	return 1;
    }


    /***************************************************************************/
    /* patch: patch a function in an object, can have two arguments */

    status patch(string str) {
	mixed last_arg;
	string type_arg;
	object *ob;
	string who, do_str, arg1, arg2;
	int i, iarg1, iarg2;
	status use_int1, use_int2, load;

	if(!str){
	    write("Usage: Patch <object::function>\n"+
	      "       Patch <object::function::arg1>\n"+
	      "       Patch <object::function::arg1::arg2>\n\n"+
	      "Notes: Calls to fn, 'function' in <object>. Function can be\n"+
	      "       called with up to 2 arguments. Patch <object> attempts\n"+
	      "       to load the object.\n");
	    return 1;
	}
	if(sscanf(str,"%s::%s::%s::%s",who, do_str, arg1, arg2) == 4){
	    if(sscanf(arg1,"%d",iarg1) == 1) use_int1 = 1;
	    if(sscanf(arg2,"%d",iarg2) == 1) use_int2 = 1;
	}
	else if(sscanf(str,"%s::%s::%s", who, do_str, arg1) == 3) {
	    if(sscanf(arg1,"%d",iarg1) == 1) use_int1 = 1;
	}
	else if(!sscanf(str,"%s::%s", who, do_str)) {
	    who = str;    
	    load = 1;    
	}
	if(!sizeof((ob = PROCESS_ARG(who)))) return 1;
	for(i = 0; i < sizeof(ob); i++) {
            if((!secure(SEC9) && !secure(SEC10)) && MASTER->valid_master_call(ob[i])) {
		write("Invalid Call to "+ file_name(ob[i]) +"\n");
		continue;
	    }
            if(!secure(SEC3) && ob[i] != this_object()) {
              write("Illegal patch! "+file_name(ob[i])+"\n");
              log_file("patches", this_object()->query_name() +" patched "+
                file_name(ob[i]) +". String: "+ str +" at "+
                ctime(time())+"\n");
              return 1;
            }
	    write("\nObject: "+file_name(ob[i])+"\n");
	    if(use_int1 && use_int2)
		last_arg = (mixed)call_other(ob[i],do_str,iarg1,iarg2);
	    else if(use_int1 && arg2)
		last_arg = (mixed)call_other(ob[i],do_str,iarg1,arg2);
	    else if(arg1 && use_int2)
		last_arg = (mixed)call_other(ob[i],do_str,arg1,iarg2);
	    else if(use_int1)
		last_arg = (mixed)call_other(ob[i],do_str,iarg1);
	    else if(arg1)
		last_arg = (mixed)call_other(ob[i],do_str,arg1);
	    else if(do_str) 
		last_arg = (mixed)call_other(ob[i],do_str);
	    write("Result:\n");     
	    show_results(last_arg);
	    if(do_str)
		log_file("patches", query_name(1)+", Patched:"+ob[i]->short()+"("+
		  file_name(ob[i])+"), Call:"+do_str+".\n");
	    if(!ob[i]) {
		write("Object destructed itself!\n");
	    }
	    else if(!(last_arg || load)) {
		string sh;
		sh = (ob[i]->short()) ? (string)ob[i]->short()+", "+file_name(ob[i])
		: "/" + file_name(ob[i]);
		if(function_exists(do_str, ob[i])) {
		    write("Function: \""+do_str+"\" exists in "+sh+"\n");
		}
		else {
		    write("Function: \""+do_str+"\" does not exist in "+sh+"\n");
		}
	    }
	}

	return 1;
    }


    /***************************************************************************/
    /* Reset: do a reset(0) in an object */

    varargs static status Reset_ob(string arg, status reset_arg){
	int i;
	object *ob;
	string name, filename;

	if(!arg){
	    write("Usage: reset <object> (normal reset)\n"+
	      "       Reset <object> (full reset)\n\n"+
	      "Notes: calls reset() in <object>\n"+
	      "       Use reset <object>, use Reset only if necessary.\n");
	    return 1;
	}
	if(!sizeof((ob = PROCESS_ARG(arg)))) return 1;
	for(i = 0; i < sizeof(ob); i++){
	    name = (string)ob[i]->short();
	    if(!name) name = "Invisible Object";
	    filename =file_name(ob[i]);
	    write("Reset("+reset_arg+")->"+filename+"<->"+name+".\n");
	    call_other(ob[i], "reset", reset_arg);
	}
	return 1;
    }


    /***************************************************************************/
    /* reset: do a reset(1) in an object */

    static status reset_ob(string arg) {
	Reset_ob(arg,1);
	return 1;
    }


    /****************************************************************************/
    /* light: add or subtract from the light in a room */

    static status set_lighting(string str) {
	int n;
	string what;

	if(!str) {
	    write("Light Strength: " + set_light(0) + "\n");
	    write("Usage: light <+/- int>\n\n"+
	      "Notes: This adjusts the amount of light you give out.\n"+
	      "       'light 100' will light most rooms :)\n");
	    return 1;
	}
	if(sscanf(str, "%d", n) == 1) {
	    adj_light(n);
	    if(n > 0) {
		say(query_name() + " waves a hand and it lightens the room.\n");
		write( "You wave your hand and the room lightens up.\n");
	    }
	    else
		tell_room(environment(this_player()),
		  "Everything suddenly gets darker.\n");
	}
	else
	    set_lighting(0);
	return 1;  
    }


    /***************************************************************************/
    /* grab: grab some code out of one file and put it in another */

    static status grab(string str){
	string filename1, filename2, txt, tmp;
	int line1, line2;
	int finish;

	if(!str){
	    write("Usage: grab line1,line2 file1 file2\n"+
	      "       grab line1 file1 file2\n\n"+
	      "Notes: Copies from line1 of file1 to another file\n"+
	      "       There is a 500 line limit to what can copied.\n");
	    return 1;
	}
	if(sscanf(str,"%d,%d %s %s",line1,line2,filename1,filename2) != 4){
	    if(sscanf(str,"%d %s %s", line1, filename1, filename2) != 3) {
		write("Wrong Arguments!\n\n"+
		  "Usage: Grab line1,line2 file1 file2>\n");
		return 1;
	    }
	}
	tmp = valid_read(filename1);

	if(!tmp || bad_file(tmp) || file_size("/"+tmp) < 0){
	    write(filename1+" does not exist or you do not have access.\n");
	    return 1;
	}
	filename1 = "/"+tmp;
	tmp = valid_write(filename2);
	if(!tmp){
	    write("Illegal write to "+filename2+"\n");
	    return 1;
	}
	filename2 = "/"+tmp;
	/* read file */

	finish = (line2 && line1 + 500 > line2) ? line2 - line1
	: 500;

	if(!(txt = read_file(filename1,line1,finish))) {
	    write("Line #"+line1+" is out of range or file is empty.\n");
	    return 1;
	}

	/* write file */

	write("Writing Block from "+line1+" of "+filename1+" to "+filename2+".\n");  
	write_file(filename2,txt);
	return 1;
    }


    /***************************************************************************/
    /* cat whole file */

#define CAT_LENGTH 45

    static status Cat_file(string str) {
	int line;

	if(!str) {
	    write("Usage: Cat <file>\n\n"+
	      "Notes: Useful for copying a file to disk via screen capture.\n"+
	      "       This will probably crash on files with more then 2000 lines.\n"+ 
	      "       For those muds that don't allow ftp downloading ;)\n");
	    return 1;
	}

	str = make_path(str);
	if(bad_file(str)) {
	    write("Illegal filename: "+ str +"\n");
	    return 1;
	}
	for(line = 1; cat(str, line, CAT_LENGTH); line += CAT_LENGTH);
	return 1;
    } 


    /**************************************************************************/
    /* copy file(s) */

    varargs static status copy(string str, status overwrite, status mv) {
	int i;
	string tmp1, tmp2;
	string in, path_in, file_in;
	string out, file_out;
	string format_in, format_out;

	if(!str) {
	    write(
	      "Usage: copy <file> { file out }\n"+
	      "       Copy <file> { file out } (overwrites file out)\n"+
	      "       mv   <file> { file out } (deletes file)\n"+
	      "       Mv   <file> { file out } (deletes file, overwrites file out)\n");

	    write("Notes: copy file to optional file out, default current path.\n"+
	      "       accepts wildcard \"*\" (may give unexpected results)\n"+
	      "       is able to copy ^[ characters, checks if size of copied\n"+
	      "       file is same of original before removing with mv.\n");
	    return 1;
	}

	if(sscanf(str,"%s %s",in,out) != 2) { /* update dec. 93 */
	    in = str;
	    out = "/"+ current_path;
	}

	/* has wizard|player got read access */

	if(!(in = valid_read(in))) {
	    write("Invalid read access.\n");
	    return 1;
	}
	in = "/" + in;
	if(bad_file(in)) {
	    write("Illegal filename: "+ in +"\n");
	    return 1;
	}

	/* has wizard|player got write access */

	if(!(out = valid_write(out))) {
	    write("Invalid write access.\n");
	    return 1;
	}
	out = "/" + out;

	if(bad_file(out)) {
	    write("Illegal filename: "+ out +"\n");
	    return 1;
	}

	if(!sscanf(out,"%s*%s",tmp1,tmp2)) {
	    if(file_size(out) == -2) {
		out += "/";
		if(!(out = valid_write(out))) {
		    write("Invalid write access.\n");
		    return 1;
		}
		out = "/" + out;
	    }
	}

	/* extract path and filename */

	for(i = strlen(in) - 1; (in[i] != '/' && i >= 0); i--);
	path_in = extract(in,0,i);
	file_in = extract(in,i+1,strlen(in)-1);

	for(i = strlen(out) - 1; (out[i] != '/' && i >= 0); i--);
	path_out = extract(out,0,i);
	file_out = extract(out,i+1,strlen(out)-1);

	/* get input wildcards to sscanf format to make output compat. string */

	format_in = wildcard_format(file_in);

	/* fix file output type file|wildcard|dir */

	if(!file_out || file_out == "") {
	    file_out = file_in;
	}
	format_out = wildcard_format(file_out);

	if(format_number(format_in) != format_number(format_out)) {
	    write("Wildcard parameters of input and output do not match.\n");
	    return 1;
	}

	/* do some directory and file checking */

	if(file_size(extract(path_out,0,strlen(path_out)-2)) != -2) {
	    write("Output Directory: "+path_out+" does not exist.\n");
	    return 1;
	}
	if(file_size(extract(path_in,0,strlen(path_in)-2)) != -2) {
	    write("Input Directory: "+path_in+" does not exist.\n");
	    return 1;
	}

	/* get list of files */

#ifdef NO_GET_DIR_WILDCARDS
	list = (format_number(format_in)) ? get_dir(path_in +".") : get_dir(in);
#else
	list = get_dir(in);
#endif

	if(!sizeof(list)) {
	    write("No match for "+ path_in + file_in +"\n");
	    return 1;
	}

	sformat = format_in;
	sformat_out = format_out;
	new_text = path_in;
	line = 0;
	over_write = overwrite;
	move_file = mv;

	do_copy(0);
	return 1;
    }


    void do_copy(string answer) {
	int abort;
	string file_out;

	if(answer == "n") {
	    write("Ok.\n");
	    return;
	}

	for(; line < sizeof(list); line++) {
	    if(abort > 20 * MAX_BYTE_READ) { /* abort after copying 160 KB */
		write("Continue (y/n) [y]: ");
		input_to("do_copy");
		return;
	    }
	    if(list[line] == "." || list[line] == "..") continue;
	    if(file_size(new_text+list[line]) == -2) continue; 
	    file_out = match_format(list[line],sformat,sformat_out);
	    if(!file_out) continue;
	    abort += file_size(new_text+list[line]);
	    if(copy_file(new_text+list[line],path_out+file_out, over_write)) {
	    }
	}
    }


    status copy_with_overwrite(string str) {
	copy(str,1,0);
	return 1;
    }

    static status move_file(string str) {
	copy(str,0,1);
	return 1;
    }

    static status move_file_with_overwrite(string str) {
	copy(str,1,1);
	return 1;
    }

static status NewCopy(string arg) //Adept, 1997
{
   string str, text, *files, file, new_file;
   status multiple;

   if (!arg || sscanf(arg, "%s %s", arg, str) != 2)
      return write("cp <file> <destination>\n"), 1;
   arg = valid_read(arg);
   if (!arg)
      return write("Bad file name.\n"), 1;

   files = get_dir("/" + arg) - ({ ".", ".." });
   if (!sizeof(files))
      return write("No files found.\n"), 1;
   arg = "/" + implode(explode(arg, "/")[0..<2], "/") + "/";
   str = valid_read(str);
   if (!str)
      return write("Bad destination.\n"), 1;
   str = "/" + str;
   if (file_size(str) == -2)
   {
      int i;
      while (i < sizeof(files))
      {
         file = arg + files[i];
         write(file + ": ");
         if (file_size(file) == -2) 
            write("Is a directory.\n"); 
         else if (text = read_file(file)) 
         {
            new_file = str + "/" + files[i];
            if (file_size(new_file) != -1)
               write("File already exists.\n");
            else 
            {
               if (write_file(new_file, text))
                  write("copied to " + new_file + ".\n");
            }
         }
         else
         {
            write("unable to read file.\n");
         }
         ++i;
      }
      return 1;
   }
   if (sizeof(files) != 1)
      return write("You may only copy multiple files to a directory.\n"), 1;
   file = arg + files[0];
   write(file + ": ");
   if (text = read_file(file))
   {
      if (file_size(str) != -1)
         return write("File already exists.\n"), 1;
      else
         if (write_file(str, text))
            return write("copied to " + str + ".\n"), 1;
   }
   return 1;
}



    /***************************************************************************/
    /* deltree */

    static status deltree(string path) {
	if(!path || path[0] != '/') {
	    write("Usage: deltree <path>\n\n"+
	      "Notes: Deletes a whole directory tree.\n"+
	      "       You must use full path, prepended by '/'\n");
	    return 1;
	}

	if(!valid_write(path + "/*")) {
	    write("Invalid Delete Access.\n");
	    return 1;
	}
	if(bad_file(path)) {
	    write("Illegal filename: "+ path +"\n");
	    return 1;
	}

	write("Are you sure you want to delete all files and directories in\n"+
	  "the path: \""+path+"\"  (y/n) [n]: ");
	new_text = path;
	input_to("answer_deltree");
	return 1;
    }

    static void answer_deltree(string ans) {
	if(ans == "y") { 
	    delete_dir(new_text);
	}
	else {
	    new_text = 0;
	}
	write("Ok\n");
    }


    static void delete_dir(string path) {
	string *files;
	int i;

	if(!path) return;
	if(path[strlen(path) - 1] != '/') path += "/";
	files = get_dir(path + ".");

	for(i = 0; i < sizeof(files); i++) {
	    if(files[i] == "." || files[i] == "..") continue;
	    if(file_size(path + files[i]) == -2) {
		delete_dir(path+files[i]);
	    }
	    else {
		if(!rm(path + files[i])) { 
		    write("Failed to Delete: "+path+files[i]+"\n");
		}
	    }
	}
	if(strlen(path) > 1) {
	    path = extract(path,0,strlen(path)-2);
	    if(!rmdir(path)) {
		write("Failed Directory Delete: "+path+"\n");
	    }
	    else {
		write("Deleted Directory: "+path+"\n");
	    }
	}
	new_text = 0;
    }


    /***************************************************************************/
    /* find file */

    static status find_file(string str) {
	string pattern, txt, path;
	status flg;

	if(!str) {
	    write("Usage: find <file{?}> { <path> }\n\n"+
	      "Notes: Finds a file in the subdirectories of your path.\n"+
	      "       If ? is used it searches as a pattern in filename\n"+
	      "       An optional start <path> can be used (prepend <path> "+
	      "with '/').\n");
	    return 1;
	}

	if(!sscanf(str,"%s %s", pattern, path)) {
	    path = "/" + (string)this_player()->query_path();
	    pattern = str;
	}
	if(bad_file(path)) {
	    write("Illegal filename: "+ path +"\n");
	    return 1;
	}

	if(sscanf(pattern,"%s?",pattern)) {
	    flg = 1;
	    write("File Pattern Search: "+pattern+"->\n");
	}
	else {
	    write("File Search: "+pattern+"->\n");
	}
	if(catch((txt = search_pattern(pattern, path, flg)))) {
	    write("Error: Subdirectory tree too large too search.\n");
	}
	if(txt == "") {
	    write("No Match.\n");
	}
	else if(txt) {
	    write(txt);
	}
	write("Ok.\n");
	return 1;
    }


    static string search_pattern(string pattern, string path, status flg) {
	string *all_files, *files, *dir;
	string file_search;
	int i;

	if(path == "/") path = "";
	if(strlen(path) > 1 && path[strlen(path)-1] == '/') {
	    path = extract(path,0,(strlen(path)-2));
	}

	all_files = get_dir(path + "/.");
	if(!all_files) return "";

	files = filter(all_files,"file_filter",this_object(),path);
	dir = filter(all_files,"directory_filter",this_object(),path);

	file_search = "";

	for(i = 0; i < sizeof(dir); i++) {
	    file_search += search_pattern(pattern,path+"/"+dir[i],flg);
	}

	files = regexp(files, pattern);

	if(!flg && sizeof(files)) {
	    files = filter(files,"pattern_filter",this_object(),pattern);
	}

	if(sizeof(files)) {
	    file_search += path + "/";
	    file_search += implode(files,"\n"+path+"/") + "\n";
	}
	return file_search;
    }  


    /****************************************************************************/
    /* tree */

    static status path_tree(string path) {
	int *path_status, i;
        string *pathInfo;
	string tmp1, tmp2;

	path_status = ({});

	path = make_path(path);

	/* scan for help */

	if(sscanf(path, "%s-h%s", tmp1, tmp2)) {
	    write("Usage: tree { options: <path> }\n\n"+
	      "Notes: writes a pictorial list of directory structure.\n"+ 
	      "       <path> directory path\n"+
	      "       This may cause too long evaluation errors on large\n"+
	      "       directory trees.\n");
	    write("       Example: tree /room\n");
	    return 1;
	}
	write("Path: "+path+"\n\n");
	if(path != "/") {
	    string *path_split;

	    path_split = explode(path, "/");
	    path_split = filter(path_split,"filter_zeros",this_object());
	    path_status = allocate(sizeof(path_split));
	    for(i = 0; i < sizeof(path_status); i++) path_status[i] = 1;
	    write("___"+implode(path_split,"___"));
            if(!pathInfo || !sizeof(pathInfo)) pathInfo = ({ });
              pathInfo += ({ path_split, });
	    new_text = path;
	}
	else {
	    new_text = "";
	}
	file_tree(new_text, path_status);
	write("\n");
	return 1;
    }


    static status Path_tree(string path) {
	string *files, tmp1, tmp2;

	path = make_path(path);

	/* scan for help */

	if(sscanf(path, "%s-h%s", tmp1, tmp2)) {
	    write("Usage: Tree { options: <path> }\n\n"+
	      "Notes: <path> directory path\n"+
	      "       There is a pause after each directory tree in 'path'\n"+
	      "       This helps, but may still cause too long evaluation\n"+
	      "       errors on large directory trees.\n");
	    write("       Example: Tree /room\n");
	    return 1;
	}


	/* get list of directories */

	if(path == "/")
	    new_text = "";
	else
	    new_text = path;

	/* get list of directories */

	list = get_dir(new_text + "/.");
	if(!list) return 1;
	list = filter(list,"directory_filter", this_object(), path);
	line = 0;
	if(!sizeof(list)) {
	    write("Directory Empty.\n");
	}
	else {
	    answer_tree_prompt("");
	}
	return 1;
    }


    static void answer_tree_prompt(string ans) {
	int *path_status;

	if(ans == "n") return;
	if(ans == "s") {
	    skip();
	    return;
	}
	write("Path: " + new_text+"/"+list[line] + "\n\n");
	if(new_text+"/"+list[line] != "/") {
	    string *split_path;
	    int i;

	    split_path = explode(new_text+"/"+list[line], "/");
	    split_path = filter(split_path,"filter_zeros",this_object());
	    path_status = allocate(sizeof(split_path));
	    for(i = 0; i < sizeof(path_status); i++) path_status[i] = 1;
	    write("___"+implode(split_path,"___"));
	}
	tree_prompt(new_text+"/"+list[line], path_status);
    }


    static void tree_prompt(string path, int *path_status) {
	file_tree(path, path_status);
	write("\n");
	skip();
    }

    static void skip() {
	if(++line < sizeof(list)) {
	    if(new_text+list[line] == "/usr") {
		if(++line == sizeof(list)) return;
	    }
	    write("Next Path: "+new_text+"/"+list[line]+"\n");
	    write("\nContinue (y/n/(s)kip) [y]: ");
	    input_to("answer_tree_prompt");
	}
    }


    status filter_zeros(string str) {
	return ((!str || str == "") ? 0 : 1);
    }

    static string *file_tree(string path, int *path_status) {
	string *files;
	int i, k, size;
	string path_str;

	/* exceptions - dir too big for this fn */

	if(path == "/usr") {
	    write("Directory /usr is too large");
	    return ({});
	}

	/* get list of directories */

	files = get_dir(path + "/.");
	if(!files) return ({});
	files = filter(files,"directory_filter", this_object(), path);

	/* create tree */

	path_str = "";
	if(path != "") {
	    string *split_path;
	    split_path = explode(path,"/");
	    split_path = filter(split_path,"filter_zeros",this_object());
	    for(k = 0; k < sizeof(split_path) && k < sizeof(path_status); k++) {
		path_str += (path_status[k]) ? "   " : " | ";
		path_str += extract("                          ",
		  0,(strlen(split_path[k])-1));
	    }
	}

	for(i = 0, size = sizeof(files); i < size; i++) {
	    int *new_path_status;

	    if(files[i] && files[i] != "") {
		write(((!i) ? "___" : path_str + " |_") + files[i]);
		new_path_status = path_status + ({ (i == size-1) ? 1 : 0, });
		if(!sizeof(file_tree(path+"/"+files[i],new_path_status))) {
		    write("\n");
		}
	    }
	}
	return (files) ? files : ({});
    }


    /*****************************************************************************/
    /*                   Wizard Tools - fn() used by various actions             */
    /*****************************************************************************/


    /******************************************************************************/
    /* make_path */

    string make_path(string file) {
	string *path_split, tmp;
	string tmp1, tmp2;
	int i, len;

	if(!file || file == "") return "/"+current_path;
	if(file == "~") return WIZARD_DIR +""+ name;
	if(sscanf(file,"~/%s",file)) {
	    file = WIZARD_DIR +""+ file;
	}
	if(sscanf(file,"~%s",file)) {
	    file = WIZARD_DIR +""+ name +"/"+ file;
	}
	if(sscanf(file,"%s#%s",tmp1,tmp2)) {
	    file = DOMAIN_DIR +""+ tmp1 +"/w/"+ name +"/"+ tmp2;
	}
	if(sscanf(file,"%s,%s", tmp1, tmp2)) {
	    file = DOMAIN_DIR +""+ tmp1 +"/w/"+ tmp2;  /* experimental */
	}
	if(file[0] != '/') {
	    if(current_path == "") {
		file = "/"+file;
	    }
	    else {
		file = "/" + current_path + "/" + file;
	    }
	}
	while(sscanf(file, "%s//%s", tmp1, tmp2)) file = tmp1 + "/" + tmp2;
	return ::make_path(file);
    }

    /***************************************************************************/
    /* show results for patch(), and lpc() commands */

    string string_results(mixed arg) {
	string str;
	string tmp;
	string result;
	int i;
	mixed *indices;

	result = "";
	if(pointerp(arg)) {
	    result += "({";
	    for(i = 0; i < sizeof(arg); i++) {
		if(!i) result += " ";
		result += string_results(arg[i]) +", ";
	    }
	    result += "})";
	}
	else if(mappingp(arg)) {
	    str = "([\n";
	    indices = m_indices(arg);
	    for(i = 0; i < sizeof(indices); i++) {
		str += "  "+ string_results(indices[i]) +": "+
		string_results(arg[indices[i]]) +",\n";
	    }
	    result = str +"])";
	}
	else if(objectp(arg)) {
	    result = file_name(arg);
	}
	else if(stringp(arg)) {
	    str = arg;
	    result = "";
	    while(sscanf(str,"%s\n%s", tmp, str)) {
		if(arg != tmp +"\n"+ str) result += "\n";
		result += tmp +"\\n";
	    }
	    result = "\""+ result + str +"\"";
	}
	else if(intp(arg)) {
	    result = arg +"";
	}
	return result;
    }


    void show_results(mixed arg) {
	write(((pointerp(arg)) ? "<Array>\n"
	    :(objectp(arg))  ? "<Object>\n"
	    :(intp(arg))     ? "<Int>\n"
	    :(stringp(arg))  ? "<String>\n"
	    :(mappingp(arg))  ? "<Mapping>\n"
	    : "<Unknown Type>\n"));
	write(string_results(arg) +"\n");
    }

    /**************************************************************************/
    /* convert a plural string to a singlular */

    string plural_to_single(string plural) {
	string word, end;
	int len;

	if(!plural) return "";
	len = strlen(plural); 

	/* sscanf() sucks...it wouldn't work *sob*  
	 * it has problems with things like "%ss", - Zil */

	if(len > 3) { 
	    end = extract(plural,(len - 3),(len - 1));
	    word = extract(plural,0,(len - 4));
	    if(end == "ies") return word + "y";  /* babies -> baby */
	    if(end == "ses") {
		if(word[strlen(word)-1] == 's')   
		    return word + "s";               /* glasses -> glass */
		else 
		    return word + "se";              /* fuses -> fuse */
	    }
	}
	if(len > 2) {
	    end = extract(plural,(len - 2),(len - 1));
	    word = extract(plural,0,(len - 1));
	    if(end == "ii") return word + "us";  /* you never know ;) */ 
	    if(plural[len-1] == 's')
		return extract(plural,0,(len - 2));
	}
	return plural;
    }


    /**************************************************************************/
    /* find_object() - uses various object finding efuns */

    static varargs object *FIND_OBJECT(string str, object who){
	string tmp1, tmp2;
	int i, j;
	object *ob;
	string current_path;

	if(!str){ 
	    write("No Argument to FIND_OBJECT!\n");
	    return ({});
	}
	ob = ({});
	if(str == "who" || str == "users") {
	    ob = allocate(sizeof(users()));
	    ob = users();
	    if(who) {    /* eg. users in room */
		ob = filter(ob,"present_filter",this_object(),who);
	    } 
	}  
	if(!sizeof(ob)) ob = allocate(1);
	if(!who) who = this_player();

	if(str == "me") ob[0] = this_player();
	else if(str == "env") ob[0] = environment(who);
	else if(str == "room") ob[0] = environment(who);
	else if(str == "all") {
	    ob = allocate(sizeof(all_inventory(who)));
	    ob = all_inventory(who);
	    if(!sizeof(ob)) ob = allocate(1);
	}
	else if(sscanf(str, "all %s", tmp1)) {      /* eg. all swords */
	    ob = filter(all_inventory(who), "plural_filter", this_object(), tmp1);
	    if(!sizeof(ob)) ob = allocate(1);
	}
	else if(sscanf(str, "%d %s", j, tmp1)) {    /* eg. 3 swords */
	    ob = filter(all_inventory(who), "plural_filter", this_object(), tmp1);
	    if(j <= sizeof(ob)) {
		ob = ob[0..(j-1)];
	    }
	    if(!sizeof(ob)) ob = allocate(1);
	}
	else if(sscanf(str,"who%d",i) == 1) {
	    if(i < 1 || i > sizeof(users()) - 2) {
		write("Who "+i+" is out of who number bounds.\n");
		return ({});
	    } 
	    ob[0] = users()[i-1];
	}
	if(!ob[0]) ob[0] = present(str, who);
	if(!ob[0] && environment(who)) ob[0] = present(str, environment(who));
	if(!ob[0]) ob[0] = find_object(str);
	if(!ob[0]) ob[0] = find_living(str);
	if(!ob[0]) {
	    ob = find_all_living(plural_to_single(str));
	    if(!sizeof(ob)) ob = allocate(1);
	}
	if(!ob[0]) ob[0] = find_living("ghost of " + str);
	if(!ob[0]) {
	    if(!sscanf(str,"%s %s", tmp1, tmp2)) {
		str = make_path(str);
		sscanf(str,"/%s", str);
		sscanf(str,"%s.c",str);
		if(FILE_SIZE("/"+ str +".c") > 0) {
		    if(catch(call_other(str,"???"))) {
			write("Error in loading: "+str+"\n");
			return ({});
		    }
		    ob[0] = find_object(str);
		}
	    }
	}
	if(!ob[0]) return ({});
	return ob;
    }


    /***************************************************************************/
    /* processes an action string to find an object list */

object *PROCESS_ARG(string arg){
	string tmp1, tmp2;
	mixed *ob_list; 
	string *contents, list, content_list;
	mixed *ob;
	int i;

	if(!arg) return ({});
	ob_list = explode(arg," in ");
	list = implode(ob_list," of ");
	ob_list = explode(list," of ");
	if(!ob_list) ob_list = ({ arg, });
	for(i = 0; i < sizeof(ob_list); i++) {
	    content_list = ob_list[i];
	    while(sscanf(content_list,"%s, %s", tmp1, tmp2)) {
		content_list = tmp1 + "," + tmp2;
	    }
	    if(content_list[strlen(content_list)-1] != ',') content_list += ",";
	    contents = explode(content_list,",");
	    ob_list[i] = contents;
	}
	ob = PROCESS_ARG_OB(ob_list,({ 0,})); 
	if(!sizeof(ob)) {
	    write("Error: Cannot find '"+arg+"'\n");
	}
	return ob;
    }

    object *PROCESS_ARG_OB(mixed *ob_list, object *ob) {
	int i, size, j;
	object *new_ob, *obj;
	string *list;


	new_ob = ({});
	list = ob_list[sizeof(ob_list)-1];
	for(i = (size=sizeof(ob)) - 1; i >= 0; i--) {
	    for(j = 0; j < sizeof(list); j++) {
		obj = FIND_OBJECT(list[j], ob[i]);
		if(sizeof(obj)) {
		    new_ob = new_ob + obj;
		}
	    }
	}
	if(!sizeof(new_ob)) return ({});
	if(sizeof(ob_list) > 2) {  
	    return PROCESS_ARG_OB(ob_list[0..(sizeof(ob_list)-2)],new_ob);
	} 
	else if(sizeof(ob_list) == 2) {
	    return PROCESS_ARG_OB(({ ob_list[0], }), new_ob);
	}
	return new_ob;
    }


    /**************************************************************************/
    /* parses '$name' for players name; '$obj' for ob's name + those parse by
     * process_msg()
     */

    string parse_msg(string msg, object ob) {
	string rest, sh; 

	sh = (ob->query_name())
	? (string)ob->query_name()
	: (ob->short())
	? (string)ob->short()
	: "an invisible object";  
	while(sscanf(msg,"%s$obj%s", msg, rest))  msg += sh + rest;  
	while(sscanf(msg,"%s$name%s", msg, rest)) msg += query_name() + rest;  
	return process_msg(msg);  
    }


    /************************************************************************/
    /* copy a file from in to out - no validation checks */

    status copy_file(string in, string out, status overwrite) {
	int f_size, current_byte;
	int max_byte;
	string txt;

	if(file_size(out) > 0) {
	    if(!overwrite) {
		write("File Already Exists: "+out+"\n");
		return 0;
	    }
	    if(out == in) {
		write("Cannot copy file onto itself.\n");
		return 0;
	    }
	    write("Removing old file....\n");
	    rm(out);
	}
	if(move_file) {
	    write("Moving "+ in +" to "+ out +"\n");
	    rename(in, out);
	    return 1;
	}
	else {
	    write("Copying "+in+" to "+out+"\n");
	}
	f_size = file_size(in);
	while(current_byte < f_size) {
	    if(current_byte + MAX_BYTE_READ > f_size)
		max_byte = f_size - current_byte;
	    else
		max_byte = MAX_BYTE_READ;
	    txt = read_bytes(in, current_byte, max_byte);
	    write_file(out, txt);
	    current_byte += max_byte;


	}
	if(file_size(out) != file_size(in)) { 
	    write("ERROR: Corrupt File "+ out +"\n");
	    write("       Original: "+file_size(in)+" bytes, Copy: "+file_size(out)+
	      " bytes.\n");
	    return 0;
	}
	return 1;
    }


    /****************************************************************************/
    /* glob routines convert wildcarded filename to sscanf format string */

    static string wildcard_format(string file) {
	string format, pre;

	if(!file) return 0;
	format = "";
	while(sscanf(file,"%s*%s",pre,file)) format += pre +"\%s";
	return format + file;
    }    

    static int format_number(string format) {
	int i, j;
	string pre;

	if(!format) return 0;
	while(sscanf(format,"%s\%%s",pre,format)) {
	    if(format != "" && format[0] == 's') i++;
	}
	return i;
    }  

    static string match_format(string file, string format_in, string format_out) {
	string tmp1, tmp2, tmp3, tmp4, tmp5;
	string file_out;

	if(!format_out) format_out = format_in;
	switch(format_number(format_in)) {
	case 0:
	    file_out = (file == format_in) ? format_out : 0;
	    break;

	case 1:
	    if(sscanf(file, format_in, tmp1)) {
		file_out = sprintf(format_out,tmp1);
	    } 
	    break;

	case 2:
	    if(sscanf(file, format_in, tmp1, tmp2)) {
		file_out = sprintf(format_out, tmp1, tmp2);
	    } 
	    break;

	case 3:
	    if(sscanf(file, format_in, tmp1, tmp2, tmp3)) {
		file_out = sprintf(format_out, tmp1, tmp2, tmp3);
	    } 
	    break;

	case 4:
	    if(sscanf(file, format_in, tmp1, tmp2, tmp3, tmp4)) {
		file_out = sprintf(format_out, tmp1, tmp2, tmp3, tmp4);
	    } 
	    break;

	case 5:
	    if(sscanf(file, format_in, tmp1,tmp2,tmp3,tmp4,tmp5)) {
		file_out = sprintf(format_out, tmp1, tmp2, tmp3, tmp4, tmp5);
	    } 
	    break;
	default:        
	    file_out = 0;
	    break;
	}
	return file_out;
    }

    /****************************************************************************/
    /*               Filters used by filter()                             */
    /****************************************************************************/


    /* plural_filter
     *
     * makes an array objects whose id, or plural form of it matches
     */

    static status plural_filter(object ob, string object_id) {
	if(ob->id(object_id) || ob->id(plural_to_single(object_id))) return 1;
    }


    /* present_filter
     *
     * makes an array of objects which are present in another object
     */

    static status present_filter(object ob, object who) {
	if(present(ob,who)) return 1;
	return 0;
    }

    /* dot_filter
     *
     * makes and array of strings that do not have "." or ".."
     */

    static status dot_filter(string file) {
	string tmp1, tmp2;

	if(file == "." || sscanf(file,"%s..%s", tmp1, tmp2)) return 0;
	return 1;
    }

    /* pattern_filter
     *
     * makes an array of strings that match a pattern exactly (see also regexp())
     */

    static status pattern_filter(string str, string pattern) {
	if(str == pattern) return 1;
	return 0;
    }

    /* directory_filter
     *
     * makes an array of strings which are directories
     */

    static status directory_filter(string file, string path) {
	if(!dot_filter(file)) return 0;
	if(FILE_SIZE(path + "/" + file) != -2) return 0;
	return 1;
    }

    /* file_filter
     * 
     * makes an array of strings which are files (ie not directories)
     */

    static status file_filter(string file, string path) {
	if(!dot_filter(file)) return 0;
	if(FILE_SIZE(path + "/" + file) < 0) return 0;
	return 1;
    }


    /**************************************************************************/
    /*                         Sorters used by sort_array()                   */
    /**************************************************************************/ 

    /* there must be an easier way */

    static status by_name(object a, object b) {
	string a_str, b_str;
	int len_a, len_b, i;

	if(!(a_str = (string)a->query_name())) return 1;
	if(!(b_str = (string)b->query_name())) return 0;
	return (a_str < b_str) ? 1 : 0;
	/*
	  a_str = lower_case(a_str);
	  b_str = lower_case(b_str);
	  len_a = strlen(a_str);
	  len_b = strlen(b_str);
	  for(i = 0; i < len_a && i < len_b; i++) {
	    if(a_str[i] < b_str[i]) return 1;
	    if(a_str[i] > b_str[i]) return 0;
	  }
	  return (len_a < len_b) ? 1 : 0;
	 */
    }

    static status by_level(object a, object b) { 
	return ((int)a->query_level() < (int)b->query_level()) ? 1 : 0;
    }

    static status by_age(object a, object b) { 
	return ((int)a->query_age() < (int)b->query_age()) ? 1 : 0;
    }

    static status by_environment(object a, object b) { 
	string a_str, b_str;
	int len_a, len_b, i;

	if(!(a_str = file_name(environment(a)))) return 1;
	if(!(b_str = file_name(environment(b)))) return 0;
	return (a_str < b_str) ? 1 : 0;
	/*
	  a_str = lower_case(a_str);
	  b_str = lower_case(b_str);
	  len_a = strlen(a_str);
	  len_b = strlen(b_str);
	  for(i = 0; i < len_a && i < len_b; i++) {
	    if(a_str[i] < b_str[i]) return 1;
	    if(a_str[i] > b_str[i]) return 0;
	  }
	  return (len_a < len_b) ? 1 : 0;
	 */
    }

    static status by_ip_number(object a, object b) { 
	return (query_ip_number(a) < query_ip_number(b)) ? 1 : 0;
    }


    /**********************************************************************/
    /* lpc */

    status lpc(string str) {
	string file, err;
	mixed ret;
	object ob;
	int i;

	if(!str || sscanf(str, "%sreturn %s", ret, err) != 2) {
	    notify_fail("Usage: " + query_verb() + " <code>\n");
	    return 0;
	}

	file = TMP_FILE;
	for(i = 0; file_size(file + i + ".c") >= 0; i++);
	file = file + i;
	if(ob = find_object(file)) destruct(ob);
	write_file(file + ".c", "_lpc(){" + str + "}\n");
	err = catch(ret = (mixed)call_other(file, "_lpc"));
	if(ob = find_object(file)) destruct(ob);
	rm(file + ".c");
	if(err)
	    write(err);
	else
	    show_results(ret);
	return 1;
    }



