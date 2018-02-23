
/*
 * $Author: phaedrus $
 * $Revision: 1.1 $
 * $Date: 2003/11/21 22:08:30 $
 * 
 * Purpose:
 * 
 */
 
#include <socket.h>

int netstat(string str) {
  if(!str) return SOCKETD->netstat();
     return SOCKETD->netstat(str);
  }

