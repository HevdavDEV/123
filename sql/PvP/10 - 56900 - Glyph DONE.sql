-- FINAL GLYPH NPC

DELETE FROM `creature_template` WHERE (`entry`=56900);
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (56900, 0, 0, 0, 0, 0, 25277, 0, 0, 0, 'Glyphs', 'Spectrum WoW', '', 56900, 83, 83, 2, 35, 35, 129, 1, 1.14286, 1.4, 3, 1, 1, 1, 1, 1, 1, 1, 1, 258, 0, 8, 0, 0, 0, 0, 0, 1, 1, 1, 7, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 4, 1, 75, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1);

DELETE FROM `gossip_menu_option` WHERE menu_id between 56900 and 56910;
REPLACE INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(56900,0,1,'|TInterface/icons/inv_glyph_majorpaladin:35|t|r Paladin',1,1,56901,0,0,0,NULL),
(56901, 0, 1, 'Glyph Paladin', 3, 128, 56901, 0, 0, 0, ''),
(56900,1,1,'|TInterface/icons/inv_glyph_majorwarrior:35|t|r Warrior',1,1,56902,0,0,0,NULL),
(56902, 0, 1, 'Glyph Warrior', 3, 128, 56902, 0, 0, 0, ''),
(56900,2,1,'|TInterface/icons/inv_glyph_majordeathknight:35|t|r Death Knight',1,1,56903,0,0,0,NULL),
(56903, 0, 1, 'Glyph Death Knight', 3, 128, 56903, 0, 0, 0, ''),
(56900,3,1,'|TInterface/icons/inv_glyph_majorhunter:35|t|r Hunter',1,1,56904,0,0,0,NULL),
(56904, 0, 1, 'Glyph Hunter', 3, 128, 56904, 0, 0, 0, ''),
(56900,4,1,'|TInterface/icons/inv_glyph_majorshaman:35|t|r Shaman',1,1,56905,0,0,0,NULL),
(56905, 0, 1, 'Glyph Shaman', 3, 128, 56905, 0, 0, 0, ''),
(56900,5,1,'|TInterface/icons/inv_glyph_majorrogue:35|t|r Rogue',1,1,56906,0,0,0,NULL),
(56906, 0, 1, 'Glyph Rogue', 3, 128, 56906, 0, 0, 0, ''),
(56900,6,1,'|TInterface/icons/inv_glyph_majordruid:35|t|r Druid',1,1,56907,0,0,0,NULL),
(56907, 0, 1, 'Glyph Druid', 3, 128, 56907, 0, 0, 0, ''),
(56900,7,1,'|TInterface/icons/inv_glyph_majorpriest:35|t|r Priest',1,1,56908,0,0,0,NULL),
(56908, 0, 1, 'Glyph Priest', 3, 128, 56908, 0, 0, 0, ''),
(56900,8,1,'|TInterface/icons/inv_glyph_majormage:35|t|r Mage',1,1,56909,0,0,0,NULL),
(56909, 0, 1, 'Glyph Mage', 3, 128, 56909, 0, 0, 0, ''),
(56900,9,1,'|TInterface/icons/inv_glyph_majorwarlock:35|t|r Warlock  ',1,1,56910,0,0,0,NULL),
(56910, 0, 1, 'Glyph Warlock', 3, 128, 56910, 0, 0, 0, '');

--  MAGE GLYPH VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 56909);
REPLACE INTO `npc_vendor` SELECT 56909,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `class` = 16 AND `subclass`= 8 AND `displayid` = 58830 OR `displayid` = 58831;

-- Priest GLYPH VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 56908);
REPLACE INTO `npc_vendor` SELECT 56908,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `class` = 16 AND `subclass`= 5 AND `displayid` = 58834 OR `displayid` = 58835;

-- Rogue GLYPH VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 56906);
REPLACE INTO `npc_vendor` SELECT 56906,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `class` = 16 AND `subclass`= 4 AND `displayid` = 58836 OR `displayid` = 58837;

-- Druid GLYPH VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 56907);
REPLACE INTO `npc_vendor` SELECT 56907,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `class` = 16 AND `subclass`= 11 AND `displayid` = 58828 OR `displayid` = 58827;

-- Paladin GLYPH VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 56901);
REPLACE INTO `npc_vendor` SELECT 56901,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `class` = 16 AND `subclass`= 2 AND `displayid` = 58832 OR `displayid` = 58833;

-- Shaman GLYPH VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 56905);
REPLACE INTO `npc_vendor` SELECT 56905,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `class` = 16 AND `subclass`= 7 AND `displayid` = 58839 OR `displayid` = 58838;

-- Warrior GLYPH VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 56902);
REPLACE INTO `npc_vendor` SELECT 56902,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `class` = 16 AND `subclass`= 1 AND `displayid` = 58842 OR `displayid` = 58843;

-- Hunter GLYPH VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 56904);
REPLACE INTO `npc_vendor` SELECT 56904,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `class` = 16 AND `subclass`= 3 AND `displayid` = 58829 OR `displayid` = 59343;

-- Warlocks GLYPH VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 56910);
REPLACE INTO `npc_vendor` SELECT 56910,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `class` = 16 AND `subclass`= 9 AND `displayid` = 58841 OR `displayid` = 58840;

-- DK GLYPH VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 56903);
REPLACE INTO `npc_vendor` SELECT 56903,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `class` = 16 AND `subclass`= 6 AND `displayid` = 58825 OR `displayid` = 58826;
