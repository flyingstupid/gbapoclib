#ifndef BARD_H
#define BARD_H

#define HEAL_BARD_PERIOD (15 - query_intelligence()/6)
/* about 1/4 faster than mages ..who have 20 - int/6  */


/*** Bard ***/

int song;		/* magical song ability     */
int song_points;        /* points for song magic    */
int linguistics;	/* lore/languages knowledge */
int history;		/* lore/history ability     */

mapping bard_info;	/* misc info for bard stuff */



/********************************************************************/
/* sets */

int set_song(int i)	   { return song = i;        }
int set_linguistics(int i) { return linguistics = i; }
int set_history(int i)	   { return history = i;     }




/***************************************************************/
/* query */


int query_song_points() { return song_points; }
int query_song()        { return song;        }
int query_linguistics() { return linguistics; }
int query_history()     { return history;     }
int query_history_points() { return 1000;     }
/* used as dummy points */

status query_language_attempted(string str) {
  string *languages_attempted;
  languages_attempted = bard_info["linguistics"];  
  return (member_array(str, languages_attempted) == -1) ? 0 : 1;
}



/***************************************************************/
/* adjusts */

int adj_song_points(int i)   { 
  song_points = song_points + i;
  if(song_points > song * 2)  song_points = song * 2;
  if(song_points < 0) song_points = 0;
  return song_points;
}

void adj_all_bard(int i) {
  adj_song_points(i);
  if(!bard_info) bard_info = ([ ]);
  if(!random(10)) bard_info["linguistics"] = 0; /* clear it */
}


/***************************************************************/
/* temp things */

void add_languages_attempted(string str) {
  string *languages_attempted;
  languages_attempted = bard_info["linguistics"];
  if(!languages_attempted || sizeof(languages_attempted))
    languages_attempted = ({ });

  if(!this_object()->query_languagges_attempted(str))
    languages_attempted += ({ str, });
  bard_info["linguistics"] = languages_attempted;
}
  
void clear_bard() {
  song = 0; linguistics = 0; history = 0;
  this_object() -> set_two_weapon(0);
  this_object() -> set_steal(0);
  this_object() -> set_appraisal(0);
  bard_info = ([ ]);
}

void heal_bard(int arg) {
  if(random(HEAL_BARD_PERIOD)) return;
  if(arg == 0) arg = 1;
  adj_all_bard(arg);
}


void query_bard_stats() {
  string str;

  write("\n         -=[ Bard Skills ]=-\n\n");
  str = " History: "+history+"                                ";
  str = extract(str,0,20);
  str += " Linguistics: "+linguistics+"                       ";
  str = extract(str,0,40);
  str += " Song: "+song+"("+song_points+" pts)                ";
  str = extract(str,0,60);
  write(str +"\n");

  str = " Steal: "+this_object()->query_steal()+"             ";
  str = extract(str,0, 20);
  str += " Two weapon: "+this_object()->query_two_weapon()+"        ";
  str = extract(str,0,40);
  str += " Appraisal: "+this_object()->query_appraisal()+"    ";
  str = extract(str,0,60);

  write(str +"\n");
}


mapping query_bard_info() { return bard_info; }

#endif /* BARD_H */
