#ifndef PLAYER_H
#define PLAYER_H

/* static fns */

static void heart_beat();
void add_standard_commands();
static void wiz_commands();
static void wiz_commands2();
void get_new_player_object();
static void time_out();
static status logon();
static void logon2(string str);
static void check_password(string p);
static void new_password(string p);
static void logon3();
static void logon4(string maddr);
static void logon5();
static void logon6(string gender_str);
static void logon7();
static void logon7_describe_me();
static void logon8(string str);
static void logon8_describe_me();
static void logon8_validate_race(string str);
static void logon9_log_wizard();
static void logon9(object where);
static void logon9_throw_out_other_copy(string str);
static void destruct_all_inventory(object ob);
static status wimpy(string str);
static status change_password();
static void change_password1(string str);
static void change_password2(string str);
static status suicide();
static void pass1(string str);
static void suicide_note(string arg);
static void do_suicide(string note);
static status describe();
static status get_desc(string arg);
static status skills(string str);
static status score();
static status  hp();
static status chfn();
static void chfn2(string str);
static void chfn3(string str, status plan_only);
static void chfn4(string arg);
static status change_plan();
static status fix_it(string str);
static status put(string str);
static status pick_up(string str);
static status drop_thing(string str);
static status  give_object(string str);
static status kill(string str);
static status access(string dir, string file, string mode);
static status show_mainlog();
nomask status security(int sec_level);
static int FILE_SIZE(string file);

status filter_users(object ob);
status filter_wizards(object ob);
static status by_name(object a, object b);
static status by_level(object a, object b);
static status by_age(object a, object b);
static status by_environment(object a, object b);
static status by_level(object a, object b);
static status by_ip_number(object a, object b);
status by_sec_level(object a, object b); 
status command_centre(string str);
status do_cmd(string str);
static status echo(string str);
status more(string str);

/* callable fns */

/* sets */

string set_title(string t);
string set_pretitle(string t);
string set_al_title(string t);
string set_enter_room(string str);
int set_intoxicated(int i);
int set_stuffed(int i);
int set_soaked(int i);
int set_headache(int i);
int set_scar(int i);
string set_quests(string *arr);
string set_guild_string(string s);
string set_email(string s);
string set_description(string s);
string set_plan(string s);
int set_time_to_save(int i);
status set_edit_on(status i);
status set_informed(status i);
status set_start();
status parse_pick_up(mixed *items, string prep, object ob2, string msg);
status parse_pick_up(mixed *items, string prep, object ob2, string msg);
status parse_put(mixed *items, string prep, object ob2);
string set_URL(string arg);

/* querys */

string query_realname();
string query_lastname();
string query_last_login();
string query_enter_room();
status query_edit();
status query_channel(string str);
status query_informed();
status query_prevent_shadow();
string query_email();
string query_al_title();
string query_title();
string query_desc();
int query_total_exp();
int query_intoxication();
int query_stuffed();
int query_soaked();
string query_guild_string();
object query_other_copy();
string query_URL();

/* toggles */

status toggle_brief(status silently);
status toggle_no_wimpy();
status toggle_ghost();

/*  quests */  
  
status query_quest(string str);
void add_quest(string str);
void remove_quest(string str);

/* adds */

int add_exp(int e);
int add_intoxication(int i);
int add_stuffed(int i);
int add_soaked(int i);
void add_alignment(int a);
void add_channel(string str);
void remove_channel(string str);


varargs void shout_tell(string str, string lang);
void show_scar();
status save_character();
void save_me(status value_items);
status restore_me();
status quit(mixed arg);
status Quit();
status church();
status inventory();
status examine(string str);
status look(string str, status extra);
status help(string what, string dir);
status second_life();
int drink_alcohol(int drink_strength);
status drink_soft(int drink_strength);
status eat_food(int food_strength);
nomask varargs string valid_write(string file, string call_fun);
nomask varargs string valid_read(string file, string call_fun);
status tail_file(string path);
status cat_file(string path);
status chat_channel(string channel, string msg);

nomask status secure(int sec_level);
nomask int query_security();
nomask int query_security_level();
nomask int set_security_level(int new_level);
string make_path(string file);
status pwd();
status toggle_invis();
int compute_values(object ob);
void illegal_patch(string what);
void load_auto_obj();
void compute_auto_str();

int get_alias_index(string str);
status add_alias(string str);
void remove_alias(string str);
status log_for_players(string file, string str);
status who();
status emote(string str);
status tell(string str);
status whisper(string str);
status shout_to_all(string str);
static void move_or_destruct_inventory(object arg);



status valid_file_name(string arg);
void get_party();
status toggle_hp( string str);

#endif /* PLAYER_H */
