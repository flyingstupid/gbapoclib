/* VALID PSI POWERS *
 * When you add a power to the psi bin, you must also make sure that
 * you add it here, and whether or not it is a science or devotion.
 */

#define SCIENCE  3
#define DEVOTION 1

varargs valid_power(string power, status discipline) {
  mapping powers;
  mixed *tmp;

  powers = ([
        /* telepathic skills */
        "mind thrust"  :   ({ DEVOTION, "telapathic", }),
        "id insinuation" : ({ DEVOTION, "telepathic", }),
        "ego whip" :       ({ DEVOTION, "telepathic", }),
	"suggest" : 	   ({ DEVOTION, "telepathic", }),

	"charm animal" :   ({ DEVOTION, "telepathic", }),
	"charm person" :   ({ DEVOTION, "telepathic", }),
	"charm monster":   ({ DEVOTION, "telepathic", }),


        /* psychoportive skills */
        "teleport": ({ SCIENCE, "psychoportive", }),
	"warp":     ({ SCIENCE, "psychoportive", }),

        /* psychokinetic skills */
        "disintegrate": ({ SCIENCE, "psychokinetic", }),

        /* psychometabolic skills */
        "body weaponry": ({ DEVOTION, "psychometabolic", }),
	"contagion":     ({ DEVOTION, "psychometabolic", }),
	"energy drain":  ({ SCIENCE,  "psychometabolic", }),
	"enlarge":       ({ DEVOTION, "psychometabolic", }),
	"stoneskin":	 ({ DEVOTION, "psychometabolic", }),
	"strength":      ({ DEVOTION, "psychometabolic", }),
	"vampiric touch":({ SCIENCE,  "psychometabolic", }),


        /* clairsentience skills */
        "object reading": ({ DEVOTION, "clairsentient", }),
	"scry" :           ({ DEVOTION, "clairsentient", }),

  ]);

  tmp = powers[power];
  if(!tmp) return 0;
  return (discipline) ? tmp[1] : tmp[0];
}

