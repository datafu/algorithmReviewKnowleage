//
//  FStest.cpp
//  AlgorithmReviewKnowleage
//
//  Created by fushp on 2019/1/16.
//  Copyright © 2019年 fushp. All rights reserved.
//

#include "FStest.hpp"
#include "FSPsyntax.hpp"
#include "FSParray.hpp"

//赋值
void FStest::syntaxText() {
    FSPsyntaxTest1();
    FSPsyntaxTest2();
    FSPsyntaxTest3();
}

// 单例实现

void FStest::singleTest (){
    auto pClass = Magic_Singleton<MyClass>::GetInstance("create");
    pClass->print();
    Magic_Singleton<MyClass>::DesInstance();
}


////////////////////////////数组////////////////////////////////
/*
 测试用例:
  长度为n的数组包含多个数字
  数组不包含重复的数字
   无效输入测试火用例
 */
// 查找重复一个数字
void FStest::dumplicationTest {
    
    
}


////////////////////////////数组////////////////////////////////

