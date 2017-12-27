//ͼ������ʵ��
#ifndef GRAPH
#define GRAPH
#include<list>
#include<vector>
#include<string>
#include<memory>
#include<iostream>
#include<unordered_set>
#include"vertex.h"
class no_direct_graph {
	std::unordered_set<std::shared_ptr<s_vertex>> graph;
public:
	std::shared_ptr<s_vertex> operator[](const std::string& s) {
		if (graph.find(std::make_shared<s_vertex>(s)) != graph.end())
		return *(graph.find(std::make_shared<s_vertex>(s)));
		else {
			std::cout << "û�������" << std::endl;
			return std::shared_ptr<s_vertex>();
		}
	
	}
	int size() { return graph.size(); }
	void add_vertex(const std::string& s) {
		auto a = std::make_shared<s_vertex>(s);
		graph.insert(a);
		std::cout << "�ɹ�����˱��Ϊ:" << s << "�ĵ�" << std::endl;
	}
	void add_edge(const std::string& l, const std::string& r) {
		if (graph.find(std::make_shared<s_vertex>(l))==graph.end()) {
			std::cout << "����û��" <<l<<"��"<< std::endl;
			return;
		}
		else if(graph.find(std::make_shared<s_vertex>(r)) == graph.end()){
			std::cout << "����û��" << r << "��" << std::endl;
			return;
		}
		else {
			(*(graph.find(std::make_shared<s_vertex>(l))))->edge.push_back(*graph.find(std::make_shared<s_vertex>(r)));
			(*(graph.find(std::make_shared<s_vertex>(r))))->edge.push_back(*graph.find(std::make_shared<s_vertex>(l)));
		}
	}
};
#endif
