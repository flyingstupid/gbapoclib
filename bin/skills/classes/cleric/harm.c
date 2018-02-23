/* heal */

#define CAST (string)caster->query_name()
#define TARG (string)target->query_name()

status harm(string targ, mixed alt_type, string class) {
  string file;
  int i;

  if(!alt_type) alt_type = "healing_sphere";
  if(!class) class = "cleric";

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
  
  this_player()->load_spell(({
  "target",            targ,
  "name",              "Harm",
  "sphere",            alt_type, 
  "cost",              30,
  "level",             30,
  "class", class,
  "immune",            "death",
  "cast time",         5,
  "damage",            2, /* flag */
  "spell object",      file,
  "casting msg",  ({
                    "You request to your god to for wounding energies.\n",
                    "You feel a chill spreads throughout your body.\n",
                    "Powerful wounding energies swirl about you.\n",
                    "The energies are almost too much for you!\n",
                  }),
  }));
  return 1;
}


/*********************************************************************/
/* when cloned to player */


status cast_spell(object caster,object target,object prev,int dmg) {
  if(!this_player()->add_secondary_attacker(target)) {
     write("You can't harm "+target->query_name()+".\n");
     return 1;
   }
  if(dmg == 2) { /* did not save */
    dmg = (int)target->query_hp();
    target->adj_hp(20 - dmg);
    write(TARG +" screams as massive wounds open up on "+
         target->query_objective() +".\n");
    say(TARG +" screams as massive wounds open up on "+
         target->query_objective() +".\n", target);
    tell_object(target,"You scream as massive wounds open up on you.\n");
  }
  else {
    tell_room(environment(caster),"Nothing Happens...\n");
  }
  destruct(this_object());
  return 1;
}

