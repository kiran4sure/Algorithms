#include <iostream>
#include <bits/stdc++.h>

using namespace std;


/*
card shuffle
reveal-cards-in-increasing-order,
this is useful to inter-leave the sorted elements inbetween
*/
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        
        queue<int> q;
        
        //push the array indexes to the queue
        for(int i=0; i<n ; i++)
        {
            q.push(i);
        }
        
        vector<int> ans(n,0);
        std::sort(deck.begin(), deck.end());
        for(int c: deck)
        {
            //assign the sorted element to the array index in queue
            ans[q.front()] = c;
            q.pop();
            
            //pick push back the next array index to the queue to pick up in next iteration
            if(!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};


int main(int argc, const char** argv) 
{
    vector<int> deck{17,13,11,2,3,5,7};
    
    Solution sln;
    vector<int>  ans = sln.deckRevealedIncreasing(deck);
    
    cout << "Input array: " << endl;
    for(int a: deck)
    {
        cout << a << " ";
    }
    cout << endl;
    
    cout << "Reveal cards: " << endl;
    for(int a: ans)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}