#include "mouse_collision.cpp"
#include "updating_text.cpp"
#include "sprite_movement.cpp"
#include "color_switch.cpp"

int main() {
    enum Example {
        MOUSE_COLLISION,
        UPDATING_TEXT,
        SPRITE_MOVEMENT,
        COLOR_SWITCH,
        GAME_OF_LIFE
    };

    //Select which example to run
    switch (Example targetExample = COLOR_SWITCH) {
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
    }
}
