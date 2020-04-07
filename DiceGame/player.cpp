#include "player.h"
#include <iostream>

char CPlayer::readCommand()
{
	std::cin >> m_curCommand;
	return m_curCommand;
}

void CPlayer::playGame()
{
	char command;
	while (!m_isFinished)
	{
		command = readCommand();
		dealCommand(command);
	}
}