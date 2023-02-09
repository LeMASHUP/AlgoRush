#include "Ennemies.h"

Ennemies::Ennemies() : m_isAlive(true), m_ennemyVelocity(0.1)
{
	// Image of ennemy to load into texture
	sf::Image m_ennemyI;

	// Load and check images and texture of ennemy
	if (!m_ennemyI.loadFromFile("assets/ennemyBis.png")) std::cout << "Error in loading ennemy image" << std::endl;
	if (!m_ennemyT.loadFromImage(m_ennemyI)) std::cout << "Error in loading ennemy texture" << std::endl;

	m_ennemy.setSize(Vector2f(75, 75));
	m_ennemy.setRestitution(0.15);
	m_ennemy.setTexture(&m_ennemyT);
}

Ennemies::~Ennemies()
{
}

void Ennemies::initEnnemies(float pos_x, float pos_y)
{
	m_ennemy.setCenter(Vector2f(pos_x, pos_y));
}

void Ennemies::drawEnnemies(sf::RenderWindow* window)
{
	if (m_isAlive) window->draw(m_ennemy);
}

void Ennemies::addPhysics(sfp::World* world)
{
	world->AddPhysicsBody(m_ennemy);
	m_ennemy.setVelocity(Vector2f(m_ennemyVelocity, 0.1));
}

void Ennemies::removePhysics(sfp::World* world)
{
	world->RemovePhysicsBody(m_ennemy);
}

void Ennemies::updateEnnemies(sfp::World* world, Character* character, Level2* level2)
{
	if (m_ennemy.collideWith(*character).hasCollided)
	{
		if (character->getPosY() > m_ennemy.getCenter().y)
		{
			character->setIsAlive(false);
		}
		else
		{
			m_isAlive = false;
			world->RemovePhysicsBody(m_ennemy);
		}
	}
	if (m_ennemy.collideWith(level2->getTrashCan()).hasCollided)
	{
		m_ennemyVelocity = 0.1;
	}
	if (m_ennemy.collideWith(level2->getFireHydrant()).hasCollided)
	{
		m_ennemyVelocity = -0.1;
	}
	m_ennemy.setVelocity(Vector2f(m_ennemyVelocity, 0));
}