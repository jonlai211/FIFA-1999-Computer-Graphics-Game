//
// Created by jonathan on 12/4/22.
//

#include "Assessment2/include/Keyboard.h"
#include "Assessment2/include/GameState.h"

void GameState::KeyboardControl(unsigned char key, int x, int y) {
    if (key == 'q' || key == 'Q' || key == 27) {
        LOGI("Quitting...");
        exit(0);
    } else {
        LOGI("Key pressed: %c", key);
        switch (key) {
            case 'r':
                LOGI("Resetting Layout & Camera...");
                camera_.Reset();
                break;
            case 'a':
                camera_.MoveLeft();
                break;
            case 's':
                camera_.MoveBackward();
                break;
            case 'S':
                camera_.MoveDown();
                break;
            case 'd':
                camera_.MoveRight();
                break;
            case 'w':
                camera_.MoveForward();
                break;
            case 'W':
                camera_.MoveUp();
                break;
            case 'n':
                if (lighting_.GetMode() == NIGHT_MODE) {
                    lighting_.SetMode(DAY_MODE);
                } else {
                    lighting_.SetMode(NIGHT_MODE);
                }
                break;
            default:
                break;
        }
    }
}