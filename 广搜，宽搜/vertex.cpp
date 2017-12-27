#include"vertex.h"
bool operator==(std::shared_ptr<s_vertex> l, std::shared_ptr<s_vertex> r) {
	return l->name == r->name;
}
bool operator==(std::shared_ptr<vertex> l, std::shared_ptr<vertex> r) {
	return l->name == r->name;
}
size_t std::hash<std::shared_ptr<s_vertex>>::operator() (const std::shared_ptr<s_vertex>& ptr) const {
	return hash<std::string>()(ptr->name);
}
size_t std::hash<std::shared_ptr<vertex>>::operator() (std::shared_ptr<vertex> ptr) const {
	return hash<std::string>()(ptr->name);
}