#include "Button.h"

Button::Button()
{
}

Button::~Button()
{
}

void Button::PlayGame(int* state)
{
	*state = 1;
}

void Button::ExitGame(sf::RenderWindow* window)
{
	window->close();
}

void Button::NextLevel(int* state)
{
	*state += 1;
}

void Button::ReplayLevel(bool* initLevel)
{
	*initLevel = false;
}

void Button::ReturnMenu(int* state)
{
	*state = 0;
}

void Button::Credits(int* state)
{
	*state = 6;
}