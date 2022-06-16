#include "raylib.h"

int main()
{
    // window dimensions
    int width{800};
    int height{450};

   InitWindow(width, height, "Vivian's Window");

    // circle coordinates
    int circle_x{200};
    int circle_y{200};
    float radius{25};
    Color circle_color{BLUE};

    // rectangle coordinates
    int rect_x{400};
    int rect_y{0};
    int rect_width{50};
    int rect_height = rect_width;
    Color rect_color{RED};


    int fps{60};

    SetTargetFPS(fps);

    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logic begins
        DrawCircle(circle_x, circle_y, radius, circle_color);
        DrawRectangle(rect_x, rect_y, rect_width, rect_height, rect_color);

        //move rectangle
        rect_y += 10


        //move circle
        if (IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x += 10;
        }

        if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x -= 10;
        }

        // Game logic ends
        EndDrawing();    
    }
    return 0;
}