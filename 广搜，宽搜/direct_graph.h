//����ͼ������ʵ��
#ifndef DIRECTGRAPH
#define DIRECTGRAPH
#include"vertex.h"
#include<list>
#include<vector>
#include<string>
#include<memory>
#include<iostream>
#include<unordered_set>
class direct_graph {
	std::unordered_set<std::shared_ptr<vertex>> graph;
	std::vector<std::string> name;
public:
	int size() {	return name.size();}
	std::string get_name(int i) { return name[i]; }
	direct_graph reverse() {
		direct_graph rev;
		for (int i = 0; i != name.size(); i++)
		{
			rev.add_vertex(name[i]);
		}
		for (int i = 0; i != name.size(); i++)
		{
		auto x=this->operator[](name[i]);
		for (auto it = x->edge.begin(); it != x->edge.end(); it++)
		{
			rev.add_edge((*it)->name, x->name);
		}
		}
		return rev;
	}
	std::vector<std::string> get_name() {
		return name;
	}
	std::shared_ptr<vertex> operator[](std::string s) {
		if (graph.find(std::make_shared<vertex>(s)) != graph.end())
			return *(graph.find(std::make_shared<vertex>(s)));
		else {
			std::cout << "û�������" << std::endl;
			return std::shared_ptr<vertex>();
		}

	}
	void add_vertex(const std::string& s) {
		auto a = std::make_shared<vertex>(s);
		graph.insert(a);
		name.push_back(s);
		std::cout << "�ɹ�����˱��Ϊ:" << s << "�ĵ�" << std::endl;
	}
	void add_edge(const std::string& l, const std::string& r) {
		if ((graph.find(std::make_shared<vertex>(l)) == graph.end()) || graph.find(std::make_shared<vertex>(r)) == graph.end()) {
			std::cout << "����û��������" << std::endl;
			return;
		}
		else {
			(*(graph.find(std::make_shared<vertex>(l))))->edge.push_back(*graph.find(std::make_shared<vertex>(r)));
			std::cout << "�ɹ������" << l << "��" << r << "�ı�" << std::endl;
		}
	}
};
#endif

