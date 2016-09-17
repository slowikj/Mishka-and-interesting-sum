#include "TaskSolver.h"

using namespace std;

int main ()
{
	ios::sync_with_stdio(false);

	TaskSolver ts;

	for(const int& res: ts.Results())
		cout << res << endl;

	return 0;
}

