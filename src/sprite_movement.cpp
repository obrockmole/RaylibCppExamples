//Moving a sprite with the keyboard
#include "raylib.h"

inline void runSpriteMovement() {
    //Window setup
    const char *gameTitle = "Sprite Movement";
    InitWindow(1000, 800, gameTitle);
    SetTargetFPS(60);

    //Variable setup
    Rectangle player = {480, 380, 40, 40};

    while (!WindowShouldClose()) {
        //Get keyboard input for player movement
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
            player.y -= 4;
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
            player.y += 4;
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
            player.x -= 4;
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
            player.x += 4;

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawRectangle(player.x, player.y, player.width, player.height, RED); //Draw the player
        EndDrawing();
    }
}