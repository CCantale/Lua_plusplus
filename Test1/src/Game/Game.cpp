/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Game.cpp                                              by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Game.hpp"
//#include <sstream>

bool			Game::_running = false;
bool			Game::_somethingHappened = true;
SDL_Window		*Game::_window = NULL;
SDL_Renderer	*Game::_renderer = NULL;
SDL_Color		Game::_background;
lua_State		*Game::_L = NULL;

static bool	execLuaCode(std::string filePath, lua_State *L)
{
	std::string	code;
	int			ret;

	luaL_openlibs(L);
	ret = luaL_dofile(L, filePath.c_str());
	if (ret)
	{
		std::cerr << lua_tostring(L, -1) << std::endl;
		return (false);
	}
	return (true);
}

static void	setBackgroundColor(lua_State *L, SDL_Color &color)
{
	if (!execLuaCode(LUA_SCRIPT_PATH, L))
		Game::quit();
	lua_getglobal(L, "get_backgroundcolor");
	lua_pcall(L, 0, 4, 0);
	color = {
				(Uint8)lua_tointeger(L, -4),
				(Uint8)lua_tointeger(L, -3),
				(Uint8)lua_tointeger(L, -2),
				(Uint8)lua_tointeger(L, -1)
			};
}

void	Game::init(char const *title, int _window_posX, int _window_posY,
		int width, int height, int fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << "SDL: Couldn't init" << std::endl;
		return ;
	}
	_window = SDL_CreateWindow(title, _window_posX, _window_posY, width,
			height, fullscreen);
	if (!_window)
	{
		std::cerr << "SDL: Couldn't open window" << std::endl;
		SDL_Quit();
		return ;
	}
	_renderer = SDL_CreateRenderer(_window, -1, 0);
	if (!_renderer)
	{
		std::cerr << "SDL: Couldn't init renderer" << std::endl;
		Game::quit();
		return ;
	}
	_L = luaL_newstate();
	if (!execLuaCode(LUA_SCRIPT_PATH, _L))
	{
		std::cerr << "Couldn't compile Lua script." << std::endl;
		Game::quit();
		return ;
	}
	setBackgroundColor(_L, _background);
	_running = true;
}

bool	Game::isRunning(void)
{
	return (_running);
}

SDL_Renderer	*Game::getRenderer(void)
{
	return (_renderer);
}

void	Game::quit(void)
{
	_running = false;
}

void	Game::somethingHappened(void)
{
	_somethingHappened = true;
}

void	Game::update(void)
{
	SDL_SetRenderDrawColor(	_renderer,
							_background.r,
							_background.g,
							_background.b,
							_background.a
							);
	SDL_RenderClear(_renderer);
	if (_somethingHappened)
	{
		SDL_RenderPresent(_renderer);
		_somethingHappened = false;
	}
}

void	Game::clear(void)
{
	if (_window)
		SDL_DestroyWindow(_window);
	if (_renderer)
		SDL_DestroyRenderer(_renderer);
	if (_L)
		lua_close(_L);
	SDL_Quit();
}

void	Game::handleEvents(void)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_UP:
						break ;
					case SDLK_DOWN:
						break ;
					case SDLK_LEFT:
						break ;
					case SDLK_RIGHT:
						break ;
					case SDLK_w:
						break ;
					case SDLK_a:
						break ;
					case SDLK_s:
						break ;
					case SDLK_d:
						break ;
					case SDLK_ESCAPE:
						quit();
						break ;
				}
				break ;
			case SDL_KEYUP:
				case SDLK_UP:
					break ;
				case SDLK_DOWN:
					break ;
				case SDLK_LEFT:
					break ;
				case SDLK_RIGHT:
					break ;
				case SDLK_w:
					break ;
				case SDLK_a:
					break ;
				case SDLK_s:
					break ;
				case SDLK_d:
					break ;
				break ;
			default:
				break ;
		}
	}
}
