/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Game.hpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef GAME_HPP
# define GAME_HPP

# include <SDL2/SDL.h>
# include <iostream>
# include "lua.hpp"
# include "../string_utils.h"

# define LUA_SCRIPT_PATH	"src/script.lua"

class Game
{
	public:
		static void			init(char const *title, int window_posX,
									int window_posY, int width,
									int height, int fullscreen);
		static void			somethingHappened(void);
		static void			update(void);
		static bool			isRunning(void);
		static void			quit(void);
		static void			clear(void);
		static void			handleEvents(void);
		static SDL_Renderer	*getRenderer(void);

	private:
		static bool			_running;
		static bool			_somethingHappened;
		static SDL_Window	*_window;
		static SDL_Renderer	*_renderer;
		static SDL_Color	_background;
		static lua_State	*_L;
};

#endif
