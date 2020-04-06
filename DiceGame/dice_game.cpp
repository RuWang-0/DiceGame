#include "dice_game.h"
#include <cstdlib>
#include <ctime>

// random will return a random int value between [0,x)
unsigned int random(int x)
{
	return rand() % x;
}

CDiceGame::CDiceGame()
{
	srand(time(nullptr));
	m_firstRes = m_secondRes = -1;
}

void CDiceGame::roll_dice()
{
	if (m_secondRes)
	{
		show_info(IMPROPER);
		return;
	}
	unsigned int res = random(6) + 1;
	if (!m_firstRes)
	{
		m_firstRes = res;
		show_info(ROLL_RES1, res);
	}
	else
	{
		m_secondRes = res;
		show_info(ROLL_RES2, res);
		cal_res();
	}
}

void CDiceGame::cal_res()
{
	// TODO: NEED TO CATCH ZERO WRONG
	const unsigned int finalRes = m_firstRes + m_secondRes;
	show_info(FINAL_RES, finalRes);
	if (finalRes == 7)
		show_info(WIN);
	else
		show_info(LOST);
	initial_game();
}

void CDiceGame::loop_game()
{
	while (true)
	{
		show_info(COMMAND);
		char userInput = read_input();
		switch (userInput)
		{
		case 'q':
			show_info(LEAVE);
			return;
		case 's':
			show_info(START);
			break;
		case 'r':
			show_info(ROLL);
			roll_dice();
			break;
		default:
			show_info(IMPROPER);
		}
	}
}

void CDiceGame::show_info(INFO_TYPE infoType, const unsigned infoValue) const
{
	// TODO:ERROR TYPE CATCH EXCEPTION
	switch (infoType)
	{
	case COMMAND:
		show_basic_info("Please input your command('s' to start, 'r' to roll the dice ,'q' to quit)");
		break;
	case START:
		show_basic_info("Let's start playing games!");
		break;
	case LEAVE:
		show_basic_info("BYE-BYE!");
		break;
	case ROLL:
		show_basic_info("Dice is rolling...");
		break;
	case ROLL_RES1:
		if (infoValue)
			show_basic_info("The first dice rolling result is " + to_string(infoValue));
		// else
			// TODO: MUST BE STH WRONG, TYR TO CATCH THAT
		break;
	case ROLL_RES2:
		if (infoValue)
			show_basic_info("The second dice rolling result is " + to_string(infoValue));
		// else
			// TODO: MUST BE STH WRONG, TYR TO CATCH THAT
		break;
	case FINAL_RES:
		if (infoValue)
			show_basic_info("So the final result is " + to_string(infoValue));
		// else
			// TODO: EXCEPTION INSPECTION
		break;
	case WIN:
		show_basic_info("Congratulations!!! You have WON this game!");
		break;
	case LOST:
		show_basic_info("Sorry, you have lost this game this time. Why not again?");
		break;
	case IMPROPER:
		show_basic_info("The command you just input is not proper, please input again");
	}
}



