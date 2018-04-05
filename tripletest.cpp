#include <cstdio>
#include <cstring>
#include <llvm/MC/MCSubtargetInfo.h>
int main()
{
        std::string TripleName = llvm::sys::getDefaultTargetTriple();
	std::string ProTripleName = llvm::sys::getProcessTriple();
	printf("Default Target Triple %s\nProcess triple %s\n", TripleName.c_str(), ProTripleName.c_str());
}
