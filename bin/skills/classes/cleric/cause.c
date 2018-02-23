/* cause */  

#define NAME      "@@query_name:$this_player()$@@"
#define TARG      "@@query_name:$this_object()$@@"
#define OBJECTIVE "@@query_objective:$this_object()$@@"

status cause(string spell_type, string class, mixed alt_type) {
  string file, spell_name;
  string immune;
  string targ;
  int i, spell_level, dam;

  if(!spell_type) {
    notify_fail("cause wounds, cause light wounds, cause minor wounds,\n"+
      "cause medium wounds, cause serious wounds, cause critical wounds,\n"+
      "cause major wounds, cause heavy wounds, cause blindness,\n"+
      "cause deafness, cause disease.\n");
    return 0;
  }
  sscanf(spell_type,"%s wounds %s", spell_type, targ);
  sscanf(spell_type,"%s wounds", spell_type);
  sscanf(spell_type,"%s %s", spell_type, targ);

  if(!alt_type) alt_type = "healing_sphere";
  if(!class) class = "cleric";

  immune = "darkness";
  switch(spell_type) {
    case "wounds":
      spell_name = "Cause Wounds";
      dam = 1 * (random(4)+1);
      spell_level = 1;
    break;

    case "light":
      spell_name = "Cause Light Wounds";
      dam = 5 * (random(4)+1);
      spell_level = 4;
    break;

    case "minor":
      spell_name = "Cause Minor Wounds";
      dam = 10 * (random(3)+1);
      spell_level = 7;
    break;

    case "medium":
      spell_name = "Cause Medium Wounds";
      dam = 15 * (random(3)+1);
      spell_level = 10;
    break;

    case "serious":
      spell_name = "Cause Serious Wounds";
      dam = 20 * (random(3)+1);
      spell_level = 13;
    break;

    case "critical":
      spell_name = "Cause Critical Wounds";
      dam = 25 * (random(2)+1);
      spell_level = 16;
    break;

    case "major":
      spell_name = "Cause Major Wounds";
      dam = 30 * (random(2)+1);
      spell_level = 19;
    break;

    case "heavy":
      spell_name = "Cause Heavy Wounds";
      dam = 35 * (random(2)+1);
      spell_level = 23;
    break;

    case "deafness":
      spell_name = "Cause Deafness";
      spell_level = 3;
      file = "obj/skills/deaf";
      dam = (objectp(alt_type))
          ? (int)alt_type->query_cast_level()
          : (int)call_other(this_player(), "query_"+ alt_type);
       immune = "disease";
    break;

    case "blindness":
      spell_name = "Cause Blindness";
      spell_level = 5;
      file = "obj/skills/blind";
      dam = (objectp(alt_type))
          ? (int)alt_type->query_cast_level()
          : (int)call_other(this_player(), "query_"+ alt_type);
       immune = "disease";
    break;

    case "disease":
      spell_name = "Cause Disease";
      spell_level = 7;
      file = "obj/skills/disease";
      dam = (objectp(alt_type))
          ? (int)alt_type->query_cast_level()
          : (int)call_other(this_player(), "query_"+ alt_type);
      immune = "disease";
    break;

    default:
      notify_fail("cause wounds, cause light wounds, cause minor wounds,\n"+
        "cause medium wounds, cause serious wounds, cause critical wounds,\n"+
        "cause major wounds, cause heavy wounds, cause blindness,\n"+
        "cause deafness, cause disease.\n");
      return 0;
    break;
  }
  
  this_player()->load_spell(({
  "target",            targ,
  "name",              spell_name,
  "sphere",            alt_type, 
  "cost",              spell_level,
  "level",             spell_level,
  "class",             class,
  "cast time",         1,
  "spell object",      file,
  "damage",            dam,
  "msg caster",        "You see wounds open up on "+ TARG +"!\n",
  "msg target",        "As "+ NAME +" touches you, wounds open up on your"+
                       " flesh.\n",
  "msg room",          "You see wounds open up on "+ TARG +" when "+ NAME 
                      +" touches "+ OBJECTIVE +".\n",
  "immune",           immune,
  }));
  return 1;
}

