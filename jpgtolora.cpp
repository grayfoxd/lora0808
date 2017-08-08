#include</usr/include/c++/4.8.4/iostream>
#include</usr/include/c++/4.8.4/fstream>
//#include</usr/include/c++/4.8.4/sstream>
//#include</usr/include/c++/4.8.4/stdio.h>
//#include<assert.h>

using namespace std;

struct Frame{
    unsigned char head;
    unsigned char length;
    unsigned char comand;
    short num;
    char data[254];
    unsigned char cs;
    unsigned char tail;
};

class JpgToLora{


public:
        friend class SerialTest;
        Frame frame;
        SerialTest::write();
private:
        void addJpgtoFrame()
        {
            //int sum =0;
            frame.head = 0xA5;
            frame.tail = 0x5A;
            frame.num = 0;

            ofstream outFile("frame.txt");
            if(!outFile){
                cout<<"file open error!"<<endl;
                //return 0;
            }
            //
            ifstream inFile("invasion.jpg");
            if(!inFile){
                cout<<"frame open error!"<<endl;
                //return 0;
            }
            inFile.seekg(0,ios::end);
            //outFile.seekg(0,ios::beg);
            streampos pos = inFile.tellg();
            cout<<pos<<endl;
            inFile.seekg(0,ios::beg);
            if(pos>=254){
                for(int i=1;i<=pos/254;i++){
                    frame.num++;
                    inFile.read(frame.data,sizeof(frame.data));
                    //pos-=254;
                    frame.length = 0xFF;
                    outFile.write(reinterpret_cast<char *>( &frame), sizeof(frame));
                    cout<<frame.num<<endl;
                    return frame;
                    inFile.seekg(-254,ios::cur);
                }

            }
            if(pos!=0){
                frame.num++;
                frame.length = pos%254;
                inFile.read(frame.data,sizeof(frame.length));
                outFile.write(reinterpret_cast<char *>( &frame),sizeof(frame.data)+7);
                cout<<frame.num<<endl;
                return frame;
            }

            inFile.close();
            outFile.close();
        }
         int SerialTest::write()
         {
            addJpgtoFrame();

         };

};
