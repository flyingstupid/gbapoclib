/* scribe a spell onto a scroll */

#include <spell.h>

#define MAX_SPELL_LEVEL   SPELL_LEVEL + 10  /* < caster level */
#define GET_LOADED_SPELL(XXX) \
  (mixed *)clone_object("obj/shadows/get_spell")->get_loaded_spell(XXX,0,0,1)


string *casting_msg(string targ, int size) {
  int i;
  string *msg, *data;  

  data = ({
      "You gather magical energies about you.\n",
      "You pull in magic from all around you.\n",
      "You feel the magic gathering all around you.\n",
      "You gaze carefully at the paper.\n",
      "You scribe "+ targ +".\n",
      "You direct the energies into the paper.\n",
      "You chant slowly.\n",
      "You wave your arms.\n",
      "You stamp you legs.\n",
  });
  for(msg = ({}),i = 0; i < size; i++) {
    msg += ({ data[random(sizeof(data))], });
  }
  return msg;
}   


status scribe(string targ, mixed alt_type, string class) {
  int i;
  string file;

  if(!alt_type) alt_type = "level";
  if(!class) class = "cleric";

  if(!targ) {
    notify_fail("scribe <spell name>?\n");
    return 0;
  }
  if(!(present("parchment",this_player()) || present("paper",this_player()))) {
    write("You have to scribe onto a piece of parchment.\n");
    return 1;
  } 
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
    "target",            this_player(),
    "name",              "Scribe",
    "sphere",            alt_type, 
    "level",             20,
    "cast time",         150,
    "spell object",      file,
    "argument",          targ,
    "component",         "parchment#paper",
    "class",             class,
    "passive",
    "casting msg",       casting_msg(targ, 149),
    "casting msg room", ({
       "@@query_name:$this_player()$@@ starts scribing.\n",
       "@@query_name:$this_player()$@@ continues to scribe.\n",
    }),
  }));
  return 1;
}



string make_spell_name(string str) {
  int i;
  string tmp;

  while(sscanf(str,"%s %s", str, tmp)) str += tmp;
  str += (string)this_player()->query_name(1);
  str = crypt(str,0);
  str = lower_case(str);
  for(i = 0; i < strlen(str); i++) {
    if(str[i] < 'a' || str[i] > 'z') {
      str = str[0..(i-1)] + str[(i+1)..(strlen(str)-1)];
      i -= 1;
    }
  }
  if(strlen(str) > 4) str = str[0..3];
  return str;
}



status cast_spell(object caster,object target,object prev,int dmg) {
  int i;
  mixed *loaded_spell;
  string spell_name;
  string spell_trigger, spell_info;
  string tmp1, tmp2;
  object item;

    /* get a loaded spell array for spell enchantment */

  spell_name = (string)caster->query_spell_argument();
  loaded_spell = GET_LOADED_SPELL(spell_name);
  if(!sizeof(loaded_spell)) {
    destruct(this_object());
    return 1;
  }

    /* check for max. spell level able to be enchanted by caster */

  if(objectp(SPELL_TYPE)) {
    if(MAX_SPELL_LEVEL > (int)SPELL_TYPE->query_cast_level()) {
      write("The "+ SPELL_TYPE->query_name() 
           +" is not powerful enough to scribe the spell "+ SPELL_NAME +".\n");
      destruct(this_object());
      return 1;
    }
  }
  else {
    if(MAX_SPELL_LEVEL > (int)this_player()->query(SPELL_TYPE)) {
      write("You are not powerful enough to scribe the parchment with "+
             SPELL_NAME +".\n");
      destruct(this_object());
      return 1;
    }
  }
  item = clone_object("objects/magic_scroll");
  call_other(caster,"adj_"+ SPELL_TYPE +"_points", (SPELL_COST*(-3))/2);
  spell_trigger = make_spell_name(spell_name);
  item->set_spells(({ spell_trigger, spell_name, }));
  spell_info = "@@query_classes_string:$this_object()$@@"+
               "@@query_level_string:$this_object()$@@"+
               "@@query_spell_triggers:$this_object()$@@";
  item->set_info(spell_info);
  item->set_cast_level(SPELL_LEVEL);
  item->set_class((string *)caster->query_classes());
  item->set_enchanted(1);
  move_object(item, caster);
  write("You scribe spell "+ SPELL_NAME +" on the parchment.\n"+
        "It is triggered by the command word '"+ spell_trigger +"'.\n");
  say(caster->query_name()+" scribes a");
  if(SPELL_LEVEL < 5)
    say(" small ");
  else if(SPELL_LEVEL < 10)
    say(" ");
  else if(SPELL_LEVEL < 15)
    say(" powerful ");
  else if(SPELL_LEVEL < 20)
    say(" very powerful ");
  else
    say("n extremely powerful ");
  if(sscanf(SPELL_TYPE,"%ssphere%s", tmp1, tmp2)) 
    say("prayer on a scroll.\n");
  else
    say("spell on a scroll.\n");
  if(COMPONENT) {  /* destruct component list */
    for(i = 0; i < sizeof(COMPONENT); i++) {
      if(COMPONENT[i]) COMPONENT[i]->drop(1);
      if(COMPONENT[i]) destruct(COMPONENT[i]);
    }
  }
  destruct(this_object());
  return 1;
}



