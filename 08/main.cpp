#include <iostream>
#include <fstream>
#include <vector>

void printVector(std::vector<std::vector<int>> inp)
{
    for (int i = 0; i < inp.size(); i++)
    {
        for (int j = 0; j < inp[i].size(); j++)
        {
            std::cout << inp[j][i];
        }
        std::cout << std::endl;
    }
}

int highestScenicScore(std::vector<std::vector<int>> inp)
{
    int highestScenicScore = 0;

    for (int i = 0; i < inp.size(); i++)
    {
        for (int j = 0; j < inp[i].size(); j++)
        {   //inp[j][i]
            
            if(i == 0 || i == inp.size() - 1 || j == 0 || j == inp[i].size() - 1) //Edge cases
            {
                continue;
            }

            int vdL = 0; 
            int vdR = 0; 
            int vdU = 0;
            int vdD = 0; 

            for (int k = j - 1; k >= 0; k--) //LEFT
            {
                vdL += 1;


                if(inp[j][i] <= inp[k][i])
                {
                    break;
                }
            }

            for (int k = j + 1; k < inp.size(); k++) //RIGHT
            {
                vdR += 1;


                if(inp[j][i] <= inp[k][i])
                {
                    break;
                }
            }


            for (int k = i + 1; k < inp.size(); k++) //DOWN
            {
                vdD += 1;

                if(inp[j][i] <= inp[j][k])
                {
                    break;
                }
            }

            for (int k = i - 1; k >= 0; k--) //DOWN
            {
                vdU += 1;

                if(inp[j][i] <= inp[j][k])
                {
                    break;
                }
            }


            int tot = vdD * vdU * vdL * vdR;

            if(tot > highestScenicScore)
            {
                highestScenicScore = tot;
            }
        }
    }
    return highestScenicScore;
}

int findVisible(std::vector<std::vector<int>> inp)
{
    int sum = 0;

    for (int i = 0; i < inp.size(); i++)
    {
        for (int j = 0; j < inp[i].size(); j++)
        {   //inp[j][i]
            if(i == 0 || i == inp.size() - 1 || j == 0 || j == inp[i].size() - 1) //Edge cases
            {
                sum += 1;
                continue;
            }
            bool visible = true;

            for (int k = j - 1; k >= 0; k--) //LEFT
            {
                if(inp[j][i] <= inp[k][i])
                {
                    visible = false;
                    break;
                }
            }

            if(visible) { sum+= 1; continue; } 

            visible = true;

            for (int k = j + 1; k < inp.size(); k++) //RIGHT
            {
                if(inp[j][i] <= inp[k][i])
                {
                    visible = false;
                    break;
                }
            }

            if(visible) { sum+= 1; continue; }

            visible = true;

            for (int k = i + 1; k < inp.size(); k++) //DOWN
            {
                if(inp[j][i] <= inp[j][k])
                {
                    visible = false;
                    break;
                }
            }

            if(visible) { sum+= 1; continue; }

            visible = true;

            for (int k = i - 1; k >= 0; k--) //DOWN
            {
                if(inp[j][i] <= inp[j][k])
                {
                    visible = false;
                    break;
                }
            }

            if(visible) { sum+= 1; continue; }
            
        }
    }
    return sum;
}

int main()
{
    std::vector<std::vector<int>> trees = {};

    std::fstream inputFile("input");
    std::string line;

    
    while(getline(inputFile, line))
    {
        if(trees.size() == 0) //Setup 5 columns
        {
            for (int i = 0; i < line.length(); i++)
            {
                trees.push_back({});
            }
        }

        for (int i = 0; i < line.length(); i++)
        {
            trees[i].push_back(stoi(line.substr(i, 1)));
        }
    }

    
    std::cout << "Part 1 : Visible Trees: " << findVisible(trees) << std::endl;
    std::cout << "Part 2 : Highest scenic score : " << highestScenicScore(trees) << std::endl;
    

    return 0;
}