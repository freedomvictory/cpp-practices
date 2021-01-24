//
// Created by dingguoliang on 2021/1/23.
//

#include <string>
#include <vector>
#include <iostream>

//practice 7.32
//passge 253, 友元的使用 


class Screen{
    friend class Window_mgr;
public:
    using pos = std::string::size_type; 
    Screen() = default; 

    Screen(pos ht, pos wd, char c) : height(ht), width(wd), 
    contents(ht *wd, c) {} 

    char get() const 
        {return contents[cursor];}
    char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os)  {
        do_display(os); 
        return *this; 
    }

private:
    void do_display(std::ostream &os) const;

private:
    pos cursor = 0; 
    pos height = 0, width = 0; 
    std::string contents; 


};

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen(24, 80, '*')};
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height *  s.width, ' ');
}
inline char Screen::get(pos r, pos c) const 
{
    pos row = r * width; 
    return contents[row + c];
}
inline Screen &Screen::move(pos r, pos c)
{
    cursor = r * width + c;     
    return *this; 
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c; 
    return *this; 
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    pos row = r * width;
    contents[row + col] = ch; 
    return *this; 
}
inline void Screen::do_display(std::ostream &os) const {
    for(pos i = 0; i != contents.size(); ++i)
    {
        os << contents[i];
        if((i + 1) % width == 0 && i + 1 != contents.size())
            os << "\n"; 
    }
    os << "\n\n"; 
}


int main(int argc, const char *argv[])
{
    std::cout << "hello, visual studio code! :)" << '\n'; 
    Screen s(20, 20, '#');
    s.display(std::cout); 
    s.set(1, 5, '?');    
    s.display(std::cout);

    Window_mgr w;
    w.clear(0);

    return 0; 
}

