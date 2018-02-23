/** Minor Malison; by Orpheus Nov 1993  **/ 

/* update - dec 93 */

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status minor(string targ, mixed alt_type, string class) {
  int dam;

  if(!targ || !(targ == "malison" || sscanf(targ,"malison %s",targ))) {
    notify_fail("minor malison?\n");
    return 0;
  }
  if(targ == "malison") targ = 0;
  if(!alt_type) alt_type = "necromancy";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(4) + 1);
  if(dam > 30) dam = 30;  

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Minor Mailison",
  "sphere",            alt_type, 
  "cost",              7,
  "damage",            dam,
  "immune",            "evil",
  "level",             7,
  "class", class,
  "cast time",         1,
  "msg target",       "A wave of pure evil emenates from from "+ NAME + 
                      "'s palm striking you!",
  "msg room",         "A wave of pure evil emenates from from "+NAME + 
                      "'s palm striking "+ TARG +".\n",
  "msg caster",       "A wave of pure evil leaps from your palm striking "+
                      TARG +".\n",
/* other spell options...
  "area",
  "spell object",      0,
  "casting msg",       0,
  "casting msg room",  0,
  "passive",
  "component",        0,
 */
  }));
  return 1;
}

