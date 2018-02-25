#include <Arduboy2.h>
#include "keys.h"

bool Keys::clicked(int8_t button_id) {
	
	switch (button_id) {
		case A_BUTTON:
			if (arduboy.pressed(A_BUTTON) && !a_pressed) {
				a_pressed = true;
				return true;
			} else if (arduboy.notPressed(A_BUTTON)) {
				a_pressed = false;
			}
			break;
		case B_BUTTON:
			if (arduboy.pressed(B_BUTTON) && !b_pressed) {
				b_pressed = true;
				return true;
			} else if (arduboy.notPressed(B_BUTTON)) {
				b_pressed = false;
			}
			break;
		case UP_BUTTON:
			if (arduboy.pressed(UP_BUTTON) && !up_pressed) {
				up_pressed = true;
				return true;
			} else if (arduboy.notPressed(UP_BUTTON)) {
				up_pressed = false;
			}
			break;
		case DOWN_BUTTON:
			if (arduboy.pressed(DOWN_BUTTON) && !down_pressed) {
				down_pressed = true;
				return true;
			} else if (arduboy.notPressed(DOWN_BUTTON)) {
				down_pressed = false;
			}
			break;
		case LEFT_BUTTON:
			if (arduboy.pressed(LEFT_BUTTON) && !left_pressed) {
				left_pressed = true;
				return true;
			} else if (arduboy.notPressed(LEFT_BUTTON)) {
				left_pressed = false;
			}
			break;
		case RIGHT_BUTTON:
			if (arduboy.pressed(RIGHT_BUTTON) && !right_pressed) {
				right_pressed = true;
				return true;
			} else if (arduboy.notPressed(RIGHT_BUTTON)) {
				right_pressed = false;
			}
			break;
		default:
			break;
	}
	
	return false;
}
