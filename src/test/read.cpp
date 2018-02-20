//
// Created by clz on 2018/2/20.
//

#include <dmlc/io.h>
#include <dmlc/data.h>
#include <string>

int main(int argc, char *argv[]) {
    std::string infile = "file:/Users/clz/CLionProjects/FM_DMLC-1/src/data/write.txt";
    dmlc::Stream *fo = dmlc::Stream::Create(infile.c_str(),"w");
    dmlc::ostream os(fo);
    os << "test" <<'\n';
}
