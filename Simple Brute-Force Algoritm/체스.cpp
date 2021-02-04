#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num, ry, rx, cy, cx, dy, dx, result=0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			cin >> num;

			if (num == 1) { //King's Coordinate 
				ry = i;
				rx = j;
			}
			if (num == 2) { //look Coordinate 
				cy = i;
				cx = j;
			}
			if (num == 3) {
				dy = i;
				dx = j;
			}
			
			if (ry == cy || rx == cy) {
				if ((dy > ry && dy < cy) || (dx > ry && dx < cy) || (dy < ry && dy > cy) || (dx < ry && dx > cy))
					result = 0;
				else
					result = 1;
			}
			else result = 1;
				
		}
	}
	cout << result;
}