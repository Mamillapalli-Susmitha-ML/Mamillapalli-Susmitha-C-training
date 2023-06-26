#include<iostream>
using namespace std;
#define no_of_questions 10
class Questions
{
    protected:
        string ques;
        public:
        Questions(){}
        void set_question(string s)
        {
            ques=s;
        }
        void get_question()
        {
            cout<<ques<<endl;
        }
        friend void set_questions_options();
};
class Answers
{
    protected:
        static int ans[no_of_questions];
        string options;
        public:
        Answers(){}
        void set_option(string s)
        {
            options=s;
        }
        void get_option()
        {
            cout<<options<<endl;
        }
        static void set_all_ans()
        {
            int count=0;
            ans[count++]=4;
            ans[count++]=4;
            ans[count++]=4;
            ans[count++]=4;
            ans[count++]=2;
            ans[count++]=2;
            ans[count++]=4;
            ans[count++]=2;
            ans[count++]=3;
            ans[count++]=2;
        }
        friend void set_questions_options();
};
int Answers::ans[no_of_questions];
class DisplayQuizz:public Questions,public Answers
{
    public:
        int opt;
        int total_score=0;
        DisplayQuizz(){}
        void display_quizz(Questions q,Answers a)
        {
           static int count=0;
            cout<<endl<<"QUESTION-"<<count+1<<endl;
            q.get_question();
            cout<<endl<<"OPTIONS:"<<endl;
            a.get_option();
            cout<<endl<<"Choose your answer:"<<endl;
            cin>>opt;
            if(opt==ans[count])
                total_score+=1;
            count++;
        }
        void display_score()
        {
            cout<<"__________________________________________________"<<endl;
            cout<<endl<<"Your total score is:"<<total_score<<endl;
            cout<<"__________________________________________________"<<endl;
        }
};
void set_questions_options()
{
    Questions q1;
    Questions q2;
    Questions q3;
    Questions q4;
    Questions q5;
    Questions q6;
    Questions q7;
    Questions q8;
    Questions q9;
    Questions q10;
    q1.set_question("ISP stands for?");
    q2.set_question("The 'http' you type at the beginning of any site's address stands for?");
    q3.set_question("'.JPG' extension refers usually to what kind of file?");
    q4.set_question("'CD' computer abbreviation usually means?");
    q5.set_question("What does EPROM stand for?");
    q6.set_question("In computer jargon, RAM refers to?");
    q7.set_question("What's a web browser?");
    q8.set_question("How many bits is a byte?");
    q9.set_question("Computers calculate numbers in what mode?");
    q10.set_question("Which of these is a search engine?");
    Answers a1;
    Answers a2;
    Answers a3;
    Answers a4;
    Answers a5;
    Answers a6;
    Answers a7;
    Answers a8;
    Answers a9;
    Answers a10;
    a1.set_option("1.Internet Survey Period     2.Integrated Service Provider\n3.Internet Security Protocol    4.Internet Service Provider");
    a2.set_option("1.HTML Transfer Technology Process    2.Hyperspace Terms and Tech Protocol\n3.Hyperspace Techniques & Tech Progress  4.Hyper Text Transfer Protocol");
    a3.set_option("1.System file     2.Animation/movie file\n3.MS Encarta document   4.Image file");
    a4.set_option("1.Command Description    2.Change Data\n3.Copy Density  4.Compact Disc");
    a5.set_option("1.Electric Programmable Read Only Memory     2.Erasable Programmable Read Only Memory\n3.Evaluable Philotic Random Optic Memory    4.Every Person Requires One Mind");
    a6.set_option("1.Read Only Menu     2.Random Access Memory\n3Random Accent Memory     4.Read Access Memory");
    a7.set_option("1.A kind of spider    2.A computer that stores WWW files\n3.A person who likes to look at websites    4.A software program that allows you to access sites on the World Wide Web");
    a8.set_option("1.4   2.8\n3.16    4.32");
    a9.set_option("1.Decimal    2.Octal\n3.Binary    4.None of the above");
    a10.set_option("1.FTP   2.Google\n3.Archie    4.ARPANET");
    Answers a;
    a.set_all_ans();
    DisplayQuizz d;
    d.display_quizz(q1,a1);
    d.display_quizz(q2,a2);
    d.display_quizz(q3,a3);
    d.display_quizz(q4,a4);
    d.display_quizz(q5,a5);
    d.display_quizz(q6,a6);
    d.display_quizz(q7,a7);
    d.display_quizz(q8,a8);
    d.display_quizz(q9,a9);
    d.display_quizz(q10,a10);
    d.display_score();
}
int main()
{
    set_questions_options();
}