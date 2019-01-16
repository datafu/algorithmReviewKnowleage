//
//  FSPsyntax.cpp
//  AlgorithmReviewKnowleage
//
//  Created by fushp on 2019/1/16.
//  Copyright © 2019年 fushp. All rights reserved.
//

#include "FSPsyntax.hpp"

//把一个实例赋值给另外一个实例
void FSPsyntaxTest1(){
    char hello[] ="helloworld";
    FSPsyntax tax = FSPsyntax(hello);
    FSPsyntax nextTax = tax;
    printf("The expected result is: %s.\n", hello);
    printf("The actual result is: ");
    nextTax.Print();
}

//把一个实例赋值给他自己
void FSPsyntaxTest2(){
    char hello[] ="helloworld";
    FSPsyntax tax = FSPsyntax(hello);
    tax = tax;
    printf("The expected result is: %s.\n", hello);
    printf("The actual result is: ");
    tax.Print();
}

//连续赋值
void FSPsyntaxTest3(){
    char hello[] ="helloworld";
    FSPsyntax str1(hello);
    FSPsyntax str2, str3;
    str3 = str2 = str1;
    printf("The expected result is: %s.\n", hello);
    printf("The actual result is: ");
    str2.Print();
    str3.Print();
}


FSPsyntax::FSPsyntax(char *str){
    if (str == nullptr) {
        m_data =new char[1];
        m_data[0] = '\0';
    }else{
        size_t length =strlen(str);
        m_data = new char[length+1];
        strcpy(m_data, str);
    }
    
}


FSPsyntax::~FSPsyntax(){
    delete[] m_data;
    
}


void FSPsyntax::Print()
{
    printf("%s", m_data);
}

FSPsyntax::FSPsyntax(const FSPsyntax& str) {
    size_t length =strlen(str.m_data);
    m_data = new char[length+1];
    strcpy(m_data, str.m_data);
}


FSPsyntax& FSPsyntax::operator =(const FSPsyntax& str){
    
    if (this != &str){
        
        FSPsyntax tax = FSPsyntax(str);
        char * t_data = tax.m_data;
        tax.m_data = m_data;
        m_data = t_data;
    }
    return  *this;
    
}

