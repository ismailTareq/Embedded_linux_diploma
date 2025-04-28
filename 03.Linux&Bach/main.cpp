#include "iostream"
#include "string"
#include "string.h"
#include "unistd.h"
#include <sys/types.h>

int main()
{
    const char *mesg = "ismail is awesome\n";
    ssize_t bytes_written = write(STDOUT_FILENO, mesg, strlen(mesg));
    if (bytes_written == -1)
    {
        std::cerr << "write() failed" << std::endl;
        return 1;
    }

    return 0;
}