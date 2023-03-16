#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

void compress(char *line)
{
    int len = strlen(line);

    int i = 0;
    while (i < len)
    {
        int count = 1;
        while (i + count < len && line[i] == line[i + count])
        {
            count++;
        }

        if (count >= 3)
        {
            printf("%c%c%c%d*", line[i], line[i], line[i], count);
            i += count;
        }
        else
        {
            printf("%c", line[i]);
            i++;
        }
    }
}

void expand(char *line)
{
    int len = strlen(line);
    int i = 0;
    while (i < len)
    {
        if (i + 3 < len && (line[i] == line[i + 1] && line[i] == line[i + 2]) && isdigit(line[i + 3]))
        {
            int count = line[i + 3] - '0';
            if (isdigit(line[i + 4]))
            {
                count = count * 10 + (line[i + 4] - '0');
                i++;
            }
            for (int j = 0; j < count; j++)
            {
                printf("%c", line[i]);
            }
            i += 5;
        }
        else
        {
            printf("%c", line[i]);
            i++;
        }
    }
}

int main()
{
    char command[MAX_LINE_LENGTH];
    while (fgets(command, MAX_LINE_LENGTH, stdin))
    {
        if (command[0] == 'C')
        {
            char line[MAX_LINE_LENGTH];
            while (fgets(line, MAX_LINE_LENGTH, stdin))
            {
                compress(line);
            }
        }
        else if (command[0] == 'E')
        {
            char line[MAX_LINE_LENGTH];
            while (fgets(line, MAX_LINE_LENGTH, stdin))
            {
                expand(line);
            }
        }
    }
    return 0;
}
