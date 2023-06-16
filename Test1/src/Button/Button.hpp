/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Button.hpp                                            by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef BUTTON_HPP
# define BUTTON_HPP

# include <SDL2/SDL_image.h>
# include <SDL2/SDL.h>
# include <string>
# include "../Sprite/Sprite.hpp"

class	Button
{
	public:
						Button(Sprite *sprite);
						Button(Sprite *sprite, int x, int y, int w, int h);
						Button(int x, int y, int w, int h);
						Button(Button &toCopy);
		virtual			~Button(void);
		Button			&operator=(Button &toCopy);
		Sprite			&getSprite(void);
		SDL_Rect const	&getRect(void);
		int				getWidth(void);
		int				getHeight(void);
		int				setSprite(std::string const &texturePath);
		int				setTexture(std::string const &texturePath);
		void			setPos(int x, int y);
		void			setDimentions(int w, int h);
		void			setAction(void (*action)(void));
		void			setHighlightColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		bool			isThere(int x, int y);
		void			on(void);
		void			off(void);
		bool			&isActive(void);
		void			show(void);
		void			hide(void);
		bool			isVisible(void);
		void			highlight(void);
		void			lowlight(void);
		bool			isUnder(void);
		virtual void	render(void);
		virtual void	activate(void);

	protected:
		Sprite		*_sprite;
		SDL_Color	_hlColor;
		bool		_visible;
		bool		_underCursor;
		bool		_active;

	private:
		void		(*_action)(void) = NULL;
					Button(void); // please do not create useless, dimentionless, positionless bottons
};

#endif
