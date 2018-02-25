#import <Arduboy2.h>
#import "arduart.h"

Arduboy2 arduboy;
ArduArt arduart(arduboy);

int clear_counter = 0;

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
}

void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.pollButtons();
  arduboy.clear();

  if (arduboy.justPressed(UP_BUTTON)) {
    arduart.move_me(ArduArt::Dir::UP);
  }

  if (arduboy.justPressed(DOWN_BUTTON)) {
    arduart.move_me(ArduArt::Dir::DOWN);
  }

  if (arduboy.justPressed(LEFT_BUTTON)) {
    arduart.move_me(ArduArt::Dir::LEFT);
  }

  if (arduboy.justPressed(RIGHT_BUTTON)) {
    arduart.move_me(ArduArt::Dir::RIGHT);
  }

  if (arduboy.pressed(A_BUTTON)) {
    int px = arduart.coords[0];
    int py = arduart.coords[1];

    bool clear = true;
    for (int i = 0; i <= arduart.points_size; i++) {
      if (EEPROM.read(EEPROM_STORAGE_SPACE_START + i) == px && EEPROM.read(EEPROM_STORAGE_SPACE_START + 512 + i) == py) {
        clear = false;
      }
    }
    if (clear) {
      EEPROM.write(EEPROM_STORAGE_SPACE_START + arduart.points_size, arduart.coords[0]);
      EEPROM.write(EEPROM_STORAGE_SPACE_START + 512 + arduart.points_size, arduart.coords[1]);
      arduart.points_size++;
    }
  }

  if (arduboy.pressed(B_BUTTON)) {
    int px = arduart.coords[0];
    int py = arduart.coords[1];
    for (int i = 0; i < arduart.points_size; i++) {
      if (EEPROM.read(EEPROM_STORAGE_SPACE_START + i) == px && EEPROM.read(EEPROM_STORAGE_SPACE_START + 512 + i) == py) {
        EEPROM.write(EEPROM_STORAGE_SPACE_START + i, -1);
        EEPROM.write(EEPROM_STORAGE_SPACE_START + 512 + i, -1);
      }
    }
  }

  if (arduboy.pressed(B_BUTTON) && arduboy.justPressed(UP_BUTTON)) {
    arduart.TILE_SIZE++;
    arduart.GRID_WIDTH = WIDTH / arduart.TILE_SIZE;
    arduart.GRID_HEIGHT = HEIGHT / arduart.TILE_SIZE;
    arduart.grid_x = arduart.coords[0] * arduart.TILE_SIZE;
    arduart.grid_y = arduart.coords[1] * arduart.TILE_SIZE;
  } else if (arduboy.pressed(B_BUTTON) && arduboy.justPressed(DOWN_BUTTON)) {
    arduart.TILE_SIZE--;
    arduart.GRID_WIDTH = WIDTH / arduart.TILE_SIZE;
    arduart.GRID_HEIGHT = HEIGHT / arduart.TILE_SIZE;
    arduart.grid_x = arduart.coords[0] * arduart.TILE_SIZE;
    arduart.grid_y = arduart.coords[1] * arduart.TILE_SIZE;
  }

  if (arduboy.pressed(B_BUTTON) && arduboy.pressed(A_BUTTON)) {
    clear_counter++;
    if (clear_counter == 30) {
      clear_counter = 0;
      for (int i = 0; i < arduart.points_size; i++) {
        EEPROM.write(EEPROM_STORAGE_SPACE_START + i, -1);
        EEPROM.write(EEPROM_STORAGE_SPACE_START + 512 + i, -1);
      }
      arduart.points_size = 0;
    }
  }
  
  arduart.draw_cursor();
  arduart.draw_art();
  
  arduboy.display();
}

