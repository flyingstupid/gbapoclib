/** Call Lightning. Serepion, Oct 1993 **/

/* update - dec 93 */

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status call(string targ, mixed alt_type, string class) {
  int dam;

  if(!targ || !(targ == "lightning" || sscanf(targ,"lightning %s",targ))) {
    notify_fail("call lightning?\n");
    return 0;
  }
  if(targ == "lightning") targ = 0;
  if(!alt_type) alt_type = "nature_sphere";
  if(!class) class = "cleric";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(9) + 1);
  if(dam > 90) dam = 90;  

  this_player()->load_spell(({
  "target",            targ,
  "class",             class,
  "name",              "Call Lightning",
  "sphere",            alt_type, 
  "cost",              8,
  "damage",            dam,
  "immune",            "lightning",
  "level",             8,
  "cast time",         5,
  "casting msg",  ({
    "Thunder thunders through the clouds above you...\n",
    "The ground trembles as you call to the Gods for lightning.\n",
    "A flash of lightning forks across the sky...a sign of things to come\n",
    "The heavens roar as the sky lights up...!!\n",
  }),
  "casting msg room", ({
    "Thunder crashes through the clouds above "+NAME+"\n",
    "The ground around you trembles as "+NAME+" prays earnestly.\n",
    "A flash of lightning forks across the sky...a sign of things to come.\n",
    "The heavens roar as the sky lights up...!!\n",
  }),
  "msg target",   "A huge bolt of lightning strikes you down!\n",
  "msg room",      TARG +" is struck by heavenly lightning!\n",
  "msg caster",    TARG +" is struck by heavenly lightning!\n",
  }));
  return 1;
}

