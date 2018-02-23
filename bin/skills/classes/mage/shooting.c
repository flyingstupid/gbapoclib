/* Shooting Star spell by Scott English (MOC) 27 Jan 1994 */
/* All parts of this code remain public domain at all times */

#define NAME "@@query_name:$this_player()$@@"
#define TARG "@@query_name:$this_object()$@@"
#define SEXS "@@query_possesive:$this_player()$@@"

status shooting(string targ, mixed alt_type, string class) {
   int dam;

   if(!targ || !(targ == "stars" || sscanf(targ,"stars %s", targ))) {
     notify_fail("shooting stars?\n");
     return 0;
   }
   if(targ == "stars") targ = 0;
   if (!alt_type) alt_type = "conjuration";
  if(!class) class = "mage";
   dam = (objectp(alt_type))
       ? (int)alt_type->query_cast_level()
       : (int)call_other(this_player(),"query_"+alt_type);
   dam *= (random(6)+1);
   if(dam > 72) dam=72;

   this_player()->load_spell(({
   "target", targ,
   "name",  "Shooting Stars",
   "sphere", alt_type,
   "cost", 13,
   "damage", dam,
   "level", 13,
  "class", class,
   "cast time", 2,
   "msg target", "Glowing rocks with flaming tails strike you from\n"+
                 "above!\n",
   "msg room", "Glowing rocks with flaming tails plummet to the ground\n"+
               "all around you!\n",
   "msg caster", "Your conjured shooting stars plummet to the ground\n"+
                 "all around you.\n",
   "casting msg", "You hold your rock aloft to the sky and begin\n"+
                  "chanting.\n",
                  "You crush the rock into smaller pieces and hurl it\n"+
                  "into the air.\n",
   "casting msg room", NAME+" takes a rock and holds it aloft.\n",
                       NAME+" crushes a rock into smaller pieces and\n"+
                       "hurls them into the air!\n",
   "component", "rock#stone#boulder",
   }));
   return 1;
}




