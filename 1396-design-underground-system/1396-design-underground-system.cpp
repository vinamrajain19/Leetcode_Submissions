// checkIns : It maps customer id to checkin station and time.
// routeTimings: It maps startStation-endStation to total timings and number of records of startStation-endStation till now.

// Time Complexity : O(1) , since a hashmap functions in amortized O(1) time.
// Space Complexity : O(N^2), where N is total number of stations. In the worst case, routes from all stations to all stations will have to be stored. For a graph having N nodes, max number of edges is equal to N*(N-1)/2 = O(N^2)




class UndergroundSystem {
    unordered_map<int, pair<string, int> >checkIns;        // id : {stationName, time}
    unordered_map<string, pair<int, int> >routeTimings;    // startStation-endStation : {sumOfTime, count}
public:
    UndergroundSystem() {  }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};           // store id checked in at stationName at time t
    }
    
    void checkOut(int id, string stationName, int t) {
	    //                     startStation       -    endStation
        
        string startToEnd = checkIns[id].first + '-' + stationName; 
        
		// update route's total time and count
        routeTimings[startToEnd] = {routeTimings[startToEnd].first + (t - checkIns[id].second), routeTimings[startToEnd].second + 1};
        
        checkIns.erase(id); // erase checkin data to free up memory
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> p = routeTimings[startStation + '-' + endStation];
		// divide   total time by total cound to get average route time
        return (double)p.first / p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */