status unset(string str) {
 mapping envs;
 if(!str) {
 notify_fail("Unset what?\n");
 return 0;
 }
 if(this_player()->query_env_vars())
  envs = this_player()->query_env_vars();
 else {
  printf("No such variable '%s'.\n",str);
  return 1;
 }
  if(member(envs, str)) {
   this_player()->unset_env_var(str);
   return 1;
  }
  else {
   printf("No such variable '%s'.\n",str);
   return 1;
  }
}
