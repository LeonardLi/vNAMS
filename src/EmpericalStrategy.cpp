#include "EmpericalStrategy.h"
using namespace std;
#define LAN_FILE "/etc/lantency.txt"
#define BANDWIDTH_FILE "/etc/bandwidth.txt"

vector<Decision> EmpericalStrategy::schedule(const map<int, VM_info> &, 
				const vector<double> &physicalCpuUsage, const Numa_node* nodeInfos,
				const int numOfNode, const int NIC_NODE_ID)
{ 
    //init data from files
    if(!initFromFile()){
        printf("info files does not exist! Please check /etc/lantency.txt & /etc/bandwidth.txt \n");
        printf("Using System defalut info \n");
        initDefault(nodeInfos, numOfNode);
    }

    // log information
	for(int i = 0; i < numOfNode; i++) {
		const set<int>& cpuOfNode = nodeInfos[i].getCPUIDsOfThisNode();
		double nodeTotalCPUUsage = 0;
		for(auto cpuid : cpuOfNode) {
			nodeTotalCPUUsage += physicalCpuUsage[cpuid+1];
		}
		unsigned long long freeMemInMB = nodeInfos[i].getFreeMemoryInBytes()/1024/1024;
		printf("Node:%d\nTotal CPU Usage:%.3f%%\t Free Memory:%llu MB\n", i, nodeTotalCPUUsage, freeMemInMB);
	}

    vector<Decision> decisions;
    calculateAffinity(decisions); 
    return decisions;
}


bool EmpericalStrategy::initFromFile(){
    ifstream fin_lan(LAN_FILE,ios::in);
    ifstream fin_band(BANDWIDTH_FILE,ios::in);
    if(fin_lan.fail()){  
    	printf("lantency file open failed\n");     
        return false;
    }else if(fin_band.fail()){
    	printf("bandwidth file open failed\n");
    	return false;
    }
    else{
    
    //init lantencyMatrix
	while(!fin_lan.eof())
	{
		string str;
		getline(fin_lan,str);
		//cout<<str<<endl;
		istringstream is(str);
		vector<double> tmp;
		double i;
		while(is>>i) tmp.push_back(i);
		lantencyMatrix.push_back(tmp);
	}
	fin_lan.close();

     //init bandwidthMatrix
    while(!fin_band.eof())
	{
		string str;
		getline(fin_band,str);
		istringstream is(str);
		std::vector<double> tmp;
		double i;
		while(is >> i) tmp.push_back(i);		
		bandwidthMatrix.push_back(tmp);
	}
		fin_band.close();

	 //    for( auto i:lantencyMatrix)
		// {
		// 	for(auto j:i)
		// 	{
  //               	cout<<j;
		//         	cout<<" ";
  //          		 }
		// 	cout<<endl;
  //       }   
        	return true;     
    }

}


bool EmpericalStrategy::initDefault(const Numa_node* nodeInfos,const int numOfNode){
    
    return false;
}

void EmpericalStrategy::calculateAffinity(vector<Decision> &decision){
    
    return ;
}
