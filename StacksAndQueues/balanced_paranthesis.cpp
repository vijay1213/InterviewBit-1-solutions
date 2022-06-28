int Solution::solve(string A) {
    int count=0;
    for(int i=0;i<A.size();i++){
        if(A[i]=='('){
            count++;
        }
        else{
            count--;
        }
        if(count<0){
            return 0;
        }
    }
    if(count==0){
        return 1;
    }
    else
    return 0;
}

int Solution::solve(string A) 
{
    stack<int> s;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='(')
        {
            s.push(i);
        }
        else
        {
            if(s.empty())
            {
                return 0;
            }
            s.pop();
        }
    }
    return s.empty();
    
}



