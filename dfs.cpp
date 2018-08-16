#include <iomanip>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> tuopu;
#define NODES 4
/*  graph:
 *  i    [0   1   2   3]
 *  [0]   0   1   1   0
 *  [1]   1   0   0   1
 *  [2]   1   0   0   1
 *  [3]   0   1   1   0
 *
 * node:      [0]  1   2   3
 * visit:      1   0   0   0
 * father:    -1   0  -1  -1
 *
 * node:       0  [1]  2   3
 * visit:      1   1   0   0
 * father:     -1  0  -1   1
 *
 * node:       0   1   2  [3]
 * visit:      1   1   0   1
 * father:    -1   0   3   1
 *
 * node:       0   1   2  [3]
 * visit:      1   1   1   1
 * father:    -1   0   3   1
 *
 * */

void dfsVisit(vector<vector<int> >&graph, int node, vector<int>&visit,
               vector<int>&father)
{
    int n = graph.size();
    visit[node] = 1;
    //cout<<node<<"-\n";
    cout << "node:" << node << "\n";
    for(int i = 0; i < n; i++) {
	if(i != node && graph[node][i] != 0) {
	    if(visit[i] == 1 && i != father[node])//找到一个环
	    {
		int tmp = node;
		cout<<"cycle: ";
		while(tmp != i)
		{
		    cout<<tmp<<"->";
		    tmp = father[tmp];
		}
		cout<<tmp<<endl;
	    }
	    else if(visit[i] == 0)
	    {
		father[i] = node;
		dfsVisit(graph, i, visit, father);
	    }
	}
	cout << "node: " << node <<" i: " << i;

        cout << "\n";
	for(int j = 0; j < n; j++)
	    cout << " visit: " << visit[j] << ";";

        cout << "\n";
	for(int j = 0; j < n; j++)
	    cout << " father: " << father[j] << " ";

        cout << "\n";
    }
    visit[node] = 2;
    tuopu.push(node);
}

void dfs(vector<vector<int> >&graph)
{
    int n = graph.size();
    vector<int> visit(n, 0); //visit按照算法导论22.3节分为三种状态
    vector<int> father(n, -1);// father[i] 记录遍历过程中i的父节点
    for(int i = 0; i < n; i++)
        if(visit[i] == 0)
            dfsVisit(graph, i, visit, father);
}

int main()
{
    vector<vector<int> > graph;
    int a[NODES] = {0, 1, 1, 0};
    int b[NODES] = {1, 0, 0, 1};
    vector<int> temp0(a, a + NODES);
    vector<int> temp1(b, b + NODES);
    vector<int> temp2(b, b + NODES);
    vector<int> temp3(a, a + NODES);
    graph.push_back(temp0);
    graph.push_back(temp1);
    graph.push_back(temp2);
    graph.push_back(temp3);

    dfs(graph);
}
