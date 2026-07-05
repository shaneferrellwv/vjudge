#include <cmath>
#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int A;  // number of candies in bag A
    int B;  // number of candies in bag B
    int K;
    cin >> A >> B >> K;
    
    deque<int> bagA(A);
    for (int i = 0; i < A; i++)
    {
        cin >> bagA[i];
    }
    
    deque<int> bagB(B);
    for (int i = 0; i < B; i++)
    {
        cin >> bagB[i];
    }
    
    sort(bagA.begin(), bagA.end());
    sort(bagB.begin(), bagB.end());
    
    priority_queue<int> pq;
    for (int a = 0; a < A; a++)
    {
        for (int b = 0; b < B; b++)
        {
            int sum = bagA[a] + bagB[b];
            if (pq.size() < K)
            {
                pq.push(sum);
            }
            else if (sum < pq.top())
            {
                pq.pop();
                pq.push(sum);
            }
        }
    }
    
    cout << pq.top();
    
    
    return 0;
}
