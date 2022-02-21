#include "WanderBehavior.h"
#include "Actor.h"
#include "Transform2D.h"
#include <Vector2.h>
#include <time.h>
#include <iostream>
#include "MoveComponent.h"

WanderBehavior::WanderBehavior(float radius, float distance)
{
	m_radius = radius;
	m_distance = distance;
	m_force = 200;
}

void WanderBehavior::update(float deltaTime)
{
	std::srand(time(NULL));

	MathLibrary::Vector2 circlePos = getOwner()->getTransform()->getWorldPosition() + (getOwner()->getTransform()->getForward() * m_distance);
	MathLibrary::Vector2 randomPnt = (MathLibrary::Vector2(((double) rand() / (RAND_MAX + 1)), (double)rand() / (RAND_MAX + 1))).getNormalized() * m_radius;
	randomPnt = randomPnt + circlePos;


	MathLibrary::Vector2 direction =
		(randomPnt - getOwner()->getTransform()->getWorldPosition()).getNormalized() * m_force;

	MoveComponent* moveComponent = dynamic_cast<MoveComponent*>(getOwner()->getComponent("MoveComponent"));

	getOwner()->getTransform()->setForward(direction);

	MathLibrary::Vector2 newVelocity = direction - moveComponent->getVelocity();

	moveComponent->setVelocity(moveComponent->getVelocity() + newVelocity * deltaTime);
}
