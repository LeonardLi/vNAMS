#ifndef V_F_H
#define V_F_H

#include "EmpericalStrategy.h"


enum FunctionType{
		UNDEFINED=-1,
		IO_INTENSIVE = 0,
		MEM_INTENSIVE,
		MIXED
} ;

class VirtualFunction {

public:


private:
	friend class EmpericalStrategy;

	//the amounts of this kind of vf
	int 				amount;

	enum FunctionType 		type;

	std::vector<char> v;

	VirtualFunction() {
		amount = 0;
		type = UNDEFINED;
	}

};


#endif