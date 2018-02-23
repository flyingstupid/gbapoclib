#include <mudlib.h>
#include <ranadd.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;
    set_weather(1,1,5);
    set_short("A dense forest");
    set_long(
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"+
      "Thick undergrowth competes with a dense copse of trees for a \n"+
      "shaky foothold in the life giving, yet rocky soil. Gnarled \n"+
      "roots creep along the ground, ready to trip the unwary. The \n"+
      "shoreline bends to the west and the north. A faint roaring \n"+
      "sound can be heard coming from the distant northeast.\n"+
      "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    );
    set_listen("The crashing of waves against the cliffs below masks a loud\n"+
      "roaring from somewhere to the northeast.\n");
    set_exits(({
      FOREST_ROOMS+"for44", "north",
      FOREST_ROOMS+"for38", "west"
    }));
    set_items(({
      "undergrowth#scrub#shrubbery",
        "Ground level plants spread out across the forest floor.\n",
      "copse",
        "A thick cluster of trees.\n",
      "trees",
        "Tall trees populate the forest of Lonell.\n",
      "coast#coastline#coast line#shore#shoreline#shore line",
        "The coast of the island lays some twenty-five feet above sea level,\n"+
        "at the top of the cliffs that surround the island.\n",
      "soil",
        "The soil is very rocky and inhospitable. It is a wonder that plant life\n"+
        "at all.\n",
      "roots",
        "The misshapen roots of several trees rise out of the ground, stretching\n"+
        "across its surface haphazardly. It seems a wonder that they remain erect.\n",
    }));
}
