#include <mudlib.h>
inherit TREASURE;

static status filled;

status query_full() { return filled; }
status set_full(status full) { return filled = full; }

void reset(status arg)
{
    ::reset(arg);
    set_name("cup");
    set_alt_name("#miettecup#");
    set_short("special cup");
}

void long(status wiz)
{
    if(filled)
	write("This is a special cup.  It is filled with water.\n");
    else
	write("This is a special cup.  It is empty.\n");
}
