//
//  FSParray.hpp
//  AlgorithmReviewKnowleage
//
//  Created by fushp on 2018/12/14.
//  Copyright © 2018年 fushp. All rights reserved.
//

#ifndef FSParray_hpp
#define FSParray_hpp
/*
 
 tips:
 1.数组中重复的数字:
   方法：
      1.1 先排序 在查找 O(nlog(n))
      1.2 哈希表 O(n)
    测试数据{2,3,1,0,2,5,3}
 
 2.二维数组中的查找
 
 */

#include <stdio.h>

class FSPArr {
    
    
public:
    // 数组中重复的数字 时间复杂度O(n) 空间复杂度O(1)
    bool dumplicate(int numbers[],int length , int *dumplicate);
    
};

#endif /* FSParray_hpp */
