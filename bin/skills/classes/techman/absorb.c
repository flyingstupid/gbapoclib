/*   Absorb Materials - Critical
 *   Destroys items and gives nanites based on its weight and skills
 */

#define NAME        (string)this_player()->query_name()
#define DESTROY       this_player()->query_destroying()
#define CREATE      this_player()->query_creating()
#define TP          this_player()
int do_absorb();


status absorb(string str) {
  object item;

  
  if(!str) {
    write("Absorb what?\n");
    return 1;
  }
  item = present(lower_case(str), TP);

  if(!item) {
    write("You don't have that!\n");
    return 1;
  }

  if(item -> query_weight() <= 0) {
    write("There is barely anything that "+ item->short() +" is made of to absorb!\n");
    return 1;
  }
  
  
  if(item -> query_worn() || item -> query_wielded()) {
    write("You cannot item your "+ str +" while you are ");
    if(item->query_ac())
      write("wearing");
    else
      write("wielding");
    write(" it!\n");
    return 1;
  }

  
  write("You begin absorb the material of "+ item -> short() +"\n");
  say(NAME +" moves his hands over "+ item -> short() +", a silver shimmer begins to encase it.\n");
  

    call_out("do_absorb",3, item);
    return 1;
}    
    
  void do_absorb ( object obj )
  {
    object ob=obj;
    TP->set_nanites(ob->query_weight()*(DESTROY+CREATE)+TP->query_nanites());
        if(TP->query_nanites() > TP->query_maxnanites())
        {
            TP->set_nanites(TP->query_maxnanites());
        }
    write("You suddenly feel a rush power, as your nanites create thousands more of themselves, ready to serve!\n");
    
    write("The " + ob->query_short() + " disintergrates.\n");
    say("The " + ob->query_short() + " disintergrates.\n");
    
    destruct(ob);
   }
