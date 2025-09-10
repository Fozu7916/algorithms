// #include <iostream>
// #include <vector>
// #include <cmath>

// bool isPretty(long long x){
//     int mnoj = 1; int sum = 0;
//     while( x!= 0){
//         mnoj *= x%10;
//         sum += x%10;
//         x = x/10;
//         //std::cout<<sum<<mnoj<<"\n";
//     }

//     if(mnoj % sum == 0){
//         return true;
//     } else {
//         return false;
//     }
// }

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);
    
//     int count = 0;
//     long long l = 0, r = 0;
//     std::cin>>l>>r;

//     for(long long i = l; i <= r; i++){
//         //std::cout<<"zzz \n";
//         if(isPretty(i)){
//             count++;
//         }
//     }
//     std::cout<<count;
    
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// string digits;
// unordered_map<long long,long long> memo[20][163][2];
// bool used[20][163][2];

// long long dfs(int pos, int sum, long long prod, int started, bool tight){
//     if(pos==(int)digits.size()){
//         if(!started || sum==0) return 0;
//         return (prod % sum == 0);
//     }
//     if(!tight && used[pos][sum][started]){
//         auto it = memo[pos][sum][started].find(prod);
//         if(it!=memo[pos][sum][started].end()) return it->second;
//     }
//     int limit = tight ? digits[pos]-'0' : 9;
//     long long res = 0;
//     for(int d=0; d<=limit; ++d){
//         int nsum = sum + d;
//         if(nsum>162) continue;
//         if(!started){
//             if(d==0){
//                 res += dfs(pos+1, nsum, 1, 0, tight && d==limit);
//             }else{
//                 res += dfs(pos+1, nsum, d, 1, tight && d==limit);
//             }
//         }else{
//             long long nprod = prod * d;
//             res += dfs(pos+1, nsum, nprod, 1, tight && d==limit);
//         }
//     }
//     if(!tight){
//         used[pos][sum][started] = true;
//         memo[pos][sum][started][prod] = res;
//     }
//     return res;
// }

// long long countPretty(long long n){
//     if(n<0) return 0;
//     digits = to_string(n);
//     for(int i=0;i<20;++i)
//         for(int j=0;j<163;++j)
//             for(int k=0;k<2;++k){
//                 memo[i][j][k].clear();
//                 used[i][j][k]=false;
//             }
//     return dfs(0,0,1,0,true);
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     long long l,r;
//     if(!(cin>>l>>r)) return 0;
//     cout << countPretty(r) - countPretty(l-1) << '\n';
//     return 0;
// }



