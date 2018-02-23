#include <mudlib.h>
inherit TREASURE;

#define TREES "/open/spells/trees.sav"

string query_tree_location();

int counter, growing, number_branches;
status fully_grown;
string tree, tree_location;

void reset(status arg) {
  number_branches = 5;
  if(arg) return;
  set_id("tree");
  set_name("tree");
  set_short("A small Seed");
  set_long("Maybe the seed will grow if you water it.\n");
}


status id(string str) {
  if(!fully_grown) 
    return str == "seed"
        || str == "small seed"
        || str == tree+" seed";
  else
    return str == tree+" tree"
        || str == "tree"
        || ::id(str);
}


status look_at(string str) {
  if(str == tree) {
    write("Maybe you could pick the "+ tree +".\n");
    return 1;
  }
  return 0;
}


void long(status wiz) {
  ::long(wiz);
  if(tree && !number_branches) 
    write("All the branches closest to you appear to have beeb broken off.\n");
}

void load_tree_file() {
  string *trees, txt;
  string file;

  txt = read_file(TREES);
  trees = ({});
  file = file_name(environment());
  if(txt) {
    trees = explode(txt, "\n");
    if(member_array(file, trees) != -1) return;
    trees = filter(trees,"filter_tree_file", this_object());
  }
  trees += ({ file, });
  rm(TREES);
  write_file(TREES,
		"#This file stores trees from /obj/skills/tree\n"+
                   "#made by 'plant growth' spell and used by 'plant door'\n");
  write_file(TREES, implode(trees,"\n") +"\n");
}

status filter_tree_file(string file) {
  int tmp;

  if(!file || file == "" || file[0] == '#' || sscanf(file,"%s %s",file,tmp)) {
    return 0;
  }
  return 1;
}

void init() {
  if(environment() != environment(this_player())) return;
  if(tree) set_smell("It smells like "+tree+"s\n");
  add_action("pick","pick");
  add_action("water","water");
  add_action("take","take");
  add_action("take","get");
}


status take(string str) {
  string loc;
  object branch; 
  int wt;
  string tmp1, tmp2;

  if(!tree) return 0;
  this_player()->recalc_carry();
  if(sscanf(str, "%sbranch%s", tmp1, tmp2)) {
    if((branch = present("branch", environment(this_player())))){
      wt = (int)branch->query_weight();
      if(!this_player()->add_weight(wt)) {
        write("The branch is too heavy for you.\n");
        return 1;
      }
      move_object(branch, this_player());
      tell_object(this_player(), "You take a branch off the ground.\n");
      say(this_player()->query_name()+" takes a branch off the ground.\n");
      return 1;
    } 
    if(!number_branches) {
      write("There are no branches within reach!\n");
      return 1;
  }

    branch = clone_object("obj/skills/branch");
    wt = (int)branch->query_weight();
    if(!this_player()->add_weight(wt)) {
      write("The branch is too heavy for you.\n");
      destruct(branch);
      return 1;
    }
    branch->set_short("A "+capitalize(tree)+" tree branch");
    loc = query_tree_location();
    if(!loc) loc = file_name(environment(this_player()));
    branch->set_tree_location(loc);
    move_object(branch, this_player());
    write("You get a branch from the "+ capitalize(tree) +" tree.\n");
    say(this_player()->query_name() +" takes a branch from the "+
    capitalize(tree) +".\n");
    number_branches --;
    return 1;
  }
  return (fully_grown) ? 0 : 1;
}

void   set_tree_location(string str) {  tree_location = str; }
void   set_tree_type(string str)     { tree = str;           }
string query_tree_location()         {  return tree_location; } 
 
 
string tree(){
  string *fr; 
 
  fr = ({ "cherry", "apple", "peach", "mulberry", "apricot", }); 
  return tree = fr[random(sizeof(fr))];
}
 
 
grow(string fruit){
  growing = 1;
  counter += 1;
    if(tree) fruit = tree;
    if(fruit && fruit != "goodberry") {
      fruit = capitalize(fruit);
      tree  = lower_case(fruit);
    }
    else{
      fruit = capitalize(tree());
    }
  if(counter < 5)
    set_short("A Tree Seedling");
  else if(counter < 10) 
    set_short("A Small Tree");
  else if(counter < 15)
    set_short("A Tree");
  else{
    set_short("A Large "+fruit+" Tree");
    set_long(
     "This is a large "+fruit+" tree. You can see the occassional "+fruit+"\n"+
     "upon the "+fruit+" tree. It looks quite ripe and ready to pick. Near\n"+
     "the top of the tree you see a loose branch.\n");
    growing = 0;
    fully_grown = 1;
    load_tree_file();
    return 1;
  }
  tell_room( environment(this_object()),
   "The "+fruit+" Tree shoots up, growing towards the heavens.\n");
  call_out("grow", 5, fruit);
  return 1;
}
 

status water(){
  if(!present("water", this_player()) && !present("watercan", this_player())) {
    write("You need something to water it with.\n");
    return 1;
  }
  if(environment()->query_no_summon()
  || environment()->query_no_teleport()) {
    write("Something causes the tree to die and fade...\n");
    destruct(this_object());
    return 1;
  }

  write("You water the seed.\n");
  grow();
  return 1;
}

status pick(string str){
  object fruit;
  string tmp1, tmp2;

  if(growing){
    write("There is no fruit on the tree yet.\n");
    return 1;
  }
  if(!tree){
    write("It is only a seed.\n");
    return 1;
  }
  if(!str) { 
    notify_fail("Pick what?\n");
    return 0;
  }
  if(!sscanf(str, "%s"+tree+"%s", tmp1, tmp2)) {
    notify_fail("Pick <what>\n");
    return 0;
  }
  if(!this_player()->add_weight(1)){
    write("You cannot carry anymore.\n");
    return 1;
  }
  fruit = clone_object(FOOD);
  fruit -> set_name(tree);
  fruit -> set_alt_name("berry");
  fruit -> set_short(capitalize(tree));
  fruit -> set_long("The "+tree+" looks really delicious.\n");
  fruit -> set_weight(1);
  fruit -> set_strength(0);
  fruit -> set_eater_mess(
   "You bite down into the juicy "+tree+". It tastes a little bitter,\n"+
   "leaving a tingling sensation in your mouth.\n");
  fruit -> set_eating_mess(" bites into a scrumptious "+tree+".\n");
  move_object(fruit, this_player());
  write("You pick from the tree a delicious "+ tree +".\n");
  say(this_player()->query_name()+" picks a delicious "+tree+
     " from the tree.\n");
  return 1;
}

status drop() { return (fully_grown) ? 1 : 0; }
status get() {
  if(fully_grown) {
    write("The roots of the tree, hold it firmly to the ground.\n");
    return 0;
  }
  return 1;
}
 
/* plant growth spell socket */

#include <spell.h>

status cast_spell(object caster,object target,object prev,int level) {
  mixed *loaded_spell;
  object seed;
  string fruit;

  if(environment(caster)->query_no_summon()
  || environment(caster)->query_no_teleport()) {
    write("Something causes the tree to die and fade...\n");
    destruct(this_object());
    return 1;
  }

  loaded_spell = (mixed *)caster->query_loaded_spell();
  fruit = (string)COMPONENT[0]->query_name(); 
  write("You plant the seed in the ground, and start coaxing it to grow.\n");
  say((string)caster->query_name()+" plants a seed in the ground.\n");
  grow(fruit);
  set_tree_location(file_name(environment(caster)));
  return 1;
}

