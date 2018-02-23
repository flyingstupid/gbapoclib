/* Magic Mouth */
#include <mudlib.h>
string message, spellCaster;
object caster;

status magicmouth(string targ, mixed alt_type, string class) {
  int level, i;
  string file;
  string spell_name;
  int spell_level;

  if(!alt_type) alt_type = "conjuration";
  if(!class) class = "mage";

  level = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()
      : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());

  this_player()->load_spell(({
  	"argument",          targ,
        "name",              "Magic Mouth",
  	"sphere",            alt_type,
  	"cost",              10,
  	"damage",            level,
  	"level",             10,
  	"class", 	     class,
  	"cast time",         1,
  	"spell object",      file,
   "msg room",         "A shimmering mouth begins to appear before you.\n",
   "msg caster",       "A shimmering shape beging to appear . . .\n",
  	"passive",
  }));
  return 1;
}


void set_message(string str) { message = str; }

status cast_spell(object who,object target,object prev,int dmg) {
  object editor;

  spellCaster = (string)who->query_name();
  caster = who;
  write("What is the message for the 'magic mouth'?\n");

  editor = clone_object(EDITOR);
  move_object(editor, this_player());
  editor -> edit("set_message", message);
  move_object(this_object(), environment(caster));
  return 1;
}

void long(status wiz) {
  write("This is a strange shimmering mouth. You can \n"+
        "almost see straight though it as if it were \n"+
        "but some mere illusion or ghostly figure.   \n");
  if(wiz) {
    write("This seems to be the handy work of the wizard "+
    capitalize(spellCaster)+".\n");
  }
}


void extra_long() {
  write("There is a large shimmering mouth in "+
  lower_case(environment()->short())+".\n");
}

void init() {
  if(!environment()) return;
  if(environment() == caster) return;
  call_out("giveMessage", 2);
}

void giveMessage() {
  if(!message) return;
  tell_room(environment(), "A shimmering mouth says: \n"+ message +"\n");
}

void time_out() {
  if(environment())
    tell_room(environment(),"The magic mouth disappears....\n");
  destruct(this_object());
}

void clean_up()     { time_out(); }
void dispel_magic() { time_out(); }


status id(string str) {
  return str == "spell"
      || str == "mouth"
      || str == "magic mouth";
}







