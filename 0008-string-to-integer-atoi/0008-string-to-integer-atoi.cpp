class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(s[i] == ' '){
            i++;
        }

        bool negative = false;;
        if(s[i] == '-'){
            negative = true;
            i++;
        }else if(s[i] == '+') i++;

        double ans = 0;
        for(int j = i; j < s.size(); j++){
            if(s[j] >= '0' && s[j] <= '9'){
                ans = ans*10 + (s[j]-'0');
            }else{
                break;
            }
        }

        if(ans-1 >= INT_MAX && negative == true) return INT_MIN;
        if(ans >= INT_MAX && negative != true) return INT_MAX;
        if(negative == true) return (int)-ans;
        return (int)ans;
    }
};