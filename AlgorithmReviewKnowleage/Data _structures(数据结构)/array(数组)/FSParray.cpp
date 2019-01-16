//
//  FSParray.cpp
//  AlgorithmReviewKnowleage
//
//  Created by fushp on 2018/12/14.
//  Copyright © 2018年 fushp. All rights reserved.
//

#include "FSParray.hpp"

// 数组中重复的数字 时间复杂度O(n) 空间复杂度O(1)
bool FSPArr::dumplicate(int numbers[],int length , int *dumplicate) {
    //边界判断
    if (numbers == nullptr || length == 0) {
        return  false;
    }
    //数组是否超过范围
    for (int index = 0 ; index < length ; index ++) {
        if (numbers[index] < 0 || numbers[index] >= length ) {
            return  false;
        }
    }
    
    for (int index = 0; index < length; index ++) {
        while (numbers[index] != index) { //当前下标不是为index 进行比较
            if (numbers[numbers[index]] ==  numbers[index]) {
                *dumplicate = numbers[index];
                return  true;
            }
            int temp = numbers[index];
            numbers[index] = numbers[numbers[index]];
            numbers[numbers[index]] = temp;
            
        }
    }
    
    return  false;
}
