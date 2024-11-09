#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

/*vector<int> mergeArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged = arr1;
    merged.insert(merged.end(), arr2.begin(), arr2.end());
    return merged;
}*/
template<typename T>
void merge_array(const std::vector<T> &vec1,const std::vector<T> &vec2,std::vector<T> &res){
    res.insert(res.end(),vec1.begin(),vec1.end());
    res.insert(res.end(),vec2.begin(),vec2.end());
}

int main()
{
    std::vector <float>result;
    merge_array<float>({1,2,3,4},{5,6.5f,7,8.4f},result);

    for (float i : result)
    {
        std::cout << i << ' ';
    }
    std::cout<<std::endl;

    return 0;
}
