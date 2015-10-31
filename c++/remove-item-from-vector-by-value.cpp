//
//  main.cpp
//  remove an item from a vector by value
//
//  Created by Fatima B on 10/31/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    std::vector<std::pair<int,int>> vec;
    vec.push_back(std::make_pair(3, 4));
    vec.push_back(std::make_pair(1, 2));
    for (auto i = vec.begin(); i!=vec.end(); i++) {
        std::cout << i->first << " " << i->second << std::endl;
    }
    vec.erase(std::remove(vec.begin(), vec.end(),  std::make_pair(3,4)), vec.end());
    for (auto i = vec.begin(); i!=vec.end(); i++) {
        std::cout << i->first << " " << i->second << std::endl;
    }
    return 0;
}
