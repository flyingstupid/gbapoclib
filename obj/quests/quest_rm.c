/* Quest Room, Ramses 1993. Revisions by Angel 1994
 * Original code by Lemat(-jj), 1992.
 */

#include <mudlib.h>
inherit ROOM;

#define ELDER        60
 
void reset(status arg) {
  string *quests_to_clone;
  int i;
  object ob;

  quests_to_clone = ({
    "cabin",
    "sols_toy",
    "lifestealer",
  });
  if(arg) return;

  for(i=0; i<sizeof(quests_to_clone); i++) {
    ob = clone_object("obj/quests/"+ quests_to_clone[i]);
    move_object(ob, this_object());
  }



  set_weather(2, 1, 0);
  set_short("The Quest Room");
  set_long(
     "-=[  The Quest Room  ]=-                                         \n"+
     "Inside this room are all the quest objects required for the game.\n"+
     "To find out how a quest works, please check 'man quests' and     \n"+
     "read everything inside there. Before you can have a quest object \n"+
     "placed in here, it must be checked by the head of the QC team.   \n"+
     "If a quest does not appear here, then simply 'update' the room.  \n");
  set_exits(({
     "/d/ooc/creator/lpc", "west",
     INNER,		 "inner",
     CHURCH,             "square",
     VOID,               "void",
  }));
}
 
string get_new_quest(object pl) {   
  object *obj;
  string *quests_done;
  int level, i;
  string *quests_can_do;

  quests_can_do = ({});
  quests_done = (string *)this_player()->query_done_quests();
  if(!pl) pl = this_player();
  level = (int)pl->query_level();
  obj = all_inventory(this_object());

  for(i=0; i<sizeof(obj); i++) {
    if(member_array(obj[i]->query_name(), quests_done) == -1)
      if(!obj[i]->query_test())
      if((level >= obj[i]->query_min_level()) && 
         (level <= obj[i]->query_max_level())) {
        if((string)obj[i]->query_object_type() == "Quest_object")
          quests_can_do += ({ obj[i]->query_name(), });
      }
  }
  if(!sizeof(quests_can_do)) return 0;
  i = random(sizeof(quests_can_do));
  return quests_can_do[i];
}

 
int finish_quest(string quest_name, object caller, object who) { 
  object quest;
  string tmp, caller_file, caller_room;
  int i;

  if(present(quest_name), this_object()) 
    quest = present(quest_name, this_object());
  if(!quest) {
    write("Error! Quest object missing!\n");
    return 0;
  }
  if(quest->query_test()) {
    write("Quest completed for quest phaze Alpha.\n");
    return 0;
  }
  /* must still be his current quest to finish it */
  if((string)who->query_curr_quest() != quest_name) return 0;

  /* so an Elder can force a complete a quest */
  if(caller->query_security_level() >= 60) {
    if(interactive(caller))
      return (int)quest->query_qpoints();
  }

  sscanf(file_name(caller), "%s", tmp);
  sscanf(file_name(caller), "%s#%d", tmp, i);
  if(tmp != (string)quest->query_req_caller()) {
    return 0;
  }
  if(file_name(environment(who)) != (string)quest->query_req_place()) return 0;

  i = (int)quest->query_qpoints();
  return i;
  return (int)quest->query_qpoints();
}


status get_quest_hint(string quest_name) {
  object quest;
  string tmp;

  if(!quest_name) return 0;
  quest = present(quest_name, this_object());
  if(!quest) return 0;

  tmp = (string)quest->query_hint();
  write(tmp +"\n");
  return 1;
}
