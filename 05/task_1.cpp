#include <iostream>
#include <fstream>
#include <vector>

bool swap(std::vector<char>& from, std::vector<char>& to, int count)
{
    for (int i = 0; i < count; i++)
    {
        to.push_back(from.back());
        from.pop_back();
    }
    return true;
}

int main()
{
    std::vector<std::vector<char>> arr;

    for (int i = 0; i < 9; i++) { arr.push_back({}); }

    std::fstream inpFile("input");
    std::string line;

    if(!inpFile.is_open()) { return 1; }

    int lineNum = 0;

    while(getline(inpFile, line))
    {
        lineNum++;

        if(lineNum < 9) // Fill vectors
        { 
            for (int i = 1; i < line.length(); i+=4)
            {
                if(line[i] != ' ')
                {
                    arr[(i - 1) / 4].insert(arr[(i - 1) / 4].begin(), line[i]);
                }
            }
        }
        else if(lineNum > 10) //Moves
        {
            int count = stoi(line.substr(line.find("move") + 5, 2));
            int fromIndex = stoi(line.substr(line.find("from") + 5, 2));
            int toIndex = stoi(line.substr(line.find("to") + 3, line.length()));
            //std::cout << "count : " << count << std::endl << "fromIndex : " << fromIndex << std::endl << "toIndex : " << toIndex << std::endl;
            swap(arr[fromIndex - 1], arr[toIndex - 1], count);
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i].back();
    }

    std::cout << std::endl;
    
    
    

    return 0;
}