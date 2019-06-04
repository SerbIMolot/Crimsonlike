#include "inc.h"
bool collisionCheck(Object* obj1, Object* obj2)
{
	if (obj1->getBox()->LeftSide() >= obj2->getBox()->RightSide())
	{
		return false;
	}

	if (obj1->getBox()->RightSide() <= obj2->getBox()->LeftSide())
	{
		return false;
	}

	if (obj1->getBox()->topSide() >= obj2->getBox()->BottomSide())
	{
		return false;
	}


	if (obj1->getBox()->BottomSide() <= obj2->getBox()->topSide()) {
		return false;
	}

	return true;
}
bool collisionCheck(Camera * cam, Object * obj)
{

	if (cam->getBox()->LeftSide() >= obj->getBox()->RightSide())
	{
		return false;
	}

	if (cam->getBox()->RightSide() <= obj->getBox()->LeftSide())
	{
		return false;
	}

	if (cam->getBox()->topSide() >= obj->getBox()->BottomSide())
	{
		return false;
	}


	if (cam->getBox()->BottomSide() <= obj->getBox()->topSide()) {
		return false;
	}


	return true;
}

bool collisionCheck(Camera * cam, Tile * tile)
{

	if (cam->getBox()->LeftSide() >= tile->getBox()->RightSide())
	{
		return false;
	}

	if (cam->getBox()->RightSide() <= tile->getBox()->LeftSide())
	{
		return false;
	}

	if (cam->getBox()->topSide() >= tile->getBox()->BottomSide())
	{
		return false;
	}


	if (cam->getBox()->BottomSide() <= tile->getBox()->topSide()) {
		return false;
	}


	return true;
}
