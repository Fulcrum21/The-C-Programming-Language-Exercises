/*
                                Exercise 1.22

    Write a program to ``fold'' long input lines into two or more shorter lines
   after the last non-blank character that occurs before the n-th column of
   input. Make sure your program does something intelligent with very long
   lines, and if there are no blanks or tabs before the specified column.
*/

#include <stdio.h>
#include <stdint.h>

#define MAXCOLUMN 80


int main() 
{
    int8_t c;
    uint8_t i,num_blanks;
    uint8_t blanks[MAXCOLUMN] = {0};
    
    while (1)
    {
        num_blanks = 0;
        for (i = 0; i < MAXCOLUMN; i++)
        {
            c = getchar();
            if ( c != EOF)
            {
                if ( c == ' ' || c == '\t') 
                {
                    blanks[num_blanks++] = c;    
                    continue;
                }
                if ( c == '\n')
                {
                    putchar(c);
                    break;
                }
                while (num_blanks) 
                {
                    putchar(blanks[--num_blanks]);
                }
                putchar(c);
                continue;
            }
            goto finish;
        }
        if (c != '\n')
        {
            putchar('\n');
        }
    }
    finish:
    return 0;
}
