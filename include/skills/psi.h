
#ifndef PSI_H
#define PSI_H
#define HEAL_PSI_PERIOD (30 - (query_intelligence()/3))

/*** Psionicist ***/



int clairsentient;          /* sensory effecting powers   */
int psychokinetic;          /* object effecting powers    */
int psychometabolic;        /* body effecting powers      */
int psychoportive;          /* space effecting powers     */
int telepathic;             /* thought effecting powers   */

int psionic_points;         /* current psionic points     */
int max_psionic_points;     /* maximum psionic points     */

int psi_skill_points;       /* how many skill pts you got */
int max_psi_skill_points;   /* total psi pts to spend     */
string *psi_skills;         /* skills psi can use         */
mapping psi_skills_list;    /* just a list for the score  */





/***             Psionicist             ***/ 

int query_psionic_points()     { return psionic_points;     }
int query_psp()                { return psionic_points;     }

int query_max_psionic_points() { return max_psionic_points; }
int query_max_psp()            { return max_psionic_points; }

int adj_psionic_points(int i) {
  psionic_points = psionic_points + i;
  if(psionic_points > max_psionic_points)
    psionic_points = max_psionic_points;
  return psionic_points;
}


void heal_psionicist(int arg) {
  if(random(HEAL_PSI_PERIOD)) return;
  if(arg == 0) arg = 6;
  adj_psionic_points(arg);
}

int query_clairsentient()     { return clairsentient;   }
int query_psychokinetic()     { return psychokinetic;   }
int query_psychometabolic()   { return psychometabolic; }
int query_psychoportive()     { return psychoportive;   }
int query_telepathic()        { return telepathic;      }

int query_psi_skill_points()       { return psi_skill_points;    }
int query_max_psi_skill_points() { return max_psi_skill_points;  }

int adj_clairsentient_points(int i)  { return adj_psionic_points(i); }
int adj_psychokinetic_points(int i)  { return adj_psionic_points(i); }
int adj_psychometabolic_points(int i){ return adj_psionic_points(i); }
int adj_psychoportive_points(int i)  { return adj_psionic_points(i); }
int adj_telepathic_points(int i)     { return adj_psionic_points(i); }


int adj_psi_skill_points(int i)    { return psi_skill_points += i;    }
int set_max_psi_skill_points(int i){ return max_psi_skill_points = i; }


int query_clairsentient_points()  { return query_psionic_points();  }
int query_psychokinetic_points()  { return query_psionic_points();  }
int query_psychometabolic_points(){ return query_psionic_points();  }
int query_psychoportive_points()  { return query_psionic_points();  }
int query_telepathic_points()     { return query_psionic_points();  }


status query_psi_skills(string str)   {
  return (member_array(str, psi_skills) != -1) ? 1 : 0;
}

string *query_all_psi_skills() {
  if(!sizeof(psi_skills)) {
    psi_skills = ({ });
    psi_skills_list = ([ ]);
  }
  return psi_skills;
}

mapping query_all_psi_skills_list() {
  if(!sizeof(psi_skills_list)) psi_skills_list = ([ ]);
  return psi_skills_list;
}


void add_psi_skills(string str) {
  string tmp1;
  mixed *tmp2;
  if(!query_psi_skills(str)) psi_skills += ({ str, });
  tmp1 = (string)"/bin/skills/classes/psionicist/valid"->valid_power(str,1);
  tmp2 = psi_skills_list[tmp1];
  if(!tmp2) tmp2 = ({ });
  tmp2 += ({ capitalize(str), });
  psi_skills_list[tmp1] = tmp2;
}

void set_psi_skills(string *arr) {
  int i;
  psi_skills = (arr) ? arr : ({});
  psi_skills_list = ([ ]);
  for(i=0; i<sizeof(arr); i++) {
    add_psi_skills(arr[i]);
  }
}

void set_max_psp() {
  max_psionic_points += clairsentient + psychokinetic + psychometabolic;
  max_psionic_points += psychoportive + telepathic;
  max_psionic_points = 2 * max_psionic_points;
}

int set_clairsentient(int i) {
  clairsentient = i;
  set_max_psp();
  return clairsentient;
}

int set_psychokinetic(int i) { 
  psychokinetic = i;
  set_max_psp();
  return psychokinetic;
}

int set_psychometabolic(int i) { 
  psychometabolic = i;
  set_max_psp();
  return psychometabolic;
}

int set_psychoportive(int i) { 
  psychoportive = i;
  set_max_psp();
  return psychoportive;
}

int set_telepathic(int i) {
  telepathic = i;
  set_max_psp();
  return telepathic;
}


void clear_psionicist() {
  clairsentient = 0;  psychokinetic = 0; psychometabolic = 0;
  psychoportive  = 0;  telepathic = 0; 
  psionic_points = 0; max_psionic_points = 0;
  psi_skill_points = 0; max_psi_skill_points = 0;
  psi_skills = 0; psi_skills_list = 0;
}

void query_psionicist_stats() {
  int i, j;
  string str;
  mixed *keys, *values;

  str = "\n         -=[ Psionicist Disciplines ]=-\n\n";
  write(str);
  str = " Clairsentient: "+clairsentient+"                   ";
  str = extract(str,0,25);
  str += " Psychokinetic: "+psychokinetic+"                      ";
  str = extract(str,0,50);
  str += " Psychometabolic: "+psychometabolic+"                 ";
  str = extract(str,0,75);
  write(str +"\n");

  str = " Psychoportive: "+psychoportive+"                       ";
  str = extract(str,0,25);
  str += " Telepathic: "+telepathic+"                           ";
  str = extract(str,0,50);
  str = extract(str,0,75);
  write(str +"\n");

  str = " Psionic Points: "+psionic_points+"("+ max_psionic_points+")      ";
  str += "                                          ";
  str = extract(str,0,25);

  str += " (Pts to spend on new powers: "+psi_skill_points+")              "+
         "                                                                 ";
  str = extract(str,0,75);
  write(str+"\n");

  write(" Psionic Powers Known: ");

  if(!sizeof(psi_skills_list))  {
    write("None. \n");
    return;
  }
  keys = m_indices(psi_skills_list);
  values = m_values(psi_skills_list);

  str = "";
  for(i=0; i<sizeof(keys); i++) {
    write("\n\t"+ capitalize(keys[i]) +"\n");
    write(" ");
    for(j=0; j<sizeof(values[i]); j++) {
      str += values[i][j]+", ";
    }
    write(str);
    str = "";
  }
  write("\n");
}


#endif /* PSI_H */


