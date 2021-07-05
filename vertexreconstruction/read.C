#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void read() {
    gROOT->LoadMacro("readvtx2tree.C");
    gROOT->ProcessLine("readvtx2tree t");
    auto start = high_resolution_clock::now();
    gROOT->ProcessLine("t.Loop()");
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "\n************************************\nExecution time: " << duration.count() << " ms" << endl;
}
