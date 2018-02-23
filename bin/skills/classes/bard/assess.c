#include <mudlib.h>

status assess(string targ, mixed alt_type) {
  int history;
  object ob;

  if(!targ) {
    notify_fail("Assess what?\n");
    return 0;
  }

  history = (int)this_player()->query_history();

  if(!ob = (present(targ, environment(this_player())))) {
    if(!ob = (present(targ, this_player())))
      notify_fail(capitalize(targ)+" isn't here.\n");
  }


  /* identify things about people/creatures using history */
  if(ob->query_npc() || ob->id("PLAYER")) {
    return (status)"/bin/skills/classes/mage/identify" -> 
    cast_spell(this_player(),ob, 0, history);
  }

  /* identify peoperties of magic items using history */
  else {
    return (status)"/bin/skills/classes/cleric/detect" ->
    cast_spell(this_player(), ob, 0, history);

  }
  /* to find out value of items, use appraise skill instead! */


}

  

