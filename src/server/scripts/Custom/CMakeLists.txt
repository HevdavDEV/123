# Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
    Custom/npc_arenaspectator.cpp
	Custom/npc_arena1v1.cpp
	Custom/npc_arena1v1.h
	Custom/Transmogrification.cpp
	Custom/Transmogrification.h
	Custom/Transmogrifier.cpp
	Custom/NPC/npc_beastmaster.cpp
	Custom/NPC/npc_enchant.cpp
	Custom/NPC/npc_enchantment.cpp
	Custom/NPC/npc_morph.cpp
	Custom/NPC/npc_morpher.cpp
	Custom/NPC/npc_profession.cpp
	Custom/NPC/npc_reset_instance.cpp
	Custom/NPC/npc_show.cpp
	Custom/NPC/npc_skill.cpp
	Custom/NPC/npc_tools.cpp
	Custom/NPC/npc_top.cpp
	Custom/NPC/npc_trainer.cpp
	Custom/SCR/scr_autolearn.cpp
	Custom/SCR/scr_boss_announcer.cpp
	Custom/SCR/scr_channel_factions.cpp
	Custom/SCR/scr_Fast_Arena_Start.cpp
	Custom/SCR/scr_killstreak.cpp
	Custom/SCR/scr_login.cpp
	Custom/SCR/scr_ResetDuel.cpp
)

message("  -> Prepared: Custom")
