/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Sprite.hpp                                           by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef SPRITE_HPP
# define SPRITE_HPP

# include <SDL.h>
# include <SDL_image.h>
# include <string>
# include "../Game/Game.hpp"

class	Sprite
{
	public:
						Sprite(void);
						Sprite(std::string const &path);
						Sprite(std::string const &path, int x, int y);
						Sprite(int x, int y, int w, int h);
						Sprite(Sprite const &toCopy);
						~Sprite(void);
		Sprite			&operator=(Sprite const &toCopy);
		int				setTexture(std::string const &path);
		void			setPos(int x, int y);
		void			setDimentions(int w, int h);
		SDL_Rect const	&getRect(void);
		SDL_Texture		*getTexture(void);
		void			render(void);
		void			clear(void);

	private:
		std::string		_path;
		SDL_Texture		*_texture;
		SDL_Rect		_rect;
};

#endif
