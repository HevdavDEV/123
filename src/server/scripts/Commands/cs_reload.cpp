/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
Name: reload_commandscript
%Complete: 100
Comment: All reload related commands
Category: commandscripts
EndScriptData */

#include "AccountMgr.h"
#include "AchievementMgr.h"
#include "AuctionHouseMgr.h"
#include "Chat.h"
#include "CreatureTextMgr.h"
#include "DisableMgr.h"
#include "Language.h"
#include "LFGMgr.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "SkillDiscovery.h"
#include "SkillExtraItems.h"
#include "SmartAI.h"
#include "SpellMgr.h"
#include "TicketMgr.h"
#include "WardenCheckMgr.h"
#include "WaypointManager.h"

class reload_commandscript : public CommandScript
{
public:
    reload_commandscript() : CommandScript("reload_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand reloadAllCommandTable[] =
        {
            { "achievement", rbac::RBAC_PERM_COMMAND_RELOAD_ALL_ACHIEVEMENT, true,  &HandleReloadAllAchievementCommand, "", NULL },
            { "area",        rbac::RBAC_PERM_COMMAND_RELOAD_ALL_AREA,        true,  &HandleReloadAllAreaCommand,       "", NULL },
            { "gossips",     rbac::RBAC_PERM_COMMAND_RELOAD_ALL_GOSSIP,      true,  &HandleReloadAllGossipsCommand,    "", NULL },
            { "item",        rbac::RBAC_PERM_COMMAND_RELOAD_ALL_ITEM,        true,  &HandleReloadAllItemCommand,       "", NULL },
            { "locales",     rbac::RBAC_PERM_COMMAND_RELOAD_ALL_LOCALES,     true,  &HandleReloadAllLocalesCommand,    "", NULL },
            { "loot",        rbac::RBAC_PERM_COMMAND_RELOAD_ALL_LOOT,        true,  &HandleReloadAllLootCommand,       "", NULL },
            { "npc",         rbac::RBAC_PERM_COMMAND_RELOAD_ALL_NPC,         true,  &HandleReloadAllNpcCommand,        "", NULL },
            { "quest",       rbac::RBAC_PERM_COMMAND_RELOAD_ALL_QUEST,       true,  &HandleReloadAllQuestCommand,      "", NULL },
            { "scripts",     rbac::RBAC_PERM_COMMAND_RELOAD_ALL_SCRIPTS,     true,  &HandleReloadAllScriptsCommand,    "", NULL },
            { "spell",       rbac::RBAC_PERM_COMMAND_RELOAD_ALL_SPELL,       true,  &HandleReloadAllSpellCommand,      "", NULL },
            { "",            rbac::RBAC_PERM_COMMAND_RELOAD_ALL,             true,  &HandleReloadAllCommand,           "", NULL },
            { NULL,          0,                  false, NULL,                              "", NULL }
        };
        static ChatCommand reloadCommandTable[] =
        {
            { "auctions",                      rbac::RBAC_PERM_COMMAND_RELOAD_AUCTIONS, true,  &HandleReloadAuctionsCommand,                   "", NULL },
            { "access_requirement",            rbac::RBAC_PERM_COMMAND_RELOAD_ACCESS_REQUIREMENT, true,  &HandleReloadAccessRequirementCommand,          "", NULL },
            { "achievement_criteria_data",     rbac::RBAC_PERM_COMMAND_RELOAD_ACHIEVEMENT_CRITERIA_DATA, true,  &HandleReloadAchievementCriteriaDataCommand,    "", NULL },
            { "achievement_reward",            rbac::RBAC_PERM_COMMAND_RELOAD_ACHIEVEMENT_REWARD, true,  &HandleReloadAchievementRewardCommand,          "", NULL },
            { "all",                           rbac::RBAC_PERM_COMMAND_RELOAD_ALL, true,  NULL,                          "", reloadAllCommandTable },
            { "areatrigger_involvedrelation",  rbac::RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_INVOLVEDRELATION, true,  &HandleReloadQuestAreaTriggersCommand,          "", NULL },
            { "areatrigger_tavern",            rbac::RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_TAVERN, true,  &HandleReloadAreaTriggerTavernCommand,          "", NULL },
            { "areatrigger_teleport",          rbac::RBAC_PERM_COMMAND_RELOAD_AREATRIGGER_TELEPORT, true,  &HandleReloadAreaTriggerTeleportCommand,        "", NULL },
            { "autobroadcast",                 rbac::RBAC_PERM_COMMAND_RELOAD_AUTOBROADCAST, true,  &HandleReloadAutobroadcastCommand,              "", NULL },
            { "command",                       rbac::RBAC_PERM_COMMAND_RELOAD_COMMAND, true,  &HandleReloadCommandCommand,                    "", NULL },
            { "conditions",                    rbac::RBAC_PERM_COMMAND_RELOAD_CONDITIONS, true,  &HandleReloadConditions,                        "", NULL },
            { "config",                        rbac::RBAC_PERM_COMMAND_RELOAD_CONFIG, true,  &HandleReloadConfigCommand,                     "", NULL },
            { "creature_text",                 rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_TEXT, true,  &HandleReloadCreatureText,                      "", NULL },
            { "creature_questender",           rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_QUESTENDER, true,  &HandleReloadCreatureQuestEnderCommand,  "", NULL },
            { "creature_linked_respawn",       rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_LINKED_RESPAWN,    true,  &HandleReloadLinkedRespawnCommand,              "", NULL },
            { "creature_loot_template",        rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_LOOT_TEMPLATE, true,  &HandleReloadLootTemplatesCreatureCommand,      "", NULL },
            { "creature_onkill_reputation",    rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_ONKILL_REPUTATION, true,  &HandleReloadOnKillReputationCommand,           "", NULL },
            { "creature_queststarter",         rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_QUESTSTARTER, true,  &HandleReloadCreatureQuestStarterCommand,     "", NULL },
            { "creature_summon_groups",        rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_SUMMON_GROUPS, true,  &HandleReloadCreatureSummonGroupsCommand,       "", NULL },
            { "creature_template",             rbac::RBAC_PERM_COMMAND_RELOAD_CREATURE_TEMPLATE, true,  &HandleReloadCreatureTemplateCommand,           "", NULL },
            //{ "db_script_string",              rbac::RBAC_PERM_COMMAND_RELOAD_, true,  &HandleReloadDbScriptStringCommand,            "", NULL },
            { "disables",                      rbac::RBAC_PERM_COMMAND_RELOAD_DISABLES, true,  &HandleReloadDisablesCommand,                   "", NULL },
            { "disenchant_loot_template",      rbac::RBAC_PERM_COMMAND_RELOAD_DISENCHANT_LOOT_TEMPLATE, true,  &HandleReloadLootTemplatesDisenchantCommand,    "", NULL },
            { "event_scripts",                 rbac::RBAC_PERM_COMMAND_RELOAD_EVENT_SCRIPTS, true,  &HandleReloadEventScriptsCommand,               "", NULL },
            { "fishing_loot_template",         rbac::RBAC_PERM_COMMAND_RELOAD_FISHING_LOOT_TEMPLATE, true,  &HandleReloadLootTemplatesFishingCommand,       "", NULL },
            { "game_graveyard_zone",           rbac::RBAC_PERM_COMMAND_RELOAD_GAME_GRAVEYARD_ZONE, true,  &HandleReloadGameGraveyardZoneCommand,          "", NULL },
            { "game_tele",                     rbac::RBAC_PERM_COMMAND_RELOAD_GAME_TELE, true,  &HandleReloadGameTeleCommand,                   "", NULL },
            { "gameobject_questender",         rbac::RBAC_PERM_COMMAND_RELOAD_GAMEOBJECT_QUESTENDER, true,  &HandleReloadGOQuestEnderCommand,        "", NULL },
            { "gameobject_loot_template",      rbac::RBAC_PERM_COMMAND_RELOAD_GAMEOBJECT_QUEST_LOOT_TEMPLATE, true,  &HandleReloadLootTemplatesGameobjectCommand,    "", NULL },
            { "gameobject_queststarter",       rbac::RBAC_PERM_COMMAND_RELOAD_GAMEOBJECT_QUESTSTARTER, true,  &HandleReloadGOQuestStarterCommand,           "", NULL },
            { "gm_tickets",                    rbac::RBAC_PERM_COMMAND_RELOAD_GM_TICKETS, true,  &HandleReloadGMTicketsCommand,                  "", NULL },
            { "gossip_menu",                   rbac::RBAC_PERM_COMMAND_RELOAD_GOSSIP_MENU, true,  &HandleReloadGossipMenuCommand,                 "", NULL },
            { "gossip_menu_option",            rbac::RBAC_PERM_COMMAND_RELOAD_GOSSIP_MENU_OPTION, true,  &HandleReloadGossipMenuOptionCommand,           "", NULL },
            { "item_enchantment_template",     rbac::RBAC_PERM_COMMAND_RELOAD_ITEM_ENCHANTMENT_TEMPLATE, true,  &HandleReloadItemEnchantementsCommand,          "", NULL },
            { "item_loot_template",            rbac::RBAC_PERM_COMMAND_RELOAD_ITEM_LOOT_TEMPLATE, true,  &HandleReloadLootTemplatesItemCommand,          "", NULL },
            { "item_set_names",                rbac::RBAC_PERM_COMMAND_RELOAD_ITEM_SET_NAMES, true,  &HandleReloadItemSetNamesCommand,               "", NULL },
            { "lfg_dungeon_rewards",           rbac::RBAC_PERM_COMMAND_RELOAD_LFG_DUNGEON_REWARDS, true,  &HandleReloadLfgRewardsCommand,                 "", NULL },
            { "locales_achievement_reward",    rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_ACHIEVEMENT_REWARD, true,  &HandleReloadLocalesAchievementRewardCommand,   "", NULL },
            { "locales_creature",              rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_CRETURE, true,  &HandleReloadLocalesCreatureCommand,            "", NULL },
            { "locales_creature_text",         rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_CRETURE_TEXT, true,  &HandleReloadLocalesCreatureTextCommand,        "", NULL },
            { "locales_gameobject",            rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_GAMEOBJECT, true,  &HandleReloadLocalesGameobjectCommand,          "", NULL },
            { "locales_gossip_menu_option",    rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_GOSSIP_MENU_OPTION, true,  &HandleReloadLocalesGossipMenuOptionCommand,    "", NULL },
            { "locales_item",                  rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_ITEM, true,  &HandleReloadLocalesItemCommand,                "", NULL },
            { "locales_item_set_name",         rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_ITEM_SET_NAME, true,  &HandleReloadLocalesItemSetNameCommand,         "", NULL },
            { "locales_npc_text",              rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_NPC_TEXT, true,  &HandleReloadLocalesNpcTextCommand,             "", NULL },
            { "locales_page_text",             rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_PAGE_TEXT, true,  &HandleReloadLocalesPageTextCommand,            "", NULL },
            { "locales_points_of_interest",    rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_POINTS_OF_INTEREST, true,  &HandleReloadLocalesPointsOfInterestCommand,    "", NULL },
            { "locales_quest",                 rbac::RBAC_PERM_COMMAND_RELOAD_LOCALES_QUEST, true,  &HandleReloadLocalesQuestCommand,               "", NULL },
            { "mail_level_reward",             rbac::RBAC_PERM_COMMAND_RELOAD_MAIL_LEVEL_REWARD, true,  &HandleReloadMailLevelRewardCommand,            "", NULL },
            { "mail_loot_template",            rbac::RBAC_PERM_COMMAND_RELOAD_MAIL_LOOT_TEMPLATE, true,  &HandleReloadLootTemplatesMailCommand,          "", NULL },
            { "milling_loot_template",         rbac::RBAC_PERM_COMMAND_RELOAD_MILLING_LOOT_TEMPLATE, true,  &HandleReloadLootTemplatesMillingCommand,       "", NULL },
            { "npc_spellclick_spells",         rbac::RBAC_PERM_COMMAND_RELOAD_NPC_SPELLCLICK_SPELLS, true,  &HandleReloadSpellClickSpellsCommand,           "", NULL},
            { "npc_trainer",                   rbac::RBAC_PERM_COMMAND_RELOAD_NPC_TRAINER, true,  &HandleReloadNpcTrainerCommand,                 "", NULL },
            { "npc_vendor",                    rbac::RBAC_PERM_COMMAND_RELOAD_NPC_VENDOR, true,  &HandleReloadNpcVendorCommand,                  "", NULL },
            { "page_text",                     rbac::RBAC_PERM_COMMAND_RELOAD_PAGE_TEXT, true,  &HandleReloadPageTextsCommand,                  "", NULL },
            { "pickpocketing_loot_template",   rbac::RBAC_PERM_COMMAND_RELOAD_PICKPOCKETING_LOOT_TEMPLATE, true,  &HandleReloadLootTemplatesPickpocketingCommand, "", NULL},
            { "points_of_interest",            rbac::RBAC_PERM_COMMAND_RELOAD_POINTS_OF_INTEREST, true,  &HandleReloadPointsOfInterestCommand,           "", NULL },
            { "prospecting_loot_template",     rbac::RBAC_PERM_COMMAND_RELOAD_PROSPECTING_LOOT_TEMPLATE, true,  &HandleReloadLootTemplatesProspectingCommand,   "", NULL },
            { "quest_poi",                     rbac::RBAC_PERM_COMMAND_RELOAD_QUEST_POI, true,  &HandleReloadQuestPOICommand,                   "", NULL },
            { "quest_template",                rbac::RBAC_PERM_COMMAND_RELOAD_QUEST_TEMPLATE, true,  &HandleReloadQuestTemplateCommand,              "", NULL },
            { "rbac",                          rbac::RBAC_PERM_COMMAND_RELOAD_RBAC, true,  &HandleReloadRBACCommand,                       "", NULL },
            { "reference_loot_template",       rbac::RBAC_PERM_COMMAND_RELOAD_REFERENCE_LOOT_TEMPLATE, true,  &HandleReloadLootTemplatesReferenceCommand,     "", NULL },
            { "reserved_name",                 rbac::RBAC_PERM_COMMAND_RELOAD_RESERVED_NAME, true,  &HandleReloadReservedNameCommand,               "", NULL },
            { "reputation_reward_rate",        rbac::RBAC_PERM_COMMAND_RELOAD_REPUTATION_REWARD_RATE, true,  &HandleReloadReputationRewardRateCommand,       "", NULL },
            { "reputation_spillover_template", rbac::RBAC_PERM_COMMAND_RELOAD_SPILLOVER_TEMPLATE, true,  &HandleReloadReputationRewardRateCommand,       "", NULL },
            { "skill_discovery_template",      rbac::RBAC_PERM_COMMAND_RELOAD_SKILL_DISCOVERY_TEMPLATE, true,  &HandleReloadSkillDiscoveryTemplateCommand,     "", NULL },
            { "skill_extra_item_template",     rbac::RBAC_PERM_COMMAND_RELOAD_SKILL_EXTRA_ITEM_TEMPLATE, true,  &HandleReloadSkillExtraItemTemplateCommand,     "", NULL },
            { "skill_fishing_base_level",      rbac::RBAC_PERM_COMMAND_RELOAD_SKILL_FISHING_BASE_LEVEL, true,  &HandleReloadSkillFishingBaseLevelCommand,      "", NULL },
            { "skinning_loot_template",        rbac::RBAC_PERM_COMMAND_RELOAD_SKINNING_LOOT_TEMPLATE, true,  &HandleReloadLootTemplatesSkinningCommand,      "", NULL },
            { "smart_scripts",                 rbac::RBAC_PERM_COMMAND_RELOAD_SMART_SCRIPTS, true,  &HandleReloadSmartScripts,                      "", NULL },
            { "spell_required",                rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_REQUIRED, true,  &HandleReloadSpellRequiredCommand,              "", NULL },
            { "spell_area",                    rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_AREA, true,  &HandleReloadSpellAreaCommand,                  "", NULL },
            { "spell_bonus_data",              rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_BONUS_DATA, true,  &HandleReloadSpellBonusesCommand,               "", NULL },
            { "spell_group",                   rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_GROUP, true,  &HandleReloadSpellGroupsCommand,                "", NULL },
            { "spell_learn_spell",             rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_LEARN_SPELL, true,  &HandleReloadSpellLearnSpellCommand,            "", NULL },
            { "spell_loot_template",           rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_LOOT_TEMPLATE, true,  &HandleReloadLootTemplatesSpellCommand,         "", NULL },
            { "spell_linked_spell",            rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_LINKED_SPELL, true,  &HandleReloadSpellLinkedSpellCommand,           "", NULL },
            { "spell_pet_auras",               rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_PET_AURAS, true,  &HandleReloadSpellPetAurasCommand,              "", NULL },
            { "spell_proc_event",              rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_PROC_EVENT, true,  &HandleReloadSpellProcEventCommand,             "", NULL },
            { "spell_proc",                    rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_PROC, true,  &HandleReloadSpellProcsCommand,                 "", NULL },
            { "spell_scripts",                 rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_SCRIPTS, true,  &HandleReloadSpellScriptsCommand,               "", NULL },
            { "spell_target_position",         rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_TARGET_POSITION, true,  &HandleReloadSpellTargetPositionCommand,        "", NULL },
            { "spell_threats",                 rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_THREATS, true,  &HandleReloadSpellThreatsCommand,               "", NULL },
            { "spell_group_stack_rules",       rbac::RBAC_PERM_COMMAND_RELOAD_SPELL_GROUP_STACK_RULES, true,  &HandleReloadSpellGroupStackRulesCommand,       "", NULL },
            { "trinity_string",                rbac::RBAC_PERM_COMMAND_RELOAD_TRINITY_STRING, true,  &HandleReloadTrinityStringCommand,              "", NULL },
            { "warden_action",                 rbac::RBAC_PERM_COMMAND_RELOAD_WARDEN_ACTION, true,  &HandleReloadWardenactionCommand,               "", NULL },
            { "waypoint_scripts",              rbac::RBAC_PERM_COMMAND_RELOAD_WAYPOINT_SCRIPTS, true,  &HandleReloadWpScriptsCommand,                  "", NULL },
            { "waypoint_data",                 rbac::RBAC_PERM_COMMAND_RELOAD_WAYPOINT_DATA, true,  &HandleReloadWpCommand,                         "", NULL },
            { "vehicle_accessory",             rbac::RBAC_PERM_COMMAND_RELOAD_VEHICLE_ACCESORY, true,  &HandleReloadVehicleAccessoryCommand,           "", NULL },
            { "vehicle_template_accessory",    rbac::RBAC_PERM_COMMAND_RELOAD_VEHICLE_TEMPLATE_ACCESSORY, true,  &HandleReloadVehicleTemplateAccessoryCommand,   "", NULL },
            { NULL,                            0,                          false, NULL,                                           "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "reload", rbac::RBAC_PERM_COMMAND_RELOAD,  true, NULL, "", reloadCommandTable },
            { NULL,     0,                         false, NULL,               "", NULL }
        };
        return commandTable;
    }

    //reload commands
    static bool HandleReloadGMTicketsCommand(ChatHandler* /*handler*/, const char* /*args*/)
    {
        sTicketMgr->LoadTickets();
        return true;
    }

    static bool HandleReloadAllCommand(ChatHandler* handler, const char* /*args*/)
    {
        HandleReloadSkillFishingBaseLevelCommand(handler, "");

        HandleReloadAllAchievementCommand(handler, "");
        HandleReloadAllAreaCommand(handler, "");
        HandleReloadAllLootCommand(handler, "");
        HandleReloadAllNpcCommand(handler, "");
        HandleReloadAllQuestCommand(handler, "");
        HandleReloadAllSpellCommand(handler, "");
        HandleReloadAllItemCommand(handler, "");
        HandleReloadAllGossipsCommand(handler, "");
        HandleReloadAllLocalesCommand(handler, "");

        HandleReloadAccessRequirementCommand(handler, "");
        HandleReloadMailLevelRewardCommand(handler, "");
        HandleReloadCommandCommand(handler, "");
        HandleReloadReservedNameCommand(handler, "");
        HandleReloadTrinityStringCommand(handler, "");
        HandleReloadGameTeleCommand(handler, "");

        HandleReloadCreatureSummonGroupsCommand(handler, "");

        HandleReloadVehicleAccessoryCommand(handler, "");
        HandleReloadVehicleTemplateAccessoryCommand(handler, "");

        HandleReloadAutobroadcastCommand(handler, "");
        return true;
    }

    static bool HandleReloadAllAchievementCommand(ChatHandler* handler, const char* /*args*/)
    {
        HandleReloadAchievementCriteriaDataCommand(handler, "");
        HandleReloadAchievementRewardCommand(handler, "");
        return true;
    }

    static bool HandleReloadAllAreaCommand(ChatHandler* handler, const char* /*args*/)
    {
        //HandleReloadQuestAreaTriggersCommand(handler, ""); -- reloaded in HandleReloadAllQuestCommand
        HandleReloadAreaTriggerTeleportCommand(handler, "");
        HandleReloadAreaTriggerTavernCommand(handler, "");
        HandleReloadGameGraveyardZoneCommand(handler, "");
        return true;
    }

    static bool HandleReloadAllLootCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadLootTables();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadAllNpcCommand(ChatHandler* handler, const char* args)
    {
        if (*args != 'a')                                          // will be reloaded from all_gossips
        HandleReloadNpcTrainerCommand(handler, "a");
        HandleReloadNpcVendorCommand(handler, "a");
        HandleReloadPointsOfInterestCommand(handler, "a");
        HandleReloadSpellClickSpellsCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllQuestCommand(ChatHandler* handler, const char* /*args*/)
    {
        HandleReloadQuestAreaTriggersCommand(handler, "a");
        HandleReloadQuestPOICommand(handler, "a");
        HandleReloadQuestTemplateCommand(handler, "a");

        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadQuestStartersAndEnders();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadAllScriptsCommand(ChatHandler* handler, const char* /*args*/)
    {
        if (sScriptMgr->IsScriptScheduled())
        {
            handler->PSendSysMessage("Junky & Symbolix Repack Reloaded");
            handler->SetSentErrorMessage(true);
            return false;
        }

        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        HandleReloadEventScriptsCommand(handler, "a");
        HandleReloadSpellScriptsCommand(handler, "a");
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        HandleReloadDbScriptStringCommand(handler, "a");
        HandleReloadWpScriptsCommand(handler, "a");
        HandleReloadWpCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllSpellCommand(ChatHandler* handler, const char* /*args*/)
    {
        HandleReloadSkillDiscoveryTemplateCommand(handler, "a");
        HandleReloadSkillExtraItemTemplateCommand(handler, "a");
        HandleReloadSpellRequiredCommand(handler, "a");
        HandleReloadSpellAreaCommand(handler, "a");
        HandleReloadSpellGroupsCommand(handler, "a");
        HandleReloadSpellLearnSpellCommand(handler, "a");
        HandleReloadSpellLinkedSpellCommand(handler, "a");
        HandleReloadSpellProcEventCommand(handler, "a");
        HandleReloadSpellProcsCommand(handler, "a");
        HandleReloadSpellBonusesCommand(handler, "a");
        HandleReloadSpellTargetPositionCommand(handler, "a");
        HandleReloadSpellThreatsCommand(handler, "a");
        HandleReloadSpellGroupStackRulesCommand(handler, "a");
        HandleReloadSpellPetAurasCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllGossipsCommand(ChatHandler* handler, const char* args)
    {
        HandleReloadGossipMenuCommand(handler, "a");
        HandleReloadGossipMenuOptionCommand(handler, "a");
        if (*args != 'a')                                          // already reload from all_scripts
        HandleReloadPointsOfInterestCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllItemCommand(ChatHandler* handler, const char* /*args*/)
    {
        HandleReloadPageTextsCommand(handler, "a");
        HandleReloadItemEnchantementsCommand(handler, "a");
        return true;
    }

    static bool HandleReloadAllLocalesCommand(ChatHandler* handler, const char* /*args*/)
    {
        HandleReloadLocalesAchievementRewardCommand(handler, "a");
        HandleReloadLocalesCreatureCommand(handler, "a");
        HandleReloadLocalesCreatureTextCommand(handler, "a");
        HandleReloadLocalesGameobjectCommand(handler, "a");
        HandleReloadLocalesGossipMenuOptionCommand(handler, "a");
        HandleReloadLocalesItemCommand(handler, "a");
        HandleReloadLocalesNpcTextCommand(handler, "a");
        HandleReloadLocalesPageTextCommand(handler, "a");
        HandleReloadLocalesPointsOfInterestCommand(handler, "a");
        HandleReloadLocalesQuestCommand(handler, "a");
        return true;
    }

    static bool HandleReloadConfigCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sWorld->LoadConfigSettings(true);
        sMapMgr->InitializeVisibilityDistanceInfo();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadAccessRequirementCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadAccessRequirements();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadAchievementCriteriaDataCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sAchievementMgr->LoadAchievementCriteriaData();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadAchievementRewardCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sAchievementMgr->LoadRewards();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadAreaTriggerTavernCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadTavernAreaTriggers();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadAreaTriggerTeleportCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadAreaTriggerTeleports();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadAutobroadcastCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sWorld->LoadAutobroadcasts();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadCommandCommand(ChatHandler* handler, const char* /*args*/)
    {
        handler->SetLoadCommandTable(true);
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadOnKillReputationCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadReputationOnKill();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadCreatureSummonGroupsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded.");
        sObjectMgr->LoadTempSummons();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadCreatureTemplateCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Tokenizer entries(std::string(args), ' ');

        for (Tokenizer::const_iterator itr = entries.begin(); itr != entries.end(); ++itr)
        {
            uint32 entry = uint32(atoi(*itr));

            PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_TEMPLATE);
            stmt->setUInt32(0, entry);
            PreparedQueryResult result = WorldDatabase.Query(stmt);

            if (!result)
            {
                handler->PSendSysMessage(LANG_COMMAND_CREATURETEMPLATE_NOTFOUND, entry);
                continue;
            }

            CreatureTemplate* cInfo = const_cast<CreatureTemplate*>(sObjectMgr->GetCreatureTemplate(entry));
            if (!cInfo)
            {
                handler->PSendSysMessage(LANG_COMMAND_CREATURESTORAGE_NOTFOUND, entry);
                continue;
            }

            TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded | %u", entry);

            Field* fields = result->Fetch();

            cInfo->DifficultyEntry[0] = fields[0].GetUInt32();
            cInfo->DifficultyEntry[1] = fields[1].GetUInt32();
            cInfo->DifficultyEntry[2] = fields[2].GetUInt32();
            cInfo->KillCredit[0]      = fields[3].GetUInt32();
            cInfo->KillCredit[1]      = fields[4].GetUInt32();
            cInfo->Modelid1           = fields[5].GetUInt32();
            cInfo->Modelid2           = fields[6].GetUInt32();
            cInfo->Modelid3           = fields[7].GetUInt32();
            cInfo->Modelid4           = fields[8].GetUInt32();
            cInfo->Name               = fields[9].GetString();
            cInfo->SubName            = fields[10].GetString();
            cInfo->IconName           = fields[11].GetString();
            cInfo->GossipMenuId       = fields[12].GetUInt32();
            cInfo->minlevel           = fields[13].GetUInt8();
            cInfo->maxlevel           = fields[14].GetUInt8();
            cInfo->expansion          = fields[15].GetUInt16();
            cInfo->faction_A          = fields[16].GetUInt16();
            cInfo->faction_H          = fields[17].GetUInt16();
            cInfo->npcflag            = fields[18].GetUInt32();
            cInfo->speed_walk         = fields[19].GetFloat();
            cInfo->speed_run          = fields[20].GetFloat();
            cInfo->scale              = fields[21].GetFloat();
            cInfo->rank               = fields[22].GetUInt8();
            cInfo->mindmg             = fields[23].GetFloat();
            cInfo->maxdmg             = fields[24].GetFloat();
            cInfo->dmgschool          = fields[25].GetUInt8();
            cInfo->attackpower        = fields[26].GetUInt32();
            cInfo->dmg_multiplier     = fields[27].GetFloat();
            cInfo->baseattacktime     = fields[28].GetUInt32();
            cInfo->rangeattacktime    = fields[29].GetUInt32();
            cInfo->unit_class         = fields[30].GetUInt8();
            cInfo->unit_flags         = fields[31].GetUInt32();
            cInfo->unit_flags2        = fields[32].GetUInt32();
            cInfo->dynamicflags       = fields[33].GetUInt32();
            cInfo->family             = fields[34].GetUInt8();
            cInfo->trainer_type       = fields[35].GetUInt8();
            cInfo->trainer_spell      = fields[36].GetUInt32();
            cInfo->trainer_class      = fields[37].GetUInt8();
            cInfo->trainer_race       = fields[38].GetUInt8();
            cInfo->minrangedmg        = fields[39].GetFloat();
            cInfo->maxrangedmg        = fields[40].GetFloat();
            cInfo->rangedattackpower  = fields[41].GetUInt16();
            cInfo->type               = fields[42].GetUInt8();
            cInfo->type_flags         = fields[43].GetUInt32();
            cInfo->lootid             = fields[44].GetUInt32();
            cInfo->pickpocketLootId   = fields[45].GetUInt32();
            cInfo->SkinLootId         = fields[46].GetUInt32();

            for (uint8 i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
                cInfo->resistance[i] = fields[47 + i -1].GetUInt16();

            cInfo->spells[0]          = fields[53].GetUInt32();
            cInfo->spells[1]          = fields[54].GetUInt32();
            cInfo->spells[2]          = fields[55].GetUInt32();
            cInfo->spells[3]          = fields[56].GetUInt32();
            cInfo->spells[4]          = fields[57].GetUInt32();
            cInfo->spells[5]          = fields[58].GetUInt32();
            cInfo->spells[6]          = fields[59].GetUInt32();
            cInfo->spells[7]          = fields[60].GetUInt32();
            cInfo->PetSpellDataId     = fields[61].GetUInt32();
            cInfo->VehicleId          = fields[62].GetUInt32();
            cInfo->mingold            = fields[63].GetUInt32();
            cInfo->maxgold            = fields[64].GetUInt32();
            cInfo->AIName             = fields[65].GetString();
            cInfo->MovementType       = fields[66].GetUInt8();
            cInfo->InhabitType        = fields[67].GetUInt8();
            cInfo->HoverHeight        = fields[68].GetFloat();
            cInfo->ModHealth          = fields[69].GetFloat();
            cInfo->ModMana            = fields[70].GetFloat();
            cInfo->ModArmor           = fields[71].GetFloat();
            cInfo->RacialLeader       = fields[72].GetBool();
            cInfo->questItems[0]      = fields[73].GetUInt32();
            cInfo->questItems[1]      = fields[74].GetUInt32();
            cInfo->questItems[2]      = fields[75].GetUInt32();
            cInfo->questItems[3]      = fields[76].GetUInt32();
            cInfo->questItems[4]      = fields[77].GetUInt32();
            cInfo->questItems[5]      = fields[78].GetUInt32();
            cInfo->movementId         = fields[79].GetUInt32();
            cInfo->RegenHealth        = fields[80].GetBool();
            cInfo->MechanicImmuneMask = fields[81].GetUInt32();
            cInfo->flags_extra        = fields[82].GetUInt32();
            cInfo->ScriptID           = sObjectMgr->GetScriptId(fields[83].GetCString());

            sObjectMgr->CheckCreatureTemplate(cInfo);
        }

        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadCreatureQuestStarterCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadCreatureQuestStarters();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLinkedRespawnCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadLinkedRespawn();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadCreatureQuestEnderCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadCreatureQuestEnders();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadGossipMenuCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadGossipMenu();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadGossipMenuOptionCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadGossipMenuItems();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadGOQuestStarterCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadGameobjectQuestStarters();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadGOQuestEnderCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadGameobjectQuestEnders();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadQuestAreaTriggersCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadQuestAreaTriggers();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadQuestTemplateCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadQuests();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");

        /// dependent also from `gameobject` but this table not reloaded anyway
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadGameObjectForQuests();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLootTemplatesCreatureCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadLootTemplates_Creature();
        LootTemplates_Creature.CheckLootRefs();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesDisenchantCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadLootTemplates_Disenchant();
        LootTemplates_Disenchant.CheckLootRefs();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesFishingCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadLootTemplates_Fishing();
        LootTemplates_Fishing.CheckLootRefs();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesGameobjectCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadLootTemplates_Gameobject();
        LootTemplates_Gameobject.CheckLootRefs();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesItemCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadLootTemplates_Item();
        LootTemplates_Item.CheckLootRefs();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesMillingCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadLootTemplates_Milling();
        LootTemplates_Milling.CheckLootRefs();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesPickpocketingCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadLootTemplates_Pickpocketing();
        LootTemplates_Pickpocketing.CheckLootRefs();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesProspectingCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadLootTemplates_Prospecting();
        LootTemplates_Prospecting.CheckLootRefs();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesMailCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadLootTemplates_Mail();
        LootTemplates_Mail.CheckLootRefs();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesReferenceCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadLootTemplates_Reference();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesSkinningCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadLootTemplates_Skinning();
        LootTemplates_Skinning.CheckLootRefs();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadLootTemplatesSpellCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadLootTemplates_Spell();
        LootTemplates_Spell.CheckLootRefs();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        return true;
    }

    static bool HandleReloadTrinityStringCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadTrinityStrings();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadWardenactionCommand(ChatHandler* handler, const char* /*args*/)
    {
        if (!sWorld->getBoolConfig(CONFIG_WARDEN_ENABLED))
        {
            handler->SendSysMessage("Junky & Symbolix Repack Reloaded");
            handler->SetSentErrorMessage(true);
            return false;
        }

        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sWardenCheckMgr->LoadWardenOverrides();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadNpcTrainerCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadTrainerSpell();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded.");
        return true;
    }

    static bool HandleReloadNpcVendorCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadVendors();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadPointsOfInterestCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadPointsOfInterest();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadQuestPOICommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded" );
        sObjectMgr->LoadQuestPOI();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSpellClickSpellsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadNPCSpellClickSpells();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadReservedNameCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadReservedPlayersNames();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadReputationRewardRateCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded" );
        sObjectMgr->LoadReputationRewardRate();
        handler->SendGlobalSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadReputationSpilloverTemplateCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded" );
        sObjectMgr->LoadReputationSpilloverTemplate();
        handler->SendGlobalSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSkillDiscoveryTemplateCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadSkillDiscoveryTable();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSkillExtraItemTemplateCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadSkillExtraItemTable();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSkillFishingBaseLevelCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadFishingBaseSkillLevel();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSpellAreaCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sSpellMgr->LoadSpellAreas();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSpellRequiredCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sSpellMgr->LoadSpellRequired();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSpellGroupsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sSpellMgr->LoadSpellGroups();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSpellLearnSpellCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sSpellMgr->LoadSpellLearnSpells();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSpellLinkedSpellCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sSpellMgr->LoadSpellLinked();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSpellProcEventCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sSpellMgr->LoadSpellProcEvents();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSpellProcsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sSpellMgr->LoadSpellProcs();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSpellBonusesCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sSpellMgr->LoadSpellBonusess();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSpellTargetPositionCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sSpellMgr->LoadSpellTargetPositions();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSpellThreatsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sSpellMgr->LoadSpellThreats();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSpellGroupStackRulesCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sSpellMgr->LoadSpellGroupStackRules();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSpellPetAurasCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sSpellMgr->LoadSpellPetAuras();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadPageTextsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadPageTexts();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadItemEnchantementsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        LoadRandomEnchantmentsTable();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadItemSetNamesCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadItemSetNames();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadEventScriptsCommand(ChatHandler* handler, const char* args)
    {
        if (sScriptMgr->IsScriptScheduled())
        {
            handler->SendSysMessage("Junky & Symbolix Repack Reloaded");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (*args != 'a')
            TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");

        sObjectMgr->LoadEventScripts();

        if (*args != 'a')
            handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");

        return true;
    }

    static bool HandleReloadWpScriptsCommand(ChatHandler* handler, const char* args)
    {
        if (sScriptMgr->IsScriptScheduled())
        {
            handler->SendSysMessage("Junky & Symbolix Repack Reloaded");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (*args != 'a')
            TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");

        sObjectMgr->LoadWaypointScripts();

        if (*args != 'a')
            handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");

        return true;
    }

    static bool HandleReloadWpCommand(ChatHandler* handler, const char* args)
    {
        if (*args != 'a')
            TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");

        sWaypointMgr->Load();

        if (*args != 'a')
            handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");

        return true;
    }

    static bool HandleReloadSpellScriptsCommand(ChatHandler* handler, const char* args)
    {
        if (sScriptMgr->IsScriptScheduled())
        {
            handler->SendSysMessage("Junky & Symbolix Repack Reloaded");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (*args != 'a')
            TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");

        sObjectMgr->LoadSpellScripts();

        if (*args != 'a')
            handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");

        return true;
    }

    static bool HandleReloadDbScriptStringCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadDbScriptStrings();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadGameGraveyardZoneCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");

        sObjectMgr->LoadGraveyardZones();

        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");

        return true;
    }

    static bool HandleReloadGameTeleCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");

        sObjectMgr->LoadGameTele();

        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");

        return true;
    }

    static bool HandleReloadDisablesCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        DisableMgr::LoadDisables();
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        DisableMgr::CheckQuestDisables();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLocalesAchievementRewardCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sAchievementMgr->LoadRewardLocales();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLfgRewardsCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sLFGMgr->LoadRewards();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLocalesCreatureCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadCreatureLocales();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLocalesCreatureTextCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sCreatureTextMgr->LoadCreatureTextLocales();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLocalesGameobjectCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadGameObjectLocales();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLocalesGossipMenuOptionCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadGossipMenuItemsLocales();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLocalesItemCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadItemLocales();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLocalesItemSetNameCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadItemSetNameLocales();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLocalesNpcTextCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadNpcTextLocales();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLocalesPageTextCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadPageTextLocales();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLocalesPointsOfInterestCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadPointOfInterestLocales();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadLocalesQuestCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadQuestLocales();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadMailLevelRewardCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadMailLevelRewards();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadAuctionsCommand(ChatHandler* handler, const char* /*args*/)
    {
        ///- Reload dynamic data tables from the database
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sAuctionMgr->LoadAuctionItems();
        sAuctionMgr->LoadAuctions();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadConditions(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sConditionMgr->LoadConditions(true);
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadCreatureText(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sCreatureTextMgr->LoadCreatureTexts();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadSmartScripts(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sSmartScriptMgr->LoadSmartAIFromDB();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadVehicleAccessoryCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadVehicleAccessories();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadVehicleTemplateAccessoryCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sObjectMgr->LoadVehicleTemplateAccessories();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }

    static bool HandleReloadRBACCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Junky & Symbolix Repack Reloaded");
        sAccountMgr->LoadRBAC();
        sWorld->ReloadRBAC();
        handler->SendGlobalGMSysMessage("Junky & Symbolix Repack Reloaded");
        return true;
    }
};

void AddSC_reload_commandscript()
{
    new reload_commandscript();
}
