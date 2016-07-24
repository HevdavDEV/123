-- Fix - The Light of Dawn
UPDATE `quest_template` SET RequiredNpcOrGo1 = "0" WHERE id = "12801";
UPDATE `quest_template` SET RequiredNpcOrGoCount1 = "0" WHERE id = "12801";

-- Fix - Despawn Patchwerk
SET @ENTRY := 31099;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Patchwerk - Reset - SMART_ACTION_SET_CORPSE_DELAY");

-- Fix - Acherus NPC Attack
DELETE FROM `creature` WHERE guid IN (130721,130815,130567,130658,130722,130602,130570,130743,130733,130792,130608,130793,130574,130682,130826,130829,130661,130830,130690,130689,130683,130828,130827,130798,130660,130695,130797,130795,130796,130794);
DELETE FROM `creature_addon` WHERE guid IN (130721,130815,130567,130658,130722,130602,130570,130743,130733,130792,130608,130793,130574,130682,130826,130829,130661,130830,130690,130689,130683,130828,130827,130798,130660,130695,130797,130795,130796,130794);

-- Add Portals to Acherus
insert into `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('164335','183325','0','1','1','2324.47','-5658.21','382.241','0.236005','0','0','0.117729','0.993046','300','0','1');
insert into `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('164336','183323','0','1','1','2349.03','-5697.25','382.24','1.08031','0','0','0.514268','0.85763','300','0','1');
insert into `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('164337','183323','0','1','1','2345.98','-5697.64','426.031','0.864333','0','0','0.418839','0.908061','300','0','1');
insert into `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) values('164338','183325','0','1','1','2322.92','-5660.54','426.031','0.196743','0','0','0.0982129','0.995165','300','0','1');

-- Move LK Dragon
DELETE FROM `creature` WHERE guid = "130896";
insert into `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) values('130896','29110','609','1','192','0','0','2322.28','-5731.97','153.92','3.6066','360','0','0','27890000','0','0','0','0','0');

-- Fix Full House - Reanimated Adherent - Reanimated Fanatic
DELETE FROM `spell_script_names` WHERE spell_id in (72495,72496,72497);
INSERT INTO `spell_script_names` VALUES
(72495, 'spell_cultist_dark_martyrdom'),
(72496, 'spell_cultist_dark_martyrdom'),
(72497, 'spell_cultist_dark_martyrdom');

-- DB/NPCs: Little Ooze (Rotface in ICC) can not be taunted, 2012_09_10_06_world_creature_template.sql
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|256 WHERE `entry` IN (36897, 38138); -- Little Ooze

-- Volatile Ooze - Gas Cloud Movement Speed
UPDATE `creature_template` SET speed_walk = "0.6" WHERE `entry` IN (37697,38604,38758,38759);
UPDATE `creature_template` SET speed_walk = "0.8" WHERE `entry` IN (37562,38602,38760,38761);
UPDATE `creature_template` SET speed_run = "0.6" WHERE `entry` IN (37697,38604,38758,38759);
UPDATE `creature_template` SET speed_run = "0.8" WHERE `entry` IN (37562,38602,38760,38761);

-- Fix Precious and Stinky Respawn Time
UPDATE `creature` SET `spawntimesecs` =  '604800' WHERE `creature`.`id` =37025;
UPDATE `creature` SET `spawntimesecs` =  '604800' WHERE `creature`.`id` =37217;

-- Fix Val'kyr Shadowguard Speed 
UPDATE `creature_template` SET speed_walk = "0.242857" WHERE entry IN (36609,39120,39121,39122);
UPDATE `creature_template` SET speed_run = "0.242857" WHERE entry IN (36609,39120,39121,39122);

-- Sindragosa: Fix spell 69762 Unchained Magic - Add internal cooldown with 1 seconds, so multi-spell spells will only apply one stack of triggered spell 69766 (i.e. Chain Heal)
DELETE FROM `spell_proc_event` WHERE `entry` = 69762;
INSERT INTO `spell_proc_event` (entry, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, procFlags, procEx, ppmRate, CustomChance, Cooldown) VALUES
(69762, 0, 0, 0, 0, 0, 81920, 0, 0, 0, 1);

UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (37955,38434,38435,38436); -- Blood-Queen Lana'thel (ICC)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (38004); -- Blood-Queen Lana'thel (Event)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (36853,38265,38266,38267); -- Sindragosa (ICC)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (36609, 39120, 39121, 39122); -- Valkyr Shadowguard
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (37126,38258); -- Sister Svalna
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (37533,38220); -- Rimefang (ICC)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (37534,38219); -- Spinestalker (ICC)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (39747,39823); -- Saviana Ragefire (RS)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (10184,36538); -- Onyxia (Ony)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (24068,31655); -- Annhylde the Caller (UK)
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (11583); -- Nefarian
UPDATE creature_template SET InhabitType = InhabitType | 4 WHERE `entry` IN (27829); -- Ebon Gargyole

-- Add immunities to Little Ooze / Big Ooze
UPDATE `creature_template` SET `mechanic_immune_mask` = 650853247 WHERE `entry` IN (36897, 36899, 38138, 38123);

-- Add interrupt immunity to mini bosses (Rimefang / Raufang)
UPDATE `creature_template` SET `mechanic_immune_mask` = 650853247 WHERE `entry` IN (37533, 38220, 37534, 38219);

-- DB/NPCs: Little Ooze (Rotface in ICC) can not be taunted.
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|256 WHERE `entry` IN (36897, 38138);

-- Set speed values to database for Vile Spirits and InhabitType
UPDATE `creature_template` SET `speed_walk` = 0.5, `speed_run` = 0.5, `InhabitType` = 4 WHERE `entry` IN (37799, 39284, 39285, 39286);

-- Halion immunities
UPDATE creature_template SET mechanic_immune_mask = mechanic_immune_mask | 650854271 WHERE entry IN (
39863, 40142, -- 10 nm
39864, 40143, -- 25 nm
39944, 40144, -- 10 hc
39945, 40145  -- 25 hc
);

-- Halion damage multipliers
UPDATE creature_template SET dmg_multiplier = 70 WHERE entry IN (39863, 40142);  -- 10 nm
UPDATE creature_template SET dmg_multiplier = 100 WHERE entry IN (39864, 40143); -- 25 nm
UPDATE creature_template SET dmg_multiplier = 100 WHERE entry IN (39944, 40144); -- 10 hc
UPDATE creature_template SET dmg_multiplier = 170 WHERE entry IN (39945, 40145); -- 25 hc

-- General Zarithrian damage multipliers
UPDATE `creature_template` SET `mindmg`=497, `maxdmg`=676, `attackpower`=795, `dmg_multiplier`=50 WHERE `entry`=39746;
UPDATE `creature_template` SET `mindmg`=497, `maxdmg`=676, `attackpower`=795, `dmg_multiplier`=90 WHERE `entry`=39805;

-- Saviana Ragefire damage multipliers
UPDATE `creature_template` SET `mindmg`=497, `maxdmg`=676, `attackpower`=795, `dmg_multiplier`=50 WHERE `entry`=39747;
UPDATE `creature_template` SET `mindmg`=497, `maxdmg`=676, `attackpower`=795, `dmg_multiplier`=90 WHERE `entry`=39823;

-- Fix Halion - Orb Rotation Focus visible for players
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=11686, `flags_extra` = `flags_extra` | 128 WHERE `entry` IN (40091, 43280, 43281, 43282);

-- Removes Master's Call stun immunity.
INSERT INTO `spell_linked_spell`(`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (54216,-56651,1,'Removes Master''s Call stun immunity');

-- Disarm Bladestorm
DELETE FROM `spell_linked_spell` WHERE  `spell_trigger`=51722 AND `spell_effect`=-46924 ;
DELETE FROM `spell_linked_spell` WHERE  `spell_trigger`=676 AND `spell_effect`=-46924;
INSERT INTO `spell_linked_spell` VALUES (676, -46924, 1, '(War)Disarm Cancel Bladestorm');
INSERT INTO `spell_linked_spell` VALUES (51722, -46924, 1, '(Rogue)Dismantle Cancel Bladestorm');
INSERT INTO `spell_linked_spell` VALUES (64058, -46924, 1, '(Priest) Psychic Horror Cancel Bladestorm');
DELETE FROM `spell_linked_spell` WHERE  `spell_trigger`=64346 AND `spell_effect`=-46924;
INSERT INTO `spell_linked_spell` VALUES (64346, -46924, 1, '(Mage)Fiery Payback Cancel Bladestorm');
DELETE FROM `spell_linked_spell` WHERE  `spell_trigger`=53359 AND `spell_effect`=-46924;
INSERT INTO `spell_linked_spell` VALUES (53359, -46924, 1, '(Hunter)Chimera Shot(scorpid) Cancel Bladestorm');

-- Add MC Immunity to all NPC's
UPDATE `creature_template` SET mechanic_immune_mask = mechanic_immune_mask + 1 WHERE entry >0;

-- Bags and Totem at Character Creation
insert into `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) values('0','1','5765','4');
insert into `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) values('0','2','5765','4');
insert into `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) values('0','4','5765','4');
insert into `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) values('0','3','5765','3');
insert into `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) values('0','5','5765','4');
insert into `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) values('0','7','5765','4');
insert into `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) values('0','8','5765','4');
insert into `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) values('0','11','5765','4');
insert into `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) values('0','9','5765','4');
insert into `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) values('11','7','46978','1');
insert into `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) values('2','7','46978','1');
insert into `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) values('6','7','46978','1');
insert into `playercreateinfo_item` (`race`, `class`, `itemid`, `amount`) values('8','7','46978','1');

-- Stop Bladestorm when Hand of Protection buff is given
DELETE FROM `spell_linked_spell` WHERE `spell_effect`=-46924;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(1022, -46924, 1, 'Hand of protection (Rank1) - remove bladestorm'),
(5599, -46924, 1, 'Hand of protection (Rank2) - remove bladestorm'),
(10278, -46924, 1, 'Hand of protection (Rank3) - remove bladestorm'),
(66009, -46924, 1, 'Hand of protection (rank1 dupe) - remove bladestorm');

-- Fix Cyclone on Cyclone and Faerie Fire on Cyclone
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) values('33786','-33786','2','Cyclone - Cyclone');
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) values('33786','-16857','2','Cyclone - Faerie Fire (Feral)');
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) values('33786','-770','2','Clyclone - Faerie fire');

-- Fix Brain Freeze - Fingers of Frost
UPDATE `spell_proc_event` SET `procEx` = 0x0040000 WHERE `entry` IN (44546,44548, 44549, 44543, 44545);

-- Fix a bug when pets chasing target even if it's invisible
DELETE FROM `spell_linked_spell` WHERE `spell_effect` = 54661 AND `spell_trigger` IN (32612,5215,1784);
INSERT INTO `spell_linked_spell` VALUES
(32612,54661,0,'Invisibility Sanctuary Effect'),
(5215,54661,0,'Prowl Sanctuary Effect'),
(1784,54661,0,'Stealth Sanctuary Effect');

-- Fix Killing Machine PPM
UPDATE `spell_proc_event` SET cooldown = "5" WHERE entry IN (51123, 51127, 51128, 51129, 51130);

-- Fix ToC Raid and ToC Heroic Maps
delete from `disables` where entry in (649,650);
insert into `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) values('7','649','0','','','Disable Mmap - Trial of the Crusader');
insert into `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) values('7','650','7','','','Disable Mmap - Trial of the Champion');

-- Custom Stackeables Values
UPDATE `item_template` SET Stackable = "1000" WHERE entry = "21177";
UPDATE `item_template` SET Stackable = "100" WHERE entry = "9186";
UPDATE `item_template` SET Stackable = "100" WHERE entry = "44605";
UPDATE `item_template` SET Stackable = "100" WHERE entry = "44614";
UPDATE `item_template` SET Stackable = "100" WHERE entry = "3776";
UPDATE `item_template` SET Stackable = "100" WHERE entry = "43231";
UPDATE `item_template` SET Stackable = "100" WHERE entry = "43233";
UPDATE `item_template` SET Stackable = "100" WHERE entry = "43235";
UPDATE `item_template` SET Stackable = "100" WHERE entry = "43237";
UPDATE `item_template` SET Stackable = "100" WHERE entry = "44615";
UPDATE `item_template` SET Stackable = "20" WHERE entry = "17033";
UPDATE `item_template` SET Stackable = "5" WHERE entry = "6265";

-- Crossfaction Bg Minplayersperteam
UPDATE `battleground_template` SET Minplayersperteam = "3", Weight = "7" WHERE id IN (2,3,7,9,32);

-- Disable Alterac Valley - Isle of Conquest
insert into `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) values('3','1','0','','','Battleground - Alterac Valley');
insert into `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) values('3','30','0','','','Battleground - Isle of Conquest');

-- Update ALL ICC Immunities
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`
|1 -- CHARM
|2 -- DISORIENTED
|4 -- DISARM
|8 -- DISTRACT
|16 -- FEAR
|32 -- GRIP
|64 -- ROOT
|256 -- SILENCE
|512 -- SLEEP
|1024 -- SNARE
|2048 -- STUN
|4096 -- FREEZE
|8192 -- KNOCKOUT
|65536 -- POLYMORPH
|131072 -- BANISH
|524288 -- SHACKLE
|4194304 -- TURN
|8388608 -- HORROR
|67108864 -- DAZE
|536870912 -- SAPPED
WHERE `entry` IN
(36612,37957,37958,37959, -- Lord Marrowgar
36619,38233,38459,38460, -- Bone Spike
36855,38106,38296,38297, -- Lady Deathwhisper
38490,38494, -- Root Giante
37813,38402,38582,38583, -- Deathbringer Saurfang
36626,37504,37505,37506, -- Festergut
36627,38390,38549,38550, -- Rotface
36897,38138, -- Little Ooze
36899,38123, -- Big Ooze
36678,38431,38585,38586, -- Professor Putricide
37697,38604,38758,38759, -- Volatile Ooze
37562,38602,38760,38761, -- Gas Cloud
37970,38401,38784,38785, -- Prince Valanar
37972,38399,38769,38770, -- Prince Keleseth
37973,38400,38771,38772, -- Prince Taldaram
38369, -- Dark Nucleus 
38454,38775,38776,38777, -- Kinetic Bomb
37955,38434,38435,38436, -- Blood-Queen Lana'thel
37126,38258, -- Sister Svalna
37533,38220, -- Rimefang
37534,38219, -- Spinestalker
36853,38265,38266,38267, -- Sindragosa
36597,39166,39167,39168, -- The Lich King
37698,39299,39300,39301, -- Shambling Horror
37695,39309,39310,39311, -- Drudge Ghoul
36633,39305,39306,39307, -- Ice Sphere
36701,39302,39303,39304, -- Raging Spirit
36609,39120,39121,39122, -- Val'kyr Shadowguard
37799, 39284, 39285, 39286, -- Vile Spirits
39190,39287,39288,39289, -- Wicked Spirit
36824,39296); -- Spirit Warden

-- Fix ICC Maps
delete from `disables` where entry in (631);
insert into `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) values('7','631','0','','','Disable Mmap - Icecrown Citadel');

-- Fix Shadowmeld.
DELETE FROM spell_script_names WHERE spell_id = 58984;
INSERT INTO spell_script_names VALUES (58984, 'spell_gen_shadowmeld');

-- Dancing Rune No Attack No Select
UPDATE `creature_template` SET unit_flags = "33685504" WHERE entry = "27893"

-- Fix Chill of the Thrones being removed by Divine Intervention.
insert into `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) values('19753','69127','1','Chill of the Throne - Divine Intervention.');

-- Spawn Elemental Totems
UPDATE `creature_template` SET `spell1`=32982 WHERE `entry`=15439;
UPDATE `creature_template` SET `spell1`=33663 WHERE `entry`=15430;

-- Fix Spirit Bomb Speed
UPDATE `creature_template` SET speed_run =0.4 WHERE entry =39189;

-- Friendly Rep Requiered Reputation Commendation Badges
UPDATE `item_template` SET RequiredReputationFaction = 1119, RequiredReputationRank = 4 WHERE entry = "49702";
UPDATE `item_template` SET RequiredReputationFaction = 1091, RequiredReputationRank = 4 WHERE entry = "44710";
UPDATE `item_template` SET RequiredReputationFaction = 1106, RequiredReputationRank = 4 WHERE entry = "44711";
UPDATE `item_template` SET RequiredReputationFaction = 1098, RequiredReputationRank = 4 WHERE entry = "44713";
UPDATE `item_template` SET RequiredReputationFaction = 1090, RequiredReputationRank = 4 WHERE entry = "43950";

-- Quest The Refiner's Fire now requieres Mending Fences to be complete
UPDATE `quest_template` SET PrevQuestId = 12915 WHERE id = "12922";

-- Warlock Glyph of Succubus
DELETE FROM `spell_script_names` WHERE `spell_id`=6358;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(6358,'spell_warl_seduction');

-- Freeze Trap removes Stealth and Prowl.
INSERT INTO spell_linked_spell (spell_trigger, spell_effect, type,
comment) VALUES 
(60210, -1784, 1, 'Freezing Arrow removes Stealth'),
(3355, -1784, 1, 'Freezing Trap R1 removes Stealth'),
(14308, -1784, 1, 'Freezing Trap R2 removes Stealth'),
(14309, -1784, 1, 'Freezing Trap R3 removes Stealth'),
(60210, -5215, 1, 'Freezing Arrow removes Prowl'),
(3355, -5215, 1, 'Freezing Trap R1 removes Prowl'),
(14308, -5215, 1, 'Freezing Trap R2 removes Prowl'),
(14309, -5215, 1, 'Freezing Trap R3 removes Prowl');

-- Fire Elemental
DELETE FROM `spell_bonus_data` WHERE `entry` IN (13376,57984);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`,`ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(13376,0.032,-1,-1,-1,'Greater Fire Elemental - Fire Shield'),
(57984,0.4289,-1,-1,-1,'Greater Fire Elemental - Fire Blast');