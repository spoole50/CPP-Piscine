import sys
import os

def create_hpp():
    filename = sys.argv[1]
    current_dir = os.getcwd()
    #print(filename)
    #print(current_dir)
    doc = open(current_dir + "/" + filename + ".hpp", "a")
    doc.writelines("#ifndef " + filename.upper() + "_H")
    doc.writelines("\n#define " + filename.upper() + "_H")
    doc.writelines("\n\t#include <string>")
    doc.writelines("\n\t#include <iostream>")
    doc.writelines("\n\n\tclass " + filename.capitalize() + "\n\t{};")
    doc.writelines("\n\n#endif")
    doc.close()


def main():
    create_hpp()

if __name__ == "__main__":
    main()