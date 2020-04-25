#include "dice_game_platform.h"

CDiceGamePlatform* CDiceGamePlatform::singleInstance = new CDiceGamePlatform();

CDiceGamePlatform::CDiceGamePlatform()
{
	regPlayer("A"); regPlayer("B");
}

shared_ptr<CPlayer> CDiceGamePlatform::regPlayer(string player_name)
{
	shared_ptr<CPlayer>new_player = make_shared<CPlayer>(player_name);
	auto res = m_players.insert(*new_player);
	if (res.second)
		return new_player;
	return nullptr;
}

