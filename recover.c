#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FILEBLOCK 512
typedef uint8_t BYTE;




int main(int argc, char *argv[])
{

    if(argv[1] !=0)
    {
        //Declare buffer size
        BYTE buffer[FILEBLOCK];
        int recovered_img_count =0;
        char recovered_filename[8];
        
        FILE *analized_file = fopen(argv[1], "r");
        // Open memory card
        while(!feof(analized_file))
        {
        // Repeat until end of card:
            // Read 512 bytes into buffer
            FILE *img = NULL;
            size_t fread_byte;
            fread_byte = fread(buffer, sizeof(BYTE), FILEBLOCK, analized_file);

            // If start of new JPEG
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0 ) == 0xe0)
            {
               
            }
            //Else
                // If already found JPEG

        // Close any remaining filesDecakre 
        }

    }
    else
    {
        return 1;
    }
}
