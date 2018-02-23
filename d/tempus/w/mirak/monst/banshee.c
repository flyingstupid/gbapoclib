#include <mudlib.h>
inherit UNDEAD;
void reset(status arg) {

    ::reset(arg);
    if(arg) return;

    set_name("Banshee");
    set_alias("groaning spirit");
    set_alt_name("spirit");
    set_gender(2);
    set_race("undead");
    set_al(-2000);
    set_short("A groaning spirit");
    set_long(
      "The banshee is the spirit of an evil female elf.\n"+
      "It inhabits things that are desolate and forgotten,\n"+
      "things better left alone.  The wail of the Banshee\n"+
      "is a deadly thing.  It is a nearly transparent figure,\n"+
      "sometmes mistaken for a spectre; until heard.\n");
    set_level(15);
    set_chill_chance(100);
    set_chill_dam(random(8));
    set_dead_ob(this_object());
}

void monster_died() {
    object corpse;
    say("The Banshee emits a final wail and fades away to ethers!\n");
    corpse = present("corpse");
    if (corpse)  destruct(corpse);
}
