#pragma once
#include "Component.h"
class MoveComponent;
class Agent;

class SeekBehavior  : 
	public Component {
public:
	SeekBehavior(Actor* m_target);
	~SeekBehavior(); //Deallocates memory 

	void setTarget(Actor* target) { m_target = target; }
	Actor* getTarget() const { return m_target;}

	void setForce(float force) { m_force = force; }

	void update(float deltaTime) override; 

private:
	Actor* m_target;
	float m_force;
};

