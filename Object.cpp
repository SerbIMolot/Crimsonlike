#include "inc.h"



Object::Object() {
	pos = Vector2d();
	rotation = 0.0f;
	active = false;
	skin = nullptr;
	parent = nullptr;
	box = new Rect(0,0,0,0);
	type = tUndefined;
}

Object::Object(float x, float y, Texture* textr, Type type) {
	pos = Vector2d(x,y);

	rotation = 0.0f;
	active = true;

	parent = nullptr;

	if (textr == nullptr) {

		box = new Rect(x, y, 0.0f, 0.0f);
		this->type = type;
		skin = textr;
	} else {

		box = new Rect(x, y, static_cast<float>(textr->getWight()), static_cast<float>(textr->getHight()));
		setSkin(textr, type);
	}
}

Object::Object(Vector2d vec, Texture* textr, Type type) {
	pos = vec;
	rotation = 0.0f;
	active = true;
	parent = nullptr;

	if (textr == nullptr) {
		box = new Rect(vec);
		this->type = type;
	}
	else {
		box = new Rect(vec, textr);
		setSkin(textr, type);
	}
}

Object::~Object()
{
	delete parent;
	delete box;
}

void Object::Pos(Vector2d pos) {
	this->pos = pos;
	box->setVec(pos);
}

Vector2d& Object::Pos(SPACE space) {
	return this->pos;
}

void Object::Active(bool active)
{
	this->active = active;
}

bool Object::Active()
{
	return active;
}

void Object::onCamera(bool onCamera)
{
	this->onCam = onCamera;
}

bool Object::onCamera()
{
	return this->onCam;
}

void Object::setParent(Object * parent)
{
	pos = Pos(world) - parent->Pos(world);

	this->parent = parent;
}

Object* Object::getParent()
{
	return parent;
}

void Object::setSkin(Texture * texture, Type type)
{
	this->skin = texture;
	this->type = type;

	Pos(Vector2d(pos.getX() - (skin->getWight() / 2.0f), pos.getY() - (skin->getHight() / 2.0f)));
	box = new Rect(pos,texture);
}

Texture& Object::getSkin()
{
	return *skin;
}

Rect* Object::getBox()
{
	return box;
}

Type Object::getType()
{
	return type;
}

void Object::setType(Type type) {
	this->type = type;
}

void Object::UpdateBox() {
	box->setVec(pos);
}

void Object::Rotation(float r) {
	rotation = r;
	if (rotation > 360.0f) {
		rotation -= 360.0f;
	}
	if (rotation < 0.0f) {
		rotation += 360.0f;
	}
}

float Object::Rotation(SPACE space) {
	if (space == screen || parent == nullptr) {
		return rotation;
	}
	return parent->Rotation(world) + rotation;
}


void Object::Update(Object* obj) {
	collisionCheck(this, obj);
	UpdateBox();
}

void Object::Draw() {
	if (Active() && collisionCheck(Camera::Instance(), this)) {
		skin->drawTexture(this->pos - Camera::Instance()->Pos());
	}
}
