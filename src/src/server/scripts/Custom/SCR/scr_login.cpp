/************************************
*            Login Script           *
*			SymboliXDEV				*
************************************/

 
//Credit to SymbolixDEV for original.
 
class login_script : public PlayerScript
{
public:
	login_script() : PlayerScript("login_script") { }
 
	void OnLogin(Player* player)
	{
		player->GetSession()->SendNotification("|cffff0000Welcome to RageFire!! |r");
	}
};
 
void AddSC_login_script()
{
	new login_script();
}