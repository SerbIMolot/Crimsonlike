#include "inc.h"

Cursor::Cursor(Vector2d vec, Texture* textr, Type type, int numAmmo)  : Object(vec, textr, type){
	player = nullptr;

	rgun = new Gun(numAmmo);

	rgun->Init();

}

Cursor::~Cursor() {
	delete rgun;
}

void Cursor::setPlayer(Player* player) {
	this->player = player;
}

void Cursor::Update(Object* obj) {
	rgun->Update();
}

void Cursor::Draw() {
	getSkin().drawTexture(Pos());
	rgun->Draw();

}
Gun* Cursor::getGun() {
	return rgun;
}


void Cursor::onMouseMove(int x, int y, int xrelative, int yrelative) {
	Pos(Vector2d(x,y));
}

void Cursor::onMouseButtonClick(FRMouseButton button, bool isReleased) {

	if (button == FRMouseButton::LEFT && isReleased == false) {

		if (rgun->getShotsLeft() > 0) {
			rgun->shoot(player->Pos(world), Pos());;
		} else {
			rgun->reload();
		}
	}
}

void Cursor::collisionDetected(Object * obj)
{
}
