#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <math.h>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// Return the system's CPU
Processor& System::Cpu() { 
    static Processor cpu;
    return cpu;}

// Return a container composed of the system's processes
vector<Process>& System::Processes() {
    processes.clear();
    for (int pid : LinuxParser::Pids()) {
        Process process(pid);
        processes.emplace_back(process);
    }
    std::sort(processes.begin(), processes.end());
    return processes;
}

// Return the system's kernel identifier (string)
std::string System::Kernel() {
  kernel = LinuxParser::Kernel();
  return kernel;
}

// Return the system's memory utilization
float System::MemoryUtilization() {
  mem_utilization = LinuxParser::MemoryUtilization();
  return mem_utilization;
}

// Return the operating system name
std::string System::OperatingSystem() {
  operating_system_ = LinuxParser::OperatingSystem();
  return operating_system_;
}

// Return the number of processes actively running on the system
int System::RunningProcesses() {
  procs_running = LinuxParser::RunningProcesses();
  return procs_running;
}

// Return the total number of processes on the system
int System::TotalProcesses() {
  total_processes = LinuxParser::TotalProcesses();
  return total_processes;
}

// Return the number of seconds since the system started running
long System::UpTime() {
    uptime = LinuxParser::UpTime();
    return uptime;
}
