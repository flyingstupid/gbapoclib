/* LYCANTHROPE.
 * Alastaire is an infected lycanthrope, a werebear
 * He will berserk and back due to combat, but who
 * would be foolish enough to attack him at that level! 
 * ( c )Angel, 1997
 */

#include <mudlib.h>
#include <linewrap.h>


#define NAME            capitalize((string)this_player()->query_name(1))
#define QUEST_SCROLL   "d/coronos/w/angel/ud/obj/scroll"

#define HUG		50
#define BITE		20
#define CLAW		20
#define DEX		(int)query_attack()->query_dexterity()

#define OBJ		"d/coronos/w/angel/city/obj"

inherit MONSTER;

int berserk, counter;
object sword, armour, helm, boots;

void quest();
void do_equip();
void un_equip();
string *query_attack_msg();


string short(status wiz) {
  if(berserk) return "A huge bear";
  else return "Lord Alastaire Nighthawk";
}

void long(status wiz) {
  if(!berserk)
  write(
"Short and solid are the best ways to describe Alastaire.\n"+
"With a flowing blonde moustache and long hair spilling  \n"+
"about his shoulders he seems more of a knight than a   \n"+
"lord of a city. His face appears awash with worry, but \n"+
"that is just his nature.\n");

  else
    write(
	"A huge berserk bear with glowing red eyes!\n"+
	"While it looks very hungry and savage, it \n"+
	"reminds you of someone you know. . . \n");
  ::long(wiz);
}


string query_race(status arg) {
  return (berserk) ? "werebear" : "human";
}


void reset(status arg) {
  ::reset(arg); /* make alive! */

  if(arg) return;

  set_name("alastaire");
  set_alias("lycanthrope");
  set_alt_name("bear");
  set_long(0);
  set_gender(1);
  set_alignment(800);
  set_race("human");
  set_level(60);
  add_spell_immune("fire");
  add_spell_immune("charm");
  add_spell_immune("lightning");
  add_spell_immune("death");
  add_spell_immune("cold");
  add_spell_immune("light");

  set_magic_resist(75);

  set_max_hp(2500);
  set_hp(2500);
  set_wc(30);
  set_ac(20);

  add_class("fighter");
  add_class("mage");
  add_class("cleric");

  load_chat(6, ({
"Alastaire says: Welcome to our fair city.\n",
"Alastaire says: I, regent of The Circle, bring you greetings.\n",
"Alastaire says: I wonder where Captain Rachel is?\n",
"Alastaire says: Be wary of the drow. They have brought the fair\n"+
"                city of Ille Coronos nothing but trouble.\n",
"Alastaire says: Please be quick, Im off to the Forest of \n"+
"                Scianthion come the full moon of Acipter.\n",
"Alastaire asks: From what city do you hail?\n",
"Alastaire asks: Have you seen Lord Porthios? I must get back\n"+
"                to my studies in magic.\n",
"Alastaire asks: Do you know who is responsible for the hand \n"+
"                prints on some of our buildings?\n",
  }));

  load_a_chat(5, ({
"Alastaire exclaims: Im going to die, Im going to die!\n",
"Alastaire exclaims: A perfect hit!!\n",
"Alastaire says: I warn you, do not make me angry.\n",
"Alastaires eyes glow red.\n",
"Alastaire growls menacingly.\n",
"Alastaire frowns.\n", 
"Alastaire says: Leave me.\n",
"Alastaire exclaims: The Black Guard will have your head!\n",
"Alastaire says: Begone from this place.\n",
  }));

  load_spells(50, ({
"magic missile", "acid arrow", "hold person",
"bless", "curse", "heal", "fire shield",
"cure light wounds", "cure wounds",
  }));

  set_wimpy(200);
  set_wander(50, 3600);
  set_domain("coronos");
  set_heart_ob(this_object());
  set_dead_ob(this_object());
}


void monster_died() {
  tell_room(environment(),
        "Alastaire cries out in pain.\n"+
        "Alastaire undergoes a horrible transformation.\n"+
        "Alastair slowly changes back into a human.\n");
}
void monster_heart_beat() {
  object ob;
  status Claw, Bite;

  if(!ob=query_attack()) {
    counter --;
    if(counter < 0) counter = 0;
    if(berserk) {
      berserk --;
      tell_room(environment(),
	"Alastaire growls: Leave me be, else I shall eat you!\n");
      if(!berserk) {
        tell_room(environment(),
	"Alastaire cries out in pain.\n"+
	"Alastaire undergoes a horrible transformation.\n"+
	"Alastair slowly changes back into a human.\n");
        do_equip();
        set_race("human");
        set_attack_msg(0);
        adj_hp(500);
      }
    }
    return;
  }
	

  if(berserk) {
    if(random(DEX) < random(BITE)) {
      say(query_name()+" bites deeply into "+ob->query_name()+"\n",ob);
      tell_object(ob, query_name()+" bites deeply into you!\n");
      ob->do_damage(random(BITE) + 1);
      Bite = 1;
    }

    if(!query_attack()) return; /* safe guard from hit */

    if(random(DEX) < random(CLAW)) {
      say(query_name()+" claws chunks of flesh from "+
		ob->query_name()+"s body.\n",ob);
      tell_object(ob, query_name()+" claws chunks of flesh from "+
	"your body!\n");
      ob->do_damage(CLAW);
      Claw = 1;
    }

    if(!query_attack()) return; /* safe guard from hit */

    if(Claw && Bite) {
      if(random(DEX) < random(HUG)) {
        say(query_name()+" gives "+ob->query_name()+
		"a bear hug!\n", ob);
        tell_object(ob, query_name()+" gives you a bear hug!\n");
        ob->do_damage(HUG);
      }
    }
    counter ++;
    return;
  }    

  counter ++;

  if(counter < 10)
    tell_room(environment(), 
		"Alastaire says: I warn you. Do not make me angry.\n");
  else if(counter < 20)
    tell_room(environment(),
	"Alastaire exclaims: Leave me, else you will be sorry!\n");
  else {
      tell_room(environment(), 
	"Alastaire undergoes a horrible change!\n"+
	"Alastaire bursts out of his armour!\n"+
	"Alastaire cries out in pain as he transforms into a bear!\n");
    un_equip();
    berserk ++;
    set_attack_msg(query_attack_msg());
    set_race("bear");
    adj_hp(500);
  }
}


void do_equip() {
  if(sword && present(sword)) 
    init_command("wield sword");
  if(helm && present(helm))
    init_command("wear helm");
  if(armour && present(armour))
    init_command("wear fieldplate");
  if(boots && present(boots))
    init_command("wear boots");
  set_wc(30);
  set_ac(20);
}

void un_equip() {
  if(sword && present(sword))   sword->drop();
  if(helm && present(helm))     helm->drop();
  if(armour && present(armour)) armour->drop();
  if(boots && present(boots))   boots ->drop();
  set_wc(50);
  set_ac(40);
} 

string *query_attack_msg() {
  return (berserk) ?
	({ "grazes", "with a bear claw.",
	   "bites",  "lightly, with his grizzly fangs.",
           "gouges", "with his bear claws.",
           "rips",   "at the throat with his huge bear claws.",
	   "bites deeply", "with his bear teeth.",
	   "smashes", "with a huge bear hug!",
           "devistates",   "with a claw to the head.",
	}) :
	({ });
}

void init() {
  ::init();
  quest();
  if(!boots) {
    boots = clone_object(OBJ+"/sboots");
    move_object(boots, this_object());
    init_command("wear boots");
  }

  if(!sword) {
    sword = clone_object(WEAPON);
    sword -> set_name("twohandedsword");
    sword -> set_alias("sword");
    sword -> set_short("A twohanded sword");
    sword -> set_alt_name("twohanded sword");
    sword -> set_wc(18);  /* +4 sword */
    sword -> set_length(72);
    sword -> set_type("cleave");
    sword -> set_weight(5);
    sword -> set_value(8500);
    sword -> set_long(
	"A fine twohanded sword forged from a blue-tinged metal.\n"+
	"The hilt itself is encrusted with precious gems and the\n"+
	"guard is fashioned from steel and white gold. It is quite\n"+
	"an impressive weapon.\n");
    sword -> set_enchanted(1);
    move_object(sword, this_object());
    init_command("wield sword");
  }

  if(!helm) {
    helm = clone_object(MAGIC_ARMOUR);
    helm -> set_type("helm");
    helm -> set_ac(1);
    helm -> set_weight(1);
    helm -> set_value(300);
    helm -> set_arm_light(1);
    helm -> set_name("helm");
    helm -> add_spell("fire ball");
    helm -> add_spell("lt");
    helm -> add_spell("lightning bolt");
    helm -> add_spell("prismatic spray");
    helm -> set_short("A shining helm");
    helm -> set_bins(({
	"/skills/mage", "/skills/affils/wrm",
    }));

    helm -> set_long(
	"This helm has a number of brilliant gems encrusted \n"+
	"within its surface; all number of fire opals, rubies,\n"+
	"and even diamonds. Some appear a little dull, but \n"+
	"the others appear to even glint with a magical sheen.\n");
    helm -> set_info("A helm of brilliance");
    helm -> set_cast_level(20);
    helm -> set_protection("fire");
    helm -> set_max_charges(50);
    helm -> set_charges(50);
    helm -> set_cast_level(25);
    helm -> set_sell_destruct(1);
  }

  if(!armour) {
    armour = clone_object(MAGIC_ARMOUR);
    armour -> set_name("fieldplate");
    armour -> set_type("armour");
    armour -> set_ac(5);
    armour -> set_weight(4);
    armour -> set_value(9000);
    armour -> set_protection("cold");
    armour -> set_sell_destruct(1);
    armour -> set_short("A suit of fieldplate armour");
    armour -> set_info("Fieldplate of Etherealness\n");
    armour -> set_max_charges(40);
    armour -> set_charges(20);
    armour -> set_cast_level(20);
    armour -> add_spell("wraith form");
    armour -> set_long(
"With tassels of golden silk from its shoulders, and many \n"+
"medals on its breast plate this is indeed a fine suit of \n"+
"armour. Such would be worn only by paladin, knights, and \n"+
"by the most noble of generals. On the left breast is a   \n"+
"golden circle bearing a crucifix and an eagle soaring    \n"+
"over its apex; it is the symbol of the city of Ille Coronos.\n");
    move_object(armour, this_object());
    init_command("wear armour");
  }
}





status query_no_steal() { return 1; }


void quest() {
  object ob;
  string *names;
  string file;
  int i;

  names = ({ });
  if(this_player()->query_current_quest() != "LifeStealer") return;

  if(!(ob = present("lifestealer", this_player()))) {
    if(member_array(names, NAME) == -1) {
      writelw(query_name() +" says: Greetings "+NAME+". I see you are embarking "+
      "on a quest for our fair city. You still need to find the weapon before "+
      "the drow can get it to their clan who live within the Underdark. Haste "+
      "is of the essence, my friend.\n");
      names += ({ NAME, });
    }
    else {
      writelw(query_name() +" exclaims: Why are you back so soon, and without "+
      "that dreadful weapon! Return when you have found it from our enemy, the "+
      "house Noquar!\n");
    }
    return;
  }
 
  file = file_name(ob);
  if(!sscanf(file, "d/coronos/w/angel/ud/obj/life#%d", i)) {
    writelw(query_name()+" says: I see you have a weapon, but that is not the "+
    "terrible item we hope to destroy. You must find it before the Noquar "+
    "can spirit it away into the Underdark!\n");
    return;
  }

  writelw(query_name() +" says: Excelent, "+NAME+". I see you have that horrible "+
  "weapon. Seek out the head of the Black Guard, he will inform you of how we "+
  "wish to dispose of the item.\n");

  write(query_name() +" gives you a scroll.\n");
  say(query_name() +" gives "+NAME+" a scroll.\n", this_player());

  writelw(query_name() +" says: Show him this. He will know what to do.\n");
  move_object(clone_object(QUEST_SCROLL), this_player());
  return;
}

