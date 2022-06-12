// Method1: Hashing method

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    vector<int> res(2);
    vector<int> hash(n+1,0);
    for(int i=0;i<n;i++)
    hash[A[i]]++;
    for(int i=0;i<=n;i++){
        if(hash[i]==2)
          res[0]=i;
        if(hash[i]==0)
          res[1]=i;
    }
    return res;
}

// Method2: Using Maths 

vector<int> Solution::repeatedNumber(const vector<int> &A){
    long long int len = A.size();

    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }
     
    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;

    vector <int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;
    
}

// Method3: Using Xor operations

vector<int> Solution::repeatedNumber(const vector<int> &A){
    int xor1;
    int set_bit_no;
    int i;
    int x=0; // missing
    int y=0; // repeated
    int n=A.size();
    xor1=A[0];
    for(i=1;i<n;i++)
        xor1=xor1^A[i];
    for(i=1;i<=n;i++)
        xor1=xor1^i;
    set_bit_no=xor1 & ~(xor1-1);
    for(i=0;i<n;i++){
        if(A[i] & set_bit_no)
            x=x^A[i];
        else
            y=y^A[i];
    }
    for(i=1;i<=n;i++){
        if(i & set_bit_no)
            x=x^i;
        else
            y=y^i;
    }
    int x_count=0;
    for(int i=0;i<n;i++){
        if(A[i]==x)
          x_count++;
    }
    if(x_count==0)
        return {y, x};
    return {x, y};
}
