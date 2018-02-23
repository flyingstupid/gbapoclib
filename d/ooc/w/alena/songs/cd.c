#include <mudlib.h>
#include <linewrap.h>

#define SONG_DIR	"/d/ooc/w/alena/songs/open"
#define DELAY		2 			/* delay for next song line */

inherit TREASURE;


void cd_stop();

mapping song_list;
string song_name;
string song_file;
string song_txt;
string *song_content;
int song_counter;

void reset(status arg) {
    if(arg) return;
    set_name("cd player");
    set_alias("cd");
    set_short("A cd player");
    set_long("A little cd player.\n");
    set_weight(1);

    song_list = ([
      "unloved" : "unloved",
      "ironic" : "ironic",
      "light" : "light",
      "can't cry anymore" : "cantcry",
    ]);
}

void long(status wiz) {
    string *tmp;
    ::long(wiz);
    tmp = m_indices(song_list);
    write("The CD player has the following songs in its stack.\n");
    writelw(implode(tmp, ". ")+"\n");
    write("Commands are: select <song>\n"+
      "              play\n"+
      "	       stop\n"+
      "	       pause\n");
}
void init() {
    add_action("cd_select", "select");
    add_action("cd_pause",  "pause");
    add_action("cd_stop",   "stop");
    add_action("cd_play",   "play");
}


status cd_select(string str) {
    string tmp;
    if(!str) {
	write("Select: <what song>?\n");
	return 1;
    }

    if(!tmp = song_list[str]) {
	write("There is no such song.\n");
	return 1;
    }

    cd_stop();
    song_name = str;
    song_file = SONG_DIR +"/"+ tmp +".txt";
    song_txt  = read_bytes(song_file, 0, file_size(song_file));
    song_content = explode(song_txt, "#");
    song_counter = 0;
    write("CD: "+capitalize(song_name)+" Loaded.\n");
    return 1;
}

status cd_play() {
    if(!song_name) {
	write("You need to select a CD first.\n");
	return 1;
    }
    if(song_counter > 0) {
	write("The song starts again.\n");
	song_counter = 0; 
	return 1; 
    }
    write("The CD starts.\n");
    say(this_player()->query_name()+" plays "+capitalize(song_name)+" on "+
      "the CD player.\n", this_player());
    call_out("cd_heart", 1);
    return 1;
}

status cd_stop() {
    remove_call_out("cd_heart");
    song_counter = 0;
    write("The CD player stops.\n");
    say(this_player()->query_name()+" stops the CD player.\n", this_player());
    return 1;
}

status cd_pause() {
    remove_call_out("cd_heart");
    write("You pause the CD.\n");
    return 1;
}


void cd_heart() {

    if(song_counter > sizeof(song_content)-1) {
	tell_room(environment(), "The CD finished playing its song and stops.\n");
	song_name = 0;
	song_file = 0;
	song_content = 0;
	song_counter = 0;
	return;
    }
    tell_room(environment(), song_content[song_counter]);
    song_counter++;
    call_out("cd_heart", DELAY);
}

