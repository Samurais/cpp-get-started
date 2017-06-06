
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

class KVStore
{
public:
    KVStore(const string filePath): _filepath(filePath) {
    }

    ~KVStore(){
    }

    void load(){
        std::cout << "read file:" <<  _filepath << std::endl;
        std::ifstream infile(_filepath.c_str());
        std::string a, b;
        while (infile >> a >> b)
        {
            // process pair (a,b)
            std::cout << "first number:" << a << " second number:" << b << std::endl;
            _store[a] = b;
        }
    }

    std::string get(const std::string key){
        return _store[key];
    }

    void set(const std::string key, const std::string val){
        _store[key] = val;
    }

    std::map<string, string> fetchAll(){
        return _store;
    }

    void dump(const string path){
        // open a file in write mode, it would flush the previous data is it exists.
        ofstream saved;
        saved.open(path.c_str());
        
        // write data
        std::map<string, string>::iterator it = _store.begin();
        for(; it != _store.end(); ++it){
            std::cout<< "Key: " <<  it->first 
                    << " Value: " << it->second << std::endl;
            saved << it->first << " ++$++ " << it->second << '\n';
        }

        // close
        saved.close();
    }

private:
    string _filepath;
    std::map<string, string> _store;
};

std::string getCurrentPath(){
   char buff[256];
   getcwd( buff, 256 );
   std::string cwd( buff );
   return cwd;
}


int main(int argc, char const *argv[])
{   
    // result file path
    std::string basePath = getCurrentPath();
    std::cout<< "File basePath:" << basePath<< std::endl;;

    // read file
    KVStore f(basePath + "/numbers.txt");
    f.load();
    std::map<string, string> result = f.fetchAll();
    
    // print file
    std::cout << "Iter result as a map" << std::endl;
    std::map<string, string>::iterator it = result.begin();

    for(; it != result.end(); ++it)
        std::cout<< "Key: " <<  it->first 
                << " Value: " << it->second << std::endl;

    // get value by key
    std::cout << "Get value by key(1), result:" << result["1"] << std::endl;

    // change value by key, note, this is not changed the Store value inside Object f.
    result["1"] = "0";
    std::cout << "After update value by key(1), result:" << result["1"] << std::endl;

    // change obj f's value by key
    f.set("1", "5");

    // dump to file
    f.dump(basePath + "/numbers.dump.txt");

    std::cout << "End." << std::endl;
    return 0;
}