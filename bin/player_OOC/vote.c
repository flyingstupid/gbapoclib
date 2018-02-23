#define VOTE_DIR	"/ob_saves/votes/dirk/"
#define NAME		(string)this_player()->query_name(1)
#define TOPICS ({ "bob", "jo", })

int total_votes;

status vote(string str) {
  string tmp1, tmp2;

  if(file_size(VOTE_DIR+NAME+".o") > 0) {
    notify_fail("You have already placed a vote.\n");
    return 0;
  }

  if(!str) {
    notify_fail("Vote <what>?\n");
    return 0;
  }

  if(member_array(str, TOPICS) == -1) {
    notify_fail("You can't vote on that.\n");
    return 0;
  }

  write("You cast your vote to "+str+".\n");
  restore_object(VOTE_DIR+"/results/"+str);
  total_votes += 1;
  save_object(VOTE_DIR+"/results/"+ str);
  save_object(VOTE_DIR+NAME);
  return 1;
}
