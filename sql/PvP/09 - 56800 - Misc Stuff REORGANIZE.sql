-- FINAL NPC Misc Stuff

DELETE FROM `creature_template` WHERE (`entry`=56800);
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (56800, 0, 0, 0, 0, 0, 25277, 0, 0, 0, 'Misc Stuff', 'Spectrum WoW', '', 56800, 83, 83, 2, 35, 35, 129, 1, 1.14286, 1.4, 3, 1, 1, 1, 1, 1, 1, 1, 1, 258, 0, 8, 0, 0, 0, 0, 0, 1, 1, 1, 7, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 4, 1, 75, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1);

DELETE FROM `gossip_menu_option` WHERE menu_id in (56800,56801,56802);
REPLACE INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(56800,0,1,'|TInterface/icons/ability_druid_challangingroar:35|t|r Arena Mounts',1,1,56801,0,0,0,NULL),
(56801, 0, 1, 'Arena Mounts', 3, 128, 56801, 0, 0, 0, ''),
(56800,1,1,'|TInterface/icons/inv_shirt_guildtabard_01:35|t|r Tabards',1,1,56802,0,0,0,NULL),
(56802, 0, 1, 'Tabards', 3, 128, 56802, 0, 0, 0, '');

DELETE FROM `npc_vendor` WHERE entry in (56801,56802);
REPLACE INTO `npc_vendor` (`entry`, `item`, `ExtendedCost`) VALUES
-- Arena Mounts
('56801','44077','2625'),
('56801','43956','2625'),
('56801','45180','2359'),
('56801','29103','2359'),
('56801','44083','2361'),
('56801','54068','2361'),
('56801','49098','2361'),
('56801','47180','2361'),
('56801','52200','2361'),
('56801','37011','2624'),
('56801','38576','2625'),
('56801','44224','2625'),
('56801','37828','2361'),
('56801','25549','2359'),
('56801','32768','2361'),
('56801','38576','2361'),
('56801','49086','2359'),
('56801','35513','2361'),
('56801','37719','2361'),
('56801','13335','2361'),
('56801','19872','2361'),
('56801','13317','2359'),
('56801','30487','2361'),
('56801','19029','2361'),
('56801','19902','2361'),
('56801','33977','2361'),
('56801','33809','2361'),
('56801','45595','2625'),
('56801','45589','2625'),
('56801','45590','2625'),
('56801','45591','2625'),
('56801','45592','2625'),
('56801','45125','2625'),
('56801','45596','2625'),
('56801','45586','2625'),
('56801','45593','2625'),
('56801','29227','2625'),
('56801','29102','2625'),
('56801','31830','2625'),
('56801','31829','2625'),
-- Tabards
-- 2200 Rating - 1500 Arena Points
('56802','51534','2359'),
('56802','49086','2359'),
('56802','45983','2359'),
-- 2000 Rating - 1500 Arena Points
('56802','35280','1435'),
('56802','52252','1435'),
('56802','35279','1435'),
('56802','40643','1435'),
-- 1930 Rating - 1350 Arena Points
('56802','24344','2467'),
('56802','38311','2467'),
('56802','23705','2467'),
('56802','23709','2467'),
('56802','38314','2467'),
('56802','38310','2467'),
('56802','38313','2467'),
('56802','38309','2467'),
('56802','25549','2467'),
-- 1750 Rating - 47400 Honor Points
('56802','23192','2715'),
('56802','31404','2715'),
('56802','31405','2715'),
('56802','28788','2715'),
('56802','22999','2715'),
-- 1650 Rating - 62000 Honor Points
('56802','45579','2718'),
('56802','45580','2718'),
('56802','45578','2718'),
('56802','45577','2718'),
('56802','45574','2718'),
('56802','45581','2718'),
('56802','45582','2718'),
('56802','45585','2718'),
('56802','45584','2718'),
('56802','45583','2718'),
-- 50000 Honor Points
('56802','20132','2570'),
('56802','19032','2570'),
('56802','19506','2570'),
('56802','20131','2570'),
('56802','19031','2570'),
('56802','19505','2570'),
-- 40000 Honor Points
('56802','15198','2403'),
('56802','15199','2403'),
-- 21000 Honor Points
('56802','15196','2428'),
('56802','15197','2428'),
('56802','36941','2428');
