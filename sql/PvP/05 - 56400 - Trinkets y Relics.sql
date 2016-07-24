-- FINAL NPC Relentless

DELETE FROM `creature_template` WHERE (`entry`=56400);
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (56400, 0, 0, 0, 0, 0, 25277, 0, 0, 0, 'Trinket & Relics', 'Spectrum WoW', '', 56400, 83, 83, 2, 35, 35, 129, 1, 1.14286, 1.4, 3, 1, 1, 1, 1, 1, 1, 1, 1, 258, 0, 8, 0, 0, 0, 0, 0, 1, 1, 1, 7, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 4, 1, 75, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1);

DELETE FROM `gossip_menu_option` WHERE menu_id between 56400 and 56402;
REPLACE INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`) VALUES
(56400,0,1,'|TInterface/icons/inv_misc_bone_skull_02:35|t|r Trinkets',1,1,56401),
(56401, 0, 1, 'Trinkets', 3, 128, 56401),
(56400,1,1,'|TInterface/icons/inv_qirajidol_strife:35|t|r Relics',1,1,56402),
(56402, 0, 1, 'Relics', 3, 128, 56402);

UPDATE `item_template` SET AllowableClass = 2 WHERE entry IN (51478,51472,50460,50455,50461,42854,42616,47664,47661,47662,45510,45436,45145,40191,40337,40268,40707,40706,40705);
UPDATE `item_template` SET AllowableClass = 32 WHERE entry IN (51417,50462,50459,42622,47672,47673,45144,45254,40207);
UPDATE `item_template` SET AllowableClass = 64 WHERE entry IN (51507,51513,51501,50458,50463,50464,42609,42604,42599,47665,47666,47667,45114,45255,45169,40322,40267,39728);
UPDATE `item_template` SET AllowableClass = 1024 WHERE entry IN (51429,51437,51423,50454,50456,50457,42591,42585,42580,47671,47670,47668,45509,45270,46138,40342,39757,40321);

DELETE FROM `npc_vendor` WHERE entry between 56001 and 56006;
REPLACE INTO `npc_vendor` (`entry`, `item`, `ExtendedCost`) VALUES
-- Trinkets

-- Relics
-- Paladin
('56402','51478','0'),
('56402','51472','0'),
('56402','50460','0'),
('56402','50455','0'),
('56402','50461','0'),
-- Without Price
('56402','42854','0'),
('56402','42616','0'),
('56402','47664','0'),
('56402','47661','0'),
('56402','47662','0'),
('56402','45510','0'),
('56402','45436','0'),
('56402','45145','0'),
('56402','40191','0'),
('56402','40337','0'),
('56402','40268','0'),
('56402','40707','0'),
('56402','40706','0'),
('56402','40705','0'),
-- Death Knight
('56402','51417','0'),
('56402','50462','0'),
('56402','50459','0'),
-- Without Price
('56402','42622','0'),
('56402','47672','0'),
('56402','47673','0'),
('56402','45144','0'),
('56402','45254','0'),
('56402','40207','0'),
('56402','40715','0'),
('56402','40714','0'),
-- Shaman
('56402','51507','0'),
('56402','51513','0'),
('56402','51501','0'),
('56402','50458','0'),
('56402','50463','0'),
('56402','50464','0'),
-- Without Price
('56402','42609','0'),
('56402','42604','0'),
('56402','42599','0'),
('56402','47665','0'),
('56402','47666','0'),
('56402','47667','0'),
('56402','45114','0'),
('56402','45255','0'),
('56402','45169','0'),
('56402','40322','0'),
('56402','40267','0'),
('56402','39728','0'),
('56402','40709','0'),
('56402','40710','0'),
('56402','40708','0'),
-- Druid
('56402','51429','0'),
('56402','51437','0'),
('56402','51423','0'),
('56402','50454','0'),
('56402','50456','0'),
('56402','50457','0'),
-- Without Price
('56402','42591','0'),
('56402','42585','0'),
('56402','42580','0'),
('56402','47671','0'),
('56402','47670','0'),
('56402','47668','0'),
('56402','45509','0'),
('56402','45270','0'),
('56402','46138','0'),
('56402','40342','0'),
('56402','39757','0'),
('56402','40321','0'),
('56402','40711','0'),
('56402','40712','0'),
('56402','40713','0');
