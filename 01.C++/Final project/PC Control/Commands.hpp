#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include <iostream>
#include <fstream>

class Command {
public:
    private:
        std::string buffer;
        
    public:
    
        std::string openTerminal(const std::string& command);
        std::string youtube(const std::string& command);
        std::string openFolder(const std::string& folderName);
        std::string openBrowser(const std::string& query);
        void createFile(const std::string& fileName);
        void deleteFile(const std::string& fileName);
        void copyFile(const std::string& sourcePath, const std::string& destinationPath);
        std::string openVScode();
        std::string openCalculator();
        std::string shutdown();
        std::string Restart();
        std::string linkedin();
        std::string github();
};

#endif // COMMANDS_HPP