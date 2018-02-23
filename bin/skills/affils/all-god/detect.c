status detect(string targ, mixed alt_type) {
  int level, i;
  string file, objective, tmp1;
  object obj;

  if(!targ) {
    notify_fail("Detect what?\n");
    return 0;
  }

  if(!this_player()->query_class("cleric")) {
    notify_fail("Only a priest of the All-God may pray for spells.\n");
    return 0;
  }
  if(sscanf(targ, "alignment %s", targ)) {
   if(!alt_type) alt_type = "divination_sphere";
   level = (objectp(alt_type))
         ? (int)alt_type->query_cast_level()
         : (int)call_other(this_player(),"query_"+ alt_type);
   file = file_name(this_object());
   sscanf(file,"%s#%d",file,i);

   this_player()->load_spell(({
      "target",       targ,
      "name",         "Detect Alignment",
      "sphere",       alt_type,
      "passive",
      "cost",         0,
      "immune",       "divination",
      "damage",       level,
      "level",        0,
      "cast time",    1,
      "spell object", file,
      "passive",
    }));
    return 1;
  }

  return (status)"/bin/skills/classes/cleric/detect"->detect(targ, alt_type);
}


status cast_spell(object caster,object target,object prev,int level) {
  if(target->id("PLAYER")) {
    write("You sense that "+target->query_name()+" alignment is "+
	target->query_al_title()+".\n");
    destruct(this_object());
    return 1;
  }
  caster -> adj_divination_sphere_points(1); /* give em a point to do it */
  caster->unload_spell();

  (status)"/skills/cleric/detect" -> detect("evil "+target->query_name(1));
  destruct(this_object());
  return 1;
}



