#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0; 

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed =  average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {    
            int sepiaRed =  round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue); 
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);  
            int sepiaBlue =  round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue); 

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }    
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) // change middle for some reason?
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    for (int m = 0; m < height; m++)
    {
        for (int n = 0; n < width; n++)
        {
            int counter = 0;

            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;

            for (int i = -1; i < 2; i++)
            {  
                for (int j = -1; j < 2; j++)
                {
                    if (((m + i) > -1 && (m + i) < height) || ((n + j) > -1 && (n + j) < width))
                    {

                        sumRed = sumRed + image[m + i][n + j].rgbtRed;
                        sumGreen = sumGreen + image[m + i][n + j].rgbtGreen;
                        sumBlue = sumBlue + image[m + i][n + j].rgbtBlue;

                        counter++;
                    }
                }
            }

            image[m][n].rgbtRed  = round(sumRed / counter);
            image[m][n].rgbtGreen = round(sumGreen / counter);
            image[m][n].rgbtBlue = round(sumBlue / counter);

        }
    }


    return;
}
