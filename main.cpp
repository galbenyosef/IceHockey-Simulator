#include "simIce_Hockey.h"

using namespace std;

int main(int argc,char* argv[])
{
	//general check
	if (argc!=3)
	{
	  cout << "Invalid arguments!" << endl;
	  exit(0);
	}
	char* config_file=argv[1];
	char* init_file=argv[2];

	simIceHockey obj(config_file,init_file);
	cout << obj.start() << endl;
	obj.print();
	getchar();
}