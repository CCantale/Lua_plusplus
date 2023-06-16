#include "main.h"

static bool	execute(std::string filePath, lua_State *L)
{
	std::string	luaCode;
	int			ret;

	luaCode = fileToString(filePath);
	if (luaCode.empty())
		return (false);
	ret = luaL_dostring(L, luaCode.c_str());
	if (!ret)
		return (false);
	return (true);
}

bool	execLuaCode(std::string &code, lua_State *L)
{
	int	ret;

	ret = luaL_dostring(L, code.c_str());
	if (!ret)
		return (false);
	return (true);
}

int	printStuff(lua_State *L)
{
	(void)L;
	std::cout << "Hello from C++ from Lua from C++!" << std::endl;
	return 1;
}

static void	runTest(lua_State *L)
{
	std::cout << "Hello from C++!" << std::endl;
	lua_pushcfunction(L, printStuff);
	lua_setglobal(L, "cpp_print_func");
	lua_getglobal(L, "print_this");
	lua_pcall(L, 0, 0, 0);
}


int	main(int argc, char **argv)
{
	lua_State	*L = luaL_newstate();

	luaL_openlibs(L);
	execute("src/hello.lua", L);
	runTest(L);

	(void)argc;
	(void)argv;
	Game::init(PROGRAM_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH, WINDOW_HEIGHT, FULLSCREEN);
	while (Game::isRunning())
	{
		Game::handleEvents();
		Game::update();
	}
	Game::quit();
	return (0);
}
