#include "ScriptPCH.h"

enum NpcAtions {
NPC_RESET_NORMAL = 100,
NPC_RESET_HEROIC = 200
};

class npc_reset_instance : public CreatureScript
{
    public:
    npc_reset_instance() : CreatureScript("npc_reset_instance"){}

    bool OnGossipHello(Player* player, Creature* pCreature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface\\icons\\Spell_Holy_DevineAegis:35|t|r Reset my Instaces ID's", GOSSIP_SENDER_MAIN, NPC_RESET_NORMAL);
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*Sender*/, uint32 Action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (Action == NPC_RESET_NORMAL)
        {
            for (uint8 i = 0; i < 2; ++i)
            {
                Player::BoundInstancesMap &binds = player->GetBoundInstances(Difficulty(i));
                for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
                {
                    player->UnbindInstance(itr, Difficulty(i));
                }
            }

            ChatHandler(player->GetSession()).PSendSysMessage("Your ID's have been reseted.");

            player->PlayerTalkClass->SendCloseGossip();
        }

        return true;
    }
};

void AddSC_npc_reset_instance()
{
        new npc_reset_instance();
}
