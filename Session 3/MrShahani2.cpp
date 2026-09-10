#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    int sum;
    int result;

    cout << " delet mikhad chand adad vared koni? ( 3 ya 5 )";
    cin >> n;
    sum=0;
    if (n==3 || n==5)
    {
        for (int i=0; i<n; i++)
        {
            int adad;
            cout << "adad ha ra vared konid: ";
            cin >> adad;
            sum= adad + sum;
        }
    }
    else
    {
        cout << " 3 ya 5 ra vared kon" << endl;
        return 1;
    }
 
    result = sum / n;
    cout << "result:" << result << endl;
    return 0;
}