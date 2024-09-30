#include "gc.h"

using namespace std;

void Parser::split_input(const string line, string & sn, string & sm) const{
	stringstream str(line);			//make artifical stream
	str >> sn >> sm;			 	//and read from it
}

void Parser::read(){
	ifstream file(filename);
	file.seekg(0, std::ios::end);
	file.seekg(0, std::ios::beg);
	string line;
	getline(file, line);
	string sN, sM;
	split_input(line, sN, sM);
	N = stoi(sN);
	M = stod(sM);
	edges.resize(N);
	for(int i = 0; i < N; i++)
		edges[i].push_back(i);
	while (getline(file, line) and !file.eof()){
		string sv, su;
		split_input(line, sv, su);
		edges[stod(sv)].push_back(stod(su));
		edges[stod(su)].push_back(stod(sv));
	}
	file.close();
}

void Solver::colorize(){
	vector<vector<int>> edges = parser->get_edges();
	count_colors = 0;

	sort(edges.begin(), edges.end(), cmp);

	int size = edges.size();
	for(int i = 0; i < size-1; i++) {
        int v = edges[i][0];
		if(colors[v] == -1){
			colors[v] = count_colors;
			//for all next by v
			for(int j = i+1; j < size; j++){
				bool flag = 0;
				int u = edges[j][0];
				//all neighbours of u: 
				for(unsigned k = 1; k < edges[j].size() && !flag; k++)
					//if neighbour have the same color we out
					if(colors[edges[j][k]] == count_colors) flag = 1;
				if(!flag && colors[u] == -1) colors[u] = count_colors;
			}
			++count_colors;
		}
    }
}
