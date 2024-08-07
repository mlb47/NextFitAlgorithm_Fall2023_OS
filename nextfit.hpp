//Written by Miles Brown
#ifndef NEXTFIT_H
#define NEXTFIT_H
#include <vector>
#include <string>
#include "slotpair.hpp"
#include "processpair.hpp"

class NextFit{
    public:
        NextFit();
        ~NextFit();
        void AddSlot(std::string base, std::string displacement);
        void AddProcess(std::string size);
        void PrintSlotMap();
        void PrintProcesses();
        void PrintSuccess(int index, int currPos);
        void PrintFail(int index);
        void AddProcess();
        bool CanAddProcess(int size, int pos);
    private:
        SlotPair slot;
        ProcessPair process;
        std::vector<SlotPair> slots;
        std::vector<ProcessPair> processes;
};
#endif