#include "inc.h"

Player* Player::pInstance = nullptr;

Player::Player() { }

Player::Player(Vector2d vec, Texture* textr, Type type) : Object(vec, textr, type) 
{

	timer = Timer::Instance();

	Active(true);
	moveBounds = Map::getMapSize(); 
	moveSpeed = 200;
}

Player::~Player() 
{
}

Player * Player::Instance() 
{
	if (pInstance == nullptr) 
	{

		pInstance = new Player();
	}
	else  if (pInstance->getType() != tPlayer) {
		pInstance = new Player(Map::getMapSize() / 2, TextureManager::getTexture("avatar.jpg"), tPlayer);
	}
		return pInstance;

}

void Player::Init() { }

void Player::Close() 
{
	delete pInstance;
	pInstance = nullptr;
}

void Player::Update(Object* obj) {

	plTimer += static_cast<long long>(timer->DeltaTime());

	Pos(world).setX(Pos(world).getX() + vel.getX() * timer->DeltaTime());

	if (!outOfBounds()) {
		UpdateBox();
	}
	Pos(world).setY(Pos(world).getY() + vel.getY() * timer->DeltaTime());
	if (!outOfBounds()) {
		UpdateBox();
	}

	UpdateBox();
}



void Player::collisionDetected(Object* obj) {
	if (obj->getType() == tEnemy) {
		int screenW, screenH;
		getScreenSize(screenW, screenH);
		Pos(Vector2d(screenW / 2, screenH / 2));
	}

	if (obj->getType() == tObject) {
		if (collisionCheck(this, obj)) {
			Pos(world).setX(Pos(world).getX() - vel.getX() * timer->DeltaTime());
			UpdateBox();
		}
		if (collisionCheck(this, obj)) {
			Pos(world).setY(Pos(world).getY() - vel.getY() * timer->DeltaTime());
			UpdateBox();
		}
	}
}

bool Player::outOfBounds()
{

	if (Pos(world).getX() + getSkin().getWight() >= moveBounds.getX() || Pos(world).getX() <= 0) {

		Pos(world).setX(Pos(world).getX() - vel.getX() * timer->DeltaTime());
		UpdateBox();
		return true;
	}
	if (Pos(world).getY() + getSkin().getHight() >= moveBounds.getY() || Pos(world).getY() <= 0) {

		Pos(world).setY(Pos().getY() - vel.getY() * timer->DeltaTime());
		UpdateBox();
		return true;
	}
	return false;
}


void Player::onKeyPressed(FRKey k) {
	if (k == FRKey::UP) {
		vel.setY(vel.getY() - moveSpeed);
	}
	if (k == FRKey::DOWN) {
		vel.setY(vel.getY() + moveSpeed);
	}
	if (k == FRKey::LEFT) {
		vel.setX(vel.getX() - moveSpeed);
	}
	if (k == FRKey::RIGHT) {
		vel.setX(vel.getX() + moveSpeed);
	}
}

void Player::onKeyReleased(FRKey k) {
	if (k == FRKey::UP) {
		vel.setY(vel.getY() + moveSpeed);
	}
	if (k == FRKey::DOWN) {
		vel.setY(vel.getY() - moveSpeed);
	}
	if (k == FRKey::LEFT) {
		vel.setX(vel.getX() + moveSpeed);
	}
	if (k == FRKey::RIGHT) {
		vel.setX(vel.getX() - moveSpeed);
	}
}
