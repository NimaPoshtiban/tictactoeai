// tictactoeai.cpp : Defines the entry point for the application.
//

#include "tictactoeai.h"

__declspec(dllexport)std::array<int, 9> Answer(std::array<int, 9> plate) {
	return AI::answer(plate);
}
