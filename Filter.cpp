#include <iostream>
#include "bmplib.cpp"

using namespace std;

void loadImage(unsigned char image[SIZE][SIZE]);
void saveImage(unsigned char image[SIZE][SIZE]);
void whiteAndBlack(unsigned char image[SIZE][SIZE]);
void colorinversion(unsigned char image[SIZE][SIZE]);
void mergeimages(unsigned char image[SIZE][SIZE]);
void flipimage(unsigned char image[SIZE][SIZE]);
void rotateiamge(unsigned char image[SIZE][SIZE]);
void lightenimage(unsigned char image[SIZE][SIZE]);
void darkenimage(unsigned char image[SIZE][SIZE]);
void edgedetection(unsigned char image[SIZE][SIZE]);
void blurimage(unsigned char image[SIZE][SIZE]);
void enlargeimage(unsigned char image[SIZE][SIZE]);
void shuffleimage(unsigned char image[SIZE][SIZE]);



int main() 
{
    unsigned char image[256][256];
    while(true)
    {
        loadImage(image);
        
        
        cout << "Welcome to the filter app, Please select your filter" << endl;
        cout << "1. White and Black " << endl;
        cout << "2. Color inversion " << endl;
        cout << "3. Merge images" << endl;
        cout << "4. Flip image" << endl;
        cout << "5. rotate image" << endl;
        cout << "6. lighten the image by 50%" << endl;
        cout << "7. Darken the image by 50%" << endl;
        cout << "8. Edge detection" << endl;
        cout << "9. Blur image" << endl;
        cout << "10. Enlarge image" << endl;
        cout << "11. Shuffle image" << endl;
        cout << "12. Exit" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                whiteAndBlack(image);
                break;
            }
            case 2:
            {
                colorinversion(image);
                break;
            }
            case 3:
            {
                mergeimages(image);
                break;
            }    
            case 4:
            {
                flipimage(image);
                break;
            }
            case 5:
            {
                rotateiamge(image);
                break;
            }
            case 6:
            {
                lightenimage(image);
                break;
            }
            case 7:
            {
                darkenimage(image);
                break;
            }
            case 8:
            {
                edgedetection(image);
                break;
            }
            case 9:
            {
                blurimage(image);
                break;
            }
            case 10:
            {
                enlargeimage(image);
                break;
            }
            case 11:
            {
                shuffleimage(image);
                break;
            }
            case 12:
            {
                cout<< "Thanks for using the filter app";
                return 0;
                
            }
            default:
            {
            cout << "Invalid choice, please select a valid option." << endl;
                    continue;
            }

        }
            saveImage(image);

            cout << "Filter applied successfully" << endl;
    }
        return 0;
}

void whiteAndBlack(unsigned char image[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
          if (image[i][j] > 128)
          {
                image[i][j] = 255;
          }
          else 
          {
                image[i][j] = 0;
          }
        }
    }
}
void loadImage(unsigned char image[256][256])
{
    string inputFilename; 
    cout << "Enter the name of the image file: ";   
    cin >> inputFilename;
    inputFilename = inputFilename + ".bmp";
    
    if (readGSBMP(inputFilename.c_str(), image) != 0) 
    {
        while(true)
        {
        cout << "Error, File not found,Please enter the name of the image file" << endl;
        cin >> inputFilename;
        inputFilename = inputFilename + ".bmp";
        if(readGSBMP(inputFilename.c_str(), image) == 0)
            break;
        } 
    }
}
void saveImage(unsigned char image[256][256])
{
    string outputFilename;
    cout << "Enter the name for the output file: ";
    cin >> outputFilename;
    outputFilename = outputFilename+ ".bmp";
    writeGSBMP(outputFilename.c_str(), image);
}
void colorinversion(unsigned char image[SIZE][SIZE])
{
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            image[i][j] = 255 - image[i][j];
        }
    }
}

void mergeimages(unsigned char image[SIZE][SIZE])
{
    unsigned char image2[256][256];    
    string inputFilename2; 
    
    cout << "Enter the name of the second image file: ";   
    cin >> inputFilename2;
    inputFilename2 = inputFilename2 + ".bmp";
    
    if (readGSBMP(inputFilename2.c_str(), image2) != 0) 
    {
        while(true)
        {
        cout << "Error, File not found,Please enter the name of the image file" << endl;
        cin >> inputFilename2;
        inputFilename2 = inputFilename2 + ".bmp";
        if(readGSBMP(inputFilename2.c_str(), image2) == 0)
            break;
        } 
    }

    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            image[i][j] = (image2[i][j] + image[i][j])/2;
        }
    }
}
void flipimage(unsigned char image[SIZE][SIZE])
{
    cout<<"How do you want to flip the picture"<<endl;
    cout<<"1. Horizontally" << endl;
    cout<<"2. Vertically" << endl;
      
    int flipchoice;
    cin >> flipchoice;
    while(flipchoice>2)
    {
        cout << "Invalid choice, please enter a valid option." << endl;
        cin >> flipchoice;
    }
    if(flipchoice == 1)
    {
        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 128; j++)
            {
                unsigned char temp = image[i][j];
                image[i][j] = image[i][255 - j];
                image[i][255 - j] = temp;
            }
        }
    }
    
    else if(flipchoice == 2)
    {
        for (int j = 0; j < 256; j++)
        {
            for (int i = 0; i < 128; i++)
            {
                unsigned char temp = image[i][j];
                image[i][j] = image[255 - i][j];
                image[255 - i][j] = temp;
            }
        }
     }
}

void rotateiamge(unsigned char image[SIZE][SIZE])
{
    int rotatechoice;
    bool validChoice = false;

    while (!validChoice)
    {
        cout << "How do you want to rotate the picture?" << endl;
        cout << "1. 90 degrees clockwise" << endl;
        cout << "2. 180 degrees clockwise" << endl;
        cout << "3. 270 degrees clockwise" << endl;
        cin >> rotatechoice;

        if (rotatechoice == 1 || rotatechoice == 2 || rotatechoice == 3) 
        {
            validChoice = true;
        }

        else
        {
            cout << "Invalid choice, please enter 1, 2, or 3." << endl; 
        }
    }
      
    unsigned char temp[256][256];

    switch (rotatechoice)
    {
        case 1:
            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    temp[j][255 - i] = image[i][j];
                }
            }
            break;

        case 2:
            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    temp[255 - i][255 - j] = image[i][j];
                }
            }
            break;

        case 3:
            for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    temp[255 - j][i] = image[i][j];
                }
            }
            break;

    }

        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
            {
                image[i][j] = temp[i][j];
            }
        }
}
void lightenimage(unsigned char image[SIZE][SIZE])
{
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            if(image[i][j]<=170)
            {
                image[i][j] = image[i][j]+85;
            }
                          
            else
            {
                image[i][j] = 255;
            }
        }
    }
}

void darkenimage(unsigned char image[SIZE][SIZE])
{
    for(int i =0;i<256;i++)
    {
        for (int j = 0; j < 256; j++)
        {
                image[i][j] = image[i][j]/2;
        }
    }
}

void edgedetection(unsigned char image[SIZE][SIZE])
{
    unsigned char temp[256][256];
    
    for (int i = 1; i < SIZE - 1; i++)
    {
        for (int j = 1; j < SIZE - 1; j++)
        {
            int diff = 0;
            int center = image[i][j];
            
            diff = max(diff, abs(center - image[i - 1][j])); 
            diff = max(diff, abs(center - image[i + 1][j])); 
            diff = max(diff, abs(center - image[i][j - 1])); 
            diff = max(diff, abs(center - image[i][j + 1])); 
            diff = max(diff, abs(center - image[i - 1][j - 1])); 
            diff = max(diff, abs(center - image[i - 1][j + 1])); 
            diff = max(diff, abs(center - image[i + 1][j - 1])); 
            diff = max(diff, abs(center - image[i + 1][j + 1])); 
            
            if (diff > 50)
            {
                temp[i][j] = 0;
            }
            else
            {
                temp[i][j] = 255;
            }
        }
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}
void blurimage(unsigned char image[SIZE][SIZE])
{
    unsigned char temp[256][256];
    for(int i =1;i<256;i++)
    {
        for (int j = 1; j < 256; j++)
        {
            int sum = 0;
            for(int k = -1; k<=1; k++)
            {
                for(int l = -1; l<=1; l++)
                {
                    sum =sum + image[i+k][j+l];
                }
            }
            sum = sum/9;
            temp[i][j] = sum;
            
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}
void enlargeimage(unsigned char image[SIZE][SIZE])
{
    unsigned char temp[SIZE][SIZE];
    int enlargechoice;

    cout << "Which quarter do you want to zoom in on?" << endl;
    cout << "1. Top left" << endl;
    cout << "2. Top right" << endl;
    cout << "3. Bottom left" << endl;
    cout << "4. Bottom right" << endl;
    cin >> enlargechoice;

    while (enlargechoice < 1 || enlargechoice > 4) {
        cout << "Invalid choice, please enter 1, 2, 3, or 4: ";
        cin >> enlargechoice;
    }

    int startX, startY;

    if (enlargechoice == 1 || enlargechoice == 2) {
        startX = 0;
    } else {
        startX = 128;
    }

    if (enlargechoice == 1 || enlargechoice == 3) {
        startY = 0;
    } else {
        startY = 128;
    }

    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {
            unsigned char pixel = image[startX + i][startY + j];

            temp[i * 2][j * 2] = pixel;
            temp[i * 2][j * 2 + 1] = pixel;
            temp[i * 2 + 1][j * 2] = pixel;
            temp[i * 2 + 1][j * 2 + 1] = pixel;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = temp[i][j];
        }
    }
}
void shuffleimage(unsigned char image[SIZE][SIZE])
 {
    unsigned char temp[SIZE][SIZE]; 
    int order[4];

    cout << "Enter the order of quarters (1-4, separated by spaces): ";

    for (int i = 0; i < 4; i++)
    {
        cin >> order[i];
    }
    int quarterX[4] = {0, 0, 128, 128};
    int quarterY[4] = {0, 128, 0, 128};

    for (int i = 0; i < 4; i++)
    {
        int srcX = quarterX[order[i] - 1];
        int srcY = quarterY[order[i] - 1];
        int destX = quarterX[i];
        int destY = quarterY[i];

        for (int x = 0; x < 128; x++)
        {
            for (int y = 0; y < 128; y++)
            {
                temp[destX + x][destY + y] = image[srcX + x][srcY + y];
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}