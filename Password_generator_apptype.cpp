#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<sstream>

using namespace std;

const int MAX=52;
class Random
{
    //String randomizer
    public:
        string string_gen(int size)
        {
            char alphabet[MAX]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                                'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
            string res=" ";
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
            for(int i=0;i<rand.size();i++){
                st<<rand[i];
            }
            return st.str();
        }
    
    public:
        string final_conv(string res, int size){
            string final_str=" ";
            for(int i=0;i<size;i++)
            {
                final_str=final_str+res[rand()%(size*3)];
            }
            return final_str;
        }
    public:
        bool check_case(int num)
        {
            if(num>0 && num<8)
                return true;
            else
                return false;
        }
};

int main()
{
    srand(time(NULL));
    string str1,str2,str3;
    Random r;
    int size,ch;
    char c;
    
    cout<<"Welcome to password generator!"<<endl;
    cout<<"The options are:\n1.String generator\n2.Number generator\n3.Character generator\n4.String, Character generator\n5.String, Number generator \n6.Character, Number generator\n7.String, Character, Number generator"<<endl;
    
    cout<<"Enter your option: "<<endl;
    cin>>ch;

    if(r.check_case(ch)==true)
    {
        cout<<"Enter the size of the password: "<<endl;
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

    //Password generator should have- string, number, special characters
    // Random string genertor
    // Number generator- string convert
    // Random charcters generator- string convert
    // Finally I would place them in any particular order

    switch (ch)
    {
        case 1:
            cout<<"\nThe Random string is: "<<str1<<endl;
            break;

        case 2:
            cout<<"\nRandom numbers are: "<<str2<<endl;
            break;

        case 3:
            cout<<"\nRandom characters are: "<<str3<<endl;
            break;

        case 4:
            cout<<"\nRandom string, charcter are: "<<endl;
            cout<<r.final_conv(str4,size);
            break;

        case 5:
            cout<<"\nRandom string, number are: "<<endl;
            cout<<r.final_conv(str5,size);
            break;

        case 6:
            cout<<"\nRandom charcter, number are: "<<endl;
            cout<<r.final_conv(str6,size);
            break;

        case 7:
            cout<<"\nRandom string, character, number are: "<<endl;
            cout<<r.final_conv(str7,size);
            break;

        default:
            cout<<"\nThe case is not invalid"<<endl;
            break;
    }

    return 0;
}