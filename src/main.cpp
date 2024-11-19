#include "mouse_collision.cpp"
#include "updating_text.cpp"
#include "sprite_movement.cpp"
#include "color_switch.cpp"
#include "game_of_life.cpp"

int main() {
    enum Example {
        MOUSE_COLLISION,
        UPDATING_TEXT,
        SPRITE_MOVEMENT,
        COLOR_SWITCH,
        GAME_OF_LIFE
    };

    //Select which example to run
    switch (Example targetExample = GAME_OF_LIFE) {
        case MOUSE_COLLISION:
            runMouseCollision();
            break;

        case UPDATING_TEXT:
            runUpdatingText();
            break;

        case SPRITE_MOVEMENT:
            runSpriteMovement();
            break;

        case COLOR_SWITCH:
            runColorSwitch();
            break;

        case GAME_OF_LIFE:
            runGameOfLife();
            break;
    }
}
