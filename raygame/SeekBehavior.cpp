#include "SeekBehavior.h"
#include "Transform2D.h"
#include "Actor.h"
#include <Vector2.h>
#include "MoveComponent.h"

SeekBehavior::SeekBehavior(Actor* target) {
	m_target = target;
}

void SeekBehavior::update(float deltaTime)
{
	MathLibrary::Vector2 direction =
		(getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()).getNormalized();

	direction = direction * m_force;

	getOwner()->getComponent("MoveComponent").
}
