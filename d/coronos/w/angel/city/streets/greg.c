#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gregory");
  set_short("Gregory, the dog trainer");
  set_long(
	"Gregory is a member of the city guard who trains dogs to aid \n"+
	"them in various tasks. He has always believed a good dog is  \n"+
	"better than 5 good guards.\n");

  set_race("human");
  load_chat(5, ({ "Gregory asks: Do you wish to purchase a fine dog?\n",
	"Gregory goes about his duties, cleaning kennels.\n",
  }));

  set_magic_resist(200); /* dont want him going anywhere! */
  set_level(12);
}

void catch_tell(string str) {
  string tmp1, tmp2;
  ::catch_tell(str);
  if(sscanf(str, "%sbuy%s", tmp1, tmp2)) 
    environment()->buyme();
}
