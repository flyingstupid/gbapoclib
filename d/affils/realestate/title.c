#include <mudlib.h>
#include <linewrap.h>
inherit TREASURE;

string file;

void reset(status arg) {
  if(arg) return;
  set_name("scroll");
  set_short("A fine scroll of parchment");
  set_alias("parchment");
  set_alt_name("RealEstate");
  set_plural("scrolls");
}


void long(status wiz) {
  if(file)
  write("This is the title deed to '"+(string)call_other(file, "short")+"'.\n");
  writelw(
	"A title deed gives you building rights for you land. In order to "+
	"build your premesis you need to find an architect "+
	"whose style you like, and bring him to the site you own. From there "+
	"you may build. For extra help with how to build, please "+
	"see the help file 'help keeps'.\n");
}


void init_arg(string str) { file = str; }

mixed *query_auto_load() {
  string tmp;
  int i;

  tmp = file_name(this_object());
  sscanf(tmp,"%s#%d", tmp, i);
  return ({ tmp, file, });
}

status drop(status quit) {
  return 1;
}

string set_file(string str) { return file = str; }
string query_file()         { return file;       }

string query_object_type() { return "RealEstate"; }
