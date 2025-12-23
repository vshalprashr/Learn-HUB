#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
	
	int nodeCount, edgeCount, startingNode;
	
	cin >> nodeCount >> edgeCount >> startingNode;

	vector<vector<bool>> edges(nodeCount, vector<bool>(nodeCount, false));

	for (int i = 0 ; i < edgeCount ; i++) {
		int left, right;

		cin >> left >> right;

		edges[left][right] = true;
		edges[right][left] = true;
	}

	int totalVisited = 0;
	int timeCtr = 0;

	vector<bool> visited(nodeCount, false);

	queue<int> visiting;
	visiting.push(startingNode);
	visiting.push(-1);

	visited[startingNode] = true;

	while (!visiting.empty()) {
		int curr = visiting.front();
		visiting.pop();


		if (curr == -1) {
			timeCtr++;

			if (!visiting.empty()) {
				visiting.push(-1);
			}

			continue;
		}

		for (int i=0 ; i < nodeCount ; i++) {
			if (edges[curr][i] == true) {
				if (!visited[i]) {
					visiting.push(i);
					visited[i] = true;
				}
			}
		}
	}

	cout << "Resultant time to burn: " << timeCtr << "\n";

	return 0;
}