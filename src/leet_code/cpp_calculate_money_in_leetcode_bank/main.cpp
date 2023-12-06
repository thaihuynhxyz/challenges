#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int w = n / 7;
        int ans = w * (w - 1) / 2 * 7 + w * 28;
        int lastW = n % 7;
        if (lastW) {
            ans += (lastW * (lastW + 1) / 2 + lastW * w);
        }
        return ans;
    }
};

TEST_CASE("Calculate Money in Leetcode Bank") {
  SECTION("Test case 1") {
    REQUIRE(Solution().totalMoney(4) == 10);
  }
  SECTION("Test case 2") {
    REQUIRE(Solution().totalMoney(10) == 37);
  }
  SECTION("Test case 3") {
    REQUIRE(Solution().totalMoney(20) == 96);
  }
}

int main(int argc, char *argv[]) {
  // global setup...

  int result = Catch::Session().run(argc, argv);

  // global clean-up...
  return result;
}