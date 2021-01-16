#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FILEBLOCK 512
typedef uint8_t BYTE;




int main(int argc, char *argv[])
{
    // Open memory card
    if(argv[1] !=0)
    {
    FILE *file = fopen(argv[1], "r");
    

    
    // Repeat until end of card:
    while(!feof(file))
    {
        continue;
    }
        // Read 512 bytes into buffer
        // If start of new JPEG
            //If first JPEG
            
            // Else
            
        //Else
            // If already found JPEG
            
    // Close any remaining files
    }
    else
    {
        return 1;
    }
}
