#include <ansi_filter.h>

#define MAX_LEN 75

/*
 * Function: list_array(mixed)
 * Date:     January 1999, Sarak.
 * Purpose:  This function is used to list the contents of an array 
 *           array in a tabular format.  The function first determines
 *           the best column size based on the given data and then proceeds
 *           to construct the string that should be returned.
 *
 * History: 09/03/02, Sarak: Updated with fixes from the archived FDM:
 *                           Castinian lib.  This fixes the problem with
 *                           excess whitespace causing newlines to appear
 *                           on some clients.
 */

string list_array(mixed *arg) {
  int max, i, j, per_line, tot_lines;
  string *arr, tmp, complete;

  arr = ({ });

  for(i = 0; i < sizeof(arg) ; i++) {
    if(stringp(arg[i])) {
      arr += ({ arg[i], });
      if(strlen(filter_ansi(arg[i])) > max) 
        max = strlen(filter_ansi(arg[i]));
    }
  }
  per_line = MAX_LEN / (max + 2);
  if(!per_line) return 0;

  tot_lines = sizeof(arr) / per_line;
  if(sizeof(arr) % per_line) tot_lines++;

  tmp = "";
  complete = "";
  for(i = 0 ; i < tot_lines ; i++) {
    for(j = 0 ; j < per_line ; j++) {
      if(i + j * tot_lines < sizeof(arr)) {
        tmp += arr[i + j * tot_lines] +
            "                                                             ";
        tmp = ansi_extract(tmp, 0, (max + 2) * (j + 1));
      }
    }
    // Clear out trailing whitespace.  Was causing newline problems under
    // some circumstances.
/*
    while(tmp[strlen(tmp) - 1] == ' ')
      tmp = tmp[0..strlen(tmp) - 2];
    if(strlen(tmp)) complete += tmp+"\n";
*/
  complete += tmp+"\n";
    tmp = "";
  }
  return complete;
}

