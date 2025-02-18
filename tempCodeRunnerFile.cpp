#include <iostream>
using namespace std;

void hexToBinary(char hexValue[])
{
    int length = 0;
    while (hexValue[length] != '\0')
    {
        length++;
    }

    bool leadingZero = true;

    for (int i = 0; i < length; i++)
    {
        int decimal = 0;

        if (hexValue[i] >= '0' && hexValue[i] <= '9')
        {
            decimal = hexValue[i] - '0';
        }
        else if (hexValue[i] >= 'a' && hexValue[i] <= 'f')
        {
            decimal = hexValue[i] - 'a' + 10;
        }

        int binaryDigits[4] = {0, 0, 0, 0};
        int index = 3;

        while (decimal > 0)
        {
            binaryDigits[index] = decimal % 2;
            decimal /= 2;
            index--;
        }

        for (int j = 0; j < 4; j++)
        {
            if (binaryDigits[j] == 1)
            {
                leadingZero = false;
            }
            if (!leadingZero)
            {
                cout << binaryDigits[j];
            }
        }
    }
}

int main() {
    char hexValue[100];
    cin >> hexValue;

    hexToBinary(hexValue);

    return 0;
}
