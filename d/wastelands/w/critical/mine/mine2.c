#include <mudlib.h>
inherit ROOM;
 

     int minestability;
    int miningmax;
 int mine_find();
 int mine();
 int do_mine();
 
void reset(status arg) {
    
    if(arg) return;

    set_weather(2, 1, 0);
    set_short("Within the mine");
    set_long(
      "Rough stone carved smooth from digging into the earth rests at"+
      "reachable levels. In front of you is a mineshaft that leads downword"+ "into the mine itself. From here you can enter the mine.");
    set_exits(({"d/wastelands/w/critical/mine/mine1.c","out",}));
}

void init() {
  ::init();

    add_action("mine", "mine");
    miningmax=random(10)+15;
}

int mine()
{
    //Short cutting the pick axe -Critical
      write("You begin to pick away at the walls\n");
      call_out("do_mine",20);
      return 1;
    /*
    if(present("pickaxe",this_object()))
    {
        write("You begin to pick away at the walls\n");
        call_out("do_mine",20);
        return 1;
    }
    else
    {
        write("You need a pickaxe to mine\n");
        return 1;
    }
    */
}

int do_mine()
{
     
     minestability=minestability+1;
    if(minestability > miningmax)
    {
        write("The mine begins to crumble and crack!\n");
        say("The mine begins to crumble and crack!\n");
        //Put in damage code
        minestability=0;
    }
    
    
    write("You continue to chip away at the walls...\n");
    say(this_object()->query_name() + " continues to chip at the walls../n");
    mine_find();

}


int mine_find ()
{
    object find;
    int num=0;
    
    num = random(100)+1;
    write("The mining roll was:"+num+"\n");
    // When we can modify the roll by the skill!
    num = num + (this_player()->query_mining()/2);
    write("After the skill adjustment:"+num+"\n");
    if( num <= 40)
    {
        write("You find nothing ...\n");
        say("Nothing comes of their efforts.\n");
        return 1;
    }
    if( num > 41 && num < 75 )
    {
        this_object()->add_exp(50);
        write("You've hit coal!\n");
        find=clone_object("/inherit/materials.c");
        find->set_name("coal");
        find->set_alias("coal");
        find->set_short("a lump of coal");
        find->set_long("This is a lump of coal. You could craft some things out of it!\n");
        move_object(find,this_player());
        return 1;
    }
    if( num > 75 && num < 90)
    {
        this_object()->add_exp(75);
        write("You've hit iron!\n");
        find=clone_object("/inherit/materials.c");
        find->set_name("iron");
        find->set_alias("iron");
        find->set_short("a nugget of iron");
        find->set_long("This is a nugget of iron. You could craft some things out of it!\n");
        move_object(find,this_player());;
        return 1;
    }
    if( num > 90 )
    {
        this_object()->add_exp(100);
        write("You've hit crystal!\n");
        find=clone_object("/inherit/materials.c");
        find->set_name("crystal");
        find->set_alias("crystal");
        find->set_short("crystal");
        find->set_long("A crystal from a mine, you could craft some things out of it!\n");
        move_object(find,this_player());
        return 1;
    }
    
}