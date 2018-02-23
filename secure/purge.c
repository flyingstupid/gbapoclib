void purge() {
  object obj;
  string *primary;
  string *skills;
  string *tmp_array;
  string temp;
  int i, j, k;
  
  primary = ({
	"strength", "intelligence", "wisdom", "dexterity", "charisma",
	"constitution", "combat", "level",
	"swim", "climb",
  });
  skills = ({
    "unarmed", "two_weapon", "multi_attack", "multi_opponent",
    "armouring", "weapon_smith",

	"healing_sphere", "divination_sphere", "combat_sphere",
	"nature_sphere",  "necromancy_sphere", "stellar_sphere",
	"protection_sphere", 

	"evocation", "divination", "necromancy", "alteration",
	"illusion", "charm", "conjuration",
	"abjuration",

	"stealth", "locks", "steal", "disguise", "appraisal", "backstab",
	"traps",
	"disguise",
  });
  obj = this_player();

  tmp_array = primary + skills;
  for(i=0; i<sizeof(tmp_array); i++) {
    if(call_other(obj, "query_"+tmp_array[i]) > 20)
      call_other(obj, "set_"+tmp_array[i], 20);
    k = (int)call_other(obj, "query_"+tmp_array[i]);
    if(k) {
    k *= 2;
    k /= 3;
    k += random(3);
    }
    call_other(obj, "set_"+tmp_array[i], k);
  }

  k = (int)obj->query_level();
  if(obj->query_class("fighter")) temp = "/room/city/arena";
  else if(obj->query_class("mage")) temp = "/players/drakken/tower/mguild";
  else if(obj->query_class("thief")) temp = "/room/city/theif/guild";
  else temp = "/room/city/cleric/hall4";
  obj->set_title(call_other(temp, "get_new_title", (k-1)));
  obj->set_exp(call_other(temp, "get_next_exp", (k-1)));
  write("You character has now been purged...\n");
}
