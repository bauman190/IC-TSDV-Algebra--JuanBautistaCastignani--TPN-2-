#include "raylib.h"
#include <math.h>
#include <iostream>

struct vector
{
    Vector3 start;
    Vector3 end;
};



int main()
{
    
    const int screenWidth = 1500;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "La piramide");

    SetTargetFPS(60);    

    Camera3D camera = { 0 };
    camera.position = { 0.0f, 10.0f, 10.0f };  
    camera.target = { 0.0f, 0.0f, 0.0f };      
    camera.up = { 0.0f, 1.0f, 0.0f };          
    camera.fovy = 70.0f;                                
    camera.projection = CAMERA_PERSPECTIVE;
    
    

    vector vectorA;
    vectorA.start.x = 0.0f;
    vectorA.start.y = 0.0f;
    vectorA.start.z = 0.0f;

    vectorA.end.x = GetRandomValue(1,5);
    vectorA.end.y = GetRandomValue(1,5);
    vectorA.end.z = GetRandomValue(1,5);

    std::cout << vectorA.end.x << " " << vectorA.end.y << " " << vectorA.end.z;

    vector vectorB;
    vectorB.start.x = vectorA.start.x;
    vectorB.start.y = vectorA.start.y;
    vectorB.start.z = vectorA.start.z;

    vectorB.end.x = vectorA.end.z;
    vectorB.end.y = vectorA.end.y;
    vectorB.end.z = -vectorA.end.x;

    vector vectorC;
    vectorC.start.x = vectorA.start.x;
    vectorC.start.y = vectorA.start.y;
    vectorC.start.z = vectorA.start.z;

    vectorC.end.x = ((vectorA.end.y * vectorB.end.z) - (vectorA.end.z * vectorB.end.y));
    vectorC.end.y = ((vectorA.end.z * vectorB.end.x) - (vectorA.end.x * vectorB.end.z));
    vectorC.end.z = ((vectorA.end.x * vectorB.end.y) - (vectorA.end.y * vectorB.end.x));

    Vector3 corte;

    corte.y = vectorA.end.x / 3;
    corte.x = (vectorC.end.x / vectorC.end.y) * corte.y;
    corte.z = (vectorC.end.z / vectorC.end.y) * corte.y;

    SetCameraMode(camera, CAMERA_ORBITAL);
  
    while (!WindowShouldClose())    
    {      
    
        UpdateCamera(&camera);

        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode3D(camera);

        DrawLine3D(vectorA.start, vectorA.end, RED);

        DrawLine3D(vectorB.start, vectorB.end, BLUE);

        DrawLine3D(vectorC.start, corte, GREEN);

        DrawGrid(20.0f, 1.0f);
        
        EndMode3D();

        EndDrawing();
        
    }

    CloseWindow();        
    

    return 0;
}

