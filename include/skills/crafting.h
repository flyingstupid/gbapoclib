/*


    Crafting skills!

    This will cover the skill and the skill xp gained by using the skills
    as well as the ability to check the skill level.
*/
#ifndef CRAFT_H
#define CRAFT_H

// Declare the skills
int clothing;
int clothingxp;

int armours;
int armoursxp;

int weapons;
int weaponsxp;

int tools;
int toolsxp;

// Get the skills
int query_clothing()    { return clothing;}
int query_clothingxp()    { return clothingxp;}

int query_armours()     { return armours; }
int query_armoursxp()     { return armoursxp; }

int query_weapons()     { return weapons; }
int query_weaponsxp()     { return weaponsxp; }

int query_tools()       { return tools;   }
int query_toolsxp()       { return toolsxp;   }


// Set the skills
int set_clothing(int i) { return clothing=i; }
int set_clothingxp(int i) { return clothingxp=i; }

int set_armours(int i)  { return armours=i;  }
int set_armoursxp(int i)  { return armoursxp=i;  }

int set_weapons(int i)  { return weapons=i;  }
int set_weaponsxp(int i)  { return weaponsxp=i;  }

int set_tools(int i)    { return tools=i;    }    
int set_toolsxp(int i)    { return toolsxp=i;    }  

void query_crafting_stats() {

string str;
  write("\n              -=[ Crafting Skills ]=-\n\n");
  str  = " Clothing: "+clothing+"                               ";
  str  = extract(str,0,25);
  str += " Armours: "+armours+"                                 ";
  str  = extract(str,0,50);
  str += " Weapons: "+ weapons +"                         ";
  str  = extract(str,0,75);
  write(str +"\n");
  str  = " Tools: "+tools+"            ";
  str  = extract(str,0,25);
  write(str +"\n");  

}

/* 
    The xp added is the complexity of what your making. If the xp is greather
    than 100x the skill level, then you gain skill and the XP is reduced to zero.
    
    Pass the complexity and then the skill as a string!
    -Critical
    
    
 

void do_craft_xp(int complexity, string skill)
{
    //Error Checking
    mixed slevel   = call_other(this_object(),"query_" + skill);
    mixed skillxp  = call_other(this_object(),"query_" + skill + "xp");
    mixed xpneeded = call_other(this_object(),"query_" + skill + "xp");
    string sname = skill;
    
    
    if(!sname)      {  return write("No skill passed failure!\n");       }
    if(!complexity) { return write("No complexity passed failure!\n");   }
    
        //Set the XP based on the skill
        call_other(this_object(), "set_" + sname +"xp", complexity );
    //See if skill is higher than x100 xp    
    if( skillxp > ( xpneeded * 100 ) )
    {
            call_other(this_object(), "set_" + sname, slevel+1);
            call_other(this_object(), "set_" + sname +"xp",0);
          return write("Your knowledge reaches a new plateu in " + sname+"!\n");
    }
    return write("You learn more about " + sname+"!\n");
}
*/
#endif