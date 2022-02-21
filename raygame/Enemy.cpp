#include "Enemy.h"
#include "SeekBehavior.h"
#include "FleeBehavior.h"
#include "WanderBehavior.h"
#include "Transform2D.h"
#include "Engine.h"

Enemy::Enemy(float x, float y, const char* name, float speed, int maxHealth, Actor* targetActor) :
	Character::Character(x, y, name, speed, maxHealth)
{
	m_targetActor = targetActor;
}

void Enemy::start()
{
	Character::start();
	WanderBehavior* wanderBehavior = new WanderBehavior(30, 10000);
	addComponent(wanderBehavior);

	/*SeekBehavior* seekBehavior = new SeekBehavior(m_targetActor);
	addComponent(seekBehavior);*/
}

void Enemy::update(float deltaTime)
{
	if (getTransform()->getWorldPosition().x > Engine::getScreenWidth())
		getTransform()->setWorldPostion({ -5, getTransform()->getWorldPosition().y });
	if (getTransform()->getWorldPosition().y > Engine::getScreenHeight())
		getTransform()->setWorldPostion({ getTransform()->getWorldPosition().x, -5});

	Character::update(deltaTime);

}
