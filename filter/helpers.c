#include "helpers.h"
#include <cs50.h>
#include <stdio.h>
#include <math.h>

void swap(RGBTRIPLE *a, RGBTRIPLE *b);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int w = 0; w < width; w++)
        {

            float avg = ((image[i][w].rgbtRed + image[i][w].rgbtGreen + image[i][w].rgbtBlue) / 3.0);

            image[i][w].rgbtRed = round(avg);
            image[i][w].rgbtGreen = round(avg);
            image[i][w].rgbtBlue = round(avg);
        }
    }
    
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterating over the image via columns and rows
    for (int i = 0; i < height; i++)
    {
        for (int w = 0; w < width; w++)
        {
            
            // Algorithms for Sepia
            float sepiaRed = (.393 * image[i][w].rgbtRed + .769 * image[i][w].rgbtGreen + .189 * image[i][w].rgbtBlue);
            float sepiaGreen = (.349 * image[i][w].rgbtRed + .686 * image[i][w].rgbtGreen + .168 * image[i][w].rgbtBlue);
            float sepiaBlue = (.272 * image[i][w].rgbtRed + .534 * image[i][w].rgbtGreen + .131 * image[i][w].rgbtBlue);

            // If any of the values exceed 255 then set it to 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Rounding the float values to an int and setting them to their respective RGB places
            image[i][w].rgbtRed = round(sepiaRed);
            image[i][w].rgbtGreen = round(sepiaGreen);
            image[i][w].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    int width_swap = round(width / 2);
    for (int i = 0; i < height; i++)
    {
        int c = 1;
        for (int j = 0; j < width_swap; j++)
        {
            swap(&image[i][j], &image[i][width - c]);
            c++;
        }
    }
    return;

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempArray[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int w = 0; w < width; w++)
        {
            float blurBlue = 0.0, blurGreen = 0.0, blurRed = 0.0;
            blurBlue = image[i][w].rgbtBlue;
            blurRed = image[i][w].rgbtRed;
            blurGreen = image[i][w].rgbtGreen;
            
            int divide = 1;
            
            if (i > 0)
            {
                //Above
                blurRed += image[i - 1][w].rgbtRed;
                blurGreen += image[i - 1][w].rgbtGreen;
                blurBlue += image[i - 1][w].rgbtBlue;

                divide++;
            }

            if (i > 0 && w < (width - 1))
            {
                //Top Right
                blurRed += image[i - 1][w + 1].rgbtRed;
                blurGreen += image[i - 1][w + 1].rgbtGreen;
                blurBlue += image[i - 1][w + 1].rgbtBlue;

                divide++;

            }

            if (i > 0 && w > 0)
            {
                //Top Left
                blurRed += image[i - 1][w - 1].rgbtRed;
                blurGreen += image[i - 1][w - 1].rgbtGreen;
                blurBlue += image[i - 1][w - 1].rgbtBlue;

                divide++;

            }

            if (w < (width - 1))
            {
                //Right
                blurRed += image[i][w + 1].rgbtRed;
                blurGreen += image[i][w + 1].rgbtGreen;
                blurBlue += image[i][w + 1].rgbtBlue;

                divide++;

            }

            if (w > 0)
            {
                //Left
                blurRed += image[i][w - 1].rgbtRed;
                blurGreen += image[i][w - 1].rgbtGreen;
                blurBlue += image[i][w - 1].rgbtBlue;

                divide++;

            }

            if (i < (height - 1))
            {
                //Below
                blurRed += image[i + 1][w].rgbtRed;
                blurGreen += image[i + 1][w].rgbtGreen;
                blurBlue += image[i + 1][w].rgbtBlue;

                divide++;

            }

            if (i < (height - 1) && w < (width - 1))
            {
                //Bottom Right
                blurRed += image[i + 1][w + 1].rgbtRed;
                blurGreen += image[i + 1][w + 1].rgbtGreen;
                blurBlue += image[i + 1][w + 1].rgbtBlue;

                divide++;

            }

            if (i < (height - 1) && (w < (width) && w > 0))
            {
                //Bottom Left
                blurRed += image[i + 1][w - 1].rgbtRed;
                blurGreen += image[i + 1][w - 1].rgbtGreen;
                blurBlue += image[i + 1][w - 1].rgbtBlue;


                divide++;
            }
            
            blurRed /= divide;
            blurGreen /= divide;
            blurBlue /= divide;
            
            // If any of the numbers are above 255 they are maximized to 255
            if (blurRed > 255)
            {
                blurRed = 255;
            }
            
            if (blurBlue > 255)
            {
                blurBlue = 255;
            }
            
            if (blurGreen > 255)
            {
                blurGreen = 255;
            }
            
            tempArray[i][w].rgbtRed = round(blurRed);
            tempArray[i][w].rgbtBlue = round(blurBlue);
            tempArray[i][w].rgbtGreen = round(blurGreen);
            
        }
        
        
    }
    
    // Copying the values from the temporary array into the actual picture
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tempArray[i][j].rgbtRed;
            image[i][j].rgbtGreen = tempArray[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tempArray[i][j].rgbtBlue;
        }
    }
        
    return;
}

// Swap function for reflecting pixels
void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    // Setting temporary variables for swapping as learnt in class
    RGBTRIPLE temp;
    RGBTRIPLE temp2;
    temp = *a;
    temp2 = *b;
    *a = temp2;
    *b = temp;
}