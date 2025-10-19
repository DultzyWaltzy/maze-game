#ifndef MAP_H
#define MAP_H

#include <stdint.h>

#define MAP_WIDTH 16
#define MAP_HEIGHT 16
#define TRUE 1
#define FALSE 0

struct MapData {
	uint8_t map_arrangement[MAP_HEIGHT][MAP_WIDTH]; //unit8_t so we don't waste 3 extra bytes per MapData struct.
};

void render_map(uint8_t map_data[MAP_HEIGHT][MAP_WIDTH]);

uint8_t move_player_x(uint8_t map_data[MAP_HEIGHT][MAP_WIDTH], uint8_t x, uint8_t map_y, uint8_t direction);


uint8_t move_player_y(uint8_t map_data[MAP_HEIGHT][MAP_WIDTH], uint8_t y, uint8_t map_x, uint8_t direction);

#endif