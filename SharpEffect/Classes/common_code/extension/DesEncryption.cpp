//
//  DesEncryption.cpp
//  ccf
//
//  Created by ccf on 16-8-9.
//
//

#include "DesEncryption.h"

using namespace std;  

//静态常量  
const int DES::ip[64]={  
    58,50,42,34,26,18,10,2,  
    60,52,44,36,28,20,12,4,  
    62,54,46,38,30,22,14,6,  
    64,56,48,40,32,24,16,8,  
    57,49,41,33,25,17,9,1,  
    59,51,43,35,27,19,11,3,  
    61,53,45,37,29,21,13,5,  
    63,55,47,39,31,23,15,7  
};  
const int DES::c0[28]={  
    57,49,41,33,25,17,9,  
    1,58,50,42,34,26,18,  
    10,2,59,51,43,35,27,  
    19,11,3,60,52,44,36  
};  
const int DES::d0[28]={  
    63,55,47,39,31,23,15,  
    7,62,54,46,38,30,22,  
    14,6,61,53,45,37,29,  
    21,13,5,28,20,12,4  
};  
const int DES::keyoff[16]={  
    1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1  
};  
const int DES::di[48]={  
    14,17,11,24,1,5,  
    3,28,15,6,21,10,  
    23,19,12,4,26,8,  
    16,7,27,20,13,2,  
    41,52,31,37,47,55,  
    30,40,51,45,33,48,  
    44,49,39,56,34,53,  
    46,42,50,36,29,32  
};  
const int DES::e_operate[48]={  
    32,1,2,3,4,5,  
    4,5,6,7,8,9,  
    8,9,10,11,12,13,  
    12,13,14,15,16,17,  
    16,17,18,19,20,21,  
    20,21,22,23,24,25,  
    24,25,26,27,28,29,  
    28,29,30,31,32,1  
};  
const int DES::sbox[8][64]={  
    {    
        14, 4, 13, 1, 1, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,    
        0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,    
        4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,    
        15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13    
    },    
    
    {    
        15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,    
        3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,    
        0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,    
        13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9    
    },    
    
    {    
        10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,    
        13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,     
        13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,    
        1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12    
    },    
    
    {    
        7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,     
        13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,    
        10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,    
        3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14    
    },    
    
    {    
        2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,    
        14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,    
        4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,    
        11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3    
    },    
    
    {    
        12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,    
        10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,    
        9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,    
        4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13    
    },    
    
    {    
        4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,    
        13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,    
        1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,    
        6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12    
    },    
    
    {    
        13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 13, 14, 5, 0, 12, 7,    
        1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,    
        7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,    
        2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11    
    }    
};   
const int DES::p_operate[32]={  
    16,7,20,21,  
    29,12,28,17,  
    1,15,23,26,  
    5,18,31,10,  
    2,8,24,14,  
    32,27,3,9,  
    19,13,30,6,  
    22,11,4,25  
};  
const int DES::back_ip[64]={  
    40,8,48,16,56,24,64,32,  
    39,7,47,15,55,23,63,31,  
    38,6,46,14,54,22,62,30,  
    37,5,45,13,53,21,61,29,  
    36,4,44,12,52,20,60,28,  
    35,3,43,11,51,19,59,27,  
    34,2,42,10,50,18,58,26,  
    33,1,41,9,49,17,57,25  
};  
const char DES::bitmask[8]={static_cast<char>(128),64,32,16,8,4,2,1};  

//实现函数  

//  
//设置明文  
//  
void DES::SetMsg(char* _msg,int _length)  
{  
    if (_length>8)  
    {  
        return;  
    }  
    for (int i = 0; i < _length; i++)  
    {  
        msg[i]=_msg[i];  
    }  
    //转换成二进制  
    Char2Bit(msg,bmsg,8);  
    
};  
//  
//设置密钥  
//  
void DES::SetKey(char* _key,int _length)  
{  
    if (_length>8)  
    {  
        return;  
    }  
    for (int i = 0; i < _length; i++)  
    {  
        key[i]=_key[i];  
    }  
    //转成二进制  
    Char2Bit(key,bkey,8);  
};  
//  
//字符转成二进制  
//ok   length字符数组的长度  
void DES::Char2Bit(char* _carray,bool* _barray,int length)  
{  
    //int index=0;  
    for (int i = 0; i <length; i++)  
    {  
        for (int j = 0; j < 8; j++)  
        {  
            _barray[i*8+7-j]=(_carray[i]>>j)&1;  
        }  
    }  
};  
//  
//二进制转成字符  
//  
void DES::Bit2Char(bool* _barray,char* _carray)  
{  
    char temp;  
    for (int i = 0; i < 8; i++)  
    {  
        //数学方法转成字符  
        temp=0;  
        for (int j = 0; j < 8; j++)  
        {  
            if (_barray[i*8+j]==1)  
            {  
                temp|=bitmask[j];  
            }  
        }  
        //cout<<temp;  
        _carray[i]=temp;  
    }  
};  
//  
//初始置换函数  
//ok  
void DES::InitSwap(bool in[64])  
{  
    //打乱  
    for (int i = 0; i < 32; i++)  
    {  
        lmsgi[i]=in[ip[i]-1];  
        rmsgi[i]=in[ip[i+32]-1];  
    }  
};  
//  
//初始逆置换函数  
//ok  
void DES::InitReSwap(bool out[64])  
{  
    //组合成64数组  
    bool temp[64];  
    for (int i = 0; i < 32; i++)  
    {  
        temp[i]=rmsgi[i];  
        temp[32+i]=lmsgi[i];  
    }  
    //按照逆ip矩阵  
    for (int i = 0; i < 64; i++)  
    {  
        out[i]=temp[back_ip[i]-1];  
    }  
};  
//  
//循环左移  
//ok  
void DES::SubKeyOff(bool* _subkey,int _off)  
{  
    //有没有更好的办法???  
    bool temp;  
    for (int i = 0; i < _off; i++)  
    {  
        temp=_subkey[0];  
        for (int i = 0; i < 27; i++)  
        {  
            _subkey[i]=_subkey[i+1];  
        }  
        _subkey[27]=temp;  
    }  
};  
//  
//生产子密钥  
//ok  
void DES::ProduceSubKey()  
{  
    //置换选择1  
    bool ctemp[28],dtemp[28];  
    for (int i = 0; i < 28; i++)  
    {  
        ctemp[i]=bkey[c0[i]-1];  
        dtemp[i]=bkey[d0[i]-1];  
    }  
    bool keytemp[56];  
    for (int i = 0; i < 16; i++)  
    {  
        //循环左移  
        SubKeyOff(ctemp,keyoff[i]);  
        SubKeyOff(dtemp,keyoff[i]);  
        //合并成一个56数组  
        for (int j = 0; j <28; j++)  
        {  
            keytemp[j]=ctemp[j];  
            keytemp[28+j]=dtemp[j];  
        }  
        //置换选择2  
        for (int j = 0; j < 48; j++)  
        {  
            subkey[i][j]=keytemp[di[j]-1];  
        }  
    }  
};  
//  
//e运算  
//ok  
void DES::EOperation(bool a[32],bool b[48])  
{  
    for (int i = 0; i < 48; i++)  
    {  
        b[i]=a[e_operate[i]-1];  
    }  
};  
//  
//模2想加  
//ok  
void DES::Mode2Add(bool a[],bool b[],bool c[],int length)  
{  
    for (int i = 0; i < length; i++)  
    {  
        if (a[i]==b[i])  
        {  
            c[i]=0;  
        }else  
        {  
            c[i]=1;  
        }  
    }  
};  
//  
//sbox处理  
//ok  
void DES::DealSBox(bool in[48],bool out[32])  
{  
    bool _in[6],_out[4];  
    //8个盒子  
    for (int i = 0; i < 8; i++)  
    {  
        //提取盒子  
        for (int j = 0; j < 6; j++)  
        {  
            _in[j]=in[i*6+j];  
        }  
        //压缩  
        _DealSBox(_in,_out,i);  
        //放进out数组  
        for (int jj = 0; jj < 4; jj++)  
        {  
            out[i*4+jj]=_out[jj];  
        }  
    }  
};  
//  
//_dealsbox  
//ok  
void DES::_DealSBox(bool in[6],bool out[4],int box)  
{  
    int raw,col;  
    raw=in[0]*2+in[5];//转换成十进制 行  
    col=in[1]*2*2*2+in[2]*2*2+in[3]*2+in[4];//列  
    int result=sbox[box][raw*16+col];  
    //转成二进制  
    for (int i = 3; i >=0; i--)  
    {  
        out[i]=(result>>(3-i))&1;  
    }  
};  
//  
//p操作  
//ok  
void DES::POperation(bool temp[32],bool result[32])  
{  
    for (int i = 0; i < 32; i++)  
    {  
        result[i]=temp[p_operate[i]-1];  
    }  
};  
//  
//加密函数  
//isubkey表明用那个子密钥加密   ok  
void DES::CrypteFunction(bool in[32],int isubkey,bool out[32])  
{  
    //e 操作  
    bool temp1[48];  
    EOperation(in,temp1);  
    bool temp2[48];  
    Mode2Add(temp1,(bool *)subkey[isubkey],temp2,48);//ok  
    //盒子压缩  
    bool temp3[48];  
    DealSBox(temp2,temp3);  
    //置换运算p  
    POperation(temp3,out);  
    
};  
//  
// des加密流程  
//ok  
void DES::Crypte()  
{  
    //直接用bmsg明文  
    //直接用cryptedmsg存放密文  
    bool temp1[32],temp2[32];  
    //初始置换ip  
    InitSwap(bmsg);  
    //16轮迭代  
    for (int i = 0; i < 16; i++)  
    {  
        if (i%2==0)  
        {  
            //L1=R0  
            CopyArray(rmsgi,lmsgi1,32);  
            //f(R0,k0)  
            CrypteFunction(rmsgi,i,temp1);  
            //L0+f(R0,k0)  
            Mode2Add(lmsgi,temp1,temp2,32);  
            //R1=L0+f(R0,k0)  
            CopyArray(temp2,rmsgi1,32);  
        }else  
        {  
            //L2=R1  
            CopyArray(rmsgi1,lmsgi,32);  
            //f(R1,k1)  
            CrypteFunction(rmsgi1,i,temp1);  
            //L1+f(R1,k1)  
            Mode2Add(lmsgi1,temp1,temp2,32);  
            //R2=L1+f(R1,k1)  
            CopyArray(temp2,rmsgi,32);  
        }  
    }  
    
    //逆初始置换ip  
    InitReSwap(bcryptedmsg);  
    //转成字符  
    Bit2Char(bcryptedmsg,cryptedmsg);  
};  
//  
//数组赋值  
//ok  
void DES::CopyArray(bool content[],bool empty[],int size)  
{  
    for (int i = 0; i < size; i++)  
    {  
        empty[i]=content[i];  
    }  
};  
//  
//解密  
//ok  
void DES::Decipher()  
{  
    bool temp1[32],temp2[32];  
    //初始置换ip  
    InitSwap(bcryptedmsg);  
    //16轮迭代加密  
    
    for (int i = 0; i < 16; i++)  
    {  
        if (i%2==0)  
        {  
            //L1=R0  
            CopyArray(rmsgi,lmsgi1,32);  
            //f(R0,k0)  
            CrypteFunction(rmsgi,15-i,temp1);  
            //L0+f(R0,k0)  
            Mode2Add(lmsgi,temp1,temp2,32);  
            //R1=L0+f(R0,k0)  
            CopyArray(temp2,rmsgi1,32);  
        }else  
        {  
            //L2=R1  
            CopyArray(rmsgi1,lmsgi,32);  
            //f(R1,k1)  
            CrypteFunction(rmsgi1,15-i,temp1);  
            //L1+f(R1,k1)  
            Mode2Add(lmsgi1,temp1,temp2,32);  
            //R2=L1+f(R1,k1)  
            CopyArray(temp2,rmsgi,32);  
        }  
    }  
    //逆初始置换ip  
    InitReSwap(bdecipher);  
    //转成字符  
    Bit2Char(bdecipher,decipher);  
    
};  
//  
//输出密文  
//  
void DES::OutPutCryptedMsg()  
{  
    //Bit2Char(bcryptedmsg,cryptedmsg);  
    cout<<endl<<"密文:";  
    for (int i = 0; i < 8; i++)  
    {  
        cout<<cryptedmsg[i]<<' ';  
    }  
};  
//  
//输出解密明文  
//  
void DES::OutPutDecipher()  
{  
    //Bit2Char(bdecipher,decipher);  
    cout<<endl<<"解密:";  
    for (int i = 0; i < 8; i++)  
    {  
        cout<<decipher[i]<<' ';  
    }  
    cout<<endl;  
};  

/*
#include<iostream>  
#include"des.h"  
#include<string.h>  
using namespace std;  

int main()  
{  
    //教材的测试数据  
    char msg[8]={'0','1','2','3','4','5','6','7'};  
    char key[8]={'1','2','3','4','5','6','7','8'};  
    cout<<"明文：";  
    for (int i = 0; i < 8; i++)  
    {  
        cout<<msg[i]<<' ';  
    }  
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
    
    system("pause");  
    return 0;  
}  
*/