#include <bits/stdc++.h>
#define INF 200000000

using namespace std;
float Totaldistance, tank, gph, original;
int stations;

float changeGas(vector<pair<float, float>> gasStops, int index, float gas){
	float drive = 0;

	if(index == 0){
		drive = gasStops[index].first;
	}
	else{
		drive = gasStops[index].first - gasStops[index - 1].first;
	}

	float gallons = drive / gph;
	gas -= gallons;
	return gas;
}

float DFS(float gas, int index, const vector<pair<float, float>>& gasStops){
//	if(gasStops[index].first >= Totaldistance) return (float) 0;
	if(index == (int) gasStops.size()){
		float length = Totaldistance - gasStops[index - 1].first;
		float gallons = length / gph;
		gas -= gallons;

		if(gas >= 0){
			return 0;
		}
		return (float)INF;
	}

	gas = changeGas(gasStops, index, gas);
//	cout << index << " " << gas << endl;
	if(gas < 0) return (float) INF;
	float res1, res2;

	res1 = DFS(gas, index + 1, gasStops);
	if(gas > tank / 2.0) return res1;

	res2 = DFS(tank, index + 1, gasStops) +
			(float) 200 + (float) (gasStops[index].second * (tank - gas));
//	cout << index << "  " << res1 << "  " << res2 << endl;
	return min(res1, res2);
}

int main() {
	int times = 1;

	while(true){
		cin >> Totaldistance;
		if(Totaldistance == -1) break;
		cin >> tank >> gph >> original >> stations;
		vector<pair<float, float>> gasStops;

		for(int i = 0; i < stations; i++){
			float d, c;
			cin >> d >> c;
			gasStops.push_back(make_pair(d, c));
		}

		sort(gasStops.begin(), gasStops.end());
		float res = DFS(tank, 0, gasStops) + (original * 100);
		res /= (float)100;

		cout << "Data Set #" << times << endl;
		cout << "minimum cost = $" << fixed << setprecision(2) << res << endl;
		times ++;

	}

	return 0;
}
