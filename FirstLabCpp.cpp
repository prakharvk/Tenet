#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mat_add(const vector<vector<int>> &A,const vector<vector<int>> &B)
{
	vector<vector<int>> res;
    int p = A.size();
    if(p==0) return res;
	int q = A[0].size();
	if(q==0) return res;
    int m = B.size();
    if(m==0) return res;
    int n = B[0].size();
    if(n==0) return res;
    if(p!=m && q!=n) return res;
    if(m<p || n<q) return mat_add(B,A);
    if(m%p != 0 || n%q != 0) return res;
    
    res.resize(m, vector<int>(n));

    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            res[i][j] = A[i%p][j%q] + B[i][j];
        }
    }
    return res;

}
vector<vector<int>> mat_sub_constant(const vector<vector<int>>& A, const int &B)
{
    vector<vector<int>> res;
    int m = A.size();
    if(m==0) return res;
    int n = A[0].size();
    if(n==0) return res;
    res.resize(m, vector<int>(n));
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j) res[i][j] = A[i][j] - B;
    }
    return res;
}
vector<vector<int>> mat_multi(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int p = A.size();
    int q = A[0].size();

    int r = B.size();
    int s = B[0].size();

    vector<vector<int>> res;

    if(q!=r) return res;

    res.resize(p, vector<int>(s));
    for(int i=0;i<q;++i)
    {
        for(int j=0;j<p;++j)
        {
            for(int k=0;k<s;++k)
            {
                res[j][k] += A[j][i] * B[i][k];
            }
        }
    }
    return res;
}
vector<vector<int>> transpose(const vector<vector<int>> &A)
{
    vector<vector<int>> res;
    int m = A.size();
    if(m==0) return res;
    int n = A[0].size();
    if(n==0) return res;

    res.resize(n, vector<int>(m));

    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            res[j][i] = A[i][j];
        }
    }
    return res;
}
template<typename T>
void print(const vector<vector<T>>& A)
{
    cout<<"==============Matrix==========="<<endl;
    for(auto& i:A)
    {
        for(auto&j: i) cout<<j<<"\t";
        cout<<endl;
    }
    cout<<"==============================="<<endl;
}


int main()
{
    // 1
    cout<<"1: "<<endl;
    vector<vector<int>> A = {{0,-1,9,2}};
    vector<vector<int>> B = {{4,1,6,6},{1,8,6,4}};
    
    auto C = mat_add(A,B);
    print(C);

    // 2
    cout<<"2: "<<endl;
    vector<vector<int>> nullmatrix;
    auto nullmatrix_T = transpose(nullmatrix);
    print(nullmatrix_T);

    // 3
    cout<<"3: "<<endl;
    int m3_1[] = {11,-13, 24,-31};
    int m3_2[] = {8, 2, 5, 1};
    double m3_res[4];
    transform(m3_1,m3_1+4,m3_2,m3_res,divides<double>());
    for(int i=0;i<4;++i) cout<<m3_res[i]<<"\t";
    cout<<endl;

    // 4
    cout<<"4: "<<endl;
    vector<vector<int>> m4_1 = {{1,2,3},{4,5,6}};
    vector<vector<int>> m4_2 = {{7,8,9},{10,11,12}};
    auto m4_res = mat_add(m4_1,m4_2);
    
    print(m4_res);

    // 5
    cout<<"5: "<<endl;
    vector<vector<int>> m5_1 = {{1,2,5,3,5},{10,1,6,3,9},{1,6,3,7,8}};
    vector<vector<int>> m5_2 = {{6,5,9,3,5},{6,5,4,8,5},{6,3,5,7,9}};
    vector<vector<int>> m5_3 = {{2,5,9,3,4},{5,6,3,7,8},{9,8,6,5,4}};

    auto m5_res = transpose(mat_add(mat_add(m5_1,m5_2),m5_3));
    print(m5_res);

    // 6
    cout<<"6: "<<endl;
    vector<vector<int>> m6_1 = {{0,8,3,5,5},{3,9,6,1,3},{5,3,1,4,8}};
    vector<vector<int>> m6_2 = {{4,9,5,3,4},{6,5,7,9,5},{6,1,5,4,10}};
    vector<vector<int>> m6_3 = {{0,1,9,3,3},{5,5,7,2,9},{9,5,3,1,4}};
    
    auto m6_res = mat_sub_constant(mat_add(mat_add(m6_1,m6_2),m6_3),1);
    print(m6_res);

    // 7
    cout<<"7: ";
    vector<vector<int>> m7_1 = {{1,2},{3,4},{5,6}};
    vector<vector<int>> m7_2 = {{7,8},{9,10},{11,12}};

    auto m7_res = mat_add(m7_1,m7_2);
    print(m7_res);

    // 8
    cout<<"8: "<<endl;
    int P[] = {22,-33, 121,-20};
    int Q[] = {4,5,13,1};
    double res[4];
    transform(P,P+4,Q,res,divides<double>());
    for(int i=0;i<4;++i) cout<<res[i]<<"\t";
    cout<<endl;
    
    // 9 
    cout<<"9: "<<endl;
    vector<vector<int>> m9_1 = {{1,1,1},{1,1,1},{1,1,1}};
    auto m9_res = mat_add(nullmatrix,m9_1);
    print(m9_res);


    // 10
    cout<<"10: "<<endl;
    vector<vector<int>> m10_1 = {{2340},{1},{2010}};
    vector<vector<int>> m10_2 = {{210,212}};

    auto m10_res = mat_multi(m10_1,m10_2);
    print(m10_res);
}