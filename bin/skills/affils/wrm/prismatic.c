#include <mudlib.h>
#include <spell.h>


#define CASTER "@@query_name:$this_player()$@@"
#define TARG   "@@query_name:$this_object()$@@"



inherit "inherit/timer";

status prismatic(string spell_type, mixed alt_type) {
  int dam;
  string targ;
  string file;
  int i;

  if(!spell_type) {
    notify_fail("Prismatic <sphere|spray|wall> ?\n");
    return 0;
  }

  sscanf(spell_type,"%s %s", spell_type, targ);
  spell_type = lower_case(spell_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  switch(spell_type) {
    case "spray" : /* level 25 */
      if(!alt_type) alt_type = "evocation";
      dam = (objectp(alt_type))
          ? (int)alt_type->query_cast_level()
          : (int)call_other(this_player(),"query_"+alt_type);
          dam *= (random(10) + 1);
      if(dam > 50) dam = 50;

      this_player()->load_spell(({
        "target",            targ,
        "name",              "Prismatic Spray",
        "sphere",            alt_type,
        "cost",              25,
        "immune",            "light",
        "level",             25,
	"component", "gem#gemstone#stone#rock",
        "damage",            dam,
        "passive", /* have to do this to get end effect! */
        "cast time",         2,
        "area",
        "casting msg",      ({
                "Blinding light sprays from your fingertips.\n",
        }),
        "casting msg room", ({
          "Blinding light sprays from "+CASTER+"'s fingertips.\n",
        }),
        "spell object", file,
      }));
    break;




    case "wall" :  /* level 28 */
      if(!alt_type) alt_type = "evocation";
      dam = (objectp(alt_type))
          ? (int)alt_type->query_cast_level()
          : (int)call_other(this_player(),"query_"+alt_type);
          dam *= (random(11) + 1);
      if(dam > 60) dam = 60;

      this_player()->load_spell(({
        "target",            targ,
        "name",              "Prismatic Wall",
        "sphere",            alt_type,
        "cost",              28,
        "component", "gem#gemstone#stone#rock",
        "immune",            "light",
        "level",             28,
        "damage",            dam,
        "passive", /* have to do this to get end effect! */
        "cast time",         2,
        "area",
        "casting msg",      ({
                "Blinding light sprays from your fingertips.\n",
        }),
        "casting msg room", ({
          "Blinding light sprays from "+CASTER+"'s fingertips.\n",
        }),
        "spell object", file,
      }));


    break;



    case "sphere" :  /* level 30 */
      if(!alt_type) alt_type = "evocation";
      dam = (objectp(alt_type))
          ? (int)alt_type->query_cast_level()
          : (int)call_other(this_player(),"query_"+alt_type);
          dam *= (random(11) + 1);
      if(dam > 70) dam = 70;

      this_player()->load_spell(({
        "target",            targ,
        "name",              "Prismatic Sphere",
        "sphere",            alt_type,
        "cost",              30,
        "component", "gem#gemstone#stone#rock",
        "immune",            "light",
        "level",             30,
        "damage",            dam,
        "passive", /* have to do this to get end effect! */
        "cast time",         2,
        "area",
        "casting msg",      ({
                "Blinding light sprays from your fingertips.\n",
        }),
        "casting msg room", ({
          "Blinding light sprays from "+CASTER+"'s fingertips.\n",
        }),
        "spell object", file,
      }));
    break;

    default:
      notify_fail("prismatic sphere? prismatic spray? prismatic wall?\n");
      return 0;
    break;
  }

  return 1;
}


static mixed  *loaded_spell;
static string *colour, effect, owner, name;

void reset(status arg) {
  if(arg) return;
  colour = ({
        "red", "orange", "yellow", "green", "blue", "indigo", "violet",
  });
}

string query_name() { return name; }

status cast_spell(object caster,object target,object prev,int dmg) {
  object ob;

  loaded_spell = caster->query_loaded_spell();
  owner = capitalize((string)caster->query_name(1));

  name = SPELL_NAME;

  if(SPELL_NAME == "Prismatic Spray") {
    effect = "spray";
    if(target == caster || (caster->query_party()
    && (string)caster->query_party() == (string)target->query_party())) {
      destruct(this_object());
      return 1;
    }
    this_object()->find_out_effect(target,
                                   caster,
                                   colour[random(sizeof(colour)-1)]);
    return 0;
  }



  else if(SPELL_NAME == "Prismatic Wall") {
    if(target != caster) {
      destruct(this_object());
      return 0;
    }
    effect = "wall";
    if(ob = present("wall", environment(caster))) {
      tell_object(caster, 
	"You extend the duration of the Prismatic Wall.\n");
      ob->adj_time(dmg * 30);
      destruct(this_object());
      return 1;
    }
    move_object(this_object(), environment(caster));
    tell_room(environment(caster), 
	"A wall of light forms infront of you!\n");
    adj_time(dmg * 30);
    return 1;
  }

  else if (SPELL_NAME == "Prismatic Sphere") {
    if(target != caster) {
      destruct(this_object());
      return 1;
    }
    effect = "sphere";
    if(ob = present("sphere 2", caster)) {
      tell_object(caster, 
	"You extend the duration on there Prismatic Sphere.\n");
      ob->adj_time(dmg * 30);
      destruct(this_object());
      return 1;
    }
    tell_object(caster, "A Prismatic Sphere forms around you.\n");
    say("A multi-coloured sphere forms around "+caster->query_name()+".\n",
        caster);
    return 1;
  }
  return 0;
}


void find_out_effect(object target, object caster, string colour) {
  object ob;
  string *files;
  int dam;

  dam = SPELL_DAM;

  tell_object(target, "You are struck by "+colour+" light!\n");
  say(target->query_name()+" is struck with "+colour+" light!\n", target);
  if(target != caster && present(caster, environment(target)))
    tell_object(caster, target->query_name()+" is struck with "+
		colour+" light!\n");

  if(effect == "wall") {
    dam /= 10;
    caster = target;
  }

  switch(colour) {
    case "red" :
      caster->attack_msg(dam, "spell", target, 0);
      target->do_damage(dam);
    break;

    case "orange" :
      caster->attack_msg(dam * 2, "spell", target, 0);
      target->do_damage(dam * 2);
    break;

    case "yellow" :
      caster->attack_msg(dam * 3, "spell", target, 0);
      target->do_damage(dam * 3);
    break;

    case "green" :
      ob = clone_object("objects/poison");
      move_object(ob, target);
      ob->cast_spell(caster, target, 0, SPELL_LEVEL);
      tell_object(target, "You are poisoned!\n");
      say(target->query_name()+" staggers from the poison!\n", target);
      if(target != caster && present(caster, environment(target)))
        tell_object(caster, target->query_name()+" staggers from the "+
		"poison!\n");
    break;

    case "blue" :
      ob = clone_object("bin/skills/classes/mage/hold");
      move_object(ob, target);
      ob->cast_spell(caster, target, 0, SPELL_DAM);
    break;

    case "indigo" :
      tell_object(target, "Your mind feels numb...\n");
      say(target->query_name()+" looks confused and muddle minded.\n",target);
      target->set_wisdom((int)target->query_wisdom() - 1); /* ouch */
      if(target != caster && present(caster, environment(target)))
        tell_object(caster, target->query_name()+" looks confused "+
		"and muddle minded.\n");
    break;

    default : /* violet */
      tell_object(target, "A void opens before you and sucks you inside!\n");
      say("A void opens before "+target->query_name()+"\n", target);
      files = ({
                "room/void",
                "players/sarak/minotaur/start",
                "d/coronos/w/angel/city/docks/dock1",
                "d/sorcery/w/angel/path3",
      });
      target->move_player("into the void!#"+files[random(sizeof(files)-1)]);
      if(target->query_npc()) destruct(ob);
    break;
  }
  if(effect == "spray")
    destruct(this_object());
  return;
}



#define NAME    (string)this_player()->query_name()

void init() {
  string tmp;
  if(effect == "wall") {
    if(this_player()->query_name(1) == lower_case(owner)) {
      write("The Prismatic Wall shimmers a little...\n");
      return;
    }
    if(random(SPELL_LEVEL) > random((int)this_player()->query_wisdom())) {
      write("\nYou touch the Prismatic Wall, but it has no effect "+
	"on you.\n\n");
      say(NAME+" touches the Prismatic Wall, but it has no effect on "+
        this_player()->query_objective()+".\n", this_player());
    }
    else {
      write("\nYou touch the Prismatic Wall!\n\n");
      say(NAME+" touches the Prismatic Wall!\n", this_player());
      tmp = colour[random(sizeof(colour)-1)];
      find_out_effect(this_player(), this_player(), tmp);
    }
  }
}



status id(string str) {
  return str == "spell"    ||
         str == "external" ||
         str == "wall"     ||
         str == "sphere"   ||
	 str == name;
}


void extra_long() {
  switch(effect) {
    case "sphere" :
    if(environment() == this_player())
      write("You are surrounded by a multi-coloured sphere of power.\n");
    else
      write("A multi-coloured sphere of power surrounds"+
                environment()->query_name()+".\n");
    break;

    default :
      write("A wall of multi-coloured hues stands in "+
	environment()->short()+"\n");
    break;
  }
}




void long(status wiz) {
  switch(effect) {
    case "sphere" :
      write("A sphere of power with multi-coloured hues.\n");
    default :
      write("A wall of multi-coloured hues, created by "+owner+".\n");
    break;
  }
}


status spell_capture(object caster,
                     object target,
                     object target_ob,
                     object previous,
                     int dmg) {
  int globe_level;
  string tmp;

  globe_level = 10 + random(30);
  tmp = colour[random(sizeof(colour)-1)];

  if(effect != "sphere") return 0;
  loaded_spell = caster->query_loaded_spell();

  if(PASSIVE) return 0;

  if(SPELL_LEVEL < globe_level) {
    tell_object(caster,
        "Your spell is absorbed by "+environment()->query_name()+
        "'s Prismatic Sphere!\n");
    tell_object(environment(),
        "Your Prismatic Sphere stops "+caster->query_name()+
        "'s spell!\n");

    caster->unload_spell();
    find_out_effect(target, caster, tmp);
    return 1;
  }
  else {
    tell_object(caster, "Your spell penetrates "+environment()->query_name()+
	"'s Prismatic Sphere!\n");
    tell_object(environment(), 
	caster->query_name()+"'s spell penetrates your Prismatic Sphere.\n");
  }
  return 0;
}

int query_extra_attack() {
  object ob;
  int dex, my_stat;

  if(!ob = environment()->query_attack()) return 0;
  
  my_stat = (int)environment()->query_evocation();
  if(!my_stat) my_stat = 30; /* spell level */

  dex = (int)ob->query_dexterity();

  if(random(dex) > random(my_stat)) {
    tell_object(environment(), ob->query_name()+" dodges the colours of "+
	"your Prismatic Sphere.\n");
    say(ob->query_name()+" dodges the colours of "+
	environment()->query_name()+"'s Prismatic Sphere.\n", ob);
    tell_object(ob, "You dodge the colours of the " +
	environment()->query_name()+"'s Prismatic Sphere.\n");
  }
  else {
    tell_object(environment(), ob->query_name()+" stumbles into your "+
	"Prismatic Sphere!\n");
    tell_object(ob, "You stumble into "+environment()->query_name()+
	"'s Prismatic Sphere!\n");
    say(ob->query_name()+" stumbles into "+environment()->query_name()+
	"'s Prismatic Sphere!\n", ob);
    find_out_effect(ob, environment(),     colour[random(sizeof(colour)-1)]);
  }
  return 0;
}

void time_out() {
  if(environment())
    tell_room(environment(), "The colours of the "+query_name()+
	" fade away...\n");
  ::time_out();
}


status drop(status quit) {
  ::time_out();
  return 1;
}
status get(status quit) { return 0; }
