/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Button.cpp                                            by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Button.hpp"

/*
Button::Button(void)
{
	this->_sprite = NULL;
	this->_active = false;
	setHighlightColor(35, 34, 33, 100);
}
*/

Button::Button(Sprite *sprite)
{
	this->_sprite = sprite;
	this->_visible = false;
	this->_underCursor = false;
	this->_active = false;
	setHighlightColor(35, 34, 33, 100);
}

Button::Button(Sprite *sprite, int x, int y, int w, int h)
{
	this->_sprite = sprite;
	this->_visible = false;
	this->_underCursor = false;
	this->setPos(x, y);
	this->setDimentions(w, h);
	this->_active = false;
	setHighlightColor(35, 34, 33, 100);
}

Button::Button(int x, int y, int w, int h)
{
	this->_sprite = new Sprite(x, y, w, h);
	this->_visible = false;
	this->_underCursor = false;
	this->_active = false;
	setHighlightColor(35, 34, 33, 100);
}

Button::Button(Button &toCopy)
{
	if (toCopy._sprite)
		this->_sprite = new Sprite(toCopy.getSprite());
	this->_visible = false;
	this->_action = toCopy._action;
	this->_active = toCopy._active;
	setHighlightColor(35, 34, 33, 100);
}

Button	&Button::operator=(Button &toCopy)
{
	if (this->_sprite)
		delete (this->_sprite);
	this->_sprite = new Sprite(toCopy.getSprite());
	this->_visible = false;
	this->_action = toCopy._action;
	this->_active = toCopy._active;
	setHighlightColor(35, 34, 33, 100);
	return (*this);
}

Button::~Button(void)
{
	if (this->_sprite)
		delete (this->_sprite);
}

Sprite	&Button::getSprite(void)
{
	return (*this->_sprite);
}

SDL_Rect const	&Button::getRect(void)
{
	return (this->_sprite->getRect());
}

int	Button::getWidth(void)
{
	return (this->_sprite->getRect().w);
}

int	Button::getHeight(void)
{
	return (this->_sprite->getRect().h);
}

int	Button::setSprite(Sprite &sprite)
{
	this->_sprite = new Sprite(sprite);
	if (!this->_sprite)
		return (-1);
	return (0);
}

int	Button::setTexture(std::string const &texturePath)
{
	if (this->_sprite->setTexture(texturePath) < 0)
		return (-1);
	return (0);
}

void	Button::setPos(int x, int y)
{
	this->_sprite->setPos(x, y);
}

void	Button::setDimentions(int w, int h)
{
	this->_sprite->setDimentions(w, h);
}

void	Button::setAction(void (*action)(void))
{
	this->_action = action;
}

void	Button::setHighlightColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	this->_hlColor = { r, g, b, a };
}

bool	Button::isThere(int x, int y)
{
	SDL_Rect	rect;

	rect = this->_sprite->getRect();
	if (x >= rect.x && x < rect.x + rect.w
		&& y >= rect.y && y < rect.y + rect.h)
	{
		return (true);
	}
	return (false);
}

void	Button::on(void)
{
	this->_active = true;
}

void	Button::off(void)
{
	this->_active = false;
}

bool	&Button::isActive(void)
{
	return (this->_active);
}

void	Button::show(void)
{
	this->_visible = true;
}

void	Button::hide(void)
{
	this->_visible = false;
}

bool	Button::isVisible(void)
{
	return (_visible);
}

void	Button::highlight(void)
{
	this->_underCursor = true;
}

void	Button::lowlight(void)
{
	this->_underCursor = false;
}

bool	Button::isUnder(void)
{
	return (_underCursor);
}

void	Button::render(void)
{
	if (_underCursor)
	{
		SDL_SetRenderDrawColor(Game::getRenderer(), _hlColor.r, _hlColor.g, _hlColor.b, _hlColor.a);
		SDL_RenderFillRect(Game::getRenderer(), &getRect());
	}
	if (this->_sprite)
		this->_sprite->render();
}

void	Button::activate(void)
{
	if (_action)
		this->_action();
}
