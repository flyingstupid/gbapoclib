
status set(string str) {
 string var, val;
 string *vars;
 mapping envs;
 int x;
 x = 0;
 var = 0;
 val = 0;
 if(!str) {
 printf("Environment variables.\n");
 if(this_player()->query_env_vars())
 envs = this_player()->query_env_vars();
 else {
  printf("No environment variables set.\n");
  return 1;
 }
 vars = m_indices(envs);
 if(sizeof(vars) == 0) {
  printf("No environment variables set.\n");
  return 1;
 }
 while(x < sizeof(vars)) {
  printf("%-=15s   %s\n",vars[x], envs[vars[x],0]);
  x += 1;
 }
 return 1;
 }
 if(sscanf(str, "%s %s", var, val) == 2) {
  this_player()->set_env_var(str);
  return 1;
 }
 if(this_player()->query_env_vars())
  envs = this_player()->query_env_vars();
 else {
  printf("No such variable '%s'.\n",str);
  return 1;
}
  if(member(envs, str)) {
   printf("%s is set to %s.\n",str, envs[str,0]);
   return 1;
  }
  else {
   printf("No such variable '%s'.\n",str);
   return 1;
  }
}
