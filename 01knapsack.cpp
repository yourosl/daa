#include<iostream>
using namespace std;
void knapSack(int W, int weight[], int value[], int n)
{   
    
    //  2-d array
    int a[n + 1][W + 1];

    // fill first row with all value zero
    for (int i = 0; i <= W; i++)
    {
        a[0][i] = 0;
    }

    // fill first col with all value zero
    for (int i = 0; i <= n; i++)
    {
        a[i][0] = 0;
    }

    //fill rest of the array with following logic
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(weight[i-1] > j)
                a[i][j] = a[i-1][j];
            else 
                a[i][j] = max(value[i-1] + a[i-1][j - weight[i-1]], a[i-1][j]);    
        }
    }
    cout<<"Printing Matrix :"<<endl;
    //printing array
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j< W+1; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"The Maximum Profit of knapsack is: "<<a[n][W];

    
}
int main()
{
    // Enter the numbers of items you want
    int n ;
    cout<<"Enter the numbers of items"<<endl;
    cin>>n;


    //Enter the capacity of knapsack  
    int W ;
    cout<<"Enter the Capacity of Knapsack"<<endl;
    cin>>W;

    // Enters the values 
    int value[n];
    cout<<"Enter the values"<<endl;
    for (int i=0;i<n;i++){
        cin>>value[i];

    }

    // Enter the weights
    int weight[n];
    cout<<"Enter the weights"<<endl;
    for (int i=0;i<n;i++){
        cin>>weight[i];

    }
    
    
    knapSack(W, weight, value, n);

    return 0;
}
