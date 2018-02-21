//
// Created by clz on 2018/2/20.
// https://github.com/chenlongzhen/FM_DMLC-1/blob/master/rabit/doc/guide.md

#include <dmlc/io.h>
#include <dmlc/data.h>
#include <string>

int main(int argc, char *argv[]) {
    char* infile = argv[1];
    //std::string infile = "file:/Users/clz/CLionProjects/FM_DMLC-1/src/data/write.txt";
    dmlc::Stream *fo = dmlc::Stream::Create(infile,"w");
    dmlc::ostream os(fo);
    // std::cout<<"input"<<std::endl;
    // os << "test" <<'\n';
    char* oufile = argv[2];
    std::cout<<"output"<<std::endl;
    dmlc::RowBlockIter<unsigned> *dtrain = dmlc::RowBlockIter<unsigned>::Create(oufile, 0 , 1, "libsvm"); // path , read part, split number, mode
    dtrain->BeforeFirst();
    while (dtrain->Next()) {
        const dmlc::RowBlock<unsigned> &batch = dtrain->Value();
	for (size_t i_b=0; i_b < batch.size; ++i_b) {
		dmlc::Row<unsigned> v = batch[i_b];
		//std::cout<< v.label <<std::endl;
	    os << v.label<< " ";
	    for (unsigned i_v=0; i_v < v.length; ++i_v) {
	        os << v.index[i_v] << ":";
		os << v.get_value(i_v) << " ";
		}
	    os << "\n" ;
         }
    }
    os.set_stream(NULL);
    delete fo;
    std::cout << "Finishing dump" <<std::endl;
}

