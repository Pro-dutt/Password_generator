#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;
const int MAX=52;

class File
{
    public:
        void create_file(string temp)
        {
            string input=temp;
            string str_file;
            cout<<"Enter name of the file (--filename.txt--): ";
            cin>>str_file;
            ofstream MyFile(str_file);
            MyFile<<temp<<endl;
            MyFile.close();
        }

};

class Random
{
    //String randomizer
    public:
        string string_gen(int size)
        {
            char alphabet[MAX]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                                'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
            string res;
            for(int i=0;i<size;i++)
            {
                res=res+alphabet[rand()% MAX];
            }
            return res;
        }   
    
    public:
        vector<int> random_num(int size)
        {
            int number[]={0,1,2,3,4,5,6,7,8,9};
            vector<int> res(size);
            for(int i=0;i<size;i++)
            {
                res[i]=number[rand()%10];
            }
            return res;
        }

        vector<int> print_num(vector<int>&rand,int size){
            for(int j=0;j<size;j++){
                cout<<rand[j]<<" ";
            }
            return rand;
        }
    
    public:
        string sp_char_gen(int size){
            char sp_char[]={'@','#','$','^','&','*','!','~','/','*','-'};
            int iter_size=sizeof(sp_char)/sizeof(sp_char[0]);
            string res=" ";
            for(int k=0;k<size;k++){
                res=res+sp_char[rand()%iter_size];
            }
            return res;
        }
    
    public:
        string convert_to_string(vector<int>&rand,int size){
            stringstream st;
            if(rand.size()>0){
                for(int i=0;i<rand.size();i++)
                {
                    st<<rand[i];
                }
            }
            return st.str();
        }
    
    public:
        string final_conv(string res, int size)
        {
            string final_str;
            for(int i=0;i<size;i++)
            {
                final_str=final_str+res[rand() % res.size()];
            }
            return final_str;
        }

};

class Check{
    public:
        bool istrue(char ch)
        {
            if(ch=='y' || ch=='Y')
                return true;
            else if(ch=='n' || ch=='N')
                return false;
            else
            {
                cout<<"\nEnter (y/n) in console!"<<endl;
                return false;
            }
        }
    
    public:
        bool check_case(int num)
        {
            if(num>0 && num<8)
                return true;
            else
                return false;
        }
    public:
        bool ask(){
            char c;
            cout<<"\nDo you wish to create a txt file (y/n): ";
            cin>>c;
            if(c=='y' || c=='Y')
                return true;
            else if(c=='n' || c=='N')    
                return false;
            else
            {
                cout<<"\nEnter (y/n) in the console: "<<endl;
                return false;
            }
        }
};

int main()
{
    srand(time(NULL));
    string generatedPassword;
    string str1,str2,str3;
    Random r;
    File f;
    Check c;
    int size,ch;
    char chc='y';
    
    cout<<"Welcome to password generator!"<<endl;
    cout<<endl;
    cout<<"The options are:"<<endl;
    cout<<"1. String Generator"<<endl;
    cout<<"2. Number generator"<<endl;
    cout<<"3. Symbol generator"<<endl;
    cout<<"4. String, Symbol generator"<<endl;
    cout<<"5. String, Number generator"<<endl;
    cout<<"6. Character, Number generator"<<endl;
    cout<<"7. String, Character, Number generator"<<endl;


    cout<<"Enter your option: ";
    cin>>ch;

    if(c.check_case(ch)==true)
    {
        cout<<"Enter the size of the password: ";
        cin>>size;
    }
    else
        cout<<"Case not valid";

    vector<int> randomNumbers=r.random_num(size);
    str1=r.string_gen(size);
    //r.print_num(randomNumbers,size);
    str2=r.convert_to_string(randomNumbers,size);
    str3=r.sp_char_gen(size);
    string str4=str1+str3;
    string str5=str1+str2;
    string str6=str3+str2;
    string str7=str1+str2+str3;

    //Password generator should have- string(upper as well as lower), number, special characters
    // Random string genertor
    // Number generator- A vector of numbers is created and later converted to a string 
    // Random symbols generator- Special Symbols are created and stored in a string
    // The String, Number and Symbols are taken and stored in a finally string from which any particular size of number is taken
    // Finally I would place them in any particular order


    do{
        switch (ch)
        {
            case 1:
                generatedPassword=r.string_gen(size);
                cout<<"\nThe Random string is: "<<generatedPassword<<endl;
                if (c.ask()==true)
                    f.create_file(generatedPassword);
                else
                    break;

            case 2:
                generatedPassword=r.convert_to_string(randomNumbers,size);
                cout<<"\nRandom numbers are: "<<generatedPassword<<endl;
                if (c.ask()==true)
                    f.create_file(generatedPassword);
                break;

            case 3:
                generatedPassword=r.sp_char_gen(size);
                cout<<"\nRandom symbols are: "<<generatedPassword<<endl;
                if (c.ask()==true)
                    f.create_file(generatedPassword);
                break;

            case 4:
                generatedPassword=r.final_conv(str4,size);
                cout<<"\nRandom string, symbol are: "<<generatedPassword<<endl;
                if (c.ask()==true)
                    f.create_file(generatedPassword);
                break;

            case 5:
                generatedPassword=r.final_conv(str5,size);
                cout<<"\nRandom string, number are: "<<generatedPassword<<endl;
                if (c.ask()==true)    
                    f.create_file(generatedPassword);
                break;

            case 6:
                generatedPassword=r.final_conv(str6,size);
                cout<<"\nRandom symbol, number are: "<<generatedPassword<<endl;
                if (c.ask()==true)
                    f.create_file(generatedPassword);
                break;

            case 7:
                generatedPassword=r.final_conv(str7,size);
                cout<<"\nRandom string, symbol, numbers are: "<<generatedPassword<<endl;
                if (c.ask()==true)
                    f.create_file(generatedPassword);
                break;

            default:
                cout<<"\nThe case is not invalid"<<endl;
                break;
        }
        
        cout<<"\nDo you wish to continue (y/n):";
        cin>>chc;
    }   while(c.istrue(chc)==true);

   
    return 0;
}