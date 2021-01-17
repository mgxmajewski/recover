#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Define 
#define FILEBLOCK 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argv[1] !=0)
    {
        //Declare buffer size - to one block of 512 bytes
        BYTE buffer[FILEBLOCK];
        
        // Declare counter of recovered files and char for their names
        int recovered_img_count =0;
        char recovered_filename[8];
        
        // Create boolean to keep track of first recovered jpg
        bool found_jpg = false;
        
        // Open memory card
        FILE *analized_file = fopen(argv[1], "r");
        
        FILE *img = NULL;
        
        // Repeat until end of card and read FILEBLOCK (512 bytes) into buffer
        while(fread(buffer, FILEBLOCK, 1, analized_file) == 1)
        {
            // If start of new JPEG
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0 ) == 0xe0)
            {
                // Close previous JPEG in case it's not first one 
                if (found_jpg)
                {
                    fclose(img);
                }
                
                // Create foamrated filename for recovered JPEG
                sprintf(recovered_filename, "%03i.jpg", recovered_img_count);
                
                // Opens img file to write into it
                img = fopen(recovered_filename, "w");
                recovered_img_count++;
                found_jpg = true;
            }
            
            // If already found JPEG
            if (found_jpg)
            {
                fwrite(buffer, FILEBLOCK, 1, img);
            }
        }
        // Close any remaining filesDeclare
        fclose(analized_file);
        fclose(img);
    }
    else
    {
        return 1;
    }
}
