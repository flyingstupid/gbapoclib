#include <mudlib.h>
#include <levels.h>

#define TP this_player()

status look(string str, status extra) 
{
    object ob;
    object special;
    string item;
    string extra_str;
    status wiz;
    int wt;

    wiz = TP->secure(SEC1);
    if(TP->query_real_light() < 1) 
    {
        tell_object(TP, "It's too dark.\n");
        return 1;
    }

    if(!str) 
    {
        ob = environment(TP);
    }
    else 
    {
        sscanf(str, "at %s", str); 
        sscanf(str, "in %s", str);
        
        if(environment(TP)->look_at(str)) 
        {
            return 1;
        }
        else if((ob = present(str, TP)) && ob->look_at("") )
        {
            return 1;
        }

        sscanf(str, "%s on %s", item, str);
        sscanf(str, "%s in %s", item, str);
        str = lower_case(str);
        
        if(!(ob = present(str, TP))) 
        {
            if(!(ob=present(str,environment(TP)))) 
            {
                tell_object(TP, "There is no " + str + " here.\n");
                return 1;
            }
        }

        if(item) 
        {
            if(!ob->look_at(item))
                tell_object(TP, "There is no "+ item +".\n");

            return 1;
        }
    }

    if(extra)
    {
        ob->extra_info(wiz);
    }
    else
    {
        ob->long(wiz);
    }

    if (living(ob)) 
    {
        special = first_inventory(ob);
        
        while(special) 
        {
            extra_str = (string)special->extra_look();
            if (extra_str)
            {
                tell_object(TP, extra_str + ".\n");
            }
            special = next_inventory(special);
        }
    }
    if(ob == environment() || living(ob) || ob->can_put_and_get()) 
    {
        if(!living(ob) && !extra) 
        {
            wt = (int)ob->query_weight();
            if(wt >= 5)
            {
                tell_object(TP, "It looks very heavy.\n");
            }
            else if (wt >= 3)
            {
                tell_object(TP, "It looks heavy.\n");
            }
        }
        TP->show_inventory(ob);
    }
    else if(!living(ob) && ob->can_put_and_get()) 
    {
        wt = (int)ob->query_weight();
        if(wt >= 5)
        {
            tell_object(TP, "It looks very heavy.\n");
        }
        else if (wt >= 3)
        {
            tell_object(TP, "It looks heavy.\n");
        }
    }

    return 1;
}
