#include"direct_graph.h"
#include<stack>
void INORDER_DFS(direct_graph& graph, std::vector<std::string>& order,std::vector<std::string> & result);
void S_DFS(direct_graph& graph, std::vector<std::string>& result);
direct_graph STRONGLY_CONNECTED_COMPONENTS(direct_graph &graph,std::vector<std::string>& R) {
	auto G = graph.reverse();
	std::vector<std::string> result;
	std::vector<std::string> order;
	S_DFS(graph, result);
	for (auto it = result.rbegin(); it != result.rend(); it++)
	{
		order.push_back(*it);
	}
	INORDER_DFS(G, order,R);
	return G;
}
void PRINT_STRONGLY_CONNECTED_COMPONENTS(direct_graph &G, std::vector<std::string>& R) {
	std::vector<std::string> order;
	for (auto it = R.begin(); it != R.end(); it++)
	{
		order.push_back(*it);
	}
	int i = 0;
	while (i != R.size())
	{
		std::stack<std::shared_ptr<vertex>> s;
		auto x = G[order[i]];
		while (x)
		{
			s.push(x);
			x = x->parent;
			i++;
	   }
		while (!s.empty())
		{
			std::cout << s.top()->name << " ";
			s.pop();
		}
		std::cout<< std::endl;
	}
}
