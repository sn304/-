#include"graph2.h"
#include"direct_graph.h"
int time = 0;
void DFS_VISIT(std::shared_ptr<vertex> v);
void S_DFS_VISIT(std::shared_ptr<vertex> v, std::vector<std::string>& result);
void INORDER_DFS_VISIT(std::shared_ptr<vertex> v, std::vector<std::string> &result);
void DFS(no_direct_graph& graph,std::vector<std::string> &vertex_name) {
	time = 0;
	for (int i = 0; i != vertex_name.size(); i++)
		if (graph[vertex_name[i]]->calor == white)
			DFS_VISIT(graph[vertex_name[i]]);
}
void DFS(direct_graph& graph, std::vector<std::string> &vertex_name) {
	time = 0;
	for (int i = 0; i != vertex_name.size(); i++)
		if (graph[vertex_name[i]]->calor == white)
			DFS_VISIT(graph[vertex_name[i]]);

}
void S_DFS(direct_graph& graph, std::vector<std::string>& result) {
	time = 0;
	for (int i = 0; i != graph.size(); i++)
		if (graph[graph.get_name(i)]->calor == white)
			S_DFS_VISIT(graph[graph.get_name(i)],result);
}
void S_DFS_VISIT(std::shared_ptr<vertex> v, std::vector<std::string>& result) {
	++time;
	v->s = time;
	v->calor = grey;
	for (auto it = v->edge.begin(); it != v->edge.end(); it++)
	{
		if ((*it)->calor == white)
		{
			(*it)->parent = v;
			S_DFS_VISIT(*it,result);
		}
	}
	v->calor = black;
	++time;
	v->f = time;
	result.push_back(v->name);
}
void DFS_VISIT(std::shared_ptr<vertex> v) {
	++time;
	v->s = time;
	v->calor = grey;
	for (auto it = v->edge.begin(); it != v->edge.end(); it++)
	{
		if ((*it)->calor == white)
		{
			(*it)->parent = v;
			DFS_VISIT(*it);
		}
	}
	v->calor = black;
	++time;
	v->f = time;
}
void INORDER_DFS(direct_graph& graph,std::vector<std::string>& order,std::vector<std::string>& result) {
	time = 0;
	for (int i = 0; i != order.size(); i++)
		if (graph[order[i]]->calor == white)
			INORDER_DFS_VISIT(graph[order[i]],result);
}
void INORDER_DFS_VISIT(std::shared_ptr<vertex> v,std::vector<std::string> &result) {
	++time;
	v->s = time;
	v->calor = grey;
	for (auto it = v->edge.begin(); it != v->edge.end(); it++)
	{
		if ((*it)->calor == white)
		{
			(*it)->parent = v;
			INORDER_DFS_VISIT(*it,result);
		}
	}
	v->calor = black;
	++time;
	v->f = time;
	result.push_back(v->name);
}