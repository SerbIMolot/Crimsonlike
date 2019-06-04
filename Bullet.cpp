#include "inc.h"

Bullet::Bullet(float x, float y, Texture * textr, Type type)
	: Object(x,y,textr,type) {
	Active(false);
	Init();
}

Bullet::~Bullet() {
	delete moveBounds;
}

void Bullet::Init() {
	vel = Vector2d();
	timer = Timer::Instance();
	
}

void Bullet::Update(Object* obj) {
	if (bulTimer > 2 || Pos().getX() > Map::getMapSize().getX() + 50 || Pos().getY() > Map::getMapSize().getX() + 50 || Pos().getX() < -50 || Pos().getY() < -50) {
		Active(false);
	}
	if (Active()) {
		bulTimer += timer->DeltaTime();
		Pos((Pos() + vel));
		UpdateBox();

	}
}
void Bullet::collisionDetected(Object* obj) {
	if (obj->getType() == tEnemy) {
		Active(false);
	}
}

void Bullet::Draw() {
	getSkin().drawTexture(Pos() - Camera::Instance()->Pos());
}


void Bullet::shoot(Vector2d& player, Vector2d& target) {

	Pos(player);
	vel = target - Pos();

	vel.normalise();
	vel *= 2;

	bulTimer = 0;
	Active(true);
}

