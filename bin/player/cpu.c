
int uptime()
{
   string *files;
   int i, j, k, reset_time;
   files = explode(read_file("/secure/init_file"), "\n");
   reset_time = time();
   while (i < sizeof(files) && j++ < 10)
   {
      object ob;
      if (files[i][0] != '#' && (ob = find_object(files[i])) &&
         (k = program_time(ob)) < reset_time)
      {
         reset_time = k;
      }
     ++i; 
   }
   /* TODO: use query_date_as_string fn */
   reset_time = time() - reset_time;

   /* if (j = reset_time / 604800)
   {
      write(j == 1 ? "1 week " : j + "W");
      reset_time %= 604800;
   }
   if (j = reset_time / 86400)
   {
      write(j == 1 ? "1 day " : j + "D");
      reset_time %= 86400;
   }
   if (j = reset_time / 3600)
   {
      write(j == 1 ? "1 hour " : j + "H");
      reset_time %= 3600;
   }
   if (j = reset_time / 60)
   {
      write(j == 1 ? "1 minute " : j + "M");
      reset_time %= 60;
   }
   write(reset_time + "S\n"); */

   return reset_time;
}


int cpu (string str) {
  int *r;
 
  r = rusage();
  printf("%s, %4.2f%% CPU usage on %s.\n", query_load_average(),
    ((r[0] + r[1]) / (10.0 * (float)uptime())),
    "Linux");
  return 1;
}

