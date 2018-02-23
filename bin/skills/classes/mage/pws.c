/* power word stun */

inherit "inherit/timer";

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status pws(string targ, mixed alt_type, string class) {
  int time, i;
  string file;

  if(!alt_type) alt_type = "conjuration";
  if(!class) class = "mage";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level()
       : (int)this_player()->query(alt_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);


  this_player()->load_spell(({
  "target",            targ,
  "name",              "Power Word Stun",
  "sphere",            alt_type, 
  "cost",              15,
  "damage",            time, /* used as time, no damage */
  "level",             15,
  "class", class,
  "cast time",         1,
  "spell object",      file,
  }));
  return 1;
}

/***********************************************************************/
/* when cloned to target */

void time_out() {
  tell_object(environment(),"Your mind clears...\n");
  ::time_out();
}

void dispel_magic() { time_out(); } /* std spell fn to clean up */

status cast_spell(object caster,object target,object prev,int dmg) {
  object hold;

  hold = present("Hold 2", target);
  if(hold) {
    tell_object(caster,"You extend the time of the Stun spell on "+
                (string)target->query_name()+".\n");
    hold->adj_time(dmg);
    destruct(this_object());
    return 1;
  }
  tell_object(caster,"You see "+(string)target->query_name()+
               " stagger as they are stunned!\n");
  tell_object(target,"You real from the power word's stunning effect!\n");
  say((string)target->query_name()+" suddenly staggers.\n",
       target);
  adj_time(dmg);
  return 1;
}


status id(string str) {
  return str == "spell"
      || str == "Hold";
}

status drop(status quit) {
  if(quit) time_out();
  return 1;
}

