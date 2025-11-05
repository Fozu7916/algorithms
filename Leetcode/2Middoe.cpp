class Solution {
    public:
        int reverse(int x) {
            std::string zalupa = std::to_string(x);
            int len = zalupa.size();
            int sex = 0;
            if(x >= 0){
                sex = 0;
            } else {
                sex = 1;
            }

            if(len%2 == 0){
                for(int i = 0; i < (len/2); i++){
                    char temp = zalupa[i+sex];
                    zalupa[i+sex] = zalupa[len-i-1];
                    zalupa[len-i-1] = temp;
                }
                long long a = stoll(zalupa);
                if(a >= INT_MAX or a <= - INT_MAX){ return 0;}
                return a;
            } else {
                for(int i = 0; i < (len/2); i++){
                    char temp = zalupa[i+sex];
                    zalupa[i+sex] = zalupa[len-i-1];
                    zalupa[len-i-1] = temp;
                }
                long long a = stoll(zalupa);
                if(a >= INT_MAX or a <= - INT_MAX){ return 0;}
                return a;
            }
        }
    };