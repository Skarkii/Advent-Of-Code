#include <iostream>
#include <fstream>
#include <vector>

class File
{
    public:
        std::string name;
        int size;
        File(std::string name, int size)
        {
            File::name = name;
            File::size = size;
        }
};

class BTree
{
    private:

    public:
        BTree* parent;
        std::vector<File> files;
        std::vector<BTree*> dir;
        std::string name;
        BTree(std::string name, BTree* parent)
        {
            BTree::parent = parent;
            BTree::name = name;
            BTree::files = {};
            BTree::dir = {};
        }
        void AddFile(std::string name, int size)
        {
            BTree::files.push_back(File(name, size));
        }
        void printAllFiles()
        {
            std::cout << BTree::name << std::endl;
            for (int i = 0; i < BTree::files.size(); i++)
            {
                std::cout << "\t" << BTree::files[i].name << " - " << BTree::files[i].size << std::endl;
            }
            
            for(int i = 0; i < BTree::dir.size(); i++)
            {
                std::cout << "\t" << BTree::dir[i]->name << " - dir" << std::endl;
            }
        }
        int GetFileSize()
        {
            int size = 0;
            for (int i = 0; i < BTree::files.size(); i++)
            {
                size += BTree::files[i].size;
            }
            return size;
        }

        int GetTotalSize(int &underCap, int &underCapValue)
        {
            int size = 0;
            size += GetFileSize();
            
            for (int i = 0; i < BTree::dir.size(); i++)
            {
                size += BTree::dir[i]->GetTotalSize(underCap, underCapValue);
            }

            if(size < 100000) 
            { 
                underCap += 1 ; 
                underCapValue += size;
            }
            return size;
        }

        int FindPartToRemove(int sizeNeeded, int &removeSize)
        {
            int size = 0;
            size += GetFileSize();
            
            for (int i = 0; i < BTree::dir.size(); i++)
            {
                size += BTree::dir[i]->FindPartToRemove(sizeNeeded, removeSize);
            }
            //std::cout << BTree::name << " - " << size << std::endl;

            if(size > sizeNeeded && size < removeSize)
            {
                removeSize = size;
            }

            return size;

        }
};

int main()
{
    BTree root = BTree("/", nullptr);
    BTree* cur = &root;

    std::fstream inputFile("input");
    std::string line;
    
    int lineNum = 0;

    while(getline(inputFile, line))
    {
        lineNum += 1;
        if(lineNum == 1 || line.substr(0, 4) == "$ ls") { continue; }

        if(line.substr(0, 4) == "$ cd")
        {
            std::string newDir = line.substr(5);
            if(newDir == ".." && cur->parent != nullptr)
            {
                cur = cur->parent;
            }
            else
            {
                for (int i = 0; i < cur->dir.size(); i++)
                {
                    if(cur->dir[i]->name == newDir)
                    {
                        cur = cur->dir[i];
                        continue;
                    }
                }
                
            }
            continue;
        }

        if(line.substr(0, 3) == "dir")
        {
            
            std::string newDir = line.substr(4);

            BTree* newBTree = new BTree(newDir, cur);

            cur->dir.push_back(newBTree);

            continue;
        }

        std::string fileName = line.substr(line.find(' ') + 1, line.length() - line.find(' '));
        int fileSize = stoi(line.substr(0, line.find(' ')));

        cur->AddFile(fileName, fileSize);
    }
    
    int underCap = 0;
    int underCapValue = 0;
    int sizeNeeded = 30000000 - (70000000 - root.GetTotalSize(underCap, underCapValue));

    int removeSize = 999999999;
    root.FindPartToRemove(sizeNeeded, removeSize);


    std::cout << "Task 1:" << std::endl;
    std::cout << "Occasions under 100k: " << underCap 
              << std::endl << "Value : " << underCapValue << std::endl;
    std::cout << "Task 2:" << std::endl;
    std::cout << "We need to remove the partition with the size : " << removeSize << std::endl; 

              
    return 0;
}