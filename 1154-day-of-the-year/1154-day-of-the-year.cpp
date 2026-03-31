class Solution {
public:
    int dayOfYear(string date) {
        int month_days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        string yr=date.substr(0,4);
        int year=stoi(yr);
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
            month_days[1]=29;
        }

        int month=stoi(date.substr(5,2));
        int day=stoi(date.substr(8,2));
        int ans=0;
        for(int i=0;i<month-1;i++){
          ans+=month_days[i];
        }
        ans+=day;
        return ans;
    }
};