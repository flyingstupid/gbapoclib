/* Plant Door Spell */  

#define NAME "@@query_name:$this_player()$@@"

status plant(string targ, mixed alt_type, string class) {
  int dam, i;
  string file;

  switch(targ) {
    case "door":
      if(!alt_type) alt_type = "nature_sphere";
  if(!class) class = "cleric";
      if(!present("tree", environment(this_player()))) {  
        write("There is no tree to use as a plant door.\n");  
        return 1;  
      }  
      file = file_name(this_object());
      sscanf(file,"%s#%d",file,i);

      this_player()->load_spell(({
      "target",            this_player(),
      "name",              "Plant Door",
      "sphere",            alt_type, 
      "cost",              8,
      "level",             8,
      "class",             class,
      "spell object",      file,
      "cast time",         2,
      "casting msg",       "You prepare to step into the tree.\n",
      "casting msg room",   NAME +" walks towards the tree.\n",
      "component",         "branch",
      "passive",
     }));
    break;

    case "growth":
      if(environment(this_player())->query_inside()) {
        notify_fail("You can't make a plant grow inside.\n");
        return 0;
      }

      if(!alt_type) alt_type = "nature_sphere";
      if(present("tree", environment(this_player()))) {  
        write("There is already a tree here.\n");  
        return 1;  
      }  
      file = file_name(this_object());
      sscanf(file,"%s#%d",file,i);

      this_player()->load_spell(({
      "target",            environment(this_player()),
      "name",              "Plant Growth",
      "sphere",            alt_type, 
      "cost",              9,
      "level",             9,
      "class",             class,
      "spell object",      "obj/skills/tree",
      "cast time",         2,
      "casting msg",       "You carefully nurtue the seed.\n",
      "casting msg room",   NAME +" carefully nurtures a seed.\n",
      "component",         "seed#berry#goodberry",
      "passive",
     }));
    break;

    default:
      notify_fail("plant door, plant growth?\n");
      return 0;
    break;
  }
  return 1;
}


/***********************************************************************/
/* when cloned */

status filter_domain(string file, string domain) {
  string d_name;
  string tmp;

  if(file == "" || file[0] == '#' || sscanf(file,"%s %s",file,tmp)) {
    return 0;
  }
  sscanf(file,"d/%s/%s", d_name, file);
  return (d_name == domain) ? 1 : 0;
}


status cast_spell(object caster,object target,object prev,int dmg) {
  object branch;  
  int i;
  string txt, *trees, *domain_trees, dest, domain, room;  

  trees = ({});
  domain_trees = ({});

  if((branch = present("branch", target))) {  
    dest = (string)branch->query_tree_location();  
    if(dest == (string)target->query_current_room()) dest = 0;  
  }    

  
  txt = read_bytes("/open/spells/trees.sav",0,
                   file_size("/open/spells/trees.sav"));
  if(txt) {
    trees = explode(txt,"\n");  
    room = (string)target->query_current_room();
    sscanf(room,"d/%s/%s", domain, txt);
    domain_trees = filter(trees,"filter_domain", this_object(), domain);
  }
  if(!dest) {   
    if(sizeof(domain_trees) < 2) {   
      write("There are no other trees to goto via a plant door.\n");   
      return 1;   
    }    
    while((dest = domain_trees[random(sizeof(domain_trees))]) == room);
  }  
  write("You step into the tree.\n");  
  say((string)target->query_name()+" steps into the tree.\n");  
  move_object(target, dest);  
  command("look", target);  
  write("You step out of a tree.\n");  
  say((string)target->query_name()+" steps out of the tree.\n");  
  if(!present("tree", environment(target))) {   
    if((i = member_array(dest, trees)) == -1) return 1;   
    trees = trees[0..(i-1)] + trees[(i+1)..(sizeof(trees)-1)];
    if(rm("/open/spells/trees.sav")) {
      txt = implode(trees,"\n") + "\n";   
      write_file("/open/spells/trees.sav", txt);
    }   
  }   
  destruct(this_object());
  return 1;  
}  

