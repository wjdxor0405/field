#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstring>

void read_file(char *);

int main(int argc, char **argv){
    
    printf("argc : %d\n", argc);
    printf("argv1 : %s\n", argv[1]);
    if (argc > 1){
        read_file(argv[1]);
    }

    return 0;
}

void read_file(char * file_name){

    std::ifstream readFile;
    readFile.open(file_name);
    int count = 0;
    if(readFile.is_open()){
        while(!readFile.eof()){
            count++;
            char tmp[1024];
            readFile >> tmp;
            std::ofstream writeFile;
            
            char name_tmp[256];

            sprintf(name_tmp, "%d.txt", count);
            writeFile.open(name_tmp);
            // writeFile.write(tmp, strlen(tmp));
            int len = strlen(tmp);
            // printf("\n", len);
            for(int i=0;i<len;i++){
                writeFile << tmp[i];
            }
            writeFile << std::endl;
            writeFile.close();
            printf("%s saved, (%d bytes) \n",name_tmp, len);
            // if(count > 10)break;
            
        }
        readFile.close();
    }


}