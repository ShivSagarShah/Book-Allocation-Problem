/*
You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. 
Every student is assigned to read some consecutive books. 
The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Input Format
First line contains integer t as number of test cases. Next t lines contains two lines. 
For each test case, 1st line contains two integers n and m which represents the number of books and students and 
2nd line contains n space separated integers which represents the number of pages of n books in ascending order.

Constraints
1 < t < 50
1< n < 100
1< m <= 50
1 <= Ai <= 1000

Output Format
Print the maximum number of pages that can be assigned to students.

Sample Input
1
4 2
12 34 67 90

Sample Output
113 

Explanation
1st students : 12 , 34, 67 (total = 113)
2nd students : 90 (total = 90)
Print max(113, 90)
*/
//basically iss question mein humko maximum books deni hai student ko aur capacity minimum rakhni hai jitni ho sake.
//jo maximum book hum de sakte hai with minimum capacity vo maximum pages waala hoga and maximum capacity will be sum of all pages, to inhi range ke beech mein humara ans aayega
/*
example lelo: 
1
4 2
10 20 30 40
toh range hai 40-100, binary search laga ke capacity aayegi 60
1 student: 10+20+30 = 60(maximum book diya aur capacity ko minimum rakha)
2 student: 40
to ans 60 aa gaya
*/

// if kisi ques me aisa aaya ki maximise ya minimise karo ya search or likha ho ki array is sorted, then we use binary search. 

#include<iostream>
using namespace std;

bool isvalid(int *books, int n, int students, int capacity)
{
    int s=1;
    int currentpages=0;
    for (int i = 0; i < n; i++)
    {
        if ((currentpages + books[i]) > capacity)
        {
            s++;
            currentpages = books[i];
            if (s>students)
            {
                return false;
            }
        }
        else
        {
            currentpages += books[i];
        }
    }
    return true;
}

int book_allocation(int *a, int n, int m)
{
    int totalpages = 0;
    int s=0,e;
    for (int i = 0; i < n; i++)
    {
        totalpages += a[i];
        // this 
        // s = max(s, a[i])
    }
    // or this
    s = a[n-1];
    e = totalpages;
    int finalans;
    while (s<=e)
    {
        int mid = (s+e)/2;
        if (isvalid(a,n,m,mid))
        {
            finalans = mid;
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    }
    return finalans;
}

int main()
{
    int t, arr[105];
    cin>>t;
    while (t--)
    {
        int n, m; // n is number of books and m is number of students
        cin>>n>>m;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int x = book_allocation(arr, n, m);
        cout<<x<<endl;
    }
    return 0;
}
