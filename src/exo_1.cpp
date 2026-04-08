#include <iostream>
#include <vector>


size_t folding_string_hash(std::string const& s, size_t max){

    size_t hash {0};

    for(size_t i{0};i< s.size(); i++){
        hash += s[i];
        hash%=max;
    }
    std::cout<<hash<<std::endl;
    return hash;

}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t hash {0};

    for(size_t i{0};i<s.size(); i++){
        hash += s[i]*(i+1);
        hash%=max;
    }

    std::cout<<hash<<std::endl;
    return hash;

}


int main(){
    std::string str{0};
    std::cout <<"Enter une string:"<< std::endl;
    std::cin >>str;
    folding_string_hash(str, 100);
    folding_string_ordered_hash(str, 100);

    return 0;
}