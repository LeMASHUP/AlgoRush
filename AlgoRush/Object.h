#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include <iostream>

class Object : public sfp::PhysicsRectangle {
private:

	sf::Texture m_texture;
	Vector2f m_scale;
	bool m_draw;

public:

	Object(Vector2f scale);
	void throwObject();
	bool getIsDraw();
	void setIsDraw(bool isDraw);
};
