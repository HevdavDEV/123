

    #include "ScriptPCH.h"
    class Boss_Announcer : public PlayerScript
    {
    public:
    Boss_Announcer() : PlayerScript ("Boss_Announcer") {}
    void OnCreatureKill(Player* player, Creature* boss)
    {
    if (boss->isWorldBoss() && player->GetGuild())
    {
		std::string boss_n = boss->GetName();
		std::string tag_colour = "FF0000";
		std::string plr_colour = "F7FE2E";
		std::string boss_colour = "FF9512";
		std::string gld_colour = "00FF00";
		std::ostringstream stream;
		std::string plrdiff;
		int plrdifff = player->GetRaidDifficulty();
		std::string plr_guild = player->GetGuildName();
    if (plrdifff == 0) 
		{
			plrdiff = ("10 Normal");
		}
    if (plrdifff == 1) 
		{
			plrdiff = ("25 Normal");
		}
    if (plrdifff == 2)
		{
			plrdiff = ("10 Heroico");
		}
    if (plrdifff == 3) 
		{
			plrdiff = ("25 Heroico");
		}
       
	if (plrdifff ==0) 
	{
    /*10H-Bosses ICC */
	if (boss_n == "The Lich King" || boss_n == "Professor Putricide" || boss_n == "Sindragosa" || boss_n == "Blood-Queen Lana'thel" || boss_n == "Halion" || boss_n == "Kel'Thuzad" || boss_n =="Anub'arak") 
	{
		if (boss_n == "The Lich King") 
		{
			boss_n = ("El Rey Exánime");
		}
		if (boss_n == "Professor Putricide")
		{
			boss_n = ("Profesor Putricidio");
		}
	    if (boss_n == "Blood-Queen Lana'thel") 
		{
			boss_n = ("Reina de Sangre Lana'thel");
		}
		stream << "|CFF" << tag_colour <<
		"[Boss-Announcer]:|r |cff" << plr_colour << "The Brotherhood|cff" << gld_colour << "[" <<
		plr_guild << "]|r has defeated |CFF" << boss_colour << "[" << boss_n << "]|r difficulty mode [" << plrdiff << "]!";
		sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
    }
    }   
	   
    if (plrdifff ==1) 
	{
    /*10H-Bosses ICC */
	if (boss_n == "The Lich King" || boss_n == "Professor Putricide" || boss_n == "Sindragosa" || boss_n == "Blood-Queen Lana'thel" || boss_n == "Halion" || boss_n == "Kel'Thuzad" || boss_n =="Anub'arak") 
	{
		if (boss_n == "The Lich King") 
		{
			boss_n = ("El Rey Exánime");
		}
		if (boss_n == "Professor Putricide")
		{
			boss_n = ("Profesor Putricidio");
		}
	    if (boss_n == "Blood-Queen Lana'thel") 
		{
			boss_n = ("Reina de Sangre Lana'thel");
		}
		stream << "|CFF" << tag_colour <<
		"[Boss-Announcer]:|r |cff" << plr_colour << "The Brotherhood |cff" << gld_colour << "[" <<
		plr_guild << "]|r has defeated |CFF" << boss_colour << "[" << boss_n << "]|r difficulty mode [" << plrdiff << "]!";
		sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
    }
    }
	
	
    if (plrdifff ==2) 
	{
    /*10H-Bosses ICC */
	if (boss_n == "The Lich King" || boss_n == "Professor Putricide" || boss_n == "Sindragosa" || boss_n == "Blood-Queen Lana'thel" || boss_n == "Halion" || boss_n == "Kel'Thuzad" || boss_n =="Anub'arak") 
	{
		if (boss_n == "The Lich King") 
		{
			boss_n = ("El Rey Exánime");
		}
		if (boss_n == "Professor Putricide")
		{
			boss_n = ("Profesor Putricidio");
		}
	    if (boss_n == "Blood-Queen Lana'thel") 
		{
			boss_n = ("Reina de Sangre Lana'thel");
		}
		stream << "|CFF" << tag_colour <<
		"[Boss-Announcer]:|r |cff" << plr_colour << "The Brotherhood |cff" << gld_colour << "[" <<
		plr_guild << "]|r has defeated |CFF" << boss_colour << "[" << boss_n << "]|r difficulty mode [" << plrdiff << "]!";
		sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
    }
    }
   

	if (plrdifff ==3) {
    /*25H-Bosses ICC */	
	if (boss_n == "The Lich King" || boss_n == "Professor Putricide" || boss_n == "Sindragosa" || boss_n == "Blood-Queen Lana'thel" || boss_n == "Halion" || boss_n == "Kel'Thuzad" || boss_n =="Anub'arak") 
	{
    if (boss_n == "The Lich King") 
	{
		boss_n = ("El Rey Exánime");
    }
    if (boss_n == "Professor Putricide")
	{
		boss_n = ("Profesor Putricidio");
    }
    if (boss_n == "Blood-Queen Lana'thel")
	{
		boss_n = ("Reina de Sangre Lana'thel");
    }
 		stream << "|CFF" << tag_colour <<
		"[Boss-Announcer]:|r |cff" << plr_colour << "The Brotherhood |cff" << gld_colour << "[" <<
		plr_guild << "]|r has defeated |CFF" << boss_colour << "[" << boss_n << "]|r difficulty mode [" << plrdiff << "]!";
		sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
    }
    }
    }
    };
    };
    void AddSC_Boss_Announcer()
    {
    new Boss_Announcer;
    }
