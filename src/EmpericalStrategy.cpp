#include "EmpericalStrategy.h"
using namespace std;
#define LAN_FILE "/etc/lantency.txt"
#define BANDWIDTH_FILE "/etc/bandwidth.txt"

vector<Decision> EmpericalStrategy::schedule(const map<int, VM_info> &vmInfoMap, 
				const vector<double> &physicalCpuUsage, const Numa_node* nodeInfos,
				const int numOfNode, const int NIC_NODE_ID)
{ 
    //init data
    if(!initFromFile()){
        printf("info files does not exist! Please check /etc/lantency.txt & /etc/bandwidth.txt \n");
        printf("Using System defalut info \n");
        initDefault(nodeInfos, numOfNode);
    }
    vector<Decision> decisions;
    calculateAffinity(decisions); 
    return decisions;
}


bool EmpericalStrategy::initFromFile(){
    ifstream fin_lan(LAN_FILE,ios::in);
    ifstream fin_band(BANDWIDTH_FILE);
    if(fin_lan.fail()|| fin_band.fail()){       
        return false;
    }else{
    
    //init lantencyMatrix
	while(!fin_lan.eof())
	{
		string str;
		getline(in,str);
		//cout<<str<<endl;
		istringstream is(str);
		vector<double> tmp;
		while(!is.eof())
		{
			double i;
			is>>i;
			//cout<<i<<endl;
			tmp.push_back(i);
		}
		lantencyMatrix.push_back(tmp);
	}
     //init bandwidthMatrix
    while(!fin_band.eof())
	{
		string str;
		getline(in,str);
		//cout<<str<<endl;
		istringstream is(str);
		std::vector<double> tmp;
		while(!is.eof())
		{
			double i;
			is>>i;
			//cout<<i<<endl;
			tmp.push_back(i);
		}
		bandwidthMatrix.push_back(tmp);
	}


	    for( auto i:lantencyMatrix)
		{
			for(auto j:i)
			{
                cout<<j;
		        cout<<" ";
            }
		cout<<endl;
        }
        return true;
    }
}


bool EmpericalStrategy::initDefault(){
    return false;
}

void Empericalstrategy::calculateAffinity(vector<Decision>& decision){
    return 0;
}