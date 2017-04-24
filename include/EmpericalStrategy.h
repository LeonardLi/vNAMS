#ifndef _EMPERICAL_STRATEGY_
#define _EMPERICAL_STRATEGY_

#include "ScheduleStrategy.h"
#include <utility> 

class EmpericalStrategy :public ScheduleStrategy{
public:
EmpericalStrategy(){};
virtual ~EmpericalStrategy(){};
std::vector<Decision> schedule(const std::map<int, VM_info> &vmInfoMap, 
				const std::vector<double> &physicalCpuUsage, const Numa_node* nodeInfos,
				const int numOfNode, const int NIC_NODE_ID);
private:

};

#endif