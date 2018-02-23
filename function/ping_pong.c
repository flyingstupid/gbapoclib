static ping(s)
{
object ob;
int		privacy_room;
	
if (spell_points < 3)
	{
	write("You are low on power.\n");
	return 1;
	}
if (!s) 
	{
	write("Ping whom?\n");
	return 1;
	}
if (level < LEVEL_WIZARD) 
	spell_points -= 3;
it = lower_case(s);
ob = find_living(it);
if (!ob)
	{
	write("No player with that name.\n");
	return 1;
	}
if (!catch(privacy_room = environment(ob)->query_prop(PPRIVATE)))
	if (privacy_room)
		{
		write("No player with that name.\n");
		ob->catch_ping();
		return (1);
		}
if (!(ob->catch_ping())) 
	{
	write("Can't ping "+s+".\n");
	return 1;
	}
write("You ping "+capitalize(s)+".\n");
return (1);
}


catch_ping()
{
string n, pinger;

pinger = this_player();
previous_object()->set_pinger(pinger);
if (!pinger)
	return 0;
n = pinger->query_real_name();
if (!n)
	return pinger=0;
tell_object(this_object(), capitalize(n)+" pings you." + sprintf("%c", 7) + "\n");
return 1;
}


static pong()
{
string n, pinger;
	
if (pinger = previous_object()->query_pinger())
	n = pinger->query_real_name();
if (!(pinger && n))
	{
	pinger = 0;
	write("No one has pinged you.\n");
	return 1;
	}
tell_object(pinger, capitalize(name) + " pongs back.\n");
pinger = 0;
write("You pong back to " + capitalize(n) + ".\n");
return (1);
}

