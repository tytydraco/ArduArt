#ifndef ARDUART_H
#define ARDUART_H

class ArduArt {
	Arduboy2 arduboy;
	public:
		ArduArt(Arduboy2 n_arduboy) {
			arduboy = n_arduboy;
		}
		enum Dir {
			UP,
			DOWN,
			LEFT,
			RIGHT
		};
		int8_t coords[3];
		int8_t TILE_SIZE = 8;
		int8_t GRID_WIDTH = WIDTH / TILE_SIZE;
		int8_t GRID_HEIGHT = HEIGHT / TILE_SIZE;
		
		void move_me(Dir dir);
};

#endif
