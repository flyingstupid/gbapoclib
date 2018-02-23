#include <mudlib.h>
inherit BASE;
 
#include <rnd_name.h>
 
#define BARD_USE_ITEM 25 /* compared to history skill */
#define GET_LOADED_SPELL(XX,YY,ZZ) \
  (mixed *)clone_object("obj/shadows/get_spell")->get_loaded_spell(XX,YY,ZZ,1)
 
#define BINS  bins
#define WAND_ACTIVATION_TIME  3   /* Time to cast any spell      */
#define WAND_USAGE_TIME       5   /* Time between casting spells */
 
string *spells, *class, casting_msg, * bins;
int charges, max_charges, cast_level;
 
#ifdef WAND_USAGE_TIME
int last_time;
#endif
 
/********************************************************************/
/* query */
 
/* These are necessary hooks to work as a wand in spell system */

string query_object_type() { return "Wand"; }

mapping query_specs() {
  return ([
"charges" 	: charges,
"max_charges" 	: max_charges,
"cast_level" 	: cast_level,
"spells" 	: spells, 
"class" 	: class, 
"bins" 		: bins, 
"casting_msg" 	: casting_msg, 
  ]);
}

 
int query_charges()   { return charges;                        }
int query_cast_level(){ return cast_level;                     }
 
 
 
int query_value() { return ((100 * cast_level) + charges); }
 
int query_max_charges(){ return max_charges;  }
 
string *query_spells() { return spells;                 }
string *query_class()  { return (class) ? class : ({}); }
string query_casting_msg() { return casting_msg;        }
 
/********************************************************************/
/* sets */
 
int set_charges(int i) {
  if(!max_charges) max_charges = i;
  return charges = i;
}
 
int set_max_charges(int i)     { return max_charges = i; }
int set_cast_level(int i)      { return cast_level = i;  }
 
string *set_spells(string *arr) { return spells = (arr) ? arr : ({}); }
string *set_class(string *arr)  { return class = (arr) ? arr : ({});  }
string *set_bins(string *arr)   { return bins = (arr) ? arr : ({});   }
string set_casting_msg(string s){ return casting_msg = s;             }
 
 
void add_spell(mixed arg) {
  int i;
 
  if(!pointerp(arg)) arg = ({ arg, });
  if(!spells) spells =({});  
  for(i = 0; i < sizeof(arg); i++) {
    if(member_array(arg[i], spells) == -1) {
      spells += ({ make_name(arg[i]), arg[i], });
    }
  }
}
 
/********************************************************************/
/* adj */
 
int adj_charges(int i) {  
  charges += i; 
  if(charges > max_charges) charges = max_charges;
  if(charges < 0) charges = 0;
  return charges;
}  
 
 
init() {
  int i, j;
  status bard_can_use;
 
  ::init();
  if(!spells) return;
  if(!class) class = ({ "all", });
  if(!bins) bins = ({ 
	"/bin/skills/classes/mage/", 
	"/bin/skills/classes/cleric/", });
  if(!casting_msg) {
    casting_msg = "The @@query_name:$this_object()$@@ begins to feel warm.\n";
  }

  if(member_array(this_player()->query_class("bard"), class) == -1) {
    if(random((int)this_player()->query_history()) > BARD_USE_ITEM)
      bard_can_use = 1;
  }

  for(j = 0; j < sizeof(class); j++) {
    if((member_array("all", class) != -1) ||
       bard_can_use                       ||
       this_player()->query_class(class[j])) {
      if (!sizeof(spells))
      {
        add_action ("load_spell","",1);
        break;
      }
 
      for(i = 0; i < sizeof(spells); i += 2) {
        add_action("load_spell", spells[i]);
      }
      break;
    }
  }
}
 
void activate_wand(string *spell) {
  if(!this_player()) return; /* player logged out */
  if(sizeof((mixed *)this_player()->query_loaded_spell())) { /* wait state */
    call_out("activate_wand", 2, spell);
    return;
  }
  call_other(spell[0], spell[1], spell[2], this_object()); /* invoke spell  */
  this_player()->cast_spell_at_target();                   /* force casting */
}
 
status load_spell(string str) {   /* start cast spell */
  string verb, spell, spell2;
  int i;
 
  verb = query_verb();
 
#ifdef WAND_USAGE_TIME
  if(last_time + WAND_USAGE_TIME + WAND_ACTIVATION_TIME > time()) {
    write("Nothing Happens.\n");
    return 1;
  }
#endif
 
  if(find_call_out("activate_wand") != -1) {
    write("Nothing Happens.\n");
    return 1;
  }
  
  if (sizeof(spells))
  {
    if((i = member_array(verb, spells)) == -1) return 0;
    spell = spells[i+1];
  
    if(sscanf(spell,"%s %s", spell, spell2) == 2) 
    {
      if(str) 
        str = spell2 +" "+ str;
      else
        str = spell2;
    }
  }
  else
  {
    spell = verb;
  }
 
  for(i = 0; i < sizeof(BINS); i++) {
    if(file_size(BINS[i] + spell +".c") > 0) {
      write(process_msg(casting_msg));
      say(this_player()->query_name() +"'s "+ query_name() 
         +" begins to glow...\n");
 
      /* This is Ugly..but it solves some notify fail problems */
      
      if(!sizeof(GET_LOADED_SPELL(spell,str,this_object()))) return 0;
 
#if (WAND_ACTIVATION_TIME > 0)
      call_out("activate_wand", WAND_ACTIVATION_TIME,
#else
      activate_wand(
#endif
               ({ BINS[i] + spell, spell, str, }));
 
#ifdef WAND_USAGE_TIME
      last_time = time();
#endif
      return 1;
    }
  }
  return 0;
}
 
 
status get() { return 1; }
 
void end_spell() {     /* this is called when the spell finishes */
  write("The "+ query_name() +" starts to cools down.\n");
}
 
/* for enchant an item spell info */
 
string query_charges_string() {
  if(spells && sizeof(spells)) {
    return "The "+ query_name() +" has "+ charges +" charges.\n";
  }
}
 
string query_classes_string() {
  if(class && sizeof(class)) {
    return "The "+ query_name() +" can only be used by "+
           implode(class, ", ") +".\n";
  }
}
 
string query_level_string() {
  if(cast_level) {
    return "The "+ query_name() +" casts spells at a skill level of "+
         cast_level +".\n";
  }
}
 
string query_spell_triggers() {
  int i;
  string str;
 
  if(spells) {
    if((string)this_object()->query_object_type() == "Potion")
      str = "You must drink the potion for it to work.\n";
    else
    for(i = 0; i < sizeof(spells); i += 2) {
      if(!str) str = "";
      str += "The word '"+ spells[i] +"' triggers the spell '"
          + spells[i+1] +"'.\n";
    }
  }
  return str;
}
 
string query_wand_info() {
  return "@@query_charges_string:$this_object()$@@"+
         "@@query_classes_string:$this_object()$@@"+
         "@@query_level_string:$this_object()$@@"+
         "@@query_spell_triggers:$this_object()$@@";
}

