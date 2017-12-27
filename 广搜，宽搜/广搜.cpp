#include"grahp.h"
#include<queue>
void BFS(no_direct_graph &graph, const std::string&s) {
	std::queue<std::shared_ptr<s_vertex>> queue;
	auto x = graph[s];
	x->d = 0;
	x->calor = grey;
	queue.push(x);
	while (!queue.empty())
	{
		auto y = queue.front();
		queue.pop();
		for (auto it = y->edge.begin(); it != y->edge.end(); it++) {
			if ((*it)->calor == white)
			{
				(*it)->d = y->d + 1;
				(*it)->parent = y;
				(*it)->calor = grey;
				queue.push(*it);
			}
		}
		y->calor = black;
	}
}