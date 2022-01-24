#include <yvals.h>
#if (_MSC_VER >= 1600)
#define __STDC_UTF_16__
#endif
#include "mex.h"
#include <iostream>
#include <engine.h>

#pragma comment(lib, "libmx.lib")
#pragma comment(lib, "libmex.lib")
#pragma comment(lib, "libeng.lib")

using namespace std;

int main() {
	Engine *ep;
	ep = engOpen(NULL);
	if (ep == NULL) {
		cout << "Error: Not Found" << endl;
		exit(1);
	}

	double step[100];
	for (int i = 0; i < 100; ++i) {
		step[i] = i / 10.0;
	}
	mxArray *A;
	A = mxCreateDoubleMatrix(1, 100, mxREAL);
	memcpy((void *)mxGetPr(A), (void *)step, sizeof(double) * 100);
	engPutVariable(ep, "x", A);
	engEvalString(ep, "y = sin(x);");
	engEvalString(ep, "plot(x,y)");

	system("pause");

	//clean operation
	mxDestroyArray(A);
	engEvalString(ep, "close;");

	//close engine
	engClose(ep);
	return 0;
}