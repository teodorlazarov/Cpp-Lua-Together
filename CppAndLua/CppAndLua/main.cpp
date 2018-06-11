//Showing connecting lua files and registering a function, doing the math in c++
//and giving it back to lua for printing

#include <iostream>
#include "lua.hpp"

int LUA_Pow(lua_State *L)
{
	float x = lua_tonumber(L, 1);
	float y = lua_tonumber(L, 2);
	lua_pushnumber(L, pow(x,y));
	return 1;
}

int main()
{
	lua_State *L = luaL_newstate();

	luaL_openlibs(L);
	lua_register(L, "Pow", LUA_Pow);
	luaL_loadfile(L, "test.lua");
	lua_call(L, 0, 0);

	lua_close(L);

	std::cin.get();

}