/*
  ================================================
   ATM System - HEM Bank
   printBanner() - () border style
  ================================================
*/

#include <iostream>
#include <string>
using namespace std;

void printBanner() {
    cout << "\n";
    cout << "  (==========================================)\n";
    cout << "  (                                          )\n";
    cout << "  (   #  #  ####  #   #                      )\n";
    cout << "  (   #  #  #     ## ##                      )\n";
    cout << "  (   ####  ###   # # #                      )\n";
    cout << "  (   #  #  #     #   #                      )\n";
    cout << "  (   #  #  ####  #   #                      )\n";
    cout << "  (                                          )\n";
    cout << "  (      AUTOMATED TELLER MACHINE            )\n";
    cout << "  (        Secure * Reliable * Fast          )\n";
    cout << "  (                                          )\n";
    cout << "  (==========================================)\n";
    cout << "  (                                          )\n";
    cout << "  (   [1] Withdraw      [2] Deposit          )\n";
    cout << "  (   [3] Balance       [4] Transfer         )\n";
    cout << "  (   [5] Change PIN    [0] Exit             )\n";
    cout << "  (                                          )\n";
    cout << "  (==========================================)\n";
    cout << "  (  Enter your choice: _                    )\n";
    cout << "  (==========================================)\n";
    cout << "\n";
}

int main() {
    printBanner();
    return 0;
}
