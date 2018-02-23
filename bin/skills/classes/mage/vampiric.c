/*** Vampiric Touch, Drakken Jan 1994 ***/
 
#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"
 
status vampiric(string target, mixed alt_type, string class) {
  int dam, i;
  string file;
 
  if(!target || !(target == "touch" || sscanf(target,"touch %s",target))) {
    notify_fail("vampiric touch?\n");
    return 0;
  }
  if(target == "touch") target = 0;
  if(!alt_type) alt_type = "necromancy";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(5) + 1);
  if(dam > 40) dam = 40;
 
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
 
  this_player()->load_spell(({
  "target",            target,
  "name",              "Vampiric Touch",
  "sphere",            alt_type, 
  "cost",              12,
  "damage",            dam,
  "level",             12,
  "class", class,
  "cast time",         2,
  "spell object",      file,
  "casting msg",       ({
                         "Your hand is encompassed with a blue glowing aura.\n",
                       }),
  "casting msg room",  ({ 
                          NAME +"'s hand is encompassed with a blue "+
                          "glowing aura.\n",
                       }),
  "msg target",       "You feel a sudden chill throughout your body.\n",
  "msg room",         TARG +" shrieks in pain.\n",
  "component",        "corpse#skeleton#bone",
  }));
  return 1;
}
 
/******************************************************************/
/* when cloned to target */
 
cast_spell(object caster,object target,object prev,int dmg){
  if(!target->query_made_my_save()) {
    if(dmg < 25)
      caster->adj_hp(dmg);
    else
      caster->adj_hp(25);
    caster->adj_alignment(-dmg);
  }
  destruct(this_object());
  return 0;  /* do damage */
}

