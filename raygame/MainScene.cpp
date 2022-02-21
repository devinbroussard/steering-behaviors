#include "MainScene.h"
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "Transform2D.h"

void MainScene::start()
{
	Player* player = new Player(200, 200, "player", 2000, 10);
	Enemy* enemy = new Enemy(10, 100, "enemy", 60, 1, player);
	player->getTransform()->setScale({ 50, 50 });
	enemy->getTransform()->setScale({ 50, 50 });

	addActor(player);
	addActor(enemy);
}
