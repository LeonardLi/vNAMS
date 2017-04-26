#include "Nuiod.h"
#include "SimpleStrategy.h"
#include "EmpericalStrategy.h"
#include <numa.h>
#include <sys/time.h>
#include <sys/types.h>


using namespace std;

int main(int argc, char* argv[])
{
	if(numa_available() < 0){
    	fprintf(stderr, "System does not support NUMA API!\n");
    	exit(1);
    }

    int ret = 0;
     int numa_number = numa_max_node() + 1;	
     int cpu_number = sysconf(_SC_NPROCESSORS_ONLN);
	 printf("There are %d cpus, %d numa nodes in your system.\n", cpu_number, numa_number);
	// ScheduleStrategy *strategy = new SimpleStrategy;
	EmpericalStrategy *strategy = new EmpericalStrategy;
	Nuiod nuiod(numa_number, cpu_number, "qemu:///system", strategy);	
	nuiod.start();
	delete strategy;

	exit(0);
}
