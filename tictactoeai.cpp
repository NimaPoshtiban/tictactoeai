#include "tictactoeai.h"

std::array<int, 9> AI::answer(std::array<int,9>& plate)
{
    // validation phase
    std::int8_t zeros{}, ones{}, twos{};
    std::vector<int> empty_blocks;
    for (size_t i = 0; i < 9;i++) {
        if (plate.at(i) < 0 || plate.at(i)>2) {
            return std::array<int,9>();
        }
        if (plate.at(i) == 0) {
            empty_blocks.push_back(i);
            zeros++;
        }
        if (plate.at(i) == 1) {
            ones++;
        }
        if (plate.at(i)== 2) {
            twos++;
        }
    }
    
    if (ones != twos + 1) {
        return std::array<int,9>();
    }
    // data is valid proceed
    std::array<int,9> prediction{};
    std::int8_t current_score = 10; //   some impossible score at first
    for (size_t i = 0; i < empty_blocks.size(); i++) {

        auto tmp_matrix = generate_matrix(plate, empty_blocks[i]);
        auto score = calculate_score(tmp_matrix);
        if (score < current_score) {
            current_score = score;
            prediction = tmp_matrix;
        }
    }
    
    return prediction;
}
// calculating the score of the next possible move
std::int8_t AI::calculate_score(std::array<int, 9>& matrix)
{
    std::int8_t score{};
    std::int8_t min_score{};
    std::int8_t max_score{};
    // [0..2]
    // --------- row 1 ------------
    if (matrix.at(0)==0)
    {
        if (matrix.at(1) ==0 ) {
            if (matrix.at(2) == 1) {
                min_score++;
            }
            if (matrix.at(2) == 2) {
                max_score++;
            }
        }
        else if(matrix.at(1)==1) {
            if (matrix.at(2) != 2) {
                min_score++;
            }
        }
        else if(matrix.at(1)==2){
            if (matrix.at(2) != 1) {
                max_score++;
            }
        }
    }
    else if (matrix.at(0) == 1) {
        if (matrix.at(1) != 2 && matrix.at(2)!=2)
        {
            min_score++;
        }
    }
    else {
        if (matrix.at(1) != 1 && matrix.at(2) != 1)
        {
            max_score++;
        }
    }
    
    // ================= row 2=================
    if (matrix.at(3) == 0)
    {
        if (matrix.at(4) == 0) {
            if (matrix.at(5) == 1) {
                min_score++;
            }
            if (matrix.at(5) == 2) {
                max_score++;
            }
        }
        else if (matrix.at(4) == 1) {
            if (matrix.at(5) != 2) {
                min_score++;
            }
        }
        else if (matrix.at(4) == 2) {
            if (matrix.at(5) != 1) {
                max_score++;
            }
        }
    }
    else if (matrix.at(3) == 1) {
        if (matrix.at(4) != 2 && matrix.at(5) != 2)
        {
            min_score++;
        }
    }
    else {
        if (matrix.at(4) != 1 && matrix.at(5) != 1)
        {
            max_score++;
        }
    }
    // ============================== row 3 ====================================
    if (matrix.at(6) == 0)
    {
        if (matrix.at(7) == 0) {
            if (matrix.at(8) == 1) {
                min_score++;
            }
            if (matrix.at(8) == 2) {
                max_score++;
            }
        }
        else if (matrix.at(7) == 1) {
            if (matrix.at(8) != 2) {
                min_score++;
            }
        }
        else if (matrix.at(7) == 2) {
            if (matrix.at(8) != 1) {
                max_score++;
            }
        }
    }
    else if (matrix.at(6) == 1) {
        if (matrix.at(7) != 2 && matrix.at(8) != 2)
        {
            min_score++;
        }
    }
    else {
        if (matrix.at(7) != 1 && matrix.at(8) != 1)
        {
            max_score++;
        }
    }
    // ======================= col 1 =============================
    if (matrix.at(0) == 0)
    {
        if (matrix.at(3) == 0) {
            if (matrix.at(6) == 1) {
                min_score++;
            }
            if (matrix.at(6) == 2) {
                max_score++;
            }
        }
        else if (matrix.at(3) == 1) {
            if (matrix.at(6) != 2) {
                min_score++;
            }
        }
        else if (matrix.at(3) == 2) {
            if (matrix.at(6) != 1) {
                max_score++;
            }
        }
    }
    else if (matrix.at(0) == 1) {
        if (matrix.at(3) != 2 && matrix.at(6) != 2)
        {
            min_score++;
        }
    }
    else {
        if (matrix.at(3) != 1 && matrix.at(6) != 1)
        {
            max_score++;
        }
    }
    // ============================ col 2 =========================
    if (matrix.at(1) == 0)
    {
        if (matrix.at(4) == 0) {
            if (matrix.at(7) == 1) {
                min_score++;
            }
            if (matrix.at(7) == 2) {
                max_score++;
            }
        }
        else if (matrix.at(4) == 1) {
            if (matrix.at(7) != 2) {
                min_score++;
            }
        }
        else if (matrix.at(4) == 2) {
            if (matrix.at(7) != 1) {
                max_score++;
            }
        }
    }
    else if (matrix.at(1) == 1) {
        if (matrix.at(4) != 2 && matrix.at(7) != 2)
        {
            min_score++;
        }
    }
    else {
        if (matrix.at(4) != 1 && matrix.at(7) != 1)
        {
            max_score++;
        }
    }
    // ======================== col 3 ===========================
    if (matrix.at(2) == 0)
    {
        if (matrix.at(5) == 0) {
            if (matrix.at(8) == 1) {
                min_score++;
            }
            if (matrix.at(8) == 2) {
                max_score++;
            }
        }
        else if (matrix.at(5) == 1) {
            if (matrix.at(8) != 2) {
                min_score++;
            }
        }
        else if (matrix.at(5) == 2) {
            if (matrix.at(8) != 1) {
                max_score++;
            }
        }
    }
    else if (matrix.at(2) == 1) {
        if (matrix.at(5) != 2 && matrix.at(8) != 2)
        {
            min_score++;
        }
    }
    else {
        if (matrix.at(5) != 1 && matrix.at(8) != 1)
        {
            max_score++;
        }
    }
    // ================================== diameter top left to bottom right =================
    if (matrix.at(0) == 0)
    {
        if (matrix.at(4) == 0) {
            if (matrix.at(8) == 1) {
                min_score++;
            }
            if (matrix.at(8) == 2) {
                max_score++;
            }
        }
        else if (matrix.at(4) == 1) {
            if (matrix.at(8) != 2) {
                min_score++;
            }
        }
        else if (matrix.at(4) == 2) {
            if (matrix.at(8) != 1) {
                max_score++;
            }
        }
    }
    else if (matrix.at(0) == 1) {
        if (matrix.at(4) != 2 && matrix.at(8) != 2)
        {
            min_score++;
        }
    }
    else {
        if (matrix.at(4) != 1 && matrix.at(8) != 1)
        {
            max_score++;
        }
    }
    // ==================================== diameter top right to left bottom ================
    if (matrix.at(2) == 0)
    {
        if (matrix.at(4) == 0) {
            if (matrix.at(6) == 1) {
                min_score++;
            }
            if (matrix.at(6) == 2) {
                max_score++;
            }
        }
        else if (matrix.at(4) == 1) {
            if (matrix.at(6) != 2) {
                min_score++;
            }
        }
        else if (matrix.at(4) == 2) {
            if (matrix.at(6) != 1) {
                max_score++;
            }
        }
    }
    else if (matrix.at(2) == 1) {
        if (matrix.at(4) != 2 && matrix.at(6) != 2)
        {
            min_score++;
        }
    }
    else {
        if (matrix.at(4) != 1 && matrix.at(6) != 1)
        {
            max_score++;
        }
    }
    // ================= calculation ends here======================
    return min_score - max_score;
}

std::array<int, 9> AI::generate_matrix(const std::array<int, 9>& matrix, std::uint8_t insert_position)
{
    std::array<int, 9> m = matrix;
    m[insert_position] = 2;
    return m;
}
