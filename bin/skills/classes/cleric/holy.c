/* holy strike, holy word */
/* Holy Arrow, by Octavian, Jan 1999 */

#define NAME "@@query_name:$this_player()$@@"
#define TARG "@@query_name:$this_object()$@@"

status holy(string spell_type, mixed alt_type, string class) {
  string file;
  string targ;
  int i, cl;


  if(!spell_type) {
    notify_fail("holy arrow, holy strike, holy word?\n");
    return 0;
  }
  sscanf(spell_type,"%s %s", spell_type, targ);
  switch(spell_type) {
    case "strike":
      if(!alt_type) alt_type = "combat_sphere";
  if(!class) class = "cleric";
      cl = (objectp(alt_type))
         ? (int)alt_type->query_cast_level()
         : (int)this_player()->query(alt_type);
      cl *= (random(4)+1);
      if(cl > 35) cl = 35;

      file = file_name(this_object());
      sscanf(file,"%s#%d",file,i);
  
      this_player()->load_spell(({
      "target",            targ,
      "name",              "Holy Strike",
      "sphere",            alt_type, 
      "cost",              8,
      "level",             8,
      "class",             class,
      "cast time",         1,
      "damage",            cl,
      "msg target",        "You feel something strike at your inner self!\n",
      "msg room",          TARG +" turns a pale colour.\n"+
                           TARG +" staggers.\n",
      "msg caster",        TARG +" turns a pale colour.\n"+
                           TARG +" staggers.\n",

      }));
    break;

    case "word":
      if(!alt_type) alt_type = "combat_sphere";
      cl = (objectp(alt_type))
         ? (int)alt_type->query_cast_level()
         : (int)this_player()->query(alt_type);
      cl *= (random(11)+1);
      if(cl > 110) cl = 110;

      file = file_name(this_object());
      sscanf(file,"%s#%d",file,i);
  
      this_player()->load_spell(({
      "target",            targ,
      "name",              "Holy Word",
      "sphere",            alt_type, 
      "cost",              30,
      "level",             30,
      "class",             class,
      "cast time",         1,
      "damage",            cl,
      "msg target",        "You feel something strike at your inner self!\n",
      "msg room",          TARG +" turns a pale colour.\n"+
                           TARG +" staggers.\n",
      "msg caster",        TARG +" turns a pale colour.\n"+
                           TARG +" staggers.\n",
      }));
    break;

     case "arrow":
       if(!alt_type) alt_type = "combat_sphere";
       cl = (objectp(alt_type))
           ? (int)alt_type->query_cast_level()
           : (int)call_other(this_player(),"query_"+alt_type);
       cl *= (random(4)+1);
       if(cl > 40) cl = 40;
       cl *= (random(4) + 1);
       this_player()->load_spell(({
       "target",     targ,
       "name",       "Holy Arrow",
       "sphere",     alt_type,
       "cost",       5,
        "damage", cl,
       "level",      5,
       "class", class,
       "cast time",  1,
       "msg caster", "A blinding light sprays from your hands striking "+ TARG 
                     +".\n",
       "msg target", "A blinding light sprays from "+ NAME + 
                     "'s hands striking you!\n",
       "msg room",   "A blinding light sprays from "+ NAME + 
                     "'s hands striking "+ TARG +".\n",
       }));
     break;

    default:
      notify_fail("holy arrow, holy strike, holy word?\n");
      return 0;
    break;
  }
  return 1;
}



