#include <iostream>
#include <vector>
#include <string>
#include <array>
#pragma warning(disable:4996)
using namespace std;
class Node {
public:
	Node *parent;
	vector<Node> children; // []
	string value;
	Status status;

	// Constructor
	Node(const Status &ptr_status)
	{
		status = ptr_status;
		parent = nullptr;
	}

	void add_child()
	{
		Node child{ status };
		//Status Child_status= status;
		child.parent = this;
		children.push_back(child);   // children.append()
	}
	void map_correction()
	{

			if (status.state == 0)
			{
				status.map_tmp[1][1];
			}
		


	}

	Node& get_child(int index)
	{
		return children[index];
	}

	size_t num_children() const
	{
		return children.size(); // len(children)
	}

};



class Status 
{
public:
	array<array<int, 12>, 12> cores_tmp;
	array<array<int, 12>, 12> map_tmp;
	array<array<int, 12>, 2> coordiante_tmp;
	int num_connected_cores = 0;
	int current_coordinate;
	int num_real_core;
	int size;
	int state;

	Status() {}

	Status(const array<array<int, 12>, 12> &cores, const array<array<int, 12>, 12> &map, int num_connected_cores, int size, int state, array<array<int, 12>, 2> coordiante, int num_real_core, int current_coordinate)
	{
		cores_tmp = cores;
		coordiante_tmp = coordiante;
		map_tmp = map;
		this->current_coordinate = current_coordinate;
		this->num_connected_cores = num_connected_cores;
		this->size = size;
		this->state = state;
		this->num_real_core = num_real_core;
	}


};

int main()
{
	array<array<int, 12>, 12> cores;
	array<array<int, 12>, 12> map;
	array<array<int, 12>, 2> coordinate={0};
	freopen("input.txt", "r", stdin);
	string input;
	cin >> input;
	int num_try;
	int size;
	int num_connected_cores = 0;


	num_try = stoi(input);

	cin >> input;	
	size= stoi(input);

	for (int row = 0; row < size; row++)
	{
		for (int coloum = 0; coloum < size; coloum++)
		{
			cin >> input;
			cores[row][coloum]= stoi(input);
			map[row][coloum]= stoi(input);
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (cores[0][i] == 1)
		{
			num_connected_cores++;
			cores[0][i] = 0;
		}
		if (cores[i][0] == 1)
		{
			num_connected_cores++;
			cores[i][0] = 0;
		}
		if (cores[i][size-1] == 1)
		{
			num_connected_cores++;
			cores[i][size - 1] = 0;
		}
		if (cores[size - 1][i] == 1)
		{
			num_connected_cores++;
			cores[size - 1][i] = 0;
		}
	}
	int tmp = 0;
	for (int row = 1; row < size-1; row++)
	{
		for (int coloum = 1; coloum < size-1; coloum++)
		{
			if (cores[row][coloum] == 1)
			{
				coordinate[tmp][0] = row;
				coordinate[tmp][1] = coloum;
				tmp++;
			}
		}
	}

	Status status(cores,map, num_connected_cores,size,-1, coordinate,tmp,-1);
	Node tree(status);





	return 0;
}