//
// Created by shulamit on 10/31/17.
//

#include "ConsoleTokenFactory.h"
#include "ConsoleToken.h"

//Token* ConsoleTokenFactory:: Create() {
//    return new ConsoleToken();
//}


Token* ConsoleTokenFactory:: Create(int numObjects) {
    return new ConsoleToken[numObjects];
}