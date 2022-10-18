#include <stdio.h>
#include <stdint.h>

/*
 honestly ive never got this to work, and i dont intend to continue it
 */

#define TABSTOP_INTERVAL 4
int main(int argc, char** argv)
{
    char c;
    uint_fast32_t char_index = 0;

    while ( ( c = getchar() ) != EOF)
    {
        if (c == ' ')
        {
            uint_fast32_t num_of_spaces;
            uint_fast8_t distace_from_tabstop = char_index % TABSTOP_INTERVAL;
            for(num_of_spaces = 1; ( c = getc(stdin) ) == ' '; num_of_spaces++)
            {
                char_index++;
            }
            
            if ( num_of_spaces < distace_from_tabstop ) 
            {
                while (num_of_spaces--)
                {
                    putchar(' ');
                }
            }
            else
            {
                putchar('\t');
                num_of_spaces -= distace_from_tabstop;

                while ( num_of_spaces >= TABSTOP_INTERVAL)
                {
                    putchar('\t');
                    num_of_spaces -= TABSTOP_INTERVAL;
                }
                while (num_of_spaces--)
                {
                    putchar(' ');
                }
            }
        }
        putchar(c);
        char_index++;
    }
    
    return 0;
}
