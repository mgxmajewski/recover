#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FILEBLOCK 512
typedef uint8_t BYTE;




int main(int argc, char *argv[])
{
    
    if(argv[1] !=0)
    {
        FILE *file = fopen(argv[1], "r");
        BYTE buffer[FILEBLOCK];
        // Open memory card
        size_t fread_byte;
        
        while(!feof(file))
        {
        // Repeat until end of card:
            // Read 512 bytes into buffer
            fread_byte = fread(buffer, sizeof(BYTE), FILEBLOCK, file);
          
            // If start of new JPEG
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0 ) == 0xe0)
            {
                //If first JPEG
                fwrite(buffer, sizeof(BYTE), fread_byte, file);
                // Else
                continue;
            }
                //If first JPEG
                
                // Else
                
            //Else
                // If already found JPEG
                
        // Close any remaining files
            continue;
        }
            
    }
    else
    {
        return 1;
    }
}
