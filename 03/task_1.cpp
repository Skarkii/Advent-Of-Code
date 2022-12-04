#include <iostream>
#include <fstream>
#include <vector>


int main()
{
    std::string intersects;

    std::ifstream inpFile("input");

    std::string line;

    if(!inpFile.is_open()) { return 1; }

    while(getline (inpFile, line))
    {
        int len = line.length();
        std::string firstPart = line.substr(0, len / 2);
        std::string secoundPart = line.substr(len / 2, len);

        std::string tempStr;

        for (int i = 0; i < firstPart.length(); i++)
        {
            for (int j = 0; j < secoundPart.length(); j++)
            {
                if(firstPart[i] == secoundPart[j] && tempStr.find(firstPart[i]) == std::string::npos)
                {
                    tempStr += firstPart[i];
                }
            }
        }

        intersects += tempStr;
        tempStr = "";
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