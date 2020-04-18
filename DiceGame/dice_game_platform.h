#pragma once
#ifndef DICE_GAME_PLATFORM_H
#define DICE_GAME_PLATFORM_H
#include "player.h"
#include <set>
#include <list>

class CDiceGamePlatform
{
private:
	// defined as static for thread security
	static CDiceGamePlatform* singleInstance;
	set<CPlayer&>m_players;
	
	
protected:
	CDiceGamePlatform();
public:
	static CDiceGamePlatform* getInstance()
	{
		return singleInstance;
	}
	// ×¢²á³É¹¦·µ»ØCPlayerÖ¸Õë£¬Ê§°Ü·µ»Ønullptr
	shared_ptr<CPlayer> regPlayer(string player_name);

	// playerµÇÂ¼
	
};


#endif
