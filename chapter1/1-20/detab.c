#include <stdio.h>
#include <stdint.h>

#define TABSTOP 4


int main(int argc, char** argv)
{
    char c;
    uint_fast32_t char_index = 0;

    while ( ( c = getchar() ) != EOF)
    {
        if ( c == '\t')    
        {
            uint_fast32_t spaces = TABSTOP - (char_index % TABSTOP);
            while (spaces--)
            {
                putchar(' ');
            }
        }
        else
        {
            putchar(c);
        }
    }
}
