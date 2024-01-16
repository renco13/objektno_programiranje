#include "raylib.h"

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Simple Menu Example");

    // Menu variables
    int selectedOption = 0;
    const char* menuOptions[] = { "Start Game", "Quit" };

    while (!WindowShouldClose()) {
        // Update
        // TODO: Add your game logic here

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw title
        DrawText("Tenkici", screenWidth / 2 - MeasureText("Tenkici", 100) / 2, 150, 100, WHITE);

        // Draw menu options with smaller font size
        for (int i = 0; i < 2; i++) {
            DrawText(menuOptions[i], screenWidth / 2 - MeasureText(menuOptions[i], 20) / 2, screenHeight / 2 + i * 40, 20, (i == selectedOption) ? RED : WHITE);
        }

        // Input handling
        if (IsKeyPressed(KEY_UP) && selectedOption > 0) {
            selectedOption--;
        }

        if (IsKeyPressed(KEY_DOWN) && selectedOption < 1) {
            selectedOption++;
        }

        if (IsKeyPressed(KEY_ENTER)) {
            // Execute actions based on the selected option
            if (selectedOption == 0) {
                // Start Game logic
                // TODO: Add your start game logic here
            }
            else if (selectedOption == 1) {
                // Quit the program
                break;
            }
        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
