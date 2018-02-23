#include <mudlib.h>
inherit MONSTER;

object glasses, apron;

void reset(status arg) {

  ::reset(arg);



  if(arg) return;

  set_name("shoal");
  set_short("Shoal, the land merchant");
  set_race("forest gnome");
  set_alias("merchant");
  set_alt_name("gnome");
  set_gender(1);

  set_long(
    "Shoal has worked in Ille Coronos under the guidance of \n"+
    "George, Minister for Commerce, for years, helping new  \n"+
    "settlers to find land on which to build. \n");

  set_level(5);

  load_chat(5, ({
	"Shoal asks: Is there anything I can help you with?\n",
	"Shoal asks: Can I show you some land?\n",
	"Shoal says: I have some fine plots of land.\n",
	"Shoal says: George is such a fine master.\n",
	"Shoal asks: Have you seen Master George?\n",
	"Shoal ponders when Master George will return.\n",
  }));

  set_wimpy(60);

  load_a_chat(5, ({
	"Shoal exclaims: George! Help me!\n",
	"Shoal cries out for help!\n",
	"Shoal tries to run away!\n",
  }));
}
