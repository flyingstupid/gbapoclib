#ifndef _UDP_H
#define _UDP_H

/* --- User Configuration. --- */

#define INETD		"/secure/inetd"
#define UDP_CMD_DIR	"/secure/UDP_CMD_DIR/"
#define HOST_FILE	"/secure/INETD_HOSTS"

#define INETD_LOG_FILE	"INETD"
#define LOG_FILE	"INETD"

#define REPLY_TIME_OUT	12
#define RETRIES		2

#define LOCAL_NAME	"Magia"
#define MASTER		"/secure/master"
#define PLAYER		"/obj/player"

#define LOCAL_UDP_PORT	query_imp_port()



/* --- End of config. --- */

#define INETD_DIAGNOSTICS

#define INETD_VERSION	"0.7a"

/* --- Standard header macros. --- */

#define RECIPIENT	"RCPNT"
#define REQUEST		"REQ"
#define SENDER		"SND"
/* The DATA field should be used to store the main body of any packet. */
#define DATA		"DATA"

/* These headers are reserved for system use only. */
#define HOST		"HST"
#define ID		"ID"
#define NAME		"NAME"
#define PACKET		"PKT"
#define UDP_PORT	"UDP"
#define SYSTEM		"SYS"

/* Reserved headers for diagnostics. */
#define PACKET_LOSS	"PKT_LOSS"
#define RESPONSE_TIME	"TIME"

/* --- Standard REQUEST macros. --- */

#define PING		"ping"
#define QUERY		"query"
#define REPLY		"reply"

/* --- Standard SYSTEM macros. --- */

#define FAILED		"F"
#define REPEAT		"R"
#define TIME_OUT	"TO"
#define UNAVAILABLE	"U"

/* --- Index macros for host arrays. --- */

#define HOST_NAME	0
#define HOST_IP	1
#define HOST_UDP_PORT	2
#define LOCAL_COMMANDS	3
#define HOST_COMMANDS	4
#define HOST_STATUS	5

#endif

