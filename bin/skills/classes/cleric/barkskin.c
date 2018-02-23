/* Barkskin */

inherit "obj/skills/sp_arm";

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */


status barkskin(mixed targ, mixed alt_type, string class) {
  int cl, i;
  string file;

  if(!alt_type) alt_type = "nature_sphere";
  if(!class) class = "cleric";
  cl = (objectp(alt_type))
     ? (int)alt_type->query_cast_level()
     : (int)this_player()->query(alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);


  this_player()->load_spell(({
  "target",            targ,
  "name",              "Barkskin",
  "sphere",            alt_type, 
  "cost",              7,
  "level",             7,
  "class",             class,
  "damage",            cl,
  "cast time",         4,
  "spell object",      file,
  "component",         "bark#branch#leaf#wood#timber",
  "passive",
 
  "casting msg",       ({
     "You draw on the power of nature.\n",
     "Shades of green swirl about you.\n",
     "Green leaves begin to sprout.....\n"
  }),

  "casting msg room",  ({
     NAME +" calls to nature.\n",
     "Shades of green swirl about "+ NAME +".\n",
     "Green leaves begin to sprout about "+ NAME +".\n"
  }),
 }));
  return 1;
}


/* call when this object is cloned to target */

status cast_spell(object caster,object target,object prev,int level) {
  object bark;

  if((bark = present("barkskin",target))) {
    tell_object(caster,"You extend the time of your barkskin...\n");
    bark->adj_time(level);
    destruct(this_object());
    return 1;
  }
  tell_object(environment(), "Your skin becomes as tough as bark.\n");
  say(environment()->query_name()+"'s skin becomes as tough as bark.\n");

  set_name("barkskin");
  set_listen("You hear the crackling of bark and leaves.\n");
  set_smell("You smell fresh pine in the air around you.\n");
  set_alt_extra_long("Your skin looks all crispy like bark.\n");
  set_extra_long((string)target->query_name()+"'s skin is all green and "+
     "brown and looks like bark.\n");
  set_info("The barkskin makes the target's skin tough and hard.\n"+
           "This barkskin has only @@query_approx_time:"+
            file_name(this_object())+"@@ left before it expires.\n");
  adj_time(level * 60);
  level = level/4;
  level += 1;
  if(level > 4) level = 4;
  set_ac_bonus(level);
  target->recalc_ac();
  return 1;
}


