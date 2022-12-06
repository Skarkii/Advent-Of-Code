#include <iostream>
#include <fstream>

bool containsDublicates(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if(str[i] == str[j])
                return true;
        }
    }
    
    return false;

}

int main()
{
    //                  4 = part 1, 
    //                  14 = part 2
    int messageLength = 14; 

    std::fstream inputFile("input");

    if(!inputFile.is_open()) { return 1; }

    std::string line;
    getline(inputFile, line);
    
    int charsProcessed = 0;

    for (int i = messageLength; i < line.length(); i++)
    {
        std::string part = line.substr(i - messageLength, messageLength);
        if(!containsDublicates(part))
        {
            std::cout << "Characters processed : " << i << std::endl;
            break;
        }
    }
    

    return 0;
}