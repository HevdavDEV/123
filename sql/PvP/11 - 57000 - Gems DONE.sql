-- FINAL GEM NPC

DELETE FROM `creature_template` WHERE (`entry`=57000);
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (57000, 0, 0, 0, 0, 0, 25277, 0, 0, 0, 'Gems', 'Spectrum WoW', '', 57000, 83, 83, 2, 35, 35, 129, 1, 1.14286, 1.4, 3, 1, 1, 1, 1, 1, 1, 1, 1, 258, 0, 8, 0, 0, 0, 0, 0, 1, 1, 1, 7, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 4, 1, 75, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1);

DELETE FROM `gossip_menu_option` WHERE menu_id between 57000 and 57008;

REPLACE INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(57000,0,1,'|TInterface/icons/INV_JEWELCRAFTING_GEM_37:35|t|r Red',1,1,57001,0,0,0,NULL),
(57001, 0, 1, 'Red Gem', 3, 128, 57001, 0, 0, 0, ''),
(57000,1,1,'|TInterface/icons/INV_JEWELCRAFTING_GEM_38:35|t|r Yellow',1,1,57002,0,0,0,NULL),
(57002, 0, 1, 'Yellow Gem', 3, 128, 57002, 0, 0, 0, ''),
(57000,2,1,'|TInterface/icons/INV_JEWELCRAFTING_GEM_42:35|t|r Blue',1,1,57003,0,0,0,NULL),
(57003, 0, 1, 'Blue Gem', 3, 128, 57003, 0, 0, 0, ''),
(57000,3,1,'|TInterface/icons/INV_JEWELCRAFTING_GEM_39:35|t|r Orange',1,1,57004,0,0,0,NULL),
(57004, 0, 1, 'Orange Gem', 3, 128, 57004, 0, 0, 0, ''),
(57000,4,1,'|TInterface/icons/INV_JEWELCRAFTING_GEM_40:35|t|r Purple',1,1,57005,0,0,0,NULL),
(57005, 0, 1, 'Purple Gem', 3, 128, 57005, 0, 0, 0, ''),
(57000,5,1,'|TInterface/icons/INV_JEWELCRAFTING_GEM_41:35|t|r Green',1,1,57006,0,0,0,NULL),
(57006, 0, 1, 'Green Gem', 3, 128, 57006, 0, 0, 0, ''),
(57000,6,1,'|TInterface/icons/inv_jewelcrafting_shadowspirit_02:35|t|r Meta',1,1,57007,0,0,0,NULL),
(57007, 0, 1, 'Meta Gem', 3, 128, 57007, 0, 0, 0, ''),
(57000,7,1,'|TInterface/icons/inv_misc_gem_pearl_12:35|t|r Prismatic',1,1,57008,0,0,0,NULL),
(57008, 0, 1, 'Prismatic Gem', 3, 128, 57008, 0, 0, 0, '');

--  RED GEM VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 57001);
REPLACE INTO `npc_vendor` SELECT 57001,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `displayid` = 58601 and 61981;

-- Dragon Eye Red Gem
REPLACE INTO `npc_vendor` SELECT 57001,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `displayid` = 61981;

-- YELLOW GEM VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 57002);
REPLACE INTO `npc_vendor` SELECT 57002,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `displayid` = 58714;

-- Dragon Eye Yellow Gem
REPLACE INTO `npc_vendor` SELECT 57002,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `displayid` = 61983;

-- BLUE GEM VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 57003);
REPLACE INTO `npc_vendor` SELECT 57003,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `displayid` = 56636;

-- Dragon Eye Blue Gem
REPLACE INTO `npc_vendor` SELECT 57003,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `displayid` = 61982;

-- ORANGE GEM VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 57004);
REPLACE INTO `npc_vendor` SELECT 57004,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `displayid` = 60324;

-- PURPLE GEM VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 57005);
REPLACE INTO `npc_vendor` SELECT 57005,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `displayid` = 60326;

-- GREEN GEM VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 57006);
REPLACE INTO `npc_vendor` SELECT 57006,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `displayid` = 60325;

-- META BLUE GEM VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 57007);
REPLACE INTO `npc_vendor` SELECT 57007,0,`entry`,0,0,0,0,0
FROM `item_template` WHERE `displayid` = 54467 or `displayid` = 54469 or `displayid` = 39203 or `displayid` = 39205;
DELETE FROM `npc_vendor` WHERE entry = 57007 AND item IN (30567,30655,25893);

-- PRISMATIC GEM VENDOR ITEM
DELETE FROM `npc_vendor` WHERE (`entry`= 57008);
REPLACE INTO `npc_vendor` (`entry`, `item`) VALUES
('57008','22459'),
('57008','34142'),
('57008','42702'),
('57008','49110');
