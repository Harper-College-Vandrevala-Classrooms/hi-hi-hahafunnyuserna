#include <iostream>
#include <string>

using namespace std;

int strcmp_case_insensitive(string fullOne, string fullTwo, int max)
{
    string one = "";
    string two = "";

    for (int i = 0; i < fullOne.length(); i++)
    {
        if (fullOne[i] != ' ')
        {
            one += fullOne[i];
        }
    }

    for (int i = 0; i < fullTwo.length(); i++)
    {
        if (fullTwo[i] != ' ')
        {
            two += fullTwo[i];
        }
    }

    if (max < 1)
    {
        return -5;
    } else if ((max > one.length()) || (max > two.length())) {
        return 5;
    }

    if (one.length() < two.length())
    {
        return -1;
    } else if (one.length() > two.length()) {
        return 1;
    } else {
        int oneTotal = 0;
        int twoTotal = 0;

        for (int i = 0; i < max; i++)
        {
            int ayy = int(toupper(one[i]));
            oneTotal = oneTotal + ayy;
            int bee = int(toupper(two[i]));
            twoTotal = twoTotal + bee;
        }

        if (oneTotal < twoTotal)
        {
            return -1;
        } else if (oneTotal > twoTotal)
        {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    string oneString, twoString;
    int maximum;

    cout << "Please enter two strings:\n";
    getline(cin, oneString);
    getline(cin, twoString);
    cout << "Please enter the maximum amount of characters to search:\n";
    cin >> maximum;

    string oneTrunc(oneString, 0, maximum);
    string twoTrunc(twoString, 0, maximum);

    int result = strcmp_case_insensitive(oneString, twoString, maximum);

    if (result == -5)
    {
        cout << "ERROR: Please enter a positive number.\n\n";
    } else if (result == 5) {
        cout << "ERROR: Please enter an integer less than the length of either string.\n\n";
    } else {
        cout << "The comparison of the two strings is " << result << ".\n";
    } 

}