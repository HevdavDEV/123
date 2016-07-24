#include "ScriptPCH.h"

class SymbolixDevArenaSystem : public PlayerScript
{
    public:
        SymbolixDevArenaSystem() : PlayerScript("SymbolixDevArenaSystem") {	}

    void OnPVPKill(Player* ubivam, Player* pedal)
    {
	if (ubivam->GetMap()->IsBattleArena())
	{
		ubivam->GetSession()->SendNotification("You just killed %s and stole his soul!", pedal->GetName());
		ubivam->AddItem(29434, 1);
	}
    }
};

void AddSC_SymbolixDevArenaSystem()
{
    new SymbolixDevArenaSystem;
}