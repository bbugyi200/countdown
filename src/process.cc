#include <fstream>

#include <iostream>
#include <unistd.h>
#include <signal.h>

#include <gutils.h>
#include <process.h>

static const char *pid_fname = "/run/user/1000/countdown/pid";

process::OldProcessStillAlive::OldProcessStillAlive(const int pid_) { pid = pid_; }

void process::create_pid() {
    int pid = getpid();
    std::ifstream ifile(pid_fname);
    if (ifile.good()) {
        int old_pid;
        ifile >> old_pid;
        ifile.close();

        if (kill(old_pid, 0) == 0) {
            throw process::OldProcessStillAlive(old_pid);
        }
    }

    ifile.close();
    std::ofstream ofile(pid_fname);
    ofile << pid;
    ofile.close();
}
