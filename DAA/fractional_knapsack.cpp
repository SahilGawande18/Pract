#include<iostream>
#include<algorithm>
using namespace std;


struct Item 
{
    int profit;
    int weight;
};


bool compare(Item a,Item b)
{
    return (double)a.profit/a.weight> (double)b.profit/b.weight;
}

double knapsack(int capacity,Item arr[],int n)
{
    double total=0.0;
    sort(arr,arr+n,compare);
    
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight<capacity)
        {
            total+=arr[i].profit;
            capacity-=arr[i].weight;
        }
        
        else
        {
            total+=arr[i].profit* ((double) capacity/arr[i].weight);
        }
        
    }
    return total;
}

int main()
{
    int n,capacity;
    cout<<"Enter total number and caoacity:";
    cin>>n>>capacity;
    
    Item items[n];
    
    
    for(int i=0;i<n;i++)
    {
        cin>>items[i].profit>>items[i].weight;
    }
    
    cout<<knapsack(capacity,items,n);
}