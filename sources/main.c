/*
** EPITECH PROJECT, 2024
** Template-Raylib-C
** File description:
** main
*/

#include "game.h"

int main(void)
{
  InitWindow(800, 600, "Raylib");

  const char *text = "Congrats! You created your first window!";
  const int textWidth = MeasureText(text, 20);
  const int posX = (GetScreenWidth() - textWidth) / 2;
  const int posY = GetScreenHeight() / 2;

  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText(text, posX, posY, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();
  return (0);
}