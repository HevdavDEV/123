DELETE FROM `command` WHERE `name` = 'challenge';	
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('challenge', 1, 'Syntax: .challenge $subcommand $player1 $player2.\nAllow to join arena two party leader.');
DELETE FROM `command` WHERE `name` = 'challenge 2x2';	
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('challenge 2x2', 1, 'Syntax: .challenge 2x2 $player1 $player2\nUse .help challenge for more info.');
DELETE FROM `command` WHERE `name` = 'challenge 3x3';	
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('challenge 3x3', 1, 'Syntax: .challenge 3x3 $player1 $player2\nUse .help challenge for more info.');
DELETE FROM `command` WHERE `name` = 'challenge 5x5';	
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('challenge 5x5', 1, 'Syntax: .challenge 5x5 $player1 $player2\nUse .help challenge for more info.');