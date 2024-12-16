// tictactoeai.cpp : Defines the entry point for the application.
//

#include "tictactoeai.h"

using namespace std;

int main()
{
	std::array<int, 9> x{ 1,1,0,2,0,0,0,0,0 };
	x = AI::answer(x);
	for (size_t i = 0; i < 9; i++)
	{
		if(i==0) cout << " [";
		cout << x[i];
	
		if(i==2||i==5||i==8)cout << "]\n";
	}
	return 0;
}
