#ifndef SHOUT_H
#define SHOUT_H

#ifndef CHANNEL_D
#define CHANNEL_D	"/functions/channel"
#endif /* CHANNEL_D */
/****************************************************************************/
/* check_shout() */


varargs void check_shout(string str, string lang) {
  int i;
  object *user;

#ifndef CHANNEL_D
  user = users();
  for(i = sizeof(user); i--;) {
    if(user[i] && this_player() != user[i]) user[i]->shout_tell(str,lang);
  }
#else
  CHANNEL_D -> chat_channel(lang, str, 1, 1);
#endif /* CHANNEL_D */
} 

#endif /* end SHOUT_H */

