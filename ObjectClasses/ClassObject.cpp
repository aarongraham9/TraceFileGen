/*
 * ClassObject.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: cas
 */
#include <iostream>
#include <sstream>
#include "../defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClassObject.h"
#include <time.h>

using namespace std;

namespace traceGen {

ClassObject::ClassObject(int classId, string clsName, int staticReference) {
	myId = classId;
	myName = clsName;
	pointerSize = staticReference;
	nPrimitives = (rand() % MAX_PRIMITIVES) +1;
	
	countFieldType[0] = (rand()% nPrimitives); // for char 8
	countFieldType[1]= (rand()% nPrimitives) ;  // for int 32
	
	while(1){

		if ( (countFieldType[0]+countFieldType[1])< nPrimitives ){
			break;
		}
		countFieldType[0] = (rand()% nPrimitives); // for char 8
		countFieldType[1]= (rand()% nPrimitives) ;  // for int 32
	}

	countFieldType[2] = nPrimitives - (countFieldType[0]+countFieldType[1]);  // for long 64
	mySize = 16 + countFieldType[0]*8 + countFieldType[1]*32 + countFieldType[2]*64 + pointerSize*8;
	acc = 0;
}



ClassObject::~ClassObject() {
	// TODO Auto-generated destructor stub
}

}