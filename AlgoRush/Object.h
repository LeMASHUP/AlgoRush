#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include <iostream>

class Object : public sfp::PhysicsSprite {
private:

	sf::Texture m_texture;
	Vector2f m_scale;
	bool m_draw;

public:

	Object(sf::Texture texture, Vector2f scale);
	void throwObject();
	bool update(Object object);
	bool getIsDraw();
};
