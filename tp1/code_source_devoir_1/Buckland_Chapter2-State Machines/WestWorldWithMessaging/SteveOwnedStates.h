#ifndef STEVE_OWNED_STATES_H
#define STEVE_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   MinerOwnedStates.h
//
//  Desc:   All the states that can be assigned to the Miner class.
//          Note that a global state has not been implemented.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "fsm/State.h"


class Steve;
struct Telegram;


//------------------------------------------------------------------------
//
//  miner changes location to the saloon and keeps buying Whiskey until
//  his thirst is quenched. When satisfied he returns to the goldmine
//  and resumes his quest for nuggets.
//------------------------------------------------------------------------
class Drinking : public State<Steve>
{
private:

	Drinking() {}

	//copy ctor and assignment should be private
	Drinking(const Drinking&);
	Drinking& operator=(const Drinking&);

public:

	//this is a singleton
	static Drinking* Instance();

	virtual void Enter(Steve* steve);

	virtual void Execute(Steve* steve);

	virtual void Exit(Steve* steve);

	virtual bool OnMessage(Steve* agent, const Telegram& msg);
};


//------------------------------------------------------------------------
//
//  this is implemented as a state. Steve gets drunk
//  
//------------------------------------------------------------------------
class Drunk : public State<Steve>
{
private:

	Drunk() {}

	//copy ctor and assignment should be private
	Drunk(const Drunk&);
	Drunk& operator=(const Drunk&);

public:

	//this is a singleton
	static Drunk* Instance();

	virtual void Enter(Steve* steve);

	virtual void Execute(Steve* steve);

	virtual void Exit(Steve* steve);

	virtual bool OnMessage(Steve* agent, const Telegram& msg);
};

//------------------------------------------------------------------------
//
//  this is implemented as a state. Steve gets into fight state
//  
//------------------------------------------------------------------------
class Fighting : public State<Steve>
{
private:

	Fighting() {}

	//copy ctor and assignment should be private
	Fighting(const Fighting&);
	Fighting& operator=(const Fighting&);

public:

	//this is a singleton
	static Fighting* Instance();

	virtual void Enter(Steve* steve);

	virtual void Execute(Steve* steve);

	virtual void Exit(Steve* steve);

	virtual bool OnMessage(Steve* agent, const Telegram& msg);
};

#endif
