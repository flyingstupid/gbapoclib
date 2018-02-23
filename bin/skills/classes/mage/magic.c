#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status magic(mixed targ, mixed alt_type, string class) {
  int dam;
  int how_many;

  if(!targ || !(targ == "missile" || sscanf(targ, "missile %s", targ) || targ == "mouth")) {
    notify_fail("magic missile? magic mouth?\n");
    return 0;
  }
  if(targ == "missile") targ = 0;
  if(targ == "mouth") {
    return (status)"/bin/skills/classes/mage/magicmouth"->magicmouth(0,alt_type,class);
  }

  if(!alt_type) alt_type = "evocation";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);
  how_many = (dam/3) + 1;
  dam *= (random(2) + 1);
  if(dam > 10) dam = 10;  

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Magic Missile",
  "sphere",            alt_type, 
  "cost",              1,
  "damage",            dam,
  "immune",            "light",
  "level",             1,
  "class", class,
  "cast time",         1,
   "msg target",       how_many +" magic missiles fly from "+ NAME 
                       +"'s hand,  striking you.\n",
   "msg room",         how_many +" magic missiles fly from "+ NAME
                       +"'s hand, striking "+TARG+".\n",
   "msg caster",       how_many +" magic missiles fly from your hand, "+
                       "striking "+ TARG +".\n",
  }));
  return 1;
}

