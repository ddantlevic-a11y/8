// UnitTest_08_1_it.cpp
// Данилевич Данило
// Модульний тест для Lab_08_1_it.cpp

#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

#define UNIT_TEST
#include "Lab_08_1_it.cpp"

void TestCount()
{
    assert(Count("") == 0);
    assert(Count("whil") == 0);
    assert(Count("hello world") == 0);
    assert(Count("while") == 1);
    assert(Count("do while loop") == 1);
    assert(Count("whilewhile") == 2);
    assert(Count("while x while y while") == 3);
    assert(Count("While whil whilee") == 1);

    cout << "Test 1 (Count) passed successfully!" << endl;
}

void TestChange()
{
    {
        char s[101] = "hi";
        char* dest = Change(s);
        assert(strcmp(s, "hi") == 0);
        assert(strcmp(dest, "hi") == 0);
        if (dest != s) delete[] dest;
    }

    {
        char s[101] = "hello world";
        char* dest = Change(s);
        assert(strcmp(s, "hello world") == 0);
        assert(strcmp(dest, "hello world") == 0);
        if (dest != s) delete[] dest;
    }

    {
        char s[101] = "while";
        char* dest = Change(s);
        assert(strcmp(s, "***") == 0);
        assert(strcmp(dest, "***") == 0);
        if (dest != s) delete[] dest;
    }

    {
        char s[101] = "do while loop";
        char* dest = Change(s);
        assert(strcmp(s, "do *** loop") == 0);
        assert(strcmp(dest, "do *** loop") == 0);
        if (dest != s) delete[] dest;
    }

    {
        char s[101] = "whilewhile";
        char* dest = Change(s);
        assert(strcmp(s, "******") == 0);
        assert(strcmp(dest, "******") == 0);
        if (dest != s) delete[] dest;
    }

    {
        char s[101] = "awhilebwhile";
        char* dest = Change(s);
        assert(strcmp(s, "a***b***") == 0);
        assert(strcmp(dest, "a***b***") == 0);
        if (dest != s) delete[] dest;
    }

    {
        char s[101] = "whil whilee While";
        char* dest = Change(s);
        assert(strcmp(s, "whil ***e While") == 0);
        assert(strcmp(dest, "whil ***e While") == 0);
        if (dest != s) delete[] dest;
    }

    cout << "Test 2 (Change) passed successfully!" << endl;
}

int main()
{
    TestCount();
    TestChange();

    cout << "\nAll Unit Tests passed successfully!" << endl;
    return 0;
}
