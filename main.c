#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "map.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3


int get_kb_input()
{
    if(_kbhit())
    {
        return _getch();
    }
}

int main()
{
    // starting coordinates: [1][1]
    uint8_t player_x = 1;
    uint8_t player_y = 1;

    struct MapData demo_map = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,1,1,1,1,1,1,1,1,0,1,1,0,1,
        1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,
        1,0,0,1,1,1,1,1,1,1,1,0,1,0,0,1,
        1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,
        1,0,1,1,1,1,0,0,0,0,1,0,1,0,0,1,
        1,0,1,0,0,1,0,0,0,0,1,1,1,0,0,1,
        1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,
        1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,
        1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,
        1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,
        1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,
        1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 
    }; // The 2 in [1][1] is the player

    render_map(demo_map.map_arrangement);

    while(1)
    {
        int kb_input = get_kb_input();
        uint8_t moved = 0; // flag to check if player moved

        // remove player from old position
        demo_map.map_arrangement[player_y][player_x] = 0;

        if (kb_input == 'w')
        {
            uint8_t new_y = move_player_y(demo_map.map_arrangement, player_y, player_x, UP);
            if (new_y != player_y) { player_y = new_y; moved = 1; }
        }

        if (kb_input == 's')
        {
            uint8_t new_y = move_player_y(demo_map.map_arrangement, player_y, player_x, DOWN);
            if (new_y != player_y) { player_y = new_y; moved = 1; }
        }

        if (kb_input == 'a')
        {
            uint8_t new_x = move_player_x(demo_map.map_arrangement, player_x, player_y, LEFT);
            if (new_x != player_x) { player_x = new_x; moved = 1; }
        }

        if (kb_input == 'd')
        {
            uint8_t new_x = move_player_x(demo_map.map_arrangement, player_x, player_y, RIGHT);
            if (new_x != player_x) { player_x = new_x; moved = 1; }
        }

        // put player back
        demo_map.map_arrangement[player_y][player_x] = 2;

        // only redraw if player actually moved
        if (moved)
        {
            system("cls");
            render_map(demo_map.map_arrangement);
        }
    }

    return 0;
}