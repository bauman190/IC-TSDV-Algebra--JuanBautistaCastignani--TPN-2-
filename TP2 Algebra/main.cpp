#include "raylib.h"
#include <math.h>

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
    camera.fovy = 45.0f;                                
    camera.projection = CAMERA_PERSPECTIVE;

    vector vectorA;
    vectorA.start.x = 3.0f;
    vectorA.start.y = 0.0f;
    vectorA.start.z = 1.0f;

    vectorA.end.x = 4.0f;
    vectorA.end.y = 0.0f;
    vectorA.end.z = 2.0f;

    vector vectorB;
    vectorB.start.x = vectorA.start.x;
    vectorB.start.y = vectorA.start.y;
    vectorB.start.z = vectorA.start.z;

    vectorB.end.x = vectorA.end.z;
    vectorB.end.y = vectorA.end.y;
    vectorB.end.z = vectorA.end.x;

    
  
    while (!WindowShouldClose())    
    {
        
        
        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode3D(camera);

        DrawLine3D(vectorA.start, vectorA.end, RED);

        DrawLine3D(vectorB.start, vectorB.end, BLUE);

        DrawGrid(10.0f, 1.0f);
        
        EndMode3D();

        EndDrawing();
        
    }

    
    CloseWindow();        
    

    return 0;
}

