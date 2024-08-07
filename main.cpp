//Written by Miles Brown
#include<iostream>
#include<fstream>
#include "nextfit.hpp"
using namespace std;

int main(){
    NextFit NextFit;
    ifstream input;
    string base;
    string displacement;
    string size;

    cout << "This program simulates a modified Next Fit Allocation.\n";
    cout << "Given an input file of bases and displacements for memory blocks, plus an input file of process sizes,\n";
    cout << "the program will allocate the processes to memory using a modified Next Fit algorithm.\n";
    cout << endl;

    //Open input file with base + displacement values
    input.open("23F_COP4610_Project2_InputFileBaseDisp.txt");
    if(!input.is_open())
        cout << "Failed to open file" << endl;
    
    while(input >> base >> displacement)
        NextFit.AddSlot(base, displacement);

    input.close();
    //Open input file with process size value
    input.open("23F_COP4610_Project2_InputFileProc.txt");
    if(!input.is_open())
        cout << "Failed to open file" << endl;

    while(input >> size)
        NextFit.AddProcess(size);
    cout << "These are the starting values: \n";
    cout << "\n";
    NextFit.PrintSlotMap();
    NextFit.PrintProcesses();
    NextFit.AddProcess();

    return 0;
}