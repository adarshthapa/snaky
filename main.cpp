#include <iostream>
#include <stdlib.h>
#include <thread>
#include <chrono> 
#include <conio.h>
using namespace std;

bool gameOver;

const int WIDTH = 20;
const int HEIGHT = 20;

int x, y; // position of the player
int foodX, foodY; // position of the food
int score;
int tailX[60], tailY[60];
int nTail; // increments each time snake eats the food

enum enumDirect {STOP = 0, LEFT, RIGHT, UP, DOWN}; // enumerator for directions
enumDirect dir;

void settings() {
    gameOver = false;
    dir = STOP; // prevents the player from moving itself when the game starts
    
    // players will be starting from the center of the height & width
    x = WIDTH / 2; 
    y = HEIGHT / 2;
    
    // helps to span our food in the random (0 to 19: on x and y) location on the arena
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
    
    score = 0;
}

void visual() {
    system("clear");
    
    // creates top walls
    for (int i = 0; i < WIDTH+2; i++) { // +2 for remaining two # on the top wall of the arena
        cout << "#";
    }
    
    cout << endl;
    
    // creates side walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                cout << "#";
                
                if (i==y && j ==x)
                    cout << "🐍";
                else if (i == foodY && j == foodX) 
                    cout << "🐹";
                else
                    cout << " ";
                    
                    if (j == WIDTH-1)
                        cout << "#";
        }
        cout << endl;
    }
    
    // creates bottom walls
    for (int i = 0; i < WIDTH+2; i++) { // +2 for remaining two # on the bottom wall of the arena
        cout << "#";
    }
    
    cout << endl;
    cout << "Score: " << score << endl;
}

void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2x, prev2y;
    // firs snake ex: x[0] after the main, is going to follow the the direction of the main (x) snake
    tailX[0] = x; 
    tailY[0] = y; 
    
    for (int i = 1; i < nTail; i++) {
        // second member of snake flows first memeber, third -> second and so on
        prev2x = tailX[i];
        prev2y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2x;
        prevY = prev2y;
    }
    
     switch (dir) {
         case UP:
            y--; // helps to move the snake upwards
            break;
        case LEFT:
            x--; // helps to move the snake leftwards
            break;
        case DOWN:
            y++; // helps to move the snake downwards
            break;
        case RIGHT:
            x++; // helps to move the snake rightwards
            break;
        default:
            break;
     }
     
     // making the snake able to pass through wall and reappear from the reverse of that side
     if (x >= WIDTH) {
         x = 0;
     } else if (x < 0) {
         x = WIDTH - 1; // if snake hits left most coordinate, then it will transfer to last coordinate of the right side of the arena
     }
     
     if (y >= WIDTH) {
         y = 0;
     } else if (y < 0) {
         y = WIDTH - 1; // if snake hits up most coordinate, then it will transfer to last coordinate of the down side of the arena
     }
     
     //  if position of snake equals with the position of the food, then eat the food, increment score and spawn food to new random location
     if (x == foodX && y == foodY) {
         score++;
         foodX = rand() % WIDTH;
         foodY = rand() % HEIGHT;
     }
     
}

void input() {
    // adding w, a, s, d keys for the directions and t to terminate the game
    if (_kbhit()) {
        switch (_getch()) {
            case "w":
                dir = UP;
                break;
            case "a":
                dir = LEFT;
                break;
            case "s":
                dir = DOWN;
                break;
            case "d":
                dir = RIGHT;
                break;
            case "t":
                gameOver = true;
                break;
        }
    }
}

int main() {
    settings();
    
    while (!gameOver) {
        visual();
        input();
        logic();
        std::this_thread::sleep_for (std::chrono::seconds(50)); // you can reduce the seconds to increase difficulty like 20
    }
    
    return 0;
}
