#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
using namespace std;
string printvec(vector <int> a)
{
    ostringstream oss;
    copy(a.begin(), a.end() - 1, ostream_iterator<int>(oss, " "));
    oss << a.back();
    return oss.str()+"\n";
}
int sumvec(vector <int> a)
{
    int sum = 0;
    for (int i = 0; i < size(a); i++)
        sum += a[i];
    return sum;
}

string gener(vector <int> &a)
{
    if (sumvec(a) == size(a)) { return printvec(a);  }
    else
    {
        if (a[size(a) - 1] == 0) { a[size(a) - 1] = 1; return printvec(a);  }
        else
        {
            a[size(a) - 1] = 0;
            int j = size(a) - 2;
            int flag = 1;
            while (a[j] == 1 && j > 0) {

                if (a[j - 1] == 0)
                {
                    a[j] = 0;
                    a[j - 1] = 1;
                    return printvec(a);
                }
                else {
                    a[j] = 0;
                    a[j - 1] = 1;
                }
                j--;
            }
            if (j > 0)
            {
                a[j] = 1;
                return printvec(a);
            }
            else {
                return printvec(a);
            }

        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector <int> a(n, 0);
    int pow2 = pow(2, n);
    ofstream out("out.txt");
    out << printvec(a);
    for (int u = 0; u < pow2 - 1; u++)
        out << gener(a);
    out.close();
}