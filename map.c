#include "map.h"
#include <stdio.h>

static const char tile_lookup[] = {
    ' ', // 0 = blank space
    '#', // 1 = wall
    'X', // 2 = player
    '$', // 3 = money
};

void render_map_raw(uint8_t map_data[MAP_HEIGHT][MAP_WIDTH])
{
    for (uint8_t y = 0; y < MAP_HEIGHT; y++)
    {
        for (uint8_t x = 0; x < MAP_WIDTH; x++)
        {
            printf("%d", map_data[y][x]); // prints raw numbers of the render_map data
        }
        putchar('\n');
    }
}

void render_map(uint8_t map_data[MAP_HEIGHT][MAP_WIDTH])
{
    for (uint8_t y = 0; y < MAP_HEIGHT; y++)
    {
        for(uint8_t x = 0; x < MAP_WIDTH; x++)
        {
            putchar(tile_lookup[map_data[y][x]]); // 3x-10x faster than printf (only a few nanoseconds per call)
        }
        putchar('\n');
    }
}

uint8_t move_player_x(uint8_t map_data[MAP_HEIGHT][MAP_WIDTH], uint8_t x, uint8_t map_y, uint8_t direction)
{
    switch(direction)
    {
        case 2: // LEFT
            if(map_data[map_y][x - 1] == 0)
            {
                return x - 1;
            }

            else
            {
                return x;
            }

        case 3: // RIGHT
            if(map_data[map_y][x + 1] == 0)
            {
                return x + 1;
            }
            else
            {
                return x;
            }

        default:
            return x;
    }
}

uint8_t move_player_y(uint8_t map_data[MAP_HEIGHT][MAP_WIDTH], uint8_t y, uint8_t map_x, uint8_t direction)
{
    switch(direction)
    {
        case 0: // UP
            if(map_data[y - 1][map_x] == 0)
            {
                return y - 1;
            }
            else
            {
                return y;
            }

        case 1: // DOWN
            if(map_data[y + 1][map_x] == 0)
            {
                return y + 1;
            }
            else
            {
                return y;
            }

        default:
            return y;
    }
}