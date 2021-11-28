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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int GxRed, GxGreen, GxBlue; 
            int GyRed, GyGreen, GyBlue;

            GxRed = GxGreen = GxBlue =  GyRed = GyGreen = GyBlue = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {

                    if (i + k >= 0 || i + k < height || j + l >= 0 || j + l < width)
                    {
                        //Summarize positionin rows in 3x3
                        GxRed += Gx[k + 1][l + 1] * image[i + k][j + l].rgbtRed;
                        GxGreen += Gx[k + 1][l + 1] * image[i + k][j + l].rgbtGreen;
                        GxBlue += Gx[k + 1][l + 1] * image[i + k][j + l].rgbtBlue;

                        GyRed += Gy[k + 1][l + 1] * image[i + k][j + l].rgbtRed;
                        GyGreen += Gy[k + 1][l + 1] * image[i + k][j + l].rgbtGreen;
                        GyBlue += Gy[k + 1][l + 1] * image[i + k][j + l].rgbtBlue;       
                    }  
                            
                }
                
            }

            int red = round(sqrt(GxRed * GxRed + GyRed * GyRed));
            int green = round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen));
            int blue = round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue));


            if (red > 255)
            {
                red = 255;
            }
            else if (green > 255)
            {
                green = 255;
            }
            else if (blue > 255)
            {
                blue  = 255;
            }

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;  
        }
    }

    return;
}
