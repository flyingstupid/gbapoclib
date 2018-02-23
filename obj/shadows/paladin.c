/**********************************************************************/
/* PALADIN'S HOLY AURA.  Angel, August 1994.  v2.00  November, 1994   */



/*********************************************************************/
/* defines */

#define PALADIN_BONUS         2
#define EVIL_ALIGNMENT        -50
#define TITHE_AMOUNT          10


/*********************************************************************/
/* functions */

inherit "obj/shadows/shadow";
static object paladin;

void paladin_aura(object who) {  /* called when cloned to paladin */
  paladin = who;
  shadow_object(who);
}

int hit_player(int dmg) {
  if((int)this_player()->query_alignment() < EVIL_ALIGNMENT) 
    dmg -= PALADIN_BONUS;  /* an equivalent of +2 ac */
  return (int)paladin->hit_player(dmg);
}

int add_money(int money) {
  if(money > 0) {
    tell_object(paladin, "You set aside your tithe for the church.\n");
    money -= money/TITHE_AMOUNT;
  }
  return (int)paladin->add_money(money);
}

/* Bonuses to saving throws */
int query_save_bonus() {
  object guild_object;
  int i;
  guild_object = present("guild_object", paladin);
  if(guild_object) 
    i += ((int)guild_object->check_alignment() ? PALADIN_BONUS : 0);
  i += paladin->query_save_bonus();
  return i;
}

int add_alignment(int amount) {
  object guild_object;
  guild_object = present("guild_object", paladin);
  if(guild_object) guild_object->process_alignment(amount);
  return (int)paladin->add_alignment(amount);
}

object query_paladin_aura_object() { return this_object(); }
