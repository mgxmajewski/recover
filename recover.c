#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
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
        bool found_jpg = false;
        FILE *analized_file = fopen(argv[1], "r");
        FILE *img = NULL;
        
        // Open memory card
        size_t fread_byte;
        fread_byte = fread(&buffer, FILEBLOCK, 1, analized_file);

        // Repeat until end of card:
        while(fread_byte == 1)
        {
            // Read 512 bytes into buffer
            // If start of new JPEG
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0 ) == 0xe0)
            {
                
                if (found_jpg)
                {
                    fclose(img);
                }
                
                sprintf(recovered_filename, "%03i.jpg", recovered_img_count);
                img = fopen(recovered_filename, "w");
                recovered_img_count++;
                found_jpg = true;
        
            }
            
            // If already found JPEG
            if (found_jpg)
            {
                fwrite(&buffer, FILEBLOCK, 1, img);
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
