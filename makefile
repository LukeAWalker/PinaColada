#Makefile for PinaColada

# SDL header locations

SDL_INCLUDE := .\lib\SDL2-2.0.4\i686-w64-mingw32\include
INCLUDE := .\inc

# Library locations
SDL_LIB := lib\SDL2-2.0.4\i686-w64-mingw32\lib

#List of existing .cpp files and list of prospective .o files
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
EXE_PATH  := .\publish\debug
LD_FLAGS := -lmingw32 -L$(SDL_LIB) -lSDL2main -lSDL2
CC_FLAGS := -Wall -g -I $(SDL_INCLUDE)

$(EXE_PATH)\PinaColada.exe: $(OBJ_FILES)
	g++ -o $@ $^ $(LD_FLAGS)
	cmd /c copy .\lib\SDL2-2.0.4\i686-w64-mingw32\bin\SDL2.dll .\publish\debug

obj/%.o: src/%.cpp
	g++ $(CC_FLAGS) -c -I $(INCLUDE) -o $@ $<

#.PHONY : clean
#clean:
#	rm $(OBJ_FILES)
