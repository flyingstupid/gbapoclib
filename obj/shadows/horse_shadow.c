/* Horse Shadow, for the HEAVEN7 mudlib
 * This is a fully configurable Shadow-Object for use with the         
 * RIDEABLE-object. You are able to configure the different messages  
 * or simply use the default ones. Its up to you.
 *
 * Started work 15.04.1997    Kerridis
 */

inherit "obj/shadows/shadow";

#define NAME  (string)who->query_name()


object who;

string ride_msgin;
string ride_msgout;
string ride_id;
string ride_short;
string ride_long;

void set_ride_id (string s) {
   ride_id = s;
}

string query_ride_id () {
string rid;
       return rid = (ride_id) ? ride_id : "horse";
}

void set_ride_short (string s) {
   ride_short = s;
}

string query_ride_short (string s) {
string shrt;
   return  shrt = (ride_short) ? ride_short : "A horse with "+NAME+" on its back";
}

void set_ride_long (string s) {
   ride_long = s;
}

string query_ride_long () {
string lng;
   return lng = (ride_long) ? ride_long : "A fine beautiful and strong horse.\n"+
   NAME+" is currentlyriding it.\n";
}

void set_ride_msgin (string s) {
   ride_msgin = s;
}

string query_ride_msgin () {
string min;
   return min = (ride_msgin) ? ride_msgin : "gallops in";
}

void set_ride_msgout (string s) {
   ride_msgout = s;
}

string query_ride_msgout () {
string mout;
   return mout = (ride_msgout) ? ride_msgout : "gallops out to the";
}   



void shadow_horse(string str) {
  who = this_player();
  if(who->query_horse_object()) {
    destruct(this_object());
    return;
  }
  shadow_object(who);
}

status id(string str) {
  return str == this_object()->query_ride_id() || who->id(str);
}

string short(status wiz) {
  return this_object()->query_ride_short();
}

string query_msgin() {
  return this_object()->query_ride_msgin();
}

string query_msgout() {
  return this_object()->query_ride_msgout();
}

void long(status wiz) {
  write((string)this_object()->query_ride_long());
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
