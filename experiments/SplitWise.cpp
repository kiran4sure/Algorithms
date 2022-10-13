// C++ program to fin maximum cash flow among a set of persons
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int getMin(vector<float> &arr)
{
	int minInd = 1;
	for (int i=2; i<arr.size(); i++)
		if (arr[i] < arr[minInd])
			minInd = i;
	return minInd;
}

int getMax(vector<float> &arr)
{
	int maxInd = 1;
	for (int i=2; i<arr.size(); i++)
		if (arr[i] > arr[maxInd])
			maxInd = i;
	return maxInd;
}

float minOf2(float x, float y)
{
	return (x<y)? x: y;
}

void minCashFlowRec(vector<float> &amount, map<int, string> &mapping)
{
	int mxCredit = getMax(amount), mxDebit = getMin(amount);

	if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
		return;

	float min = minOf2(-amount[mxDebit], amount[mxCredit]);
	amount[mxCredit] -= min;
	amount[mxDebit] += min;

	cout << mapping[mxDebit] << " pays " << min
	    << " to " << mapping[mxCredit] << endl;

	minCashFlowRec(amount, mapping);
}

void minCashFlow(vector<vector<int>> &graph, map<int, string> &mapping)
{
	vector<float> amount(graph[0].size(), 0);
	
    float total = 0;    
    for(int a = 0; a<graph[0].size(); a++)
    {
        total+=graph[a][0];
    }
    total = total/(graph[0].size() - 1);
    
	for (int p=1; p<graph[0].size(); p++)
	{
	    for (int i=1; i<graph[0].size(); i++)
	    {
		    amount[p] += (graph[i][p] - graph[p][i]);
	    }
	    amount[p] += (graph[p][0] - total);
	}
    
    for(int i=0; i<amount.size(); i++)
    {
        cout << mapping[i] << " --> " << amount[i] << endl;
    }
	minCashFlowRec(amount, mapping);
}

int main()
{                                    //                   kiran   pavan   ratikant  senthil
    map<string, vector<int>> graphs = { {"group",   {0,     0,     0,      0,      0}},
                                        {"kiran",   {50,    0,     20,    50,      0}},
                                        {"pavan",   {100,   100,   0,      0,      0}},
                                        {"ratikant",{0,     10,    70,     0,      0}},
                                        {"senthil", {0,     41,    20,     5,      0}}
                                    };
    
	map<int, string> mapping = {{0,"group"},
	                            {1,"kiran"},
	                            {2,"pavan"},
	                            {3,"ratikant"},
	                            {4,"senthil"},
	};
	
	 vector<vector<int>> graph{ {0,     0,     0,      0,      0},
	                            {50,     0,     20,    50,      0},
        						{100,     100,   0,      0,      0},
        						{0,     10,    70,     0,      0},
        	                    {0,     41,    20,     5,      0},
	};

	// Print the solution
	minCashFlow(graph, mapping);
	return 0;
}

