/* +2 sword, +5 vs evils */
#include <mudlib.h>
inherit WEAPON;


reset(arg) {
    if(arg) return;

    set_name("twohandedsword");
    set_alias("sword");
    set_short("A twohanded sword");
    set_long(
      "This is a huge broad sword. Only some kind of "+
"giant could wield this.\n"
);
    set_wc(16);
    set_type("slash");
    set_length(45);  /* a little longer than normal */
    set_weight(6);
    set_value(3300);
    set_hit_func(this_object());
}


init() {
    ::init();
    add_action("read","read");
}

read(string str) {
    string tmp1, tmp2;
    if(sscanf(str, "%srunes%s", tmp1, tmp2)) {
	if((status)this_player()->query_language("elf"))
	    write(query_info());
	else
	    write("They don't make any sense to you.\n");
	return 1;
    }
}

string info() { return query_info(); }
string query_info() {
  string tmp;
  tmp =	"This blade was forged by the great elfin smith Liath'lan, \n"+
	"during the Age of Might, for the Lord of Entannax. It now \n"+
	"is the property of Tempus, given as a gift to the city. The\n"+
	"elfin runes along the blade read 'Evil, Beware'\n";
  return tmp;
}


weapon_hit(object target) {
    if(target -> query_alignment() < -100) {
	tell_object(environment(), "Your sword glows a brilliant white!\n");
	say(environment()->query_name() +"'s sword throws sparks !\n"
	);
	return 3;
    }
    return 0;
}

