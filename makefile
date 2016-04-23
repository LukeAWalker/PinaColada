#Makefile for PinaColada

# SDL header locations
SDL_INCLUDE := .\lib\SDL2-2.0.4\i686-w64-mingw32\include\SDL2
IMG_INCLUDE := .\lib\SDL2_image-2.0.1\i686-w64-mingw32\include\SDL2
INCLUDE := .\inc $(SDL_INCLUDE) $(IMG_INCLUDE)

# Library locations
SDL_LIB := .\lib\SDL2-2.0.4\i686-w64-mingw32\lib
IMG_LIB := .\lib\SDL2_image-2.0.1\i686-w64-mingw32\lib
LIB := $(SDL_LIB) $(IMG_LIB)

#prefix include locations with -I, and lib locations with -L
INCLUDE_PARAMS = $(foreach d, $(INCLUDE), -I$d)
LIB_PARAMS = $(foreach d, $(LIB), -L$d)

#List of existing .cpp files and list of prospective .o files
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
EXE_PATH  := .\publish\debug
LD_FLAGS := -lmingw32 $(LIB_PARAMS) -lSDL2main -lSDL2 -lSDL2_image
CC_FLAGS := -Wall -g $(INCLUDE_PARAMS)

$(EXE_PATH)\PinaColada.exe: $(OBJ_FILES)
	g++ -o $@ $^ $(LD_FLAGS)
	cmd /c copy .\lib\SDL2-2.0.4\i686-w64-mingw32\bin\SDL2.dll .\publish\debug
	cmd /c copy .\lib\SDL2_image-2.0.1\i686-w64-mingw32\bin\SDL2_image.dll .\publish\debug
	cmd /c copy .\lib\SDL2_image-2.0.1\i686-w64-mingw32\bin\libpng16-16.dll .\publish\debug
	#lib\SDL2_image-2.0.1\i686-w64-mingw32\bin\zlib1.dll

obj/%.o: src/%.cpp
	g++ $(CC_FLAGS) -std=gnu++11 -c -o $@ $<

#.PHONY : clean
#clean:
#	rm $(OBJ_FILES)
