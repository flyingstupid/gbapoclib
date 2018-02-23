/* brew a spell onto a potion */

#include <spell.h>
#include <mudlib.h>

#define MAX_SPELL_LEVEL   SPELL_LEVEL + 5  /* < caster level */
#define GET_LOADED_SPELL(XXX) \
  (mixed *)clone_object("obj/shadows/get_spell")->get_loaded_spell(XXX,0,0,1)

string *casting_msg(string targ, int size) {
  int i;
  string *msg, *data;  
  string *tmp;

  data = ({
      "You gather magical energies about you.\n",
      "You pull in magic from all around you.\n",
      "You feel the magic gathering all around you.\n",
      "You gaze carefully at the bottle.\n",
      "You start to brew a potion of "+ targ +".\n",
      "You direct the energies into the brew.\n",
      "You chant slowly.\n",
      "You stamp your legs.\n",
    });
  for(i=0; i<30; i++) data += ({ "", "", "", });
  for(msg = ({}),i = 0; i < size; i++) {
    msg += ({ data[random(sizeof(data))], });
  }
  return msg;
}   


status brew(string targ, mixed alt_type, string class) {
  int i;
  string file;

  if(!alt_type) alt_type = "level";
  if(!class) class = "mage";

  if(!targ) {
    notify_fail("brew <spell name>?\n");
    return 0;
  }
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
    "target",            this_player(),
    "name",              "Brew",
    "sphere",            alt_type, 
    "level",             15,
    "class",             class,
    "cast time",         100,
/* was 100 */
    "spell object",      file,
    "argument",          targ,
    "passive",
    "casting msg",       casting_msg(targ, 99),
/* was 99 */
    "casting msg room", ({
       "@@query_name:$this_player()$@@ starts brewing.\n",
       "@@query_name:$this_player()$@@ continues to brew.\n",
    }),
    "component",  "bottle#jug#bowl#basin#kettle#pot#keg#vase"
  }));
  return 1;
}



status cast_spell(object caster,object target,object prev,int dmg) {
  int i;
  string tmp_colour, *colours;
  mixed *loaded_spell;
  string spell_name;
  string spell_trigger, spell_info;
  string tmp1, tmp2;
  object item;

  colours = ({
	"red", "blue", "brown", "purple", "orange",
	"spotty", "dotty", "smelly", "green", 
	"cyan", "aqua", "bubbling", "black", "grey",
  });

  tmp_colour = colours[random(sizeof(colours))];


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
           +" is not powerful enough to brew the spell "+ SPELL_NAME +".\n");
      destruct(this_object());
      return 1;
    }
  }
  else {
    if(MAX_SPELL_LEVEL > (int)this_player()->query(SPELL_TYPE)) {
      write("You are not powerful enough to brew the potion with "+
             SPELL_NAME +".\n");
      destruct(this_object());
      return 1;
    }
  }
  item = clone_object(MAGIC_POTION);
  item -> set_adjectiv(({ tmp_colour, }));
  item -> set_name(tmp_colour+" potion");
  item -> set_short("A "+tmp_colour+" potion");
  item -> set_alt_name("bottle");
  item -> set_empty_container("bottle");
  item -> set_alias("potion");
  item -> set_long("A "+tmp_colour+" potion, brewed by "+
		  (string)this_player()->query_name()+".\n");
  call_other(caster,"adj_"+ SPELL_TYPE +"_points", (SPELL_COST*(-3))/2);
  if(!item->set_spell(spell_name)) {
    write("You can only brew 'non'-offensive spells.\n");
    destruct(item);
    destruct(this_object());
    return 1;
  }
  item->set_enchanted(1);
  move_object(item, caster);
  write("You brew a potion of "+ SPELL_NAME +".\n");
  say(caster->query_name()+" brews a potion with a");
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
    say("prayer.\n");
  else
    say("spell.\n");
  if(COMPONENT) {  /* destruct component list */
    for(i = 0; i < sizeof(COMPONENT); i++) {
      if(COMPONENT[i]) COMPONENT[i]->drop(1);
      if(COMPONENT[i]) destruct(COMPONENT[i]);
    }
  }
  this_player()->add_exp(SPELL_LEVEL * 500);
  destruct(this_object());
  return 1;
}



