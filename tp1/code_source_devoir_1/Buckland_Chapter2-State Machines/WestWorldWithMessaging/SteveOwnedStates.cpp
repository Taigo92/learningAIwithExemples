#include "SteveOwnedStates.h"
#include "fsm/State.h"
#include "Steve.h"
#include "Locations.h"
#include "messaging/Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "Time/CrudeTimer.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;


#ifdef TEXTOUTPUT
#include <fstream>
#include "SteveOwnedStates.h"
extern std::ofstream os;
#define cout os
#endif

//-------------------------------------------------------------------------Drinking

Drinking * Drinking::Instance()
{
	static Drinking instance;

	return &instance;
}

void Drinking::Enter(Steve * steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "The wine is so yummy!";
}

void Drinking::Execute(Steve * steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "execute drinking!!";

	if ((rand()) / (RAND_MAX + 1.0) < 0.1) {
		steve->GetFSM()->ChangeState(Drunk::Instance());
	}
}

void Drinking::Exit(Steve * steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "exit drinking!";
}

bool Drinking::OnMessage(Steve * agent, const Telegram & msg)
{
	return false;
}



//-------------------------------------------------------------------------Drunk
//------------------------------------------------------------------------Drunk

Drunk* Drunk::Instance()
{
	static Drunk instance;

	return &instance;
}


void Drunk::Enter(Steve* steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "I am drunk maybe!";
	
}

void Drunk::Execute(Steve* steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "Bob, u are shit!";

	//Defy Steve
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
		steve->ID(),        //ID of sender
		ent_Miner_Bob,            //ID of recipient
		Msg_Defy,   //the message
		NO_ADDITIONAL_INFO);
}

void Drunk::Exit(Steve* steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "I'm so sorry about what i did";
}


bool Drunk::OnMessage(Steve* steve, const Telegram& msg)
{
	//send msg to global message handler
	switch (msg.Msg)
	{
	case Msg_BeHit:
	{
		SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "\nMessage received by " << GetNameOfEntity(steve->ID()) <<
			" it is so hurt: ";

		steve->GetFSM()->ChangeState(Drinking::Instance());
	}

	return true;

	}//end switch

	return false;
}