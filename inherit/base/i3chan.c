#include <imud3.h>
#define myself this_player()

string *intermud3_channels_blocked;

static add_intermud3_channels()
{
    string *x;
    int i;
    i = sizeof(x = m_indices(INTERMUD3 -> query_channels()) -
      query_actions(myself, 1));
    while (i--)
	add_action("intermud3_channel", x[i]);
}

static intermud3_channel(str)
{
    string verb, it;
    status emote;
    if (!str) return 0;
    verb = query_verb();
    if (!intermud3_channels_blocked) intermud3_channels_blocked = ({});
    if (str == "/off")
    {
	if (member_array(verb, intermud3_channels_blocked) == -1)
	    intermud3_channels_blocked += ({ verb });
	write(verb + " off.\n");
	return 1;
    }
    if (str == "/on")
    {
	intermud3_channels_blocked -= ({ verb });
	write(verb + " on.\n");
	return 1;
    }
    if (sscanf(str, "/who @%s", str))
    {
	it = INTERMUD3 -> get_mud_name(str);
	if (!it)
	    return write("Unknown mud: " + str + "\n"), 1;
	if (!INTERMUD3 -> query_mud_info(it)[11]["channel"])
	    return write(it + " does not support intermud channels.\n"), 1;
	INTERMUD3 -> send_channel_who_request(verb, it);
	write("Request transmitted.\n");
	return 1;
    }
    if (member_array(verb, intermud3_channels_blocked) != -1)
	return write("You have that channel blocked.\n"), 1;
    emote = sscanf(str, ":%s", str);
    if (emote)
	INTERMUD3 -> send_channel_emote(verb, "$N " + str);
    else
    {
	INTERMUD3 -> send_channel_message(verb, str);
    }
    return 1;
}

intermud3_channel_blocked(chan)
{
    return intermud3_channels_blocked &&
           member_array(chan, intermud3_channels_blocked) != -1;
}

static ucache_update()
{
    if (this_player()->query_security_level() >= 20)
	INTERMUD3 -> send_ucache_update(this_object());
}


