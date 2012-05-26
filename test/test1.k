import gui; // dynamically load /usr/lib/libgui.so and load header /usr/include/krcc/gui.h
import io; // same as above, but for io

using namespace gui;

int main(constant argc, constant *argv[]) {
    io.File infile = new io.File("~/.bashrc"); // "io.File" because modules are namespaces.  Use "using namespace" to simply type "File"
    io.File outfile = new io.File("~/.bashrc_backup");
    foreach(string line = infile.readln()) {
    	outfile.writeln(line);
    }
    return 0;
}