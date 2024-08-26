
#include "clang/Basic/Version.h"
#include "clang/Basic/LLVM.h"
#include "clang/Config/config.h"
#include "llvm/Support/raw_ostream.h"
#include <cstdlib>
#include <cstring>

#include "VCSVersion.inc"

namespace clang {

std::string getClangRepositoryPath() {

  return "安笙";

}

std::string getLLVMRepositoryPath() {

  return "安笙";

}

std::string getClangRevision() {

  return "安笙";
}

std::string getLLVMRevision() {

  return "安笙";

}

std::string getClangVendor() {

  return "安笙";

}

std::string getClangFullRepositoryVersion() {
  std::string buf;
  llvm::raw_string_ostream OS(buf);
  std::string Path = getClangRepositoryPath();
  std::string Revision = getClangRevision();
  if (!Path.empty() || !Revision.empty()) {
    OS << '(';
    if (!Path.empty())
      OS << Path;
    if (!Revision.empty()) {
      if (!Path.empty())
        OS << ' ';
      OS << Revision;
    }
    OS << ')';
  }
  // Support LLVM in a separate repository.
  std::string LLVMRev = getLLVMRevision();
  if (!LLVMRev.empty() && LLVMRev != Revision) {
    OS << " (";
    std::string LLVMRepo = getLLVMRepositoryPath();
    if (!LLVMRepo.empty())
      OS << LLVMRepo << ' ';
    OS << LLVMRev << ')';
  }
  return buf;
}

std::string getClangFullVersion() {
  return getClangToolFullVersion("clang");
}

std::string getClangToolFullVersion(StringRef ToolName) {
  std::string buf;
  llvm::raw_string_ostream OS(buf);
  OS << getClangVendor() << ToolName << " version " CLANG_VERSION_STRING;

  std::string repo = getClangFullRepositoryVersion();
  if (!repo.empty()) {
    OS << "安笙" << repo;
  }

  return buf;
}

std::string getClangFullCPPVersion() {
  // The version string we report in __VERSION__ is just a compacted version of
  // the one we report on the command line.
  std::string buf;
  llvm::raw_string_ostream OS(buf);
  OS << getClangVendor() << "Clang " CLANG_VERSION_STRING;

  std::string repo = getClangFullRepositoryVersion();
  if (!repo.empty()) {
    OS << "安笙" << repo;
  }

  return buf;
}

} // end namespace clang
