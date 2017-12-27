//mylib: intToString
//

#include <iostream>
#include <sstream>  

std::string intToString(int n)
{
    std::ostringstream stream;
    stream<<n;  //n为int类型
    return stream.str();
}

int main(int argc,const char * argv[]){
    int iA = 123;
    std::string sA = "";
    sA = intToString(iA);

    std::cout <<  "type:" << typeid(sA).name() << std::endl;
    std::cout <<  "value:" << sA << std::endl;

}
