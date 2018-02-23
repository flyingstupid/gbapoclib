/* The get action
 *
 * This uses the parse_command fn supported by the driver.
 * Any mud using amylaar with compat mode, rather than native
 * mode, ends up using parse_old.c, rather than the newer and
 * more efficient parse.c ..hence, mudlib side fns are not
 * supported
 *
 * It's a clumsy object ...but it works ok and does its job
 * (c) Angel 1998
 */

#include <mudlib.h>
#define NAME   (string)this_player()->query_name()
/*
  "ob": ({ inherit/weapon#9134, }),
  "environment": objects/bag#9163,
  "prep": "from",
  "destination": objects/bag#9163,
  "container": objects/bag#9163,
*/

#if USE_PARSE_COMMAND

status get(string str) {
  object ob1, ob2;
  int i;
  mixed *items;
  string prep;
  string sh;
  string *silly;
  string adverb;
  string verb;
  mapping result;
  object *ob;
  object destination;
  object container;
  status all_flag;
  status gotSomething;
  string tmp1, tmp2;



  silly = ({
	"dilligently", "carefully", "quickly", "sneakilly",
	"quietly", "noisely", "slowly",
  });

  verb = query_verb();
  ob1 = environment(this_player());

#ifdef RPG
  if(this_player()->check_ooc()) return 1;
#endif /* RPG */
  if(!str) {
    notify_fail("Get what? from where?\n");
    return 0;
  }

  if(this_player()->query_ghost()) {
    tell_object(this_player(),"It passes straight through your hands...\n");
    return 1;
  }

  if((int)this_player()->query_real_light() < 1)   {
    tell_object(this_player(), "It's too dark to do that.\n");
    return 1;
  }

  
  if(!parse_command(
    verb +" "+ str, ob1, " '"+verb+"' %i %p %o", items, prep, ob2))
    parse_command(verb +" "+ str, ob1, " '"+verb+"' %i", items);

//remove blueprints... want only clones in the result
  if(pointerp(items))
  	items[1..] = filter(items[1..], #'clonep);

  result = SORTER -> sorter(items, prep, ob2, verb+str, environment(ob1));
  
  if(!mappingp(result)) {
    write("There is nothing like that to "+ verb +" here.\n");
    return 1;
  }

  ob        = result["ob"];
  container = result["container"];

  if(sscanf(str, "%s all %s", tmp1, tmp2)) all_flag = 1;


  if(!prep) prep = "from";
  for(i=0; i<sizeof(ob); i++) {
    sh = (string)ob[i]->short();
    if(!strlen(sh)) sh = ob[i]->query_name();
    if(!strlen(sh)) continue;
    sh = lower_case(sh);

    /* can't pick up yourself */
    if(ob[i] == this_player()) continue;
    if(environment(ob[i])->query_closed()) continue;

    /* can't get an object inside a player or inside a monster! */
    if(environment(ob[i])->id("PLAYER") || environment(ob[i])->query_npc()) continue;

    /* if bag's env is not this_player(), continue */
    if(environment(environment(ob[i]))) {
      if(environment(environment(ob[i]))->query_npc()) continue;
      if(environment(environment(ob[i]))->id("PLAYER") &&
         environment(environment(ob[i])) != this_player()) continue;
    }
    /* just in case we get items from a bag in a monster! *grin* */


    if(!ob[i]->get()) {
      write(capitalize(sh) +" doesn't want to budge!\n");
      continue;
    }
    if(!this_player()->add_weight(ob[i]->query_weight())) {
      write(capitalize(sh) +" is too heavy for you to "+ verb +"\n");
      continue;
    }

    if(!random(15))
      adverb = silly[random(sizeof(silly)-1)];
    write("You"+ ((adverb) ? " "+adverb : "") +" "+ verb +" "+ sh +" "+
    prep +" "+ lower_case(environment(ob[i])->short())+".\n");
    say(NAME +" "+ verb +"s "+ sh +" "+ prep +" "+
    lower_case(environment(ob[i])->short()) +".\n", this_player());
    environment(ob[i]) -> add_weight(-(ob[i])->query_weight());
    move_object(ob[i], this_player());
    gotSomething = 1;

  }
  if(!gotSomething) {
    notify_fail("There is nothing here to "+ verb +".\n");
    this_object()->pick_up(str);
    return 0;
  }

  /* fail safe */
  this_object()->pick_up(str);
  return 1;
}
#else
status get(string str) {
	previous_object()->pick_up(str);
	return 1;
}
#endif /* parse_command */