# include <mudlib.h>
 
inherit ROOM;
 
void reset (status arg){
  if(arg) return;
 
  set_short("a dirt path\n");
  set_long(
    "This is the beginning of a dirt path that leads west to the gardens.\n"+
    "Many trees and patches of wildflowers grow along the sides of the \n"+
    "path.");
  set_day_desc(
    "  An oil lamp hangs from a lamp post next to the path.\n");
  set_night_desc(
    "  A lit oil lamp lights the way along the path.\n");
  set_items(({
    "post#lamp post",
    "This is a simple lamp post with an oil lamp hanging from it.\n",
    "gardens#garden",
    "The city garden is to the west.\n",
    "leaf#leaves", "These are the leaves of the trees.\n",
    "path#dirt path", "This is a dirt path.\n",
    "tree#trees", "These are large trees that grow next to the path.\n",
    "wildflowers#flowers#flower#patches of wildflowers",
    "These wildflowers are very colorful and pretty.\n",      
    }));
  set_day_items(({
    "lamp#oil lamp",
    "This is a simple oil lamp that hangs from a post.  It is has a metal\n"+
    "frame and glass panels.  The lamp is unlit right now.\n",
    }));
  set_night_items(({
    "lamp#oil lamp",
    "This is a simple oil lamp that hangs from a post.  It has a metal\n"+
    "frame and glass panels.  The lamp shines brightly, illuminating the\n"+
    "area.\n",
    }));
  set_smell("You smell the scent of fragrant wildflowers.\n");
  set_listen("You hear the rustle of the leaves.\n");
  set_weather(2, 4, 0);
  set_exits(({
    "/d/coronos/w/darkness/dpath2", "west",
    "/d/coronos/w/darkness/eastrd3", "east",
    }));
}
