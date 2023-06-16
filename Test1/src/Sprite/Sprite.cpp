/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Sprite.hpp                                           by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Sprite.hpp"

Sprite::Sprite(void)
{
	this->_texture = NULL;
	this->_rect.x = 0;
	this->_rect.y = 0;
}

Sprite::Sprite(std::string const &path) : _path(path)
{
	this->_texture = IMG_LoadTexture(Game::getRenderer(), path.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	this->_rect.x = 0;
	this->_rect.y = 0;
}

Sprite::Sprite(std::string const &path, int x, int y) : _path(path)
{
	this->_texture = IMG_LoadTexture(Game::getRenderer(), path.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	this->_rect.x = x;
	this->_rect.y = y;
}

Sprite::Sprite(int x, int y, int w, int h)
{
	this->_texture = NULL;
	this->setPos(x, y);
	this->setDimentions(w, h);
}

Sprite::Sprite(Sprite const &toCopy)
{
	this->_texture = IMG_LoadTexture(Game::getRenderer(), toCopy._path.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	this->_rect.x = toCopy._rect.x;
	this->_rect.y = toCopy._rect.y;
}

Sprite::~Sprite(void)
{
	this->clear();
}

Sprite	&Sprite::operator=(Sprite const &toCopy)
{
	this->_texture = IMG_LoadTexture(Game::getRenderer(), toCopy._path.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	this->_rect.x = toCopy._rect.x;
	this->_rect.y = toCopy._rect.y;
	return (*this);
}

int	Sprite::setTexture(std::string const &path)
{
	this->_path = path;
	if (this->_texture)
		SDL_DestroyTexture(this->_texture);
	this->_texture = IMG_LoadTexture(Game::getRenderer(), path.c_str());
	if (this->_texture)
		SDL_QueryTexture(this->_texture, NULL, NULL, &this->_rect.w, &this->_rect.h);
	else
	{
		std::cerr << "Couldn't upload texture \"" << path << "\"." << std::endl;
		return (-1);
	}
	return (0);
}

void	Sprite::setPos(int x, int y)
{
	this->_rect.x = x;
	this->_rect.y = y;
}

void	Sprite::setDimentions(int w, int h)
{
	this->_rect.w = w;
	this->_rect.h = h;
}

SDL_Rect const	&Sprite::getRect(void)
{
	return (this->_rect);
}

SDL_Texture	*Sprite::getTexture(void)
{
	return (this->_texture);
}

void	Sprite::render(void)
{
	if (this->_texture)
		SDL_RenderCopy(Game::getRenderer(), this->_texture, NULL, &this->_rect);
}

void	Sprite::clear(void)
{
	if (this->_texture)
		SDL_DestroyTexture(this->_texture);
}
