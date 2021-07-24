#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    //Return error for wrong usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //Open image as img
    FILE *img = fopen(argv[1], "r");

    if (img == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    //Declare array buffer for storing
    BYTE buffer[512];
    int counter = 0;

    //Create new jpeg
    char filename[8];
    sprintf(filename, "%03i.jpg", counter);

    //Open new file
    FILE *jpg = fopen(filename, "w");

    //Read file
    while (fread(&buffer, sizeof(BYTE), 512, img))
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter == 0)
            {
                //Write to jpeg
                fwrite(&buffer, sizeof(BYTE), 512, jpg);

                counter++;

            }
            else if (counter != 0)
            {
                //Close the file
                fclose(jpg);

                //Create new jpeg
                sprintf(filename, "%03i.jpg", counter);

                //Open new file
                jpg = fopen(filename, "w");

                //Write to new jpeg file
                fwrite(&buffer, sizeof(BYTE), 512, jpg);

                counter++;
            }

        }
        else if (counter > 0)
        {
            fwrite(&buffer, sizeof(BYTE), 512, jpg);
        }

    }

    //Close remaining files
    fclose(jpg);
    fclose(img);

}