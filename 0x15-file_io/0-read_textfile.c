#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters)
{
    int txt_file, total, read_status;
    char buffer[BUFSIZ];

    if (filename == NULL)
        return (0);

    txt_file = open(filename, O_RDONLY);
    if (txt_file == -1)
        return (0);

    total = 0;
    read_status = 1;

    while (letters > BUFSIZ && read_status != 0)
    {
        read_status = read(txt_file, buffer, BUFSIZ);
        write(STDOUT_FILENO, buffer, read_status);
        total += read_status;
        letters -= BUFSIZ;
    }

    read_status = read(txt_file, buffer, letters);
    write(STDOUT_FILENO, buffer, read_status);
    total += read_status;

    close(txt_file);
    return total;
}

