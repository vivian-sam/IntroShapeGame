#include "raylib.h"

int main()
{
    // window dimensions
    int width{800};
    int height{450};

   InitWindow(width, height, "Avoid the Box!");

    // circle coordinates
    int circle_x{200};
    int circle_y{200};
    float radius{25};
    Color circle_color{BLUE};
    //circle edges
    int l_circle_x{circle_x - radius};
    int r_circle_x{circle_x + radius};
    int u_circle_y{circle_y - radius};
    int b_circle_y{circle_y + radius};

    // rectangle coordinates
    int rect_x{400};
    int rect_y{0};
    int rect_length{50};
    Color rect_color{RED};
    int direction = 10;
    // rectangle edges
    int l_rect_x{rect_x};
    int r_rect_x{rect_x + rect_length};
    int u_rect_y{rect_y};
    int b_rect_y{rect_y + rect_length};

    bool collision_with_rect = 
                                (b_rect_y >= u_circle_y) &&
                                (u_rect_y <= b_circle_y) &&
                                (r_rect_x >= l_circle_x) &&
                                (l_rect_x <= r_circle_x);

    
    //Game Over variables
    int text_x{400};
    int text_y{200};
    int font_size{20};
    Color text_color{RED};

    //Continue variables
    int continue_x{400};
    int continue_y{250};
    int f_continue_font{15};
    Color continue_color{RED};

    int fps{60};

    SetTargetFPS(fps);

    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        //check collision of rectangle with circle
        if(collision_with_rect){
            DrawText("GAME OVER!", text_x, text_y, font_size, text_color);
            DrawText("Continue? Y N(ESC)", continue_x, continue_y, f_continue_font, continue_color);

            if(IsKeyDown(KEY_Y)){
                collision_with_rect = false;

                // reset circle coordinates
                circle_x = 25;
                circle_y = 200;
            }
        }

        else{
            // Game logic begins    

            //update edges
            //circle edges
            l_circle_x = circle_x - radius;
            r_circle_x = circle_x + radius;
            u_circle_y = circle_y - radius;
            b_circle_y = circle_y + radius;

            //rectangle edges
            l_rect_x = rect_x;
            r_rect_x = rect_x + rect_length;
            u_rect_y = rect_y;
            b_rect_y = rect_y + rect_length;

            //update collision
            collision_with_rect = 
                                (b_rect_y >= u_circle_y) &&
                                (u_rect_y <= b_circle_y) &&
                                (r_rect_x >= l_circle_x) &&
                                (l_rect_x <= r_circle_x);

            DrawCircle(circle_x, circle_y, radius, circle_color);
            DrawRectangle(rect_x, rect_y, rect_length, rect_length, rect_color);

            //move rectangle
            rect_y += direction;

            if(rect_y > height || rect_y < 0){
                direction = -direction;
            }


            //move circle
            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }

            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }
        }
        // Game logic ends
        EndDrawing();    
    }
    return 0;
}