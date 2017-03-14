cmake_minimum_required(VERSION 2.6)
set(CMAKE_SYSTEM_NAME windows)

set(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)
set(CMAKE_RC_COMPILER i686-w64-mingw32-windres)


set(CMAKE_FIND_ROOT_PATH /usr/x86_64-w64-mingw32/)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(MINGW_PREFIX /usr/x86_64-w64-mingw32)
set(MINGW_BIN_DIR /usr/bin)
set(MINGW_LIB_DIR ${MINGW_PREFIX}/lib)
set(MINGW_INCLUDE_DIR ${MINGW_PREFIX}/include)

set(BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(TMP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tmp)
set(LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)
set(LIBS_DIR_SRC ${LIBS_DIR}/src)
set(PATCHES_DIR ${LIBS_DIR}/patches)

set(SYSTEM_TMP_DIR ${TMP_DIR}/${CMAKE_SYSTEM_NAME})
set(SYSTEM_TMP_LIBS_SRC_DIR ${SYSTEM_TMP_DIR}/libs/src)
set(SYSTEM_LIBS_DIR ${LIBS_DIR}/${CMAKE_SYSTEM_NAME})
set(SYSTEM_BIN_DIR ${BIN_DIR}/${CMAKE_SYSTEM_NAME})
set(SYSTEM_BIN_LIB_DIR ${BIN_DIR}/${CMAKE_SYSTEM_NAME}/lib)

set(ZLIB_BINARY ${SYSTEM_LIBS_DIR}/zlib-1.2/bin/zlib1.dll)
set(LIBPNG_CFLAGS -I${SYSTEM_LIBS_DIR}/zlib-1.2/include)
set(LIBPNG_LDFLAGS -L${SYSTEM_LIBS_DIR}/zlib-1.2/lib)
set(LIBPNG_CONFIGURE_OPTIONS --build=i686-unknown-linux --host=i686-w64-mingw32 --with-zlib-prefix=${SYSTEM_LIBS_DIR}/zlib-1.2/bin)
set(LIBPNG_BINARY ${SYSTEM_LIBS_DIR}/libpng-1.6/bin/libpng16-16.dll)

set(SDL_CONFIGURE_OPTIONS --build=i686-unknown-linux --host=i686-w64-mingw32)
set(SDL_BINARY ${SYSTEM_LIBS_DIR}/SDL-1.2/bin/SDL.dll)

set(SDL_IMAGE_CFLAGS "-I${SYSTEM_LIBS_DIR}/zlib-1.2/include -I${SYSTEM_LIBS_DIR}/SDL-1.2/include/SDL -I${SYSTEM_LIBS_DIR}/libpng-1.6/include")
set(SDL_IMAGE_LDFLAGS "-L${SYSTEM_LIBS_DIR}/zlib-1.2/lib -L${SYSTEM_LIBS_DIR}/libpng-1.6/lib")
set(SDL_IMAGE_CONFIGURE_OPTIONS --build=i686-unknown-linux --host=i686-w64-mingw32 --with-sdl-prefix=${SYSTEM_LIBS_DIR}/SDL-1.2)
set(SDL_IMAGE_BINARY ${SYSTEM_LIBS_DIR}/SDL-1.2/bin/SDL_image.dll)

set(FREETYPE_CONFIGURE_OPTIONS --build=i686-unknown-linux --host=i686-w64-mingw32)

set(SDL_TTF_CONFIGURE_OPTIONS --build=i686-unknown-linux --host=i686-w64-mingw32 --with-freetype-prefix=${SYSTEM_LIBS_DIR}/FreeType-2.4 --with-sdl-prefix=${SYSTEM_LIBS_DIR}/SDL-1.2)
set(SDL_TTF_BINARY ${SYSTEM_LIBS_DIR}/SDL-1.2/bin/SDL_ttf.dll)

set(SYSTEM_LIBRARIES mingw32 libSDL libSDLmain.a libSDL libSDL_image libSDL_ttf)
