#include "Enemy.h"
#include "SeekBehavior.h"
#include "FleeBehavior.h"
#include "WanderBehavior.h"

Enemy::Enemy(float x, float y, const char* name, float speed, int maxHealth, Actor* targetActor) :
	Character::Character(x, y, name, speed, maxHealth)
{
	m_targetActor = targetActor;
}

void Enemy::start()
{
	Character::start();
	WanderBehavior* wanderBehavior = new WanderBehavior(500, 5);
	addComponent(wanderBehavior);

	/*SeekBehavior* seekBehavior = new SeekBehavior(m_targetActor);
	addComponent(seekBehavior);*/
}
