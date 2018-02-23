/* Comet spell by Scott English (MOC) 28 Jan 1994 */
/* All parts of this code remain public domain at all times */

#define NAME "@@query_name:$this_player()$@@"
#define TARG "@@query_name:$this_object()$@@"
#define SEXS "@@query_possesive:$this_player()$@@"

status comet(mixed targ, mixed alt_type, string class) {
   int dam;

   if (!alt_type) alt_type = "conjuration";
  if(!class) class = "mage";
   dam = random(31)+6;

   this_player()->load_spell(({
   "target", targ,
   "name",  "Comet",
   "sphere", alt_type,
   "cost", 8,
   "immune", "fire",
   "damage", dam,
   "level", 8,
  "class", class,
   "cast time", 1,
   "msg target", "A small fiery comet strikes you with great force from\n"+
                 "above, knocking you severely!!\n",
   "msg room", "A small fiery comet strikes "+TARG+" from above!!\n",
   "msg caster", "You bring down a comet hard on "+TARG+".\n",
   }));
   return 1;
}




