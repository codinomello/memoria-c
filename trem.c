#include "raylib.h"
#include "raymath.h"
#include <stdlib.h>
#include <math.h>

#define MAX_OBSTACLES 10
#define MAX_PASSENGERS 15
#define TRACK_LENGTH 200.0f

typedef struct {
    Vector3 pos;
    float rotation;
    float speed;
    int score;
    int passengers;
    bool gameOver;
} Train;

typedef struct {
    Vector3 pos;
    bool active;
    float type; // 0 = box, 1 = cone
} Obstacle;

typedef struct {
    Vector3 pos;
    bool collected;
    float bobTimer;
} Passenger;

void InitGame(Train *train, Obstacle obstacles[], Passenger passengers[]) {
    train->pos = (Vector3){0, 0.5f, 0};
    train->rotation = 0;
    train->speed = 5.0f;
    train->score = 0;
    train->passengers = 0;
    train->gameOver = false;
    
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        obstacles[i].pos = (Vector3){
            (float)(rand() % 10 - 5),
            0.5f,
            -10.0f - (rand() % 150)
        };
        obstacles[i].active = true;
        obstacles[i].type = (float)(rand() % 2);
    }
    
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        passengers[i].pos = (Vector3){
            (float)(rand() % 8 - 4),
            0.3f,
            -15.0f - (rand() % 180)
        };
        passengers[i].collected = false;
        passengers[i].bobTimer = (float)(rand() % 100) / 100.0f;
    }
}

void UpdateTrain(Train *train, Obstacle obstacles[], Passenger passengers[]) {
    if (train->gameOver) {
        if (IsKeyPressed(KEY_R)) {
            InitGame(train, obstacles, passengers);
        }
        return;
    }
    
    // Movimento lateral
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        train->pos.x -= 3.0f * GetFrameTime();
        train->rotation = -15.0f;
    } else if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        train->pos.x += 3.0f * GetFrameTime();
        train->rotation = 15.0f;
    } else {
        train->rotation *= 0.9f;
    }
    
    // Limitar movimento lateral
    if (train->pos.x < -6.0f) train->pos.x = -6.0f;
    if (train->pos.x > 6.0f) train->pos.x = 6.0f;
    
    // Acelerar/desacelerar
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        train->speed += 2.0f * GetFrameTime();
        if (train->speed > 12.0f) train->speed = 12.0f;
    } else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        train->speed -= 3.0f * GetFrameTime();
        if (train->speed < 3.0f) train->speed = 3.0f;
    }
    
    // Atualizar obstáculos
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        if (obstacles[i].active) {
            obstacles[i].pos.z += train->speed * GetFrameTime();
            
            // Checar colisão
            if (CheckCollisionBoxes(
                (BoundingBox){{train->pos.x - 0.5f, train->pos.y - 0.3f, train->pos.z - 0.8f},
                             {train->pos.x + 0.5f, train->pos.y + 0.7f, train->pos.z + 0.8f}},
                (BoundingBox){{obstacles[i].pos.x - 0.5f, obstacles[i].pos.y - 0.5f, obstacles[i].pos.z - 0.5f},
                             {obstacles[i].pos.x + 0.5f, obstacles[i].pos.y + 0.5f, obstacles[i].pos.z + 0.5f}}
            )) {
                train->gameOver = true;
            }
            
            // Respawn obstáculo
            if (obstacles[i].pos.z > 10.0f) {
                obstacles[i].pos.z = -TRACK_LENGTH;
                obstacles[i].pos.x = (float)(rand() % 10 - 5);
                train->score += 10;
            }
        }
    }
    
    // Atualizar passageiros
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        if (!passengers[i].collected) {
            passengers[i].pos.z += train->speed * GetFrameTime();
            passengers[i].bobTimer += GetFrameTime() * 3.0f;
            passengers[i].pos.y = 0.3f + sinf(passengers[i].bobTimer) * 0.1f;
            
            // Checar coleta
            if (Vector3Distance(train->pos, passengers[i].pos) < 1.2f) {
                passengers[i].collected = true;
                train->passengers++;
                train->score += 50;
            }
            
            // Respawn passageiro
            if (passengers[i].pos.z > 10.0f) {
                passengers[i].pos.z = -TRACK_LENGTH;
                passengers[i].pos.x = (float)(rand() % 8 - 4);
            }
        } else {
            passengers[i].pos.z += train->speed * GetFrameTime();
            if (passengers[i].pos.z > 10.0f) {
                passengers[i].pos.z = -TRACK_LENGTH;
                passengers[i].pos.x = (float)(rand() % 8 - 4);
                passengers[i].collected = false;
            }
        }
    }
}

void DrawTrain(Train train) {
    // Corpo do trem
    DrawCubeV(train.pos, (Vector3){1.0f, 0.7f, 1.5f}, RED);
    DrawCubeWiresV(train.pos, (Vector3){1.0f, 0.7f, 1.5f}, MAROON);
    
    // Chaminé
    Vector3 chimneyPos = {train.pos.x, train.pos.y + 0.6f, train.pos.z + 0.3f};
    DrawCylinder(chimneyPos, 0.15f, 0.15f, 0.5f, 8, DARKGRAY);
    
    // Janelas
    DrawCube((Vector3){train.pos.x - 0.35f, train.pos.y + 0.2f, train.pos.z}, 0.2f, 0.3f, 0.3f, SKYBLUE);
    DrawCube((Vector3){train.pos.x + 0.35f, train.pos.y + 0.2f, train.pos.z}, 0.2f, 0.3f, 0.3f, SKYBLUE);
    
    // Rodas
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            Vector3 wheelPos = {train.pos.x + i * 0.5f, train.pos.y - 0.4f, train.pos.z + j * 0.4f};
            DrawCylinder(wheelPos, 0.2f, 0.2f, 0.1f, 8, DARKGRAY);
        }
    }
}

void DrawTrack(float offset) {
    for (int i = -20; i < 20; i++) {
        float z = i * 10.0f + fmodf(offset, 10.0f);
        
        // Trilhos
        DrawCube((Vector3){-2.0f, 0, z}, 0.2f, 0.1f, 10.0f, DARKBROWN);
        DrawCube((Vector3){2.0f, 0, z}, 0.2f, 0.1f, 10.0f, DARKBROWN);
        
        // Dormentes
        for (int j = 0; j < 5; j++) {
            float dormZ = z - 4.0f + j * 2.0f;
            DrawCube((Vector3){0, -0.05f, dormZ}, 5.0f, 0.1f, 0.3f, BROWN);
        }
    }
}

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Trenzinho 3D - Colete Passageiros!");
    
    Camera3D camera = {0};
    camera.position = (Vector3){0.0f, 5.0f, 8.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    Train train;
    Obstacle obstacles[MAX_OBSTACLES];
    Passenger passengers[MAX_PASSENGERS];
    
    InitGame(&train, obstacles, passengers);
    
    float trackOffset = 0;
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        UpdateTrain(&train, obstacles, passengers);
        
        if (!train.gameOver) {
            trackOffset += train.speed * GetFrameTime();
        }
        
        // Atualizar câmera
        camera.position = (Vector3){train.pos.x * 0.3f, 5.0f, train.pos.z + 8.0f};
        camera.target = train.pos;
        
        BeginDrawing();
            ClearBackground(SKYBLUE);
            
            BeginMode3D(camera);
                // Chão
                DrawPlane((Vector3){0, -0.1f, 0}, (Vector2){100, 200}, DARKGREEN);
                
                // Trilhos
                DrawTrack(trackOffset);
                
                // Trem
                DrawTrain(train);
                
                // Obstáculos
                for (int i = 0; i < MAX_OBSTACLES; i++) {
                    if (obstacles[i].active) {
                        if (obstacles[i].type == 0) {
                            DrawCube(obstacles[i].pos, 1.0f, 1.0f, 1.0f, ORANGE);
                            DrawCubeWires(obstacles[i].pos, 1.0f, 1.0f, 1.0f, BROWN);
                        } else {
                            DrawCylinder(obstacles[i].pos, 0, 0.7f, 1.0f, 8, PURPLE);
                        }
                    }
                }
                
                // Passageiros
                for (int i = 0; i < MAX_PASSENGERS; i++) {
                    if (!passengers[i].collected) {
                        DrawSphere(passengers[i].pos, 0.3f, YELLOW);
                        DrawCylinder((Vector3){passengers[i].pos.x, passengers[i].pos.y - 0.3f, passengers[i].pos.z}, 
                                   0.15f, 0.15f, 0.3f, 8, BLUE);
                    }
                }
            EndMode3D();
            
            // HUD
            DrawRectangle(10, 10, 250, 100, Fade(BLACK, 0.7f));
            DrawText(TextFormat("PONTOS: %d", train.score), 20, 20, 20, YELLOW);
            DrawText(TextFormat("PASSAGEIROS: %d", train.passengers), 20, 50, 20, LIME);
            DrawText(TextFormat("VELOCIDADE: %.1f", train.speed), 20, 80, 20, WHITE);
            
            DrawText("WASD/SETAS: Mover", 10, screenHeight - 60, 15, WHITE);
            DrawText("W/S: Acelerar/Freiar", 10, screenHeight - 40, 15, WHITE);
            
            if (train.gameOver) {
                DrawRectangle(0, 0, screenWidth, screenHeight, Fade(RED, 0.5f));
                DrawText("GAME OVER!", screenWidth/2 - 150, screenHeight/2 - 50, 50, WHITE);
                DrawText(TextFormat("Pontuacao Final: %d", train.score), screenWidth/2 - 120, screenHeight/2 + 20, 30, YELLOW);
                DrawText("Pressione R para reiniciar", screenWidth/2 - 140, screenHeight/2 + 70, 20, WHITE);
            }
        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}