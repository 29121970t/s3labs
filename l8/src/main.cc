#include <consoleUtils.hh>
#include <l8/include/list.hh>
#include <memory>
#include <vector>
using namespace std;
class PpAp {
   private:
    /* data */
   public:
    PpAp(size_t i);
    ~PpAp();
};

PpAp::PpAp(size_t i) {}

PpAp::~PpAp() {}

int main(void) {
    CircleList<PpAp> f;

    return 0;
}
