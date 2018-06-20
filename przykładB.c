#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> //lseek

int main()
{
    int fd;
    off_t size;

    int m_read, m_written;
    char buf[12]="Ala ma kota!";

    fd=open("a.txt", O_CREAT | O_RDWR);

    if (fd==-1)
    {
        perror("blad");
        exit(1);
    }

    size =lseek(fd,5,SEEK_CUR); //aktualna pozycja w pliku

    if(size==-1)
    {
        perror("blad");
        exit(1);
    }

    m_written=write(fd,buf,sizeof(buf));

    if(m_written==-1)
    {
        perror("blad");
        exit(1);
    }

    close(fd);

    exit(0);
}
