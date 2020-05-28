#include "AgentChaser.h"

AgentChaser::AgentChaser(GameWorld * world,
						Vector2D position, double rotation, 
						Vector2D velocity, 
						double mass, 
						double max_force, 
						double max_speed, 
						double max_turn_rate, 
						double scale,
						VehicleType type) : Vehicle(world,
												position,
												rotation,
												velocity,
												mass,
												max_force,
												max_speed,
												max_turn_rate,
												scale)
{
	Vehicle::SetVehicleType(type);
}

AgentChaser::~AgentChaser()
{
	//delete Vehicle::Steering();
	//delete Vehicle::HeadingSmoother();
}
