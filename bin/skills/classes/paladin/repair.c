/*   Repair Armour, Angel October 1993 
 *   Require a forge to do this ! 
 */

#define NAME        (string)this_player()->query_name()
#define DEFAULT     15
#define REPAIR_MOD  350

repair(string str) {
  object arm;
  int chance;
  string tmp1, tmp2;
  int chance1, chance2;
  
/***** temp removed till forge room put in ***
  if(!present("forge", environment(this_player()))) {
    write("You can only repair armour in the presence of a forge.\n");
    return 1;
  }
********/

  if(!str) {
    write("Repair what?\n");
    return 1;
  }
  arm = present(lower_case(str), this_player());

  if(!arm) {
    write("You don't have that!\n");
    return 1;
  }

  if(arm -> query_repair() >= 3) {
    write("There is nothing you can do for "+ arm->short() +".\n"+
    "It already looks too patched and won't survive another repair.\n");
    return 1;
  }
  if(arm -> query_worn() || arm -> query_wielded()) {
    write("You cannot repair your "+str+" while you are ");
    if(arm->query_ac())
      write("wearing");
    else
      write("wielding");
    write(" it!\n");
    return 1;
  }

  if(arm -> query_ac())
    chance1 = this_player()->query_armouring();
    if(sscanf(this_player()->query_race(), "%sdwarf", tmp1))
      chance += 4;
    if(this_player()->query_race() == "gnome")
      chance += 2;
  else
    chance1 = this_player()->query_weapon_smith();
    chance2 = DEFAULT;

  write("You begin to repair "+ arm -> short() +"\n");
  say(NAME +" begins to repair "+ arm -> short() +"\n");

  chance1 = random(chance1);
  chance2 = random(chance2);
  if(chance1 > chance2) {
    if(arm->query_ac()) {
      arm->repair_armour(chance1 * REPAIR_MOD);
    }
    else {
      arm->repair_weapon(chance1 * REPAIR_MOD);
    }
  }
  else {
    arm -> set_current_strength(-(random(chance1) * REPAIR_MOD));
    if(this_player()->query_intelligence() > chance1) {
      write("You think you have done a lowsy job on the "+
      arm->short()+"\n");
    }

  }

  if(arm -> query_current_strength() <= 0) {
    arm -> drop(1);
    write(arm -> short() +" falls to pieces!\n");
    say(NAME +"'s "+ arm -> short() +" falls to pieces!\n");
    destruct(arm);
    return 1;
  }
  write("You finish your repairs on "+ arm -> short() +"\n");
  say(NAME +" finishes "+ this_player()->query_possessive() +" repair of "+
      arm -> short() +"\n");
  return 1;
}


