//
//  obj/tool.c
//
// General file for all tools
//

#include <mudlib.h>
inherit BASE;

//tool variables
int damage = 0;
int maxDamage = 100;
int difficulty = 3;
int quality = 100;
string components;

//tool functions
void set_damage(int damage);
int get_damage();
void set_max_damage(int quality);
int get_max_damage();
void set_components(string comp);
string get_components();
void set_difficulty(int vdifficulty);
int get_difficulty();
void set_quality(int quality);
int get_quality();

void reset(status arg)
{
    if(arg) return;
    set_name("tool");
    set_alias("tool");
    set_short("tool");
    set_long("This is a tool.\n");
    set_extra_info("It looks like you may be able to use it for something.\n");
    
}

status get()
{
    return 1;
}


string query_object_type()
{
    return "tool";
}

void set_damage(int vdamage)
{
    damage = vdamage;
}

int get_damage()
{
    return damage;
}

void set_max_damage(int vquality)
{
    maxDamage = vquality;
}

int get_max_damage()
{
    return maxDamage;
}

string get_components()
{
    return components;
}

void set_components(string comp)
{
    components = comp;
}

void set_difficulty(int vdifficulty)
{
    difficulty = vdifficulty;
}

int get_difficulty()
{
    return difficulty;
}

void set_quality(int quality)
{
    quality = quality;
}

int get_quality()
{
    return quality;
}
