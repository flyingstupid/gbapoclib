/** fire storm

Techman's AoE blast attack

 **/
 
 
#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"
 
status firestorm(string arg, mixed alt_type, string class) {
  int dam;
  string targ;
  
  if(!spell_type) {
    notify_fail("firestorm?\n");
    return 0;
  }
 
  sscanf(arg,"%s" , targ);
   
  if(!class) class = "techman";
  if(!alt_type) alt_type = "destroying";

      dam = (objectp(alt_type))
          ? (int)alt_type->query_cast_level() 
          : (int)call_other(this_player(),"query_"+alt_type);
 
    dam *= (random(4) + 1);
    if(dam > 25) dam = 25;
 
      this_player()->load_spell(({
      "target",            targ,
      "name",              "Fire Storm",
      "sphere",            alt_type, 
      "cost",              0,
      "damage",            dam,
      "immune",            "fire",
      "level",             10,
      "cast time",         2,
      "class",             class,
      "area",
      "casting msg",       "A small red dot forms from your fingertip...\n",
      "casting msg room", "A small red dot forms at "+ NAME  
                            +"'s fingertip...\n",
      "msg target",        "A ball of hot flame sears you.\n",
      }));