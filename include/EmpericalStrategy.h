#ifndef _EMPERICAL_STRATEGY_
#define _EMPERICAL_STRATEGY_

#include "ScheduleStrategy.h"
#include "VirtualFunction.h"
#include <vector>
#include <utility> 
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>



class EmpericalStrategy :public ScheduleStrategy{
public:
EmpericalStrategy(){};
virtual ~EmpericalStrategy(){};
std::vector<Decision> schedule(const std::map<int, VM_info> &vmInfoMap, 
				const std::vector<double> &physicalCpuUsage, const Numa_node* nodeInfos,
				const int numOfNode, const int NIC_NODE_ID);
public:
	//read the infomation from file
	bool initFromFile();	
	//or from system
	bool initDefault(const Numa_node* nodeInfos,
					const int numOfNode);

	//the basic infomation
	std::vector<std::vector<double> > lantencyMatrix;

	std::vector<std::vector<double> > bandwidthMatrix;

	std::vector<VirtualFunction> serviceFunctionChain;

	void calculateAffinity(std::vector<Decision>&);

};

#endif
