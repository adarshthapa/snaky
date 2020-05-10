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
    cout << "Score" << score << endl;
}

void logic() {
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
        std::this_thread::sleep_for (std::chrono::seconds(10));
    }
    
    return 0;
}
