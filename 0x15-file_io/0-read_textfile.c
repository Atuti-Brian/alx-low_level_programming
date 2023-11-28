#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>  /* Add this line for malloc and free */
#include <fcntl.h>   /* Add this line for open */
#include <stdio.h>   /* Add this line for perror */

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. If it fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t nrd, nwr;
    char *buf;

    if (!filename)
        return (0);

    fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("Error opening the file");
        return (0);
    }

    buf = malloc(sizeof(char) * letters);
    if (!buf) {
        perror("Error allocating memory");
        close(fd);
        return (0);
    }

    nrd = read(fd, buf, letters);
    if (nrd == -1) {
        perror("Error reading from file");
        close(fd);
        free(buf);
        return (0);
    }

    nwr = write(STDOUT_FILENO, buf, nrd);
    if (nwr == -1) {
        perror("Error writing to stdout");
        close(fd);
        free(buf);
        return (0);
    }

    close(fd);
    free(buf);

    return (nwr);
}

