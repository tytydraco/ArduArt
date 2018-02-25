#import <Arduboy2.h>

Arduboy2 arduboy;

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);
  
}

void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.clear();
  
  arduboy.display();
}
