#include "helpers.h"
#include <math.h>

#define RED_COLOR 0
#define GREEN_COLOR 1
#define BLUE_COLOR 2

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float r = 0;
    float g = 0;
    float b = 0;
    float avg = 0;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            r = image[h][w].rgbtRed;
            g = image[h][w].rgbtGreen;
            b = image[h][w].rgbtBlue;
            avg = (r+g+b)/3;
            avg = round(avg);
            if (avg > 256)
            {
                avg = 255;
            }
            image[h][w].rgbtRed = avg;
            image[h][w].rgbtGreen = avg;
            image[h][w].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            sepiaRed = .393 * image[h][w].rgbtRed + .769 * image[h][w].rgbtGreen + .189 * image[h][w].rgbtBlue;
            sepiaGreen = .349 * image[h][w].rgbtRed + .686 * image[h][w].rgbtGreen + .168 * image[h][w].rgbtBlue;
            sepiaBlue = .272 * image[h][w].rgbtRed + .534 * image[h][w].rgbtGreen + .131 * image[h][w].rgbtBlue;

            sepiaRed = round(sepiaRed);
            sepiaGreen = round(sepiaGreen);
            sepiaBlue = round(sepiaBlue);

            if (sepiaRed >= 256)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen >= 256)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue >= 256)
            {
                sepiaBlue = 255;
            }
            image[h][w].rgbtBlue = sepiaBlue;
            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
        }
    }




    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE bit;
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width / 2; column++)
        {

            bit = image[row][column];
            image[row][column] = image[row][width - column - 1];
            image[row][width - column - 1] = bit;
        }
    }
}

int get_blur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position)
{
    float count = 0;
    int sum = 0;

    for (int row = i - 1; row <= i + 1; row++)
    {
        for (int column = j - 1; column <= j + 1; column++)
        {
            if (row < 0 || row >= height || column < 0 || column >= width)
            {
                continue;
            }
            if (color_position == RED_COLOR)
            {
                sum += image[row][column].rgbtRed;
            }
            else if (color_position == GREEN_COLOR)
            {
                sum += image[row][column].rgbtGreen;
            }
            else
            {
                sum += image[row][column].rgbtBlue;
            }
            count++;
        }
    }
    return round(sum/count);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            copy[row][column] = image[row][column];
        }
    }
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            image[row][column].rgbtRed = get_blur(row, column, height, width, copy, RED_COLOR);
            image[row][column].rgbtGreen = get_blur(row, column, height, width, copy, GREEN_COLOR);
            image[row][column].rgbtBlue = get_blur(row, column, height, width, copy, BLUE_COLOR);
        }
    }
    return;
}
