#include <mudlib.h>

inherit SOUL_I;

void reset(status arg) {
  if (arg) return;
  set_default_adverb("");
  set_origin_view("A light from above shines down upon you, "+
		  "filling you with enlightenment.");
  set_target_view("A light from above shines upon $e filling "+
		  "$o with enlightenment.");
  set_other_view("A light from above shines upon $e filling "+
		 "$o with enlightenment.");
}

