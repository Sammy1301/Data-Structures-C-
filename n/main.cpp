#include <iostream>

using namespace std;
struct estudiante{
    int array[3];
};
int main()
{
    struct estudiante est;
    int n = 30;
   int *prt = est;
    cout << *prt << "\t" << &est << endl;
    return 0;
}
