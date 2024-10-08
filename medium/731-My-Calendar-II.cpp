//      10     20
//                                   50      60
//      10                  40
//  5       15
//

//        26         35
//        26      32
//      25        32

class MyCalendarTwo
{
public:
    vector<pair<int, int>> events;
    vector<pair<int, int>> overlappingEvents;

    MyCalendarTwo()
    {
        events = {};
        overlappingEvents = {};
    }

    bool book(int start, int end)
    {
        //  check if triple overlap
        for (int i = 0; i < overlappingEvents.size(); i++)
        {
            if ((start >= overlappingEvents[i].first && start < overlappingEvents[i].second) ||
                (end > overlappingEvents[i].first && end < overlappingEvents[i].second) ||
                (start <= overlappingEvents[i].first && end >= overlappingEvents[i].second))
            {
                return false;
            }
        }

        //  update overlaps if any overlap with current, and insert current, return true
        for (int i = 0; i < events.size(); i++)
        {
            if (start >= events[i].first && start < events[i].second)
            {
                overlappingEvents.push_back({start, min(events[i].second, end)});
            }
            if (end > events[i].first && end < events[i].second)
            {
                overlappingEvents.push_back({max(events[i].first, start), end});
            }
            if (start <= events[i].first && end >= events[i].second)
            {
                overlappingEvents.push_back({events[i].first, events[i].second});
            }
        }

        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */