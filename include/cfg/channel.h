/* This is only really for InterMud stuff */
#ifndef _CHANNEL_H
#define _CHANNEL_H

#include <levels.h>

#define CHANNELD	"/function/channel"

#define CHANNEL		"channel"
#define COMMAND		"cmd"

#define C_INTERMUD	1
#define C_RECEIVE_ONLY	2

#define CHANNELS \
([ \
"notify":	({	1,	2,	1	}), \
"god":	({	2,	0,	ADMIN	}), \
"intermud":	({	16,	1,	0	}), \
"interadmin":	({	64,	1,	ADMIN	}), \
])
    
#define ISCHANNEL(x)		CHANNELS[x]
#define CHANNEL_MASK(x)	CHANNELS[x][0]
#define CHANNEL_TYPE(x)	CHANNELS[x][1]
#define CHANNEL_LEVEL(x)	CHANNELS[x][2]

#endif /* _CHANNEL_H */

