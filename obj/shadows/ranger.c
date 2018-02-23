/**********************************************************************/
/* RANGER's AURA. Angel, Aug '96. v1.0
 */



/*********************************************************************/
/* defines */



/*********************************************************************/
/* functions */

inherit "obj/shadows/shadow";
static object ranger;

void ranger_aura(object who) {  /* called when cloned to ranger */
  ranger = who;
  shadow_object(who);
}


/* can only have items on them, no having hidy saving accounts */
int add_savings(int i) {
  tell_object(ranger, "Your roaming nature prevents you from setting up "+
  "savings in one town.\n");
  return 0;
}

int set_savings(int i) {
  return add_savings(i);
}

int query_savings() { return 0; }
/* they have no savings */


/* Bonuses to saving throws */

int add_alignment(int amount) {
  object guild_object;
  guild_object = present("guild_object", ranger);
  if(guild_object) guild_object->process_alignment(amount);
  return (int)ranger->add_alignment(amount);
}

object query_ranger_aura_object() { return this_object(); }
