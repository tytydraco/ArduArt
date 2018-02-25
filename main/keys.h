#ifndef KEYS_H
#define KEYS_H

class Keys {
	Arduboy2 arduboy;
	bool a_pressed = false;
	bool b_pressed = false;
	bool up_pressed = false;
	bool down_pressed = false;
	bool left_pressed = false;
	bool right_pressed = false;

	public:
		Keys(Arduboy2 n_arduboy) {
		  arduboy = n_arduboy;
		}
		bool clicked(int8_t button_id);
};

#endif
