//
//  functions.h
//  palindrome
//
//  Created by Xiaoyu Wu on 10/21/18.
//  Copyright © 2018 Xiaoyu Wu. All rights reserved.
//

#ifndef functions_h
#define functions_h

#include <string>
using namespace std;

void printUsageInfo(string name);
bool isPalindrome(string name, bool flag_c, bool flag_s);
bool isPalindromeR(string name);
string removePunctuation(string name);
string toLower(string name);

#endif /* functions_h */
