#include "AgentChaser.h"
#include "SteeringBehaviors.h"

AgentChaser::AgentChaser(GameWorld * world,
						Vector2D position, double rotation, 
						Vector2D velocity, 
						double mass, 
						double max_force, 
						double max_speed, 
						double max_turn_rate, 
						double scale,
						VehicleType type,
						Vehicle* currentLeader) : Vehicle(world,
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
	previousLeader = currentLeader;
	Vehicle::Steering()->OffsetPursuitOn(previousLeader, Vector2D(0, 0.0001));

	if (Vehicle::Type() == VehicleType::chaser) {
		Vehicle::Steering()->SeparationOn();
	} 
	
}

AgentChaser::~AgentChaser()
{
	//delete Vehicle::Steering();
	//delete Vehicle::HeadingSmoother();
}

void AgentChaser::Update(double time_elapsed)
{
	Vehicle::Update(time_elapsed);
}