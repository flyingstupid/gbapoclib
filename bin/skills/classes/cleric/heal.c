/* heal */

#define CAST (string)caster->query_name()
#define TARG (string)target->query_name()

status heal(string targ, mixed alt_type, string class) {
  string file;
  int i;

  if(!alt_type) alt_type = "healing_sphere";
  if(!class) class = "cleric";

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
  
  this_player()->load_spell(({
  "target",            targ,
  "name",              "Heal",
  "sphere",            alt_type, 
  "cost",              30,
  "level",             30,
  "class", class,
  "cast time",         6,
  "spell object",      file,
  "passive",
  "casting msg",  ({
                    "You request to your god to for healing energies.\n",
                    "You feel a warmth spread throughout your body.\n",
                    "You feel a channel embrace you.\n",
                    "Powerful healing energies swirl about you.\n",
                    "The energies are almost too much for you!\n",
                  }),
  }));
  return 1;
}


/*********************************************************************/
/* when cloned to player */


status cast_spell(object caster,object target,object prev,int dmg) {
  target->adj_hp(100000000000);  /* heal lots */
  if(target != caster) {
    write("You lay your hands upon "+ TARG +"\n"+
           target->query_possessive() +"'s wounds has been healed.\n");
    say(CAST +" lays "+caster->query_possessive()+" hands upon "+TARG+".\n"+ 
        TARG +" is healed.\n", target);
    tell_object(target, CAST +" lays "+ caster->query_possessive() 
       +" hands upon you.\nYou are healed!\n");  
  }  
  else {  
    write("You heal your wounds.\n");
    say(CAST +"'s wounds are healed.\n");  
  }  
  destruct(this_object());
  return 1;
}

