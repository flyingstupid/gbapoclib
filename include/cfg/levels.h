#ifndef LEVELS_H
#define LEVELS_H

/*** security levels ***/ 
 
#define SEC0 0        /*  player                                      */
#define SEC1 10       /*  aspirant   - 1st make 'wiz'                 */
#define SEC2 20       /*  apprentice - 'wiz powers, no privleges      */
#define SEC3 30       /*  creator    - 'full wiz',  open area         */
#define SEC4 40       /*  sage       -                                */
#define SEC5 50       /*  lord       - of a domain (mud theme)        */
#define SEC6 60       /*  senior     - start of admin level, sponsor  */ 
#define SEC7 70       /*  elder      - area checking and approving    */ 
#define SEC8 80       /*  arch       - whole mudlib working           */ 
#define SEC9 90       /*  admin      - policy making, mud control     */ 
#define SEC10 100     /* found of Heaven7 (H7) is Angel and Zilanthius */

/****************************************************************/
/* optional QCs full read access, except private, write access  */
/* according to security level                                  */

#define QC ({ "none", }) /* array of creator's names on QC duty */

/****************************************************************/
/* optional SCs have write access to the soul function object   */

#define SC ({ "none", })

#endif /* LEVELS_H */
