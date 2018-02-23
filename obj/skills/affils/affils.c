/*****************************************************************************
 * The Affiliation Object *
 * 
 * This is just an external object used in conjunction with affiliations.
 * The object itself doesn't do much, other than be able to call various little
 * bits of info from the central affiliation object.
 * v1.01 - Angel of Heaven7, 1996
 */

#include <mudlib.h>
#include <bad_file.h>

#define NAME		(string)environment()->query_name()
#define SKILLS_FILE	"/bin/skills/affils/"

string affiliation_name, affiliation_file;
string affiliation_sponsor;
status dest_me_soon;
mapping data;

mixed *query_auto_load() {
  string tmp;
  int i;

  tmp = file_name(this_object());
  if(!sscanf(tmp, "%s#%d", tmp, i)) {
    write("Warning: Can't save affiliation object.\n");
    return 0;
  }

  data = ([	"file":	(string)this_object()->query_affiliation_file(),
		"name":	(string)this_object()->query_affiliation_name(),
                "sponsor" : (string)this_object()->query_affiliation_sponsor(),
  ]);

  return ({ tmp, data, });
}

string query_object_type() { return "Affiliation"; }

string query_name() { return "Affiliation";        }

status id(string str) {
  return str == "Affiliation" ||
         str == affiliation_name ||
         str == affiliation_file ||
         str == "external";
}

void init_arg(varargs arg) {
  string tmp1, tmp2, file;
  object file_ob;
  int i;
  if(!sscanf(file_name(this_object()), "obj/skills/affils/%s#%d", tmp1, i)) {
    write("Warning: Can't log affiliation data. Return to afiliation room.\n");
    dest_me_soon = 1;
    return;
  }

  file = "/d/affils/rooms/"+tmp1;

  affiliation_file = (string)call_other(file, "query_affiliation_file");
  affiliation_name = (string)call_other(file, "query_affiliation_name");
  affiliation_sponsor = (string)call_other(file, "query_affiliation_sponsor");
  data = ([ "name": affiliation_name,
	    "file": affiliation_file,
            "sponsor" : affiliation_sponsor,
  ]);

}

void extra_look() {
  string tmp;
  tmp = NAME+" is a "+affiliation_name+".\n";
  write(tmp);
}

void init() {
  if(environment()) {
    if(present(affiliation_name +" 2", environment())) {
      call_out("dest_me_now", 2);
    }
  }


}

void dest_me_now() {
  destruct(this_object());
}



string set_affiliation_file(string str) { return affiliation_file = str; }
string set_affiliation_name(string str) { return affiliation_name = str; }
string set_affiliation_sponsor(string str) { return affiliation_sponsor = str; }

status drop(string wiz) { return 1; }
status get(string wiz)  { return 0; } /* getable, but not dropable */

string query_affiliation_file() { return affiliation_file; }
string query_affiliation_name() { return affiliation_name; }
string query_affiliation_sponsor() { return affiliation_sponsor; }

mapping query_affiliation_data() { return data; }
