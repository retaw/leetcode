/*
 * Author: LiZhaojia 
 *
 * Last modified: 2014-09-29 22:05 +0800
 *
 * Description: 测试工具头文件
 */

#ifndef WATER_BASE_TEST_HPP
#define WATER_BASE_TEST_HPP

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

#include <sstream>
#include <string>

#include <memory>
#include <functional>

#include <exception>
#include <stdexcept>

#include <algorithm>

#include <iostream>
#include <iomanip>
#include "ostream_stdcontainer.h"

using std::cout;
using std::cerr;
using std::cin;
using std::endl;

using std::string;

using std::vector;
using std::map;
using std::multimap;
using std::unordered_map;
using std::unordered_multimap;

using std::set;
using std::multiset;
using std::unordered_set;
using std::unordered_multiset;

using namespace std::placeholders;

#endif


#ifdef FOR_EXAMINATION
static int x = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
#endif
