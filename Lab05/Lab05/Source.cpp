#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>

using namespace std;

vector<double> distances;

void sortVector(vector<double>& vec)
{
	double indexSmallest, temp;   
	int size = vec.size();

	for (int i = 0; i < size - 1; ++i)
	{
		indexSmallest = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (vec[j] < vec[indexSmallest])
			{
				indexSmallest = j;
			}
		}
		temp = vec[i];
		vec[i] = vec[indexSmallest];
		vec[indexSmallest] = temp;
	}
}

double calcDistance(double x1, double y1, double z1, double x2, double y2, double z2)
{
	double distance ;

	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));

	return distance;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout, fout_sorted;
	fout.open("output.txt");
	fout_sorted.open("output_sorted.txt");
	double x1, y1, z1, x2, y2, z2;

	if (!fin.is_open())
	{
		cout << "Input file failed to open" << endl;
	}
	if (fout.fail())
	{
		cout << "Output file failed to open" << endl;
	}
	if (fout_sorted.fail())
	{
		cout << "Output_sorted file failed to open" << endl;
	}

	while (fin.good())
	{
		fin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		distances.push_back(calcDistance(x1, y1, z1, x2, y2, z2));
		fout << calcDistance(x1, y1, z1, x2, y2, z2) << endl;
	}
	
	sortVector(distances);

	int size = distances.size();
	for (int i = 0; i < size; i++)
	{
		fout_sorted << distances[i] << endl;
	}

	fin.close();
	fout.close();
	fout_sorted.close();

	return 0;
}