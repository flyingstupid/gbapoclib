/*
 * This is a shut down deamon, that will take care of shutting down
 * the game.
 * Call the function "shut" with a number of seconds as an
 * argument.
 * Don't clone this object.
 */

#include <mudlib.h>
inherit MONSTER;

void reset(int arg) {
    ::reset(arg);
    if (arg)
	return;
    set_name("armageddon");
    set_level(19);
    set_wc(40);
    set_ac(20);
    set_short("Armageddon the game crasher");
    set_long("He looks like he enjoys to stop the game.\n");
    set_alias("shut");
    set_magic_resist(100);
    mmsgin = "Arrives in a puff of smoke";
     move_player("in a puff of smoke#"+CHURCH);
}

shut(int seconds) {
    int i;

    if(!MASTER->valid_player_call(previous_object())) {
      write("Use: shutdown <reason>\n");
      return 1;
    }
    if(!seconds) {
	write("No time given\n");
	return;
    }
    set_long("He is firmly concentrated on counting.\n");
    i = remove_call_out("cont_shutting");
    if (i > 0) {
	i = (i + 10) * 4;
	if (i < seconds) {
	    write("There was already a shutdown in process, " + i +
		  " seconds.\n");
	    seconds = i;
	}
    }
    call_out("cont_shutting", 0, seconds * 60);
}

int transport_offer;

cont_shutting(int seconds) {
    string delay;
    int new_delay;

    if (seconds <= 0) {
	shout(query_name() + " shouts: I will reboot now.\n");
	shutdown();
	return;
    }
    new_delay = seconds * 3 / 4 - 10;
    call_out("cont_shutting", seconds - new_delay, new_delay);
    delay = "";
    if (seconds > 59) {
	delay = seconds / 60 + " minutes ";
	seconds = seconds % 60;
    }
    if (seconds != 0)
	delay += seconds + " seconds";
    shout(query_name() + " shouts: Game reboot in " + delay + ".\n");
}

catch_tell(str) {
    string who, what;
    object ob;

    if (!transport_offer)
	return;
    if (sscanf(str, "%s tells you: %s", who, what) != 2)
	return;
}

shouting(string str) {
  object obj;
  int j;

  obj = users();
  for(j=0; j<sizeof(obj); j++) {
    if(!obj[j] -> query_edit())
        tell_object(obj[j], str);
  }
}

