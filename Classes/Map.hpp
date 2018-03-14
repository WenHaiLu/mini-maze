//
//  Map.hpp
//  MIGONG
//
//  Created by 卢文海 on 2016/12/19.
//
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


//设置地图通过传值来选择地图

//0是墙
//1是路
//2 是鼠
//3是粮

int map1[100] = {
    0,0,0,0,0,0,0,0,0,0,
    0,2,0,1,1,1,1,1,1,0,
    0,1,0,1,0,0,0,0,0,0,
    0,1,0,1,0,0,1,1,1,0,
    0,1,0,1,0,0,0,1,0,0,
    0,1,1,1,1,1,1,1,1,0,
    0,1,0,0,1,0,0,0,0,0,
    0,1,1,0,1,0,1,1,1,0,
    0,1,0,0,1,1,1,0,3,0,
    0,0,0,0,0,0,0,0,0,0
};




int *setMap(int d)
{
    //地图1
    
    switch(d)
    {
        case 1:
            return map1;
    }
    return nullptr;
}




#endif /* Map_hpp */
