/** Illusion **/

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */

string illusion_name;
string illusion_short;
int time;

status visual(string str, mixed alt_type, string class) {
  int level, i;
  string file;

  if(!str || sscanf(str,"illusion %s",str) != 1) {
    write("visual illusion <item>?\n");
    return 1;
  }
  if(!alt_type) alt_type = "illusion";
  if(!class) class = "mage";
  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level() 
        : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            str,
  "name",              "Visual Illusion",
  "sphere",            alt_type, 
  "cost",              15,
  "damage",            level,
  "immune",            "illusion",
  "level",             15,
  "class", class,
  "cast time",         2,
  "spell object",      file,
  "casting msg",      "Colours begin to swirl around you.\n",
  "casting msg room", "You see colours swirl about "+ NAME +".\n",
/* other spell options... 
  "msg target",       0,
  "msg room",         0,
  "msg caster",       0,
  "passive",
  "component",        0,
 */
  }));
  return 1;
}


/* call when this object is cloned to target */

void illusion3(string str) {
  object ob, env;

  env = environment();
  write("You weave the illusion about ");
  write((living(env) ? "" : "the ")+ (string)env->query_name() +".\n");
  ob = clone_object("obj/shadows/illusion");
  ob->illusion(env, illusion_name, illusion_short, str);
  ob->adj_time(time);
  destruct(this_object());
}

void illusion2(string str) {
  illusion_short = str;
  write("Illusion description is what you see when you 'look at'.\n");
  write("Illusion Description> ");
  input_to("illusion3");
}


void illusion1(string str) {
  illusion_name = str;
  write("Illusion short is what you see when you do an  'inventory'.\n");
  write("Illusion Short> ");
  input_to("illusion2");
}
  
status cast_spell(object caster, object target, object previous, int level) {
  object ob;

  if((ob = (object)target->query_illusion_object())) {
    write("Your illusion disrupts an existing illusion.\n");
    destruct(ob);
    destruct(this_object());
    return 1;
  }
  if(!living(target)                        /* an item */
  || ((int)caster->query_spell_dmg() == level  /* npc failed save */
  && target->query_npc())) {                   
    write("Illusion name is the name you give to 'get', or to"+
          " 'look at', etc.\n");
    write("Illusion Name> ");
    time = level * 60;
    input_to("illusion1");
  }
  else {
    write("Nothing Happens...\n");
    destruct(this_object());
  }
  return 1;
}


status id(string str) { 
  return str == "spell"
      || str == "illusion";
}

