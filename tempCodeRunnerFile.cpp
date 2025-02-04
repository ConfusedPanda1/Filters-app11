#include <iostream>
#include "bmplib.cpp"

using namespace std;

int main() 
{
    unsigned char image[256][256];
    string inputFilename;
    string outputFilename;

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

    cout << "Welcome to the filter app, Please select your filter" << endl;
    cout << "1. White and Black " << endl;
    cout << "2. Color inversion " << endl;
    cout << "3. Merge images" << endl;
    cout << "4. Flip image" << endl;

    int choice;
    cin >> choice;
    switch (choice)
    {
        case 1:
            {for (int i = 0; i < 256; i++)
            {
                for (int j = 0; j < 256; j++)
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
    


          

        default:
            cout << "Invalid choice" << endl;
            return 0;
    }
    cout << "Enter the name for the output file"<<endl;
    cin >> outputFilename;
    outputFilename = outputFilename + ".bmp";

    writeGSBMP(outputFilename.c_str(), image);

    cout << "Filter applied successfully" << endl;
    return 0;
}