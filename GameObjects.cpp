#include "inc.h"

GameObjects::GameObjects() {

	
}

GameObjects::~GameObjects(){
	Close();
}


bool GameObjects::Init(Vector2d mapSize, int numEnemies, int numBullets) {
	showCursor(0);

	int screenH, screenW;
	getScreenSize(screenW, screenH);

	mouse = new Cursor(Vector2d(-10000,-100000), TextureManager::getTexture("Scope1.png"), tUndefined, numBullets);

	Camera::Instance()->Init();

	map = new Map(mapSize.getX(), mapSize.getY());
	map->Init();

	Player::Instance()->Init();

	player = Player::Instance();
	cam = Camera::Instance();

	cam->setMap();
	cam->Init();

	createEnemyes(numEnemies);

	mouse->setPlayer(player);

	return true;
}

void GameObjects::Close() {

	delete child;
	delete mouse;
	delete enemy;
	for (auto obj : Objects) {
		delete obj.second;
	}
	Objects.clear();

	for (auto t : textures) {
		delete t;
	}
	textures.clear();
	player->Close();
	TextureManager::Close("all");
	delete map;
	
}

bool GameObjects::Tick() {

	mouse->Update();

	player->Update();

	cam->Update();

	for (auto en : enemyes) {
		en->Update();
	}

	return true;
}

bool GameObjects::LateTick() { 
	for (auto en : enemyes) {

		if (collisionCheck(player, en) && en->Active() == true) {
			reset();
		}
		if (mouse->getGun()->getShotsLeft() != 0 && en->Active() == true) {
			for (auto bul : mouse->getGun()->getBullets()) {
				if (bul->Active() == true) {
					if (collisionCheck(bul, en)) {
						bul->collisionDetected(en);
						en->collisionDetected(bul);
					}
				}
			}
		}


		for (auto en2 : enemyes) {
			if (collisionCheck(en, en2) && en->Active() == true && en2->Active() == true && en != en2 ) {
				en->collisionDetected(en2);
			}
		}
	}

	return true;
}

void GameObjects::draw() {
	map->draw();
	mouse->Draw();

	player->Draw();

	for (auto en : enemyes) {
		en->Draw();
	}
}

void GameObjects::createEnemyes(int num) {
	for (int i = 0; i < num; i++) {
		enemyes.push_back(new Enemy(Vector2d(-15000, -15000), TextureManager::getTexture("en1.png"), tEnemy));
	}
}
void GameObjects::reset() {
	player->Pos(Map::getMapSize() / 2);

	for (auto en : enemyes) {
		en->collisionDetected(player);
	}

	mouse->getGun()->reload();
}

