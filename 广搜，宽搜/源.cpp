//关于哈希函数，定义写在头文件，实现写在源文件！！！！！！
#include"direct_graph.h"
#include"vertex.h"
#include<iostream>
direct_graph STRONGLY_CONNECTED_COMPONENTS(direct_graph &graph, std::vector<std::string>& R);
void PRINT_STRONGLY_CONNECTED_COMPONENTS(direct_graph &G, std::vector<std::string>& R);
int main() {
	direct_graph graph;
	graph.add_vertex("a");
	graph.add_vertex("b");
	graph.add_vertex("e");
	graph.add_vertex("f");
	graph.add_vertex("g");
	graph.add_vertex("c");
	graph.add_vertex("d");
	graph.add_vertex("h");
	graph.add_edge("a", "b");
	graph.add_edge("b", "e");
	graph.add_edge("e", "a");
	graph.add_edge("b", "f");
	graph.add_edge("e", "f");
	graph.add_edge("b", "c");
	graph.add_edge("f", "g");
	graph.add_edge("g", "f");
	graph.add_edge("c", "d");
	graph.add_edge("d", "c");
	graph.add_edge("c", "g");
	graph.add_edge("g", "h");
	graph.add_edge("d", "h");
	graph.add_edge("h", "h");
	std::vector<std::string> R;
	auto a= STRONGLY_CONNECTED_COMPONENTS(graph, R);
	PRINT_STRONGLY_CONNECTED_COMPONENTS(a , R);
	//for (auto it = R.begin(); it != R.end(); it++)
		//std::cout << *it << " ";
}