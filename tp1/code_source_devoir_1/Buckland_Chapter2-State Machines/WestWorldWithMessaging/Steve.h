#ifndef STEVE_H
#define STEVE_H
//------------------------------------------------------------------------
//
//  Name:   Miner.h
//
//  Desc:   A class defining a goldminer.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <string>
#include <cassert>
#include <iostream>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
#include "SteveOwnedStates.h"
#include "fsm/StateMachine.h"

template <class entity_type> class State;
struct Telegram;

class Steve : public BaseGameEntity
{
private:

	//an instance of the state machine class
	StateMachine<Steve>*  m_pStateMachine;

	location_type         m_Location;

	bool                   m_isDrunk;

public:

	Steve(int id) :m_Location(saloon),
		m_isDrunk(false),
		BaseGameEntity(id)

	{
		//set up state machine
		m_pStateMachine = new StateMachine<Steve>(this);

		m_pStateMachine->SetCurrentState(Drinking::Instance());

	}

	~Steve() { delete m_pStateMachine; }

	//this must be implemented
	void Update();

	//so must this
	virtual bool  HandleMessage(const Telegram& msg);

	StateMachine<Steve>* GetFSM()const { return m_pStateMachine; }

	//-------------------------------------------------------------accessors
	location_type Location()const { return m_Location; }
	void          ChangeLocation(location_type loc) { m_Location = loc; }

	bool          Drunk()const { return m_isDrunk; }
	void          SetDrunk(bool val) { m_isDrunk = val; }
};


#endif
