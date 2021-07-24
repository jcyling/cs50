#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over image
    for (int i = 0; i < height; i++)
    {
        for (int j =0; j < width; j++)
        {
            //Average of RGB
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            float rgbAvg = (originalRed + originalGreen + originalBlue) / 3;
            int gvalue = round(rgbAvg);

            // Set RGB to same value
            image[i][j].rgbtRed = gvalue;
            image[i][j].rgbtGreen = gvalue;
            image[i][j].rgbtBlue = gvalue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    //Loop over image
    for (int i = 0; i < height; i++)
    {
        for (int j =0; j < width; j++)
        {
            //Convert RGB to separate sepia values
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // Set RGB to new value
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over image
    for (int i = 0; i < height; i++)
    {

        for (int j =0; j < width / 2; j++)
        {
            //Swap pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image

/*
- Create RGBTRIPLE copy of image
- Check for edge condition
    - if it exists (within the width and height of the image)
        - add the RGB of each pixel to a RGB total
        - add one to pixel counter
- find average values by dividing RGB totals by pixel counter
*/
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int x = 0; x < height; x++)
    {
        for (int y =0; y < width; y++)
        {
            copy[x][y] = image[x][y];
        }
    }

    // Loop over image and get RGB



    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rvalue = 0;
            int gvalue = 0;
            int bvalue = 0;
            int pixels = 0;

            //Loop for 9 pixels around it
            for (int row = i - 1; row < i + 2 && row < height; row++)
            {


                if (row < 0 || row > height)
                {
                    continue;
                }

                for (int col = i - 1; col < i + 2 && col < width; col++)
                {
                    if (col < 0 || col > width)
                    {
                        continue;
                    }

                    rvalue += copy[row][col].rgbtRed;
                    gvalue += copy[row][col].rgbtGreen;
                    bvalue += copy[row][col].rgbtBlue;

                    pixels+=1;
                }

            }

            image[i][j].rgbtRed = round((float)rvalue / pixels);
            image[i][j].rgbtGreen = round((float)gvalue / pixels);
            image[i][j].rgbtBlue = round((float)bvalue/ pixels);
        }

    }
return;

}
