//
//  DesEncryption.h
//  ccf
//
//  Created by ccf on 16-8-9.
//
//

#ifndef __JellyBlast__DesEncryption__
#define __JellyBlast__DesEncryption__

#include <iostream>

class DES  
{  
public:  
    //明文  
    char msg[8];  
    bool bmsg[64];  
    //密钥  
    char key[8];  
    bool bkey[64];  
    //16个子密钥  
    bool subkey[16][48];  
    //l0 r0中间变量  
    bool rmsgi[32],lmsgi[32];//第i个  
    bool rmsgi1[32],lmsgi1[32];//第i+1个  
    //密文  
    bool bcryptedmsg[64];  
    char cryptedmsg[8];  
    //解密的结果  
    bool bdecipher[64];  
    char decipher[8];  

private:  
    //静态常量      
    //不允许在类内初始化  
    //初始值换ip  
    const static int ip[64];  

    //子密钥  
    //置换选择1  
    const static int c0[28];  
    const static int d0[28];  
    //循环左移表  
    const static int keyoff[16];  
    //置换选择2  
    const static int di[48];  
    //加密函数  
    //e运算  
    const static int e_operate[48];  
    //sbox  
    const static int sbox[8][64];  
    //置换运算p  
    const static int p_operate[32];  
    //逆初始置换ip  
    const static int back_ip[64];  
    //位掩码  
    const static char bitmask[8];  
    
public:  
    //设置明文和密钥  
    //_length要小于或等于8  
    void SetMsg(char* _msg,int _length);  
    void SetKey(char* _msg,int _length);  
    //生产子密钥  
    void ProduceSubKey();  
    //总的的加密流程  
    void Crypte();  
    //解密  
    void Decipher();  
    //输出密文  
    void OutPutCryptedMsg();  
    //二进制转成字符  
    void Bit2Char(bool* _barray,char* _carray);//length=64  
    //输出解密后的明文  
    void OutPutDecipher();  
    
public:  
    //字符转成二进制，并保存到64位bool数组中  
    void Char2Bit(char* _carray,bool* _barray,int length);  
    ////二进制转成字符  
    //void Bit2Char(bool* _barray,char* _carray);//length=64  
    //初始置换  
    void InitSwap(bool in[64]);  
    //初始逆置换  
    void InitReSwap(bool out[64]);  
    //循环左移  
    void SubKeyOff(bool* _subkey,int _off);  
    //e运算操作函数  
    void EOperation(bool a[32],bool b[48]);  
    //模2相加  
    //相同为0 不同为1  
    void Mode2Add(bool a[],bool b[],bool c[],int length);  
    //sbox  
    void DealSBox(bool in[48],bool out[32]);  
    void _DealSBox(bool in[6],bool out[4],int box);  
    //p opraration  
    void POperation(bool temp[32],bool result[32]);  
    //加密函数  
    void CrypteFunction(bool in[32],int isubkey,bool out[32]);  
    
    //数组之间赋值  
    void CopyArray(bool array1[],bool array2[],int size);  
};  

#endif /* defined(__JellyBlast__DesEncryption__) */
