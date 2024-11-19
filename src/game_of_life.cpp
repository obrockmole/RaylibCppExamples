//Conways Game of Life
#include <vector>
#include "raylib.h"

inline void runGameOfLife() {
	//Window setup
	const char *gameTitle = "Game of Life";
	InitWindow(1440, 900, gameTitle);
	SetExitKey(KEY_NULL);
	SetTargetFPS(12);

	//Variables
	enum CellState {DEAD, ALIVE};
	std::vector<std::vector<CellState>> cells(45, std::vector<CellState>(72, DEAD));
	bool running = false;

	while (!WindowShouldClose()) {
		//Starting a pausing
		if (IsKeyPressed(KEY_SPACE)) {
			running = !running;
		}

		//Reset the board
		if (IsKeyPressed(KEY_R) && !running)
			cells = std::vector<std::vector<CellState>>(45, std::vector<CellState>(72, DEAD));

		if (running) {
			std::vector<std::vector<CellState>> currentCells = cells; //Save a copy of the current cells to count neighbours
			//Loop through all the cells
			for (int i = 0; i < cells.size(); i++) {
				for (int j = 0; j < cells[i].size(); j++) {
					int aliveNeighbors = 0;
					//Count all alive neighbors using the cell copies
					for (int k = -1; k <= 1; k++) {
						for (int l = -1; l <= 1; l++) {
							if (i + k >= 0 && j + l >= 0 && i + k < cells.size() && j + l < cells[i].size()) {
								if ((currentCells[(i + k + currentCells.size()) % currentCells.size()][(j + l + currentCells[i].size()) % currentCells[i].size()] == ALIVE) && !(k == 0 && l == 0))
									aliveNeighbors++;
							}
						}
					}

					//Apply rules to the cells
					//If a cell is alive with 1 or 0 alive neighbors, that cell dies (underpopulation)
					//If a cell is alive with 4 or more alive neighbors, that cell dies (overpopulation)
					//If a cell is alive with 2 or 3 alive neighbors, that cell remains alive (survival)
					//If a cell is dead with 3 alive neighbors, that cell comes alive (reproduction)
					if (cells[i][j] == ALIVE) {
						if (aliveNeighbors < 2 || aliveNeighbors > 3)
							cells[i][j] = DEAD;
					} else if (aliveNeighbors == 3) {
						cells[i][j] = ALIVE;
					}
				}
			}
		}

		BeginDrawing();
			ClearBackground({180, 180, 180, 255});

			//Loop through each cell
			for (int i = 0; i < cells.size(); i++) {
				for (int j = 0; j < cells[i].size(); j++) {
					const Rectangle cell = {j * 20.0f, i * 20.0f, 20.0f, 20.0f}; //Get cell position and size
					DrawRectangleRec(cell, cells[i][j] == ALIVE ? Color{50, 170, 200, 255} : BLANK); //Draw the cell
					DrawRectangleLines(cell.x, cell.y, cell.width, cell.height, {235, 235, 235, 255}); //Draw grid

					//Toggle cell state when clicked
					if (CheckCollisionPointRec(GetMousePosition(), cell) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !running)
						cells[i][j] = cells[i][j] == ALIVE ? DEAD : ALIVE;
				}
			}

			DrawText(running ? "Running" : "Paused", 10, 10, 32, running ? RED : DARKGREEN); //Display running status
		EndDrawing();
	}
}