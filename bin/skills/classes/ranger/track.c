/* track someone ...basically, it is just a follow command 8) */
#define TRACK	(int)this_player()->query_tracking()

status find_where_the_creature_is(object ob);

status track(string str, string alt_type) {
  object obj;

  obj = present(str, environment(this_player()));
  if(!obj) {
    if(!obj=find_living(str)) {
      write("There is no "+capitalize(str)+" to track.\n");
      return 1;
    }
    find_where_the_creature_is(obj);
    return 1;
  }
  if(obj->query_followers(this_player())) {
    write("You are already following "+obj->short()+".\n");
    write("You stop following "+obj->short()+"\n");
    obj->remove_followers(this_player());
    return 1;
  }
  write("You start to follow "+obj->short()+".\n");
  obj->add_followers(this_player());
  return 1;
}

status find_where_the_creature_is(object ob) {
  object room;
  int resist;
  if(!ob) {
    write("You're unsure where the tracks lead.\n");
    return 1;
  }
  room = environment(ob);
  resist = (int)ob->query_resistance() + (int)ob->query_stealth();
  if((status)room->query_no_track()) {
    write("You're unsure where the tracks lead.\n");
    return 1;
  }

  if(random(resist) > random(TRACK)) {
    write("You're unsure where the tracks lead.\n");
    return 1;
  }
  write("You think "+ob->query_name()+"'s tracks lead to "+
  room->short()+"\n");
  return 1;
}
