#include "Commands.hpp"

std::string Command::openTerminal(const std::string& command)
{
    
    std::string fullCommand = "gnome-terminal -- bash -c \"echo 0118445090d | sudo -S " + command + "; exec bash\"";
    // Open a pipe to execute the full command
    FILE *fp = popen(fullCommand.c_str(), "r");
    if(!fp){
        // Error handling if the popen function fails
        return "failed to open terminal and run command";
    }
    // Close the pipe
    pclose(fp);
    return "terminal opened successfully";

}
std::string Command::openVScode()
{
    FILE *fp = popen("xdg-open https://www.linkedin.com/in/ismail-tarek-7291b8252/", "r");
    if(!fp)
        return "failed to open VScode";
    
    // Close the pipe
    pclose(fp);
    return "Visual Studio Code opened successfully";
}
std::string Command::openCalculator()
{
    FILE *fp = popen("xcalc", "r");
    if(!fp)
        return "failed to open VScode";
    
    // Close the pipe
    pclose(fp);
    return "calculator opened successfully";
}

void  Command::createFile(const std::string& fileName) {
    std::ofstream file(fileName);
    if (file.is_open()) {
        std::cout << "File created: " << fileName << std::endl;
        file.close();
    } else {
        std::cerr << "Failed to create file: " << fileName << std::endl;
    }
}

void Command::copyFile(const std::string& sourcePath, const std::string& destinationPath) {
    std::ifstream source(sourcePath, std::ios::binary);
    std::ofstream destination(destinationPath, std::ios::binary);

    if (source && destination) {
        destination << source.rdbuf();
        std::cout << "File copied from " << sourcePath << " to " << destinationPath << std::endl;
    } else {
        std::cerr << "Failed to copy file from " << sourcePath << " to " << destinationPath << std::endl;
    }

    source.close();
    destination.close();
}

void Command::deleteFile(const std::string& fileName) {
    if (std::remove(fileName.c_str()) == 0) {
        std::cout << "File deleted: " << fileName << std::endl;
    } else {
        std::cerr << "Failed to delete file: " << fileName << std::endl;
    }
}

std::string Command::openFolder(const std::string& folderName)
{
    const char *homeDir = getenv("HOME");
    std::string fullPath = std::string(homeDir) + "/" + folderName;
    std::string cmd = "thunar \"" + fullPath + "\"";
    FILE *fp = popen(cmd.c_str(), "r");
    if(!fp)
        return "failed to open folder";
    
    // Close the pipe
    pclose(fp);
    return cmd +"opened successfully";
}
std::string Command::shutdown()
{
    FILE *fp = popen("shutdown -h now", "r");
    if(!fp)
        return "failed to shutdown";
    
    // Close the pipe
    pclose(fp);
    return "bye";
}
std::string Command::Restart()
{
    FILE *fp = popen("reboot", "r");
    if(!fp)
        return "failed to reboot";
    
    // Close the pipe
    pclose(fp);
    return "rebooting";
}
std::string Command::openBrowser(const std::string& query) {
    // Construct the URL for the search query
    std::string searchUrl = "https://www.google.com/search?q=" + query;

    // Construct the command to open Brave with the search URL
    std::string command = "brave \"" + searchUrl + "\"";

    // Open Brave with the search URL
    FILE *fp = popen(command.c_str(), "r");
    if (!fp) {
        return "Failed to open Brave browser";
    }

    // Close the pipe
    pclose(fp);

    return "Brave browser opened successfully with search query: " + query;
}
std::string Command::youtube(const std::string& command)
{
    std::string CMD = "xdg-open https://www.youtube.com/results?search_query=" + command;
    FILE *fp = popen( CMD.c_str() , "r");
    if(!fp)
        return "failed to open youtube";
    
    // Close the pipe
    pclose(fp);
    return "youtube opened successfully for " + command;
}
std::string Command::linkedin()
{
    FILE *fp = popen("xdg-open https://www.linkedin.com/in/ismail-tarek-7291b8252/", "r");
    if(!fp)
        return "failed to open Github";
    
    // Close the pipe
    pclose(fp);
    return "linkedin opened successfully";
}
std::string Command::github()
{
    FILE *fp = popen("xdg-open https://github.com/ismailTareq", "r");
    if(!fp)
        return "failed to open Github";
    
    // Close the pipe
    pclose(fp);
    return "Github opened successfully";
}
