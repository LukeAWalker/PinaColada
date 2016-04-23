#Makefile for PinaColada

#List of existing .cpp files and list of prospective .o files
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
EXE_PATH  := .\publish\Debug
LD_FLAGS :=
CC_FLAGS :=

$(EXE_PATH)\PinaColada.exe: $(OBJ_FILES)
	g++ $(LD_FLAGS) -o $@ $^

obj/%.o: src/%.cpp
	g++ $(CC_FLAGS) -c -o $@ $<

.PHONY : clean
clean:
	rm $(OBJ_FILES)
