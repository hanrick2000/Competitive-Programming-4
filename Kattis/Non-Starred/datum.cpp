#include <bits/stdc++.h>
using namespace std;
const char* name[] =
{
    "Monday", "Tuesday", "Wednesday", "Thursday",
    "Friday", "Saturday", "Sunday"
};
 
const char* weekday(int y, int m, int d)
{
    // 1月2月看作是前一年的13月14月，方便統計。
    if (m == 1 || m == 2) { m += 12; y--; }
 
    // 在1752/9/3之前，閏年機制不同。
    int w = 0;
    if ((y < 1752) ||
        (y == 1752 && m < 9) ||
        (y == 1752 && m == 9 && d < 3))
        w = (d + 2*m + 3*(m+1)/5 + y + y/4 + 5) % 7;
    else
        w = (d + 2*m + 3*(m+1)/5 +
                y + y/4 - y/100 + y/400) % 7;
 
    return name[w];
}
int main() {
    int d, m; cin >> d >> m;
    cout << weekday(2009, m, d) << '\n';
}
