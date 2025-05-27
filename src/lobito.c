#include "lauxlib.h"
#include "lua.h"
#include "luaconf.h"
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
static int killo(lua_State *L){
  // checks if there is to are based
  int n = lua_gettop(L);
  if ( n != 2 ) {
    printf("accept two args only you give : %d\n",n);
    // if not return 0
    return 0;
  }
  // get pid
  int pid = (int) luaL_checkinteger(L, 1);
  // get signal 
  int signal = (int) luaL_checkinteger(L, 2);
  // kill
  int killup = kill(pid,signal);
  // ret if true or false
  lua_pushboolean(L, killup += 1);

  return 1;
}
static int getUid(lua_State *L){
  lua_pushinteger(L,getuid());
  return 1;
}

static int getPpid(lua_State *L){
  lua_pushinteger(L,getppid());
  return 1;
}


static int getPid(lua_State *L){
  // get Pid 
  // return the pid
  lua_pushinteger(L, getpid());
  return 1;
}
static const luaL_Reg funcs[] = {

  {"kill",killo},

  {"getppid",getPpid},

  {"getuid",getUid},
  {"getpid",getPid},
};
LUAMOD_API int open_cc(lua_State *L){
  luaL_newlib(L, funcs);
  return 1;
}
