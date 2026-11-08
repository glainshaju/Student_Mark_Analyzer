#include<iostream>
using namespace std;
    void readMarks(int marks[] , int n)
    {
        for(int i=0; i<n; i++)
        {
            cout<<"Student "<<i+1<<": ";
            cin>>marks[i];
        }
    }
    int findTotal(int marks[],int n)
    {
        int total=0;
        for(int i=0; i<n; i++)
        {
            total += marks[i];
        }
        return total;
    }
    double findAverage(int marks[],int n)
    {
        double total = findTotal(marks, n);
        return total / n;
    }
    int findHighest(int marks[], int n)
    {
        int highest = marks[0];
        for(int i = 1; i < n; i++)
        {
            if(marks[i] > highest)
            {
                highest = marks[i];
            }

        }
        return highest;
    }
    int findLowest(int marks[], int n)
    {
        int lowest = marks[0];
        for(int i = 1; i < n; i++)
        {
            if(marks[i] < lowest)
            {
                lowest = marks[i];
            }
        }
        return lowest;
    }
    int countPassed(int marks[], int n)
    {
        int passed = 0;
        for(int i = 0; i < n; i++)
        {
            if(marks[i] >= 40)
            {
                passed++;
            }
        }
        return passed;
    }
    void printReport(int marks[], int n)
    {
        int total = findTotal(marks, n);
        double average = findAverage(marks, n);
        int highest = findHighest(marks, n);
        int lowest = findLowest(marks, n);
        int passed = countPassed(marks, n);
        int failed = n - passed;

        cout << "\n===== STUDENT REPORT =====\n";
        cout << "Total: " << total << endl;
        cout << "Average: " << average << endl;
        cout << "Highest: " << highest << endl;
        cout << "Lowest: " << lowest << endl;
        cout << "Passed: " << passed << endl;
        cout << "Failed: " << failed << endl;
    }
    int main()
    {
        int marks[100];
        int n;
        char choice;
        do
        {
            cout<<"Enter the number of students: ";
            cin>>n;
            while(n<1 || n>100)
            {
                cout<<" Invalid number.";
                cin>>n;
            }
            cout<<"Enter The Mark of ";
            readMarks(marks, n);
            printReport(marks, n);
            cout << "Do you want to analyze again? (y/n): ";
            cin >> choice;
        } while(choice == 'y' || choice == 'Y');
        return 0;
    }