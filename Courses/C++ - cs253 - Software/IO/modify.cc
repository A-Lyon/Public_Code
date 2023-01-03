#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
	cerr << "usage: " << argv[0] << " infile/outfile\n";
	return 1;
    }


    fstream in(argv[1]);            //argument 1  input stream
    if (!in) {
	cerr << argv[0] << ": can't open " << argv[1] << '\n';
	return 2;
    }

    while(in.get()){
        if(in.peek() == 'T' || in.peek() == 't'){
            in.get();
            if(in.peek() == 'r'){
                in.get();
                if(in.peek() == 'u'){
                    in.get();
                    if(in.peek() == 'm'){
                        in.get();
                        if(in.peek() == 'p'){
                        in.unget();in.unget();in.unget();in.unget();
                        in.put('B'); in.put('i'); in.put('d'); in.put('e'); in.put('n');                 
                        in.unget();
                        continue;
                        }
                    }
                }
            }       
        }

            
        else{
            if (in.eof()){
                break;
            }
            continue;
        }
    }

    return 0;
}

// Note that line.npos ≡ string::npos.
// It’s a static constant, part of the string class.
// It’s a number that means “Sorry, I couldn’t find that.”
// make this read from a file, modify the lines, then write them back to that file.
// dont use vector, use creativity, use get() and peek() tellg()-where? seekp()-move


/*
removed these:
	for (size_t pos=0; (pos=line.find("Trump", pos)) != line.npos; )
	    line.replace(pos, 5, "Biden");
	out << line << '\n';

*/