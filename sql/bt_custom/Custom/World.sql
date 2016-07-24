-- удаляем Шатры, саурфанга бьют на них.
DELETE FROM gameobject WHERE map = '631' AND id IN (201886, 201887, 201868, 196417);

-- Auc in dalaran.
insert into `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) values('298375','8661','571','1','1','0','0','5797.91','643.95','647.481','2.42304','300','0','0','6645','0','0','0','0','0');
insert into `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) values('298392','8661','571','1','1','0','0','5799.4','632.766','647.468','3.91137','300','0','0','6645','0','0','0','0','0');

-- add vendor in frozen halls.
insert into `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) values('300005','29491','571','1','1','0','0','5657.49','2035.63','798.042','3.42348','300','0','0','3256','7981','0','0','0','0');

-- Book of Glyph Mastery, to high drop wiith x4 drop rate.
UPDATE creature_loot_template SET ChanceOrQuestChance = '0.05' WHERE item = '45912';
