#include <iostream>
#include "raylib.h"
#include "tank.h"
#include "projectile.h"
#include "turntimer.h"

int main(void)
{
    //REZOLUCIJa ekrana
    const int screenWidth = 854;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    //Kreiranje tenka
    Tank tank1(screenWidth / 4 - 20, screenHeight / 2 - 20, YELLOW, 200.0f, 400.0f);
    Tank tank2(3 * screenWidth / 4 - 20, screenHeight / 2 - 20, BLUE, 200.0f, 400.0f);
    Tank* activeTankTurn = &tank1;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        //Kontrole za trenutacno aktivni tenk ili tenk ciji je potez trenurtacno
        if (tank1.IsTurnActive()) {
            tank1.Move(KEY_A, KEY_D);
            tank1.Shoot(KEY_W);
        }
        else if (tank1.IsTurnActive()) {
            tank2.Move(KEY_LEFT, KEY_RIGHT);
            tank2.Shoot(KEY_UP);
        }

        ////Kontrole za micanje tenkova livo desno
        //tank1.Move(KEY_A, KEY_D);
        //tank2.Move(KEY_LEFT, KEY_RIGHT);

        ////Kontrole za pucanje tenkova
        //tank1.Shoot(KEY_W);
        //tank2.Shoot(KEY_UP);

        //Updatea tenkove i ciji je red
        tank1.Update();
        tank2.Update();

        //Graficki prikaz na ekranu
        BeginDrawing();
        ClearBackground(BLACK);

        //prikaz tenkova
        tank1.Draw();
        tank2.Draw();

        //prikaz raketa
        tank1.DrawProjectile();
        tank2.DrawProjectile();

        //prikaz vremena preostalog za trenutacni tenk
        //DrawText(TextFormat("Remaining time is: %.2f", activeTankTurn->GetRemainingTime()), 10, 10, 20, WHITE);

        activeTankTurn->EndTurn();
        activeTankTurn = (activeTankTurn == &tank1) ? &tank2 : &tank1;
        activeTankTurn->StartTurn();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
