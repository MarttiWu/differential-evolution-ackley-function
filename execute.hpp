//
//  execute.hpp
//  search
//
//  Created by WU,MENG-TING on 2020/7/8.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#ifndef execute_hpp
#define execute_hpp

#include <stdio.h>
#include <iostream>
#include <ctime>
#include "DE.hpp"

using namespace std;

const int block = 1;

void execute(const int Algo,const int runs,const int generations,const string filename,const int population,const double F,const double Cr, const double L, const double H,const int dim);

#endif /* execute_hpp */
