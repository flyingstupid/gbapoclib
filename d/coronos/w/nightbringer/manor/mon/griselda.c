/* GRISELDA, THE MAID */
/* Author:DarkBringer */
/* 04-23-97 */


#include <mudlib.h>
#include <ansi.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;


  set_short("Griselda, The Maid");
  set_name("griselda");
  set_alias("maid");
  set_race("elf");
  set_long(
"    Griselda is a sweat young Elvin maid who works for the Penors', in \n"+
"    return for food and board. She appears to be about 17 years old, but\n"+
"    in elvin, she is actually 68, still a child. She has long, flowing honey\n"+
"    colored hair that she wears in braids. She has a beautiful complexion,\n"+
"    blue, almond shaped eyes, and full, pouty, red lips. Many a suitor \n"+
"    from Ille Coronos and behond have offered the Penors' their life savings\n"+
"    for her hand in marriage. Griselda always refuses these offers, as she\n"+
"    is quite content to remain on as the maid for the manor. \n");


  set_gender(2);
  set_level(6);
  set_ac(5);
  set_wc(10);
  add_money(100 + random(150));
  add_class("fighter");


  load_chat(5, ({"Griselda says: I love working for the Penors'.\n",
    "Griselda asks: Are you a guest of m'ladies ?.\n",
    " Griselda Says: Lady Penor is bothered by noises in the night.\n",
    }));

  load_a_chat(5,({"Griselda says: Why you evil, evil creature you.\n",
    "Griselda bursts out into tears.\n",
    }));


  }
