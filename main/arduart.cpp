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
