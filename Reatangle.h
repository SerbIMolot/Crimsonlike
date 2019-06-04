#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rect {
public:

	float x;
	float y;
	float w;
	float h;

	Rect();
	Rect(int x, int y, int w, int h);
	Rect(float x, float y, float w, float h);
	Rect(Vector2d vec = Vector2d(), Texture* texture = nullptr);
	~Rect();
	
	Vector2d getVec();
	void setVec(Vector2d& vec);

	float topSide();
	
	float BottomSide();
	
	float LeftSide();
	
	float RightSide();




	
};
#endif // RECTANGLE_H
