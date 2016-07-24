/* add rbac permissions to new commands */
DELETE FROM `rbac_permissions` WHERE `id` IN (1100, 1101, 1102, 1103,1104);
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(1105,'Command: anticheat global'),
(1106,'Command: anticheat player'),
(1107,'Command: anticheat handle'),
(1108,'Command: anticheat delete');

DELETE FROM `rbac_linked_permissions` WHERE `id` IN (1100, 1101, 1102, 1103,1104);
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
/* adds qc status to players */
(193, 1105),
(193, 1106), 
(193, 1107), 
(193, 1108);