/* 
    Exercise 1.23
    
    Write a program to remove all comments from a C program. Don't forget to
    handle quoted strings and character constants properly. C comments don't nest.
*/

/* hi */

#include <stdio.h>
#include <stdlib.h> /* hi 
hello
*/
#include <stdint.h>

// the max amount of characters read in a line
#define BUFFERSIZE 8192
#define STRINGBITMASK 0b01 // a mask to toggle the bit that tells us whether the slash is in a string or not
#define CSTYLEBITMASK 0b10 /* a mask to toggle the bit that tells us that the comment is in c-style */

// probably not needed
typedef struct {
    char string[8192];
    uint16_t length;
} Line;

Line getLine()
{
    char c;
    Line line = { {0}, 0}; // initialize the struct with an empty string
    
    for ( line.length = 0; line.length < BUFFERSIZE && ( c = getchar() ) != EOF && c != '\n'; (line.length)++) 
    {
        line.string[line.length] = c; // increments the length member and set the char at the index to the read character
    }
    if ( c == '\n')
    {
        line.string[(line.length)++] = c; // if the last character read was a new line, add it to the string
    }
    line.string[line.length] = 0;
    return line;
}

int main (int argc, char *argv[])
{
    Line line = getLine();
    int16_t i;
    uint8_t helper = 0; // the lowest bit in this variable checks whether we are in a string literal and the second lowest bit checks if we are dealing with a multi line comment
    char c;
    while(line.length > 0)
    {
        helper = 0;
        for (i = 0; i < line.length && (c = line.string[i]) != 0; i++)
        {
            if ( c == '\'' || c == '\"')
            {
                //if the backslash 
                if (line.string[i-1] == '\\') { continue; } 
                helper ^= STRINGBITMASK;
                continue;
            }
            if (c == '/')
            {
                if (!(helper & (STRINGBITMASK)))
                {
                    if (line.string[i+1] == '*')
                    {
                        helper ^= CSTYLEBITMASK; 
                        break;
                    }
                    line.string[i] = '\n';
                    line.string[i+1] = 0;
                    break;
                }
            }
        }
        
        if (helper & CSTYLEBITMASK)
        {
            for (int j = i+2; j < BUFFERSIZE && line.string[j] != 0; j++)
            {
                if (line.string[j] == '*' && line.string[j+1] == '/')
                {
                    helper ^= CSTYLEBITMASK;
                    line.string[i] = '\n';
                    line.string[i+1] = 0;
                }
            }
            while (helper & CSTYLEBITMASK)
            {
                line = getLine();
                for (i = 0; i < BUFFERSIZE && line.string[i] != 0; i++)
                {
                    if (line.string[i] == '*' && line.string[i+1] == '/')
                    {
                        helper ^= CSTYLEBITMASK;
                        line.string[0] = '\n';
                        line.string[1] = 0;
                        break;
                    }
                }
            }
        }
        
        fputs(line.string,stdout);
        line = getLine();
        helper = 0;
        
    }
    
    return 0;
}
