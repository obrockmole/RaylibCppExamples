//Mouse Collision in rectangle
#include "raylib.h"

inline void runMouseCollision() {
    //Window setup
    const char *windowTitle = "Mouse Collision";
    InitWindow(1000, 800, windowTitle);
    SetExitKey(KEY_NULL);
    SetTargetFPS(60);

    //Variable setup
    const Rectangle box = {450, 350, 100, 100};

    while (!WindowShouldClose()) {
        //Check if the mouse is inside the box
        const bool colliding = CheckCollisionPointRec(GetMousePosition(), box);

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawRectangle(450, 350, 100, 100, colliding ? RED : GREEN); //Draw box
        EndDrawing();
    }
}