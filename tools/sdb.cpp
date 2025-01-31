
#include <iostream>
#include <unistd.h>
#include <string_view>

#include <sys/types.h>
#include <sys/wait.h>

#include <libsdb/libsdb.hpp>

namespace {
  auto attach(int argc, const char** argv) -> pid_t {

    pid_t pid { 0 };

    if (argc == 3 && argv[1] == std::string_view("-p")) {

      pid = std::atoi(argv[2]);

      if (pid <= 0) {
        std::cerr << "Invalid pid" << endl;
        return -1;
      }

      if (ptrace(PTRACE_ATTACH, pid, nullptr, nullptr) < 0) {
        std::perror("Could not attach");
        return -1;
      }

    } else {

      const char* program_path { argv[1] };

      if ((pid = fork()) < 0) {
        std::perror("Fork failed");
        return -1;
      }

      if (pid == 0) {

        if (ptrace(PTRACE_TRACEME, 0, nullptr, nullptr) < 0) {
          std::perror("Tracing failed");
          return -1;
        }

        if (execlp(program_path, program_path, nullptr) < 0) {
          std::perror("Exec failed");
          return -1;
        }
      }

    }

    return pid;
  }
}

auto main(int argc, const char** argv) -> int {

  if (argc == 1) {

    std::cerr << "No arguments given" << endl;

    return -1;
  }

  auto pid { attach(argc, argv) };

  int wait_status { 0 };
  int options { 0 };

  if (waitpid(pid, &wait_status, options) < 0) {
    std::perror("Waitpid failed");
  }

  return 0;
}

