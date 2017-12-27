#include"direct_graph.h"
void S_DFS(direct_graph& graph,std::vector<std::string>& result);
void TOPOLOGICAL_SORT(direct_graph & graph) {
	std::vector<std::string> result;
	S_DFS(graph,result);
	std::cout << "Ò»¸öÍØÆËÅÅÐòÊÇ:";
	for (int i = result.size() - 1; i != -1; i--)
		std::cout << result[i] << " ";
}