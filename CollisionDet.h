#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H


#include "inc.h"
enum Side {
	Left,
	Right,
	Top,
	Bottom
};


class Object;
class Camera;
class Tile;
bool collisionCheck(Object* obj1, Object* obj2);
bool collisionCheck(Camera* cam, Object* obj);
bool collisionCheck(Camera* cam, Tile *tile);

#endif // !COLLISION_DETECTION_H
