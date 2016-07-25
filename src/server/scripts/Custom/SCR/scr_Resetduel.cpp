/*Duel Reset info. 
-------------------------------------------------------------------------------------
/* Made by SymbolixDEV
Script for: On Duel End Reset Hp , Cooldowns , cast stop , attack stop etc..
Working on 19.3.2014 REV
Compile Success
Working : Test and work 100%
What is good on this script ?

izgubi = losser
pobeditel = winner

_________________________
player->CastStop(); - Stop Cast on Duel End and give Evade 
player->Attackstop(); - Stop Attack on duel end !
player->SetHealth(Losser->GetMaxHealth()); - set winner health to max 
player->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE); - Remove Auras on Duel End
player->RemoveAllSpellCooldown(); - Remove All Cooldowns on Duel End Again
NOT CHANSE FOR DIE PEOPLE WITH THIS DUEL SCRIPT
http://github.com/SymbolixDEV
Thanks ! 
--------------------------------------------------------------------------------------
*/
// SymbolxiDEV Start !

// Please all remove my credits don't remove Credits !
//Thanks SYMBOLIXDEV !
#include "ScriptPCH.h"
#include "Map.h"

enum spells 
{
	POWER_WORD_FORTITUDE = 48162,
	PRAYER_OF_SPRITE = 48074,
	SHADOW_BUFF = 48170,
	KINGS_BUFF = 43223,
	ARCANE_BUFF = 36880,
	MARK_OF_THE_WILD = 48469
};

class Reset_OnDuelEnd : public PlayerScript
{
public:
    Reset_OnDuelEnd() : PlayerScript("Reset_OnDuelEnd") {  }

	void OnDuelStart(Player * winner, Player * loser)
    {
        if (winner->getPowerType() == POWER_ENERGY)
            winner->SetPower(POWER_ENERGY, winner->GetMaxPower(POWER_ENERGY));
        if (winner->getPowerType() == POWER_RAGE)
            winner->SetPower(POWER_RAGE, 10);
    }

    void OnDuelEnd(Player *player, Player *izgubi/*, Player *pet* SymbolixDEV */, DuelCompleteType type)
    {
			//Set Max Healt [START] //
            player->SetHealth(player->GetMaxHealth());
            izgubi->SetHealth(izgubi->GetMaxHealth());
			if ( player->getPowerType() == POWER_MANA )
            player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
			if ( izgubi->getPowerType() == POWER_MANA )
            izgubi->SetPower(POWER_MANA, izgubi->GetMaxPower(POWER_MANA));
			//Set Max Healt [END]
			// Cast And Attack Stop [Start] //
			player->CastStop();
			izgubi->CastStop();
			player->AttackStop();
			izgubi->AttackStop();
			// Cast And Attack Stop [END] //
			
			//Remove Cooldowns [START] //
			player->RemoveAllSpellCooldown();
			izgubi->RemoveAllSpellCooldown();
			//Remove Cooldowns [END} //
			//Combat Stop [START]
			player->CombatStop();
			izgubi->CombatStop();
			//Combat Stop [END] //
			//Remove Auras On duel end Sickness
			player->RemoveAura(15007);
			izgubi->RemoveAura(15007);
			//Winner Buffs !
			player->CastSpell(player, POWER_WORD_FORTITUDE, true);
			player->CastSpell(player, KINGS_BUFF, true);
			player->CastSpell(player, MARK_OF_THE_WILD, true);
			player->CastSpell(player, PRAYER_OF_SPRITE, true);
			player->CastSpell(player, SHADOW_BUFF, true);
            player->GetSession()->SendNotification("You are win on duel!");
			izgubi->GetSession()->SendNotification("You are lose on duel!");
			//Winner +3 Badge ! 
			player->AddItem(45624, 3);
			// Some Remove Auras from Periodic Damage !
			player->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
			izgubi->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
	}
};

void AddSC_Reset()
{
    new Reset_OnDuelEnd;
}