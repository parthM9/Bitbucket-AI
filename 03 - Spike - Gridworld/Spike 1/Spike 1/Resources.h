#pragma once
using namespace std;

enum Move { North, South, East, West, Quit };
enum GameState { Valid, Win, Loss };

struct Position {
	int fXPos;
	int fYPos;
};