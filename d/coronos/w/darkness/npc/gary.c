#include <mudlib.h>
inherit MONSTER;
 
void init() {
  call_out("chat",1);
  ::init();
}
 
void reset(status arg) {
  if (arg) {
  return;  
  }
 
  ::reset(arg);
  set_name("Gary");
  set_alias("man");
  set_short("Gary the guitarist");
  set_long(
    "This human looks to be in his late forties.  He has a scruffy\n"+
    "beard and his clothes are somewhat ragged.\n");
  load_chat(5, ({
    "Gary smiles at you.\n",
    "Gary plays a tune on his guitar\n",
    "Gary tunes his guitar.\n",
    "Gary whistles as he plays his guitar.\n",
    "Gary smiles at you, 'Could ya spare a coin?'\n",
    })); 
 
  load_a_chat(40, ({
    "HELP!\n",
    "Help!  Someone help me!\n",
    "Why are you doing this to me?\n",
    "Please stop hurting me!\n",
    "What did i do to you?\n",    
    }));
  set_al(0);
  set_level(4);
  set_gender(1);
  set_race("human");
  add_money(17); 
 
  if(!present("guitar")){
    move_object(clone_object(
    "/d/coronos/w/darkness/items/guitar"),
    this_object());
  }
}
