//
//  FSPsyntax.hpp
//  AlgorithmReviewKnowleage
//
//  Created by fushp on 2019/1/16.
//  Copyright © 2019年 fushp. All rights reserved.
//
/*
 
 类语法使用
  赋值运算符使用
    关注点: 1. 是否会循环引用
           2. 内存释放,每次申请(如果内存不足 异常处理,所有我们需要先申请内存 再是否之前的内存)
           3.
           4.
  实现单例模式
 
 */

#ifndef FSPsyntax_hpp
#define FSPsyntax_hpp

#include <mutex>
#include <memory>
#include <stdio.h>
#include<cstring>
#include<cstdio>

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 赋值函数
 **/
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void FSPsyntaxTest1();
void FSPsyntaxTest2();
void FSPsyntaxTest3();

class FSPsyntax {
    
public:
    FSPsyntax(char *str = nullptr);
    ~FSPsyntax();
    FSPsyntax(const FSPsyntax& str);
    //赋值
    FSPsyntax& operator = (const FSPsyntax& str);
    void Print();
private:
    //member 成员
    char * m_data;
    
};



///////////////////////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************/
/* 名称：万能单例类                                                     */
/* 说明：可把任何类包装成线程安全的全局单例类，出口默认智能指针           */
/* 作者：Song                                                          */
/* Email：songshuda@vip.qq.com */
/* 原文：https://blog.csdn.net/godmaycry/article/details/78458329 */
/************************************************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////////////


template<typename T>
class Magic_Singleton {
public:
    
    //获取全局单例对象
    template<typename ...Args>
    static std::shared_ptr<T> GetInstance(Args&&... args) {
        if (!m_pSington) {
            std::lock_guard<std::mutex> gLock(m_Mutex);
            if (nullptr == m_pSington) {
                m_pSington = std::make_shared<T>(std::forward<Args>(args)...);
            }
        }
        return m_pSington;
    }
    
    //主动析构单例对象（一般不需要主动析构，除非特殊需求）
    static void DesInstance() {
        if (m_pSington) {
            m_pSington.reset();
            m_pSington = nullptr;
        }
    }
    
private:
    explicit Magic_Singleton();
    Magic_Singleton(const Magic_Singleton&) = delete;
    Magic_Singleton& operator=(const Magic_Singleton&) = delete;
    ~Magic_Singleton();
    
private:
    static std::shared_ptr<T> m_pSington;
    static std::mutex m_Mutex;
};

template<typename T>
std::shared_ptr<T> Magic_Singleton<T>::m_pSington = nullptr;

template<typename T>
std::mutex Magic_Singleton<T>::m_Mutex;

/**---------------------
作者：godmaycry
来源：CSDN
原文：https://blog.csdn.net/godmaycry/article/details/78458329
版权声明：本文为博主原创文章，转载请附上博文链接！

///////////////////////////////////////////////////////////////////////////////////////////////////////////
**/


class MyClass {
public:
    MyClass(const std::string& strData) : m_strData(strData) {
        printf("%s\n", m_strData.data());
    };
    ~MyClass() {
        printf("destory");
    };
    void print(){
        printf("print MyClass \n");
    }
    
private:
    std::string m_strData;
};


#endif /* FSPsyntax_hpp */
