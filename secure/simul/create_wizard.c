

varargs mixed create_wizard(string owner, string domain) {
    mixed result;

    result =
      (mixed)MASTER->master_create_wizard(owner, domain, previous_object());
    if(stringp(result)) return result;
    return 0;
}
