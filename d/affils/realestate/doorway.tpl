


#include <linewrap.h>
status built;
string house_type;

void build_me();

void reset(status arg) {
  object ob;

  ENV->reset(0);
  ob = find_object(ENV);
  move_object(this_object(), ob);
  build_me();
}



void build_me() {
  string file;
  int i;

  sscanf(file_name(this_object()), "doorway%d", i);
  if(!environment()) return;

  environment()->load_door(({
	"file", "d/affils/p/"+lower_case(NAME)+"/home"+i,
	"direction", "oak door",
	"long", "A large door made from oak. On the middle of the door is \n"+
		"a silver plaque which reads: "+capitalize(NAME)+" lives "+
		"here.\n",
  }));

  call_other("/d/affils/p/"+ lower_case(NAME) +"/home"+i, "load_door",
	({ "file", ENV,
	   "direction", "oak door",
	   "long", "A large door made from oak. On the middle of the door \n"+
	           "is a silver plaque which reads: "+
		   capitalize(NAME) +" lives here.\n",
        }));

  built = 1;
  house_type = (string)call_other(
	"/d/affils/p/"+ lower_case(NAME) +"/home"+i,
	"query_house_type");

}


string query_object_type() { return "RealEstate"; }

string query_name() { return  "Doorway";    }


status id(string str) {
  return str == "Doorway" || 
         str == "RealEstate" ||
         str == "house"      ||
         str == "keep"       ||
         str == "stronghold";
}

void extra_long() {
  string txt;
  if(house_type) {
    switch(house_type) {
      case "House" :
        txt = "Close by "+environment()->short()+" there is a fine house.\n";
        break;
      case "Tower" :
        txt = "Towering above "+environment()->short()+" the shadows of "+
	      "a tall building covers your in darkness.\n";
        break;
      default :
        txt = "A great keep with high walls of stone, covered in ivy, "+
	      "stands strong amid "+environment()->short()+". "+
	     "Such a fine stronghold could withstand any possible attackers.\n";
	      "possible attackers.\n";
        break;
    }
  }
  writelw(txt);
}

void long(status wiz) {
  writelw("It belongs to "+NAME+".\n");
}
