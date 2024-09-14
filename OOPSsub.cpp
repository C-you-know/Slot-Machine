#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>   
#include <unistd.h>

#define scr_mul 2
#define dim1 (30*scr_mul)
#define dim2 (60*scr_mul)

using namespace std;

class area 
{
    public:
    static int btw(int i0 ,int i1, int i2) 
    {
        for(int i = i1; i <= i2; i++)
        {
            if(i0 == i)
            {
                return 1; 
            }
        }
        return 0;
    }

    static int in(int i1, int l1, int h1, int i2,int l2, int h2)
    {
        int flag_1 = 0, flag_2 = 0;
        if(btw(i1,l1,h1))
            flag_1 = 1;

        if(btw(i2, l2, h2))
            flag_2 = 1;

        return(flag_1&&flag_2);
    }

    static int boundary(int i1, int i2)
    {
        if(in(i1,0,60,i2,0,120) && !in(i1,2,58,i2,2,118))
            return 1;
        else 
            return 0;
    }

    static int is_on_diagonal(int x, int y, int x1, int y1, int x2, int y2) 
    {
        if ((x >= x1 && x <= x2) || (x >= x2 && x <= x1)) 
        {
            if ((y >= y1 && y <= y2) || (y >= y2 && y <= y1)) 
            {
                if ((y - y1) == ((y2 - y1) / (x2 - x1)) * (x - x1)) 
                {
                    return 1;
                }
            }
        }
        
        return 0;
    }

    static string color_choice(int i)
    {
        switch (i)
        {
            case 0:
                return("\033[31m█\033[0m"); //red
                break;
            case 1:
                return("\033[32m█\033[0m"); //yellow
            break;
            case 2:
                return("\033[34m█\033[0m"); //blue
            break;
            case 3:
                return(" "); 
            break;
            
            default:
                return("█");
                break;
        }
    }

};

class display: public area
{
    public:
    static void u_gen_space()
    {
        cout<<"    \t\t\t\t\t    ";
    }

    static void u_generate_scr(string array[dim1][dim2]) 
    {
        for(int i = 0; i < dim1; i++) 
        {
            u_gen_space();
            for(int j = 0; j < dim2; j++) 
            {
                cout << array[i][j];
            }
            cout << endl;
        }

        cout<<endl;
        cout<<endl;
        cout<<endl;
    }  

    int hi_struct(int i1, int i2)
    {
        if(btw(i1,25-10,35-10) && i2 == 60+10)
        {
            return 1;
        }
        else if(i1 == 25-10 && btw(i2,50+10,70+10))
        {
            return 1;
        }
        else if(i1 == 35-10 && btw(i2,50+10,70+10))
        {
            return 1;
        }
       else if(i1 == 30-10 && btw(i2,25+10,45+10))
        {
            return 1;
        }
        else if(btw(i1,25-10,35-10) && i2 == 45+10)
        {
            return 1;
        }
        else if(btw(i1,25-10,35-10) && i2 == 25+10)
        {
            return 1;
        }
        else if(btw(i1,25-10,35-2-10) && i2 == 75+10)
        {
            return 1;
        }
        else if(i1 == 35-10 && i2 == 75+10)
        {
            return 1;
        }

        return 0;

    }

    int load_struct(int i1, int i2)
    {
        if(btw(i1,35,35)&&btw(i2,35,85+1))
            return 1;
        else
            return 0;
    }

    int frame_struct(int i1, int i2)
    {
        if(((i2 % 12 == 0) || (i2 % 12 == 1)) && ((i2 != 0) && (i2 != 1) && (i2 != 24) && (i2 != 25) && (i2 != 60) && (i2 != 61) && (i2 != 96) && (i2 != 97)) && btw(i1,20,40)
           || ((i1 % 20 == 0) && (i1 != 0) && (btw(i2,12,37) || btw(i2,48,73) || btw(i2,84,109))))
            return 1;
        return 0;
    }

    int light_struct(int i1, int i2)
    {
        if((i1 % 12 == 0)&&(i1 != 0)&&(i1 != 24)&&(i1 != 36))
        {
            return 1;
        }


        return 0;
    }

    int _____struct(int i1,int i2)
    {
        if(in(i1,22,38,i2,14,35)) //13
            return 1;
        if(in(i1,22,38,i2,50,49+22))//49
            return 1;
        if(in(i1,22,38,i2,86,85+22)) //85
            return 1;
        return 0;
        
    }

    int entire_scr_struct(int i1, int i2)
    {
        return 1;
    }

    int LOSE_struct(int i1, int i2)
    {
        if((btw(i1,20,40) && (i2 == 13 || i2 == 14) ) || (i1 == 40 && btw(i2,13,32)))    
            return 1;
        if((btw(i1,20,40) && (i2 == 35+2||i2 == 36+2)) || (btw(i1,20,40) && (i2 == 45+2+6||i2 == 46+2+6)) || ((i1 == 20 && btw(i2,35+2,45+2+6))) || ((i1 == 40 && btw(i2,35+2,45+2+6)))) //o
            return 1;

        if(i1 == 20 && btw(i2,49+2+6+2,49+21+6+2))
            return 1;
        if(i1 == 20+20 && btw(i2,49+2+6+2,49+21+6+2))
            return 1;
        if(i1 == 20+10 && btw(i2,49+2+6+2,49+21+6+2))
            return 1;
        if(btw(i1,20+10,20+20) && (i2 == 49+20+6+2|| i2 == 49+21+6+2))
            return 1;
        if(btw(i1,20,20+10) && (i2 == 49+2+6+2|| i2 == 49+3+6+2))
            return 1;
        
        //E

        if(i1 == 20 && btw(i2,85+2,85+21))
            return 1;
        if(i1 == 20+20 && btw(i2,85+2,85+21))
            return 1;
        if(i1 == 20+10 && btw(i2,85+2,85+21))
            return 1;
         if(btw(i1,20,20+20) && (i2 == 85|| i2 == 85+1))
            return 1;

        return 0;
    }

    int WIN_struct(int i1, int i2)
    {
        if((btw(i1,20,40)&&btw(i2,13,14)) || (btw(i1,20,40)&&btw(i2,15+15,15+16)) || (btw(i1,20,40)&&btw(i2,15+15+15,15+16+15)) || (i1==40 && btw(i2,13,46)))
            return 1;


        if(btw(i1,20,20+20) && (i2 == 49+11 || i2 == 49+12))
            return 1;
        if(btw(i2,49+2,49+21) && i1 == 20+20)
            return 1;
        if(i1 == 20 && btw(i2,49+2,49+21))
            return 1;

        if((btw(i1,20,40) && btw(i2,85-5,86-5)) || (btw(i1,20,40) && btw(i2,85+15+4-1,86+15+4-1)) || is_on_diagonal(i1,i2,20,85-5+2,40,86+15+4+2))
            return 1;
        



        return 0;
    }
};

class object_maintenance 
{
    public:
    virtual void object_place() = 0;
    virtual void object_animation() = 0;
    virtual void object_clean() = 0;
};

class game : public display, public object_maintenance
{
    private:
    string type;
    int priority;
    int x, y;
    int status = 0;

    public:
    int q_animation;
    int animatio_start_loc;

    string a[dim1][dim2] = {{" "}};
    static string p[dim1][dim2];
    

    game(int p): priority(p), q_animation(0) 
    {}
   
    game(int p, int a): priority(p), q_animation(a)
    {
        this->animatio_start_loc = 35;
    }

    game(int p, int a, int q): priority(p),q_animation(a),status(q) 
    {}

    game(string q,int p,int a):type(q),x(p),y(a) 
    {}

    void u_create_scr()
    {
        for (int i = 0; i < dim1; ++i) 
        {
            for (int j = 0; j < dim2; ++j) 
            {
                p[i][j] = "█";
            }
        }
    }

    int u_return_status(game& ob)
    {
        return(ob.status);
    }

    void update_x_n_y(int i)
    {
        this->x = 20;

        if(i == 0)
        {
            this->y = 13;
            return;
        }
        if(i == 1)
        {
            this->y = 49;
             return;
        }
        if(i == 2)
        {
            this->y = 85;
             return;
        }
    }

    void object_existence(int (game::*f)(int, int))
    {
        for(int i = 0; i < dim1; i++)
        {
            for(int j = 0; j < dim2; j++)
            {
                if((this->*f)(i, j))
                {
                    a[i][j] = color_choice(this->status);
                    //p[i][j] = a[i][j];
                }
            }
        }
    }

    void object_place()
    override
    {
            for(int i = 0; i < dim1; i++)
            {
                for(int j = 0; j < dim2; j++)
                {
                    if(a[i][j] == color_choice(this->status))
                        p[i][j] = a[i][j];
                }
            }
    }   

    void object_animation()
    override
    {
        for(int i = 0; i < dim1; i++)
        {
            for(int j = 0; j < dim2; j++)
            {
                if(a[i][j] == "\033[31m█\033[0m" && btw(j,35,this->animatio_start_loc))
                    p[i][j] = a[i][j];
            }
        }
        this->animatio_start_loc++;
    }

    void object_clean()
    override
    {
        for(int i = 0; i < dim1; i++)
        {
            for(int j = 0; j < dim2; j++)
            {
                a[i][j] = " ";
            }
        }
    }

    int __1__struct(int i1, int i2)
    {
        if(btw(i1,this->x+4,this->x+16) && (i2 == this->y+11 || i2 == this->y+12))
            return 1;
        else if(btw(i2,this->y+2,this->y+21) && i1 == this->x+16)
            return 1;
        else if(i1 == this->x+4 && btw(i2,this->y+2,this->y+10))
            return 1;

        return 0;
    }

    int __2__struct(int i1, int i2)
    {
        if(i1 == this->x+4 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(i1 == this->x+16 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(i1 == this->x+10 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(btw(i1,this->x+10,this->x+16) && (i2 == this->y+2|| i2 == this->y+3))
            return 1;
        if(btw(i1,this->x+4,this->x+10) && (i2 == this->y+20|| i2 == this->y+21))
            return 1;
        

        return 0;
    }

    int __3__struct(int i1,int i2)
    {
        if(btw(i1,this->x+4,this->x+16) && (i2 == this->y+20|| i2 == this->y+21))
            return 1;
        if(i1 == this->x+4 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(i1 == this->x+16 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(i1 == this->x+10 && btw(i2,this->y+2,this->y+21))
            return 1;
        return 0;
    }

    int __4__struct(int i1,int i2)
    {
        if(btw(i1,this->x+4,this->x+16) && (i2 == this->y+20|| i2 == this->y+21))
            return 1;
         if(i1 == this->x+10 && btw(i2,this->y+2,this->y+21))
            return 1;
         if(btw(i1,this->x+4,this->x+10) && (i2 == this->y+2|| i2 == this->y+3))
            return 1;

        return 0;

    }

    int __5__struct(int i1,int i2)
    {
        if(i1 == this->x+4 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(i1 == this->x+16 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(i1 == this->x+10 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(btw(i1,this->x+10,this->x+16) && (i2 == this->y+20|| i2 == this->y+21))
            return 1;
        if(btw(i1,this->x+4,this->x+10) && (i2 == this->y+2|| i2 == this->y+3))
            return 1;
        
        return 0;
    }

    int __6__struct(int i1,int i2)
    {
        if(i1 == this->x+4 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(i1 == this->x+16 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(i1 == this->x+10 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(btw(i1,this->x+10,this->x+16) && (i2 == this->y+20|| i2 == this->y+21))
            return 1;
        if(btw(i1,this->x+4,this->x+10) && (i2 == this->y+2|| i2 == this->y+3))
            return 1;
        if(btw(i1,this->x+10,this->x+16) && (i2 == this->y+2|| i2 == this->y+3))
            return 1;
        
        return 0;
    }

    int __7__struct(int i1,int i2)
    {
        if(btw(i1,this->x+4,this->x+16) && (i2 == this->y+20|| i2 == this->y+21))
            return 1;
        if(i1 == this->x+4 && btw(i2,this->y+2,this->y+21))
            return 1;

        return 0;
    }

    int __8__struct(int i1,int i2)
    {
        if(i1 == this->x+4 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(i1 == this->x+16 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(i1 == this->x+10 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(btw(i1,this->x+10,this->x+16) && (i2 == this->y+20|| i2 == this->y+21))
            return 1;
        if(btw(i1,this->x+4,this->x+10) && (i2 == this->y+2|| i2 == this->y+3))
            return 1;
        if(btw(i1,this->x+10,this->x+16) && (i2 == this->y+2|| i2 == this->y+3))
            return 1;
        if(btw(i1,this->x+4,this->x+10) && (i2 == this->y+20|| i2 == this->y+21))
            return 1;
        return 0;
    }

    int __9__struct(int i1,int i2)
    {
        if(i1 == this->x+4 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(i1 == this->x+16 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(i1 == this->x+10 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(btw(i1,this->x+10,this->x+16) && (i2 == this->y+20|| i2 == this->y+21))
            return 1;
        if(btw(i1,this->x+4,this->x+10) && (i2 == this->y+2|| i2 == this->y+3))
            return 1;
        if(btw(i1,this->x+4,this->x+10) && (i2 == this->y+20|| i2 == this->y+21))
            return 1;


         return 0;
    }

    int __0__struct(int i1,int i2)
    {
        if(i1 == this->x+4 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(i1 == this->x+16 && btw(i2,this->y+2,this->y+21))
            return 1;
        if(btw(i1,this->x+10,this->x+16) && (i2 == this->y+20|| i2 == this->y+21))
            return 1;
        if(btw(i1,this->x+4,this->x+10) && (i2 == this->y+2|| i2 == this->y+3))
            return 1;
        if(btw(i1,this->x+10,this->x+16) && (i2 == this->y+2|| i2 == this->y+3))
            return 1;
        if(btw(i1,this->x+4,this->x+10) && (i2 == this->y+20|| i2 == this->y+21))
            return 1;
        return 0;


    }
};

class game_mechanics_exceptions
{
    public:
    string e_msg;
    game_mechanics_exceptions(string e_msg):e_msg(e_msg) {}
    string what()
    {
        return(e_msg);
    }

};

class game_mechanics
{
    public:
    int a[3];
    void populate(int *a)
    {
        for(int i = 0; i < 3; i++)
        {
            a[i] = rand() % 10;

            if(a[i] >= 10)
            {
                throw game_mechanics_exceptions("Number too big!");
            }
            else if(a[i] < 0)
            {
                throw game_mechanics_exceptions("Number too small!");
            }
        }
    }

    static void phasing(game& g, game& ob)
    {
        if(ob.q_animation > 0)
        {
            do{
                ob.object_animation();
                ob.q_animation--; 
                //printf("%d",ob.q_animation);
                usleep(100000);
                g.u_generate_scr(game::p);
                
            }while(ob.q_animation != 0);
        }
        else 
        {
            ob.object_place();
            sleep(1);
            g.u_generate_scr(game::p);
        }
    };

    static void no_delay_phasing(game& g, game& ob)
    {
            if(ob.q_animation > 0)
        {
            do{
                ob.object_animation();
                ob.q_animation--; 
                printf("%d",ob.q_animation);
                usleep(100000);
                g.u_generate_scr(game::p);
                
            }while(ob.q_animation != 0);
        }
        else 
        {
            ob.object_place();
            g.u_generate_scr(game::p);
        }
    };

    static void next_frame(game& access)
    {
        access.u_create_scr();
        no_delay_phasing(access,access);

    }

};

string game::p[dim1][dim2] = {{" "}}; 

int main() 
{
    srand(time(0));

    game access(-1), hi(0),load(0,51),frame(1),light(1,0,1);
    game blank(1,0,1000),num1("1",20,13),num2("2",20,49),num3("3",20,13),num4("4",20,49),num5("5",20,85),num6("6",20,85),num7("7",20,13),num8("8",20,49),num9("9",20,85),num0("0",20,49);
    game endl(2,0,0),endw(2,0,1),lose(2,0,3),win(2,0,1000);


    access.u_create_scr();


    //Object Structure binding
    hi.object_existence(&display::hi_struct);
    load.object_existence(&display::load_struct);
    frame.object_existence(&display::frame_struct);
    light.object_existence(&display::light_struct);
    blank.object_existence(&display::_____struct);
    num1.object_existence(&game::__1__struct);
    num2.object_existence(&game::__2__struct);
    num3.object_existence(&game::__3__struct);
    num4.object_existence(&game::__4__struct);
    num5.object_existence(&game::__5__struct);
    num6.object_existence(&game::__6__struct);
    num7.object_existence(&game::__7__struct);
    num8.object_existence(&game::__8__struct);
    num9.object_existence(&game::__9__struct);
    num0.object_existence(&game::__0__struct);
    endl.object_existence(&game::entire_scr_struct);
    endw.object_existence(&display::entire_scr_struct);
    win.object_existence(&game::WIN_struct);
    lose.object_existence(&game::LOSE_struct);


   

   
    
    game_mechanics::phasing(access,hi);
    game_mechanics::phasing(access,load);
    game_mechanics::next_frame(access);
    game_mechanics::phasing(access,frame);
    game_mechanics::no_delay_phasing(access,light);
    

     

    
    {
        sleep(1);
        game_mechanics::no_delay_phasing(access,num1);
        game_mechanics::no_delay_phasing(access,num2);
        game_mechanics::no_delay_phasing(access,num9);
        sleep(1);
        game_mechanics::phasing(access,blank);

        game_mechanics::no_delay_phasing(access,num3);
        game_mechanics::no_delay_phasing(access,num8);
        game_mechanics::no_delay_phasing(access,num5);
        sleep(1);
        game_mechanics::phasing(access,blank);

        game_mechanics::no_delay_phasing(access,num7);
        game_mechanics::no_delay_phasing(access,num4);
        game_mechanics::no_delay_phasing(access,num6);
        sleep(1);
        game_mechanics::phasing(access,blank);
    }


    { 
        num1.object_clean();
        num2.object_clean();
        num3.object_clean();
        num4.object_clean();
        num5.object_clean();
        num6.object_clean();
        num7.object_clean();
        num8.object_clean();
        num9.object_clean();
        num0.object_clean();
    }

    game_mechanics g1;
    int rand_loop = 0;

    try
    {
        g1.populate(g1.a);
    }
    catch(game_mechanics_exceptions& e)
    {
        cout<<e.what() << '\n';
    }
    
    
    do
    {
        sleep(1);
        
       switch(g1.a[rand_loop])
       {
        case 1: 
            num1.update_x_n_y(rand_loop);
            num1.object_existence(&game::__1__struct);
            game_mechanics::no_delay_phasing(access,num1);
            break;
        case 2: 
            num2.update_x_n_y(rand_loop);
            num2.object_existence(&game::__2__struct);
            game_mechanics::no_delay_phasing(access,num2);
            break;
        case 3: 
            num3.update_x_n_y(rand_loop);
             num3.object_existence(&game::__3__struct);
            game_mechanics::no_delay_phasing(access,num3);
            break;
        case 4: 
            num4.update_x_n_y(rand_loop);
            num4.object_existence(&game::__4__struct);
            game_mechanics::no_delay_phasing(access,num4);
            break;
        case 5: 
            num5.update_x_n_y(rand_loop);
            num5.object_existence(&game::__5__struct);
            game_mechanics::no_delay_phasing(access,num5);
            break;
        case 6: 
            num6.update_x_n_y(rand_loop);
            num6.object_existence(&game::__6__struct);
            game_mechanics::no_delay_phasing(access,num6);
            break;
        case 7: 
            num7.update_x_n_y(rand_loop);
            num7.object_existence(&game::__7__struct);
            game_mechanics::no_delay_phasing(access,num7);
            break;
        case 8: 
            num8.update_x_n_y(rand_loop);
            num8.object_existence(&game::__8__struct);
            game_mechanics::no_delay_phasing(access,num8);
            break;
        case 9: 
            num9.update_x_n_y(rand_loop);
            num9.object_existence(&game::__9__struct);
            game_mechanics::no_delay_phasing(access,num9);
            break;
        case 0: 
            num0.update_x_n_y(rand_loop);
            num0.object_existence(&game::__0__struct);
            game_mechanics::no_delay_phasing(access,num0);
            break;
       }

        rand_loop++;
        

    } while (rand_loop != 3);
    
    sleep(1);

    if(g1.a[0] == g1.a[1] && g1.a[1] == g1.a[2])
    {
        game_mechanics::no_delay_phasing(access,endw);
        game_mechanics::no_delay_phasing(access,win);
        return 0;
    }
    
    game_mechanics::no_delay_phasing(access,endl);
    game_mechanics::no_delay_phasing(access,lose);

    int wait;
    scanf("%d",&wait);
    return 0;
}
