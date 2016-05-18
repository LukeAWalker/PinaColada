#include <SDL.h>
#include <level.hpp>
#include <utils.hpp>
#include <iostream>
#include <fstream>
#include <render.hpp>
#include <string.h>
#include "debug.hpp"
#include "block.hpp"
#include "character.hpp"

Level::Level() {
    SDL_Rect clipBase = {0,0,354,312};
    SDL_Rect clipPlatform = {0,0,600,300};
    //Colour colour = {0,0xFF,0xFF,0xFF};
    Load_from_file("../../resources/level1.txt");

    //We know the base is the first block in the file, so set that first
    Blocks[0]->sprite->Set_clip(clipBase);
    for(unsigned int i=1;i<Blocks.size();i++) Blocks[i]->sprite->Set_clip(clipPlatform);

}

Level::~Level() {

    //Clear all the objects from memory
    for(unsigned int i; i<Blocks.size();i++) delete Blocks[i];
    for(unsigned int i; i<Characters.size();i++) delete Characters[i];
}

game_errno_type Level::Load_from_file(std::string path) {

    game_errno_type rv = GAME_ERRNO_SUCCESS;

    //Create stream for level file data
    std::ifstream level_file;
    level_file.open(path, std::ifstream::in);

    //If file is open / good, then start extracting data
    if(level_file.is_open()) {
        while (level_file.good()) {
            //Get the next line in the file. Stop if encountering a comma
            char str[256];
            level_file.getline(str, 256, ',');

            //Depending on the keyword (at start of line), do a different action?
            if(!strncmp((const char *) str, "BLOCK", 5)) {
            //Block
            /*Extract texture path (relative), level coordinates, block type
             *(decides clip?) */
                //Texture path
                char temp_path[256];
                level_file.getline(temp_path, 256, ',');
                std::string temp_string(temp_path);

                //Level coordinates: x, y, w, h
                SDL_Rect temp_rect;
                level_file.getline(temp_path, 256, ',');
                temp_rect.x = atoi(temp_path);
                level_file.getline(temp_path, 256, ',');
                temp_rect.y = atoi(temp_path);
                level_file.getline(temp_path, 256, ',');
                temp_rect.w = atoi(temp_path);
                level_file.getline(temp_path, 256, ',');
                temp_rect.h = atoi(temp_path);

                //TODO: Add more, i.e. block type?
                Blocks.push_back(new block_t(temp_string, temp_rect));
            }
            else if(!strncmp((const char *) str, "CHARACTER", 9)) {
                //Character
                /*Extract texture path (relative), level coordinates*/
                //Texture path
                char temp_path[256];
                level_file.getline(temp_path, 256, ',');
                std::string temp_string(temp_path);

                //Level coordinates: x, y, w, h
                SDL_Rect temp_rect;
                level_file.getline(temp_path, 256, ',');
                temp_rect.x = atoi(temp_path);
                level_file.getline(temp_path, 256, ',');
                temp_rect.y = atoi(temp_path);
                level_file.getline(temp_path, 256, ',');
                temp_rect.w = atoi(temp_path);
                level_file.getline(temp_path, 256, ',');
                temp_rect.h = atoi(temp_path);

                //TODO: Add more?
                Characters.push_back(new Character(temp_string,temp_rect));
            }

            //Clear whatever remains of this line
            level_file.getline(str, 256, '\n');
        }

        level_file.close();
    }
else {
    #ifdef DEBUG
        std::cout << "Error opening file";
    #endif
    rv = GAME_ERRNO_BAD_PATH;
}

return rv;

}


/**
 * handle_collisions
 *
 * See level.hpp
 */
void
Level::handle_collisions() {
    bool                 is_collision = false;
    uint16_t             char_index;
    Character           *character;
    uint16_t             block_index;
    block_t             *block;
    SDL_Rect             char_rect;
    rectangle_overlap_t  char_overlap;

    /**
     * First deal with any collisions between characters and the elements of
     * the level.
     */
    for (char_index = 0; char_index < Characters.size(); char_index++) {
        character = Characters[char_index];
        char_rect.x = character->position.x;
        char_rect.y = character->position.y;
        char_rect.w = character->size.x;
        char_rect.y = character->size.y;
        for (block_index = 0; block_index < Blocks.size(); block_index++) {
            block = Blocks[block_index];
            is_collision = check_rectangle_overlap(&char_rect,
                                                   &block->location,
                                                   &char_overlap,
                                                   NULL);
            if (is_collision) {
                character->handle_collisions(OBJECT_LEVEL_BLOCK,
                                            &block->location,
                                            char_overlap);
            }
        }
    }
}
