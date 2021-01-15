#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Open memory card
    if(argv[1] !=0)
    {
    FILE *file = fopen(argv[1], "r");
    }
    else
    {
        return 1;
    }
    // Repeat until end of card:
        // Read 512 bytes into buffer
        // If start of new JPEG
            //If first JPEG
            
            // Else
            
        //Else
            // If already found JPEG
            
    // Close any remaining files
}
