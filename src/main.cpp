#include "mouse-collision.cpp"
#include "updating_text.cpp"

int main() {
    enum Example {
        MOUSE_COLLISION,
        UPDATING_TEXT
    };

    //Select which example to run
    switch (Example targetExample = UPDATING_TEXT) {
        case MOUSE_COLLISION:
            runMouseCollision();
            break;

        case UPDATING_TEXT:
            runUpdatingText();
            break;
    }
}
