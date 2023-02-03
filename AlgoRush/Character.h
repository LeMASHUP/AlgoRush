#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

class Character
{

private:

	sfp::PhysicsRectangle m_body;
	sf::Texture m_sprite;
	sf::Clock m_clock;
	sf::Time lastTime;
	

public:

	Character(sfp::World* world);

	void forward();
	void backward();
	void jump();
	void jumpForward();
	void catchObject();
	void throwObject();
	void wait();
	void draw(sf::RenderWindow* window);

	int getPosX();
	int getPosY();

};