inherit "inherit/monster";
object nuts;
int n;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("girl");
  set_alt_name("little girl");
  set_short("A little girl");
  set_long(
	   "A cute little girl. She walks around in Ille Coronos, trying to\n"+ 
	   "sell some nuts. She carries a small sign that says:\n"+
	   "   Nuts : 10 coppers.\n");
  set_level(1);
  set_gender(2);
  set_hp(40);
  set_ac(3);
  set_wc(5);
  load_chat(15, ({"Girl shouts: Come and buy some tasty hazel-nuts.\n",
		  "Girl asks: Would you like some nuts?\n", 
		  "Girl says: Please, buy some nuts. Only 10 coppers.\n",
		  "The little girl smiles cutely.\n",
		  "Girl shouts: Come and buy some nuts.\n",
		  "Girl shouts: Only 10 coppers.\n",
		}));
  load_a_chat(20, ({ "Girl says: No! Please leave me alone.\n",
		     "Girl tries to run away.\n",
		     "Girl bursts into tears.\n",
		     "Girl says: You're hurting me!\n",
		   }));
  set_attack_msg(({
    "spits",     "on the shoes",
    "touches",   "on the arm",
    "pinches",   "in the face",
    "punches",   "on the arm",
    "kicks",     "weakly on the leg",
    "bites",     "with her sharp teeth",
  }));
  if(!present("nuts")) 
    {
      for (n=0;n<2+random(4);n++)
      {
	nuts=clone_object("/d/coronos/w/lanfear/stuff/nuts");
	move_object(nuts,this_object());
	command("put nuts in bag");
      }
    }
  set_race("human");
  set_al(500);
  set_wander(10, 500);
}


void init() 
{
  call_out("chat", 1);
  ::init();
  add_action("buy", "buy");
}

status buy(string str) 
{
  string tmpa, tmpb;
  if (str)
  {
    if(sscanf(str, "%snuts%s", tmpa, tmpb))  
    {
      if ((this_player()->query_money())<10)
      {
	tell_object(this_player(), 
	"Girl says: The "+str+" cost 10 coppes and you dont have that.\n"); 
	return 1;
      }
      else
      {
	this_player()->add_money(-10);
	tell_object(this_player(), 
	"The girl says: Thank you "+this_player()->query_name()+
	",and gives you some nuts.\n");
	nuts=clone_object("/d/coronos/w/lanfear/stuff/nuts");
	move_object(nuts,this_player());
	say(""+this_player()->query_name()+
	" buys some nuts from the cute little girl.\n", this_player());
	return 1;
      }
    }
    else
    {
     tell_object(this_player(), "Girl says: But I don't sell "+str+
      ", I only sell nuts.\n"); 
      return 1;
    }
  }
}

void chat() 
{
  if(!this_player()->query_stealth_on() && !this_player()->query_npc()) 
  {
    tell_object(this_player(), "The little girl curtseys cutely before"+ 
			       "you and asks:\n"+           
			       " Would you like to buy some nuts?\n");
    say("The girl asks if "+ this_player()->query_name() +
	" would like to buy some nuts.\n", 
this_player());
  }
}

catch_tell(string str) {
 string tmp1, tmp2, tmp3;
 int i;
 
  if(sscanf(str, "%s gives you %s\n", tmp1, tmp2)) 
  {
    if(sscanf(tmp2, "%d coins", i)) 
    {
    if (i==10)
      {
	tell_object(this_player(), 
	"Girl gives you some nuts and says: Thank you "+tmp1+".\n");
	nuts=clone_object("/d/coronos/w/lanfear/stuff/nuts");
	move_object(nuts,this_player());
	say(""+tmp1+" buys some nuts.\n", this_player());
      }
    else if (i > 10) 
      {
	tell_object(this_player(), 
	"Girl curtseys, gives you some nuts and says: Thank you very much "+tmp1+".\n");
	nuts=clone_object("/d/coronos/w/lanfear/stuff/nuts")
;
	move_object(nuts,this_player());
	say( ""+tmp1+" buys the nuts for an over-prize and makes the girl happy.\n", 
	this_player());
      }
    else if (i<10) 
      {
       tell_object(this_player(), 
       "The little girl says: The nuts cost 10 coppers.\n");
      }
    }
  }                                            
}                                     


