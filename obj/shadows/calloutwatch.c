/* follower */

inherit "obj/shadows/shadow";

object who;
object callout_owner;
string callback;

// Constructor
void calloutwatch(object _who, object _callout_owner, string _callback) 
{
    who = _who;
    callout_owner = _callout_owner;
    callback = _callback;
    shadow_object(who);
}

status move_player(string dest, mixed opt, status safe) 
{
    status flag;

    flag = (status)who->move_player(dest,opt,safe);

    if( flag )
    {
        call_other( callout_owner, callback, who );
    }
    
    return flag;
}

object query_calloutwatch_object(object ob) 
{
    if( ob = callout_owner )
        return this_object();

    //TODO not sure if this will work
    return who->query_calloutwatch_object(ob);
}
object query_callout_owner() { return callout_owner; }

