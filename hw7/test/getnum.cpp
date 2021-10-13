#include <cstdlib>
#include <ctime>
#include <fstream>
#define N 100
using namespace std;

int main()
{
	srand(time(NULL));
	fstream file;
	file.open("input.txt", ios::out);
	for (int i=0;i<N;i++)
	{
		int n=rand();
		file << n << endl;
	}
	file.close();

	return 0;
}
