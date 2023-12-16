// String's Count
// https://www.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints1135/1

long long int countStr(long long int n){
    //complete the function here
  
    return 1+(n*2)+(n*((n*n)-1)/2);
}
