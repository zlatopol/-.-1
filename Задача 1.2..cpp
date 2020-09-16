#include<cstddef>
#include<string>
#include<iostream>
#include<locale>
#include<cassert>
#include<cstring>
struct ci_char_traits : public std::char_traits<char>
// Просто наследуем все остальные функции,
// чтобы не писать их заново
{
    static bool eq(char c1, char c2)
         {return toupper(c1) == toupper(c2); }
    static bool lt(char c1, char c2)
        { return toupper(c1) < toupper(c2); }
    static int compare( const char * s1,
                        const char * s2,
                        size_t n )
        {
            int rez=0;
            for(size_t i=0;i < n;++i)
            {
                char c1=s1[i],c2=s2[i];
                c1=toupper(c1);
                c2=toupper(c2);
                rez=rez+static_cast<int>(c1)-static_cast<int>(c2);
            }
            return rez;
        }
    static const char *
    find( const char * s, int n, char a )
    {
        while(n-- > 0 && toupper(*s) != toupper(a))
        {
            ++s;
        }
        return n >= 0 ? s : 0;
    }
};
typedef std::basic_string<char, ci_char_traits > ci_string;
 int main()
 {
    ci_string s("AbCdE");
    // Нечувствительно к регистру
    assert( s == "abcde" );
    assert( s == "ABCDE" );
    // Остается чувствительно к регистру
    assert(strcmp(s.c_str(),"AbCdE") == 0);
    assert(strcmp(s.c_str(),"abcde") != 0);
     return 0;
 }
