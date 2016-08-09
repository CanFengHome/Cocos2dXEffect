//
//  EncryptionHandler.h
//  SharpEffect
//
//  Created by ccf on 16/8/9.
//
//

#ifndef __EncryptionHandler__
#define __EncryptionHandler__

#include <iostream>
#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class EncryptionHandler
{
public:
    static string encrypt(const string& msg);
    static string decrypt(const string& cryptedMsg);
    
protected:
    static string singleEncrypt(const string& msg);
    static string singleDecrypt(const string& cryptedMsg);
};

#endif /* defined(__EncryptionHandler__) */
