#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void read() {
    gROOT->LoadMacro("readgentree.C");
    gROOT->ProcessLine("readgentree t");
    auto start = high_resolution_clock::now();
    gROOT->ProcessLine("t.Loop(100)");
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Execution time: " << duration.count() << " ms" << endl;
}
