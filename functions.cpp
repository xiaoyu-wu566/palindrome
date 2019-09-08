//
//  functions.cpp
//  palindrome
//
//  Created by Xiaoyu Wu on 10/21/18.
//  Copyright © 2018 Xiaoyu Wu. All rights reserved.
//

#include "functions.h"
#include <string>
#include <iostream>
#include <cctype>
#include <locale>
using namespace std;

// A function that prints program usage message in case no input strings were found at the command line.
void printUsageInfo(string name)
{
    cout << "Usage: " << name << " [-c] [-s] string ..." << endl;
    cout << "  -c: turn on case sensitivity" << endl;
    cout << "  -s: turn off ignoring spaces" << endl;
}

// Remove all punctuation marks possibly including spaces depending on the flag value.
string removePunctuation(string name)
{
    string newName;
    for (int i = 0; i < name.size(); ++i)
    {
        if(!isspace(name.at(i)))
        {
            newName.push_back(name.at(i));
        }
    }
    return newName;
}

// convert each letter to the lowercase version for case-insensitive comparisons.
string toLower(string name)
{
    string newName;
    for(int i = 0; i < name.size(); ++i)
    {
        char newChar;
        newChar = tolower(name.at(i));
        newName.push_back(newChar);
    }
    return newName;
}

// Helper recursive function that determines whether a string is a character-unit palindrome.
bool isPalindromeR(string name)
{
    if(name.size() == 1)
    {
        return true;
    }
    else if(name.size() == 2)
    {
        if(name.at(0) == name.at(1))
        {
            return true;
        }
        else{
            return false;
        }
    }
    else
    {
        if(name.at(0) == name.at(name.size() - 1))
           {
               name = name.substr(1, name.size()-2);
               return isPalindromeR(name);
           }
        else{
            return false;
        }
    }
}

// A function that determines whether a string is a character-unit palindrome.
bool isPalindrome(string name, bool flag_c, bool flag_s)
{
    string newName;
    for(int i = 0; i < name.size(); ++i)
    {
        if(isalpha(name.at(i)) || isspace(name.at(i)))
        {
            newName.push_back(name.at(i));
        }
    }
    
    if(!flag_c)
    {
        newName = toLower(newName);
    }
    if(flag_s)
    {
        newName = removePunctuation(newName);
    }
    return isPalindromeR(newName);
}
                            
