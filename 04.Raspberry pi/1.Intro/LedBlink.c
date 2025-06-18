#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#define PATH_EXPORT         "/sys/class/gpio/export"
#define PATH_DIRECTION      "/sys/class/gpio/gpio588/direction"
#define PATH_VALUE          "/sys/class/gpio/gpio588/value"
#define LED_PIN "588"
#define LED_DIRECTION "out"
void direction_init()
{
    int fd= open(PATH_DIRECTION, O_WRONLY);
    if( fd ==-1 )
    {
        printf("file  [Direction] cannot open ");
        return ;
    }

    write( fd, LED_DIRECTION, strlen(LED_DIRECTION));
    close(fd);
}

void export_init()
{
    int fd= open(PATH_EXPORT, O_WRONLY);
    if( fd ==-1 )
    {
        printf("file  [Export] cannot open ");
        return ;
    }
    write( fd, LED_PIN, strlen(LED_PIN));
    close(fd);
}

int main()
{
    export_init();
    sleep(2);
    direction_init();

    int fd= open(PATH_VALUE, O_WRONLY);
    if( fd ==-1 )
    {
        printf("file  [Export] cannot open ");
        return -1;
    }
    while(1)
    { 
        write( fd, "1", strlen("1"));
        sleep(1);
        write( fd, "0", strlen("0"));
        sleep(1);
            
    }
    close(fd);
    return 0;
}


