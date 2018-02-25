#import <Arduboy2.h>
#import "keys.h"
#import "arduart.h"

Arduboy2 arduboy;
Keys keys(arduboy);
ArduArt arduart(arduboy);

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  
}

void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.clear();
  if (arduboy.everyXFrames(5)) {
    if (arduboy.pressed(UP_BUTTON)) {
      arduart.move_me(ArduArt::Dir::UP);
    }

    if (arduboy.pressed(DOWN_BUTTON)) {
       arduart.move_me(ArduArt::Dir::DOWN);
    }

    if (arduboy.pressed(LEFT_BUTTON)) {
       arduart.move_me(ArduArt::Dir::LEFT);
    }

    if (arduboy.pressed(RIGHT_BUTTON)) {
       arduart.move_me(ArduArt::Dir::RIGHT);
    }
  }

  int8_t grid_x = arduart.coords[0] * arduart.TILE_SIZE;
  int8_t grid_y = arduart.coords[1] * arduart.TILE_SIZE;
  arduboy.drawRect(grid_x, grid_y, arduart.TILE_SIZE, arduart.TILE_SIZE, WHITE);
  
  arduboy.display();
}

