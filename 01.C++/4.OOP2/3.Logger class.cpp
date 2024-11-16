#include <bits/stdc++.h>

enum class level_t
{
    WARN,
    INFO,
    ERROR,
    DEBUG
};

class LOG
{
private:
    std::vector<std::string>logbuffer;
    level_t level;
public:
    LOG()
    :level(level_t::INFO)
    {

    }

    void setlevel(level_t lev)
    {
        level = lev;
    }

    LOG& operator<<(const std::pair<std::string , level_t> &loginfo)
    {
        level_t lev = loginfo.second;
        const std::string message = loginfo.first;

        if((int)lev >= (int)level)
        {
            logbuffer.push_back(message);
        }
        return *this;
    }

    void dump()
    {
        for(const auto &mess : logbuffer)
            std::cout<<mess<<std::endl;
    }

    void Clear()
    {
        logbuffer.clear();
    }
};

int main()
{
    LOG logger;
    logger.setlevel(level_t::WARN);

    logger << std::make_pair("This is an info message",level_t::INFO); // Will not be logged
    logger << std::make_pair("Forget to close file",level_t::WARN );
    logger << std::make_pair( "Error occurred",level_t::ERROR);

    std::cout << "Dumping logs:" << std::endl;
    logger.dump();

    std::cout << "Clearing logs." << std::endl;
    logger.Clear();

    std::cout << "Dumping logs after clear:" << std::endl;
    logger.dump();
}
