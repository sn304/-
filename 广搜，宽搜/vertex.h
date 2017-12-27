#ifndef VERTEX
#define VERTEX
#include<memory>
#include<string>
#include<list>
#include<iostream>
enum calor
{
	white, grey, black
}; 
struct s_vertex
{

	s_vertex(const std::string& s) :name(s) {}
	int calor = white;
	std::string name;
	int d = 9999999;
	std::shared_ptr<s_vertex> parent;
	std::list<std::shared_ptr<s_vertex>> edge;
};
struct vertex
{

	vertex(const std::string& s) :name(s) {}
	int calor = white;
	std::string name;
	int s;
	int f;
	std::shared_ptr<vertex> parent;
	std::list<std::shared_ptr<vertex>> edge;
};
bool operator==(std::shared_ptr<s_vertex> l, std::shared_ptr<s_vertex> r);
bool operator==(std::shared_ptr<vertex> l, std::shared_ptr<vertex> r);
namespace std {
	template<> struct hash<std::shared_ptr<s_vertex>> {
		typedef size_t result_type;
		typedef std::shared_ptr<s_vertex> argument_type;
		size_t operator()(const std::shared_ptr<s_vertex>&) const;
	};
}
namespace std {
	template<> struct hash<std::shared_ptr<vertex>> {
		typedef size_t result_type;
		typedef std::shared_ptr<vertex> argument_type;
		size_t operator()(std::shared_ptr<vertex>) const;
	};
}
#endif