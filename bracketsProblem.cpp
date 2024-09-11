#include "Stack.h"
#include <string>
#include <vector>
using namespace std;
int main(void)
{
    string lefty = "([{";
    string righty = ")]}";
    string test1 = "((((([])))))[][][]))))";
    vector<char> v(test1.begin(), test1.end());
    Stack *l1 = new Stack();
    for (auto i = v.begin(); i != v.end(); i++)
    {
        int index = lefty.find(*i);
        if (index != -1)
            l1->push(*i);
        else
        {
            try
            {
                if (lefty.find(l1->pop()) == righty.find(*i))
                {
                    continue;
                }
                else
                {
                    cout << "Failed!";
                    return -1;
                }
            }
            catch (const char *msg)
            {
                cout << "Failed!";
                return -1;
            }
        }
    }
    if (l1->getSize() != 0)
    {
        cout << "Failed!";
        return -1;
    }
    cout << "Passed!";
}
