#include <iostream>
#include <raylib.h>

using namespace std;

Color Blue = Color{0, 115, 207, 255};
Color light_Blue = Color{99, 166, 255, 255};
Color tennis_yellow = Color{223, 255, 79, 255};

int player_score = 0;
int cpu_score = 0;


class Ball{
    public:
    float x,y;
    int speed_x,speed_y;
    int radius;

    void Draw(){
        DrawCircle(x,y,radius,tennis_yellow);
    }

    void update(){//to make the ball move
        x += speed_x;
        y += speed_y;

        if (y + radius >= GetScreenHeight() || y - radius <= 0){//if there's collision with the bottom || top of the screen(x & y are at the center of the ball)
            speed_y *= -1;//it reverses the way
        }
        if (x + radius >= GetScreenWidth()){//cpu wins in this case because the player couldn't catch the ball
            cpu_score++;
            ResetBall();
        }
        if(x - radius <= 0){
            player_score++;
            ResetBall();
        }
    }

    void ResetBall(){//for when one of the players wins
        x = GetScreenWidth()/2;
        y = GetScreenHeight()/2;
        //give the ball a random direction in both x and y axis:
        int speed_choices[2] = {-1,1};
        speed_x *= speed_choices[GetRandomValue(0,1)];
        speed_y *= speed_choices[GetRandomValue(0,1)];
    }
};

class Paddle{
    public:
    float x,y;
    float width, height;
    int speed; //it moves up and down only, so we need only one speed

    void Draw(){
        DrawRectangleRounded(Rectangle{x,y,width,height},0.8,0,WHITE);//for a rec with rounded edges:DrawRectangleRounded(rec, roundness,segment,color)
    }

    void LimitMvt(){
        if (y <= 0){
            y = 0;
        }
        if(y + height >= GetScreenHeight()){
            y = GetScreenHeight() - height;
        }
    }

    void update(){
        if (IsKeyDown(KEY_UP)){//if the user presses the up key(to move up)
            y -= speed;//to move up y decreases
        }
        if (IsKeyDown(KEY_DOWN)){//if the user presses the up key(to move up)
            y += speed;
        }

        LimitMvt();//so that the rectangle doesn't move out of the screen
    }
};

class CPU_paddle: public Paddle{//inheritance from paddle
//we'll provide a different update method because we want the computer to move the paddle not the player
    public:

    void update(int ball_y){//basic algorithm: we check the Ypos of the ball, if it's above the Ypos of the center of the paddle we move the paddle up, else we move it down
        if (y + height/2 > ball_y){
            y -= speed;
        }
        if (y + height <= ball_y){
            y += speed;
        }
        LimitMvt();
    }
};

Ball ball;
Paddle player;
CPU_paddle cpu;

int main () {
    cout<<"starting the game"<<endl;
    const int screen_width = 1280;
    const int screen_height = 800;
    InitWindow(screen_width, screen_height, "My Pong Game!");//the function initialises a window.its parameters are width,height and title of the window

    SetTargetFPS(60);//sepcifies how fast the game runs(the ineger argument is the nbre of frames per second)
    //if we don't specify the fps the computer will run the game as fast as it can,so the game speed will depend on the speed of the computer
    //i have defined that the while loop will run and the display is updated 60 times per second
    
    ball.radius = 20;
    ball.x = screen_width/2;
    ball.y = screen_height/2;
    ball.speed_x = 7;// the ball moves 7 pixels per mvt
    ball.speed_y = 7;

    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width -10;//the rectangle is drawn from its top left corner
    player.y = screen_height/2 - player.height/2;
    player.speed = 6;

    cpu.height = 120;
    cpu.width = 25;
    cpu.x = 10;
    cpu.y = screen_height/2 - cpu.height/2;
    cpu.speed = 6;

    while(WindowShouldClose() == false){//game loop
//WindowShouldClose() function checks if the escape key on the keyboard is pressed or if the close icon of the window is pressed and returns true if that's the case
//so if it returns true, the game loop ends and the window is destroyed
        BeginDrawing(); //this fct creates a blank canvas so we can draw our game objects on

        //updating
        ball.update();//this increases the x and y coordinates by 7 pixels each time the game loop is run
        player.update();
        cpu.update(ball.y);

        //checking for collisions
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height})){
            ball.speed_x *= -1;
        }
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height})){
            ball.speed_x *= -1;
        }
        //drawing
        ClearBackground(Blue);//fill the window we are drawing on with black: we clear the window
        //we dont want the objects to leave a trace when moving(without clearing the backgroung we'll see all the positions the objects had, they don't get erased simply because they moved)
        DrawCircle(screen_width/2, screen_height/2, 150, light_Blue);
        DrawLine(screen_width/2,0,screen_width/2,screen_height,WHITE);
        ball.Draw();
        cpu.Draw();
        player.Draw();

        DrawText(TextFormat("%i",cpu_score), screen_width/4, 20, 80, WHITE);// DrawText(text, xpos, ypos, fontsize, WHITE);
        DrawText(TextFormat("%i",player_score), 3*screen_width/4, 20, 80, WHITE);
        EndDrawing();//ends the canvas drawing
    }

    //now, everytime we create a windo we have to destrpy it using the closewindow() function
    CloseWindow();

    return 0;
}