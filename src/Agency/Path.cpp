#include "Path.h"

Path::Path() {
    capacity = INT_MAX;
    duration = 0;
    flow = INT_MAX;
}

vector<Trip> Path::getTrips() const {
    return trips;
}

void Path::addTrip(const Trip& trip) {
    capacity = min(capacity, trip.capacity);
    flow = min(flow, trip.flow);
    duration += trip.duration;
    trips.push_back(trip);
}

void Path::setFlow(const int &flux) {
    this->flow = flux;
}

int Path::getFlow() const {
    return this->flow;
}

void Path::printInfo() const {
    cout << "Capacity: " << capacity << endl;
    cout << "Duration: " << duration << endl;
    cout << "Flux: " << flow << endl;
    cout << "Trips: " << trips.size() << endl;
}

void Path::printTrips() const {
    for (Trip trip: trips) {
        cout << trip.src << " ------------> " << trip.dest << "\n";
        cout << "   capacity: " << trip.capacity << "\n";
        cout << "   flux: " << trip.flow << "\n";
        cout << "   duration: " << trip.duration << "\n\n";
    }
}
