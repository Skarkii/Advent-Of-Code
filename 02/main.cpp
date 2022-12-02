#include <vector>
#include <iostream>
#include <fstream>


void loadFile(std::string filename, std::vector<char>& playerInputs, std::vector<char>& opponentInputs)
{
    std::ifstream inpFile(filename);

    std::string line;

    if(!inpFile.is_open()) { return; }

    while(getline (inpFile, line))
    {
        playerInputs.push_back(line[2]);
        opponentInputs.push_back(line[0]);
    }
}

int countScore(std::vector<char> playerInputs, std::vector<char> opponentInputs)
{
    int score = 0;
    for (int i = 0; i < playerInputs.size(); i++)
    {
        switch(playerInputs[i]) 
        {
            case 'X': //Rock [A]
                score += 1;
                break;
            case 'Y': //Paper [B]
                score += 2;
                break;
            case 'Z': //Scissors [C]
                score += 3;
                break;
        }

        if( (playerInputs[i] == 'X' && opponentInputs[i] == 'B')
         or (playerInputs[i] == 'Y' && opponentInputs[i] == 'C')
         or (playerInputs[i] == 'Z' && opponentInputs[i] == 'A')
        ) { 
            score += 0;
            continue;
        }
        
        if( (playerInputs[i] == 'X' && opponentInputs[i] == 'A')
         or (playerInputs[i] == 'Y' && opponentInputs[i] == 'B')
         or (playerInputs[i] == 'Z' && opponentInputs[i] == 'C')
        ) { 
            score += 3; 
            continue;
        }

        score += 6;
    }

    return score;
}

std::vector<char> newInputs(std::vector<char> firstCol, std::vector<char> secoundCol)
{
    std::vector<char> newInputs;

    for (int i = 0; i < secoundCol.size(); i++)
    {
        if(secoundCol[i] == 'X') //Lose
        { 
            if(firstCol[i] == 'A')
            {
                newInputs.push_back('Z');
            }
            else if(firstCol[i] == 'B')
            {
                newInputs.push_back('X');
            }
            else if(firstCol[i] == 'C')
            {
                newInputs.push_back('Y');
            }
        }  
        else if(secoundCol[i] == 'Y') //Draw
        {
            if(firstCol[i] == 'A')
            {
                newInputs.push_back('X');
            }
            else if(firstCol[i] == 'B')
            {
                newInputs.push_back('Y');
            }
            else if(firstCol[i] == 'C')
            {
                newInputs.push_back('Z');
            }
        } 
        else if(secoundCol[i] == 'Z') //Win
        { 
            if(firstCol[i] == 'A')
            {
                newInputs.push_back('Y');
            }
            else if(firstCol[i] == 'B')
            {
                newInputs.push_back('Z');
            }
            else if(firstCol[i] == 'C')
            {
                newInputs.push_back('X');
            }
        } 
    }

    return newInputs;
}

int main()
{
    std::vector<char> playerInputs;
    std::vector<char> opponentInputs;

    loadFile("input", playerInputs, opponentInputs);

    std::cout << "Part One - Result : " << countScore(playerInputs, opponentInputs) << std::endl;

    std::vector<char> newPlayerInputs = newInputs(opponentInputs, playerInputs);

    std::cout << "Part Two - Result : " << countScore(newPlayerInputs, opponentInputs) << std::endl;

    return 0;
}