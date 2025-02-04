#include <iostream>
#include "bmplib.cpp"

using namespace std;



void loadImage(unsigned char image[256][256]) {
    string inputFilename;
    while (true) {
        cout << "Enter the name of the image file: ";
        cin >> inputFilename;
        inputFilename += ".bmp";

        if (readGSBMP(inputFilename.c_str(), image) == 0) 
            return;

        cout << "Error: File not found. Please try again." << endl;
    }
}
void saveImage(unsigned char image[256][256]) {
    string outputFilename;
    cout << "Enter the name for the output file: ";
    cin >> outputFilename;
    outputFilename += ".bmp";

    writeGSBMP(outputFilename.c_str(), image);
}

void whiteAndBlack(unsigned char image[SIZE][SIZE]);

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
    cout << "8. Exit" << endl;

    int choice;
    cin >> choice;
    switch (choice)
    {
        case 1:
        // !!indentation problems
            {
                whiteAndBlack(image);
                break;
            }

        case 2:
            {for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
                {
                    image[i][j] = 255 - image[i][j];
                }
            }
            break;
            }

        case 3:
          {
        unsigned char image2[256][256];    
        string inputFilename2; 
    
    cout << "Enter the name of the image file: ";   
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
            break;
          }
          
        case 4:
        {
         cout<<"How do you want to flip the picture"<<endl;
         cout<<"1. Horizontally" << endl;
         cout<<"2. Vertically" << endl;

         int flipchoice;
         cin >> flipchoice;
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
         else
         {
            while(true)
            {
                cout << "Invalid choice, Please enter 1 or 2" << endl;
                cin >> flipchoice;
                if(flipchoice == 1 || flipchoice == 2)
                break;
            }
         }
          break;
        }
        case 5:
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

    break;
}

        case 6:
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
        break;
        }
        case 7:
        {
         for(int i =0;i<256;i++)
          {
            for (int j = 0; j < 256; j++)
            {
                image[i][j] = image[i][j]/2;
            }
          }
            break;
        }

        case 8:
        {
            cout<< "Thanks for using the filter app";
            return 0;
            
        }

          

        default:
        cout << "Invalid choice, please select a valid option." << endl;
                continue;
    }
    saveImage(image);

    cout << "Filter applied successfully" << endl;
}
    return 0;
}



void whiteAndBlack(unsigned char image[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > 128) {
                image[i][j] = 255;
            } else {
                image[i][j] = 0;
            }
        }
    }
}