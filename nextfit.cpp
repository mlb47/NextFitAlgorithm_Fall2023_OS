//Written by Miles Brown
#include "nextfit.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

NextFit::NextFit(){
    slot.base = 0;
    slot.displacement = 0;
    slots.push_back(slot);
    process.name = 64;
    process.size = 0;
    processes.push_back(process);
}

NextFit::~NextFit(){
    for(auto& e : slots)
        slots.pop_back();
    for(auto& e: processes)
        processes.pop_back();
}

void NextFit::AddSlot(string base, string displacement){
    int baseInt = stoi(base);
    int displacementInt = stoi(displacement);

    slot.base = baseInt;
    slot.displacement = displacementInt;
    slots.push_back(slot);
}

void NextFit::AddProcess(string size){
    int sizeInt = stoi(size);

    process.size = sizeInt;
    process.name++;
    processes.push_back(process);
}

void NextFit::PrintSlotMap(){
    cout << "Current Slot Map:\n";
    for(int i = 1; i < slots.size(); ++i)
        cout << left << setw(6) << slots.at(i).base << "\t";
    cout << "\n";
    for(int i = 1; i < slots.size(); ++i)
        cout << left << setw(6) << slots.at(i).displacement << "\t";
    cout << "\n";
    cout << "\n";
}

void NextFit::PrintProcesses(){
    cout << "Processes:\n";
    for(int i = 1; i < processes.size(); ++i)
        cout << left << setw(6) << char(processes.at(i).name) << "\t";
    cout << "\n";
    for(int i = 1; i < processes.size(); ++i)
        cout << left << setw(6) << processes.at(i).size << "\t";
    cout << "\n";
    cout << "\n";
}

void NextFit::PrintSuccess(int index, int currPos){
    cout << "Taking up Process " << char(processes.at(index).name) << "\n";
    cout << "Slot Assignment Successful. " << char(processes.at(index).name) << " - Base Location: " << slots.at(currPos).base << "\n";
}

void NextFit::PrintFail(int index){
    cout << "Taking up Process " << char(processes.at(index).name) << "\n";
    cout << "Slot assignment NOT successful for " << char(processes.at(index).name) << "\n";
}

void NextFit::AddProcess(){
    int currentPos = 0;
    int lastSuccess = 0;
    for(int i = 1; i < processes.size(); ++i){
        //Condition: Process can be added
        if(CanAddProcess(processes.at(i).size, currentPos)){
            PrintSuccess(i, currentPos);
            //If slot is full, remove it 
            if(slots.at(currentPos).displacement == processes.at(i).size)
                   slots.erase(slots.begin() + currentPos);
            //Subtract process size from displacement, add process size to base
            else{
                slots.at(currentPos).displacement-=processes.at(i).size;
                slots.at(currentPos).base+=processes.at(i).size;
            }
            PrintSlotMap();
            lastSuccess = i;
        }
        //Condition: Process can not be added to current slot 
        else{
            //If ran through all the slots and can't allocate space, go back to last successful slot and skip to next process
            if(currentPos == slots.size()-1)
            {
                PrintFail(i);
                PrintSlotMap();
                ++i;
                currentPos = lastSuccess-1;
            }
            //Return to process, continue to next slot position
            --i;
            currentPos++;
        }
    }
    cout << "Slot assignment complete!\n";
}

bool NextFit::CanAddProcess(int size, int pos){
    if(slots.at(pos).displacement >= size)
        return true;
    return false;
}