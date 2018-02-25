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
		int points_size = 0;
		int coords[20];
		int TILE_SIZE = 4;
		int GRID_WIDTH = WIDTH / TILE_SIZE;
		int GRID_HEIGHT = HEIGHT / TILE_SIZE;
		int grid_x = coords[0] * TILE_SIZE;
		int grid_y = coords[1] * TILE_SIZE;
		
		void move_me(Dir dir);
		void keypressed();
		void draw_cursor();
		void draw_art();
};

#endif
