inherit "inherit/timer";
#include <humanoid.h>

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"


status hold(string spell_type, mixed alt_type, string class) {
  int time, i;
  string file;
  string targ;
  string spell_name;
  int spell_level;

  if(!spell_type) {
    notify_fail("Hold Person, hold monster?\n");
    return 0;
  }
  if(!alt_type) alt_type = "charm";
  if(!class) class = "mage";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level()
       : (int)this_player()->query(alt_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  sscanf(spell_type,"%s %s", spell_type, targ);
  spell_type = lower_case(spell_type);
  switch(spell_type) {
    case "person":
      spell_name  = "Hold Person";
      spell_level = 12;
    break;

    case "monster":
      spell_name  = "Hold Monster";
      spell_level = 15;
    break;

    default:
      notify_fail("Hold Person, hold monster?\n");
      return 0;
    break;
  }

  this_player()->load_spell(({
  "target",            targ,
  "name",              spell_name,
  "sphere",            alt_type, 
  "cost",              spell_level,
  "damage",            time, /* used as time, no damage */
  "immune",            "charm",
  "level",             spell_level,
  "class",             class,
  "cast time",         1,
  "spell object",      file,

/* other spell options...
  "area",
  "casting msg",       0,
  "casting msg room",  0,
  "msg target",        0,
  "msg room",          0,
  "msg caster",        0,
  "passive",
  "component",         0,
 */
  }));
  return 1;
}

/***********************************************************************/
/* when cloned to target */

void time_out() {
  tell_object(environment(),"You feel free of the Hold spell.\n");
  ::time_out();
}

void dispel_magic() { time_out(); } /* std spell fn to clean up */

status cast_spell(object caster,object target,object prev,int dmg) {
  object hold;
  object no_quit;

  if((string)caster->query_spell_name() == "Hold Person") {
    if(!humanoid(target)) {
      tell_room(environment(target),"Nothing Happens....\n");
      destruct(this_object());
      return 1;
    }
  } /* else hold monster spell */
    
  if(!target->query_made_my_save()) {
    hold = present("Hold 2", target);
    if(hold) {
      tell_object(caster,"You extend the time of the Hold spell on "+
                  (string)target->query_name()+".\n");
      hold->adj_time(dmg);
      no_quit = clone_object("obj/skills/no_quit");
      no_quit->start(dmg);
      move_object(no_quit,caster);
      destruct(this_object());
      return 1;
    }
    tell_object(caster,"You see "+(string)target->query_name()+
               " being held by a tremendous force.\n");
    tell_object(target,"You are gripped by a tremendous force.\n");
    say((string)target->query_name()+" suddenly becomes immobile.\n",
        target);
    adj_time(dmg);
  no_quit = clone_object("bin/skills/classes/mage/no_quit");
    no_quit->start(dmg);
    move_object(no_quit,caster);
    return 1;
  }
  tell_room(environment(target),"Nothing Happens....\n");
  destruct(this_object());
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

