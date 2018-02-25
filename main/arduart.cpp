#import <Arduboy2.h>
#import "arduart.h"

void ArduArt::move_me(Dir dir) {
	switch (dir) {
		case UP:
			if (coords[1] - 1 >= 0) {
				coords[1]--;
			}
			break;
		case DOWN:
			if (coords[1] + 1 < GRID_HEIGHT) {
				coords[1]++;
			}
			break;
		case LEFT:
			if (coords[0] - 1 >= 0) {
				coords[0]--;
			}
			break;
		case RIGHT:
			if (coords[0] + 1 < GRID_WIDTH) {
				coords[0]++;
			}
			break;
		default:
			break;
	}
}

void ArduArt::draw_cursor() {
	arduboy.drawRect(coords[0] * TILE_SIZE, coords[1] * TILE_SIZE, TILE_SIZE, TILE_SIZE, WHITE);
}

void ArduArt::draw_art() {
	for (int i = 0; i < points_size; i++) {
		int px = EEPROM.read(EEPROM_STORAGE_SPACE_START + i);
		int py = EEPROM.read(EEPROM_STORAGE_SPACE_START + 512 + i);
		if (px != -1 && py != -1) {
			arduboy.fillRect(px * TILE_SIZE, py * TILE_SIZE, TILE_SIZE, TILE_SIZE, WHITE);
		}
	}
}
