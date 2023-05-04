class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>rad; // store indiceis of Radiants
        queue<int>dir;
        int n=senate.size();
        for(int i=0;i<n;i++)
        {
            if(senate[i]=='R')rad.push(i);
            else
                dir.push(i);
        }
        while(true)
        {
            if(rad.empty())return "Dire";   // If one party has no vote right now
            if(dir.empty())return "Radiant";
            int r=rad.front();
            int d=dir.front();
             dir.pop();
             rad.pop();
            if(r<d)
            {
               rad.push(n+r);   // If Radiant is coming before dire
                                 // TThen this candidate will be eligible for next round
            }
            else
            {
                dir.push(n+d);   // Adiing n is important to specify thr which round
            }
        }
        return "";
    }
};