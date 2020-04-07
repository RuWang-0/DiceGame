#pragma once
#ifndef DICE_H
#define DICE_H

unsigned int random(int x);

class CDice
{
private:
	unsigned int m_upVal;

public:
	CDice() :m_upVal(0){};
	unsigned rollDice()
	{
		m_upVal = random(6) + 1;
		return m_upVal;
	}
	unsigned showVal()const
	{
		return m_upVal;
	}
	void reset()
	{
		m_upVal = 0;
	}
};



#endif
