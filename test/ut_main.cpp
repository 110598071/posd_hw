#include <gtest/gtest.h>

#include "ut_text.h"
#include "ut_list_item.h"
#include "ut_paragraph.h"

#include <stdlib.h>
#include <iostream>

int main(int argc,char** argv){
    std::cout<< "Hello world!" << std::endl;
    std::cout<< "Testing!" << std::endl;
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}