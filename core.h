#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <vector>
#include <set>

using namespace std;

using namespace std;
class Parser{
	int N, M;
	vector<vector<int>> edges;
	string filename;
	void split_input(const string line, string & sv, string & sw) const;
public:
	Parser(string fname = ""){
		filename = fname;
	}
	~Parser(){}
	
	int get_v() const{ return N; }
	int get_e() const{ return M; }
	void read();
	vector<vector<int>> get_edges() const{return edges; };
	void show_edges();
	
	Parser * operator= (Parser * p){
		vector<vector<int>> pedges = p->get_edges();
		edges.resize(pedges.size());
		for(unsigned i = 0; i < pedges.size(); i++)
			for(unsigned j = 0; j < pedges[i].size(); j++)
				edges[i].push_back(pedges[i][j]);
		N = p->N;
		M = p->M;
		filename = p->filename;
		return this;
	}
};

class Solver{
	int size;
	vector<int> colors;
	int count_colors;
	Parser * parser;
	struct{
		bool operator()(vector<int> a, vector<int> b) const{
			return (a.size() > b.size());
		}
	}cmp;
public:
	Solver(){}
	Solver(Parser * p){
		parser = p;
		size = p->get_v();
		colors.resize(0);
		colors.resize(size, -1);
	}
	~Solver(){}
	
	Solver * operator= (Solver * s){
		//allocate memory
		Parser tmp(*(s->parser));
		parser = &tmp;
		return this;
	}
	void colorize();
	vector<int> get_colors () const{ return colors; }
	void show_colors() const{
		cout << "# of colors: " << count_colors << endl;
		for(int el : colors) cout << el << " ";
	}
	
};
