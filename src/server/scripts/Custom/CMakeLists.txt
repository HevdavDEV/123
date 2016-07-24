<<<<<<< HEAD
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
  Custom/npc_arena1v1.cpp
  Custom/npc_arena1v1.h
  Custom/npc_enchant.cpp
  Custom/Transmogrification.cpp
  Custom/Transmogrification.h
  Custom/Transmogrifier.cpp
  Custom/NPC/npc_beastmaster.cpp
  Custom/NPC/npc_learn.cpp
  Custom/NPC/npc_morpher.cpp
  Custom/NPC/npc_profession.cpp
  Custom/NPC/npc_skill.cpp
  Custom/NPC/npc_spectator.cpp
  Custom/NPC/npc_teleport.cpp
  Custom/NPC/npc_title.cpp
  Custom/NPC/npc_tools.cpp
  Custom/npc_zagorka.cpp
  Custom/PlayerScript/announcer.cpp
  Custom/PlayerScript/autolearn.cpp
  Custom/PlayerScript/chat.cpp
  Custom/PlayerScript/factions.cpp
  Custom/PlayerScript/killstreak.cpp
  Custom/PlayerScript/reset.cpp
  Custom/PlayerScript/start.cpp
  Custom/PlayerScript/login.cpp
  Custom/Reforging.cpp
  Custom/top5killers.cpp
  Custom/custom_challenge_command.cpp
)

message("  -> Prepared: Custom")
=======
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
  Custom/custom.cpp
  Custom/TrialOfTheCrusader/TW_boss_faction_champions.cpp
  Custom/custom_scripts.cpp
  Custom/WorldEvents/brewfest.cpp
  Custom/cs_custom.cpp
  Custom/WorldEvents/TW_hallows_end.cpp
  Custom/WorldEvents/TW_pilgrim.cpp
  Custom/WorldEvents/TW_boss_apothecary_trio.cpp
  Custom/AzjolNerub/TW_boss_hadronox.cpp
  Custom/HallsOfReflection/TW_boss_falric.cpp
  Custom/HallsOfReflection/TW_boss_lich_king_hor.cpp
  Custom/HallsOfReflection/TW_boss_marwyn.cpp
  Custom/HallsOfReflection/TW_halls_of_reflection.cpp
  Custom/HallsOfReflection/TW_halls_of_reflection.h
  Custom/HallsOfReflection/TW_instance_halls_of_reflection.cpp
  Custom/TrialOfTheChampion/TW_instance_trial_of_the_champion.cpp
  Custom/TrialOfTheChampion/TW_trial_of_the_champion.h
  Custom/TrialOfTheChampion/TW_boss_argent_challenge.cpp
  Custom/TrialOfTheChampion/TW_boss_grand_champions.cpp
  Custom/TrialOfTheChampion/TW_boss_black_knight.cpp
  Custom/TrialOfTheChampion/TW_trial_of_the_champion.cpp
  Custom/Ulduar/TW_boss_thorim.cpp
  Custom/Ulduar/TW_boss_mimiron.cpp
  Custom/Transmogrification/Transmogrification.h
  Custom/Transmogrification/Transmogrification.cpp
  Custom/Transmogrification/Transmogrifier.cpp
  Custom/WorldNpc/emblem_vendor.cpp
  Custom/WorldNpc/mount_vendor.cpp
  Custom/WorldNpc/npc_icc_rep_rings.cpp
  Custom/WorldNpc/npc_morph.cpp
  Custom/WorldNpc/npc_rapidchange.cpp
  Custom/Duel_reset.cpp
  ${scripts_STAT_SRCS}
)

message("  -> Prepared: Custom")
>>>>>>> b0f53fc2f4aa54263df5b3b7bcc69bb2ec9f00e2
