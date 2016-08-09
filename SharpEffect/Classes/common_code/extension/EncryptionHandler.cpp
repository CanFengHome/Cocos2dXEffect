//
//  EncryptionHandler.cpp
//  SharpEffect
//
//  Created by ccf on 16/8/9.
//
//

#include "EncryptionHandler.h"
#include "DesEncryption.h"

static char DES_KEY[] = "10010010";

/*
 DES des;  
 //设置明文  
 des.SetMsg(msg,8);  
 //设置密钥  
 des.SetKey(key,8);  
 //生产子密钥  
 des.ProduceSubKey();  
 //加密  
 des.Crypte();  
 //输出密文  
 des.OutPutCryptedMsg();  
 //解密  
 des.Decipher();  
 //输出解密后的明文  
 des.OutPutDecipher();
 */

string EncryptionHandler::encrypt(const string& msg)
{
    vector<string> parts;
    for (int i = 0; i < msg.length(); i += 8)
    {
        string subStr = msg.substr(i, 8);
        parts.push_back(subStr);
    }
    
    string result;
    for (int i = 0; i < parts.size(); i++)
    {
        string cipher = singleEncrypt(parts.at(i));
        result += cipher;
//        for (int j = 0; j < cipher.size(); j++)
//        {
//            result.push_back(cipher.at(j));
//        }
    }
    
    return result;
}

string EncryptionHandler::decrypt(const string& cryptedMsg)
{
    CC_ASSERT(cryptedMsg.size() % 8 == 0);
    if (cryptedMsg.size() % 8 != 0)
    {
        return "";
    }
    
    size_t nPartNum = cryptedMsg.size() / 8;
    string result;
    
    //string onePart(8);
    for (int i = 0; i < nPartNum; i++)
    {
//        for (int j = 0; j < 8; j++)
//        {
//            onePart[j] = cryptedMsg.at(i * 8 + j);
//        }

        string onePart = cryptedMsg.substr(i * 8, 8); 
        
        string oneDecodedPart = singleDecrypt(onePart);
        result += oneDecodedPart;
    }
    
    return result;
}

string EncryptionHandler::singleEncrypt(const string& msg)
{
    DES des;
    des.SetKey(DES_KEY, 8);
    des.ProduceSubKey();
    
    
    CC_ASSERT(msg.length() <= 8);
    char byte[8] = {0};
    for (int i = 0; i < msg.length(); i++)
    {
        byte[i] = msg.c_str()[i];
    }
    
    des.SetMsg(byte, 8);
    des.Crypte();
    
   // vector<char> cipher;
   // for (int i = 0; i < 8; i++)
   // {
   //     cipher.push_back(des.cryptedmsg[i]);
   // }
    
    string cipher(des.cryptedmsg, des.cryptedmsg + 8);
    return cipher;
}

string EncryptionHandler::singleDecrypt(const string& cryptedMsg)
{
    DES des;
    des.SetKey(DES_KEY, 8);
    des.ProduceSubKey();
    
    CC_ASSERT(cryptedMsg.size() <= 8);
    for (int i = 0; i < cryptedMsg.size(); i++)
    {
        des.cryptedmsg[i] = cryptedMsg[i];
    }
    des.Char2Bit(des.cryptedmsg, des.bcryptedmsg, 8);
    
    des.Decipher();
    
    char msg[9] = {0};
    for (int i = 0; i < 8; i++)
    {
        msg[i] = des.decipher[i];
    }
    
    return string(msg);
}