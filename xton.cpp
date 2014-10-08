// Course 1 homework
// Calculate 2 raised to n
// Pitis Daniel
// Algorithm based on http://www.infoarena.ro/lucrul-cu-nr-mari
#include <cstdio>
#include <cstring>

#define LG_MAX 1000 + 1 // Max length of the big number
typedef int BigNumber[LG_MAX];

// I start with 2^1 so i need the BigNumber to be initialized with 1
// So it can be neutral element
void InitializeNumber(BigNumber x)
{
    x[0] = 1; // x[0] contains the number of decimals
    x[1] = 1;
}

// The algorithm is the following:
// I iterate trough the BigNumber from left to right
// I multiply the last number with the multiplier
// I take care to add the "transport" at the end
void Multiply(BigNumber pow, int Multiplier)
{
    int Transport = 0;

    for(int i=1; i<=pow[0]; i++)
    {
        pow[i] = pow[i]*Multiplier+Transport;
        Transport = pow[i]/10;
        pow[i] = pow[i]%10;
    }

    while(Transport) // Don't forget to add the "transport"
    {
        pow[++pow[0]] = Transport%10;
        Transport /= 10;
    }
}

void PrintBigNumber(BigNumber x)
{
    // Print the number from right to left
    for(int i=x[0]; i>=1; i--)
        printf("%d", x[i]);
}

int main()
{
    freopen("bignumber.in","r",stdin);
    freopen("bignumber.out","w",stdout);

    int Raise,NumToRaise;
    BigNumber a;
    InitializeNumber(a);

    scanf("%d", &NumToRaise);
    scanf("%d", &Raise);

    for(int i=1; i<=Raise; i++)
    {
        Multiply(a,NumToRaise);
    }

    PrintBigNumber(a);

    return 0;
}
