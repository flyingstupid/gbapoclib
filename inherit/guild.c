/* configurable guild room */
/* allows creator to easily add a guild room to use standard skills */

#include <mudlib.h>
inherit ROOM;

#define LEVEL          (int)this_player()->query_level()
#define NAME           (string)this_player()->query_name()
#define TEXP           (int)this_player()->query_total_exp()
#define MAX_CLASSES	3
#define EXP            (int)this_player()->query_exp()
#define GUILD_STR      ((string)this_player()->query_guild_string())
#define COST_FOR_JOIN  1000   /* coins to join a new class */
#define CHARISMA       (int)this_player()->query_charisma()
#define MASTER_CHA     16


#define QPS            (int)this_player()->query_quest_points()

#define DRAINED        (int)this_player()->query_level_drained()
#define NO_ADVANCE     present("no advance",this_player())
#define PLAY_MONEY     (int)this_player()->query_money()
#define G_NAME         (string)guild_master->query_name()


mixed  *classes;        /* class-skill array       */
mixed *races;            /* races to dissallow from the guild */
mixed  *titles;         /* level titles            */
mixed  *pretitles;      /* pretitles for 30+ level */
int    *exp;            /* exp per level           */
int    *qp;             /* quest points for next level */
int    *skill_exp;      /* cost for skills         */
object guild_master;    /* guild master            */
string guild_name;      /* guild title             */
string tmpClass;         /* used by leave() fn.     */
int    weapon_rate;     /* rate which get weapons proficiencies */
int    exp_multiplier;
int    skill_exp_multiplier;

static object sign;

status leave(string str);


void set_classes(mixed *arg)      { classes = arg;      }
void set_races(mixed *arg)        { races = arg;        }
void set_titles(mixed *arg)       { titles  = arg;      }
void set_pretitles(mixed *arg)    { pretitles  = arg;   }
void set_exp(int *arg)            { exp = arg;          }
void set_skill_exp(int *arg)      { skill_exp = arg;    }
void set_guild_master(object arg) { guild_master = arg; }
void set_guild_name(string arg)   { guild_name = arg;   }
void set_weapon_rate(int arg)     { weapon_rate = arg;  }


mixed *query_classes()      { return classes;      }
mixed *query_titles()       { return titles;       }
mixed *query_pretitle()     { return pretitles;    }
int *query_exp()            { return exp;          }
int *query_skill_exp()      { return skill_exp;    }
object query_guild_master() { return guild_master; }
string query_guild_name()   { return guild_name;   }
int query_weapon_rate()     { return weapon_rate;  }


void init(){
  string tmp;
  mixed *arr;
  int i;
  ::init();
  add_action("train_weapon", "train");
  add_action("advance","raise");
  add_action("advance","advance");
  add_action("cost_for_level","cost");
  add_action("join","join");
  add_action("leave","leave");
  if(!sign) {
    sign = clone_object(SIGN);
    move_object(sign, this_object());


    sign->set_message(
  "    Commands                        Comments \n"+
  "  raise, raise <level> ....... Advance level by 1\n"+
  "  raise <skill> .............. Advances skill by 1\n"+
  "  cost <level> ............... Exp or coins needed to advance\n"+
  "  cost <skill> ............... (Not)|Possible to raise skill\n"+
  "  cost <class> ............... (Not)|Possible to raise skills in class\n"+
  "  leave <class> .............. Leave a class, set all stats to 0\n"+
  "  join <class> ............... Join the class permitted in this room\n"+
  "  train <weapon> ............. Train in a weapon and become proficient\n"
    );
  }
  if(!races) races = ({ });
}


int get_next_qp(int stat) {
  int *qp;
 

  qp = ({
            0,    0,    0,    0,    0,    0,   0,    0,    0,    0,
            0,    0,    0,    0,    0,    0,   0,    0,    0,    0,
            0,    0,    0,    0,    0,    0,   0,    0,    0,    0,
            0,    0,    0,    0,    0,    0,   0,    0,    0,    0,
            0,    0,    0,    0,    0,    0,   0,    0,    0,    0,
            0,    0,    0,    0,    0,    0,   0,    0,    0,    0,
            0,    0,    0,    0,    0,    0,   0,    0,    0,    0,
            0,    0,    0,    0,    0,    0,   0,    0,    0,    0,
            0,    0,    0,    0,    0,    0,   0,    0,    0,    0,
            0,    0,    0,    0,    0,    0,   0,    0,    0,    0,
            12
         });
 
   if(stat < 0) return qp[0];
   if(stat > 100) return ((stat - 100) *10) + 2;  /* worry when close */
   return qp[stat];
}

/* exp for next level */

int get_next_exp(int stat) {
     int tmp;
  if(stat < 1) return 1014;
  if(stat < 20)
    return 1014 + to_int(1014*exp(stat * log(1.4683496)));
/* ok so it looks silly, but it makes xp for level 20 about 1.5 mill */
  else
/*
    return to_int(get_next_exp(20) * exp((stat-20) * log(1.17)));
*/
{
     tmp = get_next_exp(19) + (500000
          * (stat - 19)) + 20000 * (stat - 20) * (stat  -19) /2;
     if(tmp > 0) return tmp;
          else return 500000000000;
     }
}
/* The one above is a geometric series. lets try a algebraic one: */
/*
int get_next_exp(int stat) {
     return 1014 * (stat + 1) + 10000 * stat * (stat + 1) /2;
}
*/

/* exp for next stat */

int get_skill_exp(int stat) {
  if(stat < 0) return skill_exp[0];
  if(stat >= sizeof(skill_exp)) {
    if(!skill_exp_multiplier) skill_exp_multiplier = 25000;
    return skill_exp[sizeof(skill_exp)-1] 
         + (stat-(sizeof(skill_exp)-1))*skill_exp_multiplier;
  }
  return skill_exp[stat];
}


/* if the player is within 10% of their next level, they advance at a
 * cost of 3 times coins of the exp difference. */

int close_enuff(status costing_only){
  int required_money, required_exp;
 
  required_exp = get_next_exp(LEVEL-1);
  required_money = (required_exp - EXP) * 3;

  if(EXP < required_exp && (required_exp-EXP) < required_exp/10) {
    if(PLAY_MONEY > required_money) {
      if(!costing_only){
        this_player()->add_money(required_money*(-1));
        this_player()->set_exp( required_exp);
        write(G_NAME +" takes "+ required_money +
              " coins from you for extra training.\n");
      }
      return required_money;
    }
  }
  return 0;
}



/*** exp required ***/

string get_new_title(int next_level){
  string *weird_titles;
  int gender;

  gender = (int)this_player()->query_gender();
  while(!sizeof(titles[gender])) gender++;

  if(next_level > sizeof((string *)titles[gender]) - 1) {
    while(!sizeof((string *)pretitles[gender])) if(++gender > 2) return "";
    next_level = (next_level-30)/4;
    if(next_level > sizeof((string *)pretitles[gender])) {
      next_level = sizeof((string *)pretitles[gender])-1;
    }
    if(this_player()->query_level() > 29)
    this_player() -> set_pretitle((string)pretitles[gender][next_level]);
     
    weird_titles = ({
                      "the Stranger",
                      "the Insignificant",
                      "the Saviour",
                      "the Blood Stained",
                      "the Dragon Slayer",
                      "Orcbane",
                      "Ironfist",
                      "the Faithful",
                      "the Invincible",
                      "the Meek!!!",
                      "the Black",
                      "the White",
                      "the Incorrigible",
                    });
                      
     return weird_titles[random(sizeof(weird_titles))];
  }
  while(!sizeof((string *)titles[gender])) if(++gender > 2) return "";
  return (string)titles[gender][next_level];
}


/*** advance levels or stats, and costing ***/

status advance(string str, status costing){
  int i, j, k;
  int ii;
  string stat;
  string Affil;
  int total, cost, current_stat;
  string tmp1;

  if(!guild_master) {
    write("There is no one here to train you.\n");
    return 1;
  } 
  if(this_player()->query_npc()) {
    tell_room(this_object(),G_NAME +" laughs heartily!\n");
    return 1;
  }
  if(!this_player()->query_guild_string()) {
    this_player()->set_guild_string("no");
  }


  /* in some cases, like secondary skills, we want to allow ANYONE to train
   * with a certain trainer. In this case ONLY do we set the guild_name to
   * 'any'. This will mean that ANY one can train those skills here.
   * 
   * Useful for teaching EVERYONE secondary skills, like swimming etc.
   */
  if(lower_case(guild_name) != "any") {
    if((lower_case(guild_name) != "no" && lower_case(GUILD_STR) == "no")
      || (GUILD_STR != guild_name)) {
      write(G_NAME +" says: Sorry, you can't train here.\n");
      return 1;
    }
  }

  if(DRAINED) {
    write(G_NAME +" says: You have been drained by undead,\n"+
                 "   Perhaps you should see a priest before training.\n");
    return 1;
  }

  if(NO_ADVANCE) {
    write(G_NAME +" says: You are currently under the affect of"+
          " magic, I cannot train you\n   until it wears off!\n");
    return 1;
  }

  if(Affil = (string)this_object()->query_affiliation_file()) {
    if(!(status)this_player()->query_affiliation(Affil)) {
      write(G_NAME+" says: Only a "+
	(string)this_object()->query_affiliation_name()+" can train here.\n");
      return 1;
    }
  }


  /*** advance a players level ***/
  
  if(!str || str == "level") {
    if(costing) {
      write("Next Level: "+ get_next_exp(LEVEL-1)*3 +" total experience points ");
      if(TEXP > get_next_exp(LEVEL-1)*3) {
        write("(POSSIBLE)\n");
      }
      else if(close_enuff(1)) {
        write("(POSSIBLE: "+ close_enuff(1) +" coins)\n");
      }
      else {
        write("(NOT POSSIBLE: You need more experience points)\n");
      }
      return 1;
    }

    if((ii = (get_next_qp(LEVEL) - QPS)) > 0) {
      notify_fail(G_NAME+" says: You need "+ ii +" more quest points to advance\n");
      return 0;
    }
 
    if(TEXP > 3*get_next_exp(LEVEL-1) || close_enuff(0)) {
      this_player()->set_title(get_new_title(LEVEL+1));
      this_player()->set_level(LEVEL + 1);
      this_player()->save_character();
      say(G_NAME +" trains "+ NAME +" to level "+ LEVEL +".\n");
      write(G_NAME +" trains you. You are now level "+ LEVEL +", "+
          (string)this_player()->short()+"\n");
      return 1;
    }
    else {
      write(G_NAME+" says: You need to train more before advancing.\n");
      return 1;
    } 
    return 1;
  }

  if(costing) { /* recursively cost a class */
    if((i = member_array(str,classes)) != -1) {
      for(k = 0; k < sizeof(classes[i+1]); k++) {
        advance(classes[i+1][k],1);
      }
      return 1;
    }
  }

  for(i = 1; i < sizeof(classes); i += 2) {
    if((j = member_array(str, classes[i])) != -1) {
      if(!this_player()->query_class(classes[i-1]) 
      && classes[i-1] != "general" && classes[i-1] != "primary") {
        write(G_NAME +" says: You are not a "+ classes[i-1] +".\n");
      }
      else {
        stat = str;
        while(sscanf(stat,"%s %s",stat,tmp1))  stat += "_"+ tmp1;
        stat = lower_case(stat);
        current_stat = (int)call_other(this_player(),"query_"+stat);
        cost = get_skill_exp(current_stat);
        if(member_array(stat, ({ 
                         "strength", "intelligence", "wisdom",
                         "dexterity", "constitution", "charisma",
                         "combat", })) != -1) {

         if(current_stat >= 
           (int)call_other(this_player(), "query_max_"+stat)) {
           write(G_NAME+" says: You are more powerful than I am!\n\tI can no "+ 
                 "longer train you in "+stat+".\n");
           return 1;
         }
       }  

        if(!(classes[i-1] == "general" || classes[i-1] == "primary")) {
          /* Multi-class multiple exp setting cost; was 3/2 */
         if(sizeof((string *)this_player()->query_classes()) == 1)
           cost *= 1;
         else
           cost *= (sizeof((string *)this_player()->query_classes())*3)/2;
        }
        for(k = 0; k < sizeof(classes[i]); k++) {
          stat = classes[i][k];
          while(sscanf(stat,"%s %s", stat, tmp1)) stat += "_"+ tmp1;
          stat = lower_case(stat);
          total += (int)call_other(this_player(),"query_"+ stat);
        }
        if(total > (LEVEL + 1) * sizeof(classes[i])) {
          if(costing) {
            write("Your level needs to be higher, before you can advance "+
                  "your "+ str +".\n");
          }
          else {          
            write(G_NAME+" says: You need to be of greater Status.\n");
          }
          return 1;
        }
     if(EXP<cost) {
          if(costing) {
            str = extract(str+"                         ",0,25);
            write(capitalize(str) +"Need "+(cost-EXP) +
                    " extra experience points.\n");
          }
          else {
            write(G_NAME +" says: You need to be more experienced.\n");
          }
          return 1;
        }
        if(costing) {
          str = extract(str+"                                ",0,25);
          write(capitalize(str) + cost +" experience points.\n");
          return 1;
        }
        stat = str;
        while(sscanf(stat,"%s %s",stat,tmp1))  stat += "_"+ tmp1;
        call_other(this_player(),"set_"+ lower_case(stat), current_stat+1);
        this_player()->set_exp(EXP-cost);
        this_player()->save_character();
        if(classes[i-1] == "general" || classes[i-1] == "primary") {
          write(G_NAME+" helps you to raise your "+ capitalize(str) +".\n");
        }
        else {
          write(G_NAME+" says: I have trained you in the skill of "+
                capitalize(str)+".\n");
        }
        say(NAME +" raises "+ this_player()->query_possessive() +" "+
            str +".\n"); 
      }
      return 1;
    }
  }
  write(G_NAME + " looks at you in a confused manner.\n");
  return 1;
}


/*** Cost for raising skill levels ***/
status cost_for_level(string str){
  int i;
  
  if(!guild_master) {
    write("There is no one here for you to get a costing opinion.\n");
    return 1;
  }
  if(!str) {
    write("Usage: cost <class|skill|general|primary|level>\n");
    return 1;
  }
  this_object()->advance(str, 1);
  return 1;
}


/*** Leave class ***/

status leave_check(string str) {
  if(!str || str != "y") {
    write(G_NAME +" says: Very well then. If you wish to leave your class, spend the \n"+
          "\texperience you heave earned in it first.\n");
    return 1;
  }

      write("Removing excess experience points...\n");
      this_player()->set_exp((500 * (int)this_player()->query_level()));
  leave(tmpClass);
  return 1;
}

status leave(string str) {
  if(!guild_master) {
    write("There is no one here to remove your class.\n");
    return 1;
  }
  if(!str) {
    write(G_NAME +" says: Leave what class?\n");
    return 1;
  }
  if(member_array(str, classes) == -1) {
    write(G_NAME+" says: You can't discontinue your training as "+
    "a "+capitalize(str)+" here.\n");
    switch(str) {
    case "cleric" :
      write("\tYou need to find a temple discontinue your clerical studies.\n");
      break;
    case "fighter" :
      write("\tYou need to find the arena master to stop training.\n");
      break;
    case "thief" :
      write("\tThieves usually meet in secret places, like sewers.\n");
      break;
    case "mage" :
      write("\tThe mages study in places of learning. Search them out.\n");
      break;
    case "paladin" :
      write("\tPaladin are holy knights. You should find their temple.\n");
      break;
    default :
      write("\tYou must find where the "+capitalize(str)+" meet.\n");
      break;
    }
    return 1;
  }

  if(this_player()->query_class(str)) {
    if(this_player()->query_exp() > (500 * (int)this_player()->query_level())) {
      write(G_NAME +" exclaims: You still have experience collected from adventuring as a "+str+"!\n");
      tmpClass = str;
      write(G_NAME +" says: You can't use experience you earned as a "+ str +" in any other class.\n");
      write("\tIf you leave this class you will loose those experience points.\n"+
            "Still leave class? (y/n) > ");
      input_to("leave_check");
        return 1;
      }

    write("You are no longer in the class "+str+".\n");
    this_player()->recalc_sk();
    this_player() -> remove_class(str);
    this_player() -> remove_channel(str);
    CHANNEL_D     -> chat_channel(str, this_player()->query_name() +" is no longer a "+str+"\n");
    call_other(this_player(),"clear_"+ str);
    this_player() -> save_character();
  }
  else
    write("You were not in the class "+ str +".\n");
  return 1;
}
  

/*** Join Class ***/

status join(string str) {
  int i;
  int cost;
  mixed *arr;
  string tmp;
  status flag;
  string tmp1, tmp2;
  string race;

  cost = (int)this_player()->query_level();
  cost *= COST_FOR_JOIN;
  if(random(CHARISMA) > random(MASTER_CHA))
    cost -= random(cost/4);
  else
    cost += random(cost/3);

  if(!guild_master) {
    write("There is no one here to join you up.\n");
    return 1;
  }
  if(!str) {
    write(G_NAME +" says: Join what class?\n");
    write(G_NAME+" says: It will cost you about "+
    MONEY->convert(cost)+" for new training.\n");
    arr = query_classes();
    tmp = "";
    for(i=0; i<sizeof(arr); i+=2) {
      tmp += arr[i]+" ";
    }
    write(G_NAME+" says: You can train in the following skills here, \n");
    write("\t"+ tmp +"\n");
    return 1;
  }

  if(member_array(str, classes) == -1 || str == "general" || str == "primary"){
    write(G_NAME+" says: I can only train you as a ");
    for(i = 0; i < sizeof(classes); i += 2) {
      if(classes[i] == "general" || classes[i] == "primary") continue;
      if(flag && i+2 >= sizeof(classes))
        write("and ");
      else if(flag)
        write(", ");
      write(classes[i]);
      flag = 1;
    }
    write(".\n");
    switch(str) {
    case "cleric" :
      write("\tYou need to find a temple begin clerical studies.\n");
      break;
      case "fighter" :
      write("\tYou need to find the arena master to start training.\n");
      break;
    case "thief" :
      write("\tThieves usually meet in secret places, like sewers.\n");
      break;
    case "mage" :
      write("\tThe mages study in places of learning. Search them out.\n");
      break;
    case "paladin" :
      write("\tPaladin are holy knights. You should find their temple.\n");
      break;
    default :
      write("\tYou must find where the "+capitalize(str)+" meet.\n");
      break;
    }
    return 1;
  }

  if(this_player()->query_class(str)) {
    write(G_NAME+" says: You are already in the class "+ str +".\n");
    return 1;
  }

  /* if guilded, and this std guild, can't join */
  if(((string)this_object()->query_guild_name() == "No") &&
     ((string)this_player()->query_guild_string() != "No")) {
     write(G_NAME+" says: You belong to the "+
          (string)this_player()->query_guild_string()+", and can't join.\n");
     return 1;
  }

  /* if not guilded, and have classes, can't join */
  if(this_object()->query_guild_name() != "No") {
    if(sizeof((string *)this_player()->query_classes())) {
      write(G_NAME+" says: You must leave your other classes before I "+
      "can train you.\n");
      return 1;
    }
  }


  if(sizeof(this_player()->query_classes()) >= MAX_CLASSES) {
    write(G_NAME+" says: You're already skilled in as many professions "+
    "as you can learn!\n");
    return 1;
  }

  race = (string)this_player()->query_race();
  sscanf(race, "%s %s", tmp1, tmp2);


  if((member_array(race, races) == -1) && (sizeof(races) > 1)) {
    if(member_array("all", races) == -1)
    write(G_NAME+" says: A "+capitalize(race)+" can not hope to learn to "+
    " become a "+capitalize(str)+".\n\tThey simply don't have the aptitude.\n");
    return 1;
  }

  write(G_NAME+" says: Taking into account your set ways at your level.\n"+
  "\t it will be more difficult to start new training.\n");

  tmp = (string)call_other(MONEY, "convert", cost);
  write(G_NAME+" haggles with you over the cost of new training.\n");
  write(G_NAME+" says: "+
  "I will have to charge you "+tmp+" for extra tuition.\n");

  if((int)this_player()->query_money() < cost) {
    write(G_NAME+" says: Without the money, I can't train you in these "+
    "new skills.\n");
    return 1;
  }

  write(G_NAME+" takes "+tmp+" for your new training.\n");
  this_player()->add_money(-cost);
     
  write("You are now a member of the class "+str+".\n");
  this_player() -> add_class(str);
  this_player() -> add_channel(str);
  CHANNEL_D -> chat_channel(str, this_player()->query_name()+" has become a "+str+"!\n");
  this_player() -> save_character();
  this_player()->set_guild_string(this_object()->query_guild_name());
  if(str == "cleric") {
    write(G_NAME +" says: You will not be able to pray for spells, or advance your skills, \n"+
          "\tuntil you find a god to worship. Search out the leader of a church \n"+
          "\tin order to join his affiliation and begin life as a cleric.\n");
  }

  return 1;
}


status train_weapon(string str) {
  mapping weap_list;
  int i;
  int weap_skill, amount;
  object obj;
  int *tmpArr;
  string weapon;
  int prof_rate;


  if(!guild_master) {
    write("There is no one here to train you.\n");
    return 1;
  }

  if( (lower_case(guild_name) != "no" && lower_case(GUILD_STR) == "no")
    || (GUILD_STR != guild_name)) {
    write(G_NAME +" says: Sorry, you can't train here.\n");
    return 1;
  }

  if(!str) {
    write(G_NAME +" says: What weapon do you want to train with?\n");
    return 1;
  }

  obj = present(lower_case(str), this_player());
  if(!obj) {
    write(G_NAME+" exclaims: You have no such weapon!\n");
    return 1;
  }

  weapon = (string)obj->query_name();
  if(!obj) {
    write(G_NAME +" says: You dont have that weapon! \n"+
     "\t\tHow can I train you in that!!\n");
    return 1;
  }

  if(!obj->query_wielded()) {
    write(G_NAME +" says: You must first be able to wield your "+ weapon +
    "before I can teach\n\tyou how to use it properly.\n");
    return 1;
  }

  weap_list = (mapping)this_player()->query_weapon_prof();

  if(!weap_list) {  /* there are still some people with it defaulting to 0 */
    weap_list = ([]);
    this_player()->set_weapon_prof(([]));
  }
  tmpArr = m_values(weap_list);
  amount = 0;
  if(sizeof(tmpArr)) {
    for(i=0; i<sizeof(tmpArr); i++) 
      amount += tmpArr[i];
  }


  if(weapon_rate)
    prof_rate = weapon_rate; /* guild specific weapon rate */
  else if(this_player()->query_class("mage")) 
    prof_rate = 8;
  else if(this_player()->query_class("cleric"))
    prof_rate = 6; 
  else if(this_player()->query_class("thief"))
    prof_rate = 4;
  else /* fighter */
    prof_rate = 2;

  if((amount) > ((LEVEL+2)*3)/prof_rate) {
    write(G_NAME +" says: One such as you cannot learn so many weapons "+
    "at one time\n\tWait a little longer and return later.\n");
    return 1;
  }

  if(!weap_skill = weap_list[weapon]) {
    write(G_NAME +" trains you in the use of the "+ weapon +".\n"+
        "You feel more proficient in its use.\n");
    say(NAME +" trains with "+ G_NAME +" in use of the "+ weapon +".\n");
    this_player()->add_weapon_proficiency(weapon, 1);
    return 1;
  }
  else {
    if(weap_skill > (LEVEL*1/2)) {
      write(G_NAME +" says: One of your stature could not possibly learn "+
	   "more about\n\tyour "+weapon+" just now. Return to me  "+
	   "at another time.\n");
      return 1;
    }
    write(G_NAME+" trains you some more in the use of the "+weapon+".\n"+
	"You feel more proficient in its use.\n");
    say(NAME+" trains with "+G_NAME+" and seems more proficient in the "+
	"use of the "+weapon+".\n");
    this_player()->add_weapon_proficiency(weapon, weap_skill+1);
  } 
  return 1;
}

int *get_exp_arr() {
  int *tmp;
  int n;
  
  tmp = ({});
  for(n = 0 ; n < 200; n++) tmp += ({ get_next_exp(n) });
  return tmp;
}

int query_no_fight() { return 1; }
