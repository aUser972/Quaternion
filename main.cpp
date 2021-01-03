#include "Quaternion.h"
#include <ctime>

using namespace std;


int main()
{
    //time_t start, end;
    //time(&start);
    Quaternion q1(1.1, 2.1, 3.1, 4.1);
    Quaternion q2(1.2, 2.2, 3.2, 4.2);

    for(int i=0; i<100000000;i++)
    {
        auto q3 = q1 + q2;
        cout << " " <<endl;
    }
    //time(&end);
    //cout << difftime(end, start) <<endl;
    cout << ((float)clock()) / CLOCKS_PER_SEC << endl;

    return 0;
}
