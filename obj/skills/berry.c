/* goodberry */
#include <mudlib.h>
inherit FOOD;



reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("goodberry");
  set_alias("berry");
  set_short("Goodberry");
  set_long("This small berry is glowing red. It looks really juicy.\n"+ 
           "You can't wait to eat it.\n");
  set_weight(1);
  set_strength(3 * (random(4)+1));
  /* 3 - 12 hp of healing */
}

init(){
  ::init();
  add_action("put","put");
}

status put(string str){
  object ob;
  string bottle;
  int strength;

  if(str && sscanf(str,"goodberry in %s",bottle) == 1){
    if((ob = present(bottle, this_player()))) {
      if(ob->query_alco_drink() || ob->query_soft_drink()){
        write("The berry starts to ferment!\n");
        if(ob->query_full()){
          write("You fortify the "+(string)ob->query_name()+"!\n");
          say((string)this_player()->query_name()+" adds a berry to the "+
              (string)ob->query_name()+"!\n");
          strength = (int)ob->query_strength();
        }
        destruct(ob);
        ob = clone_object("inherit/drink");
        ob->set_name("goodberry liquor");
        ob->set_alt_name("liquor");
        ob->set_short("Goodberry Liquor");
        ob->set_long("This is an attempt at moonshining some "+
                     "Berry Liquor!\n");
        ob->set_alco_drink(1);
        ob->set_strength(strength+8+random(8));
        move_object(ob,this_player());
        destruct(this_object());
        return 1;
      }        
    }
  }
  return 0;
}

query_domain_safe() { return 1; }


status cast_spell(object caster,object target,object prev,int dmg) {
  write("You change the berry into a Goodberry.\n");  
  say("The berry "+ caster->query_name() 
     +" is holding begins to glow softly.\n");   
  return 1;  
}  

