#include "Enemy.h"
#include "SeekBehavior.h"
#include "FleeBehavior.h"
#include "WanderBehavior.h"
#include "Transform2D.h"
#include "Engine.h"
#include <Vector2.h>

Enemy::Enemy(float x, float y, const char* name, float speed, int maxHealth, Actor* targetActor) :
	Character::Character(x, y, name, speed, maxHealth)
{
	m_targetActor = targetActor;
}

void Enemy::start()
{
	Character::start();

	//getTransform()->setForward(MathLibrary::Vector2(-1, 0));

	WanderBehavior* wanderBehavior = new WanderBehavior(40, 10500);
	addComponent(wanderBehavior);

	/*SeekBehavior* seekBehavior = new SeekBehavior(m_targetActor);
	addComponent(seekBehavior);*/
}

void Enemy::update(float deltaTime)
{


	Character::update(deltaTime);

}
