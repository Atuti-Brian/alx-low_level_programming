#include <stdio.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters);

int main(int ac, char **av)
{
    ssize_t n;

    if (ac != 2)
    {
        /* Use printf for printing messages */
        fprintf(stderr, "Usage: %s filename\n", av[0]);
        exit(1);
    }

    n = read_textfile(av[1], 114);
    printf("\n(printed chars: %li)\n", n);
    n = read_textfile(av[1], 1024);
    printf("\n(printed chars: %li)\n", n);

    return 0; /* Add a return statement to indicate successful completion */
}

