#include "Path.h"

Path::Path() {
    capacity = INT_MAX;
    duration = 0;
}

void Path::addTrip(const Trip& trip) {
    capacity = min(capacity, trip.capacity);
    duration += trip.duration;
    trips.push_back(trip);
}

void Path::printInfo() const {
    cout << "Capacity: " << capacity << endl;
    cout << "Duration: " << duration << endl;
    cout << "Trips: " << trips.size() << endl;
}

void Path::printTrips() const {
    for (Trip trip: trips) {
        cout << trip.src << " ------------> " << trip.dest << "\n";
        cout << "   capacity: " << trip.capacity << "\n";
        cout << "   duration: " << trip.duration << "\n\n";
    }
}
