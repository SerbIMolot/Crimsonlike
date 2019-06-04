#include "inc.h"

Gun::Gun(int numOfB) {
	this->numOfB = numOfB;
	this->shotsLeft = numOfB;

	for (int i = numOfB; i >= 0; i--) {
		bullets.push_back(new Bullet(-366336, -366336, TextureManager::getTexture("bullet.png"), tBullet));
	}
}

Gun::~Gun() {
}
void Gun::Init() {
	for (auto b : bullets) {
			b->Init();
	}
}

std::vector<Bullet*>& Gun::getBullets() {
	return bullets;
}

void Gun::Update() {
	for (auto b : bullets) {
		if (b->Active() == true) {

			b->Update();
		}
	}
}

void Gun::Draw() {
	for (auto b : bullets) {
		if (b->Active() == true) {
			b->Draw();
		}
	}
}

int Gun::getShotsLeft() {
	return shotsLeft;
}

void Gun::reload() {
	shotsLeft = numOfB;
}

void Gun::shoot(Vector2d & player, Vector2d & target) {
	if (shotsLeft > 0 && bullets[shotsLeft]->Active() == false) {
		bullets[shotsLeft]->shoot(player, target + Camera::Instance()->Pos());
		shotsLeft -= 1;
	}
	else {
		reload();
	}
}
