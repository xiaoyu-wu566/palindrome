//
//  main.cpp
//  palindrome
//
//  Created by Xiaoyu Wu on 10/21/18.
//  Copyright © 2018 Xiaoyu Wu. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include "functions.h"
using namespace std;

int main(int argc, char * argv[])
{
    // string to hold a flag or string in the command line
    string temp;
    
    // number of flag
    int num = 0;
    
    // isC is false: turn off case sensitivity; true: turn on case sensitivity
    bool isC = false;
    
    // isS is true: turn on ignoring spaces; false: turn off ignoring spaces
    bool isS = true;
    
    // isP is false: is not a palindrome; true: is a palindrome
    bool isP;
    
    // a loop to check falgs and strings in command line
    for (int i = 1; i < argc; ++i)
    {
        temp = argv[i];
        if (temp.at(0) == '-')
        {
            for (int j = 1; j < temp.size(); ++j)
            {
                if (temp.at(j) == 'c' || temp.at(j) == 'C')  // flag c or C sets
                {
                    isC = true;
                }
                else if (temp.at(j) == 's' || temp.at(j) == 'S') // flag s or S sets
                {
                    isS = false;
                }
                else  // invid flags
                {
                    printUsageInfo(argv[0]);
                    return 0;
                }
            }
            num = num + 1;
        }
        else
        {
            isP = isPalindrome(temp, isC, isS);
            if(isP == false)
            {
                cout << "\"" << temp << "\"" << " is not a palindrome." << endl;
            }
            else
            {
                cout << "\"" << temp << "\"" << " is a palindrome." << endl;
            }
        }
    }
    if (num == argc - 1) // there is no string
    {
        printUsageInfo(argv[0]);
    }
    
    return 0;
}
