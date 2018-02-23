/*
 *	Pocket watch for checking MUD time.
 */

inherit "inherit/treasure";

reset(arg)
{
if (arg)
	return (0);
set_short("a pocket watch");
set_alias("watch");
set_weight(0);
}


drop()
{
destruct(this_object());
return 1;
}

query_domain_safe() { return 1; }

long()
{
string	long_descr, post_time;
int		hour, minute;

long_descr = "Australian eastern time is : " + ctime(time()) + "\n" +
             "The time in the Sands of Time is : " +
             environment(this_player()) -> query_time() +"\n";
write(long_descr);
return (long_descr);
}


query_auto_load()
{
return ("/objects/watch:");
}
