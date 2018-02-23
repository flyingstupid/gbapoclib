/* Paladin's Steed
 * For when the player mounts his steed, the horse object is destructed
 * and the player's short/long/etc are shadowed to give the impression
 * he is riding it.           Angel, Nov 1994
 */

inherit "obj/shadows/shadow";

object who;

void shadow_horse(string str) {
  who = this_player();
  if(who->query_horse_object()) {
    destruct(this_object());
    return;
  }
  shadow_object(who);
}

status id(string str) {
  return str == "warhorse" || str == "horse" || who->id(str);
}

string short(status wiz) {
  return "A warhorse with "+(string)who->query_name()+" in the saddle";
}

string query_msgin() {
  return "gallops in on "+who->query_possessive()+" warhorse";
}

string query_msgout() {
  return "seizes the reins of "+who->query_possessive()+" warhorse "+
         "and gallops"; /* gallops 'south' */
}

void long(status wiz) {
  string *temp;
  write("A fine heavy warhorse of excelent quality and breeding.\n");
  if(sizeof(temp = (who->query_horse_info())))
    write(temp[1]);

  write(who->query_name()+" is riding the warhorse.\n");
  return who->long(wiz);
}

status pick_up(string item) {
  string *temp;
  if(sizeof(temp = (who->query_horse_info())))
    write("You lean down from "+temp[0]+".\n");
  else  
    write("You lean down from your horse.\n");

  say(who->query_name()+" leans down from "+who->query_possessive()+
     " horse.\n",who);

  return who->pick_up(item);
}


object query_horse_object() { return this_object(); }
