#include <iostream>
#include "raylib.h"
#include "tank.h"
#include "projectile.h"
#include "turntimer.h"

void GameMenu(); //trigger za glavni meni
void GameSettings(); //trigger za postavke
void GameQuit(); //trigger za izlazak iz igre
void GameStart(); //trigger za graficko pokretanje igre
void GameUpdatePlayFrame(); //trigger za update grafickog crtnja igre ili pokrecanja igra 

const int screenWidth = 854;
const int screenHeight = 480;

int main(void)
{
    //REZOLUCIJa ekrana

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    //Kreiranje tenka

    //Staro Kreiranje tenka
    //Tank tank1(screenWidth / 4 - 20, screenHeight / 2 - 20, YELLOW, 200.0f, 100.0f, 400.0f, 3);
    //Tank tank2(3 * screenWidth / 4 - 20, screenHeight / 2 - 20, BLUE, 200.0f, 100.0f, 400.0f, 3);
    //Tank* activeTankTurn = &tank1;
    //int activeTankTurn = 1;
    //TurnTimer turnTimer(30.0);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        //Kontrole za micanje tenkova livo desno
        //tank1.Move(KEY_A, KEY_D);
        //tank2.Move(KEY_LEFT, KEY_RIGHT);

        ////Kontrole za ciljanje
        //tank1.Aim(KEY_W, KEY_S);
        //tank2.Aim(KEY_UP, KEY_DOWN);

        ////Kontrole za pucanje tenkova
        //tank1.Shoot(KEY_SPACE);
        //tank2.Shoot(KEY_SPACE);

        ////Updatea tenkove i ciji je red
        //tank1.Update();
        //tank2.Update();

        //Graficki prikaz na ekranu
        
        //BeginDrawing();
        //ClearBackground(BLACK);

        ////prikaz tenkova
        //tank1.Draw();
        //tank2.Draw();

        ////prikaz raketa
        //tank1.DrawProjectile();
        //tank2.DrawProjectile();

        //while (true) {
        //    while (tank1.IsAlive() <= 0 || tank2.IsAlive() <= 0) {
        //
        //        //Kontrole za trenutacno aktivni tenk ili tenk ciji je potez trenurtacno
        //        //if (tank1.IsTurnActive()) {
        //        //    tank1.Move(KEY_A, KEY_D);
        //        //    tank1.Shoot(KEY_W);
        //        //}
        //        //else if (tank2.IsTurnActive()) {
        //        //    tank2.Move(KEY_LEFT, KEY_RIGHT);
        //        //    tank2.Shoot(KEY_UP);
        //        //}
        //
        //        turnTimer.Start();
        //
        //        if (activeTankTurn == 1) {
        //            tank1.Move(KEY_A, KEY_D);
        //            tank1.Shoot(KEY_W);
        //        }
        //        else if (activeTankTurn == 2) {
        //            tank2.Move(KEY_LEFT, KEY_RIGHT);
        //            tank2.Shoot(KEY_UP);
        //        }
        //
        //        ////Kontrole za micanje tenkova livo desno
        //        //tank1.Move(KEY_A, KEY_D);
        //        //tank2.Move(KEY_LEFT, KEY_RIGHT);
        //
        //        ////Kontrole za pucanje tenkova
        //        //tank1.Shoot(KEY_W);
        //        //tank2.Shoot(KEY_UP);
        //
        //        //Updatea tenkove i ciji je red
        //        tank1.Update();
        //        tank2.Update();
        //
        //        //Graficki prikaz na ekranu
        //        BeginDrawing();
        //        ClearBackground(BLACK);
        //
        //        //prikaz tenkova
        //        tank1.Draw();
        //        tank2.Draw();
        //
        //        //prikaz raketa
        //        tank1.DrawProjectile();
        //        tank2.DrawProjectile();
        //
        //        //prikaz vremena preostalog za trenutacni tenk
        //        //DrawText(TextFormat("Remaining time is: %.2f", activeTankTurn->GetRemainingTime()), 10, 10, 20, WHITE);
        //
        //        //activeTankTurn->EndTurn();
        //        //activeTankTurn = (activeTankTurn == &tank1) ? &tank2 : &tank1;
        //        //activeTankTurn->StartTurn();
        //
        //        while (!turnTimer.IsTimeUp()) {
        //            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        //        }
        //
        //        activeTankTurn = (activeTankTurn == 1) ? 2 : 1;
        //    }
        //}

        //EndDrawing();
    }

    CloseWindow();

    return 0;
}

void GameStart() {
    Tank tank1();
    Tank tank2();


}
