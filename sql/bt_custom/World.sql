-- Add additional checks
insert into `warden_checks` (`id`, `type`, `data`, `str`, `address`, `length`, `result`, `comment`) values('791','243','','','7728616','1','75','Simplefly');
insert into `warden_checks` (`id`, `type`, `data`, `str`, `address`, `length`, `result`, `comment`) values('788','243','','','9993834','1','74','Simplefly');
insert into `warden_checks` (`id`, `type`, `data`, `str`, `address`, `length`, `result`, `comment`) values('789','243','','','9993835','1','52','Simplefly');
insert into `warden_checks` (`id`, `type`, `data`, `str`, `address`, `length`, `result`, `comment`) values('790','243','','','7277234','8','85F60F86F2000000','Simplefly - speedhack');
insert into `warden_checks` (`id`, `type`, `data`, `str`, `address`, `length`, `result`, `comment`) values('792','191','1E15223BF7DD461696FB25488B72FDE017D1AB7056A1273B','','583955','40','','Hitch Hiker - 0x05 Packet');
insert into `warden_checks` (`id`, `type`, `data`, `str`, `address`, `length`, `result`, `comment`) values('793','191','2FD8E5D46A57F471DE8C7DA01815AF6653B4B34BAEFD3F6B','','583955','40','','Hitch Hiker - 20 HMAC Seed');
insert into `warden_checks` (`id`, `type`, `data`, `str`, `address`, `length`, `result`, `comment`) values('794','191','98FD2423C3EC3B0867A960C94FF31583428A72C3AEFD3F6B','','583955','40','','Hitch Hiker - 16 HMAC Seed');
insert into `warden_checks` (`id`, `type`, `data`, `str`, `address`, `length`, `result`, `comment`) values('795','191','36F330EF890C237526929B959613982D3D035DABAEFD3F6B','','583955','40','','Hitch Hiker - No HMAC Seed');

--ICC. Fix spawntime blood orb controller.
-- UPDATE `creature` SET `spawntimesecs`='604800' WHERE `guid`='104364';

-- ICC T10 Mage Vendor
UPDATE `creature_template` SET `faction_A` = '2070' , `faction_H` = '2070' WHERE `entry` = '38284'; 

-- Fix Titanium Lockbox Drop
UPDATE `world`.`creature_loot_template` SET `ChanceOrQuestChance` = '0.03' WHERE `entry` = '31787' AND `item` = '43624'; 

-- Fix Shadowmeld generic elfs race spell
INSERT INTO `spell_script_names` VALUES
('58984', 'spell_gen_shadowmeld');

-- Master the Storm, http://www.wowhead.com/quest=11895
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES('26048','63238','0','0');
UPDATE smart_scripts SET id = '0', link = '1' WHERE entryorguid = '26048' AND id = '1'; 
UPDATE smart_scripts SET id = '1' WHERE entryorguid = '26048' AND id = '2'; 

-- Fix http://ru.wowhead.com/item=44115
insert into `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) values('32296','0','44115','0','0','2576');
insert into `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) values('32294','0','44115','0','0','2576');