/* Acid Rain spell by Scott English (MOC) 27 Jan 1994 */
/* All parts of this code remain public domain at all times */
/* + acid arrow */

#define NAME "@@query_name:$this_player()$@@"
#define TARG "@@query_name:$this_object()$@@"

status acid(string spell_type, mixed alt_type, string class) {
   int dam;
   string targ;
   
    if(!class) class = "mage";
   if(!spell_type) { 
     notify_fail("acid rain, acid arrow?\n");
     return 0;
   }
   sscanf(spell_type,"%s %s",spell_type,targ);
   switch(spell_type) {
     case "rain":
       if(!alt_type) alt_type = "conjuration";
       dam = (objectp(alt_type))
           ? (int)alt_type->query_cast_level()
           : (int)call_other(this_player(),"query_"+alt_type);
       dam = dam * (random(4) + 1);
       if(dam > 40) dam = 40;
       this_player()->load_spell(({
       "target",    targ,
       "name",      "Acid Rain",
       "sphere",    alt_type,
       "immune",    "acid",
       "cost",      13,
	"damage", dam,
       "level",     13,
  "class", class,
       "cast time", 1,
       "area",
       "msg target", "Violet hissing rain starts splashing all over you,\n"+
                     "causing your skin to burn!\n",
       }));
     break;

     case "arrow":
       if(!alt_type) alt_type = "evocation";
       dam = (objectp(alt_type))
           ? (int)alt_type->query_cast_level()
           : (int)call_other(this_player(),"query_"+alt_type);
       dam *= (random(4)+1);
       if(dam > 40) dam = 40;
       dam *= (random(4) + 1);
       this_player()->load_spell(({
       "target",     targ,
       "name",       "Acid Arrow",
       "sphere",     alt_type,
       "immune",     "acid",
       "cost",       5,
	"damage", dam,
       "level",      5,
       "class", class,
       "cast time",  1,
       "msg caster", "A bolt of acid sprays from your hands striking "+ TARG 
                     +".\n",
       "msg target", "A bolt of acid sprays from "+ NAME + 
                     "'s hands striking you!\n",
       "msg room",   "A bolt of acid sprays from "+ NAME + 
                     "'s hands striking "+ TARG +".\n",
       }));
     break;

     default:
       notify_fail("acid rain, acid arrow?\n");
       return 0;
     break;
   }
   return 1;
}




