#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> customers(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        customers[i] = make_tuple(a, b, i);  // arrival, departure, original index
    }

    // Sort by arrival time
    sort(customers.begin(), customers.end());

    // Min-heap: (departure time, room number)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int room_id = 0;
    vector<int> room_assignment(n);

    for (int i = 0; i < n; ++i) {
        int arrival = get<0>(customers[i]);
        int departure = get<1>(customers[i]);
        int index = get<2>(customers[i]);

        if (!pq.empty() && pq.top().first < arrival) {
            // Reuse this room
            int reused_room = pq.top().second;
            pq.pop();
            room_assignment[index] = reused_room;
            pq.push({departure, reused_room});
        } else {
            // Allocate new room
            room_id++;
            room_assignment[index] = room_id;
            pq.push({departure, room_id});
        }
    }

    cout << room_id << "\n";
    for (int i = 0; i < n; ++i)
        cout << room_assignment[i] << " ";
    cout << "\n";

    return 0;
}
