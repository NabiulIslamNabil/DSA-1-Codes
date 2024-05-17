#include <iostream>
using namespace std;

int count = 0;

void towerOfHanoi(int n, char from, char aux, char to)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from, to, aux);
    cout << "Move disk " << n << " from " << from
         << " to " << to << endl;
    towerOfHanoi(n - 1, aux, from, to);
    count++;
}

int main()
{
    int N;
    cout<<"Enter the number of disks: ";
    cin>>N;

    towerOfHanoi(N, '1', '2', '3');

    cout<<"Number of Moves: "<<count;
    return 0;
}
