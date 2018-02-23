#include <mudlib.h>
#include <i_to_str.h>

#define AMT_MONEY  (int)this_player()->query_money()
#define NAME       (string)this_player()->query_name()
#define LEVEL      (int)this_player()->query_level()

/**************************************************************************/
/* put */

status put(string item) 
{ 
  object *items;
  string container; 
  int size, i, wt;
  object ob, to; 
  
  string item_name;
  int abort;
  status havePut;
     

#ifdef RPG
  if(this_player()->check_ooc()) return 1;
#endif /* RPG */

  this_player()->recalc_carry();
  if(this_player()->query_ghost()) 
  {
    tell_object(this_player(),"It passes straight through your hands...\n");
    return 1; 
  } 
  
  if((int)this_player()->query_real_light() < 1) 
  {
    tell_object(this_player(), "It's too dark to do that.\n");
    return 1;
  }

  if(!item) 
  {
    tell_object(this_player(),"Usage: put <item> in <container>\n");
    return 1;
  } 
  sscanf(item, "%s in %s", item, container); 
  sscanf(item, "%s on %s", item, container); 
  if(!container) 
  {
    tell_object(this_player(),"Usage: put <item> in <container>\n");
    return 1;
  }
  container = lower_case(container); 
  if(!(to = present(container, this_player()))) 
  {
    if(!(to = present(container, environment(this_player())))) 
    {
      tell_object(this_player(),"There are no " + container + "s here!\n"); 
      return 1; 
    } 
    if(living(to)) 
    {
      tell_object(this_player(),"You cannot do that!\n");
      return 1;
    }      
  }
  if(item == "all") 
  { 
    items = all_inventory(); 
  } 
  else if(!(ob = present(item, this_player()))) 
  {
    if (!(ob = present (item, environment(this_player()))))
    {
      tell_object(this_player(),"You do not have "+ item +".\n"); 
      return 1; 
    }
  }
  if(ob) items = ({ ob, });

  for(i = 0, size = sizeof(items); i < size; i++) 
  {
    if(items[i] == to) continue; /* can't move items into self */
    if(!objectp(items[i]) || living(items[i])) continue; /* no move living */ 
    if(!(item_name = (string)items[i]->short())) continue; /* no move invis*/
    if(++abort > 30) 
    {
      tell_object(this_player(), "You only pick up "+int_to_str(30)+
      " "+items[i]->query_short()+"\n");
      return 1;
    }
    item = (string)items[i]->query_name();
    if (item)
      item_name = item;

    if ((this_player() == environment(items[i]) && items[i]->drop())
     || (this_player() != environment(items[i]) && !items[i]->get()))
    {
      write ("You cannot put the "+ item_name +" in "+ container +".\n");    
      continue;
    } 
 
    if(!to->can_put_and_get(0)) 
    {
      tell_object(this_player(),"You cannot do that!\n");
      return 1;
    }
     
    wt = (int)items[i]->query_weight();
    if (!to->add_weight(wt))
    {
      write ("The "+ container +" cannot hold the "+ item_name +".\n");
      say (NAME+" attempts to put the "+item_name+" in the "+container+".\n"); 
      continue;
    }
    environment(items[i])->add_weight(-wt);
      
    move_object(items[i], to);
    write("You put the "+ item_name +" into the "+ container +".\n");
    say(NAME+" puts the "+ item_name +" into the "+ container + ".\n");
    havePut = 1;    
  } 
  if (!havePut)
  {
    tell_object(this_player(),"Put? You move the air about in the "+ 
                               container +".\n");
  }
  return 1; 
} 


/***************************************************************************/
/* get */

status pick_up(string item) 
{ 
  string container;
  object from;
  object *items, ob; 
  int abort, haveGet;
  string item_name;
  int size, i, wt;
    

#ifdef RPG
  if(this_player()->check_ooc()) return 1;
#endif /* RPG */

  this_player()->recalc_carry();
  if(this_player()->query_ghost()) 
  {
    tell_object(this_player(),"It passes straight through your hands...\n");
    return 1; 
  } 
  
  if((int)this_player()->query_real_light() < 1) 
  {
    tell_object(this_player(), "It's too dark to do that.\n");
    return 1;
  }
  
  if(!item) 
  {
    tell_object(this_player(),"Usage: get <item|all>\n"+
       "       get <item|all> from <container>\n"); 
    return 1; 
  } 
  sscanf(item, "%s from %s", item, container);
  if(container) 
  {
    container = lower_case(container);
    if(!(from = present(container, this_player()))) {
      if(!(from = present(container, environment(this_player())))) {
        if(!environment(this_player())->id(container)) 
        {
          write("There is no " + container + " here.\n");
        }
        else 
        {
          tell_object(this_player(),"You cannot get anything from the "+
                                    container +".\n");
        }
        return 1; 
    }
    } 
    if(living(from)) 
    {
      tell_object(this_player(),"You cannot do that!\n");
      return 1;
    }      
  }
  else 
  {
    from = environment(this_player());
  }
  if(item == "all") 
  { 
    items = all_inventory(from); 
  } 
  else if(!(ob = present(item, from))) 
  {
    if(!environment(this_player())->id(item)) 
    {
      tell_object(this_player(),"There is no "+ item +" in the "+
                     ((container) ? container : "room") +".\n"); 
    }
    else 
    {
      tell_object(this_player(),"You cannot get the "+ item +".\n");
    }
    return 1; 
  }
  if(ob) items = ({ ob, });

  for(i = 0, size = sizeof(items); i < size; i++) 
  {
    if(items[i] == this_player()) continue; /* can't move items into self */
    if(!items[i]->get())          continue; /* can't pick it up */
    if(!objectp(items[i])) continue;
    if(items[i] -> id("PLAYER")) continue;
    if(items[i]->query_npc()) continue;
    if(!(item_name = (string)items[i]->short())) continue; /* no move invis*/
    if(++abort > 30) 
    {
      tell_object(this_player(), "You get only "+int_to_str(30)+
      " "+items[i]->query_short()+"\n");
      return 1;
    }
    item = (string)items[i]->query_name();
    if (item)
      item_name = item;

/*
    if((environment(this_player()) != environment(items[i])) || (!items[i]->get())) 
    {
      write ("You cannot get the "+ item_name +".\n");
      continue;
    } 
*/

    if (!from->can_put_and_get(0))
    {
      tell_object(this_player(),"You cannot do that!\n");
      return 1;
    }
     
    wt = (int)items[i]->query_weight();
    if (!this_player()->add_weight(wt))
    {
      write ("You're not strong enough to carry the "+ item_name +".\n");
      say (NAME+" attempts to carry the "+item_name+".\n"); 
      continue;
    }
    environment(items[i])->add_weight(-wt);
      
    move_object(items[i], this_player());
    write("You get the "+ item_name +".\n");
    say(NAME+" gets the "+ item_name +".\n");
    haveGet = 1;    
  } 
  if (!haveGet)
  {
    tell_object(this_player(),"Get? You move the air about!!!.\n");
  }
  return 1;
}

/***************************************************************************/
/* give */

status give_object(string item) 
{  
  string who;  
  object *items;
  object ob, dest_ob;  
  int amt;  
  int size, i, wt;
  string item_name;
  int abort;
  
  int haveGive;
  string coins_type;
     

#ifdef RPG
  if(this_player()->check_ooc()) return 1;
#endif /* RPG */

  this_player()->recalc_carry();
  if(this_player()->query_ghost()) 
  {
    write("It passes straight through your hands...\n");
    return 1; 
  } 
  
  if((int)this_player()->query_real_light() < 1) 
  {
    tell_object(this_player(), "It's too dark to do that.\n");
    return 1;
  }

  if(!item) 
  {
    write("Usage: give <item|all> to <who>\n"+
       "       give <amount> coins to <who>\n");
    return 1;
  }  
  sscanf(item, "%s to %s", item, who);
  sscanf(item, "%d %s coins to %s", amt, coins_type, who);
  sscanf(item, "%d coins to %s", amt, who);
  sscanf(item, "%d coin to %s", amt, who);
  if(!who) return give_object(0); 
  if(!(dest_ob = present(who, environment(this_player())))) 
  {
    write(capitalize(who)+" is not here.\n");
    return 1;
  }
  
  if(!living(dest_ob)) 
  {
    write("Thats not giving it away, its throwing it away.\n");
    return 1;
  }

  if(amt) 
  {
    if(amt < 1) 
    {
      write("Are you looking for a loan?\n");
      return 1;
    }
    if(LEVEL < 2) 
    {
      write("Your level is not high enough to be a money lender.\n");
      return 1;
    }
    if(coins_type == "platinum") amt *= PLATINUM;
    else
      if(coins_type == "gold") amt *= GOLD;
    else
      if(coins_type == "silver") amt *= SILVER;
    else
      amt *= COPPER;

    if(amt > AMT_MONEY) amt = AMT_MONEY;
    this_player()->add_money(-amt);
    this_player()->save_me(1);
    dest_ob->add_money(amt);
    dest_ob->save_character();
    tell_object(this_player(),"You give "+capitalize(who)+" "+amt+
       "  coin"+((amt == 1) ? "" : "s")+".\n");
    say(NAME+" gives "+capitalize(who)+" "+amt+
     " coin"+((amt == 1) ? "" : "s")+".\n", dest_ob);
    tell_object(dest_ob,NAME+" gives you "+amt+
     " coin"+((amt == 1) ? "" : "s")+".\n");
    return 1;
  }   
  if(item == "all") { 
    items = all_inventory(); 
  } 
  else if(!(ob = present(item, this_player()))) 
  {
    if(!(ob = present(item, environment(this_player())))) 
    {
      tell_object(this_player(),"You do not have "+ item +".\n"); 
      return 1;
    } 
  }
  if(ob) items = ({ ob, });

  for(i = 0, size = sizeof(items); i < size; i++) 
  {
    if(items[i] == dest_ob) continue; /* can't move items into self */
    if(!objectp(items[i]) || living(items[i])) continue; /* no move living */ 
    if(!(item_name = (string)items[i]->short())) continue; /* no move invis*/
    if(++abort > 30) 
    {
      tell_object(this_player(), "You give only "+int_to_str(30)+
      " "+items[i]->query_short()+"\n");
      return 1;
    }
    item = (string)items[i]->query_name();
    if (item)
      item_name = item;

    if ((this_player() == environment(items[i]) && items[i]->drop())
     || (this_player() != environment(items[i]) && !items[i]->get()))
    {
      write ("You cannot give away the "+ item_name +".\n");
      continue;
    } 
     
    wt = (int)items[i]->query_weight();
    if (!dest_ob->add_weight(wt))
    {
      write (dest_ob->query_name()+" cannot carry the "+ item_name +".\n");
      say (NAME+" attempts give "+ item_name +" to "+
               dest_ob->query_name()+".\n",dest_ob); 
      tell_object (dest_ob,NAME+" trys to give you the "+ item_name
                           +" but you cannot carry it.\n");
      continue;
    }
    environment(items[i])->add_weight(-wt);
      
    move_object(items[i], dest_ob);
    write("You give the "+ item_name +" to "+ dest_ob->query_name() +".\n");
    say(NAME+" gives the "+ item_name +" to "+ dest_ob->query_name() 
       +".\n",dest_ob);
    tell_object(dest_ob,NAME +" gives you the "+ item_name +".\n");
    haveGive = 1;    
  } 
  if (!haveGive)
  {
    tell_object(this_player(),"Give? You move the air about.\n");
  }
  return 1;
}  

 
/***********************************************************************/
/* drop */

status  drop_thing(string item) 
{  
  string container;  
  int size, i, wt;
  object ob, to;  
  object *items;
  int amt;  
  string item_name;
  string coins_type;
  int abort;
  status haveDrop;
     

#ifdef RPG
  if(this_player()->check_ooc()) return 1;
#endif /* RPG */

  this_player()->recalc_carry();
  if(!item) 
  {
    write("Usage: drop <item|all>\n"+
       "       drop <item|all> in <container>\n"+
       "       drop <amount> coins\n"); 
    return 1;
  }  
  sscanf(item, "%d %s coins", amt, coins_type);
  sscanf(item, "%d coins", amt);
  sscanf(item, "%d coin", amt);
  sscanf(item, "%s in %s", item, container);
  if(amt) 
  {
    if(amt < 1) 
    {
      write("Are you looking for a loan?\n");
      return 1;
    }
    if(LEVEL < 2) 
    {
      write("Something prevents you.\n");
      return 1;
    }
    if(coins_type == "platinum") amt *= PLATINUM;
    else if(coins_type == "gold") amt *= GOLD;
    else if(coins_type == "silver") amt *= SILVER;
    else amt *= COPPER;

    if(amt > AMT_MONEY) amt = AMT_MONEY;
    this_player()->add_money(-amt);
    this_player()->save_me(1);
    ob = clone_object(MONEY);
    ob->set_money(amt);
    move_object(ob, environment(this_player()));
    write("You drop "+amt+" coin"+((amt == 1) ? "" : "s")+".\n");
    say(NAME+" drops "+amt+" coin"+((amt == 1) ? "" : "s")+".\n");
    return 1;
  }   
  if(container) 
  {
    container = lower_case(container);
    if(!(to = present(container, this_player()))) 
    {
      if(!(to = present(container, environment(this_player())))) 
      {
         write("There is no " + container + " here.\n");
         return 1; 
      }
    }
    if(living(to)) 
    {
      write("You can't do that!\n");
      return 1;
    }
  }  
  else 
  {
    to = environment(this_player());
  }
  if(item == "all") { 
    items = all_inventory(); 
  } 
  else if(!(ob = present(item, this_player()))) 
  {
    tell_object(this_player(),"You don't have the  "+ item +".\n"); 
    return 1; 
  }
  if(ob) items = ({ ob, });  

  for(i = 0, size = sizeof(items); i < size; i++) 
  {
    if(!objectp(items[i]) || living(items[i])) continue; /* no move living */ 
    if(!(item_name = (string)items[i]->short())) continue; /* no move invis*/
    if(++abort > 30) 
    {
      tell_object(this_player(), "You drop only "+int_to_str(30)+
      " "+items[i]->query_short()+"\n");
      return 1;
    }
    item = (string)items[i]->query_name();
    if (item)
      item_name = item;

    if ((this_player() == environment(items[i]) && items[i]->drop())
     || (this_player() != environment(items[i]) && !items[i]->get()))
    {
      write ("You cannot drop the "+ item_name +".\n");
      continue;
    } 

    wt = (int)items[i]->query_weight();
    if (to != environment(this_player()))
    {
      if (!to->can_put_and_get(0))
      {
        tell_object(this_player(),"You cannot do that!\n");
        return 1;
      }

      if (!to->add_weight(wt))
      {
        write ("You cannot drop the "+ item_name +".\n");
        say (NAME+" attempts drop the "+ item_name +".\n"); 
        continue;
      }
    }
    this_player()->add_weight(-wt);
      
    move_object(items[i], to);
    write("You drop the "+ item_name +".\n");
    say(NAME+" drops the "+ item_name +".\n");
    haveDrop = 1;    
  } 
  if (!haveDrop)
  {
    tell_object(this_player(),"Drop? You fidget in your pockets.\n");
  }

  return 1;
}  
