#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int main()
{
    int fd = open("file8", O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        return 1;
    }
    char buf[200];
    unsigned int read_byte = read(fd, buf, sizeof(buf));
    if(read_byte == -1)
    {
        perror("read");
        return 1;
    }
    buf[read_byte] = '\0';

    printf("read %d bytes:\n %s",read_byte,buf);
    close(fd);
    return 0;

}