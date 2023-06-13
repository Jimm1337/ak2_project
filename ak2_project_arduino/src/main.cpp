#include <Arduino.h>
#include <Keyboard.h>
#include "constants.h"

void setup() {
  static constexpr auto BAUD_RATE = 9600;

  Keyboard.begin();
  Serial1.begin(BAUD_RATE);
}

void loop() {
  static int byteRead;

  if (Serial1.available() != 0) {
    byteRead = Serial1.read();

    switch (byteRead) { // Values from experiments
    case byteValues::CTRL_A:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('a');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_B:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('b');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_C:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('c');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_D:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('d');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_E:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('e');
      Keyboard.releaseAll();
      break;
    case byteValues::TAB:
      Keyboard.press(KEY_TAB);
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_M:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('m');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_K:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('k');
      Keyboard.releaseAll();
      break;
    case byteValues::RETURN:
      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_N:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('n');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_O:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('o');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_P:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('p');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_R:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('r');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_T:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('t');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_U:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('u');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_V:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('v');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_W:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('w');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_X:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('x');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_Y:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('y');
      Keyboard.releaseAll();
      break;
    case byteValues::CTRL_Z:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('z');
      Keyboard.releaseAll();
      break;
    case byteValues::ESC:
      Keyboard.press(KEY_ESC);
      Keyboard.releaseAll();
      break;
    case byteValues::DELETE:
      Keyboard.press(KEY_DELETE);
      Keyboard.releaseAll();
      break;
    case byteValues::BACKSPACE:
      Keyboard.press(KEY_BACKSPACE);
      Keyboard.releaseAll();
      break;
    default:
      Keyboard.write(static_cast<uint8_t>(byteRead));
      break;
    }
  }

  Keyboard.end();
}
