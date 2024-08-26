//Drawing and Updating Text
#include "raylib.h"
#include "../include/raylib_extras.hpp"

inline void runUpdatingText() {
    //Window setup
    const char *windowTitle = "Drawing and Updating Text";
    InitWindow(1000, 800, windowTitle);
    SetTargetFPS(60);

    //Variable setup
    int spaces = 0;

    while (!WindowShouldClose()) {
        //Count the number of times space is pressed
        if (IsKeyPressed(KEY_SPACE))
            spaces++;

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawTextCentered("Number of times space pressed:", Vector2{GetScreenWidth() / 2.f, GetScreenHeight() / 2.f - 26}, 48, BLACK);
            DrawTextCentered(TextFormat("%i", spaces), {GetScreenWidth() / 2.f, GetScreenHeight() / 2.f + 26}, 44, BLACK);
        EndDrawing();
    }
}