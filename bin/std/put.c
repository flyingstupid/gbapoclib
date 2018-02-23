#include <mudlib.h>

#define LEVEL (int)this_player()->query_level()
#define NAME (string)this_player()->query_name()
#define AMT_MONEY (int)this_player()->query_money()

status parse_put(mixed *items, string prep, object container);
string verb, message;
static status putSomething;

status put_action(object *ob, string prep, object container);

#if USE_PARSE_COMMAND

status put(string str) {
  mixed *items;
  int amt;
  string coins_type;
  object dest_ob;
  string who, tmpWho;
  object ob1, ob2;
  string prep;
  string adverb;

  verb = query_verb();
  message = str;

  ob1 = this_player();


#ifdef RPG
  if(this_player()->check_ooc()) return 1;
#endif /* RPG */

  if(!str) {
    notify_fail("Put what? in where??\n");
    return 0;
  }

  if(this_player()->query_ghost()) {
    tell_object(this_player(),"It passes straight through your hands...\n");
    return 1;
  }


  if((int)this_player()->query_real_light() < 1)   {
    notify_fail("It's too dark to do that.\n");
    return 0;
  }




  if(verb != "give") {
//PUT
  if(parse_command(verb+" "+str, ob1,
     " 'put' %i %p %o", items, prep, ob2)) {
//remove blueprints... want only clones in the result
  if(pointerp(items))
  	items[1..] = filter(items[1..], #'clonep);
      return parse_put(items, prep, ob2);
  }
  else if(parse_command(verb+" "+str, ob1, " 'put' %i", items)) {
//remove blueprints... want only clones in the result
  if(pointerp(items))
  	items[1..] = filter(items[1..], #'clonep);
    return parse_put(items, 0, 0);
  }
// DROP  
  if(parse_command(verb+" "+str, ob1,
     " 'drop' %i %p %o", items, prep, ob2)) {
//remove blueprints... want only clones in the result
  if(pointerp(items))
  	items[1..] = filter(items[1..], #'clonep);
      return parse_put(items, prep, ob2);
  }
  else if(parse_command(verb+" "+str, ob1, " 'drop' %i", items)) {
//remove blueprints... want only clones in the result
  if(pointerp(items))
  	items[1..] = filter(items[1..], #'clonep);
    return parse_put(items, 0, 0);
  }

  
  }

  if(parse_command(verb+" "+str, ob1, " 'give' %i %p %o", items, prep, ob2)) {
    return parse_put(items, prep, ob2);
  }
  else if(parse_command(verb+" "+str, ob1, " 'give' %o %i", ob2, items)) {
    return parse_put(items, 0, ob2);
  }


  else if(sscanf(str, "%s coins %s", amt, who) || 
          sscanf(str, "%s coins", amt)) {
    if(sscanf(str, "%d %s coins to %s", amt, coins_type, who) ||
      sscanf(str, "%s %d coins", who, amt) ||
      sscanf(str, "%s %d %s coins", amt, coins_type, who) ||
      sscanf(str, "%d coins to %s", amt, who) ||
      sscanf(str, "%d coin to %s", amt, who)) {

      if(who) if(sscanf(who, "to %s", tmpWho)) who = tmpWho;

      if(!who) return this_player()->give_object(0);
      if(!(dest_ob = present(who, environment(this_player())))) {
        notify_fail(capitalize(who)+" is not here.\n");
        return 0;
      }

      if(!living(dest_ob))  {
        notify_fail("Thats not giving it away, its throwing it away.\n");
        return 0;
      }

      if(amt)  {
        if(amt < 1) {
          notify_fail("Are you looking for a loan?\n");
          return 0;
        }
        if(LEVEL < 2)  {
          notify_fail("Your level is not high enough to be a money lender.\n");
          return 0;
        }

        if(coins_type == "platinum") amt *= PLATINUM;
          else
        if(coins_type == "gold") amt *= GOLD;
          else
        if(coins_type == "silver") amt *= SILVER;
          else
        amt *= COPPER;
 
        if(amt > AMT_MONEY) amt = AMT_MONEY;
        if(!amt) {
          notify_fail("You don't have any money!\n");
          return 0;
        }
        this_player()->add_money(-amt);
        this_player()->save_me(1);
        dest_ob->add_money(amt);
        dest_ob->save_character();
        tell_object(this_player(),"You give "+capitalize(who)+" "+MONEY->convert(amt)+
             "  coin"+((amt == 1) ? "" : "s")+".\n");
        say(NAME+" gives "+capitalize(who)+" "+MONEY->convert(amt)+
             " coin"+((amt == 1) ? "" : "s")+".\n", dest_ob);
        tell_object(dest_ob,NAME+" gives you "+MONEY->convert(amt)+
             " coin"+((amt == 1) ? "" : "s")+".\n");
        return 1;
      }
    }
    notify_fail("Give who how many coins?\n");
    return 0;
  }

  if(verb == "give") return (status)"/inherit/base/actions" -> give_object(message);
  else
    return (status)"/inherit/base/actions" -> put(message);
  return (status)"/inherit/base/actions" -> put(message);
  /* fail safe */
}
#else
status put(string str) {
	if(query_verb() == "give")
		return (int)previous_object()->give_object(str);
    else
    	return (int)previous_object()->put(str);
    return (int)previous_object()->put(str);
}
#endif /*parse_command*/

status parse_put(mixed *items, string prep, object container) {
  int i, counter, num;
  string sh;
  string adverb;
  object *ob;
  string tmp1, tmp2;
  int bag_num;




  if(!container && !prep) container = environment(this_player());
  else
    container = present("Container", this_player());

  if(!container) container = environment(this_player());





  ob = ({ });
  num = items[0];

  if(!container->can_put_and_get()) {
    notify_fail("You can't put anything in "+ container->short() +"!\n");
    return 0;
  }

  for(i=1; i<sizeof(items); i++) {

    /* get a counting of items */
    if(num > 0) {
      if(!present(items[i], this_player())) continue;
        /* dont want to drop items we dont have */
      if(++counter > num) break;
      ob += ({ items[i], });
    }
    /* get the counter'th item */
    else if(num < 0) {
      if(!present(items[i], this_player()))
      counter--;
      if(counter == num) {
        ob += ({ items[i], });
        break;
      }
    }
    else {
        ob += ({ items[i], });
    }
  }


  if(!prep) prep = "in";

  if(!sizeof(ob)) {
    notify_fail("There is nothing here to "+ verb +".\n");
    return 0;
  }

  for(i=0; i<sizeof(ob); i++) {
    sh = (string)ob[i]->short();
    if(!strlen(sh)) sh = ob[i]->query_name();
    if(!strlen(sh)) continue;
    sh = lower_case(sh);

    if(!present(ob[i], this_player())) continue;
    if(ob[i] == this_player()) continue;
    if(ob[i]->drop()) continue;
    if(ob[i] == container) continue;

    if(!container->add_weight(ob[i]->query_weight())) {
      write(container->short()+" can't carry "+sh+"!\n");
      continue;
    }

    write("You"+ ((adverb) ? " "+adverb : "") +" "+ verb +" "+ sh +" "+
    prep +" "+ lower_case(container->short())+".\n");

    say(NAME +" "+ verb +"s "+ sh +" "+ prep +" "+
    lower_case(container->short()) +".\n", this_player());

    environment(ob[i]) -> add_weight(-(ob[i])->query_weight());

    move_object(ob[i], container);
    putSomething = 1;
  }
  if(!putSomething) {
    if(!(status)"/inherit/base/actions" -> put(message)) {
      notify_fail(capitalize(verb)+" what? in where?\n");
      return 0;
    }
    notify_fail(capitalize(verb)+" what? in where?\n");
    return 0;
  }
  if(!putSomething) {
    write("Put what? in where?\n");
    return 1;
  }
  return 1;
}



