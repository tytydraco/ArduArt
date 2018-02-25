#import <Arduboy2.h>
#import "arduart.h"

Arduboy2 arduboy;
ArduArt arduart(arduboy);

const int8_t grid_x = arduart.coords[0] * arduart.TILE_SIZE;
const int8_t grid_y = arduart.coords[1] * arduart.TILE_SIZE;

int8_t points_size = 0;
int8_t points[128][2] = {};

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

  if (arduboy.justPressed(A_BUTTON)) {
    points[points_size][0] = arduart.coords[0];
    points[points_size][1] = arduart.coords[1];
    points_size++;
  }

  if (arduboy.justPressed(B_BUTTON)) {
    int8_t px = arduart.coords[0];
    int8_t py = arduart.coords[1];
    for (int i = 0; i < points_size; i++) {
      if (points[i][0] == px && points[i][1] == py) {
        points[i][0] = -1;
        points[i][1] = -1;
      }
    }
  }

  for (int i = 0; i < points_size; i++) {
    arduboy.fillRect(points[i][0] * arduart.TILE_SIZE, points[i][1] * arduart.TILE_SIZE, arduart.TILE_SIZE, arduart.TILE_SIZE, WHITE);
  }
  
  arduboy.drawRect(arduart.coords[0] * arduart.TILE_SIZE, arduart.coords[1] * arduart.TILE_SIZE, arduart.TILE_SIZE, arduart.TILE_SIZE, WHITE);
  
  arduboy.display();
}

