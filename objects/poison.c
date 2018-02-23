/* poison */

inherit "inherit/base/base_obj";

#define DEFAULT_PENALTY 50
#define DEFAULT_DMG     10


#define MAX_HP (int)environment()->query_max_hp()

int poison_penalty;   /* amount subtracted from max_hp */
int poison_rate;
int poison_dmg;
int counter;

void poison();

void reset(status arg) {
  if(arg) return;
  set_name("Poison");
  set_alt_name("poison");
  set_alt_extra_long("You are Poisoned!\n");
  set_extra_long("@@query_name:$environment()$@@ is Poisoned!\n");
  poison_rate = 60; /* once per minute */
}

/* poison max hp penalty */

void set_poison_penalty(int amt) {
  poison_penalty = amt;
}

int query_poison_penalty() { 
  if(poison_penalty > MAX_HP/2) poison_penalty = MAX_HP/2;
  return poison_penalty;
}


/* poison damage */

void set_poison_dmg(int amt) { poison_dmg = amt;  }

int query_poison_dmg()       { return poison_dmg; }


/* poison rate */

void set_poison_rate(int amt) { poison_rate = amt;  }

int query_poison_rate()       { return poison_rate; }



void init() {
  if(!poison_penalty && !poison_dmg) {
    poison_penalty = DEFAULT_PENALTY;
    poison_dmg     = DEFAULT_DMG;
  }

  if(environment()) environment()->adj_constitution(0); /* reset max_hp */
  call_out("poison", 5);
}


void poison() {
  remove_call_out("poison");
  if(!environment()) return;
  if(!living(environment())) {
    destruct(this_object());
    return;
  }
  if(poison_dmg && environment()) {
    if(poison_dmg < (int)environment()->query_hp()) {
      environment()->adj_hp(random(poison_dmg) * (-1));
      tell_object(environment(),"You stagger as poison coarses "+
                                "through your body.\n");
      tell_room(environment(),environment()->query_name() +" staggers as poison coarses "+
          "through "+ environment()->query_possessive() +" body.\n");
    }
    else {
      tell_object(environment(),"The poison overcomes you!\n");
      environment()->death();
    }
  }
/*
  if(++counter > 10) return; 
*/
  if(poison_rate) call_out("poison", poison_rate);
}


status drop(status quit) {
  if(quit) {
    remove_call_out("poison");
    destruct(this_object());
  }
  return 1;
}

mixed query_auto_load() {
  int i;
  string file;

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
  return ({ file, ({poison_penalty, poison_dmg, poison_rate, counter,}), });
}

void init_arg(int *arg) {
  poison_penalty = arg[0];
  poison_dmg = arg[1];
  poison_rate = arg[2];
  counter = arg[3];
  init();
}
 
status cast_spell(object caster,object target,object prev,int level) {
  if(present("Poison 2", target)) {
    write(target->query_name() +" is already poisoned.\n");
    destruct(this_object());
    return 1;
  }
  poison_penalty = level * 2;
  poison_dmg = level;
  init();
  return 1;
}
