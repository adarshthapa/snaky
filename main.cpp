#include <iostream>
#include <cstdlib>
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
}

void logic() {
     
}

void input() {
    
}

int main() {
    settings();
    
    while (!gameOver) {
        visual();
        input();
        logic();
    }
    
    return 0;
}
