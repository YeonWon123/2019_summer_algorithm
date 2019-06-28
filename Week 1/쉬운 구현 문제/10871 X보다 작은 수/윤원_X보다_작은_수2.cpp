#include <cstdio>
using namespace std;
 
int main(void)
{
    int N, X;
    scanf("%d %d", &N, &X);

    for(int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        if(A < X) printf("%d ", A);
    }

}