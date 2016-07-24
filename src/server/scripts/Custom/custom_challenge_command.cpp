/* ScriptData
Name: Challenge Arena
%Complete: 100
Comment: Script for events: challenge arena 1v1 2v2 3v3 5v5.
Category: Custom Script
Author: SymbolixDEV
EndScriptData */

#include "ScriptPCH.h"
#include "Group.h"

class challenge_commandscript : public CommandScript
{
public:
    challenge_commandscript() : CommandScript("challenge_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand challengeCommandTable[] =
        {            
            { "1x1",            SEC_MODERATOR,      false, &HandleSkirmish1x1Command,       "", NULL },
            { "2x2",            SEC_MODERATOR,      false, &HandleSkirmish2x2Command,       "", NULL },
            { "3x3",            SEC_MODERATOR,      false, &HandleSkirmish3x3Command,       "", NULL },
            { "player",         SEC_MODERATOR,      false, &HandleSkirmishPlaCommand,       "", NULL },
            { NULL,             0,                  false, NULL,                            "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "challenge",      SEC_MODERATOR,      false, NULL,                     "", challengeCommandTable },
            { NULL,             0,                  false, NULL,                     "",                 NULL }
        };
        return commandTable;
    }

    static bool CreateSkirmish(ChatHandler* handler, char* args, uint8 type, bool isGroup, bool isGM)
    {
        char* pParam1 = strtok(args, " ");
        Player *player1, *player2;
        
        if (!pParam1)
            return false;

        if (isGM)
        {
            char* pParam2 = strtok(NULL, " ");
            if (!pParam2)
                return false;

            if (!handler->extractPlayerTarget(pParam2, &player2))
                return false;
        }
        else
            player2 = handler->GetSession()->GetPlayer();

        if (!handler->extractPlayerTarget(pParam1, &player1))
            return false;

        if (isGroup) // 1v1
        {
            Group *gr1 = player1->GetGroup();
            Group *gr2 = player2->GetGroup();

            if (!gr1)
            {
                handler->PSendSysMessage("First player haven`t group.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (!gr2)
            {
                handler->PSendSysMessage("Second player haven`t group.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (!gr1->IsLeader(player1->GetGUID()))
            {
                handler->PSendSysMessage("First player isn`t leader.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (!gr2->IsLeader(player2->GetGUID()))
            {
                handler->PSendSysMessage("Second player isn`t leader.");
                handler->SetSentErrorMessage(true);
                return false;
            }
        }
        
        if (player1->IsInCombat() || player2->IsInCombat())
        {
            handler->PSendSysMessage("ERROR: You or Oponnent is in Combat.");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (player1->GetMap()->IsBattlegroundOrArena() || player2->GetMap()->IsBattlegroundOrArena())
        {
            handler->PSendSysMessage("ERROR: You or Oponnent is in Battleground.");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (player1->InBattlegroundQueue() || player2->InBattlegroundQueue())
        {
            handler->PSendSysMessage("ERROR: You or Oponnent is in Arena Queue.");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (player1->GetGUID() == player2->GetGUID())
        {
            handler->PSendSysMessage("ERROR: You can't challenge self.");
            handler->SetSentErrorMessage(true);
            return false;
        }
        
        WorldPacket data1(CMSG_BATTLEMASTER_JOIN_ARENA, 8+1+1+1);
        data1 << uint64(0);
        data1 << uint8(type);
        if (isGroup) 
            data1 << uint8(1);
        else
            data1 << uint8(0);
            
        data1 << uint8(0);

        WorldPacket data2(CMSG_BATTLEMASTER_JOIN_ARENA, 8+1+1+1);
        data2 << uint64(0);
        data2 << uint8(type);
        if (isGroup) 
            data2 << uint8(1);
        else
            data2 << uint8(0);
        data2 << uint8(0);

        ArenaType aType;

        switch (type)
        {
            case 0:
                aType = ARENA_TYPE_2v2;
                break;
            case 1:
                aType = ARENA_TYPE_3v3;
                break;
            case 2:
                aType = ARENA_TYPE_5v5;
                break;
            default:
                //sLog->outError("Unknown arena slot %u at CreateSkirmish", type);
                return false;
        }

        player1->setSkirmishStatus(aType, SKIRMISH_PREPEAR);
        player2->setSkirmishStatus(aType, SKIRMISH_PREPEAR);
        player1->GetSession()->HandleBattlemasterJoinArena(data1);
        player2->GetSession()->HandleBattlemasterJoinArena(data2);

        if (player1->getSkirmishStatus(aType) != SKIRMISH_JOINED)
        {
            player1->setSkirmishStatus(aType, SKIRMISH_NONE);
            handler->PSendSysMessage("ERROR: There are some problems when try to join first team.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player2->getSkirmishStatus(aType) != SKIRMISH_JOINED)
        {
            player2->setSkirmishStatus(aType, SKIRMISH_NONE);
            handler->PSendSysMessage("ERROR: There are some problems when try to join second team.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        return true;
    }

    static bool HandleSkirmish2x2Command(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return CreateSkirmish(handler, (char*)args, 0, true, true);
    }

    static bool HandleSkirmish3x3Command(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return CreateSkirmish(handler, (char*)args, 1,  true, true);
    }
    
    static bool HandleSkirmish1x1Command(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return CreateSkirmish(handler, (char*)args, 2,  false, true);
    }

    static bool HandleSkirmishPlaCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        return CreateSkirmish(handler, (char*)args, 2,  false, false);
    }

};

void AddSC_challenge_commandscript()
{
    new challenge_commandscript();
}