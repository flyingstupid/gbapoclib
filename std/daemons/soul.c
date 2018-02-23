/****************************************************************************
 * Soul Daemon for the Heaven 7 mudlib.                                     *
 *                                                                          *
 * OBJECT DESCRIPTION                                                       *
 * ******************                                                       *
 *                                                                          *
 * The Soul daemon is responsible for interpreting the soul objects in      *
 * SOUL_DIR when they are called and return the appropriate strings to the  *
 * calling program.                                                         *
 *                                                                          *
 * OBJECT HISTORY                                                           *
 * **************                                                           *
 * 1998.08.09 - Object incorporated from the Castinian mudlib.              *
 *                                                                          *
 ****************************************************************************/


#include <bad_file.h>

#define SOUL_DIR "/std/souls/"


private string *spAdverbs = ({
#include <adverbs.h>;
});


private int abbr(string sString1, string sString2)
{
  if(strlen(sString1) < 4)
    return 0;
  return sString2[0..strlen(sString1) - 1] == sString1;
}
private string validate_adverb(string sAdverbToValidate)
{
  int nIndex;
  int nSize;

  for(nIndex = 0, nSize = sizeof(spAdverbs); nIndex < nSize; nIndex++)
    if(abbr(sAdverbToValidate, spAdverbs[nIndex]))
      return spAdverbs[nIndex];
  return "";
}


private string *calc_soul_string(string sSoulFile,
                                 object oTarget, string sAdverb)
{
  string *spFormatStrings;
  string *spOutputs;
  string sTempOutput;
  string sBegin, sMid, sEnd;
  string sFormatString;
  string sToken;
  string *spTargetOptions;
  int nIndex;
  int nLength;

  spOutputs = allocate(3);

  spFormatStrings = allocate(3);
  spFormatStrings[0] = sSoulFile -> query_origin_view();
  spFormatStrings[1] = sSoulFile -> query_target_view();
  spFormatStrings[2] = sSoulFile -> query_other_view();

  for(nIndex = 0; nIndex < 3; nIndex++)
  {
    sTempOutput = "";
    sFormatString = spFormatStrings[nIndex];

    if(!sFormatString || sFormatString == "")
      continue;

    while(sscanf(sFormatString, "%s$[%s$]%s", sBegin, sMid, sEnd) == 3)
    {
      string sTemp1, sTemp2;

      spTargetOptions = (sscanf(sMid, "%s|%s", sTemp1, sTemp2) == 2)
        ? explode(sMid, "|")
        : 0;

      if(oTarget && oTarget != this_player())
        sFormatString = sBegin +
          ((spTargetOptions) ? spTargetOptions[0] : sMid) + sEnd;
      else
        sFormatString = sBegin +
          ((spTargetOptions) ? spTargetOptions[1] : "") + sEnd;
    }

    while(sscanf(sFormatString, "%s$%s", sBegin, sFormatString))
    {
      sTempOutput += sBegin;
      sToken = lower_case(sFormatString[0..0]);
      sFormatString = sFormatString[1..];

      switch(sToken)
      {
        case "a": //Insert given adverb
          sTempOutput += (sAdverb) ? sAdverb : "";

          if(!sAdverb || sAdverb == "")
            if(sFormatString[0] == ' ')
              sFormatString = sFormatString[1..];

          break;

        case "t": //Insert target's name (if any).
          sTempOutput += oTarget -> query_cap_name();
          break;

        case "e": //Insert executor's name
          sTempOutput += this_player() -> query_cap_name();
          break;

        case "s": //Insert subjective form of executor
          sTempOutput += this_player() -> query_pronoun();
          break;

        case "o": //Insert objective form of executor
          sTempOutput += this_player() -> query_objective();
          break;

        case "p": //Insert possessive form of executor
          sTempOutput += this_player() -> query_possessive();
          break;
        default:
          throw("Unknown token in soul");
      }
    }

    sTempOutput += sFormatString;
    nLength = strlen(sTempOutput);

    if(sTempOutput[nLength-2..nLength-2] == " ")
      sTempOutput = sTempOutput[0..nLength-3] +
        sTempOutput[nLength-1..nLength-1];

    spOutputs[nIndex] = sTempOutput;
  }
  return spOutputs;
}


varargs mixed do_soul(string sSoulName, string sArgs, int nChannel)
{
  object oTarget;
  string sAdverb;
  string *spOutputs;
  string *spWords;
  string sSoulFile;

  sSoulName = lower_case(sSoulName);

  sSoulFile = sprintf("%s_%s.c", SOUL_DIR, sSoulName);

  if(bad_file(sSoulFile)) return 0;
  if(catch(file_size(sSoulFile) < 0) || file_size(sSoulFile) < 0)
    return 0;

  if(sArgs && sArgs != "")
  {
    spWords = explode(sArgs, " ");

    switch(sizeof(spWords))
    {
      case 1:
        spWords[0] = lower_case(spWords[0]);

        oTarget = find_player(spWords[0]);
        if(!oTarget) oTarget = present(spWords[0], environment(this_player()));
        if(!oTarget)
            sAdverb = validate_adverb(spWords[0]);
        else
          if((!nChannel && environment(oTarget) != environment(this_player()))
            || (oTarget->query_npc() && nChannel) || !living(oTarget))
          {
            oTarget = 0;
            sAdverb = validate_adverb(spWords[0]);
          }  

        break;

      case 2:
        spWords[0] = lower_case(spWords[0]);
        spWords[1] = lower_case(spWords[1]);

        oTarget = find_player(spWords[0]);
        if(!oTarget) oTarget = present(spWords[0], environment(this_player()));
        if(!oTarget)
        {
          oTarget = find_player(spWords[1]);
          if(!oTarget) oTarget = find_living(spWords[1]);
          if(!oTarget)
            sAdverb = validate_adverb(spWords[0]);
          else
          {
            if((!nChannel && environment(oTarget) != environment(this_player()))
              || (oTarget->query_npc() && nChannel))
                oTarget = 0;

            sAdverb = validate_adverb(spWords[0]);
          }
        }
        else
          if((!nChannel && environment(oTarget) != environment(this_player()))
            || (oTarget->query_npc() && nChannel))
          {
            oTarget = 0;
            sAdverb = validate_adverb(spWords[0]);
          }
          else
            sAdverb = validate_adverb(spWords[1]);
    }
  }

  if(sSoulFile -> query_adverb_required()) {
  if(!sAdverb || sAdverb == "")
    sAdverb = sSoulFile -> query_default_adverb();
  if(!sAdverb || sAdverb == "")
    sAdverb = spAdverbs[random(sizeof(spAdverbs))];
  }

  spOutputs = calc_soul_string(sSoulFile, oTarget, sAdverb);

  if(nChannel)
    return spOutputs;
  else
  {
    write(spOutputs[0] + "\n");

    if(oTarget && oTarget != this_player())
      tell_object(oTarget, spOutputs[1] + "\n");

    tell_room(environment(this_player()), spOutputs[2] + "\n",
      ({ this_player(), oTarget, }));

    return 1;
  }

  return 0;
}
