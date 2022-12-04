#include <iostream>
#include <fstream>
#include <vector>


int main()
{
    std::string intersects;

    std::ifstream inpFile("input");

    std::string line;

    if(!inpFile.is_open()) { return 1; }

    std::vector<std::string> lines;

    while(getline (inpFile, line))
    {
        lines.push_back(line);

        if(lines.size() == 3)
        {
            std::string tempStr;

            for (int i = 0; i < lines[0].length(); i++)
            {
                for (int j = 0; j < lines[1].length(); j++)
                {
                    for (int k = 0; k < lines[2].length(); k++)
                    {
                        if(lines[0][i] == lines[1][j] 
                        && lines[1][j] == lines[2][k] 
                        && tempStr.find(lines[0][i]) == std::string::npos)
                        {
                            tempStr += lines[0][i];
                        }
                    }
                
                }
            }

            intersects += tempStr;
            tempStr = "";
            lines.clear();
        }
    }

    int sum = 0;

    for (int i = 0; i < intersects.length(); i++)
    {
        if((int)intersects[i] >= 97 && (int)intersects[i] <= 122) //Lowercase
        {
            sum += intersects[i] - int('a') + 1;
        }
        else if((int)intersects[i] >= 65 && (int)intersects[i] <= 90) //uppercase
        {
            sum += intersects[i] - int('A') + 27;
        }
    }
    

    std::cout << "Result task 1 : " << sum << std::endl;
    
    
    
    return 0;
}