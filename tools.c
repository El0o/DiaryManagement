#include "tools.h"

int powint(int x, int n) {
    int i, ans=1;
    for(i=1; i<=n; i++) ans = ans*x;
    return ans;
}
