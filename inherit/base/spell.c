
#pragma strict_types
#pragma save_types
#pragma combine_strings


#include <mudlib.h>
#include <spell.cfg>
#include <spell.h>
#include <combat.cfg>

#ifndef NAME
#define NAME    (string)this_object()->query_name()
#endif

#define IS_NPC  (status)this_object()->query_npc()

static int magic_resist;        /* resistance to offensive spells          */  
static int spell_time;          /* spell casting counter                   */
static status made_my_save;     /* a check cause now spell dmg is variable */

static string *spell_immune;    /* Spell types that being is immune to     */

static mixed *loaded_spell;     /* spell cast next heart beat              */


/***************************************************************************/
/* Sets */
string *set_spell_immune(string *arr) { 
  return spell_immune = (arr) ? arr : ({});
}

mixed *set_loaded_spell(mixed *arr) {
  return loaded_spell = (arr) ? arr : ({});
}

int set_magic_resist(int i) {
  return magic_resist = ((i > 100) ? 100 : ((i < 0) ? 0 : i));
}




/***************************************************************************/
/* Queries */
int query_spell_dmg()   { return (sizeof(loaded_spell)) ? SPELL_DAM : -1; }
int query_magic_resist(){ return magic_resist;                            }
int query_save_bonus()  { 
  return (int)this_object()->query_race_save_bonus();
}

string query_spell_name() { return (sizeof(loaded_spell)) ? SPELL_NAME : 0; }
string *query_all_spell_immune() { return spell_immune;      }

mixed query_spell_argument() { return (sizeof(loaded_spell)) ? ARGUMENT : 0; }
mixed *query_loaded_spell()  { return loaded_spell;                          }

status query_spell_area() {
  return (!sizeof(loaded_spell)) ? 0 : ((AREA_EFFECT) ? 1 : 0);
}

status query_class_spell() { return (sizeof(loaded_spell)) ? SPELL_CLASS : 0; }

status query_spell_immunity(string str) {
  if(!spell_immune) spell_immune = ({});
  return (member_array(str, spell_immune) == -1) ? 0 : 1;
} 
 
status query_spell_immune(string str) {
  return query_spell_immunity(str);
}

status query_made_my_save()      { return made_my_save;      }



/***********************************************************************/
/* Adds, Removes and Adjs */

int adj_magic_resist(int i) {
  return magic_resist += ((i > 100) ? 100 : ((i < 0) ? 0 : i));
}

void add_spell_immunity(string str) {  
  if(!query_spell_immunity(str) && str) spell_immune += ({ str, });
} 

void add_spell_immune(string str) {
  add_spell_immunity(str);
}



void remove_spell_immunity(string str) {  
  int i;

  if(!spell_immune || !sizeof(spell_immune)) spell_immune = ({ });
  if((i = member_array(str, spell_immune)) != -1) {
    spell_immune = spell_immune[0..i-1]
                 + spell_immune[i+1..sizeof(spell_immune)-1];
  }
}     

void remove_spell_immune(string str) {
  remove_spell_immunity(str);
}


/*************************************************************************/
/* check_spell */


varargs status check_spell(string id, object ob) {
  object env;

  if(!ob) ob = this_object();
  env = environment(ob);
  return (env->query_property(id) || present(id,ob) || present(id, env)) 
       ? 1 : 0;
}


/**************************************************************************/
/* spell attacks */

/* 
 * A spell undergoes 3 processes. 1. load spell 2. cast spell 3. hit by spell
 *
 * 1. load_spell() was design to give an easy to understand front-end
 *    making the development of new spells quite easy. It easily allows
 *    area effect, offensive and passive spells. And includes features
 *    such as casting time, file name for cloning an object to the target,
 *    and a spell component.
 *
 * 2. cast_spell_at_target() handles the target finding of the spell. It
 *    handles both single target, and area effects.
 *
 * 3. spell_hit() handles the resistance checks (which can be overrided
 *    by the "passive" flag in 1). It also features the capability of
 *    the target to capture the spell. It also handles cloning a
 *    "spell object" to the target and calls cast_spell() in the spell object.
 */

static status cast_spell_block; /* stops inappropriate cast_spell call */


/* component extension, '#' == 'or'; '+' == 'and'
 *
 * eg. "component", "rope#cord+diamond#emerald",
 *   will require a rope or a cord, and a diamond or an emerald for
 *   spell components.
 */

object *parse_component(string str) {
  string *pluses, *hashes, tmp;
  object *components, comp;
  int i, j, k;

  if(!str) return ({});
  components = ({});
  pluses = explode(str,"+");
  for(i = 0; i < sizeof(pluses); i++) {
    hashes = explode(pluses[i],"#");
    for(j = 0; j < sizeof(hashes); j++) {
      sscanf(hashes[j],"%s %d", hashes[j], k);
      for(k = 1, comp = 0;
          (comp = present(hashes[j] +" "+ k))
          && member_array(comp,components) != -1;
          k++);
      if(comp) {
        if(comp->id("illusion") ||
           comp->id("illusion spell")) {
           write("You can't use "+comp->query_name()+" as a spell component!\n"+
                "It's just an illusion.\n");
           continue;
        }
        components += ({ comp, });
        break;
      }
    }
    if(sizeof(components)-1 != i) { /* component not found */
      return ({});
    }
  }
  return components;
}


void unload_spell() {  
  loaded_spell = ({});
  cast_spell_block = 0;
}

/* common spell queries */


/* OLD_AREA_EFFECT - get list of victims when spell is finished casting */
/* otherwise - get list of victim when initially start casting           */ 

status load_spell(mixed *arr) { /* prepare caster to cast spell */
  int i;
  string god_name;
  string tmp1, tmp2;

  if(present("holy symbol", this_object()))
    god_name = (string)(present("holy symbol", this_object()))-> query_affiliation_sponsor();


  if(sizeof(loaded_spell)) {   /* we already had a spell loaded */
    if(this_object()->query_npc()) {
      this_object()->cast_spell_at_target();  /* cast it anyway */
      return 1;
    }
    if(objectp(SPELL_TYPE)) {
      write("You stop casting the spell.\n");
    }

    else if(SPELL_TYPE) {
      switch(SPELL_CLASS) {
        case "cleric" :
          write("You stop praying the prayer "+
              ((SPELL_NAME) ? ", "+ SPELL_NAME : "") 
                +".\n"+ ((god_name) ? god_name : "Your god" ) +" looks "+
                "down on you with disdain.\n");
        break;

        case "thief" :
          write("You end your stealthy actions and change your mind about the backstab . . .\n");        
        break;

        case "psionicist" :
          write("You stop concentrating on the "+ SPELL_NAME +" power.\n"+
             "Your mental energy fizzles into the Space-Time continuum.\n");
        break;

        case "bard" :
          write("You stop singing for "+ ((SPELL_NAME) ? SPELL_NAME : "your song") +"\n");
        break;

        // Add our interupts for our classes -Critical
        
        case "medic":
        write("Your interupted from your procedure!\n");
        break;
        
        case "techman":
        write("Something errored in your code!\n");
        break;
        
        default :
          write("You stop casting "+ ((SPELL_NAME) ? SPELL_NAME : "your spell") +"\n"+
		    "The spell's energy fizzles into the Space-Time continuum.\n");
        break;
      }
    }
  }
  spell_time = 0;
  loaded_spell = allocate(SPELL_ALLOCATE); 
  for(i = 0; i < sizeof(arr); i++) {
    if(!stringp(arr[i])) continue;
    switch(arr[i]) {
      case "target":                    TARGET      = arr[++i];     break;
      case "name": case "spellname":    SPELL_NAME  = arr[++i];     break; 
      case "school": case "sphere":     SPELL_TYPE  = arr[++i];     break;
      case "cost":                      SPELL_COST  = arr[++i];     break;
      case "damage":                    SPELL_DAM   = arr[++i];     break;
      case "msg target":                TARGET_MSG  = arr[++i];     break;
      case "msg room":                  ROOM_MSG    = arr[++i];     break;
      case "msg caster":                CASTER_MSG  = arr[++i];     break;
      case "immune":                    IMMUNE_TYPE = arr[++i];     break;
      case "level": case "spell level": SPELL_LEVEL = arr[++i];     break;
      case "spell object":              SPELL_OBJ   = arr[++i];     break;
      case "time": case "cast time":    SPELL_TIME  = arr[++i];     break;
      case "casting msg":               PREPARE_MSG = arr[++i];     break;
      case "casting msg room":        PREP_MSG_ROOM = arr[++i];     break;
      case "component":                 COMPONENT   = arr[++i];     break;
      case "passive":                   PASSIVE     = 1;            break;
      case "aggressive":                PASSIVE     = 0;            break;
      case "argument":                  ARGUMENT    = arr[++i];     break;
      /* experimental */
#ifdef OLD_AREA_EFFECT
      case "area":                     AREA_EFFECT = this_object(); break;
#else
      case "area":     AREA_EFFECT = all_inventory(environment());  break;
#endif
      case "class":                    SPELL_CLASS = arr[++i];      break;
    }
  }

  if(environment(this_player())->query_no_fight() && !PASSIVE) {
    write("Fighting is not allowed here.\n");
    this_player()->stop_fight(this_object());
    this_object()->stop_fight(this_player());
    this_player()->unload_spell();
    this_object()->unload_spell();
    return 0;
  }
  if(!objectp(SPELL_TYPE)) { 
    if(COMPONENT) {
      if(this_object()->query_npc()) {
        COMPONENT = ({});
      }
      else {
        COMPONENT = parse_component(COMPONENT);
        if(!sizeof(COMPONENT)) {
          write("You do not have the necessary components for the ");
          switch(SPELL_CLASS) {
            case "cleric"  : write("prayer\n");       break;
            case "psionicist" : write("mental focus\n"); break;
            case "bard"    : write("song\n");         break;
            default        : write("spell\n");        break;
          }
          unload_spell();
          return 0;
        }
      }
    }
    if(this_object()->query_ghost()) {
      write("You can't "+ ((SPELL_CLASS == "cleric") ? "pray" : "concentrate") +" in your "+
      "ethereal state.\n");
      unload_spell();
      return 0;
    }

    if(!(SPELL_CLASS == "psionicist") &&
       !(SPELL_CLASS == "thief")   &&
       (this_object()->query(SPELL_TYPE) < SPELL_LEVEL)) {
      switch(SPELL_CLASS) {
        case "cleric" :
          write(((god_name) ? god_name : "The gods") +" will not grant you that prayer yet.\n");
        break;

        case "psionicist" :
          write("You do not have enough knowledge for that mental power yet.\n");
        break;

        case "bard" :
          write("You do not have the knowledge for that song spell as yet.\n");
        break;

        // Our stuff for for lack of skill -Critical
        case "medic" :
        write("You don't know how to even begin to do that.\n");
        break;
        
        case "techman":
        write("You wouldn't even know how to begin to explain that in code.\n");
        break;
        
        default :        
        write("You do not have enough knowledge to cast that spell.\n");
        break;
      }
      unload_spell();
      return 0;
    }
    if(!(SPELL_CLASS == "thief") && this_object()->query(SPELL_TYPE+"_points") < SPELL_COST) {
      write(((SPELL_NAME) ? "You have no power left. Your "+
        SPELL_NAME+" fizzles!!\n" : "It fizzles!!\n"));
      unload_spell();
      return 0;
    }
    if(SPELL_CLASS == "psionicist") {
      if(random((int)this_object()->query(SPELL_TYPE)) < random(SPELL_LEVEL)) {
        write("Your concentration dwindles, and your energy is lost.\n");
        call_other(this_object(), "adj_"+SPELL_TYPE+"_points", -SPELL_COST/2);
        unload_spell();
        return 0;
      }
      else if(random((int)this_object()->query(SPELL_TYPE)) ==
              random(SPELL_LEVEL)) {
        write("Your mind focuses perfectly with the energies of "+
         "the cosmos.\n");
        SPELL_DAM *= 2;
      }
      else if(!random((int)this_object()->query(SPELL_TYPE))) {
        write("Your mind opens up and all the energy seeps away...!\n");
        call_other(this_object(), "adj_"+SPELL_TYPE+"_points", -SPELL_COST*2);
        unload_spell();
        return 0;
      }
    }

    call_other(this_object(),"adj_"+SPELL_TYPE+"_points",-SPELL_COST);
  }
  else { /* wand */
    if(COMPONENT) COMPONENT = ({});
    if((int)SPELL_TYPE->query_charges() < SPELL_COST) {
      write(((SPELL_NAME) ? "Your "+SPELL_NAME : "It") + " fizzles!!\n");
      unload_spell();
      return 0;
    }
    SPELL_TYPE->adj_charges(-SPELL_COST);
  }

  if(PREPARE_MSG && !pointerp(PREPARE_MSG)) {
    PREPARE_MSG = ({ PREPARE_MSG, });
  }
  if(PREP_MSG_ROOM && !pointerp(PREP_MSG_ROOM)) { 
    PREP_MSG_ROOM = ({ PREP_MSG_ROOM, });
  }

  if(!objectp(SPELL_TYPE)) {
    if(SPELL_NAME) {
      if(objectp(SPELL_CLASS)) write("SPELL_CLASS is object!\n");
      if(!SPELL_CLASS) SPELL_CLASS = "wand";
      switch(SPELL_CLASS) {
        case "cleric" :
          write("You offer up a "+SPELL_NAME+" prayer to "+((god_name) ? god_name : "the gods")+"...\n");
          say(NAME+" begins praying a silent prayer "+((god_name) ? "to "+god_name : "to the gods")+
			" . . .\n");
        break;

        case "psionicist" :
          say(NAME+" begins concentrating...\n");
          write("You begin concentrating upon a "+ SPELL_NAME +"...\n");
        break;

        case "thief" :
          write("You wait for the right moment to attack . . . \n");
        break;

        case "bard" :
          write("You begin to sing, mixing song and magic in perfect harmony...\n");
          say(NAME +" starts to sing a haunting melody . . . \n");
        break;

        case "wand" :
          write("Magical energies begin to flow around you...\n");
          say("Magical energies begin to flow around "+ NAME +"...\n");
        break;

        // Adding in our classes so they can use the spell loader too -Critical
        case "medic" :
            write("You start to dig through your medpack...\n");
            say(NAME+" starts to dig through their medpack...\n");
        break;
        
        case "techman" :
            write("You start punching in commands on your wrist computer...\n");
            say(NAME+" starts punching in commands on their wrist computer..\n");
        break;
        
        default :
          write("You begin chanting a "+ SPELL_NAME +" spell...\n");
          say(NAME+" begins chanting in an ancient language...\n");
        break;
      }
    }
  }
  return 1; 
}

/* old function name was cast_spell() but this clashed when spell object
   was living 
 */

void cast_spell_at_target() {  /* find target */
  object ob, *env, first_ob;
  status thief_bs;
  int i, size, spell_dam;
  int player_enter_flag; /* player has entered after area spell started */
  string who, spell_name;
  status check_flag;
  status saved;
  object tmpOb;
  string tmpType;
 

  if(!sizeof(loaded_spell)) return; /* no spell loaded */
  if(cast_spell_block) return;      /* stop inappropriate recursive calls */
  cast_spell_block = 1;  
  thief_bs = (SPELL_TYPE == "backstab")  ? 1 : 0;

  if(AREA_EFFECT) {
#ifdef OLD_AREA_EFFECT 
    env = all_inventory(environment());
    size = sizeof(env);
#else /* experimental area effect for pkill */
    if(!pointerp(AREA_EFFECT)) {
      log_file("AREA",file_name(this_object()) +
                      (string)"obj/wizard"->string_results(AREA_EFFECT)
                     +"\n");
      AREA_EFFECT = 0;
      size = 1;
    }
    else {
      env = AREA_EFFECT;
      AREA_EFFECT = this_object(); /* retain old behaviour */
      size = sizeof(env);
    }
#endif
  }
  else {
    size = 1;
  }
  for(i = 0; i < size; i++) {
    spell_dam = SPELL_DAM;
    if(AREA_EFFECT) {
      TARGET = env[i];
#ifndef OLD_AREA_EFFECT
      if(!TARGET) continue; /* object destructed */
      if(environment(TARGET) != environment()) 
        continue; /* object left room */
#endif
      if(!living(TARGET)) continue;
    }
    if(!check_flag) {
      check_flag = 1;
      if(!thief_bs && check_spell("Nulmagic")) {
        write("Something dispels the energy.\n"); 
        unload_spell();
        return;
      }
      if(!thief_bs && check_spell("Silence")) {
        write("There is a magical silence that inhibits your abilities.\n");
        unload_spell();
        return;
      }
#ifndef ROBES_OF_ALIGNMENT
#define ROBES_OF_ALIGNMENT
#endif
#ifdef ROBES_OF_ALIGNMENT
      if(!(SPELL_CLASS == "thief") && !this_player()->query_npc())
        call_other("/function/magic", "misc_magic", this_object());
#endif /* ROBES_OF_ALIGNMENT */

      spell_name = SPELL_NAME; /* used as reference for illegal unloading */
      if(TARGET) {
        who = (stringp(TARGET)) ? TARGET : (string)TARGET->query_name();
        if(!(ob = present(TARGET,environment()))) {
          if(!(ob = present(TARGET, this_object()))) {
            if(TARGET == environment() || TARGET == "room") {
              ob = environment();
              who = "room";
            }
            else {
              if(who != "room") write(capitalize(who)+" is not here.\n");
              unload_spell();
              return;
            }
          }            
        }
        if(ob) TARGET = ob;
        if(PASSIVE && !TARGET) TARGET = this_object();
        if(!living(ob)) { /* cast at non-living object */ 
          if(!SPELL_OBJ) {
            write("It has no effect on "+capitalize(who)+".\n");
            break;
          }
          ob = clone_object(SPELL_OBJ); 
          move_object(ob, TARGET); /* changed from this_object() */
          if(!ob->cast_spell(this_player(),TARGET,0,spell_dam)) {
            if(CASTER_MSG) 
              write(this_object()->process_msg(CASTER_MSG));
            if(ROOM_MSG)   
              say((string)this_object()->process_msg(ROOM_MSG),
                  ({ this_object(), this_player() }) );
          }
          break;
        }
      }
      if(!PASSIVE) {
        if(!TARGET) {
          if(this_object()->query_primary_attack()) {
            if(present((object)this_object()->query_primary_attack(),
              environment())) {
              TARGET = (object)this_object()->query_primary_attack();
            }
            else {
              write((string)(this_object()->query_primary_attack())
                        -> query_name()+" is not here.\n");
              unload_spell();
              return;
            }
          }
          else {
            write("Attack who?\n");
            unload_spell();
            return;
          }
        }
      }
      else if(!TARGET) { /* passive && no target */
        TARGET = this_player();
      }
    }
    if(!TARGET) continue; /* bypass area effect anomalies */
    if(!PASSIVE && spell_dam != -1) { 
      tmpOb = (object)this_player()->query_right_weapon();
      if(tmpOb) tmpType = (string)tmpOb->query_type();


      if(!(SPELL_CLASS == "thief"))
        this_object()->attack_msg(spell_dam, "spell", TARGET, 0);
      else {
        this_object()->attack_msg(spell_dam,
          tmpType, TARGET, "right");
        write("You slowly move from the shadows toward "+TARGET->query_name()+".\n");
        if(this_object()->query_hide_in_shadows_object())
          destruct((object)this_object()->query_hide_in_shadows_object());
        this_object()->add_secondary_attacker(TARGET);
        /* just to make sure */
      }
      if(this_object()->query_disguise_on()) {
        write(TARGET->query_name() +" will remember that face next time . . . \n");
        TARGET->add_sec_att_name(this_object()->query_name());
        this_object() -> toggle_disguise();
      }
    }



    spell_dam = (int)TARGET->spell_hit(spell_dam,
                                      CASTER_MSG,
                                      TARGET_MSG, 
                                        ROOM_MSG,
                                     AREA_EFFECT,
                                       SPELL_OBJ,
                                     IMMUNE_TYPE,
                                      SPELL_TYPE,
                                         PASSIVE);

    if(!sizeof(loaded_spell)) { /* failsafe */
      this_object()->log("SPELL_UNLOAD","Illegal spell unload by "+
                spell_name,0);
      return;
    }
    if(TARGET) AREA_EFFECT = TARGET; /* thus we know who spell hit last */
  }
  if(pointerp(COMPONENT)) {  /* destruct component list */
    for(i = 0; i < sizeof(COMPONENT); i++) {
      if(COMPONENT[i]) {
        if(COMPONENT[i]->id("Illusion") ||
           COMPONENT[i]->id("illusion") ||
           COMPONENT[i]->query_illusioin_object()) {
          tell_object(this_object(), "You can't use an illusion for spell "+
                                "components!\n");
          unload_spell();
          return;
        }
      }
      if(COMPONENT[i]) COMPONENT[i]->drop(1);
      if(COMPONENT[i]) destruct(COMPONENT[i]);
    }
  }
  if(objectp(SPELL_TYPE)) SPELL_TYPE->end_spell(); /* tell wand finished */


  unload_spell(); /* unload spell */
}  
 

/* thus in process_msg(), this_object() == target, this_player() == caster */
/* note that the caster will still have their spell loaded, so 
 * caster->query_loaded_spell() will yield the spell cast at you.
 * Also a comparison between dmg and caster->query_spell_dmg() will
 * indicate whether the target saved, or resisted the spell.
 */

int spell_hit(int dmg,     /* spell damage */
    string caster_msg,     /* message to caster */
    string target_msg,     /* message to target */
      string room_msg,     /* message to room */ 
          object prev,     /* if area effect spell, previous target */ 
         string fname,     /* filename of spell object */
   string immune_type,     /* immune type */
           mixed type,     /* the spell's type */ 
       status passive) {   /* no resistance checks */
  object alt, target_ob;
  int save;
  int z;
  status thief_bs;

  made_my_save = 0; /* reset this variable! */
  thief_bs = (type == "backstab")  ? 1 : 0;


  if(!passive) {

    if(query_magic_resist() > random(100)) {
      dmg = 0;
      made_my_save = 1;
    }
    if(immune_type && query_spell_immunity(immune_type)) {
      dmg = 0;
    }
     if(!thief_bs)
       save = (int)this_object()->query_wisdom();
     else
       save = (int)this_object()->query_intelligence();

     save = save + 1 + (int)this_object()->query_save_bonus();

    if(save < 2) save = 2; 
    if(immune_type && query_spell_immunity("-"+immune_type)) {
      save /= 2;
      if(save < 2) save = 2;
      dmg *= 2;
      /* creatures more suseptable to certain types of attacks */
    }
    if(objectp(type)) {  /* make our save */ 
      if(random((int)type->query_cast_level()+1) < random(save)) {

        dmg /= 2;
        made_my_save = 1;
      }
    }
    else {
 
      if(random((int)this_player()->query(type)+1) < random(save)){
        if(thief_bs) {
          write(NAME+" notices you sneaking up on "+
          this_object()->query_objective()+"!!\n");
          say(this_player()->query_name()+" tries to sneak up on "+NAME+"!!\n",
            this_player());
          tell_object(this_object(), this_player()->query_name()+" tries to "+
          "sneak up on you!\n");
          unload_spell();
          this_object()->add_secondary_attacker(this_player());
          return 0;
        }
        dmg /= 2;
        made_my_save = 1;
      }
    }
    for(z = 1; (alt = present(ALT+" "+z, this_player())); z++) {
      dmg += (int)alt->query_extra_spell_dmg(dmg, type);
    }
    for(z = 1; (alt = present(GUILD_OB+" "+z, this_player())); z++) {
      dmg += (int)alt->query_extra_spell_dmg(dmg, type);
    }
  }
  if(fname) {
    target_ob = clone_object(fname);  /* weakness - failure will stop heart */
    move_object(target_ob, this_object());
  }
  for(z = 1; (alt = present(ALT+" "+z, this_object())); z++) {
    if(alt->spell_capture(this_player(),this_object(),target_ob,prev,dmg)) {
      if(!passive
      && (!prev || this_player()->query_npc() || (prev && IS_NPC))) {
        this_object()->add_secondary_attacker(this_player());
      }
      return 0;
    }
  }
  for(z = 1; (alt = present(GUILD_OB+" "+z, this_object())); z++) {
    if(alt->spell_capture(this_player(),this_object(),target_ob,prev,dmg)) {
      if(!passive
      && (!prev || this_player()->query_npc() || (prev && IS_NPC))) {
        this_object()->add_secondary_attacker(this_player());
      }
      return 0;
    }
  } 
  if(target_ob) {          /*  caster,       target,    previous target, */
    if(target_ob->cast_spell(this_player(),this_object(),prev,dmg)){
      if(!passive
         && (!prev ||
         this_player()->query_npc() ||
         (prev && this_object()->query_npc()))) {
        if(this_object())
          this_object()->add_secondary_attacker(this_player());
      }
      return -1; /* No hit_player or dmg msg */
    }
  }
  if(!passive
  && !prev && !this_object()->add_secondary_attacker(this_player())) {
    if(!thief_bs) {
      write("The law prevents you from casting spells at "+ NAME +".\n");
      say(this_player()->query_name() 
       +" attempts to cast a spell at "+ NAME +"!\n", this_object());
      tell_object(this_object(), this_player()->query_name() 
       +" tries to cast a spell at you!\n");
    }
    else {
      write("The law prevents you from backstabbing "+ NAME +".\n");
      say(this_player()->query_name() +" attempts to backtab "+
        NAME +"!\n", this_object());
      tell_object(this_object(), this_player()->query_name()+" tries to "+
      "backstab you !!\n");
    }
    return -1;
  }
  if(caster_msg && this_object() != this_player()) {
    write((string)this_object()->process_msg(caster_msg));
  }
  if(room_msg) say((string)this_object()->process_msg(room_msg), ({ this_object(), this_player() }));
  if(target_msg)
    tell_object(this_object(), (string)this_object()->process_msg(target_msg));
  if(!prev     
  || (prev && ((status)this_player()->query_npc()^IS_NPC))) {
    if(this_object()->add_secondary_attacker(this_player())) {
      if(!this_object()->query_primary_attack() ||
         environment((object)this_object()->query_primary_attack()) !=
         environment()) {
        this_object()->set_primary_attack(this_player());
      }
    }
  }
#ifdef PK
//#ifdef PK_MOD
  if((status)this_player()->query_npc()^IS_NPC)
    return (int)this_object()->do_damage(dmg);
  else
    return (int)this_object()->do_damage(dmg * PK_MOD);
#else /* !PK */
  return (int)this_object()->do_damage(dmg);
#endif /* !PK */
}
