/*
Script author: SymbolixDEV
*/
#include "ScriptPCH.h"
#include "ScriptMgr.h"

 
class npc_morph : public CreatureScript
{
public:
    npc_morph() : CreatureScript("npc_morph") { }
 
    bool OnGossipHello(Player* morpher, Creature* creature)
    {
        if (morpher->IsInCombat())
			if (morpher->IsInFlight())
        {
            morpher->GetSession()->SendNotification("You are in Combat or on Flight");
            return true;
        }
		morpher->GetSession()->SendNotification("Welcome to Morph NPC!");
		morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff Gnome - Male", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+12);
        morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff Gnome - Female", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+13);
        morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff Human - Male", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+14);
        morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff Human - Female", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+15);
		morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff Tauren - Male", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+16);
        morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff Tauren - Female", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+17);
		morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff Blood Elf - Male", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+18);
        morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff Blood Elf - Female", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+20);
		morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff Night Elf - Male", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+21);
		morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff Night Elf - Female", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+22);
		morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff Dwarf - Male", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+23);
		morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff ORC [WARLOCK] - Male", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+24);
		morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff ORC [WARLOCK] - Female", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+25);
        morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff Pirate - Male", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+19);
        morpher->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|cff0000ff Remove my morph", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+30);
		morpher->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
        return true;
	}
    bool OnGossipSelect(Player* morpher, Creature* creature, uint32 sender, uint32  actions)
    {
        morpher->PlayerTalkClass->ClearMenus();
 
        if (sender != GOSSIP_SENDER_MAIN || actions <= GOSSIP_ACTION_INFO_DEF)
        {
            morpher->CLOSE_GOSSIP_MENU();
            return true;
        }
 
        switch (sender,actions)
        {

	    case GOSSIP_ACTION_INFO_DEF+12://Gnome - Male
          morpher->CLOSE_GOSSIP_MENU();
          morpher->SetDisplayId(20580);
		  break;

        case GOSSIP_ACTION_INFO_DEF+13://Gnome - Female
          morpher->CLOSE_GOSSIP_MENU();
          morpher->SetDisplayId(20581);
		  break;

        case GOSSIP_ACTION_INFO_DEF+14://Human - Male
          morpher->CLOSE_GOSSIP_MENU();
          morpher->SetDisplayId(19723);
		  break;

        case GOSSIP_ACTION_INFO_DEF+15://Tauren - Male
          morpher->CLOSE_GOSSIP_MENU();
          morpher->SetDisplayId(20585);
          break;
  
        case GOSSIP_ACTION_INFO_DEF+16://Tauren - Female
          morpher->CLOSE_GOSSIP_MENU();
          morpher->SetDisplayId(20584);
          break;

        case GOSSIP_ACTION_INFO_DEF+17://Blood Elf - Male
          morpher->CLOSE_GOSSIP_MENU();
          morpher->SetDisplayId(20578);
          break;

        case GOSSIP_ACTION_INFO_DEF+18://Blood Elf - Female
          morpher->CLOSE_GOSSIP_MENU();
          morpher->SetDisplayId(20579);
          break;

	    case GOSSIP_ACTION_INFO_DEF+19://Pirate - Male
          morpher->CLOSE_GOSSIP_MENU();
          morpher->SetDisplayId(4620);
          break;

		case GOSSIP_ACTION_INFO_DEF+21://Night Elf - Male
          morpher->CLOSE_GOSSIP_MENU();
          morpher->SetDisplayId(20122);
          break;
		  
		case GOSSIP_ACTION_INFO_DEF+22://Night Elf - Female
          morpher->CLOSE_GOSSIP_MENU();
          morpher->SetDisplayId(20126);
          break;

		case GOSSIP_ACTION_INFO_DEF+23://Dwarf Male
          morpher->CLOSE_GOSSIP_MENU();
          morpher->SetDisplayId(20220);
          break;

		case GOSSIP_ACTION_INFO_DEF+24://ORC [WARLOCK] - Male
          morpher->CLOSE_GOSSIP_MENU();
          morpher->SetDisplayId(20221);
          break;

		case GOSSIP_ACTION_INFO_DEF+25://ORC [WARLOCK] - Female
          morpher->CLOSE_GOSSIP_MENU();
          morpher->SetDisplayId(20220);
          break;


        case GOSSIP_ACTION_INFO_DEF+30://Demorph
          morpher->CLOSE_GOSSIP_MENU();
          morpher->DeMorph();
          break;

 
        default: // Close
            morpher->CLOSE_GOSSIP_MENU();
            return true;
		}
 
        OnGossipHello(morpher, creature);
		return true;
	}
};
 
void AddSC_npc_morph()
{
    new npc_morph;
}