#include <iostream>
using namespace std;

bool gameOver;

const int WIDTH = 36;
const int HEIGHT = 36;

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
    
    // helps to span our food in the random (0 to 35: on x and y) location on the arena
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
    
    score = 0;
    
}

void visual() {
    
}

void logic() {
     
}

void input() {
    
}

int main() {
    settings();
    
    while (!gameOver) {
        visual()
        input()
        logic()
    }
    
    return 0;
}
