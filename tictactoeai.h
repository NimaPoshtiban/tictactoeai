// tictactoeai.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.
#include <array>
#include<memory>
#include<vector>
extern class AI {
public:
	AI() = default;
	/// <summary>
	/// receives a array is the status of the game
	/// returns the best next move
	/// </summary>
	/// <rules>
	/// <rule> first player's allocated block is represented by 1 </rule>
	/// <rule> second player's allocated block is represented by 2 </rule>
	/// <rule> empty blocks are represented by 0 </rule>
	/// </rules>
	/// <param name="plate"></param>
	/// <returns></returns>
	static std::array<int, 9> answer(std::array<int, 9>& plate,std::uint8_t depth=1);	
private:

	// calculating the score of the next possible move
	static std::int8_t calculate_score(std::array<int, 9>& matrix);
	static std::array<int, 9> generate_matrix(const std::array<int, 9>& matrix, std::uint8_t insert_position);
	~AI() = default;
};