#include <processes.h>
#include <process.h>
#include <iostream>

int main(int argc, char*argv[])
{
    KSysGuard::Processes processes;
    QList<KSysGuard::Process*> processlist = processes.getAllProcesses();
    foreach( KSysGuard::Process * process, processlist) {
        std::cout << "Process with pid " << process->pid() << " is called " << process->name().toStdString() << std::endl;
    }
    return 0;
}
