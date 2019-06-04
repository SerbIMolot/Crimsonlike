#ifndef OBJECT_H
#define OBJECT_H

#include "inc.h"


enum SPACE { world = 0, screen = 1 };

enum Type {
	tUndefined,
	tPlayer,
	tEnemy,
	tObject,
	tBullet,
	tCamera
};


class Object {
private:
	int id;
	Type type;
	Vector2d vel;
	Vector2d pos;
	float rotation;

	bool onCam;
	bool active;

	Object* parent;

	Texture* skin;

	Rect* box;
public:

	

	Object();

	Object(float x, float y, Texture * textr, Type type);

	Object(Vector2d vec, Texture * textr, Type type);

	~Object();

	void Pos(Vector2d pos);

	Vector2d& Pos(SPACE space = world);

	void Active(bool active);
	bool Active();

	void onCamera(bool onCamera);
	bool onCamera();

	void setParent(Object* parent);
	Object* getParent();

	void setSkin(Texture* texture, Type type);
	Texture& getSkin();

	Rect* getBox();
	Type getType();

	void setType(Type type);
	void UpdateBox();

	void Rotation(float r);

	float Rotation(SPACE space);

	void Update(Object * obj = nullptr);

	virtual void Draw();
	virtual void collisionDetected(Object * obj) = 0;

};
#endif
