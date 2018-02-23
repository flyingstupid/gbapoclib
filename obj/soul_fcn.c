/*****************************************************************/
/*** New Implementation (with adverbs) by Mumbles, August 1993 ***/
/***                                                           ***/
/*** Previous Updates:                                         ***/
/***         Far-call Implementation by Zilanthius, Dec. 1992  ***/
/***         Modified for genders: padrone, Oct 22 1990        ***/
/***                                                           ***/
/*****************************************************************/
string cap_name, *adverb_list;
object the_owner;

reset(arg) {
    if (!arg) {
        adverb_list = ({
#include "adverbs.h"
        });
    }
}

soul_command(verb, str, player_name) {
    object ob;
    string adv, who;

    cap_name = player_name;
    the_owner = this_player();
    if (str) {
        if (sscanf(str,"%s %s", who, adv) != 2)
            who = str;
        ob = present(lower_case(who), environment(this_player()));
        if (ob == this_player()) {
            write("You must be awfully bored.\n");
            return 1;
        }
        if (!ob || !living(ob)) {
            adv = who;
            ob = 0;
        }
        adv = adv ? valid_adverb(adv): 0;
    }
    return call_other(this_object(), verb, ob, adv);
}

valid_adverb(s) {
    int i;
    for (i=0; i < sizeof(adverb_list); i++)
        if (abbr(s, adverb_list[i])) {
            return adverb_list[i];
        }
    return 0;
}

abbr(s1, s2) {
    if (strlen(s1) < 4)
        return 0;
    return extract(s2, 0, strlen(s1) - 1) == s1;
}

/*** Notice That The Functions Are in Alphbetical Order!! ***/
            /*** KEEP IT THAT WAY ***/

ack(ob, adv) {
    string ob_name;
   
    if (ob) {
        write("How do you ack someone else?\n");
        return 1;
    }
    write("You ack " + (adv ? adv: "noisily") + ".\n");
    say(cap_name + " acks " + (adv ? adv: "noisily") + ".\n");
    return 1;
}

agree(ob, adv) {
    string ob_name;

    if (!ob && !adv) {
        write("You agree wholeheartedly.\n");
        say(cap_name + " agrees wholeheartedly.\n");
        return 1;
    }
    if (ob) {
        tell_object(ob, cap_name+" agrees with you"+ 
          (adv ? " "+adv: "") +".\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();        
    }
    write("You agree"+ (ob ? " with "+ob_name: "") + 
      (adv ? " "+adv: "") +".\n");
    say(cap_name+" agrees"+ (ob ? " with "+ob_name: "") + 
      ( adv ? " "+adv: "") +".\n", ob ? ob: this_object());
    return 1;
}

ah(ob, adv) {

     write("You finally get the idea and give an 'ah' of comprehension.\n");
    say(cap_name + " finally gets the idea and gives an 'ah' of comprehension.\n");
    return 1;
}
applaud(ob, adv) {
    string ob_name;

    if (!ob && !adv) {
        write("You applaud wholeheartedly.\n");
        say(cap_name + " gives a round of applause.\n");
        return 1;
    }    
    if (ob) {
        tell_object(ob, cap_name+" gives you a round of applause"+
          (adv ? " "+adv: "") +".\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You applaud"+ (ob ? " "+ob_name: "")+(adv ? " "+adv: "") +".\n");
    say(cap_name+" applauds"+ (ob ? " "+ob_name: "") + 
      (adv ? " "+adv: "") +".\n", ob ? ob: this_object());
    return 1;
}
 
arch(ob, adv) {
    string ob_name;

    if(!ob && !adv) {
        write("You arch an eyebrow quizzically.\n");
        say(cap_name + " archs an eyebrow quizzically.\n");
        return 1;
    }
    if (ob) {
        tell_object(ob, cap_name+" archs an eyebrow"+ 
          (adv ? " "+adv: "") +" at you.\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You arch an eyebrow"+ (adv ? " "+adv: "") +
      (ob ? " at "+ob_name: "") +".\n");
    say(cap_name+" archs an eyebrow"+ (adv ? " "+adv: "") + 
      (ob ? " at "+ob_name: "") +".\n", ob ? ob: this_object());
    return 1;
}
 
beam (ob, adv) {
  string ob_name;

  if (ob) {
    tell_object(ob, cap_name+ " beams "+ (adv ? adv : "brightly") +" at you.\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
  }
  write ("You beam " + (adv ? adv : "brightly") + (ob ? " at " + ob_name : "") 
    + ".\n");
  say (cap_name + " beams " + (adv ? adv : "brightly") + 
    (ob ? " at "+ob_name :"") + ".\n", ob ? ob : this_object());
  return 1;
}


blush(ob, adv) {

    if (adv) {
        write("You blush "+ adv +".\n");
        say(cap_name+" blushes "+ adv +".\n");
        return 1;
    }
    write("Your cheeks are burning.\n");
    say(cap_name + " blushes.\n");
    return 1;
}
 
boggle(ob, adv) {
    string ob_name;
   
    if (ob) {
        write("You can't boggle someone else's mind!\n");
        return 1;
    }
    write("Your mind boggles"+(adv ? " "+adv: "")+" at the concept.\n");
    say(cap_name + "'s mind boggles"+(adv ? " "+adv: "")+" at the concept.\n");
    return 1;
}

bounce(ob, adv) {

    if (adv) {
        write("You bounce around "+ adv +".\n");
        say(cap_name+" bounces around "+ adv +".\n");
        return 1;
    }
    write("B O I N G !!\n");
    say(cap_name + " bounces around.\n");
    return 1;
}
 
bop(ob, adv) {
    string ob_name;
   
    if (!ob) {
        write("You bop to the beat" + (adv ? " "+adv: "") + ".\n");
        say(cap_name + " bops to the beat" + (adv ? " "+adv: "") + ".\n");
        return 1;
    }
    tell_object(ob, cap_name+" bops you on the head " +
      (adv ? adv: "playfully") + ".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You bop " + ob_name + " on the head " +
      (adv ? adv: "playfully") + ".\n");
    say(cap_name + " bops " + ob_name + " on the head " +
      (adv ? adv: "playfully") + ".\n", ob);
    return 1;
}

bow(ob, adv) {
    string ob_name;

    if (!ob && !adv) {
        write("You bow to your audience.\n");
        say(cap_name + " bows gracefully.\n");
        return 1;
    }
    if (ob) {
        tell_object(ob, cap_name+" bows"+ (adv ? " "+adv: "")+  
          " before you.\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();        
    }
    write("You bow"+ (adv ? " "+adv: "") + 
      (ob ? " to "+ob_name: "") +".\n");
    say(cap_name+" bows"+ ( adv ? " "+adv: "") + 
      (ob ? " to "+ob_name: "") +".\n", ob ? ob: this_object());
    return 1;
}
 
brb(ob, adv) {

    write("You hold up one finger and say \"I'll be right back!\"\n");
    say(cap_name + " hold up one finger and says \"I'll be right back!\"\n");
    return 1;
}

burp(ob, adv) {

    if (adv) {
        write("You burp "+ adv +".\n");
        say(cap_name+" burps "+ adv +".\n");
        return 1;
    }
    write("Excuse yourself!\n");
    say(cap_name + " burps rudely.\n");
    return 1;
}
butt(ob, adv) {
    string ob_name;

    if (!ob && !adv) {
        write("You stare deeply at the wall, close your eyes and bash your head\n"+ "into it like a madman.\n");
        say(cap_name + " stares deeply at the wall for a second then bashes\n"+ the_owner->query_possessive() +" head into it.\n");
        return 1;
    }
    if (ob) {
        tell_object(ob, cap_name+" bashes "+ the_owner->query_possessive() + " head into yours"+
          (adv ? " "+adv: "") +".\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
write ("You bash heads"+ (ob ? " with "+ob_name: "") +
      (adv ? " "+adv: "") +".\n");
    say(cap_name+" bashes "+ the_owner->query_possessive() +" head "+ (ob ? " into "+ob_name: "") +
      ( adv ? " "+adv: "") +".\n", ob ? ob: this_object());
    return 1;

}
 
cackle(ob, adv) {

    if (adv) {
        write("You cackle "+ adv +".\n");
        say(cap_name+" cackles "+ adv +".\n");
        return 1;
    }
    write("You cackle gleefully.\n");
    say(cap_name + " throws " + the_owner->query_possessive() +
        " head back and cackles with glee!\n");
    return 1;
}
 
cheer(ob, adv) {
    string ob_name;
   
    if (!ob) {
        write("You cheer " + (adv ? adv: "wholeheartedly") + ".\n");
        say(cap_name + " cheers " + (adv ? adv: "wholeheartedly") + ".\n");
        return 1;
    }
    tell_object(ob, cap_name+" cheers for you " +
      (adv ? adv: "wholeheartedly") + ".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You cheer for "+ob_name+(adv ? " "+adv: " wholeheartedly")+".\n");
    say(cap_name + " cheers for " + ob_name +
      (adv ? " "+adv: " wholeheartedly") + ".\n", ob);
    return 1;
}

chuckle(ob, adv) {

    if (adv) {
        write("You chuckle "+ adv +".\n");
        say(cap_name+" chuckles "+ adv +".\n");
        return 1;
    }
    write("You chuckle politely.\n");
    say(cap_name + " chuckles politely.\n");
    return 1;
}
 
clap(ob, adv) {

    if (adv) {
        write("You clap "+ adv +".\n");
        say(cap_name+" claps "+ adv +".\n");
        return 1;
    }
    write("You clap briefly.\n");
    say(cap_name + " claps.\n");
    return 1;
}
 
comfort(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    tell_object(ob, cap_name+" comforts you" +
      (adv ? " "+adv: "") +".\n");
    write("You comfort "+ob_name+ (adv ? " "+adv: "") +".\n");
    say(cap_name + " comforts "+ ob_name +
      (adv ? " "+adv: "") +".\n", ob);
    return 1;
}
 
cough(ob, adv) {

    if (adv) {
        write("You cough "+ adv +".\n");
        say(cap_name+" coughs "+ adv +".\n");
        return 1;
    }
    write("Cover your mouth when you do that!\n");
    say(cap_name+ " coughs noisily.\n");
    return 1;
}
 
cower(ob, adv) {
    string ob_name;
   
    if (!ob) {
        write("You cower " + (adv ? adv: "sheepishly") + ".\n");
        say(cap_name + " cowers" + (adv ? adv: "sheepishly") + ".\n");
        return 1;
    }
    tell_object(ob, cap_name+" cowers " + (adv ? adv: "sheepishly") +
      " in your presence.\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You cower "+ (adv ? adv: "sheepishly") + " in " +
      ob_name +"'s presence.\n");
    say(cap_name + " cowers " + (adv ? adv: "sheepishly") + " in " +
      ob_name + "'s presence.\n", ob);
    return 1;
}

cringe(ob, adv) {
    string ob_name;
   
    if (!ob) {
        write("You cringe " + (adv ? adv: "in terror") + ".\n");
        say(cap_name + " cringes " + (adv ? adv: "in terror") + ".\n");
        return 1;
    }
    tell_object(ob, cap_name+" cringes before you " +
      (adv ? adv: "in terror") + ".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You cringe before "+ob_name+(adv ? " "+adv: " in terror")+".\n");
    say(cap_name + " cringes before "+ob_name+(adv ? " "+adv: " in terror") +
      ".\n", ob);
    return 1;

}
cry(ob, adv) {

    if (adv) {
        write("You sob "+ adv +".\n");
        say(cap_name+" sobs "+ adv +".\n");
        return 1;
    }
    write("Waaaaah!\n");
    say(cap_name + " bursts into tears.\n");
    return 1;
}
 
cuddle(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    tell_object(ob, cap_name+" cuddles you" +
      (adv ? " "+adv: "") +".\n");
    write("You cuddle "+ob_name+ (adv ? " "+adv: "") +".\n");
    say(cap_name + " cuddles "+ ob_name +
      (adv ? " "+adv: "") +".\n", ob);
    return 1;
}
 
curtsey(ob, adv) {

    if (adv) {
        write("You curtsey "+ adv +".\n");
        say(cap_name+" curtseys "+ adv +".\n");
        return 1;
    }
    write("You curtsey gracefully.\n");
    say(cap_name + " curtseys gracefully.\n");
    return 1;
}
 
dance(ob, adv) {
    string ob_name;

    if (!ob) {
        write("Feels silly, doesn't it?\n");
        say(cap_name + " does the disco duck.\n");
        return 1;
    }
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    tell_object(ob, cap_name + " sweeps you across the dance floor.\n");
    write("You sweep "+ ob_name +" across the dance floor.\n");
    say(cap_name+" sweeps "+ ob_name +" across the dance floor.\n", ob);
    return 1;
}
 
die(ob, adv) {
  
  if (!adv)
    write("YOU DIE!!!\n");
  else
    write("You fall to the ground and " + adv + " die!\n");
  say(cap_name + " falls to the ground and " + 
    (adv ? adv : "slowly") + " dies!\n");
  return 1;
}

duh(ob, adv) {

    if (adv) {
        write("You whap yourself in the head "+ adv +
          " while saying, \"Duuuuhh!\".\n");
        say(cap_name+" "+adv+" whaps "+ this_player()->query_objective()+
          "self in the head while saying, \"Duuuuhh!\".\n");
        return 1;
    }
    write("You whap yourself in the head while saying, \"Duuuuhh!\"\n");
    say(cap_name + " whaps " + this_player()->query_objective() +
    "self in the head while saying, \"Duuuuhh!\"\n");
    return 1;
}
 
eep(ob, adv) {

    if (adv) {
        write("You eep "+ adv +".\n");
        say(cap_name+" eep's "+ adv +".\n");
        return 1;
    }
    write("You eep in horror!\n");
    say(cap_name + " eep's in horror!\n "); 
    return 1;
}
  
eh(ob, adv) {
  string ob_name;

  if (ob) {
    tell_object(ob, cap_name+" looks at you "+ (adv ? adv: "strangely")+ 
      " and goes, 'EH!?'\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();        
  }
  write("You look "+   
    (ob ? "at "+ob_name+" "+(adv ? adv : "strangely") : "around "+
    (adv ? adv : "strangely")) + " and go, 'EH!?'\n");
  say(cap_name + " looks "+
    (ob ? "at "+ob_name+" "+(adv ? adv : "strangely") : "around "+
    (adv ? adv : "strangely")) +" and goes , 'EH!?'\n", ob?ob:this_object());

  return 1;
}
 
explode(ob, adv) {
  string ob_name;

  if (ob) {
    tell_object(ob, cap_name+" explodes "+ (adv ? adv: "wildly") + 
      " all over you!\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();        
  }
  write("You explode " + (adv ? adv : "wildly") + " all over " + 
    (ob ? ob_name : "the room") + "!\n");   
  say(cap_name + " explodes " + (adv ? adv : "wildly") + " all over "+

    (ob ? ob_name : "the room") + "!\n", ob ? ob : this_object());
  return 1;
}

faint(ob, adv) {
  if (adv) {
    write("You faint " + adv + ".\n");
    say(cap_name + " faints " + adv + ".\n");
    return 1;
  }
  write("You faint...THUMP!\n");
  say(cap_name + " faints dead away.\n");
  return 1;
}

fart(ob, adv) {

    if (adv) {
        write("You fart "+ adv +".\n");
        say(cap_name+" farts "+ adv +".\n");
        return 1;
    }
    write("How rude!\n");
    say(cap_name + " lets off a real rip-roarer.\n");
    return 1;
}
 
fiffle(ob, adv){

  if (adv) {
    write ("You fiffle "+adv+".\n");
    say(cap_name + " fiffles "+adv+".\n");
    return 1;
  }
  write("You fiffle delightedly.\n");
  say(cap_name+" fiffles delightedly.\n");
  return 1;
}

flex(ob, adv) {
    string ob_name;
 
    if(!ob) {
        write("You flex your buldging muscles " +
          (adv ? adv: "egotistically") + ".\n");
        say(cap_name + " flexes "+ the_owner->query_possessive() +
          " muscles " + (adv ? adv: "egotistically") + ".\n");
        return 1;
    }
    tell_object(ob, cap_name + " flexes "+ the_owner->query_possessive() +
      " muscles at you " + (adv ? adv: "egotistically") + ".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You flex your muscles "+ (adv ? adv: "egotistically") +
      " at " + ob_name + ".\n");
    say(cap_name+" flexes "+ the_owner->query_possessive() +
      " muscles "+ (adv ? adv: "egotistically") +  " at " +
      ob_name + ".\n", ob);
    return 1;
}

flip(ob, adv) {

    if (adv) {
        write("You flip "+ adv +".\n");
        say(cap_name+" flips "+ adv +".\n");
        return 1;
    }
    write("You flip head over heels.\n");
    say(cap_name + " flips head over heels.\n");
    return 1;
}
 
flutter(ob, adv) {

    string ob_name;

    if (!ob && !adv) {
    write("You flutter your eyelids suggestively.\n");
    say(cap_name + " flutters "+the_owner->query_possessive()+ " eyelids suggestively.\n");
    return 1;
   }
    if (ob) {
        tell_object(ob, cap_name+" flutters "+ the_owner->query_possessive()+" eyelids"+ 
          (adv ? " "+adv: "") + " at you.\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You flutter your eyelids"+ (adv ? " "+adv: "") +
      (ob ? " at "+ob_name: "") +".\n");
    say(cap_name+" flutters "+ the_owner->query_possessive()+ " eyelids"+ (adv ? " "+adv: "") + 
      (ob ? " at "+ob_name: "") +".\n", ob ? ob: this_object());
    return 1;

}

fondle(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    tell_object(ob, cap_name+" fondles you" +
      (adv ? " "+adv: "") +".\n");
    write("You fondle "+ob_name+ (adv ? " "+adv: "") +".\n");
    say(cap_name + " fondles "+ ob_name +
      (adv ? " "+adv: "") +".\n", ob);
    return 1;
}
 
french(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    tell_object(ob, cap_name +
       " gives you a deep and passionate kiss..it seems to take forever...\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    write("You give "+ ob_name +" a REAL kiss..it lasts a long time...\n");
    say(cap_name+" gives "+ ob_name +" a deep and passionate kiss.."+
      "it seems to take forever...\n", ob);
    if (ob->query_frog()) {
        the_owner->frog_curse(1);
        ob->frog_curse(0);
    }
    return 1;
}
 
froth(ob, adv) {
  string ob_name;
  if(!ob) {
    write("You froth"+ (adv ? " "+ adv : "") +" at the mouth.\n");
    say(cap_name+" froths"+ (adv ? " "+ adv : "") +" at the mouth.\n");
    return 1;
  }
  ob_name = interactive(ob) ? ob->query_name() : ob->short();
  write("You froth"+ (adv ? " "+ adv : "") +" at "+ ob_name +".\n");
  tell_object(ob, cap_name+" froths"+ (adv ? " "+ adv : "") +" at you.\n");
  say(cap_name +" froths"+ (adv ? " "+adv : "") +" at "+ob_name+".\n", ob);
  return 1;
}


frown(ob, adv) {

    if (adv) {
        write("You frown "+ adv +".\n");
        say(cap_name+" frowns "+ adv +".\n");
        return 1;
    }
    write("Is something wrong?\n");
    say(cap_name + " frowns.\n");
    return 1;
}                                       
 
gasp(ob, adv) {

    if (adv) {
        write("You gasp "+ adv +".\n");
        say(cap_name+" gasps "+ adv +".\n");
        return 1;
    }
    write("You gasp in astonishment.\n");
    say(cap_name + " gasps in astonishment!\n");
    return 1;
}
 
giggle(ob, adv) {

    if (adv) {
        write("You giggle "+ adv +".\n");
        say(cap_name+" giggles "+ adv +".\n");
        return 1;
    }
    write("You giggle delightedly.\n");
    say(cap_name + " giggles delightedly.\n");
    return 1;
}
 
glare(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    tell_object(ob, cap_name+" glares"+ (adv ? " "+adv: "") +
      "at you.\n");
    write("You glare"+ (adv ? " "+adv: "") +" at "+ ob_name +".\n");
    say(cap_name+" glares"+ (adv ? " "+adv: "") +" at "+ 
      ob_name +".\n", ob);
    return 1;
}
 
grin(ob, adv) {
    string ob_name;

    if (!ob && !adv) {
        write("You grin widely.\n");
        say(cap_name + " grins widely.\n");
        return 1;
    }
    if (adv) {
        write("You grin "+ adv +".\n");
        say(cap_name+" grins "+ adv +".\n");
        return 1;
    }
    if (ob) {
        tell_object(ob, cap_name+" grins"+ (adv ? " "+adv: "") + 
          " at you.\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You grin"+ (adv ? " "+adv: "") +
      (ob ? " at "+ob_name: "") +".\n");
    say(cap_name+" grins"+ (adv ? " "+adv: "") + 
      (ob ? " at "+ob_name: "") +".\n", ob ? ob: this_object());
    return 1;
}
 
groan(ob, adv) {

    if (adv) {
        write("You groan "+ adv +".\n");
        say(cap_name+" groans "+ adv +".\n");
        return 1;
    }
    write("You groan.\n");
    say(cap_name + " groans loudly.\n");
    return 1;
}
 
grope(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    tell_object(ob, cap_name+" gropes you" +
      (adv ? " "+adv: "") +".\n");
    write("You grope "+ob_name+ (adv ? " "+adv: "") +".\n");
    say(cap_name + " gropes "+ ob_name +
      (adv ? " "+adv: "") +".\n", ob);
    return 1;
}
 
growl(ob, adv) {
    string ob_name;

    if (!ob && !adv) {
        write("You growl.\n");
        say(cap_name + " growls.\n");
        return 1;
    }
    if (ob) {
        tell_object(ob, cap_name+" growls"+ (adv ? " "+adv: "") + 
          " at you.\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You growl"+ (adv ? " "+adv: "") +
      (ob ? " at "+ob_name: "") +".\n");
    say(cap_name+" growls"+ (adv ? " "+adv: "") + 
      (ob ? " at "+ob_name: "") +".\n", ob ? ob: this_object());
    return 1;
}
 
grumble(ob, adv) {
    string ob_name;
   
    if (!ob) {
        write("You grumble " + (adv ? adv: "unhappily") + ".\n");
        say(cap_name + " grumbles " + (adv ? adv: "unhappily") + ".\n");
        return 1;
    }
    tell_object(ob, cap_name+" grumbles " + (adv ? adv: "unhappily") +
      " to you.\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You grumble "+ (adv ? adv: "unhappily") + " to " +
      ob_name +".\n");
    say(cap_name + " grumbles " + (adv ? adv: "unhappily") + " to " +
      ob_name + ".\n", ob);
    return 1;
}
guilty(ob, adv) {

    if (adv) {
        write("You look guilty "+ adv +".\n");
        say(cap_name+" looks  "+ adv +" guilty.\n");
        return 1;
    }
    write("You look guilty!\n");
    say(cap_name + " looks guilty!\n "); 
    return 1;
}

headbang(ob, adv) {
  string ob_name;
  
  if (!ob) {
    write("You headbang " + (adv ? adv: "wildly") + ".\n");
    say(cap_name + " headbangs " + (adv ? adv: "wildly") +".\n");
    return 1;
  }
    tell_object(ob, cap_name+" hits you in the head " + 
    (adv ? adv: "wildly") +".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
  write("You bang your head into " + ob_name + 
  (adv ? adv: " wildly") + ".\n");
  say(cap_name + " headbangs into " +ob_name + 
  (adv ? adv: " wildly") +".\n");
  return 1;
}

hee (ob, adv) {
  write ("You go HEE!!\n");
  say (cap_name + " goes HEE!!\n");
  return 1;
}

HEE (ob, adv) {
  write ("You do Sarak's special HEE!!\n");
  say(cap_name + " takes a deep breath and bellows\n\n"+
    "   HHHHHH      HHHHHH     EEEEEEEEEEEEEEEEEE     EEEEEEEEEEEEEEEEEE\n"+
    "   HHHHHH      HHHHHH     EEEEEEEEEEEEEEEEEE     EEEEEEEEEEEEEEEEEE\n"+
    "   HHHHHH      HHHHHH     EEEEEEEEEEEEEEEEEE     EEEEEEEEEEEEEEEEEE\n"+
    "   HHHHHH      HHHHHH     EEEEEEEEEEEEEEEEEE     EEEEEEEEEEEEEEEEEE\n"+
    "   HHHHHH      HHHHHH     EEEEEE                 EEEEEE\n"+
    "   HHHHHH      HHHHHH     EEEEEE                 EEEEEE\n"+
    "   HHHHHH      HHHHHH     EEEEEE                 EEEEEE\n"+
    "   HHHHHHHHHHHHHHHHHH     EEEEEEEEEEEEEEE        EEEEEEEEEEEEEEE\n"+
    "   HHHHHHHHHHHHHHHHHH     EEEEEEEEEEEEEEE        EEEEEEEEEEEEEEE\n"+
    "   HHHHHHHHHHHHHHHHHH     EEEEEEEEEEEEEEE        EEEEEEEEEEEEEEE\n"+
    "   HHHHHHHHHHHHHHHHHH     EEEEEEEEEEEEEEE        EEEEEEEEEEEEEEE\n"+
    "   HHHHHH      HHHHHH     EEEEEE                 EEEEEE\n"+
    "   HHHHHH      HHHHHH     EEEEEE                 EEEEEE\n"+
    "   HHHHHH      HHHHHH     EEEEEE                 EEEEEE\n"+
    "   HHHHHH      HHHHHH     EEEEEEEEEEEEEEEEEE     EEEEEEEEEEEEEEEEEE\n"+
    "   HHHHHH      HHHHHH     EEEEEEEEEEEEEEEEEE     EEEEEEEEEEEEEEEEEE\n"+
    "   HHHHHH      HHHHHH     EEEEEEEEEEEEEEEEEE     EEEEEEEEEEEEEEEEEE\n"+
    "   HHHHHH      HHHHHH     EEEEEEEEEEEEEEEEEE     EEEEEEEEEEEEEEEEEE\n");
  return 1;
}

heh (ob, adv) {
  write ("You grin and go, 'heh heh heh.'\n");
  say (cap_name + " grins and goes, 'heh heh heh.'\n");
  return 1;
}

hi5(ob, adv) {
  string ob_name;

  if (ob) {
    tell_object(ob, cap_name+" jumps "+ (adv ? adv: "madly") + 
      " into the air and gives you a high five!\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();        
  }
  write("You race " + (adv ? adv : "madly") + " around the room " + 
    (ob ? "and give "+ob_name : "giving everyone") + " a high five!\n");   
  say(cap_name + " races " + (adv ? adv : "madly") + " around the room "+
    (ob ? "and gives "+ob_name : "giving everyone") + " a high five!\n", 
    ob ? ob : this_object());
  return 1;
}

hiccup(ob, adv) {

    if (adv) {
        write("You hiccup "+ adv +".\n");
        say(cap_name+" hiccups "+ adv +".\n");
        return 1;
    }
    write("Hic!\n");
    say(cap_name + " hiccups.\n");
    return 1;
}
 
hkiss(ob, adv) {
    string ob_name;

    if (!ob) {
        write("You kiss your hand" + (adv ? " "+adv: "") + ".\n");
        say(cap_name + " kisses " + the_owner->query_possessive() +
          " hand" + (adv ? " "+adv: "") + ".\n");
        return 1;
    }
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    tell_object(ob, cap_name + " kisses your hand" +
      (adv ? " "+adv: "") +".\n");
    write("You kiss " + ob_name + "'s hand" + (adv ? " "+adv: "") +".\n");
    say(cap_name + " kisses " + ob_name + "'s hand" +
      (adv ? " "+adv: "") +".\n", ob);
    if (ob->query_frog()) {
        the_owner->frog_curse(1);
        ob->frog_curse(0);
    }
    return 1;
}

hmm(ob, adv) {
    string ob_name;
   
    if (ob) {
        write("How do you hmm someone else?\n");
        return 1;
    }
    write("You hmm " + (adv ? adv: "thoughtfully") + ".\n");
    say(cap_name + " hmms " + (adv ? adv: "thoughtfully") + ".\n");
    return 1;
}

hug(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    tell_object(ob, cap_name+" hugs you" +
      (adv ? " "+adv: "") +".\n");
    write("You hug "+ob_name+ (adv ? " "+adv: "") +".\n");
    say(cap_name+" hugs "+ob_name+(adv ? " "+adv: "") +".\n", ob);
    return 1;
}
innocent(ob, adv) {

    if (adv) {
        write("You look innocent "+ adv +".\n");
        say(cap_name+" looks  "+ adv +" innocent.\n");
        return 1;
    }
    write("You look innocent.\n");
    say(cap_name + " looks innocent.\n "); 
    return 1;
}
 
kick(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    tell_object(ob, cap_name+" kicks you" +
      (adv ? " "+adv: "") +".\n");
    write("You kick "+ob_name+ (adv ? " "+adv: "") +".\n");
    say(cap_name+" kicks "+ob_name+(adv ? " "+adv: "") +".\n", ob);
    return 1;
}
 
kiss(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    tell_object(ob, cap_name+" kisses you" +
      (adv ? " "+adv: "") +".\n");
    write("You kiss "+ob_name+ (adv ? " "+adv: "") +".\n");
    say(cap_name+" kisses "+ob_name+(adv ? " "+adv: "") +".\n", ob);
    if (ob->query_frog()) {
        this_player()->frog_curse(1);
        ob->frog_curse(0);
    }
    return 1;
}
 
knee(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    if (ob->query_male()) {
        tell_object(ob, cap_name+" hits you"+ (adv ? " "+adv: "")+  
          "with "+the_owner->query_possessive()+" knee below your belt!\n"+
          "You double over and fall to the ground, writhing in " +
          "excruciating pain,\nfeeling like you may throw up " +
          "everything you have eaten!\n");
        say(cap_name + " suddenly raises " + the_owner->query_possessive() +
          " knee, sending "+ ob_name +" to the floor, writhing in pain!\n",
          ob);
        write("You hit "+ ob_name +(adv ? " "+adv: "")+
          " with your knee.\n");
    }
    else {
        tell_object(ob, cap_name+" tries to knee you"+
          (adv ? " "+adv: "")+", without much effect.\n");
        say(cap_name+" tries to knee "+ ob_name +
          ", without much effect.\n", ob);
        write("You try to knee "+ ob_name +". Not very effective though.\n");
    }
    return 1;
}
 
lag (ob, adv) {
  if (adv) {
    write("You lag " + adv + ".\n");
    say(cap_name + " lags " + adv + ".\n");
    return 1;
  }
  write("LAAAAAAAGGG!!!\n");
  say(cap_name + " lags painflly.\n");
  return 1;
}

laugh(ob, adv) {

    if (adv) {
        write("You laugh "+ adv +".\n");
        say(cap_name+" laughs "+ adv +".\n");
        return 1;
    }
    write("You fall down laughing.\n");
    say(cap_name + " falls down laughing.\n");
    return 1;
}
 
lick(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    tell_object(ob, cap_name+" licks you" +
      (adv ? " "+adv: "") +".\n");
    write("You lick "+ ob_name + (adv ? " "+adv: "") +".\n");
    say(cap_name+" licks "+ ob_name +(adv ? " "+adv: "")+".\n", ob);
    return 1;
}
 
listen(ob, adv) {
    string ob_name;
 
    if (!ob && !adv) {
        write("You listen.\n");
        say(cap_name + " listens.\n");
        return 1;
    }    
    if (ob) {
        tell_object(ob, cap_name+" listens to you"+
          (adv ? " "+adv: "") +".\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You listen"+ (ob ? " to "+ob_name: "")+(adv ? " "+adv: "") +".\n");
    say(cap_name+" listens"+ (ob ? " to "+ob_name: "") +
      (adv ? " "+adv: "") +".\n", ob ? ob: this_object());
    return 1;
}

love(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    tell_object(ob, cap_name+" whispers to you sweet words of love.\n"); 
    write("You tell your true feelings to " + ob_name + ".\n");
    say(cap_name + " whispers softly to " + ob_name + ".\n", ob);
    return 1;
}
 
moan(ob, adv) {

    if (adv) {
        write("You moan "+ adv +".\n");
        say(cap_name+" moans "+ adv +".\n");
        return 1;
    }
    write("You start to moan.\n");
    say(cap_name + " starts moaning.\n");
    return 1;
}
 
mosh(ob, adv) {
  string ob_name;

  if (!ob) {
    write("You mosh around the room " + (adv ? adv: "madly") + ".\n");
    say(cap_name + " moshes around the room " + (adv ? adv: "madly") + ".\n");
    return 1;
  }
  tell_object(ob, cap_name+" moshes into you " +
    (adv ? adv: "madly") + ".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
  write("You mosh into " + ob_name +
  (adv ? adv: " madly") +".\n");
  say(cap_name + " moshes into" + ob_name +
  (adv ? adv: " madly") +".\n");
  return 1;
}
nibble(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    tell_object(ob, cap_name+" nibbles on your ear" +
      (adv ? " "+adv: "") +".\n");
    write("You nibble"+(adv ? " "+adv: "")+" on "+ob_name +"'s ear.\n");
    say(cap_name+" nibbles on "+ ob_name +"'s ear"+
      (adv ? " "+adv: "")+".\n", ob);
    return 1;
}
 
nod(ob, adv) {

    if (adv) {
        write("You nod "+ adv +".\n");
        say(cap_name+" nods "+ adv +".\n");
        return 1;
    }
    write("You nod your head.\n");
    say(cap_name + " nods "+the_owner->query_possessive()+ " head.\n");
    return 1;
}
 

oh(ob, adv) {

     write("You look blank and say 'oh'.\n");
    say(cap_name + " looks blank and says 'oh'.\n");
    return 1;
}
pat(ob, adv) {
    string ob_name;
 
    if (!ob && !adv) {
        write("You pat your stomach.\n");
        say(cap_name + " pats "+ this_player()->query_possessive() +
          " stomach.\n");
        return 1;
    }    
    if (ob) {
        tell_object(ob, cap_name+" pats you"+
          (adv ? " "+adv: "") +" on the head.\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You pat"+ (ob ? " "+ob_name: "") + (adv ? " "+adv: "") +
      " on the head.\n");
    say(cap_name+" pats"+ (ob ? " "+ob_name: "") +
      (adv ? " "+adv: "") +" on the head.\n", ob ? ob: this_object());
    return 1;
}

phew (ob, adv) {
  write("PHEW!!\n");
  say(cap_name + " breathes a sigh of relief.\n");
  return 1;
}

pin(ob, adv) {
  string pos, ob_name;

  if (!ob) {
    notify_fail ("You can't pin the air!\n");
    return 0;
  } 
  pos = ob->query_possessive();
  tell_object(ob, cap_name + " grabs you by the hair and " +
    (adv ? adv : "aggressively") + " pins you to the ground.\n");
  ob_name = interactive(ob) ? ob->query_name() : ob->short();
  write ("You grab " + ob_name + " by the hair and " +
    (adv ? adv : "aggressively") +" pin "+pos+" shoulders "+
    "to the ground!\n");
  say (cap_name+" grabs "+ob_name+" by the hair and " +
    (adv ? adv : "aggressively")+ " pins "+pos+" shoulders "+
    "to the ground!\n",
    ob ? ob : this_object());
  return 1;
}

pinch(ob, adv) {
    string ob_name;
   
    if (!ob) {
        write("You pinch yourself " + (adv ? adv: "sharply") + ".\n");
        say(cap_name + " pinches " + this_player()->query_objective() +
          "self " + (adv ? adv: "sharply") + ".\n");
        return 1;
    }
    tell_object(ob, cap_name+" pinches you " +
      (adv ? adv: "playfully") + ".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You pinch "+ob_name+(adv ? " "+adv: " playfully") + ".\n");
    say(cap_name + " pinches " + ob_name + (adv ? " "+adv: " playfully") +
      ".\n", ob);
    return 1;
}

point(ob, adv) {
    string ob_name;
   
    if (!ob) {
        write("You try " + (adv ? adv: "foolishly") +
          " to point in all directions at once.\n");
        say(cap_name + " tries " + (adv ? adv : "fooloshly") +
          " to point in all directions at once.\n");
        return 1;
    }
    tell_object(ob, cap_name+" points at you" + (adv ? " "+adv: "") + ".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You point at " + ob_name + (adv ? " "+adv: "") + ".\n");
    say(cap_name + " points at " + ob_name + (adv ? " "+adv: "") + ".\n", ob);
    return 1;
}

poke(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();    
    tell_object(ob, cap_name+" pokes you" +
      (adv ? " "+adv: "") +" in the ribs.\n");
    write("You poke "+ ob_name +(adv ? " "+adv: "")+
      " in the ribs.\n");
    say(cap_name+" pokes "+ ob_name + (adv ? " "+adv: "") +
      " in the ribs.\n", ob);
    return 1;
}

ponder(ob, adv) {

    if (adv) {
        write("You ponder "+ adv +".\n");
        say(cap_name+" ponders "+ adv +".\n");
        return 1;
    }
    write("You ponder the situation.\n");
    say(cap_name + " ponders the situation.\n");
    return 1;
}

pout(ob, adv) {

    if (adv) {
        write("You pout "+ adv +".\n");
        say(cap_name+" pouts "+ adv +".\n");
        return 1;
    }
    write("Ah, don't take it so hard.\n");
    say(cap_name + " pouts.\n");
    return 1;
}
 
praise(ob, adv) {
    string ob_name;
 
    if (!ob) {
        write("You would praise yourself? What a narcissist!\n");
        return 1;
    }
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    tell_object(ob, cap_name+" praises you" + (adv ? " "+adv: "") +".\n");
    write("You praise "+ ob_name + (adv ? " "+adv: "") +".\n");
    say(cap_name+" praises " + ob_name + (adv ? " "+adv: "") +".\n", ob);
    return 1;
}

pounce(ob, adv) {
  string ob_name;
  if(!ob) return 0;
  ob_name = interactive(ob) ? ob->query_name() : ob->short();
  tell_object(ob, cap_name+" pounces on you"+ (adv ? " "+adv : "") +".\n");
  write("You pounce on "+ ob_name + (adv ? " "+ adv : "") +".\n");
  say(cap_name +" pounces on "+ ob_name + (adv ? " "+ adv : "") +".\n", ob);
  return 1;
}

puke(ob, adv) {
    string ob_name;

    if(!ob && !adv) {
        write("You puke on your shoes.\n");
        say(cap_name + " doubles over and pukes.\n");
        return 1;
    }
    if (ob) {
        tell_object(ob, cap_name+" pukes"+ 
          (adv ? " "+adv+" on you": "all over you") +".\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You puke"+ (adv ? " "+adv: "") +
      (ob ? " on "+ob_name: "") +".\n");
    say(cap_name+" pukes"+ (adv ? " "+adv: "") + 
      (ob ? " on "+ob_name: "") +".\n", ob ? ob: this_object());
    return 1;
}
 
purr(ob, adv) {

    if (adv) {
        write("You purr "+ adv +".\n");
        say(cap_name+" purrs "+ adv +".\n");
        return 1;
    }
    write("MMMMEEEEEEEEOOOOOOOWWWWWWW!\n");
    say(cap_name + " purrs contentedly.\n");
    return 1;
}
 
raise(ob, adv) {
  string pos, ob_name;
  pos = this_player()->query_possessive();

  if (ob) {
    tell_object(ob, cap_name+" raises "+ pos +
      " eyebrow"+ (adv ? " "+adv: "")+ " at you.\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();        
  }
  write("You raise your eyebrow "+ (adv ? adv: "quizzically") + 
    (ob ? " at "+ob_name: "") +".\n");
  say(cap_name+" raises "+ pos + " eyebrow "+ ( adv ? adv: "quizzically") + 
    (ob ? " at "+ob_name: "") +".\n", ob ? ob: this_object());
  return 1;
}
 
rofl(ob, adv) {
  string ob_name;

  if (ob) {
    tell_object(ob, cap_name+" rolls around on the floor laughing "+ 
      (adv ? adv: "hysterically") + " at you!\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();        
  }
  write("You roll around on the floor laughing "+ 
    (adv ? adv : "hysterically") + (ob ? " at "+ob_name : "") + "!\n");   
  say(cap_name + " rolls around on the floor laughing "+
    (adv ? adv : "hysterically") + (ob ? " at "+ob_name : "") + "!\n",
    ob ? ob : this_object());
  return 1;
}

roll(ob, adv) {
    string ob_name;
   
    if (!ob) {
        write("You roll your eyes" + (adv ? " "+adv: "") + ".\n");
        say(cap_name + " rolls " + this_player()->query_possessive() +
          " eyes" + (adv ? " "+adv: "") + ".\n");
        return 1;
    }
    tell_object(ob, cap_name+" rolls "+ this_player()->query_possessive() +
      " eyes at you" + (adv ? " "+adv: "") + ".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You roll your eyes at " + ob_name + (adv ? " "+adv: "") + ".\n");
    say(cap_name + " rolls " + this_player()->query_possessive() +
      " eyes at " + ob_name + (adv ? " "+adv: "") + ".\n", ob);
    return 1;
}

ruffle(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    tell_object(ob, cap_name+" ruffles your hair"+
      (adv ? " "+adv: "") +".\n");
    write("You ruffle "+ob_name+"'s hair"+ (adv ? " "+adv: "") +".\n");
    say(cap_name+" ruffles "+ ob_name +"'s hair"+ 
      (adv ? " "+adv: "") +".\n", ob ? ob: this_object());
    return 1;
}
 
scratch(ob, adv) {

         write ("You scratch your head and say 'umm'.\n");
        say (cap_name+" scratches " + this_player()->query_possessive()+ " head and says 'umm'.\n");
        return 1;
}
 
scream(ob, adv) {

    if (adv) {
        write("You scream "+ adv +".\n");
        say(cap_name+" screams "+ adv +".\n");
        return 1;
    }
    write("ARRGGGGGGHHHHHH!!!!\n");
    say(cap_name + " screams loudly!\n");
    return 1;
}
 
shake(ob, adv) {
    string ob_name;

    if(!ob) {
        write("You shake your head"+ (adv ? " "+adv: "") +".\n");
        say(cap_name + " shakes "+the_owner->query_possessive()+" head" +
          (adv ? " "+adv: "") +".\n");
        return 1;
    }
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    tell_object(ob, cap_name+" shakes your hand"+ 
      (adv ? " "+adv: "") +".\n");
    write("You shake "+ ob_name +"'s hand"+(adv ? " "+adv: "")+".\n");
    say(cap_name+" shakes "+ ob_name +"'s hand"+ 
      (adv ? " "+adv: "") +".\n", ob);
    return 1;
}
 
shiver(ob, adv) {

    if (adv) {
        write("You shiver "+ adv +".\n");
        say(cap_name+" shivers "+ adv +".\n");
        return 1;
    }
    write("Brrrrrr!!!\n");
    say(cap_name + " shivers from the cold.\n");
    return 1;
}
 
shrug(ob, adv) {

    if (adv) {
        write("You shrug "+ adv +".\n");
        say(cap_name+" shrugs "+ adv +".\n");
        return 1;
    }
    write("You shrug.\n");
    say(cap_name + " shrugs helplessly.\n");
    return 1;
}
 
sigh(ob, adv) {

    if (adv) {
        write("You sigh "+ adv +".\n");
        say(cap_name+" sighs "+ adv +".\n");
        return 1;
    }
    write("You sigh.\n");
    say(cap_name + " sighs deeply.\n");
    return 1;
}
 
sing(ob, adv) {

    if (adv) {
        write("You sing "+ adv +".\n");
        say(cap_name+" sings "+ adv +".\n");
        return 1;
    }
    write("Oh sole mio!\n");
    say(cap_name + " sings in Italian.\n");
    return 1;
}
 
slap(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    tell_object(ob, cap_name+" slaps you"+
      (adv ? " "+adv: "") +".\n");
    write("You slap "+ob_name + (adv ? " "+adv: "") +".\n");
    say(cap_name+" slaps "+ob_name+(adv ? " "+adv: "")+".\n", ob);
    return 1;
}
 
smirk(ob, adv) {

    if (adv) {
        write("You smirk "+ adv +".\n");
        say(cap_name+" smirks "+ adv +".\n");
        return 1;
    }
    write("You smirk.\n");
    say(cap_name + " smirks.\n");
    return 1;
}
 
smile(ob, adv) {
    string ob_name;

    if(!ob && !adv) {
        write("You smile happily.\n");
        say(cap_name + " smiles happily.\n");
        return 1;
    }
    if (ob) {
        tell_object(ob, cap_name+" smiles"+ 
          (adv ? " "+adv: "") +" at you.\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You smile"+ (adv ? " "+adv: "") +
      (ob ? " at "+ob_name: "") +".\n");
    say(cap_name+" smiles"+ (adv ? " "+adv: "") + 
      (ob ? " at "+ob_name: "") +".\n", ob ? ob: this_object());
    return 1;
}
 
snap(ob, adv) {

    if (adv) {
        write("You snap your fingers "+ adv +".\n");
        say(cap_name+" snaps " + the_owner->query_possessive() +
         " " + adv + ".\n");
        return 1;
    }
    write("You snap your fingers.\n");
    say(cap_name + " snaps " + the_owner->query_possessive() +
        " fingers.\n");
    return 1;
}
 
sneer(ob, adv) {
    string ob_name;
   
    if (!ob) {
        write("You sneer " + (adv ? adv: "scornfully") + ".\n");
        say(cap_name + " sneers " + (adv ? adv: "scornfully") + ".\n");
        return 1;
    }
    tell_object(ob, cap_name+" sneers at you" + (adv ? " "+adv: "") + ".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You sneer at " + ob_name + (adv ? " "+adv: "") + ".\n");
    say(cap_name + " sneers at " + ob_name + (adv ? " "+adv: "") + ".\n", ob);
    return 1;
}

sneeze(ob, adv) {

    if (adv) {
        write("You sneeze "+ adv +".\n");
        say(cap_name+" sneezes " + adv + ".\n");
        return 1;
    }
    write("Gazundheit!\n");
    say(cap_name + " sneezes.\n");
    return 1;
}
 
snicker(ob, adv) {

    if (adv) {
        write("You snicker "+ adv +".\n");
        say(cap_name+" snickers " + adv + ".\n");
        return 1;
    }
    write("You snicker.\n");
    say(cap_name + " snickers.\n");
    return 1;
}
 
sniff(ob, adv) {

    if (adv) {
        write("You sniff "+ adv +".\n");
        say(cap_name+" sniffs " + adv + ".\n");
        return 1;
    }
    write("You sniff.\n");
    say(cap_name + " sniffs.\n");
    return 1;
}
 
snore(ob, adv) {

    if (adv) {
        write("You snore "+ adv +".\n");
        say(cap_name+" snores " + adv + ".\n");
        return 1;
    }
    write("Zzzzzzzzzz...\n");
    say(cap_name + " snores peacefully.\n");
    return 1;
}
 
snort(ob, adv) {
    string ob_name;
   
    if (!ob) {
        write("You snort " + (adv ? adv: "angrily") + ".\n");
        say(cap_name + " snorts " + (adv ? adv: "angrily") + ".\n");
        return 1;
    }
    tell_object(ob, cap_name+" snorts at you" + (adv ? " "+adv: "") + ".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You snort at " + ob_name + (adv ? " "+adv: "") + ".\n");
    say(cap_name + " snorts at " + ob_name + (adv ? " "+adv: "") + ".\n", ob);
    return 1;
}

snuggle(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    tell_object(ob, cap_name+" snuggles up to you"+
      (adv ? " "+adv: "") +".\n");
    write("You snuggle up to "+ ob_name +(adv ? " "+adv: "")+ ".\n");
    say(cap_name+" snuggles up to "+ ob_name +
      (adv ? " "+adv: "")+".\n", ob);
    return 1;
}
 
sob (ob, adv) {
  if (adv) {
    write ("You sob " + adv + ".\n"); 
    say (cap_name + "sobs " + adv+ ".\n"); 
    return 1;
  }
  write ("Poor Baby!\n");
  say(cap_name + " sobs uncontrollably.\n");
  return 1;
}

spit(ob, adv) {
    string ob_name;

    if(!ob && !adv) {
        write("You spit.\n");
        say(cap_name + " spits on the ground.\n");
        return 1;
    }
    if (ob) {
        tell_object(ob, cap_name+" spits"+ 
          (adv ? " "+adv: "") +"on you.\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You spit"+ (adv ? " "+adv: "") +
      (ob ? " on "+ob_name: "") +".\n");
    say(cap_name+" spits"+ (adv ? " "+adv: "") + 
      (ob ? " on "+ob_name: "") +".\n", ob ? ob: this_object());
    return 1;
}
 
squeeze(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    tell_object(ob, cap_name+" squeezes you"+
      (adv ? " "+adv: " fondly") +".\n");
    write("You squeeze "+ ob_name + (adv ? " "+adv: " fondly")+ ".\n");
    say(cap_name+" squeezes "+ ob_name +
      (adv ? " "+adv: " fondly") +".\n", ob);
    return 1;
}
 
squirm(ob, adv) {
  string ob_name;

  if (ob) {
    tell_object(ob, cap_name+" squirms "+ (adv ? adv: "helplessly") + 
      " to get away from you!\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();        
  }
  write("You squirm " + (adv ? adv : "helplessly") + 
    (ob ? " from "+ob_name : "") + ".\n");   
  say(cap_name + " squirms " + (adv ? adv : "helplessly") +
    (ob ? " from "+ob_name : "") + ".\n", 
    ob ? ob : this_object());
  return 1;
}

stand(ob, adv) {
  string ob_name;

  if (ob) {
    tell_object(ob, cap_name+" stands on your head "+
      (adv ? adv: "playfully") + ".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
  }
  write("You stand on " + (ob ? ob_name+"'s" : "your") +
    " head "+(adv ? adv : "playfully")+".\n");
  say(cap_name + " stands on " + (ob ? ob_name+"'s" :
    this_player()->query_possessive()) + " head " +
    (adv ? adv : "playfully")+".\n", ob ? ob : this_object());
  return 1;
}

stare(ob, adv) {
    string ob_name;

    if(!ob && !adv) {
        write("You stare into space.\n");
        say(cap_name + " stares into space.\n");
        return 1;
    }
    if (ob) {
        tell_object(ob, cap_name+" stares"+ 
          (adv ? " "+adv: "") +"at you.\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You stare"+ (adv ? " "+adv: "") +
      (ob ? " at "+ob_name: " into space") +".\n");
    say(cap_name+" stares"+ (adv ? " "+adv: "") + 
      (ob ? " at "+ob_name: " into space") +
        ".\n", ob ? ob: this_object());
    return 1;
}
 
stick(ob, adv) {
  string pos, ob_name;
  pos = this_player()->query_possessive();

  if (!ob && !adv) {
    write("NYAH NYAH!!\n");
    say(cap_name + " rudely sticks "+pos+" tongue out.\n");
    return 1;
  }
  if (ob) {
    tell_object(ob, cap_name + (adv ? " "+adv : " rudely") +" sticks "+pos+
      " tongue out at you!\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
  }
  write("You "+(adv ? adv : "rudely")+" stick your tongue out" +
    (ob ? " at "+ob_name : "") + ".\n");
  say(cap_name + (adv ? " "+adv : " rudely") +" sticks " +pos+ " toungue out"+
    (ob ? " at "+ob_name : "") + "!\n", ob ? ob : this_object());
  return 1;
}

strut(ob, adv) {

    if (adv) {
        write("You strut "+ adv +".\n");
        say(cap_name+" struts " + adv + ".\n");
        return 1;
    }
    write("Strut your stuff!\n");
    say(cap_name + " struts proudly.\n");
    return 1;
}
 
sulk(ob, adv) {

    if (adv) {
        write("You sulk "+ adv +".\n");
        say(cap_name+" sulks " + adv + ".\n");
        return 1;
    }
    write("You sulk.\n");
    say(cap_name + " sulks in the corner.\n");
    return 1;
}
 
swear (ob, adv) {
  if (adv) {
    write ("You swear " + adv + " in a dozen different languages!\n"); 
    say (cap_name + " swears " + adv+ " in a dozen different "+
    "languages!!\n");
    return 1;
  }
  write ("I BEG YOUR PARDON!!??\n");
  say(cap_name + " swears profusely in a dozen different languages!!\n");
  return 1;
}

tap(ob, adv) {

    string ob_name;

    if (!ob && !adv) {
    write("You tap your foot impatiently.\n");
    say(cap_name + " taps "+the_owner->query_possessive()+ " his foot impatiently.\n");
    return 1;
   }
    if (ob) {
        tell_object(ob, cap_name+" taps "+ the_owner->query_possessive()+" foot"+ 
          (adv ? " "+adv: "") + " at you.\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You tap your foot"+ (adv ? " "+adv: "") +
      (ob ? " at "+ob_name: "") +".\n");
    say(cap_name+" taps "+ the_owner->query_possessive()+ " foot"+ (adv ? " "+adv: "") + 
      (ob ? " at "+ob_name: "") +".\n", ob ? ob: this_object());
    return 1;

}
tackle(ob, adv) {
    string ob_name;
 
    if (!ob) {
        write("You wrestle with yourself on the ground" +
          (adv ? " "+adv: "") + ".\n");
        say(cap_name + " wrestles with "+ the_owner->query_objective() +
          "self on the ground" + (adv ? " "+adv: "") + ".\n");
        return 1;
    }    
    tell_object(ob, cap_name+" tackles you" + (adv ? " "+adv: "") +".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You tackle " + ob_name + (adv ? " "+adv: "") + ".\n");
    say(cap_name+" tackles " + ob_name + (adv ? " "+adv: "") +".\n", ob);
    return 1;
}

taunt(ob, adv) {
  string ob_name;

  if (!ob) {
    write("You taunt the room " + (adv ? adv: "childishly") + ".\n");
    say(cap_name + " taunts everyone " + (adv ? adv: "childishly") +".\n");
    return 1;
  }
    tell_object(ob, cap_name+" taunts you " +
    (adv ? adv: "childishly") +".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
  write("You taunt " + ob_name +
  (adv ? adv: " childishly") +".\n");
  say(cap_name + " taunts " + ob_name +
  (adv ? adv: " childishly") +".\n");
  return 1;
}
thank(ob, adv) {
    string ob_name;

    if (!ob)
        return 0;
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    tell_object(ob, cap_name+" thanks you" +
      (adv ? " "+adv: "") +".\n");
    write("You thank "+ ob_name + (adv ? " "+adv: "") +".\n");
    say(cap_name+" thanks "+ ob_name +
      (adv ? " "+adv: "") +".\n", ob);
    return 1;
}

think(ob, adv) {

    if (adv) {
        write("You try to think "+ adv +", but fail.\n");
        say(cap_name+" tries to think "+ adv +", but fails.\n");
        return 1;
    }
    write("You think deeply about a problem.\n");
    say(cap_name + " thinks deeply about a problem.\n"+
      capitalize(the_owner->query_possessive()) + " brow furrows up and "+
      "smoke billows from "+ the_owner->query_possessive() +" ears.\n");
    return 1;
}

tickle(ob, adv) {
    string ob_name;
   
    if (!ob) {
        write("You tickle yourself " + (adv ? adv: "mercilessly") + ".\n");
        say(cap_name + " tickles " + this_player()->query_possessive() +
          " toes " + (adv ? adv: "mercilessly") + ".\n");
        return 1;
    }
    tell_object(ob, cap_name+" tickles you " +
      (adv ? adv: "mercilessly") + ".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You tickle "+ob_name+(adv ? " "+adv: " mercilessly") + ".\n");
    say(cap_name + " tickles " + ob_name + (adv ? " "+adv: " mercilessly") +
      ".\n", ob);
    return 1;
}

tilt (ob, adv) {
  string pos, ob_name;
  pos = this_player()->query_possessive();

  if (ob) {
    tell_object(ob, cap_name+ " tilts " + pos + " head to the side and " +
    "looks at you " + (adv ? adv : "curiously") + ".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
  }
  write ("You tilt your head to the side and look " + (ob ? "at "+ob_name :
    "around") + " " + (adv ? adv : "curiously") + ".\n");
  say (cap_name +" tilts "+pos+" head to the side and looks " + 
    (ob ? "at "+ob_name : "around") + " " + 
    (adv ? adv : "curiously") + ".\n", ob ? ob : this_object());
}

tsk(ob, adv) {
  write ("You tsk.\n");
  say(cap_name + " goes, 'tsk tsk tsk.'\n");
  return 1;
}

twiddle(ob, adv) {

    if (adv) {
        write("You twiddle your thumbs "+ adv +".\n");
        say(cap_name+" twiddles "+ the_owner->query_possessive() +
          " thumbs "+ adv +".\n");
        return 1;
    }
    write("You twiddle your thumbs.\n");
    say(cap_name + " twiddles " + the_owner->query_possessive() +
        " thumbs.\n");
    return 1;
}
 
wait(ob, adv) {
    string ob_name;

    if (!ob) {
        write("You wait"+ (adv ? " "+adv: "") +".\n");
        say(cap_name + " waits"+ (adv ? " "+adv: "") +".\n");
        return 1;
    }    
    tell_object(ob, cap_name+" gives you a round of applause"+
      (adv ? " "+adv: "") +".\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You wait"+ (adv ? " "+adv: "") +" for "+ ob_name +".\n");
    say(cap_name+" waits"+ (adv ? " "+adv: "") +
      " for "+ ob_name +".\n", ob);
    return 1;
}
 
wave(ob, adv) {
    string ob_name;

    if(!ob && !adv) {
        write("You wave farewell.\n");
        say(cap_name + " waves farewell.\n");
        return 1;
    }
    if (ob) {
        tell_object(ob, cap_name+" waves farewell to you"+ 
          (adv ? " "+adv: "") +".\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You wave farewell"+ (adv ? " "+adv: "") +
      (ob ? " to "+ob_name: "") +".\n");
    say(cap_name+" waves farewell"+ (adv ? " "+adv: "") + 
      (ob ? " to "+ob_name: "") +".\n", ob ? ob: this_object());
    return 1;
}
 
whee(ob, adv){
  write("WHEEEEEEEEEEEEEEEEEE!\n");
  say (cap_name + " goes, 'WHEEEEEEEEEEEEEEEEEEEE!'\n");
  return 1;
}

whistle(ob, adv) {
    string ob_name;

    if(!ob && !adv) {
        write("You whistle appreciatively.\n");
        say(cap_name + " whistles appreciatively.\n");
        return 1;
    }
    if (ob) {
        tell_object(ob, cap_name+" whistles"+ 
          (adv ? " "+adv: "") +" at you.\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You whistle"+ (adv ? " "+adv: "") +
      (ob ? " at "+ob_name: "") +".\n");
    say(cap_name+" whistles"+ (adv ? " "+adv: "") + 
      (ob ? " at "+ob_name: "") +".\n", ob ? ob: this_object());
    return 1;
}
 
wiggle(ob, adv) {

    if (adv) {
        write("You wiggle your bottom "+ adv +".\n");
        say(cap_name+" wiggles "+ the_owner->query_possessive() +
          " bottom "+ adv +".\n");
        return 1;
    }
    write("You wiggle your bottom.\n");
    say(cap_name + " wiggles " + the_owner->query_possessive() +
        " bottom.\n");
    return 1;
}
 
wince(ob, adv) {
    string ob_name;
   
    if (!ob) {
        write("You wince " + (adv ? adv: "painfully") + ".\n");
        say(cap_name + " winces" + (adv ? adv: "painfully") + ".\n");
        return 1;
    }
    tell_object(ob, cap_name+" winces " + (adv ? adv: "painfully") +
      " before you.\n");
    ob_name = interactive(ob) ? ob->query_name(): ob->short();
    write("You wince "+ (adv ? adv: "painfully") + " before " +
      ob_name +".\n");
    say(cap_name + " winces " + (adv ? adv: "painfully") + " before " +
      ob_name + ".\n", ob);
    return 1;
}

wink(ob, adv) {
    string ob_name;

    if(!ob && !adv) {
        write("You wink.\n");
        say(cap_name + " winks suggestively.\n");
        return 1;
    }
    if (ob) {
        tell_object(ob, cap_name+" winks"+ 
          (adv ? " "+adv: "") +" at you.\n");
        ob_name = interactive(ob) ? ob->query_name(): ob->short();
    }
    write("You wink"+ (adv ? " "+adv: "") +
      (ob ? " at "+ob_name: "") +".\n");
    say(cap_name+" winks"+ (adv ? " "+adv: "") + 
      (ob ? " at "+ob_name: "") +".\n", ob ? ob: this_object());
    return 1;
}
 
yawn(ob, adv) {

    if (adv) {
        write("You yawn "+ adv +".\n");
        say(cap_name+" yawns "+ adv +".\n");
        return 1;
    }
    write("My, what big teeth you have!\n");
    say(cap_name + " yawns.\n");
    return 1;
}
