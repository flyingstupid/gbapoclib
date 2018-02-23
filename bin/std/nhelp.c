/*
 * File:    /bin/std/help.c
 $ Date:    January 1999, Sarak.
 * Purpose: The essential help command provides information about commands,
 *          gameplay, rules, creator information and anything else we can
 *          think of.  This command provides a front end to the help daemon
 *          which does most of the work for the help system.
 *
 *          It interfaces with the help daemon which does most of the work.
 *
 * History: 09/03/02, Sarak: Converted from the Archived FDM: Castinian lib
 *                           to work properly with the updated help daemon.
 */
#include <mudlib.h>

inherit M_TEMP_VAR;

#include <help.cfg>

status nhelp(string arg) {
  int i;              // Loop Counter.
  string *arr;        // Used in analyzing the file names of multiple topics.
  string *help_data;  // The data returned from the help daemon.
  string tmp;         // Used in analyzing the file names of multiple topics.
  object pager_ob;

  // If no arguments are supplied, we use the default topic.
  if(!arg) {
    tmp = HELP_D->disp_topic(HELP_DIR+DEFAULT);
    write(tmp);
    return 1;
  }

  // We call the help daemon.  If nothing is returned, then the
  // requested topic does not exist.
  if(!(help_data = HELP_D->help_string(arg))) {
    notify_fail("No help on that topic.\n");
    return 0;
  }

  // If more than one element is in the array, then that means we have
  // found multiple topics with the same name.  We request which one the
  // player wants.
  if(sizeof(help_data) > 1) {


    set_temp(this_player(), "help_str", help_data);
    write("The following topics are available :-\n\n");

    // We loop through each topic and display it.
    for(i = 0 ; i < sizeof(help_data) ; i++) {

      // We convert the special charcters used in the file/topic names.
      help_data[i] = implode(explode(help_data[i], "-"), " ");
      help_data[i] = implode(explode(help_data[i], "  "), "-");


      // Display the found topics.
      write((i + 1) + ".  ");
      if(sscanf(help_data[i], "%s" + DEFAULT, tmp) == 1) {
        arr = explode(tmp, "/");
        write(capitalize(arr[sizeof(arr) - 1]) + " Category Help.\n");
      } else if(sscanf(help_data[i], "%s" + FILE_EXT, tmp) == 1) {
        arr = explode(tmp, "/");
        write(capitalize(arr[sizeof(arr) - 1]) + " in the " +
          capitalize(arr[sizeof(arr) - 2]) + " Category Help.\n");
      } else
        // This should never happen - unless the help daemon goes pear shaped.
        write("Error receiving data!\n");
    }

    // Send the control back to the player after asking the question.
    write("\nPlease select one of the above topics (1 - " +
        sizeof(help_data) + ") :- ");
    input_to("request_option");
    return 1;
  } else {

    // Otherwise, we page the first element to the player.
    pager_ob = clone_object(PAGER);
    move_object(pager_ob, this_player());
    pager_ob->page(help_data[0]);
    return 1;
  }
}

/*
 * Function: request_option
 * Purpose : This function handles the response from the player once
 *           they have been asked to select from multiple help topics.
 */
void request_option(string arg) {
  int i; // The response from the player.
  string *help_data; // The data received back from the help daemon.
  string *tmp_arr; // The temporary data from the player.
  object pager_ob;

  // Send a new line to make it look a little neater.
  write("\n");

  // Make sure an argument was sent.
  if(!arg) {
    write("Invalid option. Exiting help.\n");
    set_temp(this_player(), "help_str", 0);
    return;
  }

  // Retrieve the temporary data from the player object.
  tmp_arr = query_temp(this_player(), "help_str");

  // Make sure the data is still there.  If not, report an error and
  // exit.
  if(!tmp_arr || !sizeof(tmp_arr)) {
    write("Internal Mapping Error. Exiting help.\n");
    return;
  }

  // Determine the number specified, and check its integrity.
  sscanf(arg, "%d", i);
  if(!i || i > sizeof(tmp_arr)) {
    write("Invalid option. Exiting help.\n");
    set_temp(this_player(), "help_str", 0);
    return;
  }

  // Decrease i to get the real value and call the help daemon for the
  // help file.
  i--;
  if(!(help_data = HELP_D->help_string(tmp_arr[i], 1)) || !sizeof(help_data)) {
    write("Help data has changed. Exiting help.\n");
    set_temp(this_player(), "help_str", 0);
    return;
  }

  // Clear the temporary data variable and send the data to the pager.
  set_temp(this_player(), "help_str", 0);
  pager_ob = clone_object(PAGER);
  move_object(pager_ob, this_player());
  pager_ob->page(help_data[0]);
  return;
}
