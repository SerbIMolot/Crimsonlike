#include "inc.h"

Camera* Camera::cInstance = nullptr;

Camera::Camera(int mapW, int mapH, Player* player) {

}

Camera::Camera() {

}

Camera::~Camera() {
	delete pos;
	delete box;
}

void Camera::Init() {

	this->player = Player::Instance();
	this->type = tCamera;

	getScreenSize(screenW, screenH);

	pos = new Vector2d(player->Pos() - Vector2d(screenW / 2, screenH / 2));
	this->box = new Rect(pos->getX(), pos->getY(), static_cast<float>(screenW), static_cast<float>(screenH));
}

void Camera::setMap() {
	if (mapX == 0 && mapY == 0) {
		
		mapX = Map::getMapSize().getX();
		mapY = Map::getMapSize().getY();
	}
}

Camera * Camera::Instance()
{
	if (cInstance == nullptr) {
		cInstance = new Camera();
	}
	return cInstance;
}

void Camera::Release()
{
	delete cInstance;
}

void Camera::setPlayer(Player* player)
{
		
		this->player = Player::Instance();

		*pos = Player::Instance()->Pos() - Vector2d(screenW / 2, screenH / 2) ;

		this->box = new Rect(pos->getX(), pos->getY(), static_cast<float>(screenW), static_cast<float>(screenH));

}


Rect * Camera::getBox()
{
	return box;
}

Type * Camera::getType()
{
	return &type;
}

Vector2d& Camera::Pos()
{
	return *pos;
}
void Camera::updateBox() {
	box->setVec(*pos);
}

void Camera::Update() {
	
	pos->setX(player->Pos().getX() - (screenW / 2));
	pos->setY(player->Pos().getY() - (screenH / 2));
	updateBox();

	if (box->x < 0) {

		pos->setX(0);
		updateBox();
	}	
	if (box->y < 0) {

		pos->setY(0);
		updateBox();
	}
	if (box->w > mapX) {
		pos->setX(-((int)getBox()->w % mapX) / 2);
		updateBox();
	} else if (box->x > mapX - box->w) {

		pos->setX((float)(mapX - box->w));
		updateBox();
	}
	if (box->h > mapY) {
		pos->setX((float)(-((int)getBox()->h % mapY)/2));
	}
	if (box->y > mapY - box->h) {

		pos->setY((float)(mapY - box->h));
		updateBox();
	}
	
}

