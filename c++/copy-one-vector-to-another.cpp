//
//  main.cpp
//  copy one vector to another
//
//  Created by Fatima B on 10/31/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    std::vector<int> test;
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);

    std::vector<int> copy;
    copy.insert(copy.end(), test.begin(), test.end());

    for (auto i = copy.begin(); i != copy.end(); i++) {
        std::cout << *i << std::endl;
    }
    return 0;
}
