#ifndef AgentLeader_H
#define AgentLeader_H

//------------------------------------------------------------------------
//
//  Name:   AgentLeader.h
//
//  Desc:   This is an agent leader, other agent poursur will follow it
//
//  Author: Lijun Zheng
//
//------------------------------------------------------------------------
#include "Vehicle.h"

class AgentLeader : public Vehicle {

private:
	bool m_isManControl;
	Vector2D m_direction;
	float m_moveRight;
	float m_moveUp;

public:
	AgentLeader(GameWorld* world,
		Vector2D position,
		double    rotation,
		Vector2D velocity,
		double    mass,
		double    max_force,
		double    max_speed,
		double    max_turn_rate,
		double    scale,
		VehicleType type,
		bool manControl);


	~AgentLeader();

	void    Update(double time_elapsed);

	bool     ManControl()const { return m_isManControl; }
	void     ToggleManControl() { m_isManControl = !m_isManControl; }

	void SetDirection(Vector2D direction) { m_direction += direction; m_direction.Normalize(); }
	Vector2D Direction()const { return m_direction; }
};
#endif