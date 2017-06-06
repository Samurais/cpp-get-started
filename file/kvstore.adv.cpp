
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <unistd.h>
#include <stdio.h>

using namespace std;

class KVStore
{
public:
    KVStore(const string filePath): _filepath(filePath) {
        _store = new std::map<string, string>();
    }

    ~KVStore(){
        std::cout << "Deconstruct ... backup kv first.";
        // backup to local file
        dump(_filepath + ".backup");
        delete _store;
    }

    void load(){
        std::cout << "read file:" <<  _filepath << std::endl;
        std::ifstream infile(_filepath.c_str());
        std::string a, b;
        while (infile >> a >> b)
        {
            // process pair (a,b)
            std::cout << "first number:" << a << " second number:" << b << std::endl;
            (*_store)[a] = b;
        }
    }

    std::string get(const std::string key){
        return (*_store)[key];
    }

    void set(const std::string key, const std::string val){
        (*_store)[key] = val;
    }

    std::set<std::string> keys(){
        std::set<std::string> keys;
        std::map<string, string>::iterator it = _store->begin();
        for(; it != _store->end(); ++it){
            keys.insert(it->first );
        }
        return keys;
    }

    void dump(const string path){
        // open a file in write mode, it would flush the previous data is it exists.
        ofstream saved;
        saved.open(path.c_str());
        
        // write data
        std::map<string, string>::iterator it = _store->begin();
        for(; it != _store->end(); ++it){
            std::cout<< "Key: " <<  it->first 
                    << " Value: " << it->second << std::endl;
            saved << it->first << " ++$++ " << it->second << '\n';
        }

        // close
        saved.close();
    }

protected:
    std::map<string, string>* fetchAll(){
        return _store;
    }

private:
    string _filepath;
    std::map<string, string> *_store;
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

    // change obj f's value by key
    f.set("1", "5");

    // print keys
    std::set<std::string> keys = f.keys();
    std::set<std::string>::iterator it = keys.begin();
    std::cout<< "Keys:" <<std::endl;
    for(; it != keys.end(); ++it){
        std::cout << "- Key: " << *it << std::endl;
    }

    // dump to file
    f.dump(basePath + "/numbers.dump.v2.txt");

    std::cout << "End." << std::endl;
    return 0;
}