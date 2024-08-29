//Color switch game
#include <random>
#include "raylib.h"
#include "../include/raylib_extras.hpp"

inline void runColorSwitch() {
    //Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    //Window setup
    const char *gameTitle = "Color Switch";
    InitWindow(600, 800, gameTitle);
    SetTargetFPS(60);

    //Variable setup
    enum state {TITLE, GAME, FAIL};
    state currentState = TITLE;

    const Rectangle start = {150, 375, 300, 50};
    const Rectangle redBox = {50, 250, 240, 240};
    const Rectangle blueBox = {310, 250, 240, 240};
    const Rectangle greenBox = {50, 510, 240, 240};
    const Rectangle yellowBox = {310, 510, 240, 240};

    const char *text = (const char *[4]){"Red", "Blue", "Green", "Yellow"}[dis(gen)];
    const Color textColors[4] = {RED, BLUE, GREEN, YELLOW};
    int selected = 0, score = 0, highscore = 0;

    while (!WindowShouldClose()) {
        switch (currentState) {
            //Event handling for if on title screen
            case TITLE:
            {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), start)) {
                    currentState = GAME;
                }
            } break;

            //Event handling for if on game screen
            case GAME: {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    //Check if the text matches the color of the box, if so generate new text and increment score
                    if (CheckCollisionPointRec(GetMousePosition(), redBox) && text == "Red"
                        || CheckCollisionPointRec(GetMousePosition(), blueBox) && text == "Blue"
                        || CheckCollisionPointRec(GetMousePosition(), greenBox) && text == "Green"
                        || CheckCollisionPointRec(GetMousePosition(), yellowBox) && text == "Yellow") {
                        score++;
                        selected = dis(gen);
                        text = (const char *[4]){"Red", "Blue", "Green", "Yellow"}[dis(gen)];

                    } else {
                        currentState = FAIL;
                    }
                }

                if (score > highscore) {
                    highscore = score;
                }
            } break;

            //Event handling for if on fail screen
            case FAIL:
            {
                score = 0;
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), start)) {
                    currentState = GAME;
                }
            } break;
        }

        BeginDrawing();
            ClearBackground(BLACK);

            switch (currentState) {
                //Draw title screen
                case TITLE:
                    DrawTextCentered("Color Switch", {GetScreenWidth() / 2.0f, 310}, 60, PINK);
                    DrawTextCentered("START", {GetScreenWidth() / 2.0f, 400}, 40, RAYWHITE);
                    DrawRectangleRoundedLines(start, 0.3, 10, 4, RAYWHITE);
                    break;

                //Draw game screen
                case GAME:
                    DrawText(TextFormat("Score: %i", score), 10, 10, 20, RAYWHITE);
                    DrawText(TextFormat("High Score: %i", highscore), 10, 35, 20, RAYWHITE);

                    DrawTextCentered(text, {GetScreenWidth() / 2.0f, 175}, 50, textColors[selected]);
                    DrawRectangleRounded(redBox, 0.3, 10, RED);
                    DrawRectangleRounded(blueBox, 0.3, 10, BLUE);
                    DrawRectangleRounded(greenBox, 0.3, 10, GREEN);
                    DrawRectangleRounded(yellowBox, 0.3, 10, YELLOW);
                    break;

                //Draw fail screen
                case FAIL:
                    DrawTextCentered("Failed", {GetScreenWidth() / 2.0f, 310}, 60, PINK);
                    DrawTextCentered("RETRY", {GetScreenWidth() / 2.0f, 400}, 40, RAYWHITE);
                    DrawRectangleRoundedLines(start, 0.3, 10, 4, RAYWHITE);
                    break;
            }

        EndDrawing();
    }
}