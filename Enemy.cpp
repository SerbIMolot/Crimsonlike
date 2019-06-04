#include "inc.h"



Enemy::Enemy(Vector2d vec, Texture * textr, Type type)  : Object(vec, textr, type)
{
	
	Active(false);
	timer = Timer::Instance();

	moveSpeed = 75;
	enTimer = 0.0f;
	player = Player::Instance();
}

Enemy::~Enemy()
{
}

void Enemy::moveToPlayer()
{
	if (player->Pos().getX() >= Pos().getX()) {
		vel = vecRIGHT;
	} else if (player->Pos().getX() <= Pos().getX()) {
		vel = vecLEFT;
	}
	if (player->Pos().getY() >= Pos().getY()) {
		vel += vecDOWN;
	}
	else if (player->Pos().getY() <= Pos().getY()) {
		vel += vecUP;
	}

}

void Enemy::spawnPoint()
{
	int scrW, scrH;
	getScreenSize(scrW,scrH);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> randX(0, (int)Map::getMapSize().getX());
	std::uniform_int_distribution<> randY(0, (int)Map::getMapSize().getY());
	int rndX = randX(gen);

	if (rndX > player->Pos().getX() - 100 && rndX < player->Pos().getX() + 100) {
		rndX += 200;
	}
	int rndY = randY(gen);

	if (rndY > player->Pos().getY() - 100 && rndY < player->Pos().getY() + 100) {
		rndY += 200;
	}

	Pos(Vector2d(rndX,rndY));
	UpdateBox();
	
}

void Enemy::Update(Object* obj) {
	enTimer += timer->DeltaTime();
	
	if (Active() == false && enTimer > 10) {
		spawnPoint();
		Active(true);
	}

	if (Active()) {
		moveToPlayer();
		Pos(Pos() + (vel * timer->DeltaTime()) * moveSpeed);
	}

}


void Enemy::collisionDetected(Object* obj) {
	if (obj->getType() == tBullet) {
		Active(false);
		enTimer = 0.0f;
	}
	if (obj->getType() == tPlayer) {
		Active(false);
		enTimer = 0.0f;
	}

	if (collisionCheck(this, obj) && Active()) {
		Pos().setX((float)Pos().getX() - (vel.getX() * timer->DeltaTime()) * moveSpeed );
		UpdateBox();
	}
	if (collisionCheck(this, obj) && Active()) {
		Pos().setY((float)Pos().getY() - (vel.getY() * timer->DeltaTime()) * moveSpeed);
		UpdateBox();
	}

}

void Enemy::collisionDetected(Camera * cam)
{
	onCamera(true);
}
